#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int matrix[3][3]; // ����� ������ �迭
	int cofactor[3][3]; // ���μ��� ������ �迭
	cout << "Enter elements of the matrix" << endl; // ����� ���Ҹ� �Է¹���
	for (int i = 0; i < 3; i++)  // �ݺ����� ���� �� ���� ���Ҹ� ����
	{
		cout << "Enter row " << "[" << i + 1 << "]" << endl;
		for (int j = 0; j < 3; j++) // �� ���� �� ���� ���Ҹ� ����
		{
			cin >> matrix[i][j];
		}
	}
	cout << "The matrix is" << endl; // ����� �����
	for (int i = 0; i < 3; i++) // �ݺ����� ���� �� ���� ���Ҹ� �����
	{
		for (int j = 0; j < 3; j++) // �� ���� �� ���� ���Ҹ� �����
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	float determinant = 0; // ��Ľ��� ������ ����
	for (int i = 0; i < 3; i++) // ��Ľ��� ����
	{
		int i1 = (i + 1) % 3, i2 = (i + 2) % 3;
		determinant = determinant + matrix[0][i] * (matrix[1][i1] * matrix[2][i2] - matrix[1][i2] * matrix[2][i1]);
	}
	cout << "Determinant: " << determinant << endl; // ��Ľ��� �����

	if (determinant == 0) // ��Ľ��� 0�� ���
	{
		cout << "Inverse of matrix does not exist." << endl; // ������� �������� ����
		return 0; // ���α׷� ����
	}
	else // �� ���� ���
	{
		for (int i = 0; i < 3; i++) // ���μ��� ����
		{
			for (int j = 0; j < 3; j++)
			{
				int i1 = (i + 1) % 3, i2 = (i + 2) % 3, j1 = (j + 1) % 3, j2 = (j + 2) % 3;
				cofactor[i][j] = matrix[i1][j1] * matrix[i2][j2] - matrix[i1][j2] * matrix[i2][j1];
			}
		}
	}
	cout << "Cofactor matrix is: \n"; // ���μ��� �����
	for (int i = 0; i < 3; i++) // �ݺ����� ���� �� ���� ���Ҹ� �����
	{
		for (int j = 0; j < 3; j++) // �� ���� �� ���� ���Ҹ� �����
		{
			cout << cofactor[i][j] << "\t";
		}
		cout << endl;
	}

	int transcofactor[3][3]; // ���μ��� ��ġ����� ������ �迭
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			transcofactor[i][j] = cofactor[j][i]; // ��� ���� �ٲ㼭 ������
		}
	}

	cout << "transpose matrix is: \n"; // ���μ��� ��ġ����� �����
	for (int i = 0; i < 3; i++) // �ݺ����� ���� �� ���� ���Ҹ� �����
	{
		for (int j = 0; j < 3; j++) // �� ���� �� ���� ���Ҹ� �����
		{
			cout << cofactor[j][i] << "\t";
		}
		cout << endl;
	}

	cout << "Inverse of matrix is: \n"; // ������� �����

	for (int i = 0; i < 3; i++) // �ݺ����� ���� �� ���� ���Ҹ� �����
	{
		for (int j = 0; j < 3; j++) // �� ���� �� ���� ���Ҹ� �����
		{
			float inverse = transcofactor[i][j] / determinant; // ��ġ��Ŀ��� ��Ľ����� ������ ������� ����
			cout << inverse << "\t";
		}
		cout << endl;
	}
}