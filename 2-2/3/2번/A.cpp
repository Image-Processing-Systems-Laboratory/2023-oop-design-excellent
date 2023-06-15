#include "A.h"

A::A(double n)												//생성자
{
	N = n;													//private N으로 접근해 값 입력
	cout << "Class A is created with " << N << endl;		// private의 N 출력
}

A::~A()														//소멸자
{
	cout << "Class A is destroyed with " << N << endl;		//private N 출력
}