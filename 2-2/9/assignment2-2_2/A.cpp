#include <iostream>
#include "A.h"

using namespace std;

//������
A::A(double anum) {
	num = anum;  //private member num�� ���ڷ� ���� ���� �� ����
	
	cout << "Class A is created with " << num << endl;    //���� ���
}

//�ı���
A::~A() {
	cout << "Class A is destroyed with " << num << endl;  //���� ���
}