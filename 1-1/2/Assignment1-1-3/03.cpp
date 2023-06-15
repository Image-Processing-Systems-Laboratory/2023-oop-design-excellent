#include<iostream>
using namespace std;

void swap(int& x, int& y);
void makePositive(int& x, int& y);
int getGCD(int x, int y);
long long getLCM(int x, int y);

int main()
{
	int x, y;

	cout << "x: "; cin >> x;
	cout << "y: "; cin >> y;
	
	cout << "�ּҰ����: " << getLCM(x, y) << endl;
}

/*�� ���� ����� ����� �ش�.*/
void makePositive(int& x, int& y)
{
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
}
/*���� x, y�� ����� ���� ���� �ٲ��ش�.*/
void swap(int& x, int& y)
{
	int tmp;

	tmp = x;
	x = y;
	y = tmp;
}

/*��Ŭ���� ȣ�������� �ִ����� ���ϱ�*/
int getGCD(int x, int y)
{
	if (x < y)
		swap(x, y);
	if (y == 0)
		return x;
	else
		return getGCD(y, x % y);
}

/* (x, y�� �ּҰ����) = (x * y / �ִ�����) �� ���� */
long long getLCM(int x, int y)
{
	long long lcm;

	makePositive(x, y); //������ �Էµŵ� ���ó�� ���
	lcm = (long long)x * (long long)y;
	lcm /= getGCD(x, y);
	
	return lcm;
}