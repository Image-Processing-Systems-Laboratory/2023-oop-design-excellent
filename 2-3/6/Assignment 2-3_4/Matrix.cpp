#include "Matrix.h"
#include <iostream>

using namespace oopstd;
using namespace std;

// Matrix 클래스의 생성자
Matrix::Matrix()
    : data(nullptr), rows(0), cols(0)		// 각 멤버 변수를 초기화
{}

// 복사 생성자
Matrix::Matrix(const Matrix& mat)
    : data(new float* [mat.rows]), rows(mat.rows), cols(mat.cols)		// 각 멤버 변수를 동적 할당
{
	// 행렬의 각 원소를 복사
    for (int i = 0; i < rows; i++)
	{
        data[i] = new float[cols];
        for (int j = 0; j < cols; j++)
		{
            data[i][j] = mat.data[i][j];
        }
    }
}

// 행렬의 크기를 지정하는 생성자
Matrix::Matrix(int rows, int cols)
    : data(new float* [rows]), rows(rows), cols(cols)		// 각 멤버 변수를 동적 할당
{
    for (int i = 0; i < rows; i++)
	{
        data[i] = new float[cols]();
    }
}

// 소멸자
Matrix::~Matrix()
{
	// 동적 할당한 메모리를 해제
    for (int i = 0; i < rows; i++)
	{
        delete[] data[i];
    }
    delete[] data;
}

// 행렬의 원소를 반환하는 함수
float Matrix::getElement(int row, int col) const
{
	// 행렬의 인덱스가 범위를 벗어날 경우
    if (row >= rows || col >= cols || row < 0 || col < 0)
	{
        cout << "Matrix index out of range" << endl;
    }
    return data[row][col];		// 행렬의 원소를 반환
}

// 행렬의 데이터를 반환하는 함수
float** Matrix::getData() const
{
    return data;		// 행렬의 데이터를 반환
}

// 행렬의 원소를 설정하는 함수
void Matrix::setElement(const int row, const int col, float value)
{
	// 행렬의 인덱스가 범위를 벗어날 경우
    if (row >= rows || col >= cols || row < 0 || col < 0)
	{
		cout << "Matrix index out of range" << endl;
    }
    data[row][col] = value;		// 행렬의 원소를 지정
}

// 행렬의 데이터를 설정하는 함수
void Matrix::setData(const int rows, const int cols, float** data)
{
    this->rows = rows;		// 행렬의 행 크기를 설정
    this->cols = cols;		// 행렬의 열 크기를 설정
    this->data = data;		// 행렬의 데이터를 설정
}

// 행렬의 행의 개수를 반환하는 함수
int Matrix::getRows() const
{
    return rows;		// 행렬의 행 크기를 반환
}

// 행렬의 열의 개수를 반환하는 함수
int Matrix::getCols() const
{
    return cols;		// 행렬의 열 크기를 반환
}

// 행렬의 행의 개수를 설정하는 함수
void Matrix::setRows(const int rows)
{
    this->rows = rows;		// 행렬의 행 크기를 설정
}

// 행렬의 열의 개수를 설정하는 함수
void Matrix::setCols(const int cols)
{
    this->cols = cols;		// 행렬의 열 크기를 설정
}

// 행렬의 행렬식을 반환하는 함수
float Matrix::determinant()
{
	// 행렬의 행과 열의 크기가 다를 경우
    if (rows != cols)
	{
        cout << "Matrix must be square" << endl;
    }
    int n = rows;		// 행렬의 행과 열의 크기
    float det = 1;		// 행렬식의 값
    Matrix temp(*this);		// 행렬의 복사본

    for (int i = 0; i < n; i++)
	{
		// 대각선 원소가 0일 경우
        if (temp.getElement(i, i) == 0)
		{
            bool swapped = false;		// 행렬의 행을 교환했는지 여부
            for (int j = i + 1; j < n; j++)
			{
				// 대각선 원소가 0이 아닐 경우
                if (temp.getElement(j, i) != 0)
				{
                    for (int k = 0; k < n; k++)
					{
                        swap(temp.data[i][k], temp.data[j][k]);		// 행렬의 행을 교환
                    }
                    det *= -1;		// 행렬식의 부호를 바꿈
                    swapped = true;		// 행렬의 행을 교환했음을 표시
                    break;
                }
            }
			// 행렬의 행을 교환하지 않았을 경우
            if (!swapped)
			{
                return 0;
            }
        }

        for (int j = i + 1; j < n; j++)
		{
            float ratio = temp.getElement(j, i) / temp.getElement(i, i);		// 비율
            for (int k = 0; k < n; k++)
			{
                temp.data[j][k] -= ratio * temp.getElement(i, k);		// 행렬의 원소를 다시 입력
            }
        }
        det *= temp.getElement(i, i);		// 행렬식의 값을 곱함
    }

    return det;		// 행렬식의 값을 반환
}

