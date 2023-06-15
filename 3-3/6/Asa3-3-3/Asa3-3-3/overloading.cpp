#include "overloading.h"

using namespace std;

// ������. ����� ũ�Ⱑ 3*3�̹Ƿ� rows�� cols�� 3���� �ٷ� �ʱ�ȭ�Ѵ�.
Arrayoverloading::Arrayoverloading()
{
	rows = 3;
	cols = 3;
	data = new double* [rows];
	for (int i = 0; i < rows; i++) data[i] = new double[cols];
}

Arrayoverloading::Arrayoverloading(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	
	data = new double* [rows];
	for (int i = 0; i < rows; i++) data[i] = new double[cols];
}

// �Ҹ���: ���� �Ҵ�� data ����
Arrayoverloading::~Arrayoverloading()
{
	for (int i = 0; i < rows; i++) delete[] data[i];
	delete data;
}

void Arrayoverloading::printmatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}

void Arrayoverloading::inputarray()
{
	double input_num = 0;
	cout << "Please input array data in one line!" << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << "input rows of " << i << " >>> ";
		for (int j = 0; j < cols; j++)
		{
			cin >> input_num;
			if (cin.fail())
			{
				cerr << "Error: number you input that [" << i << "][" << j << "] is not double value." << endl;
				exit(EXIT_FAILURE);
			}
			else
				data[i][j] = input_num;
		}
	}
}

void Arrayoverloading::operator += (const Arrayoverloading& Plus_other)
{
	if (Plus_other.rows != this->rows || Plus_other.cols != this->cols)
	{
		cerr << "Error: matrix sizes are different!" << endl;
		exit(EXIT_FAILURE);
	}
	// ���������� 3*3 ����� ����ϰ� ����������,
	// �Ϲ����� ���� ������ �߰��Ͽ����ϴ�.
	// �̴� ������ ���������� �����ϰ� �����Ͽ����ϴ�.
	else
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
				data[i][j] += Plus_other.data[i][j];
		}
	}
}

void Arrayoverloading::operator -= (const Arrayoverloading& Sub_other)
{
	if (Sub_other.rows != this->rows || Sub_other.cols != this->cols)
	{
		cerr << "Error: matrix sizes are different!" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
				data[i][j] -= Sub_other.data[i][j];
		}
	}
}

Arrayoverloading Arrayoverloading::operator* (const Arrayoverloading& Mul_other)
{
	if (this->cols != Mul_other.rows)
	{
		cerr << "Error: columns in the first matrix and rows in the second matrix are different." << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Arrayoverloading result(this->rows, Mul_other.cols); // result ��� ��� ����

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < Mul_other.cols; j++)
			{
				result.data[i][j] = 0;  // ��� ��� �ʱ�ȭ

				for (int k = 0; k < cols; k++)
				{
					result.data[i][j] += data[i][k] * Mul_other.data[k][j];
				} // �ʱ�ȭ �� ��� ����
			}
		}

		return result; // ��� ��� ��ȯ
	}
}
