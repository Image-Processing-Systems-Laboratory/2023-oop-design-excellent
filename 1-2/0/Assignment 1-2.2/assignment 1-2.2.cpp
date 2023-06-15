#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;

//�Լ� ����
char* MakeData();			//�޸� �Ҵ� �� ����ڷκ��� �Է¹޴� �Լ�
char* Sender(char* data);	//���۹��� 12��Ʈ �����Ϳ� 4��Ʈ FCS�� �ٿ� 16��Ʈ�� �����Ͽ� ��ȯ�ϴ� �Լ�
char* Transmission_Channel(const char* coded_frame);	//�� ��Ʈ���� 5%Ȯ���� ���۹��� �����Ͱ� ������ �� �� �ֵ��� �Ͽ� ��ȯ�ϴ� �Լ�
void Receiver(const char* received_frame);				//���۹��� �����Ͱ� ������ ������ �ȳ����� Ȯ���ϴ� �Լ�
int memory_free(char* data);	//�Ҵ��� �޸𸮸� ������
short short_pow(short num, short n);	//2�� ������ short������ ��ȯ���ִ� �Լ�
int length(unsigned short cal, int berfore_len);	//>>�������� ��� shift���� ����� �ϴ��� ��ȯ�ϴ� �Լ�


int main()
{
	char* Data = 0;		//������ ���� ���� �� �ʱ�ȭ
	Data = MakeData();	//�޸��Ҵ� ���ִ� �Լ�
	Receiver(Transmission_Channel(Sender(Data)));	//Data�� ������ �Ҷ� ������ �ִ��� ������ ã�´�.
	memory_free(Data);	//�Ҵ��� �޸𸮸� �������ִ� �Լ� 

	return 0;
}
/* �޸� �Ҵ� �� ����ڷκ��� �Է¹޴� �Լ� */
char* MakeData() {
	char* data = new char[17];		//���� 17�� �޸��Ҵ�
	cout << "Data: ";
	cin >> data;					//data���� �Է¹���

	return data;					//data�� ��ȯ��
}
/* ���۹��� 12��Ʈ �����Ϳ� 4��Ʈ FCS�� �ٿ� 16��Ʈ�� �����Ͽ� ��ȯ�ϴ� �Լ� */
char* Sender(char* data) {
	//unsigned short�� ���� ���� �� �ʱ�ȭ
	unsigned short cal = 0;		//data�� 10����
	unsigned short sub = 0b11011; // 2����
	//int�� ���� ���� �� �ʱ�ȭ len�� ��Ʈ ���� cal_len�� shift �̵��ؾ��� ����, before_len�� ���� �̵��ߴ� ����
	int len = 5, cal_len = 0, before_len = 0;
	//char�� �迭 ����
	char data_cpy[100];
	char R[5] = { '0', '0', '0', '0', '\0' };

	strcpy(data_cpy, data);			//data�� ���� data_cpy�� ����
	strcat(data_cpy, R);			//data_cpy�ڿ� R�� �̾����
	/*  cal�� 2������ ����� data�� 10������ ��ȯ�Ͽ� ����  */
	for (int i = 1; i <= 16; i++) //i�� 1���� 16����
	{
		char each_data[2]; //char�� �迭 ����
		each_data[0] = data_cpy[strlen(data_cpy) - i];		//0�Ǵ� 1�� ��Ʈ�� ������
		cal += short_pow(2, i - 1) * (unsigned short)atoi(each_data);		//cal�� ����� ���� data�� 10������ ǥ���� ��
	}

	sub = sub << 11;		//<<�� 11�� shift�̵��� ��
	while (len <= 16)		//len�� 16���� �۰ų� ����������
	{
		//cal�� ������
		//sub�� 11011
		cal = cal ^ sub;	//cal�� sub�� XOR������ cal�� �ٽ� ������

		cal_len = length(cal, before_len);	//shift �̵��ؾ��� ������ ������

		before_len += cal_len;		//cal_len���� ������
		sub = sub >> cal_len;		//sub�� cal_len��ŭ shift�̵��� ���� ���� sub�� ����
		len += cal_len;				//cal_len���� ������
	}
	//cal�� �������� ��Ÿ�� R�� ���ڷ� ���� int�� string���� ����
	for (int i = 0; i < 4; i++)		//i�� 0���� 3����
	{
		R[3 - i] = cal % 2 + 48;	//���ڿ��� ����
		cal = cal / 2;
	}
	strcat(data, R);			//data�� ���� FCS�� ��ġ��
	return data;			//data�� ��ȯ�Ѵ�.
}
/* �� ��Ʈ���� 5 % Ȯ���� ���۹��� �����Ͱ� ������ �� �� �ֵ��� �Ͽ� ��ȯ�ϴ� �Լ� */
char* Transmission_Channel(const char* coded_frame) {
	char* data = (char*)coded_frame;		//���� ���� �����͸� char*�� ��ȯ�Ͽ� ����

	cout << "Coded frame: " << coded_frame << endl;		//���۹��� ������ ���
	srand(time(NULL));									//���� �ʱ�ȭ
	for (int i = 0; i < 16; i++)	//i�� 0���� 15����
	{
		int rand_num = rand() % 100;	//0���� 99������ ������ �������� �����Ѵ�.
		
		if (rand_num < 5)		//5���� ������� �� Ȯ���� 5%�� ���
		{
			if (coded_frame[i] == '0')
				data[i] = '1';			//���������� �����Ѵ�.
			else if (coded_frame[i] == '1')
				data[i] = '0';			//���������� �����Ѵ�.
		}
	}
	return data;		//data ��ȯ
}
/*���۹��� �����Ͱ� ������ ������ �ȳ����� Ȯ���Ͽ� ��ȯ�ϴ� �Լ�*/
void Receiver(const char* received_frame) {
	char* data = (char*)received_frame;				//���۹��� �����͸� char*�� ��ȯ�Ͽ� ����
	cout << "Received frame: " << received_frame << endl;	//���۹��� ������ ���

	//XOR ���� ��
	//unsigned short�� ���� ���� �� �ʱ�ȭ
	unsigned short cal = 0;
	unsigned short sub = 0b11011; // 2����
	//int�� ���� ���� �� �ʱ�ȭ len�� ��Ʈ ���� cal_len�� shift �̵��ؾ��� ����, before_len�� ���� �̵��ߴ� ����
	int len = 5, cal_len = 0, before_len = 0;
	
	char data_cpy[100];			//char�� �迭 ����
	strcpy(data_cpy, data);		//data�� ���ڿ��� data_cpy�� ����
	/*  cal�� 2������ ����� data�� 10������ ��ȯ�Ͽ� ����  */
	for (int i = 1; i <= 16; i++) //i�� 1���� 16����
	{
		char each_data[2]; //char�� �迭 ����
		each_data[0] = data_cpy[strlen(data_cpy) - i];		//0�Ǵ� 1�� ��Ʈ�� ������
		cal += short_pow(2, i - 1) * (unsigned short)atoi(each_data);		//cal�� ����� ���� data�� 10������ ǥ���� ��
	}

	sub = sub << 11;		//<<�� 11�� shift�̵��� ��
	while (len <= 16)		//len�� 16���� �۰ų� ����������
	{
		//cal�� ������
		//sub�� 11011
		cal = cal ^ sub;	//cal�� sub�� XOR������ cal�� �ٽ� ������

		cal_len = length(cal, before_len);	//shift �̵��ؾ��� ������ ������

		before_len += cal_len;		//cal_len���� ������
		sub = sub >> cal_len;		//sub�� cal_len��ŭ shift�̵��� ���� ���� sub�� ����
		len += cal_len;				//cal_len���� ������
	}
	
	//XOR ���� ��
	data[12] = '\0';
	cout << "Reconstructed data: " << data << endl;		//���۹��� �������� 12��Ʈ ���
	if (cal == 0)		//�������� 0�̶��
		cout << "No detected error";	//������ ����
	else				//�������� 0�� �ƴ϶��
		cout << "Receiver has detected error";	//������ �ִ�.

}
/* �Ҵ��� �޸������ϴ� �Լ� */
int memory_free(char* data) {
	delete[]data;		//data�� �޸� ����
	return 0;	//0��ȯ
}
/* num�� ������ short������ ��ȯ�ϴ� �Լ� */
short short_pow(short num,short n) {
	short result = 1;	//short�� ���� ���� �� �ʱ�ȭ
	if (n == 0)		//n�� 0�϶�
		return 1;	//1��ȯ

	for (short i = 0; i < n; i++)	//i�� 0���� n-1����
		result *= num;		//num�� n������ŭ ������
	return result;			//result �� ��ȯ
}
/*  shift���� ��Ű�� ���� ���̸� ��ȯ�ϴ� �Լ�  */
int length(unsigned short cal, int berfore_len) {
	int arr[16];		//int�� �迭 ����
	//cal�� 2������ ����� arr�� �����ϰ� �տ������� 0�� ���ڸ� ��
	int j = 0;		//int�� ���� ����
	while (j < 16)	//j�� 15����
	{
		arr[16 - 1 - j] = cal % 2;	//cal�� 2�� ���� �������� arr[15-j]�� ����
		cal = cal / 2;		//cal/2�� cal�� ����
		j++;	//j=j+1;�� ����
	}
	for (int i = 0; i < 16; i++)	//i�� 0���� 15����
		if (arr[i] != 0)			//0�� ���������� ������ ���� ��
			return i - berfore_len;	//0�� ���������� ������ ���� ���� shift�����Ų ���� ��ŭ ���� ��ȯ
}