// 행렬의 덧셈
Matrix& oopstd::add(Matrix& r, Matrix& a, Matrix& b)
{
	// 행렬의 행과 열의 크기가 다를 경우
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
	{
		cout << "Matrices must have the same size" << endl;
	}
	int rows = a.getRows();		// 행렬의 행 크기
	int cols = a.getCols();		// 행렬의 열 크기
	float** data = new float* [rows];		// 행렬의 데이터
	// 행렬의 데이터를 입력
    for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
        for (int j = 0; j < cols; j++)
		{
			data[i][j] = a.getElement(i, j) + b.getElement(i, j);		// 행렬의 덧셈
		}
	}
	r.setData(rows, cols, data);		// 행렬의 데이터를 설정
	return r;		// 행렬의 덧셈 결과를 반환
}

// 행렬의 뺄셈
Matrix& oopstd::sub(Matrix& r, Matrix& a, Matrix& b)
{
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
	{
		cout << "Matrices must have the same size" << endl;
	}
	int rows = a.getRows();		// 행렬의 행 크기
	int cols = a.getCols();		// 행렬의 열 크기
	float** data = new float* [rows];		// 행렬의 데이터
	// 행렬의 데이터를 입력
    for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
        for (int j = 0; j < cols; j++)
		{
			data[i][j] = a.getElement(i, j) - b.getElement(i, j);		// 행렬의 뺄셈
		}
	}
	r.setData(rows, cols, data);		// 행렬의 데이터를 설정
	return r;		// 행렬의 뺄셈 결과를 반환
}

// 행렬의 곱셈
Matrix& oopstd::mul(Matrix& r, Matrix& a, Matrix& b)
{
	// 첫 번째 행렬의 열의 크기와 두 번째 행렬의 행의 크기가 다를 경우
    if (a.getCols() != b.getRows())
	{
		cout << "Number of columns in first matrix must be equal to number of rows in second matrix to multiplication" << endl;
	}
	int rows = a.getRows();		// 행렬의 행 크기
	int cols = b.getCols();		// 행렬의 열 크기
	float** data = new float* [rows];		// 행렬의 데이터
	// 행렬의 데이터를 입력
    for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
        for (int j = 0; j < cols; j++)
		{
			data[i][j] = 0;		// 행렬의 원소를 0으로 초기화
            for (int k = 0; k < a.getCols(); k++)
			{
				data[i][j] += a.getElement(i, k) * b.getElement(k, j);		// 행렬의 곱셈
			}
		}
	}
	r.setData(rows, cols, data);		// 행렬의 데이터를 설정
	return r;		// 행렬의 곱셈 결과를 반환
}

// 행렬의 스칼라 덧셈
Matrix& oopstd::elementAdd(Matrix& r, Matrix& a, float value)
{
    int rows = a.getRows();
	int cols = a.getCols();
	float** data = new float* [rows];
    for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
        for (int j = 0; j < cols; j++)
		{
			data[i][j] = a.getElement(i, j) + value;		// 행렬의 원소에 스칼라를 더함
		}
	}
	r.setData(rows, cols, data);		// 행렬의 데이터를 설정
	return r;		// 행렬의 스칼라 덧셈 결과를 반환
}

// 행렬의 스칼라 뺄셈
Matrix& oopstd::elementSub(Matrix& r, Matrix& a, float value)
{
	int rows = a.getRows();
	int cols = a.getCols();
	float** data = new float* [rows];
    for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
        for (int j = 0; j < cols; j++)
		{
			data[i][j] = a.getElement(i, j) - value;		// 행렬의 원소에 스칼라를 뺌
		}
	}
	r.setData(rows, cols, data);		// 행렬의 데이터를 설정
	return r;		// 행렬의 스칼라 뺄셈 결과를 반환
}

