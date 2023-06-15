#include "A.h"
/*
* A클래스의 맴버 메서드 정의부
*/

//생성자
A::A(int data) {
	//입력받은 변수를 출력
	cout << "Class A is created with " << data << endl;
	//맴버 변수에 입력받은 변수 저장
	this->data = data;
}
//소멸자
A::~A() {
	//맴버 변수의 값 출력
	cout << "Class A is destroyed with " << data << endl;
}
