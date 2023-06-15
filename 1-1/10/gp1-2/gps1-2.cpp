#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a = 0;
    float b = 0;
    float c = 0;
    float x1 = 0;
    float x2 = 0;
    cin >> a >> b >> c;
    if (b > 0)
    {
        // x1 = ((-1 * b + sqrt(pow(b, 2) - (4 * a * c))) / 2 * a); ������ �� ��������
        x1 = 2 * c / (-1 * b - sqrt(pow(b, 2) - (4 * a * c))); // �и� ���ڿ� -b-sqrt(pow(b,2)-(4*a*c))�� ���ؼ� ���� ������ ���� ���·� �ٲ㼭 ���� �ذ�
        x2 = ((-1 * b - sqrt(pow(b, 2) - (4 * a * c))) / 2 * a); // ���ʿ� ���� ���·� �������Ƿ� �״�� ����
        // ���⼭ �����̶� -1�� ���ڸ� �������� + ���·� �ٲ�⿡ �������¶�� �ϴ� ���̴�.
    }
    else // ��ſ� ���࿡ b�� ������ �ᱹ -b-sqrt(b^2-4ac)�� ����� �������� ���� �����̹Ƿ� �̶��� ������ x1�� �״�� ����ϰ� x2�� ����ȭ����� �Ѵ�.
    {
        x1 = ((-1 * b + sqrt(pow(b, 2) - (4 * a * c))) / 2 * a);
        x2 = 2 * c / (-1 * b + sqrt(pow(b, 2) - (4 * a * c)));
    }
    cout << "the roots of " << a << "x^2" << " + " << b << "x" << " + " << c << " = 0 : " << endl << endl;
    if (a == 0) // a�� 0�� ���(�и� 0)
        cout << "Unexpected factor of a quadratic term" << endl;
    else if (pow(b, 2) - (4 * a * c) < 0) // ��Ʈ ���� ���� ���� ������ ���
        cout << "The equation has no real number solutions." << endl;
    else if (x1 == x2) // x1�� x2�� ���� ���� ���� ���(double root�� ���߱��� ����)
        cout << "x1, x2: " << x1 << "(double root)" << endl;
    else // �Ϲ����� ���
        cout << "X1: " << x1 << ", X2: " << x2 << endl;
    return 0;
}