// 행렬의 스칼라 곱셈
Matrix& oopstd::elementMul(Matrix& r, Matrix& a, float value)
{
	int rows = a.getRows();
	int cols = a.getCols();
	float** data = new float* [rows];
    for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
        for (int j = 0; j < cols; j++)
		{
			data[i][j] = a.getElement(i, j) * value;		// 행렬의 원소에 스칼라를 곱함
		}
	}
	r.setData(rows, cols, data);		// 행렬의 데이터를 설정
	return r;		// 행렬의 스칼라 곱셈 결과를 반환
}

// 행렬의 스칼라 나눗셈
Matrix& oopstd::elementDiv(Matrix& r, Matrix& a, float value)
{
	int rows = a.getRows();
	int cols = a.getCols();
	float** data = new float* [rows];
    for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
        for (int j = 0; j < cols; j++)
		{
			data[i][j] = a.getElement(i, j) / value;		// 행렬의 원소에 스칼라를 나눔
		}
	}
	r.setData(rows, cols, data);		// 행렬의 데이터를 설정
	return r;		// 행렬의 스칼라 나눗셈 결과를 반환
}

// 행렬의 전치행렬 구하는 함수
Matrix& oopstd::transpose(Matrix& r, Matrix& m)
{
    int rows = m.getCols();
	int cols = m.getRows();
	float** data = new float* [rows];
    for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
        for (int j = 0; j < cols; j++)
		{
			data[i][j] = m.getElement(j, i);		// 행렬의 원소를 전치
		}
	}
	r.setData(rows, cols, data);		// 행렬의 데이터를 설정
	return r;		// 행렬의 전치행렬을 반환
}

// 행렬의 수반행렬을 구하는 함수
Matrix& oopstd::adjoint(Matrix& r, Matrix& m)
{
	// 행렬이 정사각 행렬이 아닐 경우
    if (m.getRows() != m.getCols())
	{
		cout << "Matrix must be square" << endl;
	}
	int rows = m.getRows();		// 행렬의 행의 개수
	int cols = m.getCols();		// 행렬의 열의 개수
	float** data = new float* [rows];		// 행렬의 데이터
	// 행렬의 행의 개수만큼 반복
    for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];		// 행렬의 열의 개수만큼 메모리 할당
        for (int j = 0; j < cols; j++)
		{
			Matrix temp(rows - 1, cols - 1);		// 행렬의 원소를 제외한 행렬
			int x = 0;		// 행렬의 행의 인덱스
			int y = 0;		// 행렬의 열의 인덱스
			// 행렬의 행의 개수만큼 반복
            for (int k = 0; k < rows; k++)
			{
                if (k == i)
				{
					continue;
				}
				// 행렬의 열의 개수만큼 반복
                for (int l = 0; l < cols; l++)
				{
                    if (l == j)
					{
						continue;
					}
					temp.data[x][y] = m.getElement(k, l) * pow(-1, k + l);		// 행렬의 원소를 제외한 행렬의 데이터 설정
					y++;
				}
				x++;
				y = 0;
			}
			data[i][j] = temp.determinant();		// 행렬의 원소를 제외한 행렬의 행렬식을 구함
		}
	}
	r.setData(rows, cols, data);		// 행렬의 데이터를 설정
	transpose(r, r);		// 행렬의 전치행렬을 구함
	return r;		// 행렬의 수반행렬을 반환
}

// 행렬의 행렬식을 구하는 함수
Matrix& oopstd::inverse(Matrix& r, Matrix& m)
{
	// 행렬이 정사각 행렬이 아닐 경우
	if (m.getRows() != m.getCols())
	{
		cout << "Matrix must be square" << endl;
	}
	int rows = m.getRows();		// 행렬의 행의 개수
	int cols = m.getCols();		// 행렬의 열의 개수
	float** data = new float* [rows];		// 행렬의 데이터
	// 행렬의 행의 개수만큼 반복
	for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];		// 행렬의 열의 개수만큼 메모리 할당
	}
	Matrix adj(rows, cols);		// 행렬의 수반행렬
	adjoint(adj, m);		// 행렬의 수반행렬을 구함
	float det = m.determinant();		// 행렬의 행렬식을 구함
	// 행렬식이 0일 경우
	if (det == 0)
	{
		cout << "Matrix is not invertible" << endl;
	}
	// 행렬의 행의 개수만큼 반복
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			data[i][j] = adj.getElement(i, j) / det;		// 수반행렬의 값을 행렬식으로 나눔
		}
	}
	r.setData(rows, cols, data);		// 행렬의 데이터를 설정
	return r;		// 행렬의 역행렬을 반환
}