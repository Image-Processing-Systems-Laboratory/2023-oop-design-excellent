#include <iostream>
using namespace std;

int gcd(int x, int y); // �ִ����� �Լ� ����
long long int lcm(int x, int y); // �ּҰ���� �Լ� ����

int main()
{
    int x, y; // �� ���� �Է¹��� ���� ����
    cout << "Enter x and y : ";
    cin >> x >> y; // �� �� �Է¹ޱ�
    cout << "LCM of " << x << " and " << y << " is " << lcm(x, y) << endl; // �ּҰ���� ���
    return 0;
}

int gcd(int x, int y) // �ִ����� �Լ� ����
{
    if (y == 0) // y�� 0�̸� x�� �ִ�����
    {
        return x; // x ��ȯ
    }
    else // y�� 0�� �ƴϸ�
    {
        return gcd(y, x % y); // y�� x�� y�� ���� �������� ���ڷ� �ϴ� gcd �Լ� ȣ�� (��͸� �̿��� ��Ŭ���� ȣ����)
    }
}

long long int lcm(int x, int y) // �ּҰ���� �Լ� ����
{
    long long int gcd1 = gcd(x, y); // gcd1�� gcd �Լ��� ��ȯ�� ����
    return (x / gcd1) * y; // �ּҰ���� ��ȯ
}
