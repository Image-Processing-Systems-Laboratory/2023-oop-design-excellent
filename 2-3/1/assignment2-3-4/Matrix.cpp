#include "Matrix.h"

using namespace ooplinalg;

Matrix::Matrix() {
	data = nullptr;
	rows = 0;
	cols = 0;
}
Matrix::Matrix(const Matrix& mat) {
	rows = mat.rows;
	cols = mat.cols;
	
	data = memory_alloc2D(rows, cols);
	/* ��Ŀ� �� ����*/
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			data[i][j] = mat.data[i][j];
	}
}
Matrix::Matrix(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	
	data = memory_alloc2D(rows, cols);
}
Matrix::~Matrix() {
	memory_free2D(data);
}

float Matrix::getElement(int row, int col) const {
	if (row < rows && col < cols)
		return data[row][col];
	else {
		cout << "Wrong approach. Try again." << endl;
		return 0;
	}
}
float** Matrix::getData() const {
	return data;
}
void Matrix::setElement(const int row, const int col, float value) {
	if (row < rows && col < cols)
		data[row][col] = value;
}
/* data�� ��ü�� �״�� �����ϴ� �޼ҵ�.*/
void Matrix::setData(const int rows, const int cols, float** data) {
	/* ��ü�� ���� �����ϴ� data�� �ִٸ� ����*/
	memory_free2D(this->data);
	
	/* rows, cols �ʱ�ȭ*/
	this->rows = rows;
	this->cols = cols;
	/* 2���� �迭 �����Ҵ�*/
	this->data = memory_alloc2D(rows, cols);
	/* ��Ŀ� �� ����*/
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			(this->data)[i][j] = data[i][j];
	}
}

/* rows�� cols�� ũ�⿡ �°� data table�� �����ϴ� �޼ҵ�*/
void Matrix::setTable(const int rows, const int cols) {
	/* ��ü�� ���� �����ϴ� data�� �ִٸ� ����*/
	memory_free2D(data);
	/* rows, cols �ʱ�ȭ*/
	this->rows = rows;
	this->cols = cols;
	/* 2���� �迭 �����Ҵ�*/
	this->data = memory_alloc2D(rows, cols);
}
int Matrix::getRows() const {
	return rows;
}
int Matrix::getCols() const {
	return cols;
}
void Matrix::setRows(const int rows) {
	this->rows = rows;
}
void Matrix::setCols(const int cols) {
	this->cols = cols;
}
/* ��� ���*/
void Matrix::print() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << data[i][j] << "\t";
		cout << endl;
	}
}

/* Matrix ������ 2���� �迭�� determinant ���ϱ�*/
float Matrix::determinant() {
	/* ��Ľ��� ���簢��Ŀ����� ���ǵ�*/
	if (cols == rows)
		return deter(data, cols);
	else{
		cout << "It's not a square Matrix" << endl;
		return 0;
	}
}

/* ������ �迭�� determinant ���ϱ�*/
float ooplinalg::deter(float** data, int size) {
	if (size == 1) {
		return data[0][0];
	}

	float** subMat;
	/* 2���� ����迭 �����Ҵ�*/
	subMat = memory_alloc2D(size, size);

	float det = 0;
	int sign = 1;

	for (int k = 0; k < size; k++) { //k�� data�� 0���� ���� col number
		int subi = 0; //subi�� subMat�� row
		for (int i = 1; i < size; i++) { // i�� subMat�� ������ data�� row �ε���
			int subj = 0; // subj�� subMat�� col
			for (int j = 0; j < size; j++) { // j�� subMat�� ������ data�� col �ε���
				if (k == j) // data�� col�� ������ ���� subMat�� �����Ѵ�.
					continue;
				subMat[subi][subj] = data[i][j];
				subj++;
			}	
			subi++;
		}
		det += sign * data[0][k] * deter(subMat, size - 1); // data�� * �κ������ ��Ľ�
		sign = -sign; // ��ȣ ��ȯ
	}
	memory_free2D(subMat);

	return det;
}

