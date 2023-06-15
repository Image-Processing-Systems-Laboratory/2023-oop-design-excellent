#include <iostream>
#include <cmath>
using namespace std;

// 2x2����� deterninant ����ϴ� �Լ��� prototype
int det_22(int i1, int i2, int j1, int j2, int mat[][3]);

int main()
{
	// �Է°��� �޴� matrix�迭, cofactor�� ����ؼ� ������ cofact �迭 ���� �� �ʱ�ȭ
	int matrix[3][3]{}, cofact[3][3]{}, i, j, det = 0;
	// ���Լ��� ����Ͽ� ������ inverse �迭 ���� �� �ʱ�ȭ. �����
	double inverse[3][3]{};
	
	// �Է°� �Է¹ޱ�
	cout << "Enter 3x3 Matrix" << endl;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			cin >> matrix[i][j];
	cout << endl;

	// 3x3 �迭�� deterninant ����ؼ� det ������ ����
	// ù��° ���� �������� det ���
	for (i = 0; i < 3; i++)
		det += matrix[i][0] * det_22((i + 1) % 3, (i + 2) % 3, 1, 2, matrix) * pow(-1, i);

	// det�� 0���ϸ� ������� �������� �ʴ´ٴ� ���� ��� �� ���α׷� ����
	if (det == 0)
	{
		cout << "The inverse matrix does not exist." << endl;
		return 0;
	}

	// ���� �ݺ������� cofactor ��� �� ����
	for(i = 0; i < 3; i++) // i�� ���� �ǹ�
		for (j = 0; j < 3; j++) // j�� ���� �ǹ�
			cofact[i][j] = det_22((i + 1) % 3, (i + 2) % 3, (j + 1) % 3, (j + 2) % 3, matrix) * pow(-1, i + j);

	// ���� �ݺ����� ���� cofactor�� transpose�Ͽ� ���� matrix�� ����
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			matrix[j][i] = cofact[i][j];

	// ���Լ� ��� �� ���
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			inverse[i][j] = static_cast<double>(matrix[i][j]) / det; // double�� ���� ����ȯ
			cout << right; // ��½� ������ ����
			cout.width(5); // ��� ĭ���� 5ĭ���� �������� ���ü� ����
			cout.precision(2); // �ִ� �Ҽ��� �Ʒ� 2�ڸ����� ���
			cout << inverse[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

// 2x2 �迭 ��� �Լ�
int det_22(int i1, int i2, int j1, int j2, int mat[][3])
{
	// ���� �ǹ��ϴ� i1�� i2�� ���Ͽ� i1�� �� ũ�� ���� ����ġ
	if (i1 > i2)
	{
		int temp = i1;
		i1 = i2;
		i2 = temp;
	}
	// ���� �ǹ��ϴ� j1�� j2�� ���Ͽ� j1�� �� ũ�� ���� ����ġ
	if (j1 > j2)
	{
		int temp = j1;
		j1 = j2;
		j2 = temp;
	}
	// �ռ� ó���� �� �� ���� i1, i2, j1, j2�� ���� determinant ��� �� ��ȯ
	return mat[i1][j1] * mat[i2][j2] - mat[i1][j2] * mat[i2][j1];
}

