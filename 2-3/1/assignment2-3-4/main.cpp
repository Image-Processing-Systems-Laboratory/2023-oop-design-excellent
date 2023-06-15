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

		/* 2���� �迭 ���� �Ҵ�*/
		aData = memory_alloc2D(aRows, aCols);
		bData = memory_alloc2D(bRows, bCols);

		srand((unsigned int)time(NULL));
		for (int i = 0; i < aRows; i++) {
			for (int j = 0; j < aCols; j++)
				aData[i][j] = float(rand() % 100)/10; // �ִ� 9.9������ �Ǽ��� �������� ����
		}
		a.setData(aRows, aCols, aData);

		for (int i = 0; i < bRows; i++) {
			for (int j = 0; j < bCols; j++)
				bData[i][j] = float(rand() % 100) / 10; // �ִ� 9.9������ �Ǽ��� �������� ����
		}
		b.setData(bRows, bCols, bData);

		/* 2���� �迭 ����*/
		memory_free2D(aData);
		memory_free2D(bData);
		
		/* �Ҽ��� �Ʒ� ���ڸ����� ��Ÿ����*/
		cout << fixed;
		cout.precision(2);

		cout << "A: " << endl;
		a.print();	cout << endl;
		cout << "B: " << endl;
		b.print();	cout << endl;
		
		/* ��� ����*/
		cout << "Add of Matrixed: " << endl;
		add(r, a, b).print();	cout << endl;
		
		/* ��� �E��*/
		cout << "Sub of Matrixed: " << endl;
		sub(r, a, b).print();	cout << endl;

		/* ��� ����*/
		cout << "Mul of Matrixed: " << endl;
		mul(r, a, b).print();	cout << endl;

		/* ��Į�� ����*/
		cout << "Add scalar 5: " << endl;
		elementAdd(r, a, 5).print();	cout << endl;

		/* ��Į�� ����*/
		cout << "Sub scalar 5: " << endl;
		elementSub(r, a, 5).print();	cout << endl;

		/* ��Į�� ����*/
		cout << "Mul scalar 5: " << endl;
		elementMul(r, a, 5).print();	cout << endl;

		/* ��Į�� ������*/
		cout << "Div scalar 5: " << endl;
		elementDiv(r, a, 5).print();	cout << endl;

		/* ��ġ���*/
		cout << "Transpose of A: " << endl;
		transpose(r, a).print();	cout << endl;

		/* ��Ľ�*/
		cout << "determinant of A: " << endl;
		cout << a.determinant() << endl << endl;
		
		/* �������*/
		cout << "adjoint of A: " << endl;
		adjoint(r, a).print();	cout << endl;
		
		/* �����*/
		cout << "Inverse of A: " << endl;
		inverse(r, a).print();	cout << endl;
	}

	return 0;
}