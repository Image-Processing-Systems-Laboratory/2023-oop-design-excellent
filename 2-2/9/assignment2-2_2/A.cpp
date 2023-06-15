#include <iostream>
#include "A.h"

using namespace std;

//생성자
A::A(double anum) {
	num = anum;  //private member num에 인자로 전달 받은 값 대입
	
	cout << "Class A is created with " << num << endl;    //문장 출력
}

//파괴자
A::~A() {
	cout << "Class A is destroyed with " << num << endl;  //문장 출력
}