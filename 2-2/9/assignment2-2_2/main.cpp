#include <iostream>
#include "A.h"

using namespace std;

int main(void) {
	double num;
	
	cin >> num;   //숫자 입력 받기

	A a(num);     //A class의 객체 a 생성하며 생성자에 num을 인자로 전달

	return 0;
}