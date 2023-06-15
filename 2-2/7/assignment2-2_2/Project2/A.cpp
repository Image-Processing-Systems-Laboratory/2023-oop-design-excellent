#include "A.h"
A::A()   // 생성자 정의
{
	member = 0;    // memver 값 초기화
	cout << "Class A is created with " << member << endl;   // member 값을 사용해 문자열 출력
}
A::A(double num)               // 매개변수가 있는 생성자 정의
{
	member = num;             // 입력된 매개 변수로 member 값 초기화
	cout << "Class A is created with " << member << endl;   // member 값을 사용해 문자열 출력
}
A::~A()                          // 파괴자 정의
{
	cout << "Class A is destroyed with " << member << endl; // member 값을 사용해 문자열 출력
} 