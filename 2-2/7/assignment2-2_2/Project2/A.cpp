#include "A.h"
A::A()   // ������ ����
{
	member = 0;    // memver �� �ʱ�ȭ
	cout << "Class A is created with " << member << endl;   // member ���� ����� ���ڿ� ���
}
A::A(double num)               // �Ű������� �ִ� ������ ����
{
	member = num;             // �Էµ� �Ű� ������ member �� �ʱ�ȭ
	cout << "Class A is created with " << member << endl;   // member ���� ����� ���ڿ� ���
}
A::~A()                          // �ı��� ����
{
	cout << "Class A is destroyed with " << member << endl; // member ���� ����� ���ڿ� ���
} 