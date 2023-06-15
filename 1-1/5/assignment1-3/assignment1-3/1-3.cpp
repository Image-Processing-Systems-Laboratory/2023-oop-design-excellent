#include <iostream> //iostream ����
using namespace std; //namespace std ����
int gcd(int n1, int n2); //gcd�Լ� ����

int main() //main�Լ� ����
{
	int x, y = 0; //�� ���� x�� y ����

	cout << "Input x = ";
	cin >> x;
	cout << "Input y = ";
	cin >> y;
	//�� ���� x�� y �Է¹ޱ�

	int resgcd = 0; //�ִ������� ���� ���� ���� ����

	if (x < y) //x�� y���� ���� ��
	{
		int swap = x;
		x = y;
		y = swap;
	} //swap�� ���� x�� y�� ���� ��ȯ

	resgcd = gcd(x, y); //�� ���� �ִ����� ���� ������ ����

	long long reslcd = (static_cast<long long> (x) / resgcd) * y; //overflow ������ ���� ���� ������ ���� Ÿ���� ����, �ּҰ���� ����

	cout << "GCD = " << resgcd << endl; //�ִ����� ���
	cout << "LCD = " << reslcd << endl; //�ּҰ���� ���

	return 0; //0�� ��ȯ
} //main�Լ� ����

int gcd(int n1, int n2) //�ִ������� ���ϴ� �Լ�
{
	int u = 0;
	while (n2 != 0)
	{
		u = n1 % n2;
		n1 = n2;
		n2 = u;
	} //Euclidean algorithm �̿�
	return n1;
} //gcd�Լ� ����