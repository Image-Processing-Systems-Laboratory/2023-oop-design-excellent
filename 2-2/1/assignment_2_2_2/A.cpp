#include "A.h" // A Ŭ������ ������ ��� ���

A::A(double input)
{
	num = input; // �Է°����� num �ʱ�ȭ
	cout << "Class A is created with " << num << endl;
}

A::~A()
{
	cout << "Class A is destroyed with " << num << endl;
}