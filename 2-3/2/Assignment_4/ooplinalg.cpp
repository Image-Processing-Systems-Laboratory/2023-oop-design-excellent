#include<iostream>
#include "ooplinalg.h"

namespace ooplinalg {
	Matrix::Matrix() {//�ڵ�������
		data = NULL;
		rows = 0;
		cols = 0;
	}

	Matrix::Matrix(const Matrix& mat) {//���� ������
		this->rows = mat.rows;
		this->cols = mat.cols;
		data = new float* [rows];
		for (int i = 0; i < rows; i++)
			data[i] = new float[cols];
		setData(rows, cols, mat.data);
	}

	Matrix::Matrix(int rows, int cols) {//��� ������
		this->rows = rows;
		this->cols = cols;
		data = new float* [rows];
		for (int i = 0; i < rows; i++)
			data[i] = new float[cols];
	}

	Matrix::~Matrix() {//�Ҹ���
		if (data != NULL) {
			for (int i = 0; i < rows; i++)//���� �Ҵ� ����
				delete data[i];
			delete data;
		}
	}

	float Matrix::getElement(int row, int col) const {//�ش� �ε��� �� ��ȯ
		return data[row][col];
	}

	float** Matrix::getData() const {//��� ��ȯ
		return data;
	}

	void Matrix::setElement(const int row, const int col, float value) {//�ش� �ε��� �� ����
		data[row][col] = value;
	}

	void Matrix::setData(const int rows, const int cols, float** data) {//��� ���� (data ����)
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				this->data[i][j] = data[i][j];
			}
		}
	}

	void Matrix::setRows(const int rows) {//�� ũ��
		this->rows = rows;
	}

	int Matrix::getRows() const {//�� ��ȯ
		return rows;
	}

	void Matrix::setCols(const int cols) {//�� ũ��
		this->cols = cols;
	}

	int Matrix::getCols() const {//�� ��ȯ
		return cols;
	}

	float Matrix::determinant() {//det �� ��ȯ
		float det = 0;//return value
		int row = rows - 1;//����Ľ� ũ��
		int col = cols - 1;
		int a = 0;//���μ� ��ȣ
		
		if (rows == 1)//1*1 ���
			return data[0][0];

		if (rows == 2) {//2*2 ���
			float value = data[0][0] * data[1][1] - data[1][0] * data[0][1];
			return value;
		}		
		else {
			Matrix subMat(row, col);//����Ľ� ����
			int j = 0;
			int k = 0;
			for (int i=0; i < cols; i++) {
				int sub_row = 0;
				for (j = 1; j < rows; j++) {
					int sub_col = 0;
					for (k = 0; k < cols; k++) {
						if (i == k)//Ư�� �� ����
							continue;
						subMat.data[sub_row][sub_col] = data[j][k];//����� �� ����
						sub_col++;
					}
					sub_row++;
				}

				if (i % 2 == 0)//���μ� ���
					a = 1;
				else
					a = -1;
				det += a * data[0][i] * subMat.determinant();//det�� ���� (subMat�� 3�̻� ���簢 ����̶�� ���ȣ��)
			}
		}
		return det;//det ��ȯ
	}

	//Matrix Operation
	Matrix& add(Matrix& r, Matrix& a, Matrix& b) {//��� ��
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				r.setElement(i, j, a.getElement(i, j) + b.getElement(i, j));
			}
		}
		return r;
	}

	Matrix& sub(Matrix& r, Matrix& a, Matrix& b) {//��� ��
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				r.setElement(i, j, a.getElement(i, j) - b.getElement(i, j));
			}
		}
		return r;
	}
	
	Matrix& mul(Matrix& r, Matrix& a, Matrix& b) {//��� ��
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				float v = 0.0;
				for (int k = 0; k < a.getRows(); k++) {
					v += a.getElement(i, k) * b.getElement(k, j);//a ��� b�� ����
				}
				r.setElement(i, j, v);
			}
		}
		return r;
	}


	Matrix& elementAdd(Matrix& r, Matrix& a, float v) {//��� ����
		int row = a.getRows();
		int col = a.getCols();

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				r.setElement(i, j, a.getElement(i, j) + v);
		}
		return r;
	}

	Matrix& elementSub(Matrix& r, Matrix& a, float v) {//��� ����
		int row = a.getRows();
		int col = a.getCols();

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				r.setElement(i, j, a.getElement(i, j) - v);
		}
		return r;
	}

	Matrix& elementMul(Matrix& r, Matrix& a, float v) {//��� ����
		int row = a.getRows();
		int col = a.getCols();

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				r.setElement(i, j, a.getElement(i, j) * v);
		}
		return r;
	}

	Matrix& elementDiv(Matrix& r, Matrix& a, float v) {//��� ������
		int row = a.getRows();
		int col = a.getCols();

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				r.setElement(i, j, a.getElement(i, j) / v); 
		}
		return r;
	}


	Matrix& transpose(Matrix& r, Matrix& m) {//��ġ ���
		for (int i = 0; i < m.getRows(); i++) {
			for (int j = 0; j < m.getCols(); j++)
				r.setElement(i, j, m.getElement(j, i));//�ε��� ��ü ����
		}
		return r;
	}

	Matrix& adjoint(Matrix& r, Matrix& m) {//���� ���
		int row = m.getRows() - 1;
		int col = m.getCols() - 1;
		int a = 0;
		Matrix subMat(row, col);//�����
		Matrix tran(m.getRows(), m.getCols());

		int j = 0;
		int k = 0;
		for (int i = 0; i < m.getRows(); i++) {
			for (int z = 0; z < m.getCols(); z++) {

				int sub_row = 0;
				for (j = 0; j < m.getRows(); j++) {
					int sub_col = 0;
					for (k = 0; k < m.getCols(); k++) {
						if (i == j || z == k)
							continue;
						subMat.setElement(sub_row, sub_col, m.getElement(j, k));//����� ����
						sub_col++;
					}
					if (i != j)
						sub_row++;
				}
				if ((i + z) % 2 == 0)//���μ� ���
					a = 1;
				else
					a = -1;
				float value = a * subMat.determinant();//����� det ��� �� value�� ����
				tran.setElement(i, z, value);//tran�� ����
			}
		}
		transpose(r,tran);//��ġ ��Ű��
		return r;
	}

	Matrix& inverse(Matrix& r, Matrix& m) {//�����
		float det = m.determinant();//det ��
		Matrix subMat(m.getRows(), m.getCols());
		adjoint(subMat, m);//������� ��

		if (det == 0) {//det=0�� ���, ����� ���� X
			std::cout << "inverse matrix not exist";
			return m;//���� ��� ��ȯ
		}
		else {
			for (int i = 0; i < subMat.getRows(); i++) {
				for (int j = 0; j < subMat.getCols(); j++) {
					r.setElement(i, j, subMat.getElement(i, j) / det);//�� �ε��� �� det�� �����ֱ�
				}
			}
		}
		return r;
	}
}