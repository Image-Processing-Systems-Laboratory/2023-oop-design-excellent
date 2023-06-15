#include"A.h"
#include<iostream>
using namespace std;
A::A(double val)	// 생성자의 매개변수로 출력과 초기화 진행
{
	value = val;
	cout << "Class A is created with " << val << endl;
}
A::~A()	// 소멸자에서 출력
{
	cout << "Class A is destroyed with " << value;
}