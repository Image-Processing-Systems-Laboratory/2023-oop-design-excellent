#include "A.h"

// 생성자
A::A(double input)
{
	// 초기화
	value = input;
	// 출력
	cout << "Class A is created with " << value << endl;
}

// 소멸자
A::~A()
{
	// 출력
	cout << "Class A is destroyed with " << value << endl;
}