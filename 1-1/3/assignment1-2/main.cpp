#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float   a, b, c;
	float 	x1, x2;

	cout << "Input(a, b, c): ";
	cin >> a >> b >> c; // a, b, c�� ������ �������� ���������� �Է¹���(scanfó��)
	if (a == 0)
		cout << "Unexpected factor of a quadratic term" << endl;
	// a == 0�̸� ���� ���Ŀ��� �и� 0�� �ǹǷ� ���� �Ұ�
	else if (pow(b, 2) - 4 * a * c < 0)
		cout << "The equation has no real number solutions." << endl;
	// b^2 -4ac < 0�̸� ���� ���Ŀ��� ��Ʈ ���� ������ �ǹǷ� ����� ���� �Ǳ��� ����
	else
	{
		if (b < 0)
		{
			x1 = (-1 * b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
			x2 = (4 * a * c) / (2 * a * (-1 * b + sqrt(pow(b, 2) - 4 * a * c)));
		}
		// b < 0�� ��, ��Ʈ �տ� -�� �ٴ� ��(x2)�� ����ϸ� ������ ���� ������ �̷�� �� �� ����
		// (��: a = 1, b = -62.1, c = 1)
		// �̶� ���ڸ� ����ȭ �ؼ� ������ ���� ������ ������ ���� �������� �ٲٸ� ���� �ּ�ȭ
		else
		{
			x1 = (-4 * a * c) / (2 * a * (b + sqrt(pow(b, 2) - 4 * a * c)));
			x2 = (-1 * b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		}
		// b >= 0�� ��, ��Ʈ �տ� +�� �ٴ� ��(x2)�� ����ϸ� ������ ���� ������ �̷�� �� �� ����
		// (��: a = 1, b = 62.1, c = 1)
		// �̶� ���ڸ� ����ȭ �ؼ� ������ ���� ������ ������ ���� �������� �ٲٸ� ���� �ּ�ȭ
		if (x1 == x2)
			cout << "x1, x2: " << x1 << "(double root)" << endl;
		else
			cout << "x1: " << x1 << " x2: " << x2 << endl;
	}
	return (0);
}