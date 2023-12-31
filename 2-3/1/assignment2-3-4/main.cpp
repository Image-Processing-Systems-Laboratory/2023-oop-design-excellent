#include"Matrix.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace ooplinalg;

int main() {
	Matrix r, a, b;
	float** aData;
	float** bData;
	int val;
	int aRows, aCols;
	int bRows, bCols;
	while (1) {
		cout << "Program Exit: 0, Continue: any input" << endl;
		cin >> val;
		if (val == 0)
			break;
		cout << "rows and cols of A: "; cin >> aRows >> aCols;
		cout << "rows and cols of B: "; cin >> bRows >> bCols;
		cout << endl;

		/* 2차원 배열 동적 할당*/
		aData = memory_alloc2D(aRows, aCols);
		bData = memory_alloc2D(bRows, bCols);

		srand((unsigned int)time(NULL));
		for (int i = 0; i < aRows; i++) {
			for (int j = 0; j < aCols; j++)
				aData[i][j] = float(rand() % 100)/10; // 최대 9.9까지의 실수를 랜덤으로 저장
		}
		a.setData(aRows, aCols, aData);

		for (int i = 0; i < bRows; i++) {
			for (int j = 0; j < bCols; j++)
				bData[i][j] = float(rand() % 100) / 10; // 최대 9.9까지의 실수를 랜덤으로 저장
		}
		b.setData(bRows, bCols, bData);

		/* 2차원 배열 해제*/
		memory_free2D(aData);
		memory_free2D(bData);
		
		/* 소수점 아래 두자리까지 나타내기*/
		cout << fixed;
		cout.precision(2);

		cout << "A: " << endl;
		a.print();	cout << endl;
		cout << "B: " << endl;
		b.print();	cout << endl;
		
		/* 행렬 덧셈*/
		cout << "Add of Matrixed: " << endl;
		add(r, a, b).print();	cout << endl;
		
		/* 행렬 뺼셈*/
		cout << "Sub of Matrixed: " << endl;
		sub(r, a, b).print();	cout << endl;

		/* 행렬 곱셈*/
		cout << "Mul of Matrixed: " << endl;
		mul(r, a, b).print();	cout << endl;

		/* 스칼라 덧셈*/
		cout << "Add scalar 5: " << endl;
		elementAdd(r, a, 5).print();	cout << endl;

		/* 스칼라 뺄셈*/
		cout << "Sub scalar 5: " << endl;
		elementSub(r, a, 5).print();	cout << endl;

		/* 스칼라 곱셈*/
		cout << "Mul scalar 5: " << endl;
		elementMul(r, a, 5).print();	cout << endl;

		/* 스칼라 나눗셈*/
		cout << "Div scalar 5: " << endl;
		elementDiv(r, a, 5).print();	cout << endl;

		/* 전치행렬*/
		cout << "Transpose of A: " << endl;
		transpose(r, a).print();	cout << endl;

		/* 행렬식*/
		cout << "determinant of A: " << endl;
		cout << a.determinant() << endl << endl;
		
		/* 수반행렬*/
		cout << "adjoint of A: " << endl;
		adjoint(r, a).print();	cout << endl;
		
		/* 역행렬*/
		cout << "Inverse of A: " << endl;
		inverse(r, a).print();	cout << endl;
	}

	return 0;
}