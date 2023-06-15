#include "A.h"
using namespace std;

int main() {
	double input;

	cin >> input;

	class A a(input);		//입력한 값으로 객체 생성, 생성자 실행

	return 0;	//종료하며 소멸자 실행
}