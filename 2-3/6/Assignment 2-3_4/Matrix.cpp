#include "Matrix.h"
#include <iostream>

using namespace oopstd;
using namespace std;

// Matrix Ŭ������ ������
Matrix::Matrix()
    : data(nullptr), rows(0), cols(0)		// �� ��� ������ �ʱ�ȭ
{}

// ���� ������
Matrix::Matrix(const Matrix& mat)
    : data(new float* [mat.rows]), rows(mat.rows), cols(mat.cols)		// �� ��� ������ ���� �Ҵ�
{
	// ����� �� ���Ҹ� ����
    for (int i = 0; i < rows; i++)
	{
        data[i] = new float[cols];
        for (int j = 0; j < cols; j++)
		{
            data[i][j] = mat.data[i][j];
        }
    }
}

// ����� ũ�⸦ �����ϴ� ������
Matrix::Matrix(int rows, int cols)
    : data(new float* [rows]), rows(rows), cols(cols)		// �� ��� ������ ���� �Ҵ�
{
    for (int i = 0; i < rows; i++)
	{
        data[i] = new float[cols]();
    }
}

// �Ҹ���
Matrix::~Matrix()
{
	// ���� �Ҵ��� �޸𸮸� ����
    for (int i = 0; i < rows; i++)
	{
        delete[] data[i];
    }
    delete[] data;
}

// ����� ���Ҹ� ��ȯ�ϴ� �Լ�
float Matrix::getElement(int row, int col) const
{
	// ����� �ε����� ������ ��� ���
    if (row >= rows || col >= cols || row < 0 || col < 0)
	{
        cout << "Matrix index out of range" << endl;
    }
    return data[row][col];		// ����� ���Ҹ� ��ȯ
}

// ����� �����͸� ��ȯ�ϴ� �Լ�
float** Matrix::getData() const
{
    return data;		// ����� �����͸� ��ȯ
}

// ����� ���Ҹ� �����ϴ� �Լ�
void Matrix::setElement(const int row, const int col, float value)
{
	// ����� �ε����� ������ ��� ���
    if (row >= rows || col >= cols || row < 0 || col < 0)
	{
		cout << "Matrix index out of range" << endl;
    }
    data[row][col] = value;		// ����� ���Ҹ� ����
}

// ����� �����͸� �����ϴ� �Լ�
void Matrix::setData(const int rows, const int cols, float** data)
{
    this->rows = rows;		// ����� �� ũ�⸦ ����
    this->cols = cols;		// ����� �� ũ�⸦ ����
    this->data = data;		// ����� �����͸� ����
}

// ����� ���� ������ ��ȯ�ϴ� �Լ�
int Matrix::getRows() const
{
    return rows;		// ����� �� ũ�⸦ ��ȯ
}

// ����� ���� ������ ��ȯ�ϴ� �Լ�
int Matrix::getCols() const
{
    return cols;		// ����� �� ũ�⸦ ��ȯ
}

// ����� ���� ������ �����ϴ� �Լ�
void Matrix::setRows(const int rows)
{
    this->rows = rows;		// ����� �� ũ�⸦ ����
}

// ����� ���� ������ �����ϴ� �Լ�
void Matrix::setCols(const int cols)
{
    this->cols = cols;		// ����� �� ũ�⸦ ����
}

