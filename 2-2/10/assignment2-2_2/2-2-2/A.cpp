#include "A.hpp"
#include <iostream>

A::A(double d) // ������
	: val(d) // val �Ӽ��� ���ڷ� ���� d�� ����
{
	// ������ ȣ���� �� �� �ְ� ���
	std::cout << "Class A is created with " << val << std::endl;
}

A::~A(void)
{
	// �Ҹ��� ȣ���� �� �� �ְ� ���
	std::cout << "Class A is destroyed with " << val << std::endl;
}