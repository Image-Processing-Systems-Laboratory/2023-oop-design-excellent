#include <iostream>
#include "A.h"
using namespace std;

int main()
{
	double num = 0;   // ����ڿ��� �Է� ���� double �� ���� ���� �� �ʱ�ȭ
	cin >> num;       // ����ڿ��� num ���� �Է¹���
	A S(num);           // num ���� ����Ͽ� class ����
	return 0;
}