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
	/* 행렬에 수 대입*/
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
/* data를 객체에 그대로 복사하는 메소드.*/
void Matrix::setData(const int rows, const int cols, float** data) {
	/* 객체에 원래 존재하는 data가 있다면 삭제*/
	memory_free2D(this->data);
	
	/* rows, cols 초기화*/
	this->rows = rows;
	this->cols = cols;
	/* 2차원 배열 동적할당*/
	this->data = memory_alloc2D(rows, cols);
	/* 행렬에 수 대입*/
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			(this->data)[i][j] = data[i][j];
	}
}

/* rows와 cols의 크기에 맞게 data table을 생성하는 메소드*/
void Matrix::setTable(const int rows, const int cols) {
	/* 객체에 원래 존재하는 data가 있다면 삭제*/
	memory_free2D(data);
	/* rows, cols 초기화*/
	this->rows = rows;
	this->cols = cols;
	/* 2차원 배열 동적할당*/
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
/* 행렬 출력*/
void Matrix::print() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << data[i][j] << "\t";
		cout << endl;
	}
}

/* Matrix 내부의 2차원 배열로 determinant 구하기*/
float Matrix::determinant() {
	/* 행렬식은 정사각행렬에서만 정의됨*/
	if (cols == rows)
		return deter(data, cols);
	else{
		cout << "It's not a square Matrix" << endl;
		return 0;
	}
}

/* 이차원 배열의 determinant 구하기*/
float ooplinalg::deter(float** data, int size) {
	if (size == 1) {
		return data[0][0];
	}

	float** subMat;
	/* 2차원 서브배열 동적할당*/
	subMat = memory_alloc2D(size, size);

	float det = 0;
	int sign = 1;

	for (int k = 0; k < size; k++) { //k는 data의 0번쨰 행의 col number
		int subi = 0; //subi는 subMat의 row
		for (int i = 1; i < size; i++) { // i는 subMat에 저장할 data값 row 인덱스
			int subj = 0; // subj는 subMat의 col
			for (int j = 0; j < size; j++) { // j는 subMat에 저장할 data값 col 인덱스
				if (k == j) // data의 col을 제외한 값만 subMat에 저장한다.
					continue;
				subMat[subi][subj] = data[i][j];
				subj++;
			}	
			subi++;
		}
		det += sign * data[0][k] * deter(subMat, size - 1); // data값 * 부분행렬의 행렬식
		sign = -sign; // 부호 변환
	}
	memory_free2D(subMat);

	return det;
}

