#include "Matrix.h"
#include <iostream>

using namespace oopstd;
using namespace std;

void printMatrix(const Matrix& m);      // ����� ����ϴ� �Լ�

int main()
{
    // ��� A
    Matrix A(3, 3);     // 3x3 ��� ����
    A.setElement(0, 0, 2);      // (0, 0)�� 2 ����
    A.setElement(0, 1, 2);
    A.setElement(0, 2, 3);
    A.setElement(1, 0, 1);
    A.setElement(1, 1, 1);
    A.setElement(1, 2, 2);
    A.setElement(2, 0, 1);
    A.setElement(2, 1, 2);
    A.setElement(2, 2, 3);
    cout << "A" << endl;
    printMatrix(A);

    // ��� B
    Matrix B(3, 3);
    B.setElement(0, 0, 1);
    B.setElement(0, 1, 2);
    B.setElement(0, 2, 3);
    B.setElement(1, 0, 4);
    B.setElement(1, 1, 5);
    B.setElement(1, 2, 6);
    B.setElement(2, 0, 7);
    B.setElement(2, 1, 8);
    B.setElement(2, 2, 9);
    cout << "B" << endl;
    printMatrix(B);
        
    // A + B
    Matrix C;
    add(C, A, B);
    cout << "A + B" << endl;
    printMatrix(C);
    
    // A - B
    Matrix D;
    sub(D, A, B);
    cout << "A - B" << endl;
    printMatrix(D);

    // A * B
    Matrix E;
    mul(E, A, B);
    cout << "A * B" << endl;
    printMatrix(E);
    
    // A = B
    sub(A, A, A);
    add(A, A, B);
    cout << "A" << endl;
    printMatrix(A);

    // A + 4
    Matrix F;
    elementAdd(F, A, 4);
    cout << "A + 4" << endl;
    printMatrix(F);

    // A - 2
    Matrix G;
    elementSub(G, A, 2);
    cout << "A - 2" << endl;
    printMatrix(G);

    // A * 2
    Matrix H;
    elementMul(H, A, 2);
    cout << "A * 2" << endl;
    printMatrix(H);

    // A / 2
    Matrix I;
    elementDiv(I, A, 2);
    cout << "A / 2" << endl;
    printMatrix(I);
    
    // A�� ��ġ ���
    Matrix J;
    transpose(J, A);
    cout << "Transpose A" << endl;
    printMatrix(J);

    // A�� ��Ľ�
    float det = A.determinant();
    cout << "determinant A = " << det << endl;

    // ��� K
    Matrix K(3, 3);
    K.setElement(0, 0, 1);
    K.setElement(0, 1, 4);
    K.setElement(0, 2, 1);
    K.setElement(1, 0, 2);
    K.setElement(1, 1, 3);
    K.setElement(1, 2, 1);
    K.setElement(2, 0, 0);
    K.setElement(2, 1, 2);
    K.setElement(2, 2, 1);
    cout << "K" << endl;
    printMatrix(K);

    // K�� ���� ���
    Matrix L;
    adjoint(L, K);
    cout << "adjoint K" << endl;
    printMatrix(L);

    // K�� �����
    Matrix M;
    inverse(M, K);
    cout << "inverse K" << endl;
    printMatrix(M);
    
    return 0;
}

void printMatrix(const Matrix& m) {
	int rows = m.getRows();
	int cols = m.getCols();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << m.getElement(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}