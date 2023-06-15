#include<iostream>
#include<cmath>

using namespace std;
void calculate(float a, float b, float c); // �Լ� ����

int main()
{
    float a, b, c; // ���������� �����

    cout << "a: ";
    cin >> a; // a �Է�

    cout << "b: ";
    cin >> b; // b �Է�

    cout << "c: ";
    cin >> c; // c �Է�

    if (a == 0) // a�� 0�̶�� ������������ �ƴϹǷ� �� ��� �� ����
    {
        cout << "Unexpected factor of a quadratic term" << endl;
        return 0;
    }
    calculate(a, b, c); // �Լ� ȣ��

    return 0;
}

void calculate(float a, float b, float c)
{
    float  x1, x2, x3, D; // x1, x2, x3�� ��, D�� �Ǻ���

    D = b * b - 4 * a * c; // �Ǻ���

    if (D > 0) // �Ǻ����� 0���� Ŭ ��
    {
        if (b > 0) // b�� ���� 0���� Ŭ ��
        {
            x1 = (-2 * c) / (b + sqrt(D)); // x1�� ��
            x2 = (-b - sqrt(D)) / (2 * a); // x2�� ��

            cout << "X1:" << x1 << "," << "X2:" << x2 << endl; // x1, x2 ���
        }
        else // �׿��� ���� ��
        {
            x1 = (-b + sqrt(D)) / (2 * a); // x1�� ��
            x2 = (-2 * c) / (b - sqrt(D)); // x2�� ��

            cout << "X1:" << x1 << "," << "X2:" << x2 << endl; // x1, x2 ���
        }
    }
    else if (D == 0) // �Ǻ����� 0�� ��
    {
        x3 = b / (-2.0 * a); // x3�� ��
        cout << "X1,X2:" << x3 << " (double root)"; // x3 ���
    }
    else if (D < 0) // �Ǻ����� 0���� ���� ��
    {
        cout << "The equation has no real number solutions."; // �Ǳ��� ���ٴ� �� ���
    }
}