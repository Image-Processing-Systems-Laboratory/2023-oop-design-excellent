#include "A.h"
/*
* AŬ������ �ɹ� �޼��� ���Ǻ�
*/

//������
A::A(int data) {
	//�Է¹��� ������ ���
	cout << "Class A is created with " << data << endl;
	//�ɹ� ������ �Է¹��� ���� ����
	this->data = data;
}
//�Ҹ���
A::~A() {
	//�ɹ� ������ �� ���
	cout << "Class A is destroyed with " << data << endl;
}
