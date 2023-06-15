#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a, b, c, discriminant, x1, x2;

	// �Է°� �ޱ� (a, b, c)
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	// a, b, c�� �Ǻ��� ��� �� discriminant�� ����
	discriminant = pow(b, 2) - 4 * a * c;

	cout << endl << "the roots of " << a << "x^2 + " << b << "x + " << c << " = 0 :" << endl << endl;

	// a�� 0�̸� ���� ��� �� ���α׷� ����
	if (a == 0)
	{
		cout << "Unexpected factor of a quadratic term" << endl;
		return 0;
	}
	
	// �Ǻ����� 0�̸� �߱��� ���
	if (discriminant == 0)
	{
		cout << "X1, X2: " << -b / (2 * a) << " (double root)" << endl;
	}
	// �Ǻ����� 0���� ������ ���� ���ٰ� ���
	else if (discriminant < 0)
	{
		cout << "The equation has no real number solutions." << endl;
	}
	// �Ǻ����� 0 �ʰ��� �� 
	else
	{
		// b�� ����� ��� ���ǰ��� ���
		if (b > 0)
		{
			// x1�� ����ȭ�ؼ� ����ϰ�, x2�� �״�� ���
			x1 = (-2 * c) / (b + sqrt(discriminant));
			x2 = (-b - sqrt(discriminant)) / (2 * a);
		}
		// b�� ������ ��� (b == 0 �̸� �Ǻ��ĵ� �����̹Ƿ� ��� x
		else
		{
			// x1�� �״�� ����ϰ�, x2�� ����ȭ�ؼ� ���
			x1 = (-b + sqrt(discriminant)) / (2 * a);
			x2 = (-2 * c) / (b - sqrt(discriminant));
		}
		// ��� ���
		cout << "X1: " << x1 << ", X2: " << x2 << endl;
	}

	return 0;
}