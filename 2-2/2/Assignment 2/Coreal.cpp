#include "Coreal.h"
#include <iostream>

using namespace std;

A::A(double val) : value(val) //������ -> �Ű����� ���
{
	cout << "Class A is created with" << value << endl;
}

A::~A() //�Ҹ���
{
	cout << "Class A is destroyed with" << value << endl;
}