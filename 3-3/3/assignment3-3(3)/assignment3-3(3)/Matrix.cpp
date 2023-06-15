#include"Matrix.h"

Matrix::Matrix()
{
	// ������. Raster scan���� 2���� �迭 �ʱ�ȭ
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
	// ��� ��� ���
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
	// ���� ������
	// �� ��Ҹ� ���� ��� ��ȯ
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
	// ���� ������
	// �� ��Ҹ� �� ��� ��ȯ
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
	// ���� ������
	// �� ��Ҹ� ��Ģ�� ���� ���� ��� ��ȯ
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