// ����� ��Ľ��� ��ȯ�ϴ� �Լ�
float Matrix::determinant()
{
	// ����� ��� ���� ũ�Ⱑ �ٸ� ���
    if (rows != cols)
	{
        cout << "Matrix must be square" << endl;
    }
    int n = rows;		// ����� ��� ���� ũ��
    float det = 1;		// ��Ľ��� ��
    Matrix temp(*this);		// ����� ���纻

    for (int i = 0; i < n; i++)
	{
		// �밢�� ���Ұ� 0�� ���
        if (temp.getElement(i, i) == 0)
		{
            bool swapped = false;		// ����� ���� ��ȯ�ߴ��� ����
            for (int j = i + 1; j < n; j++)
			{
				// �밢�� ���Ұ� 0�� �ƴ� ���
                if (temp.getElement(j, i) != 0)
				{
                    for (int k = 0; k < n; k++)
					{
                        swap(temp.data[i][k], temp.data[j][k]);		// ����� ���� ��ȯ
                    }
                    det *= -1;		// ��Ľ��� ��ȣ�� �ٲ�
                    swapped = true;		// ����� ���� ��ȯ������ ǥ��
                    break;
                }
            }
			// ����� ���� ��ȯ���� �ʾ��� ���
            if (!swapped)
			{
                return 0;
            }
        }

        for (int j = i + 1; j < n; j++)
		{
            float ratio = temp.getElement(j, i) / temp.getElement(i, i);		// ����
            for (int k = 0; k < n; k++)
			{
                temp.data[j][k] -= ratio * temp.getElement(i, k);		// ����� ���Ҹ� �ٽ� �Է�
            }
        }
        det *= temp.getElement(i, i);		// ��Ľ��� ���� ����
    }

    return det;		// ��Ľ��� ���� ��ȯ
}

// ����� ����
Matrix& oopstd::add(Matrix& r, Matrix& a, Matrix& b)
{
	// ����� ��� ���� ũ�Ⱑ �ٸ� ���
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
	{
		cout << "Matrices must have the same size" << endl;
	}
	int rows = a.getRows();		// ����� �� ũ��
	int cols = a.getCols();		// ����� �� ũ��
	float** data = new float* [rows];		// ����� ������
	// ����� �����͸� �Է�
    for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
        for (int j = 0; j < cols; j++)
		{
			data[i][j] = a.getElement(i, j) + b.getElement(i, j);		// ����� ����
		}
	}
	r.setData(rows, cols, data);		// ����� �����͸� ����
	return r;		// ����� ���� ����� ��ȯ
}

// ����� ����
Matrix& oopstd::sub(Matrix& r, Matrix& a, Matrix& b)
{
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
	{
		cout << "Matrices must have the same size" << endl;
	}
	int rows = a.getRows();		// ����� �� ũ��
	int cols = a.getCols();		// ����� �� ũ��
	float** data = new float* [rows];		// ����� ������
	// ����� �����͸� �Է�
    for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
        for (int j = 0; j < cols; j++)
		{
			data[i][j] = a.getElement(i, j) - b.getElement(i, j);		// ����� ����
		}
	}
	r.setData(rows, cols, data);		// ����� �����͸� ����
	return r;		// ����� ���� ����� ��ȯ
}

// ����� ����
Matrix& oopstd::mul(Matrix& r, Matrix& a, Matrix& b)
{
	// ù ��° ����� ���� ũ��� �� ��° ����� ���� ũ�Ⱑ �ٸ� ���
    if (a.getCols() != b.getRows())
	{
		cout << "Number of columns in first matrix must be equal to number of rows in second matrix to multiplication" << endl;
	}
	int rows = a.getRows();		// ����� �� ũ��
	int cols = b.getCols();		// ����� �� ũ��
	float** data = new float* [rows];		// ����� ������
	// ����� �����͸� �Է�
    for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
        for (int j = 0; j < cols; j++)
		{
			data[i][j] = 0;		// ����� ���Ҹ� 0���� �ʱ�ȭ
            for (int k = 0; k < a.getCols(); k++)
			{
				data[i][j] += a.getElement(i, k) * b.getElement(k, j);		// ����� ����
			}
		}
	}
	r.setData(rows, cols, data);		// ����� �����͸� ����
	return r;		// ����� ���� ����� ��ȯ
}

// ����� ��Į�� ����
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
			data[i][j] = a.getElement(i, j) + value;		// ����� ���ҿ� ��Į�� ����
		}
	}
	r.setData(rows, cols, data);		// ����� �����͸� ����
	return r;		// ����� ��Į�� ���� ����� ��ȯ
}

