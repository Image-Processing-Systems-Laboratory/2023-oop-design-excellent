#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	float a, b, c;

	cout << "a: "; cin >> a; //x������ ���
	cout << "b: "; cin >> b; // x�� ���
	cout << "c: "; cin >> c; // ���

	if (a == 0) // a = 0�̸� ������������ �ȴ�.
		cout << "Unexpected factor of a quadratic term" << endl;
	else if (pow(b, 2) < 4 * a * c) // �Ǻ��� D < 0 �̸� �ذ� �������� ����
		cout << "The equation has no real number solutions." << endl;
	else if (pow(b, 2) == 4 * a * c) // �Ǻ��� D = 0 �̸� �߱��� ������.
		cout << "X1, X2: " << (-b  / (2 * a)) << " (double root)" << endl;
	else // �Ǻ��� D > 0 �̸� ���� �ٸ� �� �Ǳ��� ������.
	{
		cout << "X1: " << (-4 * a * c) / ((2 * a) * (b + (sqrt(pow(b, 2) - 4 * a * c)))) << ", ";
		cout << "X2: " << (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) << endl;
	}
}