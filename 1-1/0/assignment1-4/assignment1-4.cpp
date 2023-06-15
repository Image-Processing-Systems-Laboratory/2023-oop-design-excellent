#include<iostream>

using namespace std;	//std ���̺귯���� ���Ե� ������� ���

//�Լ� ����
void PutIn_Matrix(double (*Matrix_arr)[3]);				//3*3 �迭�� �� �Է°��� �޴� �Լ�
double MakeInverseMatirx(double(*Matrix_arr)[3], double(*InverseMatrix_arr)[3]);	//Matrix_arr�� ������� �ִٸ� InverseMatrix_arr�� �����ϰ� 1�� ��ȯ�ϴ� �Լ� ���ٸ� 0��ȯ
double det(double(*Matrix_arr)[3]);				//Matrix_arr�� ��Ľ��� ��ȯ�ϴ� �Լ�
void PrintArr(double(*inverseMatrix_arr)[3]);	//3*3 �迭�� ���� ����ϴ� �Լ�

int main()
{
	double Matrix_arr[3][3];			//double�� 2���� �迭 3*3 ����
	double inverseMatrix_arr[3][3];		//double�� 2���� �迭 3*3 ����
	cout << "3*3 Matrix�� ���� �Է��ض�" << endl;
	PutIn_Matrix(Matrix_arr);				//3*3 �迭�� �� �Է°��� ����
	/*  Matrix_arr�� ������� inverseMatirx_arr�� ����  */
	if (MakeInverseMatirx(Matrix_arr, inverseMatrix_arr) == 1)		//������� �ִٸ� MakeInverseMatirx�Լ��� 1�� ��ȯ
	{
		cout << "3*3 Matrix�� ������� " << endl;
		PrintArr(inverseMatrix_arr);						//InverseMatirx_arr �迭�� ���� ���
	}
	return 0;
}
/*  3*3�迭�� �Է°��� �޴� �Լ�   */
void PutIn_Matrix(double(*Matrix_arr)[3]) {
	/* Matrix_arr[0][0]���� Matrix_arr[2][2]���� ���� �Է� ���� */
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> Matrix_arr[i][j];		//Matrix_arr[i][j]�� ���� �Է� �޴´�
}
/*  Matrix_arr�� ������� �ִٸ� InverseMatrix_arr�� �����ϰ� 1�� ��ȯ�ϴ� �Լ� ���ٸ� 0��ȯ   */
double MakeInverseMatirx(double(*Matrix_arr)[3], double(*InverseMatrix_arr)[3]) {
	/*  �� doube�� ������ ���� �� ������ Matrix_arr�� ������ �ʱ�ȭ��  */
	double a = Matrix_arr[0][0], b = Matrix_arr[0][1], c = Matrix_arr[0][2];
	double d = Matrix_arr[1][0], e = Matrix_arr[1][1], f = Matrix_arr[1][2];
	double g = Matrix_arr[2][0], h = Matrix_arr[2][1], i = Matrix_arr[2][2];

	if (det(Matrix_arr) == 0)	//��Ľ��� ���� 0 �̸�
	{
		cout << "The inverse matrix does not exist" << endl;
		return 0;
	}
	/*  �� ������� ���� InverseMatrix_arr�� �迭�� ������  */
	InverseMatrix_arr[0][0] = (e * i - f * h) / det(Matrix_arr);
	InverseMatrix_arr[0][1] = (c * h - b * i) / det(Matrix_arr);
	InverseMatrix_arr[0][2] = (b * f - c * e) / det(Matrix_arr);
	InverseMatrix_arr[1][0] = (f * g - d * i) / det(Matrix_arr);
	InverseMatrix_arr[1][1] = (a * i - c * g) / det(Matrix_arr);
	InverseMatrix_arr[1][2] = (c * d - a * f) / det(Matrix_arr);
	InverseMatrix_arr[2][0] = (d * h - e * g) / det(Matrix_arr);
	InverseMatrix_arr[2][1] = (b * g - a * h) / det(Matrix_arr);
	InverseMatrix_arr[2][2] = (a * e - b * d) / det(Matrix_arr);
	return 1;
}
/*  Matrix_arr�� ��Ľ��� ��ȯ�ϴ� �Լ�  */
double det(double(*Matrix_arr)[3]) {
	/*  ��Ľ��� ��ȯ��  */
	return (Matrix_arr[0][0] * Matrix_arr[1][1] * Matrix_arr[2][2]
		+ Matrix_arr[0][1] * Matrix_arr[1][2] * Matrix_arr[2][0]
		+ Matrix_arr[0][2] * Matrix_arr[1][0] * Matrix_arr[2][1]
		- Matrix_arr[0][2] * Matrix_arr[1][1] * Matrix_arr[2][0]
		- Matrix_arr[1][2] * Matrix_arr[2][1] * Matrix_arr[0][0]
		- Matrix_arr[2][2] * Matrix_arr[0][1] * Matrix_arr[1][0]);
}
/*  3*3 �迭�� ���� ����ϴ� �Լ�  */
void PrintArr(double(*inverseMatrix_arr)[3]) {
	/* inverseMatrix_arr[0][0]���� inverseMatrix_arr[2][2]���� ���� ����� */
	for (int i = 0; i < 3; i++)						//i�� 0���� 2����
	{
		for (int j = 0; j < 3; j++)					//j�� 0���� 2����
			cout << inverseMatrix_arr[i][j]<<' ';	//inverseMatrix_arr[i][j]���� �����
		cout << endl;								//����
	}
}