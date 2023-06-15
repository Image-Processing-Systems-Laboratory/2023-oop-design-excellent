#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;

//함수 선언
char* MakeData();			//메모리 할당 및 사용자로부터 입력받는 함수
char* Sender(char* data);	//전송받은 12비트 데이터에 4비트 FCS를 붙여 16비트로 저장하여 반환하는 함수
char* Transmission_Channel(const char* coded_frame);	//각 비트에서 5%확률로 전송받은 데이터가 오류가 날 수 있도록 하여 반환하는 함수
void Receiver(const char* received_frame);				//전송받은 데이터가 오류가 났는지 안났는지 확인하는 함수
int memory_free(char* data);	//할당한 메모리를 해제함
short short_pow(short num, short n);	//2의 제곱을 short형으로 반환해주는 함수
int length(unsigned short cal, int berfore_len);	//>>방향으로 몇번 shift연산 해줘야 하는지 반환하는 함수


int main()
{
	char* Data = 0;		//포인터 변수 선언 및 초기화
	Data = MakeData();	//메모리할당 해주는 함수
	Receiver(Transmission_Channel(Sender(Data)));	//Data를 전송을 할때 오류가 있는지 없는지 찾는다.
	memory_free(Data);	//할당한 메모리를 해제해주는 함수 

	return 0;
}
/* 메모리 할당 및 사용자로부터 입력받는 함수 */
char* MakeData() {
	char* data = new char[17];		//길이 17로 메모리할당
	cout << "Data: ";
	cin >> data;					//data값을 입력받음

	return data;					//data를 반환함
}
/* 전송받은 12비트 데이터에 4비트 FCS를 붙여 16비트로 저장하여 반환하는 함수 */
char* Sender(char* data) {
	//unsigned short형 변수 선언 및 초기화
	unsigned short cal = 0;		//data의 10진수
	unsigned short sub = 0b11011; // 2진수
	//int형 변수 선언 및 초기화 len은 비트 길이 cal_len은 shift 이동해야할 길이, before_len은 전에 이동했던 길이
	int len = 5, cal_len = 0, before_len = 0;
	//char형 배열 선언
	char data_cpy[100];
	char R[5] = { '0', '0', '0', '0', '\0' };

	strcpy(data_cpy, data);			//data의 값을 data_cpy에 저장
	strcat(data_cpy, R);			//data_cpy뒤에 R을 이어붙임
	/*  cal에 2진수로 저장된 data를 10진수로 변환하여 저장  */
	for (int i = 1; i <= 16; i++) //i가 1부터 16까지
	{
		char each_data[2]; //char형 배열 선언
		each_data[0] = data_cpy[strlen(data_cpy) - i];		//0또는 1인 비트를 저장함
		cal += short_pow(2, i - 1) * (unsigned short)atoi(each_data);		//cal에 저장된 값은 data의 10진수로 표현된 값
	}

	sub = sub << 11;		//<<을 11번 shift이동을 함
	while (len <= 16)		//len이 16보다 작거나 같을때까지
	{
		//cal이 데이터
		//sub가 11011
		cal = cal ^ sub;	//cal과 sub의 XOR연산을 cal에 다시 저장함

		cal_len = length(cal, before_len);	//shift 이동해야할 정도를 저장함

		before_len += cal_len;		//cal_len값을 더해줌
		sub = sub >> cal_len;		//sub를 cal_len만큼 shift이동을 해준 값을 sub에 저장
		len += cal_len;				//cal_len값을 더해줌
	}
	//cal을 이진수로 나타내 R에 문자로 저장 int를 string으로 저장
	for (int i = 0; i < 4; i++)		//i가 0부터 3까지
	{
		R[3 - i] = cal % 2 + 48;	//문자열로 저장
		cal = cal / 2;
	}
	strcat(data, R);			//data의 값과 FCS를 합치고
	return data;			//data를 반환한다.
}
/* 각 비트에서 5 % 확률로 전송받은 데이터가 오류가 날 수 있도록 하여 반환하는 함수 */
char* Transmission_Channel(const char* coded_frame) {
	char* data = (char*)coded_frame;		//전송 받은 데이터를 char*로 변환하여 저장

	cout << "Coded frame: " << coded_frame << endl;		//전송받은 데이터 출력
	srand(time(NULL));									//난수 초기화
	for (int i = 0; i < 16; i++)	//i가 0부터 15까지
	{
		int rand_num = rand() % 100;	//0부터 99까지의 난수를 무작위로 저장한다.
		
		if (rand_num < 5)		//5보다 작을경우 즉 확률이 5%일 경우
		{
			if (coded_frame[i] == '0')
				data[i] = '1';			//오류값으로 저장한다.
			else if (coded_frame[i] == '1')
				data[i] = '0';			//오류값으로 저장한다.
		}
	}
	return data;		//data 반환
}
/*전송받은 데이터가 오류가 났는지 안났는지 확인하여 반환하는 함수*/
void Receiver(const char* received_frame) {
	char* data = (char*)received_frame;				//전송받은 데이터를 char*로 변환하여 저장
	cout << "Received frame: " << received_frame << endl;	//전송받은 데이터 출력

	//XOR 연산 전
	//unsigned short형 변수 선언 및 초기화
	unsigned short cal = 0;
	unsigned short sub = 0b11011; // 2진수
	//int형 변수 선언 및 초기화 len은 비트 길이 cal_len은 shift 이동해야할 길이, before_len은 전에 이동했던 길이
	int len = 5, cal_len = 0, before_len = 0;
	
	char data_cpy[100];			//char형 배열 선언
	strcpy(data_cpy, data);		//data의 문자열을 data_cpy에 저장
	/*  cal에 2진수로 저장된 data를 10진수로 변환하여 저장  */
	for (int i = 1; i <= 16; i++) //i가 1부터 16까지
	{
		char each_data[2]; //char형 배열 선언
		each_data[0] = data_cpy[strlen(data_cpy) - i];		//0또는 1인 비트를 저장함
		cal += short_pow(2, i - 1) * (unsigned short)atoi(each_data);		//cal에 저장된 값은 data의 10진수로 표현된 값
	}

	sub = sub << 11;		//<<을 11번 shift이동을 함
	while (len <= 16)		//len이 16보다 작거나 같을때까지
	{
		//cal이 데이터
		//sub가 11011
		cal = cal ^ sub;	//cal과 sub의 XOR연산을 cal에 다시 저장함

		cal_len = length(cal, before_len);	//shift 이동해야할 정도를 저장함

		before_len += cal_len;		//cal_len값을 더해줌
		sub = sub >> cal_len;		//sub를 cal_len만큼 shift이동을 해준 값을 sub에 저장
		len += cal_len;				//cal_len값을 더해줌
	}
	
	//XOR 연산 후
	data[12] = '\0';
	cout << "Reconstructed data: " << data << endl;		//전송받은 데이터의 12비트 출력
	if (cal == 0)		//나머지가 0이라면
		cout << "No detected error";	//오류가 없다
	else				//나머지가 0이 아니라면
		cout << "Receiver has detected error";	//오류가 있다.

}
/* 할당한 메모리해제하는 함수 */
int memory_free(char* data) {
	delete[]data;		//data의 메모리 해제
	return 0;	//0반환
}
/* num의 제곱을 short형으로 반환하는 함수 */
short short_pow(short num,short n) {
	short result = 1;	//short형 변수 선언 및 초기화
	if (n == 0)		//n이 0일때
		return 1;	//1반환

	for (short i = 0; i < n; i++)	//i가 0부터 n-1까지
		result *= num;		//num의 n제곱만큼 저장함
	return result;			//result 값 반환
}
/*  shift연산 시키고 싶은 길이를 반환하는 함수  */
int length(unsigned short cal, int berfore_len) {
	int arr[16];		//int형 배열 선언
	//cal을 2진수로 만들어 arr에 저장하고 앞에서부터 0의 숫자를 셈
	int j = 0;		//int형 변수 선언
	while (j < 16)	//j가 15까지
	{
		arr[16 - 1 - j] = cal % 2;	//cal을 2로 나눈 나머지를 arr[15-j]에 저장
		cal = cal / 2;		//cal/2를 cal에 저장
		j++;	//j=j+1;과 같음
	}
	for (int i = 0; i < 16; i++)	//i가 0부터 15까지
		if (arr[i] != 0)			//0이 연속적으로 나오는 수를 셈
			return i - berfore_len;	//0이 연속적으로 나오는 수를 전에 shift연산시킨 길이 만큼 빼서 반환
}
