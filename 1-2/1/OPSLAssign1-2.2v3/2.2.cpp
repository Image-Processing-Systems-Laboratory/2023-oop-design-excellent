#include <iostream>

using namespace std;


void Sender(char* data);
void Transmission_Channel(const char* coded_frame);
void Receiver(const char* received_frame);


void Sender(char* data)
{
	char data16[16];
	char divisor[5] = { 1, 1, 0, 1, 1 };	// ���õ� divisor = 11011(2)

	for (int i = 0; i < 12; i++)
		data16[i] = data[i];

	for (int i = 12; i < 16; i++)		// ���޹��� data 12bit���� 16bit�� �ø��� ���� 0000�� �߰��Ѵ�.
		data16[i] = 0;

	///////////////////////////////////////////////////////////////////////////////
	
	int i = 0;
	int num = 0;

	while (1)
	{				
		while (data16[num] == 0)	// num��° ��Ʈ���� 0�̶�� �� �������� �Ѿ���Ѵ�. �̸� 0�� ���������� �ݺ��Ѵ�.
			num++;					// num�� �ʱⰪ�� 0�̰�, ���� 0�� ���涧���� N�� �����ϴµ�, �Ʒ�ó�� 11��° ���Ĵ� ���� ���̻� ���ؼ��� �ȵȴ�.
		if (num > 11)
			break;				// 16bit�� 5bit�� ���ϹǷ� �������� 11��° ���ķδ� ���̻� ������� �ʾƾ��Ѵ�. (4bit���� �������̹Ƿ�)
		for (int j = 0; j < 5; j++)
		{
			if (data16[j + num] != divisor[j])
				data16[j + num] = 1;
			else
				data16[j + num] = 0;	// XOR ����! divisor�� ��Ʈ���� ������ 0, �ٸ��� 1�� �����Ѵ�.
		}

	}

	///////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 12; i++)
		data16[i] = data[i];			// ������ ������ data16�� 0000 0000 0000 [ R ] �����̹Ƿ� ���� 12bit�� �ٽ� data�� �Է����ش�.

	cout << "Coded frame : \t\t";
	for (int i = 0; i < 16; i++)
		printf("%d", data16[i]);		// ���������� ����ϱ����� printf ���

	Transmission_Channel(data16);		// transmission channel�� ����

	return;
}


void Transmission_Channel(const char* coded_frame)
{
	srand(time(nullptr));							// rand()�� ����ϱ� ���� time�� ���

	char received_data[16];

	for (int i = 0; i < 16; i++)
	{
		received_data[i] = coded_frame[i];			// received data�� ���� ���� ������ ������ �� ��(Ȯ���� ����)�� �����Ѵ�.

		int random = rand() % 100;					// random = 0 ~ 99�� ��
		if (random < 5)								// random = 0, 1, 2, 3, 4 (5%)�϶� ���� ����
		{
			if (coded_frame[i] == 0)
				received_data[i] = 1;
			else
				received_data[i] = 0;				// ��Ʈ�� 0�� 1�� �ڹٲ۴�.
		}
	}

	cout << endl << "Received frame: \t";

	for (int i = 0; i < 16; i++)
		printf("%d", received_data[i]);		// ���������� ����ϱ����� printf ���


	cout << endl;

	Receiver(received_data);						// ���ù��� ���� �Ǵ� ���� ������ �������ش�. 

	return;
}

void Receiver(const char* received_frame)
{
	char checkframe[16];
	char divisor[5] = { 1, 1, 0, 1, 1 };

	cout << endl << "Reconstructed data: \t";		// ���޹��� ������ 12��Ʈ��ŭ ����Ѵ�.
	for (int i = 0; i < 12; i++)
		printf("%d", received_frame[i]);		// ���������� ����ϱ����� printf ���

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

	}												// ��� ������ �ռ� Sender�� �����ϴ�.

	int R = 0;

	for (int i = 0; i < 4; i++)
	{
		R = R + checkframe[15 - i];					// ������ 4��Ʈ�� ���ؼ� 0000 -> �϶� R�� 0�� �ǵ��� �Ѵ�. �̿��� ��쿡�� R != 0 
	}

	if (R == 0)
		cout << endl << "No detected error";
	else
		cout << endl << "Receiver has detected error";	// R�� 0�� �ƴ� ���� error, R�� 0�� ��쿡�� ��������

	return;
}

int main()
{
	char data[13];						// ���ڿ����� �Է¹ޱ⿡ ũ�Ⱑ 13�� data �迭

	cout << "Data: \t\t\t";
	cin >> data;

	for (int i = 0; i < 12; i++)
		data[i] = data[i] - '0';		// data�� ���ڿ� ���·� �޾ұ� ������ ������������ �����ϱ� ���� -'0'���� �ٽ� �����Ѵ�.

	Sender(data);						// Sender�� data�� �����Ѵ�.

	return 0;
}