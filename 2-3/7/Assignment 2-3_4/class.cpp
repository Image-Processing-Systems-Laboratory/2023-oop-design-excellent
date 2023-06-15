#include "class.h"


namespace ooplinalg {

	Matrix::Matrix() :rows(0), cols(0), data{ NULL } {}

	Matrix::Matrix(const Matrix& mat){  //���������
		rows = mat.rows;
		cols = mat.cols;
		/*2���� ��� �����Ҵ�*/
		data = new float* [rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new float[cols];
		}
		/*��� ���� �� ���� ����*/
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

	Matrix::~Matrix(){ //�Ҹ���
		/*2���� ��� �����Ҵ� ����*/
		for (int i = 0; i < rows; i++) {
			delete[] data[i];
		}
		delete[] data;
	}


	float Matrix::getElement(int row, int col) const{ //��� �� ��ȯ
		return data[row][col];
	}

	float** Matrix::getData() const{ //�迭 ������ �� ��ȯ
		return data;
	}

	void Matrix::setElement(const int row, const int col, float value){ //��� �� ����
		data[row][col] = value;
	}

	void Matrix::setData(const int rows, const int cols, float** data){ //�迭 �� ����
		/*���� ���� ������ �ִ� ����� �����Ҵ��� ������Ű�� ����*/
		for (int i = 0; i < this->rows; i++) {
			delete[] this->data[i];
		}
		delete[] this->data;

		/*���� �ٽ� ���� ���� ����*/
		this->rows = rows;
		this->cols = cols;

		/*���ο� ��� ���� �Ҵ� �� �� ����*/
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

	int Matrix::getRows() const{ //�� �� ��ȯ
		return rows;
	}

	int Matrix::getCols() const{ //�� �� ��ȯ
		return cols;
	}

	void Matrix::setRows(const int rows){ //�� �� ����
		this->rows = rows;
	}

	void Matrix::setCols(const int cols){ //�� �� ����
		this->cols = cols;
	}

	float Matrix::determinant(){ //��Ľ� ��� �� �� ��ȯ
		/*���簢 ����� �ƴ� ��� ��� �Ұ�*/
		if (rows != cols) {
			cout << "��Ľ��� ����� �� �����ϴ�." << endl;
			return 0;
		}
								 
		/*1x1 ����� ���*/
		if (rows == 1) {
			return data[0][0];
		}

		/*2x2 ����� ���*/
		else if (rows == 2) {
			float det_2 = (data[0][0] * data[1][1]) - (data[0][1] * data[1][0]);
			return det_2;
		}

		/*3x3 ����� ���*/
		else if (rows == 3) {
			float det_3_1 = (data[0][0] * data[1][1] * data[2][2]) + (data[0][1] * data[1][2] * data[2][0]) + (data[0][2] * data[1][0] * data[2][1]);
			float det_3_2 = (data[0][2] * data[1][1] * data[2][0]) + (data[0][0] * data[1][2] * data[2][1]) + (data[0][1] * data[1][0] * data[2][2]);
			return (det_3_1 - det_3_2);
		}

		/*�� �� ����� ���(�̿ϼ�)*/
		else {
			return 0;
		}
	}


	/*�� ��� �� ����, ����, ���� ��� (��� r�� ��ȯ)*/
	Matrix& add(Matrix& r, Matrix& a, Matrix& b){
		int arow = a.getRows(), acol = a.getCols(); //a�� ��, �� �� �ҷ���
		int brow = b.getRows(), bcol = b.getCols(); //b�� ��, �� �� �ҷ���
		Matrix res(arow, acol); //���� ��� ������ ���

		if (arow != brow || acol != bcol) { //���� ó��
			cout << "ũ�Ⱑ �ٸ� �� ����� ���� ������ ������ �� �����ϴ�." << endl;
			exit(1);
		}
		
		/*a, b ����� ��ҵ��� �ҷ��ͼ� ���� ���� res ��Ŀ� ����*/
		for (int i = 0; i < arow; i++) {
			for (int j = 0; j < acol; j++) {
				res.setElement(i, j, a.getElement(i, j) + b.getElement(i, j));
			}
		}

		/*��ȯ�� ��Ŀ� res ��� �������� �ҷ��ͼ� ����*/
		r.setData(arow, acol, res.getData());
		return r;
	}

	Matrix& sub(Matrix& r, Matrix& a, Matrix& b){
		int arow = a.getRows(), acol = a.getCols(); //a�� ��, �� �� �ҷ���
		int brow = b.getRows(), bcol = b.getCols(); //b�� ��, �� �� �ҷ���
		Matrix res(arow, acol); //���� ��� ������ ���

		if (arow != brow || acol != bcol) { //���� ó��
			cout << "ũ�Ⱑ �ٸ� �� ����� ���� ������ ������ �� �����ϴ�." << endl;
			exit(1);
		}

		/*a, b ����� ��ҵ��� �ҷ��ͼ� �� ���� res ��Ŀ� ����*/
		for (int i = 0; i < arow; i++) {
			for (int j = 0; j < acol; j++) {
				res.setElement(i, j, a.getElement(i, j) - b.getElement(i, j));
			}
		}

		/*��ȯ�� ��Ŀ� res ��� �������� �ҷ��ͼ� ����*/
		r.setData(arow, acol, res.getData());
		return r;
	}

	Matrix& mul(Matrix& r, Matrix& a, Matrix& b){
		int arow = a.getRows(), acol = a.getCols(); //a�� ��, �� �� �ҷ���
		int brow = b.getRows(), bcol = b.getCols(); //b�� ��, �� �� �ҷ���
		Matrix res(arow, acol); //���� ��� ������ ���

		if (acol != brow) { //���� ó��
			cout << "a�� ���� b�� �� ũ�Ⱑ �ٸ� �� ��� ���� ���� ������ ������ �� �����ϴ�." << endl;

		}

		/*a�� ���� b�� �ೢ�� ���� ���ؼ� ���� ���� res�� ����*/
		float m = 0;
		for (int i = 0; i < arow; i++) {
			for (int j = 0; j < bcol; j++) {
				m = 0;
				for (int k = 0; k < acol; k++) {
					m = m + a.getElement(i, k) * b.getElement(k, j);
				}
				res.setElement(i, j, m); //��� ���� a�� �� ũ�� x b�� �� ũ��� ����
			}
		}
		r.setData(arow, bcol, res.getData());
		return r;
	}


	/*�� ��Ŀ����� ��Į�� ����, ����, ����, ������ ���*/

	Matrix& elementAdd(Matrix& r, Matrix& a, float v){
		int row = a.getRows(), col = a.getCols(); //a�� ��, �� �� �ҷ���
		Matrix res(row, col);

		/*a ����� �� ��Ҹ��� v�� ���ؼ� res�� ����*/
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				res.setElement(i, j, a.getElement(i, j) + v);
			}
		}
		r.setData(row, col, res.getData());
		return r;
	}

