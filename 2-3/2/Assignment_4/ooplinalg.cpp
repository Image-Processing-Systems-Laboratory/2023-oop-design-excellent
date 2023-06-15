#include<iostream>
#include "ooplinalg.h"

namespace ooplinalg {
	Matrix::Matrix() {//자동생성자
		data = NULL;
		rows = 0;
		cols = 0;
	}

	Matrix::Matrix(const Matrix& mat) {//복사 생성자
		this->rows = mat.rows;
		this->cols = mat.cols;
		data = new float* [rows];
		for (int i = 0; i < rows; i++)
			data[i] = new float[cols];
		setData(rows, cols, mat.data);
	}

	Matrix::Matrix(int rows, int cols) {//행렬 생성자
		this->rows = rows;
		this->cols = cols;
		data = new float* [rows];
		for (int i = 0; i < rows; i++)
			data[i] = new float[cols];
	}

	Matrix::~Matrix() {//소멸자
		if (data != NULL) {
			for (int i = 0; i < rows; i++)//동적 할당 해제
				delete data[i];
			delete data;
		}
	}

	float Matrix::getElement(int row, int col) const {//해당 인덱스 값 반환
		return data[row][col];
	}

	float** Matrix::getData() const {//행렬 반환
		return data;
	}

	void Matrix::setElement(const int row, const int col, float value) {//해당 인덱스 값 설정
		data[row][col] = value;
	}

	void Matrix::setData(const int rows, const int cols, float** data) {//행렬 설정 (data 복사)
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				this->data[i][j] = data[i][j];
			}
		}
	}

	void Matrix::setRows(const int rows) {//행 크기
		this->rows = rows;
	}

	int Matrix::getRows() const {//행 반환
		return rows;
	}

	void Matrix::setCols(const int cols) {//열 크기
		this->cols = cols;
	}

	int Matrix::getCols() const {//열 반환
		return cols;
	}

	float Matrix::determinant() {//det 값 반환
		float det = 0;//return value
		int row = rows - 1;//소행렬식 크기
		int col = cols - 1;
		int a = 0;//여인수 부호
		
		if (rows == 1)//1*1 행렬
			return data[0][0];

		if (rows == 2) {//2*2 행렬
			float value = data[0][0] * data[1][1] - data[1][0] * data[0][1];
			return value;
		}		
		else {
			Matrix subMat(row, col);//소행렬식 선언
			int j = 0;
			int k = 0;
			for (int i=0; i < cols; i++) {
				int sub_row = 0;
				for (j = 1; j < rows; j++) {
					int sub_col = 0;
					for (k = 0; k < cols; k++) {
						if (i == k)//특정 열 제외
							continue;
						subMat.data[sub_row][sub_col] = data[j][k];//소행렬 값 저장
						sub_col++;
					}
					sub_row++;
				}

				if (i % 2 == 0)//여인수 계산
					a = 1;
				else
					a = -1;
				det += a * data[0][i] * subMat.determinant();//det에 저장 (subMat가 3이상 정사각 행렬이라면 재귀호출)
			}
		}
		return det;//det 반환
	}

	//Matrix Operation
	Matrix& add(Matrix& r, Matrix& a, Matrix& b) {//행렬 합
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				r.setElement(i, j, a.getElement(i, j) + b.getElement(i, j));
			}
		}
		return r;
	}

	Matrix& sub(Matrix& r, Matrix& a, Matrix& b) {//행렬 차
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				r.setElement(i, j, a.getElement(i, j) - b.getElement(i, j));
			}
		}
		return r;
	}
	
	Matrix& mul(Matrix& r, Matrix& a, Matrix& b) {//행렬 곱
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				float v = 0.0;
				for (int k = 0; k < a.getRows(); k++) {
					v += a.getElement(i, k) * b.getElement(k, j);//a 행과 b열 곱셈
				}
				r.setElement(i, j, v);
			}
		}
		return r;
	}


	Matrix& elementAdd(Matrix& r, Matrix& a, float v) {//상수 덧셈
		int row = a.getRows();
		int col = a.getCols();

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				r.setElement(i, j, a.getElement(i, j) + v);
		}
		return r;
	}

	Matrix& elementSub(Matrix& r, Matrix& a, float v) {//상수 뺄셈
		int row = a.getRows();
		int col = a.getCols();

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				r.setElement(i, j, a.getElement(i, j) - v);
		}
		return r;
	}

	Matrix& elementMul(Matrix& r, Matrix& a, float v) {//상수 곱셈
		int row = a.getRows();
		int col = a.getCols();

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				r.setElement(i, j, a.getElement(i, j) * v);
		}
		return r;
	}

	Matrix& elementDiv(Matrix& r, Matrix& a, float v) {//상수 나눗셈
		int row = a.getRows();
		int col = a.getCols();

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				r.setElement(i, j, a.getElement(i, j) / v); 
		}
		return r;
	}


	Matrix& transpose(Matrix& r, Matrix& m) {//전치 행렬
		for (int i = 0; i < m.getRows(); i++) {
			for (int j = 0; j < m.getCols(); j++)
				r.setElement(i, j, m.getElement(j, i));//인덱스 교체 저장
		}
		return r;
	}

	Matrix& adjoint(Matrix& r, Matrix& m) {//수반 행렬
		int row = m.getRows() - 1;
		int col = m.getCols() - 1;
		int a = 0;
		Matrix subMat(row, col);//소행렬
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
						subMat.setElement(sub_row, sub_col, m.getElement(j, k));//소행렬 저장
						sub_col++;
					}
					if (i != j)
						sub_row++;
				}
				if ((i + z) % 2 == 0)//여인수 계산
					a = 1;
				else
					a = -1;
				float value = a * subMat.determinant();//소행렬 det 계산 후 value에 저장
				tran.setElement(i, z, value);//tran에 저장
			}
		}
		transpose(r,tran);//전치 시키기
		return r;
	}

	Matrix& inverse(Matrix& r, Matrix& m) {//역행렬
		float det = m.determinant();//det 값
		Matrix subMat(m.getRows(), m.getCols());
		adjoint(subMat, m);//수반행렬 값

		if (det == 0) {//det=0일 경우, 역행렬 존재 X
			std::cout << "inverse matrix not exist";
			return m;//기존 행렬 반환
		}
		else {
			for (int i = 0; i < subMat.getRows(); i++) {
				for (int j = 0; j < subMat.getCols(); j++) {
					r.setElement(i, j, subMat.getElement(i, j) / det);//각 인덱스 값 det로 나눠주기
				}
			}
		}
		return r;
	}
}