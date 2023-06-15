#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;	//std ���̺귯���� ���Ե� ������� ���

//�Լ� ����
void PrintSierTriangle(int k, int x_size, int y_size);	//�þ��ɽ�Ű �ﰢ���� ����ϴ� �Լ�
void PutSierTriangle(int k, int x_size, int y_size);	//�þ��� ��Ű �ﰢ���� �迭�� �����ϴ� �Լ�
void init_Drawing_Array(int x_size, int y_size);		//�������� Sier_Triangle�� ���� �޸��Ҵ��� �ϰ� ��ĭ���� �ʱ�ȭ�� �� ������ ĭ���� �ι��ڸ� ���Խ�Ű�� �Լ�
void outit_Drawing_Array(int x_size, int y_size);		//�������� Sier_Triangle�� ���� �޸��Ҵ��� �����ϴ� �Լ�

//�������� ����
unsigned char** Sier_Triangle;		//unsigned char�� ���� ������ �������� ����

int main()
{
	unsigned char k;			//unsigned char�� ���� ����
	int k_int, N;				//int�� ���� ����
	cout << "�Է�: ";			//�Է��� �þ��ɽ�Ű �ﰢ���� ȣ���� ����
	cin >> k;					//�Է��� �þ��ɽ�Ű �ﰢ���� ȣ���� �Է� ����
	/* �ƽ�Ű�ڵ忡 ���� -48�� ���� */
	k_int = k - 48;				//int�� ����k_int�� �Է¹��� k�� ���� int������ ����
	
	N = pow(2, k_int - 1);		//N�� 2�� k_int-1 ������ �־��ش�.
	int x_size = 5 * N + N - 1;		//�ﰢ�� �Ʒ����� ���̸� ������ ����
	int y_size = 3 * N;					//�ﰢ�� ������ ���̸� ������ ����
	/*  �迭 �����  */
	init_Drawing_Array(x_size, y_size);				// �����Ҵ��� ���ִ� �Լ� ȣ��

	PutSierTriangle(k_int, (x_size - 1) / 2, 0);		//�þ��ɽ�Ű �ﰢ���� �����ϴ� �Լ��� �Ʒ����� �߰������� ���̸� �Է�
	PrintSierTriangle(k_int, x_size, y_size);			//�þ��ɽ�Ű �ﰢ���� ����ϴ� �Լ�
	/*  �迭 �����ϱ�  */
	outit_Drawing_Array(x_size, y_size);			// �����Ҵ��� ���� ���ִ� �Լ� ȣ��
	
	return 0;
}
/*  �þ��� ��Ű �ﰢ���� �迭�� �����ϴ� �Լ�  */
void PutSierTriangle(int k, int x, int y) {
	/*  k=1�϶��� �ﰢ���� �迭�� ����  */
	if (k == 1)						//1�� ���
	{
		Sier_Triangle[y][x] = '$';		//Sier_Triangle[y][x]�� $�� �ʱ�ȭ��
		Sier_Triangle[y + 1][x - 1] = Sier_Triangle[y + 1][x + 1] = '$';	//Sier_Triangle[y+1][x-1]�� Sier_Triangle[y+1][x+1]�� $�� �ʱ�ȭ��
		for (int i = -2; i <= 2; i++)		//i�� -2���� 2����
			Sier_Triangle[y + 2][x + i] = '$';	//Sier_Triangle[y+2][x-2]���� Sier_Triangle[y+2][x+2]���� $�� �ʱ�ȭ��
	}
	/*  (k-1)�϶��� �ﰢ���� �� ������ ����Ʈ�� ������� ����  */
	else
	{
		PutSierTriangle(k - 1, x, y);		//x,y�� ������ k-1�϶��� �ﰢ�� ����
		PutSierTriangle(k - 1, x - 3 * pow(2, k - 2), y + 3 * pow(2, k - 2));	//x - 3 * pow(2, k - 2),y + 3 * pow(2, k - 2)�� ������ k-1�϶��� �ﰢ�� ����
		PutSierTriangle(k - 1, x + 3 * pow(2, k - 2), y + 3 * pow(2, k - 2));	//x + 3 * pow(2, k - 2),y + 3 * pow(2, k - 2)�� ������ k-1�϶��� �ﰢ�� ����
	}
}
/*  �þ��ɽ�Ű �ﰢ���� ����ϴ� �Լ�  */
void PrintSierTriangle(int k, int x_size, int y_size) {
	for (int i = 0; i < y_size; i++)		//i�� 0���� y_size-1����
	{
		for (int j = 0; j < x_size; j++)	//j�� 0���� x_size-1����
			cout << Sier_Triangle[i][j];	//Sier_Triangle[i][j]���� ���
		cout << endl;						//����
	}
}
/*  �������� Sier_Triangle�� ���� �޸��Ҵ��� �ϰ� ��ĭ���� �ʱ�ȭ��
	�� ������ ĭ���� �ι��ڸ� ���Խ�Ŵ  */
void init_Drawing_Array(int x_size, int y_size) {

	/* �� ����� */
	Sier_Triangle = (unsigned char**)malloc(sizeof(unsigned char*) * y_size);			//(sizeof(unsigned char**) * y_size)��ŭ�� �����Ҵ���
	/* �� ����� */
	for (int i = 0; i < y_size; i++)	//i�� 0���� y_size-1����
		Sier_Triangle[i] = (unsigned char*)malloc(sizeof(unsigned char) * x_size + 1);	//(sizeof(unsigned char*) * x_size + 1)��ŭ�� �����Ҵ���

	for (int i = 0; i < y_size; i++)	//i�� 0���� y_size-1����
	{
		for (int j = 0; j < x_size; j++)		//j�� 0���� x_size-1����
			Sier_Triangle[i][j] = ' ';			//�迭�� ���� �ֱ�
		Sier_Triangle[i][x_size] = '\0';		//�� ���� �������࿡ �� ���� �ֱ�
	}
}
/*  �������� Sier_Triangle�� ���� �޸��Ҵ��� ������  */
void outit_Drawing_Array(int x_size, int y_size) {

	for (int i = 0; i < y_size; i++) //i�� 0���� y_size-1����
		free(Sier_Triangle[i]);		//0���� y_size-1������ �����޸� �Ҵ��� ������
	free(Sier_Triangle);			//**Sier_Triangle�� �����޸� �Ҵ��� ������
}
