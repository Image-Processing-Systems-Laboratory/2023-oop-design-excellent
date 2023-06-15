#include "Matrix.h"
#include <iostream>

using namespace std;

void Input_elements(Matrix& m);       //element를 입력 받아 저장하는 함수

int main(void)
{
	
	Matrix A, B;                   //객체 생성

	//A Matrix의 elements 값 입력
	cout << "Input elements of Matrix A:" << endl;
	Input_elements(A);

	//B Matrix의 elements 값 입력
	cout << endl << "Input elements of Matrix B : " << endl;
	Input_elements(B);

	cout << "========================================================" << endl;

	//A Matrix 출력
	cout << "A = " << endl;
	A.print();

	//B Matrix 출력
	cout << endl << "B = " << endl;
	B.print();

	//A += B 연산 후 A Matrix 출력
	cout << endl << "(A += B)" << endl;
	A += B;
	cout << "A = " << endl;
	A.print();

	//C = A * B 연산 후 C Matrix 출력
	cout << endl << "(C = A * B)" << endl;
	Matrix C = A * B;
	cout << "C = " << endl;
	C.print();

	//C -= B 연산 후 A Matrix 출력
	cout << endl << "(C -= B)" << endl;
	C -= B;
	cout << "C = " << endl;
	C.print();

	return 0;
}

//element를 입력 받아 저장하는 함수
void Input_elements(Matrix& m)
{
	double number;

	//각 element마다 값을 입력 받아 저장
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> number;
			m.SetElement(number, i, j);
		}
	}
}