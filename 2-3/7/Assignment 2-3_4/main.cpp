#include "class.h"

int main()
{
	/*클래스 객체 생성*/
	ooplinalg::Matrix A(3, 3); //A,B: 두 행렬 연산 테스트
	ooplinalg::Matrix B(3, 3);
	ooplinalg::Matrix R(3, 3); //R: 결과 저장

	ooplinalg::Matrix M(3, 3); //M: 스칼라 연산 테스트

	ooplinalg::Matrix T(2, 3); //T: 전치행렬 테스트
	ooplinalg::Matrix R2(3, 2); //R2: 결과 저장

	ooplinalg::Matrix O(3, 3); //O: 그 외 역행렬 테스트


	float a[3][3] = { {2, 2, 3}, {1, 1, 2}, {1, 2, 3} };
	float b[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	float m[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	float o[3][3] = { {1, 4, 1}, {2, 3, 1}, {0, 2, 1} };
	float t[2][3] = { {1, 2, 3}, {4, 5, 6} };

	/*각 요소 객체에 전달*/
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			A.setElement(i, j, a[i][j]);
			B.setElement(i, j, b[i][j]);
			M.setElement(i, j, m[i][j]);
			O.setElement(i, j, o[i][j]);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			T.setElement(i, j, t[i][j]);
		}
	}

	/*덧셈*/
	cout << "/* A + B */" << endl;
	ooplinalg::add(R, A, B);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*뺄셈*/
	cout << "/* A - B */" << endl;
	ooplinalg::sub(R, A, B);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*곱셈*/
	cout << "/* A x B */" << endl;
	ooplinalg::mul(R, A, B);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*스칼라 덧셈*/
	cout << "/* A + 4 */" << endl;
	ooplinalg::elementAdd(R, M, 4);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*스칼라 뺄셈*/
	cout << "/* A - 2 */" << endl;
	ooplinalg::elementSub(R, M, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*스칼라 곱셈*/
	cout << "/* A x 2 */" << endl;
	ooplinalg::elementMul(R, M, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*스칼라 나눗셈*/
	cout << "/* A / 2 */" << endl;
	ooplinalg::elementDiv(R, M, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/* 행렬식 */
	cout << "/* 3x3 행렬식 */" << endl;
	cout << O.determinant() << endl;
	cout << endl;

	/*전치행렬*/
	cout << "/* 전치행렬 */" << endl;
	ooplinalg::transpose(R2, T);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << R2.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*수반행렬*/
	cout << "/* 수반행렬 */" << endl;
	ooplinalg::adjoint(R, O);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*역행렬*/
	cout << "/* 역행렬 */" << endl;
	ooplinalg::inverse(R, O);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}