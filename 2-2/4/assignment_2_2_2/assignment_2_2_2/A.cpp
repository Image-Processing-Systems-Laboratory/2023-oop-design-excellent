#include"A.h"
using namespace std;

A::A(double num) {	//������
	variable = num;			//���ڷ� ���� ���� ���� ������ ����
	cout << "Class A is created with " << variable << endl;
}

A::~A() {			//�Ҹ���
	cout << "Class A is destroyed with " << variable << endl;
}