Matrix& ooplinalg::add(Matrix& r, Matrix& a, Matrix& b) {
	/* a�� b�� ũ�Ⱑ �޶� ���� ������ ������ �� ���� ��*/
	if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
		cout << "size of Matrixes are different." << endl;
		r.setTable(1, 1);
		**(r.getData()) = NULL;
	}
	else {
		float** dataA = a.getData();
		float** dataB = b.getData();
		/* a�� ũ�⸸ŭ r�� ����*/
		r.setTable(a.getRows(), a.getCols());
		/* a + b�� ��ҵ��� r�� ��ҿ� ����*/
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				r.setElement(i, j, dataA[i][j] + dataB[i][j]);
			}
		}
	}
	return r;
}
Matrix& ooplinalg::sub(Matrix& r, Matrix& a, Matrix& b) {
	/* a�� b�� ũ�Ⱑ �޶� ���� ������ ������ �� ���� ��*/
	if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
		cout << "size of Matrixes are different." << endl;
		r.setTable(1, 1);
		**(r.getData()) = NULL;
	}
	else {
		float** dataA = a.getData();
		float** dataB = b.getData();
		/* a�� ũ�⸸ŭ r�� ����*/
		r.setTable(a.getRows(), a.getCols());
		/* a - b�� ��ҵ��� r�� ��ҿ� ����*/
		for (int i = 0; i < r.getRows(); i++) {
			for (int j = 0; j < r.getCols(); j++) {
				r.setElement(i, j, dataA[i][j] - dataB[i][j]);
			}
		}
	}
	return r;
}
Matrix& ooplinalg::mul(Matrix& r, Matrix& a, Matrix& b) {
	/* a�� �� ������ b�� �� ������ �޶� ���� ������ ������ �� ���� ��*/
	if (a.getCols() != b.getRows()) {
		cout << "The size of Matrixes should be (n x m), (m x l)" << endl;
		r.setTable(1, 1);
		**(r.getData()) = NULL;
	}
	else {
		float** dataA = a.getData();
		float** dataB = b.getData();
		/* a�� ũ�⸸ŭ r�� ����*/
		r.setTable(a.getRows(), b.getCols());
		/* r�� ��� ��Ҹ� �湮�ϸ�*/
		for (int i = 0; i < r.getRows(); i++) {
			for (int j = 0; j < r.getCols(); j++) {
				/* a, b�� ���������� r�� ����*/
				float res = 0;
				for (int k = 0; k < a.getCols(); k++) {
					res += a.getElement(i, k) * b.getElement(k, j);
				}
				r.setElement(i, j, res);
			}
		}
	}
	return r;
}

Matrix& ooplinalg::elementAdd(Matrix& r, Matrix& a, float v) {
	/* a�� ũ�⸸ŭ r�� ����*/
	r.setTable(a.getRows(), a.getCols());
	/* ����� ��� ��ҿ� v�� ���� ���� �ʱ�ȭ*/
	float** dataA = a.getData();
	for (int i = 0; i < a.getRows(); i++) {
		for (int j = 0; j < a.getCols(); j++)
			r.setElement(i, j,dataA[i][j] + v);
	}
	return r;
}
Matrix& ooplinalg::elementSub(Matrix& r, Matrix& a, float v) {
	/* a�� ũ�⸸ŭ r�� ����*/
	r.setTable(a.getRows(), a.getCols());
	/* ����� ��� ��ҿ� v�� �� ���� �ʱ�ȭ*/
	float** dataA = a.getData();
	for (int i = 0; i < a.getRows(); i++) {
		for (int j = 0; j < a.getCols(); j++)
			r.setElement(i, j, dataA[i][j] - v);
	}
	return r;
}
Matrix& ooplinalg::elementMul(Matrix& r, Matrix& a, float v) {
	/* a�� ũ�⸸ŭ r�� ����*/
	r.setTable(a.getRows(), a.getCols());
	/* ����� ��� ��ҿ� v�� ���� ���� �ʱ�ȭ*/
	float** dataA = a.getData();
	for (int i = 0; i < a.getRows(); i++) {
		for (int j = 0; j < a.getCols(); j++)
			r.setElement(i, j, dataA[i][j] * v);
	}
	return r;
}
Matrix& ooplinalg::elementDiv(Matrix& r, Matrix& a, float v) {
	/* a�� ũ�⸸ŭ r�� ����*/
	r.setTable(a.getRows(), a.getCols());
	/* ����� ��� ��ҿ� v�� ���� ���� �ʱ�ȭ*/
	float** dataA = a.getData();
	for (int i = 0; i < a.getRows(); i++) {
		for (int j = 0; j < a.getCols(); j++)
			r.setElement(i, j, dataA[i][j] / v);
	}
	return r;
}

