#include"A.h"
using namespace std;

A::A(double num) {	//생성자
	variable = num;			//인자로 받은 값을 내부 변수에 저장
	cout << "Class A is created with " << variable << endl;
}

A::~A() {			//소멸자
	cout << "Class A is destroyed with " << variable << endl;
}