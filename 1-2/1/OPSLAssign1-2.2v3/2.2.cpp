#include <iostream>

using namespace std;


void Sender(char* data);
void Transmission_Channel(const char* coded_frame);
void Receiver(const char* received_frame);


void Sender(char* data)
{
	char data16[16];
	char divisor[5] = { 1, 1, 0, 1, 1 };	// 제시된 divisor = 11011(2)

	for (int i = 0; i < 12; i++)
		data16[i] = data[i];

	for (int i = 12; i < 16; i++)		// 전달받은 data 12bit값을 16bit로 늘리고 끝에 0000을 추가한다.
		data16[i] = 0;

	///////////////////////////////////////////////////////////////////////////////
	
	int i = 0;
	int num = 0;

	while (1)
	{				
		while (data16[num] == 0)	// num번째 비트에서 0이라면 그 다음으로 넘어가야한다. 이를 0이 없을때까지 반복한다.
			num++;					// num의 초기값은 0이고, 앞의 0이 생길때마다 N씩 증가하는데, 아래처럼 11번째 이후는 값을 더이상 비교해서는 안된다.
		if (num > 11)
			break;				// 16bit와 5bit를 비교하므로 마지막에 11번째 이후로는 더이상 계산하지 않아야한다. (4bit값의 나머지이므로)
		for (int j = 0; j < 5; j++)
		{
			if (data16[j + num] != divisor[j])
				data16[j + num] = 1;
			else
				data16[j + num] = 0;	// XOR 연산! divisor의 비트값과 같으면 0, 다르면 1을 저장한다.
		}

	}

	///////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 12; i++)
		data16[i] = data[i];			// 연산이 끝나면 data16은 0000 0000 0000 [ R ] 형태이므로 앞의 12bit에 다시 data를 입력해준다.

	cout << "Coded frame : \t\t";
	for (int i = 0; i < 16; i++)
		printf("%d", data16[i]);		// 정수형으로 출력하기위해 printf 사용

	Transmission_Channel(data16);		// transmission channel로 전달

	return;
}


void Transmission_Channel(const char* coded_frame)
{
	srand(time(nullptr));							// rand()를 사용하기 위해 time을 사용

	char received_data[16];

	for (int i = 0; i < 16; i++)
	{
		received_data[i] = coded_frame[i];			// received data에 원래 받은 값에서 오류가 난 값(확률에 따라)을 저장한다.

		int random = rand() % 100;					// random = 0 ~ 99의 값
		if (random < 5)								// random = 0, 1, 2, 3, 4 (5%)일때 오류 조건
		{
			if (coded_frame[i] == 0)
				received_data[i] = 1;
			else
				received_data[i] = 0;				// 비트의 0과 1을 뒤바꾼다.
		}
	}

	cout << endl << "Received frame: \t";

	for (int i = 0; i < 16; i++)
		printf("%d", received_data[i]);		// 정수형으로 출력하기위해 printf 사용


	cout << endl;

	Receiver(received_data);						// 리시버에 오류 또는 정상 파일을 전달해준다. 

	return;
}

void Receiver(const char* received_frame)
{
	char checkframe[16];
	char divisor[5] = { 1, 1, 0, 1, 1 };

	cout << endl << "Reconstructed data: \t";		// 전달받은 파일을 12비트만큼 출력한다.
	for (int i = 0; i < 12; i++)
		printf("%d", received_frame[i]);		// 정수형으로 출력하기위해 printf 사용

	///////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 16; i++)
		checkframe[i] = received_frame[i];

	int num = 0;

	while (1)
	{		
		while (checkframe[num] == 0)
			num++;
		if (num > 11)
			break;

		for (int j = 0; j < 5; j++)
		{
			if (checkframe[j + num] != divisor[j])
				checkframe[j + num] = 1;
			else
				checkframe[j + num] = 0;
		}

	}												// 계산 과정은 앞서 Sender와 동일하다.

	int R = 0;

	for (int i = 0; i < 4; i++)
	{
		R = R + checkframe[15 - i];					// 마지막 4비트를 비교해서 0000 -> 일때 R은 0이 되도록 한다. 이외의 경우에는 R != 0 
	}

	if (R == 0)
		cout << endl << "No detected error";
	else
		cout << endl << "Receiver has detected error";	// R이 0이 아닌 경우는 error, R이 0인 경우에는 정상적임

	return;
}

int main()
{
	char data[13];						// 문자열으로 입력받기에 크기가 13인 data 배열

	cout << "Data: \t\t\t";
	cin >> data;

	for (int i = 0; i < 12; i++)
		data[i] = data[i] - '0';		// data를 문자열 형태로 받았기 때문에 숫자형식으로 저장하기 위해 -'0'으로 다시 저장한다.

	Sender(data);						// Sender에 data를 전달한다.

	return 0;
}