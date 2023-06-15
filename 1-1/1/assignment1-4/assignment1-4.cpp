#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int matrix[3][3]; // 행렬을 저장할 배열
	int cofactor[3][3]; // 여인수를 저장할 배열
	cout << "Enter elements of the matrix" << endl; // 행렬의 원소를 입력받음
	for (int i = 0; i < 3; i++)  // 반복문을 통해 세 행의 원소를 받음
	{
		cout << "Enter row " << "[" << i + 1 << "]" << endl;
		for (int j = 0; j < 3; j++) // 각 행의 세 개의 원소를 받음
		{
			cin >> matrix[i][j];
		}
	}
	cout << "The matrix is" << endl; // 행렬을 출력함
	for (int i = 0; i < 3; i++) // 반복문을 통해 세 행의 원소를 출력함
	{
		for (int j = 0; j < 3; j++) // 각 행의 세 개의 원소를 출력함
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	float determinant = 0; // 행렬식을 저장할 변수
	for (int i = 0; i < 3; i++) // 행렬식을 구함
	{
		int i1 = (i + 1) % 3, i2 = (i + 2) % 3;
		determinant = determinant + matrix[0][i] * (matrix[1][i1] * matrix[2][i2] - matrix[1][i2] * matrix[2][i1]);
	}
	cout << "Determinant: " << determinant << endl; // 행렬식을 출력함

	if (determinant == 0) // 행렬식이 0일 경우
	{
		cout << "Inverse of matrix does not exist." << endl; // 역행렬이 존재하지 않음
		return 0; // 프로그램 종료
	}
	else // 그 외의 경우
	{
		for (int i = 0; i < 3; i++) // 여인수를 구함
		{
			for (int j = 0; j < 3; j++)
			{
				int i1 = (i + 1) % 3, i2 = (i + 2) % 3, j1 = (j + 1) % 3, j2 = (j + 2) % 3;
				cofactor[i][j] = matrix[i1][j1] * matrix[i2][j2] - matrix[i1][j2] * matrix[i2][j1];
			}
		}
	}
	cout << "Cofactor matrix is: \n"; // 여인수를 출력함
	for (int i = 0; i < 3; i++) // 반복문을 통해 세 행의 원소를 출력함
	{
		for (int j = 0; j < 3; j++) // 각 행의 세 개의 원소를 출력함
		{
			cout << cofactor[i][j] << "\t";
		}
		cout << endl;
	}

	int transcofactor[3][3]; // 여인수의 전치행렬을 저장할 배열
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			transcofactor[i][j] = cofactor[j][i]; // 행과 열을 바꿔서 저장함
		}
	}

	cout << "transpose matrix is: \n"; // 여인수의 전치행렬을 출력함
	for (int i = 0; i < 3; i++) // 반복문을 통해 세 행의 원소를 출력함
	{
		for (int j = 0; j < 3; j++) // 각 행의 세 개의 원소를 출력함
		{
			cout << cofactor[j][i] << "\t";
		}
		cout << endl;
	}

	cout << "Inverse of matrix is: \n"; // 역행렬을 출력함

	for (int i = 0; i < 3; i++) // 반복문을 통해 세 행의 원소를 출력함
	{
		for (int j = 0; j < 3; j++) // 각 행의 세 개의 원소를 출력함
		{
			float inverse = transcofactor[i][j] / determinant; // 전치행렬에서 행렬식으로 나누어 역행렬을 구함
			cout << inverse << "\t";
		}
		cout << endl;
	}
}