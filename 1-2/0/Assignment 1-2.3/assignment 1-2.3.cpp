#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;


//�Լ�����
char** memory_alloc2D(int n);			//�޸� �Ҵ����ִ� �Լ�
int memory_free2D(char** ppMemAllocated, int n);	//�޸� �������ִ� �Լ�
int Check_Strncmp(char* data, char* Input);			//'*'�� '?'�� ��Ģ�� �°� ���ڿ��� ���ٸ� 0��ȯ �ٸ��ٸ� 1��ȯ ���ִ� �Լ�


void main()
{
	char File_Name[100], data[100];	//char�� �迭 ����
	int n;							//int�� ���� ����
	char** Input_char;				//char�� ���������� ����
	ifstream fin;					//���� �д� ��ü�� fin ����

	cout << "Input file name :";
	cin >> File_Name;		//filename ���� �Է¹޴´�.
	cin >> n;				//�Է��� ���ڿ��� ��
	Input_char = memory_alloc2D(n);
	for (int i = 0; i < n; i++)		//�� n�� �ݺ���
	{
		cin >> Input_char[i];			//���ڿ��� �Է� �޴´�
	}
	

	cout << endl << "Output :" << endl;
	for (int i = 0; i < n; i++)		//�� n�� �ݺ���
	{
		fin.open(File_Name);		//File_Name�� ������ ����.
		if (!fin) {					//file�� ������ �ʾ��� ���
			cout << "no" << endl;
		}
		while (!fin.eof())			//������ ���� �����ϱ� ������ �ݺ�
		{
			fin.getline(data, 100);		//������ �о�鿩 data �迭�������Ѵ�.

			if (Check_Strncmp(data, Input_char[i]) == 0)			//�Է¹��� '*', '?'�� ��Ģ�� �´� ���ڿ��� ������ 0 ���
				cout << data << endl;								//data�� ����� ���ڿ� ���
		}
		fin.close();		//������ �ݴ´�.
	}
	memory_free2D(Input_char, n);		//�Ҵ�� �޸𸮸� �ݴ´�.
}
/*  '?', '*' �� ���Ͽ� �´� ���ڿ��� ������ 0�� ��ȯ�ϰ� ���ٸ� 1�� ��ȯ��  */
int Check_Strncmp(char*data, char*Input) {
	int len_Input = strlen(Input);	//Input�� ���� ����
	int len_data = strlen(data);	//data�� ���� ����
	char Input_back[100], data_back[100];		//'?'��'*' �� ���ڸ� �����Ҷ� ����ϴ� �迭 ����
	char data_cpy[100], Input_cpy[100];			//�迭�� �����Ҷ����
	strcpy(data_cpy, data);						//data�� ����� ���ڿ��� data_cpy�� ����
	strcpy(Input_cpy, Input);					//Input�� ����� ���ڿ��� Input_cpy�� ����
	int after = 0;								//int�� �迭 ����
	for (int i = 0; i < len_Input; i++)			//i�� 0���� len_Input-1����
	{
		
		if (Input[i] == '*')			//input[i]�� '*'�� ������
		{
			if (strncmp(data, Input, i) == 0)	//data�� Input�� i-1���� ���� �����϶�
			{

				/*  *���� ���ڿ� ����  */
				for (int k = 0; k < len_data - i; k++)	//k�� 0���� len_data-i-1����
				{
					Input_back[k] = Input[k + i + 1];	//Input�� �� ���ڿ��� Input_back�� ����
					data_back[k] = data[k + i + 1];		//data�� �� ���ڿ��� data_back�� ����
				}
				for (int j = i + 1; j < len_data; j++)	//j�� i+1���� len_data-1����
					if (Input[j] == '?')	//'?'�� ������
					{
						if (Check_Strncmp(data_back, Input_back) == 0)	//�� ���ڿ��� üũ�Ѵ�
							return 0;									//���ٸ� 0 ��ȯ
						else
							return 1;									//�ٸ��� 1��ȯ
					}
				return 0;	//0��ȯ
			}
			return 1;		//1��ȯ

		}
		else if (Input[i] == '?')	//?�� �ִٸ�
		{
			data_cpy[i] = ' ';		//�������� ����
			Input_cpy[i] = ' ';		//�������� ����
			after = i;				//?�� �ִ� ��ġ ����
		}
	}
	if (strcmp(data_cpy, Input_cpy) == 0)		//�� ���ڿ��� ���ٸ�
		return 0;		//0��ȯ

	for (int k = 0; k <= len_data - after; k++)	//k�� 0����  len_data-after-1����
	{
		Input_back[k] = Input[k + 1];			//Input�� �� ���ڿ��� Input_back�� ����
		data_back[k] = data[k + 1];				//data�� �� ���ڿ��� data_back�� ����
	}
	for (int j = after + 1; j < len_data; j++)	//j�� after+1���� len_data-1���� 
		if (Input[j] == '*')					//Input[j]�� '*'�̶��
		{
			if (Check_Strncmp(data_back, Input_back) == 0)	//�� ���ڿ��� üũ�Ѵ�
				return 0;				//0��ȯ
			else
				return 1;				//1��ȯ
		}
}
	
/*  �޸� �Ҵ��� ���ִ� �Լ� */
char** memory_alloc2D(int n) {
	char** ppMem2d = new char* [n];
	if (ppMem2d == 0)			//�޸� �Ҵ翡 �����ϸ�
		return 0;
	for (int i = 0; i < n; i++)	//i�� 0���� n-1����
		ppMem2d[i] = new char[200];	//200������ ��ŭ �Ҵ�

	for (int i = 0; i < n; i++)	//i�� 0���� n-1����
		if (ppMem2d[i] == 0)	//�޸� �Ҵ��� ���ϸ�
		{
			delete[]ppMem2d;	//�޸� �����Ѵ�.
			return 0;
		}
	return ppMem2d;			//ppMem2d ��ȯ
}
/*  �޸� �Ҵ�� �޸𸮸� ���� ���ִ� �Լ�  */
int memory_free2D(char** ppMemAllocated,int n) {
	if (ppMemAllocated == 0)		//������ �޸𸮰� ������
		return -1;					
	for (int i = 0; i < n; i++)		//i�� 0���� n-1����
		if (ppMemAllocated[i])		
			delete[] ppMemAllocated[i];	//�Ҵ�� �޸�����
	delete[] ppMemAllocated;	//�Ҵ�� �޸�����
	return 0;
}

