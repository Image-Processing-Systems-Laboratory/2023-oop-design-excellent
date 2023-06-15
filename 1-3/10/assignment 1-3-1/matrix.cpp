#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141592 //PI ��� ����

//�� ���� 3x3 ����� ���� ������ִ� �Լ�
void product(double(*a)[3], double(*b)[3], double(*c)[3]);

int main(void)
{
	double deg, rad, in_coordinate[3], out_coordinate[3] = { 0 };
	int i, j;

	//����ڷκ��� ����, 3���� ��ǥ�� �Է� �޴´�
	cout << "Degree : ";
	cin >> deg;
	cout << "Coordinate : ";
	for (i = 0; i < 3; i++)
	{
		cin >> in_coordinate[i];
	}

	//�Է� ���� ������ �������� �ٲ��ش�
	rad = deg * (PI / 180);

	//T1, T2, T3 ��ȯ ����� �ʱ�ȭ���ش�
	double trans_one[3][3] = { {cos(rad),(-1) * sin(rad),0}, {sin(rad),cos(rad),0}, {0,0,1} };
	double trans_two[3][3] = { {-1,0,0}, {0,1,0}, {0,0,0} };
	double trans_thr[3][3] = { {1,0,0},{0,1,0},{0,0,0} };
	double trans_temp[3][3] = { 0 };
	double trans[3][3] = { 0 };

	//��ȯ ����� ����Ѵ�
	product(trans_two, trans_one, trans_temp);
	product(trans_thr, trans_temp, trans);

	//T ��İ� �Է� ���� ��ǥ�� ���� ������ش�
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			out_coordinate[i] += trans[i][j] * in_coordinate[j];
		}
	}

	//��ȯ�� ����� ������ش�
	cout << endl << "Output : ";

	for (i = 0; i < 3; i++)
	{
		cout << out_coordinate[i] << " ";
	}

	cout << endl;

	return 0;
}

void product(double(* a)[3], double(* b)[3], double(*c)[3])
{
	int i, j, k;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}