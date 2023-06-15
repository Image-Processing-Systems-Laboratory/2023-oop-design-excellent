#include "class.h"


namespace ooplinalg {

	Matrix::Matrix() :rows(0), cols(0), data{ NULL } {}

	Matrix::Matrix(const Matrix& mat){  //복사생성자
		rows = mat.rows;
		cols = mat.cols;
		/*2차원 행렬 동적할당*/
		data = new float* [rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new float[cols];
		}
		/*행렬 원소 값 깊은 복사*/
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				data[i][j] = mat.data[i][j];
			}
		}
	}

	Matrix::Matrix(int rows, int cols) :rows(rows), cols(cols) {
		data = new float* [rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new float[cols];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				data[i][j] = 0;
			}
		}
	}

	Matrix::~Matrix(){ //소멸자
		/*2차원 행렬 동적할당 해제*/
		for (int i = 0; i < rows; i++) {
			delete[] data[i];
		}
		delete[] data;
	}


	float Matrix::getElement(int row, int col) const{ //요소 값 반환
		return data[row][col];
	}

	float** Matrix::getData() const{ //배열 포인터 값 반환
		return data;
	}

	void Matrix::setElement(const int row, const int col, float value){ //요소 값 저장
		data[row][col] = value;
	}

	void Matrix::setData(const int rows, const int cols, float** data){ //배열 값 저장
		/*먼저 원래 가지고 있던 행렬의 동적할당을 해제시키고 진행*/
		for (int i = 0; i < this->rows; i++) {
			delete[] this->data[i];
		}
		delete[] this->data;

		/*새로 다시 변수 값들 저장*/
		this->rows = rows;
		this->cols = cols;

		/*새로운 행렬 동적 할당 후 값 저장*/
		this->data = new float* [rows];
		for(int i = 0; i < rows; i++) {
			this->data[i] = new float[cols];
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				this->data[i][j] = data[i][j];
			}
		}
	}

	int Matrix::getRows() const{ //행 값 반환
		return rows;
	}

	int Matrix::getCols() const{ //열 값 반환
		return cols;
	}

	void Matrix::setRows(const int rows){ //행 값 저장
		this->rows = rows;
	}

	void Matrix::setCols(const int cols){ //열 값 저장
		this->cols = cols;
	}

	float Matrix::determinant(){ //행렬식 계산 후 값 반환
		/*정사각 행렬이 아닌 경우 계산 불가*/
		if (rows != cols) {
			cout << "행렬식을 계산할 수 없습니다." << endl;
			return 0;
		}
								 
		/*1x1 행렬인 경우*/
		if (rows == 1) {
			return data[0][0];
		}

		/*2x2 행렬인 경우*/
		else if (rows == 2) {
			float det_2 = (data[0][0] * data[1][1]) - (data[0][1] * data[1][0]);
			return det_2;
		}

		/*3x3 행렬인 경우*/
		else if (rows == 3) {
			float det_3_1 = (data[0][0] * data[1][1] * data[2][2]) + (data[0][1] * data[1][2] * data[2][0]) + (data[0][2] * data[1][0] * data[2][1]);
			float det_3_2 = (data[0][2] * data[1][1] * data[2][0]) + (data[0][0] * data[1][2] * data[2][1]) + (data[0][1] * data[1][0] * data[2][2]);
			return (det_3_1 - det_3_2);
		}

		/*그 외 행렬일 경우(미완성)*/
		else {
			return 0;
		}
	}


	/*두 행렬 간 덧셈, 뺄셈, 곱셈 계산 (결과 r값 반환)*/
	Matrix& add(Matrix& r, Matrix& a, Matrix& b){
		int arow = a.getRows(), acol = a.getCols(); //a의 행, 열 값 불러옴
		int brow = b.getRows(), bcol = b.getCols(); //b의 행, 열 값 불러옴
		Matrix res(arow, acol); //덧셈 결과 저장할 행렬

		if (arow != brow || acol != bcol) { //예외 처리
			cout << "크기가 다른 두 행렬의 덧셈 연산을 진행할 수 없습니다." << endl;
			exit(1);
		}
		
		/*a, b 행렬의 요소들을 불러와서 더한 다음 res 행렬에 저장*/
		for (int i = 0; i < arow; i++) {
			for (int j = 0; j < acol; j++) {
				res.setElement(i, j, a.getElement(i, j) + b.getElement(i, j));
			}
		}

		/*반환할 행렬에 res 행렬 정보들을 불러와서 저장*/
		r.setData(arow, acol, res.getData());
		return r;
	}

	Matrix& sub(Matrix& r, Matrix& a, Matrix& b){
		int arow = a.getRows(), acol = a.getCols(); //a의 행, 열 값 불러옴
		int brow = b.getRows(), bcol = b.getCols(); //b의 행, 열 값 불러옴
		Matrix res(arow, acol); //뺄셈 결과 저장할 행렬

		if (arow != brow || acol != bcol) { //예외 처리
			cout << "크기가 다른 두 행렬의 뺄셈 연산을 진행할 수 없습니다." << endl;
			exit(1);
		}

		/*a, b 행렬의 요소들을 불러와서 뺀 다음 res 행렬에 저장*/
		for (int i = 0; i < arow; i++) {
			for (int j = 0; j < acol; j++) {
				res.setElement(i, j, a.getElement(i, j) - b.getElement(i, j));
			}
		}

		/*반환할 행렬에 res 행렬 정보들을 불러와서 저장*/
		r.setData(arow, acol, res.getData());
		return r;
	}

	Matrix& mul(Matrix& r, Matrix& a, Matrix& b){
		int arow = a.getRows(), acol = a.getCols(); //a의 행, 열 값 불러옴
		int brow = b.getRows(), bcol = b.getCols(); //b의 행, 열 값 불러옴
		Matrix res(arow, acol); //뺄셈 결과 저장할 행렬

		if (acol != brow) { //예외 처리
			cout << "a의 열과 b의 행 크기가 다른 두 행렬 간의 곱셈 연산은 진행할 수 없습니다." << endl;

		}

		/*a의 열과 b의 행끼리 각각 곱해서 더한 다음 res에 저장*/
		float m = 0;
		for (int i = 0; i < arow; i++) {
			for (int j = 0; j < bcol; j++) {
				m = 0;
				for (int k = 0; k < acol; k++) {
					m = m + a.getElement(i, k) * b.getElement(k, j);
				}
				res.setElement(i, j, m); //결과 값은 a의 행 크기 x b의 열 크기로 나옴
			}
		}
		r.setData(arow, bcol, res.getData());
		return r;
	}


	/*한 행렬에서의 스칼라 덧셈, 뺄셈, 곱셈, 나눗셈 계산*/

	Matrix& elementAdd(Matrix& r, Matrix& a, float v){
		int row = a.getRows(), col = a.getCols(); //a의 행, 열 값 불러옴
		Matrix res(row, col);

		/*a 행렬의 각 요소마다 v를 더해서 res에 저장*/
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				res.setElement(i, j, a.getElement(i, j) + v);
			}
		}
		r.setData(row, col, res.getData());
		return r;
	}

	Matrix& elementSub(Matrix& r, Matrix& a, float v){
		int row = a.getRows(), col = a.getCols(); //a의 행, 열 값 불러옴
		Matrix res(row, col);

		/*a 행렬의 각 요소마다 v를 빼서 res에 저장*/
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				res.setElement(i, j, a.getElement(i, j) - v);
			}
		}
		r.setData(row, col, res.getData());
		return r;
	}

	Matrix& elementMul(Matrix& r, Matrix& a, float v){
		int row = a.getRows(), col = a.getCols(); //a의 행, 열 값 불러옴
		Matrix res(row, col);

		/*a 행렬 각 요소마다 v를 곱해서 res에 저장*/
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				res.setElement(i, j, a.getElement(i, j) * v);
			}
		}
		r.setData(row, col, res.getData());
		return r;
	}

	Matrix& elementDiv(Matrix& r, Matrix& a, float v){
		int row = a.getRows(), col = a.getCols(); //a의 행, 열 값 불러옴
		Matrix res(row, col);

		/*a 행렬 각 요소마다 v를 나눠서 res에 저장*/
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				res.setElement(i, j, a.getElement(i, j) / v);
			}
		}
		r.setData(row, col, res.getData());
		return r;
	}


	/*한 행렬에서의 전치행렬, 수반행렬, 역행렬 계산*/

	Matrix& transpose(Matrix& r, Matrix& m){ //전치행렬
		int row = m.getRows(), col = m.getCols(); //m의 행, 열 값 불러옴
		Matrix res(col, row);

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				res.setElement(i, j, m.getElement(j, i)); //행, 열 반대로 저장
			}
		}
		r.setData(col, row, res.getData());
		return r;
	}

	Matrix& adjoint(Matrix& r, Matrix& m){ //수반행렬
		int row = m.getRows(), col = m.getCols(); //m의 행, 열 값 불러옴
		Matrix res(col, row);
		Matrix arr(row-1, col-1); //소행렬
		int ai, aj; //소행렬의 행, 열 값

		/*여인수행렬 구하기*/
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				ai = 0, aj = 0;
				for (int ii = 0; ii < row; ii++) {
					for (int jj = 0; jj < col; jj++) {
						if (i != ii && j != jj) { //소행렬의 대상인 원소의 행, 열 값 제외 모두
							arr.setElement(ai, aj, m.getElement(ii, jj));
							aj++;
							if (aj == col - 1) { //하나의 소행렬이 완성된 경우
								aj = 0; //소행렬의 열 다시 0으로 초기화
								ai++; //소행렬의 행 증가
							}
						}
					}
				}
				if ((i + j) % 2 != 0) { //홀수일 경우
					res.setElement(i, j, -1 * arr.determinant());
				}
				else { //짝수일 경우
					res.setElement(i, j, arr.determinant());
				}
			}
		}

		/*여인수 행렬을 전치시켜 수반행렬 구하기*/
		transpose(r, res);
		return r;
	}

	Matrix& inverse(Matrix& r, Matrix& m){ //역행렬
		int row = m.getRows(), col = m.getCols(); //m의 행, 열 값 불러옴

		if (m.determinant() == 0) { //예외 처리
			cout << "행렬식이 0인 행렬은 역행렬을 구할 수 없습니다." << endl;
			exit(1);
		}

		/*수반행렬 구하기*/
		Matrix adj(row, col);
		adjoint(adj, m);

		/*행렬식으로 나눠서 역행렬 구하기*/
		Matrix inv(row, col);
		elementDiv(inv, adj, m.determinant());

		r.setData(row, col, inv.getData());
		return r;
	}
}