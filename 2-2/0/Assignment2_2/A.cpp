#include"A.h"
#include<iostream>
using namespace std;
A::A(double val)	// �������� �Ű������� ��°� �ʱ�ȭ ����
{
	value = val;
	cout << "Class A is created with " << val << endl;
}
A::~A()	// �Ҹ��ڿ��� ���
{
	cout << "Class A is destroyed with " << value;
}