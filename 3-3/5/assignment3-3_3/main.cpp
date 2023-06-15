#include "Matrix.h"
#include <iostream>

using namespace std;

void Input_elements(Matrix& m);       //element�� �Է� �޾� �����ϴ� �Լ�

int main(void)
{
	
	Matrix A, B;                   //��ü ����

	//A Matrix�� elements �� �Է�
	cout << "Input elements of Matrix A:" << endl;
	Input_elements(A);

	//B Matrix�� elements �� �Է�
	cout << endl << "Input elements of Matrix B : " << endl;
	Input_elements(B);

	cout << "========================================================" << endl;

	//A Matrix ���
	cout << "A = " << endl;
	A.print();

	//B Matrix ���
	cout << endl << "B = " << endl;
	B.print();

	//A += B ���� �� A Matrix ���
	cout << endl << "(A += B)" << endl;
	A += B;
	cout << "A = " << endl;
	A.print();

	//C = A * B ���� �� C Matrix ���
	cout << endl << "(C = A * B)" << endl;
	Matrix C = A * B;
	cout << "C = " << endl;
	C.print();

	//C -= B ���� �� A Matrix ���
	cout << endl << "(C -= B)" << endl;
	C -= B;
	cout << "C = " << endl;
	C.print();

	return 0;
}

//element�� �Է� �޾� �����ϴ� �Լ�
void Input_elements(Matrix& m)
{
	double number;

	//�� element���� ���� �Է� �޾� ����
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> number;
			m.SetElement(number, i, j);
		}
	}
}