	Matrix& elementSub(Matrix& r, Matrix& a, float v){
		int row = a.getRows(), col = a.getCols(); //a�� ��, �� �� �ҷ���
		Matrix res(row, col);

		/*a ����� �� ��Ҹ��� v�� ���� res�� ����*/
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				res.setElement(i, j, a.getElement(i, j) - v);
			}
		}
		r.setData(row, col, res.getData());
		return r;
	}

	Matrix& elementMul(Matrix& r, Matrix& a, float v){
		int row = a.getRows(), col = a.getCols(); //a�� ��, �� �� �ҷ���
		Matrix res(row, col);

		/*a ��� �� ��Ҹ��� v�� ���ؼ� res�� ����*/
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				res.setElement(i, j, a.getElement(i, j) * v);
			}
		}
		r.setData(row, col, res.getData());
		return r;
	}

	Matrix& elementDiv(Matrix& r, Matrix& a, float v){
		int row = a.getRows(), col = a.getCols(); //a�� ��, �� �� �ҷ���
		Matrix res(row, col);

		/*a ��� �� ��Ҹ��� v�� ������ res�� ����*/
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				res.setElement(i, j, a.getElement(i, j) / v);
			}
		}
		r.setData(row, col, res.getData());
		return r;
	}


	/*�� ��Ŀ����� ��ġ���, �������, ����� ���*/

	Matrix& transpose(Matrix& r, Matrix& m){ //��ġ���
		int row = m.getRows(), col = m.getCols(); //m�� ��, �� �� �ҷ���
		Matrix res(col, row);

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				res.setElement(i, j, m.getElement(j, i)); //��, �� �ݴ�� ����
			}
		}
		r.setData(col, row, res.getData());
		return r;
	}

	Matrix& adjoint(Matrix& r, Matrix& m){ //�������
		int row = m.getRows(), col = m.getCols(); //m�� ��, �� �� �ҷ���
		Matrix res(col, row);
		Matrix arr(row-1, col-1); //�����
		int ai, aj; //������� ��, �� ��

		/*���μ���� ���ϱ�*/
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				ai = 0, aj = 0;
				for (int ii = 0; ii < row; ii++) {
					for (int jj = 0; jj < col; jj++) {
						if (i != ii && j != jj) { //������� ����� ������ ��, �� �� ���� ���
							arr.setElement(ai, aj, m.getElement(ii, jj));
							aj++;
							if (aj == col - 1) { //�ϳ��� ������� �ϼ��� ���
								aj = 0; //������� �� �ٽ� 0���� �ʱ�ȭ
								ai++; //������� �� ����
							}
						}
					}
				}
				if ((i + j) % 2 != 0) { //Ȧ���� ���
					res.setElement(i, j, -1 * arr.determinant());
				}
				else { //¦���� ���
					res.setElement(i, j, arr.determinant());
				}
			}
		}

		/*���μ� ����� ��ġ���� ������� ���ϱ�*/
		transpose(r, res);
		return r;
	}

	Matrix& inverse(Matrix& r, Matrix& m){ //�����
		int row = m.getRows(), col = m.getCols(); //m�� ��, �� �� �ҷ���

		if (m.determinant() == 0) { //���� ó��
			cout << "��Ľ��� 0�� ����� ������� ���� �� �����ϴ�." << endl;
			exit(1);
		}

		/*������� ���ϱ�*/
		Matrix adj(row, col);
		adjoint(adj, m);

		/*��Ľ����� ������ ����� ���ϱ�*/
		Matrix inv(row, col);
		elementDiv(inv, adj, m.determinant());

		r.setData(row, col, inv.getData());
		return r;
	}
}