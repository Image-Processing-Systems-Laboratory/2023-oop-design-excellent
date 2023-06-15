#include "A.hpp"
#include <iostream>

int main(void)
{
	double input;

	std::cin >> input; // 수 입력받음
	A a(input); // input에 대한 A의 생성자 호출
	return (0); // 프로그램 끝나며 A의 소멸자 호출
}
