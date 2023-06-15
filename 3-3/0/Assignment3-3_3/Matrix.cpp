#include "Matrix.h"


//����Ʈ ������
Matrix::Matrix() {
	//���� �ʱ�ȭ
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->data[i][j] = 0;
}

//�Ҹ���
Matrix::~Matrix() {}

//data�� �������ִ� �Լ�
void Matrix::setData(double** data) {
	//data�� ����� �� ����
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->data[i][j] = data[i][j];
}
//�� ��Ҹ� �������ִ� �Լ�
void Matrix::setElement(double data,int row,int col) {
	this->data[row][col] = data;		//row,col�� data �� ����
}

//����� ����ϴ� �Լ�
void Matrix::printMatrix() {
	//�� ��� ���
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << this->data[i][j] << " ";		//���� " "�� �����Ͽ� ���
		std::cout << std::endl;							//���� �������� �����Ͽ� ���
	}
}

//+=Matrix operator
Matrix Matrix::operator+=(const Matrix& mat) {
	//������ ��ҳ��� ���Ͽ� ����
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->data[i][j] += mat.data[i][j];		//�� ��ҿ� �´� ��ġ���� ���ؼ� ����


	return *this;
}
//+=val operator
Matrix Matrix::operator+=(const double val) {
	//������ ��ҿ� val�� ���Ͽ� ����
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->data[i][j] += val;		//��� ��ҿ� val�� ���ؼ� ����
	
	return *this;
}
//-=Matrix operator
Matrix Matrix::operator-=(const Matrix& mat) {
	//������ ��ҳ��� ���� ����
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->data[i][j] -= mat.data[i][j];		//�� ��ҿ� �´� ��ġ���� ���� ����

	return *this;
}
//-=val operator
Matrix Matrix::operator-=(const double val) {
	//������ ��ҿ� val�� �� ����
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->data[i][j] -= val;		//��� ��ҿ� val�� ���� ����

	return *this;
}
//*Matrix operator
Matrix Matrix::operator*(const Matrix& mat) {
	Matrix result;
	//����� ������ ����� result�� ����
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			double sum = 0;					//������� �� ����� �� ���� ������ ����
			for (int k = 0; k < 3; k++)
				sum += this->data[i][k] * mat.data[k][j];		//����� �� ����
			result.setElement(sum, i, j);		//�������� ��� ����
		}
	}
	return result;
}
//*val operator
Matrix Matrix::operator*(const double val) {
	Matrix result;
	//������ ��ҿ� val�� ���Ͽ� ����
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result.setElement(this->data[i][j] * val, i, j);		//��� ��ҿ� val�� ���Ͽ� ����

	return result;
}
