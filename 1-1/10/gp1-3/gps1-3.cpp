#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long GCD(int x, int y) // �ִ����� �Լ�
{
    if (y == 0) // ���� y�� 0�̶��
        return x; // x�� �ִ������� �ȴ�.
    else
        return GCD(y, x % y); // GCD(y, x%y)�� ��ȯ�Ѵ�. �� ����Լ��ν�, y�� 0�� �ɶ����� ����ؼ� GCD�Լ��� �ݺ��ϴ� ���̴�. 
}

// �ּҰ������ �ִ������� �� ���� �ִ������� ���� ���� �����ָ� �ȴ�. �̴� ���μ����� ������ �����غ��� �� �� �ִ�.
// �� ���� �ᱹ �� ���� ���� �ִ������� ���� ���� ����, �� ���� �� �����ϹǷ� �� ���� ����Ѵ�.

long long LCM(int x, int y) // �ּҰ���� �Լ�
{
    return (x * (y / GCD(x, y))); // ������ ���� �� ����Ͽ� �ּҰ���� ���ϱ�. �̶� �ڷ����� �Ŀ� ���� ����ؾߵǴµ� �̴� �������� �ٷ絵�� �ϰڴ�.
}

int main()
{
    int x, y;
    long long result;
    cout << "Input: ";
    cin >> x >> y;
    result = LCM(x, y); // result�� LCM(num1, num2)���� ����, �� result�� LCM�Լ��� ���� ���� �ּҰ������ ����
    if (result == 0)
        return 0;
    cout << "LCM of " << x << " and " << y << " is " << result << endl;
    return 0;
}