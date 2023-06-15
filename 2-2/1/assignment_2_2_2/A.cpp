#include "A.h" // A 클래스의 선언이 담긴 헤더

A::A(double input)
{
	num = input; // 입력값으로 num 초기화
	cout << "Class A is created with " << num << endl;
}

A::~A()
{
	cout << "Class A is destroyed with " << num << endl;
}