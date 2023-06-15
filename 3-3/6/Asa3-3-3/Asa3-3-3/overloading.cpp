#include "overloading.h"

using namespace std;

// 생성자. 행렬의 크기가 3*3이므로 rows와 cols를 3으로 바로 초기화한다.
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

// 소멸자: 동적 할당된 data 해제
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
	// 문제에서는 3*3 행렬을 명백하게 제시했지만,
	// 일반적인 예외 사항을 추가하였습니다.
	// 이는 뺄셈과 곱셈에서도 동일하게 적용하였습니다.
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
		Arrayoverloading result(this->rows, Mul_other.cols); // result 결과 행렬 생성

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < Mul_other.cols; j++)
			{
				result.data[i][j] = 0;  // 결과 행렬 초기화

				for (int k = 0; k < cols; k++)
				{
					result.data[i][j] += data[i][k] * Mul_other.data[k][j];
				} // 초기화 후 결과 삽입
			}
		}

		return result; // 결과 행렬 반환
	}
}
