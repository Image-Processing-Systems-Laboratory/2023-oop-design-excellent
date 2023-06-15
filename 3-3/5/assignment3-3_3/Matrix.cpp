#include "Matrix.h"
#include <iostream>
#include <cstdlib>

//member function of Matrix class
Matrix::Matrix()										       //default 생성자
{
	//모든 element를 0으로 초기화
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] = 0;
		}
	}
}

Matrix::Matrix(double number)                                 //모든 element를 인자로 전달 받은 number 값으로 초기화하는 생성자
{
	//모든 element를 number로 초기화
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] = number;
		}
	}
}

Matrix::Matrix(const Matrix& other)                           //복사 생성자
{
	//모든 element 복사하여 저장
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] = other.data[i][j];
		}
	}
}

//element를 9개 입력 받아 각각 저장하는 생성자
Matrix::Matrix(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33)
{
	//각 위치에 맞도록 값 저장
	data[0][0] = a11;
	data[0][1] = a12;
	data[0][2] = a13;
	data[1][0] = a21;
	data[1][1] = a22;
	data[1][2] = a23;
	data[2][0] = a31;
	data[2][1] = a32;
	data[2][2] = a33;
}

Matrix::Matrix(double(*data)[3])                             //3x3 크기의 2차원 배열을 인자로 전달 받아 복사하여 저장하는 생성자
{
	//모든 element 복사하여 저장
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->data[i][j] = data[i][j];
		}
	}
}

Matrix::~Matrix()										       //메모리를 할당 해제하는 파괴자
{
	//모든 element 복사하여 저장
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] = 0;
		}
	}
}

bool Matrix::SetElement(double element, int row, int col)	   //element에 값 저장
{
	//유효한 범위인지 검사 후 값 저장
	if (row >= 0 && row < 3 && col >= 0 && col < 3) {
		data[row][col] = element;   //row 행, col 열에 element 값 저장
		return true;                //값을 저장하면 true 반환
	}
	else {
		return false;               //유효하지 않은 범위이면 false 반환
	}
}

double Matrix::GetElement(int row, int col)				       //element 값 반환
{
	//유효한 범위인지 검사 후 값 반환
	if (row >= 0 && row < 3 && col >= 0 && col < 3) {
		return data[row][col];      //row 행, col 열의 element 값 반환
	}
	else {
		return -1;                   //유효하지 않은 범위이면 -1 반환
	}
}

void Matrix::print()										   //Matrix 출력
{
	//3x3 행렬 출력
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << data[i][j] << ' ';     //각각의 element 사이는 공백으로 구분
		}
		std::cout << std::endl;                 //각각의 행 사이는 개행으로 구분
	}
}

const Matrix Matrix::operator +=(const Matrix& other)          //다른 Matrix와 += 연산
{
	//같은 위치의 element끼리 += 연산
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] += other.data[i][j];   //자신 객체와 다른 객체에 대해 += 연산
		}
	}

	return *this;        //객체 자신을 반환
}

const Matrix Matrix::operator +=(double num)                  //스칼라 값과 += 연산
{
	//모든 element마다 스칼라 값 num을 더한다.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] += num;                                //+= 연산
		}
	}

	return *this;        //객체 자신을 반환
}

const Matrix Matrix::operator -=(const Matrix& other)                  //다른 Matrix와 -= 연산
{
	//같은 위치의 element끼리 -= 연산
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] -= other.data[i][j];   //자신 객체와 다른 객체에 대해 -= 연산
		}
	}

	return *this;        //객체 자신을 반환
}

const Matrix Matrix::operator -=(double num)                  //스칼라 값과 -= 연산
{
	//모든 element마다 스칼라 값 num을 뺀다.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] -= num;                                //-= 연산
		}
	}

	return *this;        //객체 자신을 반환
}

const Matrix Matrix::operator *(const Matrix& other) const             //다른 Matrix와 * 연산
{
	Matrix m;           //값을 저장할 임시 객체
	double sum;         //inner product 연산 값

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			sum = 0;

			for (int h = 0; h < 3; h++) {
				sum += (data[i][h] * other.data[h][j]);     //i행과 j열을 inner product
			}

			m.SetElement(sum, i, j);        //inner product 연산 값을 i행 j열에 저장
		}
	}

	return m;            //임시 객체 반환
}

const Matrix Matrix::operator *(double num) const             //스칼라 값과 * 연산
{
	Matrix m;           //값을 저장할 임시 객체

	//모든 element마다 스칼라 값 num을 곱하여 m에 저장한다.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m.SetElement(data[i][j] * num, i, j);        //* 연산 값을 i행 j열에 저장
		}
	}

	return m;            //임시 객체 반환
}