#include "A.h"

// ������
A::A(double input)
{
	// �ʱ�ȭ
	value = input;
	// ���
	cout << "Class A is created with " << value << endl;
}

// �Ҹ���
A::~A()
{
	// ���
	cout << "Class A is destroyed with " << value << endl;
}