#include <iostream>

using namespace std;

//�� ������ �ִ������� �����ϴ� �Լ�
int gcd(int x, int y);
//�� ������ �ּҰ������ �����ϴ� �Լ�
int lcm(int x, int y);

int main() {
	int x, y;		//�� ������ �Է� ���� ����
	cout << "Enter the numbers." << endl;
	cin >> x >> y;
	cout << "LCM of two numbers is " << lcm(x, y) << endl;		//�ּҰ���� ���
}

int gcd(int x, int y) {
	//��Ŭ���� ȣ���� �̿�
	if (y == 0)
		return x;
	return gcd(y, x % y);		//��������� ����
}

int lcm(int x, int y) {
	//gcd�� �̿�
	return (x / gcd(x, y)) * y;		// (x * y) / gcd(x,y)�� ��� x * y���� �����÷ο찡 �Ͼ�� ����.
}