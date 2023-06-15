#include "A.hpp"
#include <iostream>

A::A(double d) // 생성자
	: val(d) // val 속성에 인자로 받은 d를 넣음
{
	// 생성자 호출을 볼 수 있게 출력
	std::cout << "Class A is created with " << val << std::endl;
}

A::~A(void)
{
	// 소멸자 호출을 볼 수 있게 출력
	std::cout << "Class A is destroyed with " << val << std::endl;
}