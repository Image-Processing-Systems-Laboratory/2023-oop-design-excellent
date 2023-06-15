#include "Matrix.h"
#include <iostream>
#include <cstdlib>

//member function of Matrix class
Matrix::Matrix()										       //default ������
{
	//��� element�� 0���� �ʱ�ȭ
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] = 0;
		}
	}
}

Matrix::Matrix(double number)                                 //��� element�� ���ڷ� ���� ���� number ������ �ʱ�ȭ�ϴ� ������
{
	//��� element�� number�� �ʱ�ȭ
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] = number;
		}
	}
}

Matrix::Matrix(const Matrix& other)                           //���� ������
{
	//��� element �����Ͽ� ����
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] = other.data[i][j];
		}
	}
}

//element�� 9�� �Է� �޾� ���� �����ϴ� ������
Matrix::Matrix(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33)
{
	//�� ��ġ�� �µ��� �� ����
	data[0][0] = a11;
	data[0][1] = a12;
	data[0][2] = a13;
	data[1][0] = a21;
	data[1][1] = a22;
	data[1][2] = a23;
	data[2][0] = a31;
	data[2][1] = a32;
	data[2][2] = a33;
}

Matrix::Matrix(double(*data)[3])                             //3x3 ũ���� 2���� �迭�� ���ڷ� ���� �޾� �����Ͽ� �����ϴ� ������
{
	//��� element �����Ͽ� ����
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->data[i][j] = data[i][j];
		}
	}
}

Matrix::~Matrix()										       //�޸𸮸� �Ҵ� �����ϴ� �ı���
{
	//��� element �����Ͽ� ����
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] = 0;
		}
	}
}

bool Matrix::SetElement(double element, int row, int col)	   //element�� �� ����
{
	//��ȿ�� �������� �˻� �� �� ����
	if (row >= 0 && row < 3 && col >= 0 && col < 3) {
		data[row][col] = element;   //row ��, col ���� element �� ����
		return true;                //���� �����ϸ� true ��ȯ
	}
	else {
		return false;               //��ȿ���� ���� �����̸� false ��ȯ
	}
}

double Matrix::GetElement(int row, int col)				       //element �� ��ȯ
{
	//��ȿ�� �������� �˻� �� �� ��ȯ
	if (row >= 0 && row < 3 && col >= 0 && col < 3) {
		return data[row][col];      //row ��, col ���� element �� ��ȯ
	}
	else {
		return -1;                   //��ȿ���� ���� �����̸� -1 ��ȯ
	}
}

void Matrix::print()										   //Matrix ���
{
	//3x3 ��� ���
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << data[i][j] << ' ';     //������ element ���̴� �������� ����
		}
		std::cout << std::endl;                 //������ �� ���̴� �������� ����
	}
}

const Matrix Matrix::operator +=(const Matrix& other)          //�ٸ� Matrix�� += ����
{
	//���� ��ġ�� element���� += ����
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] += other.data[i][j];   //�ڽ� ��ü�� �ٸ� ��ü�� ���� += ����
		}
	}

	return *this;        //��ü �ڽ��� ��ȯ
}

const Matrix Matrix::operator +=(double num)                  //��Į�� ���� += ����
{
	//��� element���� ��Į�� �� num�� ���Ѵ�.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] += num;                                //+= ����
		}
	}

	return *this;        //��ü �ڽ��� ��ȯ
}

const Matrix Matrix::operator -=(const Matrix& other)                  //�ٸ� Matrix�� -= ����
{
	//���� ��ġ�� element���� -= ����
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] -= other.data[i][j];   //�ڽ� ��ü�� �ٸ� ��ü�� ���� -= ����
		}
	}

	return *this;        //��ü �ڽ��� ��ȯ
}

const Matrix Matrix::operator -=(double num)                  //��Į�� ���� -= ����
{
	//��� element���� ��Į�� �� num�� ����.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] -= num;                                //-= ����
		}
	}

	return *this;        //��ü �ڽ��� ��ȯ
}

const Matrix Matrix::operator *(const Matrix& other) const             //�ٸ� Matrix�� * ����
{
	Matrix m;           //���� ������ �ӽ� ��ü
	double sum;         //inner product ���� ��

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			sum = 0;

			for (int h = 0; h < 3; h++) {
				sum += (data[i][h] * other.data[h][j]);     //i��� j���� inner product
			}

			m.SetElement(sum, i, j);        //inner product ���� ���� i�� j���� ����
		}
	}

	return m;            //�ӽ� ��ü ��ȯ
}

const Matrix Matrix::operator *(double num) const             //��Į�� ���� * ����
{
	Matrix m;           //���� ������ �ӽ� ��ü

	//��� element���� ��Į�� �� num�� ���Ͽ� m�� �����Ѵ�.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m.SetElement(data[i][j] * num, i, j);        //* ���� ���� i�� j���� ����
		}
	}

	return m;            //�ӽ� ��ü ��ȯ
}