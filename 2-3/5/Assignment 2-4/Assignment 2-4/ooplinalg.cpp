#include "ooplinalg.h"
#include <iostream>

using namespace ooplinag;

Matrix::Matrix() : rows(0), cols(0)								//생성자 단순 생성만
{
	data = new float* [rows];
	for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
	}
}

Matrix::Matrix(const Matrix& mat) : rows(0), cols(0)			//생성자 (데이터가 있음)
{
	this->rows = mat.rows;
	this->cols = mat.cols;
	this->data = new float* [rows];
	for (int i = 0; i < rows; i++) {
		this->data[i] = new float[cols];
		for (int j = 0; j < cols; j++) {
			this->data[i][j] = mat.data[i][j];
		}
	}
}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)		//생성자 (row와 col만 있음)
{
	this->data = new float* [rows];
	for (int i = 0; i < rows; i++) {
		this->data[i] = new float[cols];
		for (int j = 0; j < cols; j++) {

			float input;
			std::cout << "input [" << i << "] [" << j << "]: ";
			std::cin >> input;

			this->data[i][j] = input;
		}
	}
}

void Matrix::resetSize(const int row, const int col)		//resize data
{
	this->data = new float* [rows];
	for (int i = 0; i < rows; i++) {
		this->data[i] = new float[cols];
		for (int j = 0; j < cols; j++) {
			this->data[i][j] = 0;
		}
	}
}

Matrix::~Matrix()						//free
{
	for (int i = 0; i < rows; i++) {
		delete[] data[i];
	}
	delete[] data;

	rows = 0;
	cols = 0;

}

float Matrix::getElement(int row, int col) const		//return element
{
	return data[row][col];
}

float** Matrix::getData() const			//return data
{
	return this->data;
}

void Matrix::setElement(const int row, const int col, float value)		//set element
{
	this->data[row][col] = value;
}

void Matrix::setData(const int rows, const int cols, float** data)		//set data
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->data[i][j] = data[i][j];
		}
	}
}

int Matrix::getRows() const					//return row	
{
	return this->rows;
}

int Matrix::getCols() const					//return col
{
	return this->cols;
}

void Matrix::setRows(const int rows)		//set row
{
	this->rows = rows;
}

void Matrix::setCols(const int cols)		//set col
{
	this->cols = cols;
}

Matrix& ooplinag::add(Matrix& r, Matrix& a, Matrix& b)		//A + B (사이즈에 관한 예외처리는 메인에서)
{
	r.setRows(a.getRows());
	r.setCols(a.getCols());
	r.resetSize(r.getRows(), r.getCols());

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			r.setElement(i, j, a.getElement(i, j) + b.getElement(i, j));	//덧셈
		}
	}

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			std::cout << r.getElement(i, j) << " ";				//출력
		}
		std::cout << std::endl;
	}
	return r;
}

Matrix& ooplinag::sub(Matrix& r, Matrix& a, Matrix& b)			//A-B (사이즈에 관한 예외처리는 main에서)	
{
	r.setRows(a.getRows());
	r.setCols(a.getCols());
	r.resetSize(r.getRows(), r.getCols());

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			r.setElement(i, j, a.getElement(i, j) - b.getElement(i, j));	//뺄셈
		}
	}

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			std::cout << r.getElement(i, j) << " ";				//출력
		}
		std::cout << std::endl;
	}
	return r;
}

bool ooplinag::isMulPossible(Matrix& a, Matrix& b)				//곱셈이 가능한지
{
	return a.getRows() == b.getCols();							//a의 행사이즈와 b의 열사이즈가 동일한가
}

Matrix& ooplinag::mul(Matrix& r, Matrix& a, Matrix& b)			//AB (예외처리는 메인함수에서)
{
	r.setRows(a.getRows());
	r.setCols(b.getCols());
	r.resetSize(r.getRows(), r.getCols());

	for (int i = 0; i < a.getRows(); i++)
	{
		for (int j = 0; j < b.getCols(); j++)
		{
			float sum = 0;
			for (int k = 0; k < a.getCols(); k++)
			{
				sum += a.getElement(i, k) * b.getElement(k, j);	//곱하기
			}
			r.setElement(i, j, sum);
		}
	}

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			std::cout << r.getElement(i, j) << " ";				//출력
		}
		std::cout << std::endl;
	}
	return r;

}

Matrix& ooplinag::elementAdd(Matrix& r, Matrix& a, float v)		//스칼라 덧셈
{
	r.setRows(a.getRows());
	r.setCols(a.getCols());
	r.resetSize(r.getRows(), r.getCols());

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			r.setElement(i, j, a.getElement(i, j) + v);	//더하기
		}
	}

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{		
			std::cout << r.getElement(i, j) << " ";		//출력
		}
		std::cout << std::endl;
	}
	return r;
}

Matrix& ooplinag::elementSub(Matrix& r, Matrix& a, float v)	//스칼라 빼기
{
	r.setRows(a.getRows());
	r.setCols(a.getCols());
	r.resetSize(r.getRows(), r.getCols());

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			r.setElement(i, j, a.getElement(i, j) - v);		//빼기
		}
	}

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			std::cout << r.getElement(i, j) << " ";			//출력
		}
		std::cout << std::endl;
	}
	return r;
}

