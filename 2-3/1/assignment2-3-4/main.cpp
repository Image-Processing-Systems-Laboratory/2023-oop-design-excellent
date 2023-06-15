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

		/* 2Â÷¿ø ¹è¿­ µ¿Àû ÇÒ´ç*/
		aData = memory_alloc2D(aRows, aCols);
		bData = memory_alloc2D(bRows, bCols);

		srand((unsigned int)time(NULL));
		for (int i = 0; i < aRows; i++) {
			for (int j = 0; j < aCols; j++)
				aData[i][j] = float(rand() % 100)/10; // ÃÖ´ë 9.9±îÁöÀÇ ½Ç¼ö¸¦ ·£´ýÀ¸·Î ÀúÀå
		}
		a.setData(aRows, aCols, aData);

		for (int i = 0; i < bRows; i++) {
			for (int j = 0; j < bCols; j++)
				bData[i][j] = float(rand() % 100) / 10; // ÃÖ´ë 9.9±îÁöÀÇ ½Ç¼ö¸¦ ·£´ýÀ¸·Î ÀúÀå
		}
		b.setData(bRows, bCols, bData);

		/* 2Â÷¿ø ¹è¿­ ÇØÁ¦*/
		memory_free2D(aData);
		memory_free2D(bData);
		
		/* ¼Ò¼öÁ¡ ¾Æ·¡ µÎÀÚ¸®±îÁö ³ªÅ¸³»±â*/
		cout << fixed;
		cout.precision(2);

		cout << "A: " << endl;
		a.print();	cout << endl;
		cout << "B: " << endl;
		b.print();	cout << endl;
		
		/* Çà·Ä µ¡¼À*/
		cout << "Add of Matrixed: " << endl;
		add(r, a, b).print();	cout << endl;
		
		/* Çà·Ä –E¼À*/
		cout << "Sub of Matrixed: " << endl;
		sub(r, a, b).print();	cout << endl;

		/* Çà·Ä °ö¼À*/
		cout << "Mul of Matrixed: " << endl;
		mul(r, a, b).print();	cout << endl;

		/* ½ºÄ®¶ó µ¡¼À*/
		cout << "Add scalar 5: " << endl;
		elementAdd(r, a, 5).print();	cout << endl;

		/* ½ºÄ®¶ó »¬¼À*/
		cout << "Sub scalar 5: " << endl;
		elementSub(r, a, 5).print();	cout << endl;

		/* ½ºÄ®¶ó °ö¼À*/
		cout << "Mul scalar 5: " << endl;
		elementMul(r, a, 5).print();	cout << endl;

		/* ½ºÄ®¶ó ³ª´°¼À*/
		cout << "Div scalar 5: " << endl;
		elementDiv(r, a, 5).print();	cout << endl;

		/* ÀüÄ¡Çà·Ä*/
		cout << "Transpose of A: " << endl;
		transpose(r, a).print();	cout << endl;

		/* Çà·Ä½Ä*/
		cout << "determinant of A: " << endl;
		cout << a.determinant() << endl << endl;
		
		/* ¼ö¹ÝÇà·Ä*/
		cout << "adjoint of A: " << endl;
		adjoint(r, a).print();	cout << endl;
		
		/* ¿ªÇà·Ä*/
		cout << "Inverse of A: " << endl;
		inverse(r, a).print();	cout << endl;
	}

	return 0;
}