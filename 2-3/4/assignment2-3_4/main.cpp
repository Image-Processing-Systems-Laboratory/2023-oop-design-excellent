#include "Matrix.h"
#include <iostream>

using namespace std;

int main() {
	Matrix a(5, 3);		// 5 x 3
	Matrix b(3, 4);		// 3 x 4
	Matrix r(3, 3);		// 3 x 3
	for (size_t i = 0; i < a.getRows(); i++) {		// test�� ���� a �ʱ�ȭ
		for (size_t j = 0; j < a.getCols(); j++) {
			a[i][j] = i+j;
		}
	}
	for (size_t i = 0; i < b.getRows(); i++) {		// test�� ���� b �ʱ�ȭ
		for (size_t j = 0; j < b.getCols(); j++) {
			b[i][j] = i + j;
		}
	}
	for (size_t i = 0; i < r.getRows(); i++) {		// test�� ���� r �ʱ�ȭ
		for (size_t j = 0; j < r.getCols(); j++) {
			r[i][j] = i - 2*j+7;
		}
	}
	r[0][0] = 0;
	a.print();			// a ��� ���
	b.print();			// b ��� ���
	Matrix c(a);		// a �� ����
	c.determinant();	// ���� ó��

	// ��� ����
	std::cout << "============��� ����============" << endl;
	add(r, a, c);	// a + c
	r.print();
	sub(r, a, c);	// a - c
	r.print();
	mul(r, a, b);	// a * c
	r.print();


	// ��Į�� ����
	std::cout << "============��Į�� ����============" << endl;
	a.print();
	elementAdd(r, a, 2);	// a + 2;
	r.print();
	elementSub(r, a, 2);	// a - 2;
	r.print();
	elementMul(r, a, 2);	// a * 2;
	r.print();
	elementDiv(r, a, 2);	// a / 2;
	r.print();


	// Matrix Operation
	std::cout << "============��� ����============" << endl;
	transpose(r, a);		// ��ġ ���
	a.print();
	std::cout << "��ġ ��" << endl;
	r.print();

	r.setData(3, 3, nullptr);
	for (size_t i = 0; i < r.getRows(); i++) {		// test�� ���� 3x3���� r �ʱ�ȭ
		for (size_t j = 0; j < r.getCols(); j++) {
			r[i][j] = i - 2 * j + 7;
		}
	}
	r[0][0] = 0;

	std::cout << "r�� ��Ľ�: " << r.determinant() << endl;		// ��Ľ� �� ��ȯ result: -14
	r.print();
	adjoint(a, r);
	std::cout << "���� ���" << endl;
	a.print();
	inverse(a, r);
	std::cout << "�� ���" << endl;
	a.print();
}