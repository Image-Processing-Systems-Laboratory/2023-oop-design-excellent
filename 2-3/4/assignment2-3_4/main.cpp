#include "Matrix.h"
#include <iostream>

using namespace std;

int main() {
	Matrix a(5, 3);		// 5 x 3
	Matrix b(3, 4);		// 3 x 4
	Matrix r(3, 3);		// 3 x 3
	for (size_t i = 0; i < a.getRows(); i++) {		// test를 위해 a 초기화
		for (size_t j = 0; j < a.getCols(); j++) {
			a[i][j] = i+j;
		}
	}
	for (size_t i = 0; i < b.getRows(); i++) {		// test를 위해 b 초기화
		for (size_t j = 0; j < b.getCols(); j++) {
			b[i][j] = i + j;
		}
	}
	for (size_t i = 0; i < r.getRows(); i++) {		// test를 위해 r 초기화
		for (size_t j = 0; j < r.getCols(); j++) {
			r[i][j] = i - 2*j+7;
		}
	}
	r[0][0] = 0;
	a.print();			// a 행렬 출력
	b.print();			// b 행렬 출력
	Matrix c(a);		// a 값 복사
	c.determinant();	// 예외 처리

	// 행렬 연산
	std::cout << "============행렬 연산============" << endl;
	add(r, a, c);	// a + c
	r.print();
	sub(r, a, c);	// a - c
	r.print();
	mul(r, a, b);	// a * c
	r.print();


	// 스칼라 연산
	std::cout << "============스칼라 연산============" << endl;
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
	std::cout << "============행렬 연산============" << endl;
	transpose(r, a);		// 전치 행렬
	a.print();
	std::cout << "전치 ↓" << endl;
	r.print();

	r.setData(3, 3, nullptr);
	for (size_t i = 0; i < r.getRows(); i++) {		// test를 위해 3x3으로 r 초기화
		for (size_t j = 0; j < r.getCols(); j++) {
			r[i][j] = i - 2 * j + 7;
		}
	}
	r[0][0] = 0;

	std::cout << "r의 행렬식: " << r.determinant() << endl;		// 행렬식 값 반환 result: -14
	r.print();
	adjoint(a, r);
	std::cout << "수반 행렬" << endl;
	a.print();
	inverse(a, r);
	std::cout << "역 행렬" << endl;
	a.print();
}