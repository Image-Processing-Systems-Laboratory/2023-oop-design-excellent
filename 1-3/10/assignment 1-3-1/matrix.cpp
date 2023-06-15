#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141592 //PI 상수 선언

//두 개의 3x3 행렬의 곱을 계산해주는 함수
void product(double(*a)[3], double(*b)[3], double(*c)[3]);

int main(void)
{
	double deg, rad, in_coordinate[3], out_coordinate[3] = { 0 };
	int i, j;

	//사용자로부터 각도, 3차원 좌표를 입력 받는다
	cout << "Degree : ";
	cin >> deg;
	cout << "Coordinate : ";
	for (i = 0; i < 3; i++)
	{
		cin >> in_coordinate[i];
	}

	//입력 받은 각도를 라디안으로 바꿔준다
	rad = deg * (PI / 180);

	//T1, T2, T3 변환 행렬을 초기화해준다
	double trans_one[3][3] = { {cos(rad),(-1) * sin(rad),0}, {sin(rad),cos(rad),0}, {0,0,1} };
	double trans_two[3][3] = { {-1,0,0}, {0,1,0}, {0,0,0} };
	double trans_thr[3][3] = { {1,0,0},{0,1,0},{0,0,0} };
	double trans_temp[3][3] = { 0 };
	double trans[3][3] = { 0 };

	//변환 행렬을 계산한다
	product(trans_two, trans_one, trans_temp);
	product(trans_thr, trans_temp, trans);

	//T 행렬과 입력 받은 좌표의 곱을 계산해준다
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			out_coordinate[i] += trans[i][j] * in_coordinate[j];
		}
	}

	//변환된 행렬을 출력해준다
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