#include<iostream>

int gcd(int x, int y)		//��Ŭ���� ȣ����� ��������� ����
{
	if (y == 0)			//y�� 0�� �Ǹ� ����
		return x;
	else
		return gcd(y, x % y);
}

int main()
{
	int x, y;
	int g;		//�ִ�����
	int divided_x, divided_y;		//x��y�� �ִ������� ���� ��
	long long result;
	std::cout << "x:";
	std::cin >> x;
	std::cout << "y:";
	std::cin >> y;
	if (y > x)		//y�� x���� ũ�� �ٲ���
	{
		int temp;
		temp = x;
		x = y;
		y = temp;
	}
	g = gcd(x, y);
	divided_x = x / g;
	divided_y = y / g;
	result = (long long)g * (long long)divided_x * (long long)divided_y;		//�ڷ��� ��ȯ�� �̿��� ���
	std::cout << result;
}