// ����� ��Į�� ����
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
			data[i][j] = a.getElement(i, j) - value;		// ����� ���ҿ� ��Į�� ��
		}
	}
	r.setData(rows, cols, data);		// ����� �����͸� ����
	return r;		// ����� ��Į�� ���� ����� ��ȯ
}

// ����� ��Į�� ����
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
			data[i][j] = a.getElement(i, j) * value;		// ����� ���ҿ� ��Į�� ����
		}
	}
	r.setData(rows, cols, data);		// ����� �����͸� ����
	return r;		// ����� ��Į�� ���� ����� ��ȯ
}

// ����� ��Į�� ������
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
			data[i][j] = a.getElement(i, j) / value;		// ����� ���ҿ� ��Į�� ����
		}
	}
	r.setData(rows, cols, data);		// ����� �����͸� ����
	return r;		// ����� ��Į�� ������ ����� ��ȯ
}

// ����� ��ġ��� ���ϴ� �Լ�
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
			data[i][j] = m.getElement(j, i);		// ����� ���Ҹ� ��ġ
		}
	}
	r.setData(rows, cols, data);		// ����� �����͸� ����
	return r;		// ����� ��ġ����� ��ȯ
}

// ����� ��������� ���ϴ� �Լ�
Matrix& oopstd::adjoint(Matrix& r, Matrix& m)
{
	// ����� ���簢 ����� �ƴ� ���
    if (m.getRows() != m.getCols())
	{
		cout << "Matrix must be square" << endl;
	}
	int rows = m.getRows();		// ����� ���� ����
	int cols = m.getCols();		// ����� ���� ����
	float** data = new float* [rows];		// ����� ������
	// ����� ���� ������ŭ �ݺ�
    for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];		// ����� ���� ������ŭ �޸� �Ҵ�
        for (int j = 0; j < cols; j++)
		{
			Matrix temp(rows - 1, cols - 1);		// ����� ���Ҹ� ������ ���
			int x = 0;		// ����� ���� �ε���
			int y = 0;		// ����� ���� �ε���
			// ����� ���� ������ŭ �ݺ�
            for (int k = 0; k < rows; k++)
			{
                if (k == i)
				{
					continue;
				}
				// ����� ���� ������ŭ �ݺ�
                for (int l = 0; l < cols; l++)
				{
                    if (l == j)
					{
						continue;
					}
					temp.data[x][y] = m.getElement(k, l) * pow(-1, k + l);		// ����� ���Ҹ� ������ ����� ������ ����
					y++;
				}
				x++;
				y = 0;
			}
			data[i][j] = temp.determinant();		// ����� ���Ҹ� ������ ����� ��Ľ��� ����
		}
	}
	r.setData(rows, cols, data);		// ����� �����͸� ����
	transpose(r, r);		// ����� ��ġ����� ����
	return r;		// ����� ��������� ��ȯ
}

// ����� ��Ľ��� ���ϴ� �Լ�
Matrix& oopstd::inverse(Matrix& r, Matrix& m)
{
	// ����� ���簢 ����� �ƴ� ���
	if (m.getRows() != m.getCols())
	{
		cout << "Matrix must be square" << endl;
	}
	int rows = m.getRows();		// ����� ���� ����
	int cols = m.getCols();		// ����� ���� ����
	float** data = new float* [rows];		// ����� ������
	// ����� ���� ������ŭ �ݺ�
	for (int i = 0; i < rows; i++)
	{
		data[i] = new float[cols];		// ����� ���� ������ŭ �޸� �Ҵ�
	}
	Matrix adj(rows, cols);		// ����� �������
	adjoint(adj, m);		// ����� ��������� ����
	float det = m.determinant();		// ����� ��Ľ��� ����
	// ��Ľ��� 0�� ���
	if (det == 0)
	{
		cout << "Matrix is not invertible" << endl;
	}
	// ����� ���� ������ŭ �ݺ�
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			data[i][j] = adj.getElement(i, j) / det;		// ��������� ���� ��Ľ����� ����
		}
	}
	r.setData(rows, cols, data);		// ����� �����͸� ����
	return r;		// ����� ������� ��ȯ
}