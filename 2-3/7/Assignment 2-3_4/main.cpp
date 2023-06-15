#include "class.h"

int main()
{
	/*Ŭ���� ��ü ����*/
	ooplinalg::Matrix A(3, 3); //A,B: �� ��� ���� �׽�Ʈ
	ooplinalg::Matrix B(3, 3);
	ooplinalg::Matrix R(3, 3); //R: ��� ����

	ooplinalg::Matrix M(3, 3); //M: ��Į�� ���� �׽�Ʈ

	ooplinalg::Matrix T(2, 3); //T: ��ġ��� �׽�Ʈ
	ooplinalg::Matrix R2(3, 2); //R2: ��� ����

	ooplinalg::Matrix O(3, 3); //O: �� �� ����� �׽�Ʈ


	float a[3][3] = { {2, 2, 3}, {1, 1, 2}, {1, 2, 3} };
	float b[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	float m[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	float o[3][3] = { {1, 4, 1}, {2, 3, 1}, {0, 2, 1} };
	float t[2][3] = { {1, 2, 3}, {4, 5, 6} };

	/*�� ��� ��ü�� ����*/
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

	/*����*/
	cout << "/* A + B */" << endl;
	ooplinalg::add(R, A, B);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*����*/
	cout << "/* A - B */" << endl;
	ooplinalg::sub(R, A, B);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*����*/
	cout << "/* A x B */" << endl;
	ooplinalg::mul(R, A, B);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*��Į�� ����*/
	cout << "/* A + 4 */" << endl;
	ooplinalg::elementAdd(R, M, 4);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*��Į�� ����*/
	cout << "/* A - 2 */" << endl;
	ooplinalg::elementSub(R, M, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*��Į�� ����*/
	cout << "/* A x 2 */" << endl;
	ooplinalg::elementMul(R, M, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*��Į�� ������*/
	cout << "/* A / 2 */" << endl;
	ooplinalg::elementDiv(R, M, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/* ��Ľ� */
	cout << "/* 3x3 ��Ľ� */" << endl;
	cout << O.determinant() << endl;
	cout << endl;

	/*��ġ���*/
	cout << "/* ��ġ��� */" << endl;
	ooplinalg::transpose(R2, T);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << R2.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*�������*/
	cout << "/* ������� */" << endl;
	ooplinalg::adjoint(R, O);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << R.getElement(i, j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	/*�����*/
	cout << "/* ����� */" << endl;
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