Matrix& ooplinalg::transpose(Matrix& r, Matrix& m) {
	/* m�� ũ�⸸ŭ r�� ����*/
	r.setTable(m.getCols(), m.getRows());
	/* m�� ��� ���� ������ ��Ҹ� r�� ����*/
	float** dataM = m.getData();
	for (int i = 0; i < m.getCols(); i++) {
		for (int j = 0; j < m.getRows(); j++)
			r.setElement(i, j, dataM[j][i]);
	}
	return r;
}

Matrix& ooplinalg::adjoint(Matrix& r, Matrix& m) {
	/* m�� ���簢����� �ƴϸ� adjoint�� ���� �� ����*/
	if (m.getCols() != m.getRows()) {
		cout << "It's not a square Matrix." << endl;
		r.setTable(1, 1);
		**(r.getData()) = NULL;
	}
	else {
		int size = m.getCols();
		Matrix tmp(size, size); // ���μ� ����� ������ matrix

		float** dataM = m.getData();
		float** dataT = tmp.getData();

		float** subMat = memory_alloc2D(size - 1, size - 1);

		for (int mi = 0; mi < size; mi++) { // mi�� m�� row
			int sign;
			if (mi % 2 == 0)	sign = 1;
			else sign = -1;
			
			for (int mj = 0; mj < size; mj++) { // mj�� m�� col
				int subi = 0; // subMat�� row
				for (int i = 0; i < size; i++) { // m�� row (subMat�� ������ �������� row)
					if (i == mi)
						continue;
					int subj = 0; // subMat�� col
					for (int j = 0; j < size; j++) { // m�� col (subMat�� ������ �������� col)
						if (j == mj)
							continue;
						subMat[subi][subj] = dataM[i][j];
						subj++;
					}
					subi++;
				}
				dataT[mi][mj] = sign * deter(subMat, size - 1); // ���μ� ����� �� ��� ����
				sign = -sign; // ��ȣ ��ȯ
			}
		}
		memory_free2D(subMat);

		transpose(r, tmp); // ���μ� ����� ��ġ�Ͽ� ���� ��������� r�� ����
	}
	return r;
}

Matrix& ooplinalg::inverse(Matrix& r, Matrix& m) {
	if(m.getRows()!=m.getCols()){ // ������� ���簢��Ŀ����� ���ǵ�

		cout << "It's not a square Matrix." << endl;
		r.setTable(1, 1);
		**(r.getData()) = NULL;
	}
	else {
		Matrix tmp; // �ӽ� ���� Matrix
		adjoint(tmp, m); // m�� ��������� tmp�� ����
		elementDiv(r, tmp, m.determinant()); // ��������� ��Ľ����� ���� ���� ������� r�� ����
	}
	return r;
}

/* 2���� �迭 �����Ҵ�*/
float** ooplinalg::memory_alloc2D(int rows, int cols)
{
	float** ppMem2d = new float * [rows];
	if (ppMem2d == 0)
		return 0;
	ppMem2d[0] = new float[rows * cols];
	if (ppMem2d[0] == 0)
	{
		delete[] ppMem2d;
		return 0;
	}

	for (int i = 1; i < rows; i++)
		ppMem2d[i] = ppMem2d[i - 1] + cols;
	return ppMem2d;
}

/* 2���� �迭 �޸� ����*/
int ooplinalg::memory_free2D(float** ppMemAllocated)
{
	if (ppMemAllocated == 0)
		return -1;

	if (ppMemAllocated[0])
		delete[] ppMemAllocated[0];

	delete[] ppMemAllocated;
	return 0;
}