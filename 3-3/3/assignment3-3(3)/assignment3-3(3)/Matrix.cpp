#include"Matrix.h"

Matrix::Matrix()
{
	// 생성자. Raster scan으로 2차원 배열 초기화
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_elem[i][j] = 0;
		}
	}
}

Matrix::~Matrix() {}

void Matrix::print()
{
	// 모든 요소 출력
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << m_elem[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::setelem(int x, int y, double elem)
{
	m_elem[x][y] = elem;
}

double Matrix::getelem(int x, int y)
{
	return m_elem[x][y];
}

Matrix Matrix::operator+=(Matrix& mat)
{
	// 덧셈 연산자
	// 각 요소를 더한 행렬 반환
	Matrix result;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.setelem(i, j, m_elem[i][j] + mat.getelem(i, j));
		}
	}

	return result;
}

Matrix Matrix::operator-=(Matrix& mat)
{
	// 뺄셈 연산자
	// 각 요소를 뺀 요소 반환
	Matrix result;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.setelem(i, j, m_elem[i][j] - mat.getelem(i, j));
		}
	}

	return result;
}

Matrix Matrix::operator*(Matrix& mat)
{
	// 곱셈 연산자
	// 각 요소를 규칙에 따라 곱한 행렬 반환
	Matrix result;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			double sum = 0.0;
			for (int k = 0; k < 3; k++)
			{
				sum += m_elem[i][k] * mat.getelem(k, j);
			}
			result.setelem(i, j, sum);
		}
	}

	return result;
}
