#include "A.h"

A::A(double n)												//������
{
	N = n;													//private N���� ������ �� �Է�
	cout << "Class A is created with " << N << endl;		// private�� N ���
}

A::~A()														//�Ҹ���
{
	cout << "Class A is destroyed with " << N << endl;		//private N ���
}