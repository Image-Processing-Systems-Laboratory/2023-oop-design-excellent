#include "Matrix.h"


//디폴트 생성자
Matrix::Matrix() {
	//변수 초기화
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->data[i][j] = 0;
}

//소멸자
Matrix::~Matrix() {}

//data를 저장해주는 함수
void Matrix::setData(double** data) {
	//data에 저장된 값 저장
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->data[i][j] = data[i][j];
}
//각 요소를 저장해주는 함수
void Matrix::setElement(double data,int row,int col) {
	this->data[row][col] = data;		//row,col에 data 값 저장
}

//행렬을 출력하는 함수
void Matrix::printMatrix() {
	//각 요소 출력
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << this->data[i][j] << " ";		//열을 " "로 구분하여 출력
		std::cout << std::endl;							//행을 개행으로 구분하여 출력
	}
}

//+=Matrix operator
Matrix Matrix::operator+=(const Matrix& mat) {
	//각각의 요소끼리 더하여 저장
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->data[i][j] += mat.data[i][j];		//각 요소에 맞는 위치끼리 더해서 저장


	return *this;
}
//+=val operator
Matrix Matrix::operator+=(const double val) {
	//각각의 요소에 val을 더하여 저장
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->data[i][j] += val;		//모든 요소에 val을 더해서 저장
	
	return *this;
}
//-=Matrix operator
Matrix Matrix::operator-=(const Matrix& mat) {
	//각각의 요소끼리 빼서 저장
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->data[i][j] -= mat.data[i][j];		//각 요소에 맞는 위치끼리 빼서 저장

	return *this;
}
//-=val operator
Matrix Matrix::operator-=(const double val) {
	//각각의 요소에 val을 빼 저장
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->data[i][j] -= val;		//모든 요소에 val을 빼서 저장

	return *this;
}
//*Matrix operator
Matrix Matrix::operator*(const Matrix& mat) {
	Matrix result;
	//행렬의 곱연산 결과를 result에 저장
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			double sum = 0;					//각요소의 곱 결과의 총 합을 저장할 변수
			for (int k = 0; k < 3; k++)
				sum += this->data[i][k] * mat.data[k][j];		//행렬의 곱 연산
			result.setElement(sum, i, j);		//곱연산한 결과 저장
		}
	}
	return result;
}
//*val operator
Matrix Matrix::operator*(const double val) {
	Matrix result;
	//각각의 요소에 val을 곱하여 저장
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result.setElement(this->data[i][j] * val, i, j);		//모든 요소에 val을 곱하여 저장

	return result;
}
