#include <iostream>
#include "A.h"
using namespace std;

int main()
{
	double num = 0;   // 사용자에게 입력 받을 double 형 변수 선언 및 초기화
	cin >> num;       // 사용자에게 num 값을 입력받음
	A S(num);           // num 값을 사용하여 class 선언
	return 0;
}