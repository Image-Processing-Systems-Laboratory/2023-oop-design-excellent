#include "Coreal.h"
#include <iostream>

using namespace std;

A::A(double val) : value(val) //생성자 -> 매개변수 사용
{
	cout << "Class A is created with" << value << endl;
}

A::~A() //소멸자
{
	cout << "Class A is destroyed with" << value << endl;
}