Matrix& ooplinalg::add(Matrix& r, Matrix& a, Matrix& b) {
	/* a와 b의 크기가 달라 덧셈 연산을 진행할 수 없을 때*/
	if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
		cout << "size of Matrixes are different." << endl;
		r.setTable(1, 1);
		**(r.getData()) = NULL;
	}
	else {
		float** dataA = a.getData();
		float** dataB = b.getData();
		/* a의 크기만큼 r을 세팅*/
		r.setTable(a.getRows(), a.getCols());
		/* a + b의 요소들을 r의 요소에 복사*/
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				r.setElement(i, j, dataA[i][j] + dataB[i][j]);
			}
		}
	}
	return r;
}
Matrix& ooplinalg::sub(Matrix& r, Matrix& a, Matrix& b) {
	/* a와 b의 크기가 달라 뺄셈 연산을 진행할 수 없을 때*/
	if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
		cout << "size of Matrixes are different." << endl;
		r.setTable(1, 1);
		**(r.getData()) = NULL;
	}
	else {
		float** dataA = a.getData();
		float** dataB = b.getData();
		/* a의 크기만큼 r을 세팅*/
		r.setTable(a.getRows(), a.getCols());
		/* a - b의 요소들을 r의 요소에 복사*/
		for (int i = 0; i < r.getRows(); i++) {
			for (int j = 0; j < r.getCols(); j++) {
				r.setElement(i, j, dataA[i][j] - dataB[i][j]);
			}
		}
	}
	return r;
}
Matrix& ooplinalg::mul(Matrix& r, Matrix& a, Matrix& b) {
	/* a의 열 개수와 b의 행 개수가 달라 곱셈 연산을 진행할 수 없을 때*/
	if (a.getCols() != b.getRows()) {
		cout << "The size of Matrixes should be (n x m), (m x l)" << endl;
		r.setTable(1, 1);
		**(r.getData()) = NULL;
	}
	else {
		float** dataA = a.getData();
		float** dataB = b.getData();
		/* a의 크기만큼 r을 세팅*/
		r.setTable(a.getRows(), b.getCols());
		/* r의 모든 요소를 방문하며*/
		for (int i = 0; i < r.getRows(); i++) {
			for (int j = 0; j < r.getCols(); j++) {
				/* a, b의 곱셈연산을 r에 저장*/
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
	/* a의 크기만큼 r을 세팅*/
	r.setTable(a.getRows(), a.getCols());
	/* 행렬의 모든 요소에 v를 더한 수로 초기화*/
	float** dataA = a.getData();
	for (int i = 0; i < a.getRows(); i++) {
		for (int j = 0; j < a.getCols(); j++)
			r.setElement(i, j,dataA[i][j] + v);
	}
	return r;
}
Matrix& ooplinalg::elementSub(Matrix& r, Matrix& a, float v) {
	/* a의 크기만큼 r을 세팅*/
	r.setTable(a.getRows(), a.getCols());
	/* 행렬의 모든 요소에 v를 뺀 수로 초기화*/
	float** dataA = a.getData();
	for (int i = 0; i < a.getRows(); i++) {
		for (int j = 0; j < a.getCols(); j++)
			r.setElement(i, j, dataA[i][j] - v);
	}
	return r;
}
Matrix& ooplinalg::elementMul(Matrix& r, Matrix& a, float v) {
	/* a의 크기만큼 r을 세팅*/
	r.setTable(a.getRows(), a.getCols());
	/* 행렬의 모든 요소에 v를 곱한 수로 초기화*/
	float** dataA = a.getData();
	for (int i = 0; i < a.getRows(); i++) {
		for (int j = 0; j < a.getCols(); j++)
			r.setElement(i, j, dataA[i][j] * v);
	}
	return r;
}
Matrix& ooplinalg::elementDiv(Matrix& r, Matrix& a, float v) {
	/* a의 크기만큼 r을 세팅*/
	r.setTable(a.getRows(), a.getCols());
	/* 행렬의 모든 요소에 v를 나눈 수로 초기화*/
	float** dataA = a.getData();
	for (int i = 0; i < a.getRows(); i++) {
		for (int j = 0; j < a.getCols(); j++)
			r.setElement(i, j, dataA[i][j] / v);
	}
	return r;
}

Matrix& ooplinalg::transpose(Matrix& r, Matrix& m) {
	/* m의 크기만큼 r을 세팅*/
	r.setTable(m.getCols(), m.getRows());
	/* m의 행과 열을 뒤집은 요소를 r에 복사*/
	float** dataM = m.getData();
	for (int i = 0; i < m.getCols(); i++) {
		for (int j = 0; j < m.getRows(); j++)
			r.setElement(i, j, dataM[j][i]);
	}
	return r;
}

Matrix& ooplinalg::adjoint(Matrix& r, Matrix& m) {
	/* m이 정사각행렬이 아니면 adjoint를 구할 수 없다*/
	if (m.getCols() != m.getRows()) {
		cout << "It's not a square Matrix." << endl;
		r.setTable(1, 1);
		**(r.getData()) = NULL;
	}
	else {
		int size = m.getCols();
		Matrix tmp(size, size); // 여인수 행렬을 저장할 matrix

		float** dataM = m.getData();
		float** dataT = tmp.getData();

		float** subMat = memory_alloc2D(size - 1, size - 1);

		for (int mi = 0; mi < size; mi++) { // mi는 m의 row
			int sign;
			if (mi % 2 == 0)	sign = 1;
			else sign = -1;
			
			for (int mj = 0; mj < size; mj++) { // mj은 m의 col
				int subi = 0; // subMat의 row
				for (int i = 0; i < size; i++) { // m의 row (subMat에 저장할 데이터의 row)
					if (i == mi)
						continue;
					int subj = 0; // subMat의 col
					for (int j = 0; j < size; j++) { // m의 col (subMat에 저장할 데이터의 col)
						if (j == mj)
							continue;
						subMat[subi][subj] = dataM[i][j];
						subj++;
					}
					subi++;
				}
				dataT[mi][mj] = sign * deter(subMat, size - 1); // 여인수 행렬의 각 요소 저장
				sign = -sign; // 부호 변환
			}
		}
		memory_free2D(subMat);

		transpose(r, tmp); // 여인수 행렬을 전치하여 구한 수반행렬을 r에 저장
	}
	return r;
}

Matrix& ooplinalg::inverse(Matrix& r, Matrix& m) {
	if(m.getRows()!=m.getCols()){ // 역행렬은 정사각행렬에서만 정의됨

		cout << "It's not a square Matrix." << endl;
		r.setTable(1, 1);
		**(r.getData()) = NULL;
	}
	else {
		Matrix tmp; // 임시 저장 Matrix
		adjoint(tmp, m); // m의 수반행렬을 tmp에 저장
		elementDiv(r, tmp, m.determinant()); // 수반행렬을 행렬식으로 나눠 구한 역행렬을 r에 저장
	}
	return r;
}

/* 2차원 배열 동적할당*/
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

/* 2차원 배열 메모리 해제*/
int ooplinalg::memory_free2D(float** ppMemAllocated)
{
	if (ppMemAllocated == 0)
		return -1;

	if (ppMemAllocated[0])
		delete[] ppMemAllocated[0];

	delete[] ppMemAllocated;
	return 0;
}