Matrix& ooplinag::elementMul(Matrix& r, Matrix& a, float v)	//스칼라 곱하기
{
	r.setRows(a.getRows());
	r.setCols(a.getCols());
	r.resetSize(r.getRows(), r.getCols());

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			r.setElement(i, j, a.getElement(i, j) * v);		//곱하기
		}
	}

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			std::cout << r.getElement(i, j) << " ";			//출력
		}
		std::cout << std::endl;
	}
	return r;
}

Matrix& ooplinag::elementDiv(Matrix& r, Matrix& a, float v)	//스칼라 나눗셈
{
	r.setRows(a.getRows());
	r.setCols(a.getCols());
	r.resetSize(r.getRows(), r.getCols());

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			r.setElement(i, j, a.getElement(i, j) / v);		//나누기
		}
	}

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			std::cout << r.getElement(i, j) << " ";			//출력
		}
		std::cout << std::endl;
	}
	return r;
}

Matrix& ooplinag::transpose(Matrix& r, Matrix& m)			//전치 행렬 구하기
{
	r.setRows(m.getCols());
	r.setCols(m.getRows());
	r.resetSize(r.getRows(), r.getCols());

	for (int i = 0; i < m.getRows(); i++)
	{
		for (int j = 0; j < m.getCols(); j++)
		{
			r.setElement(j, i, m.getElement(i, j));			//단순히 행과 열의 컬럼 반전
		}
	}

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			std::cout << r.getElement(i,j) << " ";			//출력
		}
		std::cout << std::endl;
	}
	return r;
}

double ooplinag::determinant(Matrix& m)				//get Det
{
	int n = m.getRows();

	if (n == 1)
		return m.getElement(0, 0);

	if(n == 2)
		return m.getElement(0, 0)* m.getElement(1, 1) - m.getElement(0, 1) * m.getElement(1, 0);

	double det = 0;
	for (int i = 0; i < n; i++)
	{
		Matrix subMatrix;
		subMatrix.setRows(n - 1);
		subMatrix.setCols(n - 1);
		subMatrix.resetSize(subMatrix.getRows(), subMatrix.getCols());		//make sub Matrix
		for(int j = 1; j < n; j++)
		{ 
			for (int k = 0; k < n; k++)
			{
				if (k == i)continue;
				int col = (k < i) ? k : k - 1;
				subMatrix.setElement(j - 1, col, m.getElement(j, k));
			}
		}
		det += pow(-1, i + 2) * m.getElement(0, i) * determinant(subMatrix);		//재귀함수
	}

	return det;
}

Matrix& ooplinag::adjoint(Matrix& r, Matrix& m)
{
	int n = m.getRows();
	r.setRows(n);
	r.setCols(n);
	r.resetSize(n, n);

	if (n == 1)
	{	
		r.setElement(0, 0, 1);				//1이면 본인 자체가 여인수 행렬
		return r;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Matrix temp;
			temp.setRows(n - 1);
			temp.setCols(n - 1);
			temp.resetSize(temp.getRows(), temp.getCols());

			for (int k = 0; k < n; k++) {
				if (k == i) continue;
				for (int l = 0; l < n; l++) {
					if (l == j) continue;
					int row = (k < i) ? k : k - 1;
					int col = (l < j) ? l : l - 1;
					temp.setElement(row, col, m.getElement(k, l));				//소행렬 구하기
				}
			}
			r.setElement(i, j, pow(-1, i + j + 2) * determinant(temp));			//det값을 곱하여 인자 설정
		}
	}

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			std::cout << r.getElement(j,i) << " ";								//출력
		}
		std::cout << std::endl;
	}

	return r;
}

Matrix& ooplinag::adjointWithOutPrint(Matrix& r, Matrix& m)						//adjoint와 동일하지만 print가 없다 (inverse함수에서 사용하기 위함)
{
	int n = m.getRows();
	r.setRows(n);
	r.setCols(n);
	r.resetSize(n, n);

	if (n == 1)
	{
		r.setElement(0, 0, 1);
		return r;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Matrix temp;
			temp.setRows(n - 1);
			temp.setCols(n - 1);
			temp.resetSize(temp.getRows(), temp.getCols());

			for (int k = 0; k < n; k++) {
				if (k == i) continue;
				for (int l = 0; l < n; l++) {
					if (l == j) continue;
					int row = (k < i) ? k : k - 1;
					int col = (l < j) ? l : l - 1;
					temp.setElement(row, col, m.getElement(k, l));
				}
			}
			r.setElement(i, j, pow(-1, i + j + 2) * determinant(temp));
		}
	}

	return r;
}

Matrix& ooplinag::inverse(Matrix& r, Matrix& m)				//역행렬 구하기
{
	int n = m.getRows();
	Matrix adj;
	adj.setRows(n);
	adj.setCols(n);
	adj.resetSize(adj.getRows(), adj.getRows());

	adjointWithOutPrint(adj, m);
	r.setRows(n);
	r.setCols(n);
	r.resetSize(n, n);

	double det = determinant(m);							//Det (det가 0인 경우는 main에서 예외처리)
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			r.setElement(i, j, adj.getElement(i, j) / det);	//det값과 여인수행렬 값으로 계산
		}
	}

	for (int i = 0; i < r.getRows(); i++)
	{
		for (int j = 0; j < r.getCols(); j++)
		{
			std::cout << r.getElement(j, i) << " ";				//출력
		}
		std::cout << std::endl;
	}

	return r;
}