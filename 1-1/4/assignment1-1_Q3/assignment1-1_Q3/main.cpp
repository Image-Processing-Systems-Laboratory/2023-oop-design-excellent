#include <iostream>
using namespace std;

int GCD(int x, int y); // �ִ����� ���ϴ� �Լ� ��������

int main()
{
	int a, b, gcd;
	long long lcm; // �ּҰ���� ���庯��. overflow ������ long long�� ����

	// �� �Է°� ����
	cout << "Enter two number ";
	cin >> a >> b;

	// a�� b���� ������ ���� ��ġ �ٲ�
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	// gcd ������ �ִ����� ���ϴ� �Լ� ȣ���Ͽ� ����
	gcd = GCD(a, b);
	// lcm ������ a�� b�� ���� �ִ������� ������ ����
	lcm = static_cast<long long>(a) * b / gcd;

	// ��� ���
	cout << endl << "GCD : " << gcd << endl << "LCD : " << lcm << endl;

	return 0;
}

// �ִ����� ���ϴ� �Լ�. ��Ŭ���� ȣ����
// �� �Ű������� x�� �� �Ű������� y���� Ŀ����
int GCD(int x, int y)
{
	// �ι�° �Ű������� 0�̵Ǹ� ù��° �Ű������� �ִ�����
	if (y == 0)
		return x;
	// �ι�° �Ű������� 0�� �ƴϸ� GCD �Լ� ��ȣ�� (����Լ�)
	// ù��° �Ű������� y��, �ι�° �Ű������� x�� y�� ���� ������ ����
	else
		return GCD(y, x % y);
}