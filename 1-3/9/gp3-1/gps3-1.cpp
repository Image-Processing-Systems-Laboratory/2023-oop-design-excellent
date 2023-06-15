#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // float�� double ��� ��밡���ѵ�, double�� float���� �ι��� �������� �����Ƿ� ������ �� ���� double�� ���ߴ�
    double d; // ���Ŀ� ���ÿ� �������·� ����Ϸ��� double������ ��������� �Ѵ�
    const double PI = M_PI;
    cout << "Degrees: ";
    cin >> d;
    while (d >= 360) // 360���� �Ѿ�� ���� �ణ�� ������ �߻��ϰ� �Ǵµ�, �̸� �ذ��ϱ� ���� while���� ���� �׻� ������ 360�� �Ʒ��� ���ش�.
    {
        d -= 360;
    }
    double Mat[2][2]; // ���� ��� ��ü�� 3x3 ���������, 3��� 3���� ���� ��� 0�̹Ƿ�, �����ص� ��� ������� ������ ���� ������ ���� 2x2�� ���־���
    Mat[0][0] = -1 * cos((d / 180) * PI); // cmath ���� �ִ� �ﰢ�Լ� ��� ����� �̿��� ������ �������·� �����Ͽ� ������ش�
    Mat[0][1] = sin((d / 180) * PI);
    Mat[1][0] = Mat[0][1];
    Mat[1][1] = -1 * Mat[0][0];
    double co[3];
    cout << "Coordinate: ";
    for (int i = 0; i < 3; i++)
        cin >> co[i];
    double out[3];
    for (int i = 0; i < 2; i++)
        out[i] = (Mat[i][0] * co[0]) + (Mat[i][1] * co[1]); // ��� ���� ������ ���� �⿪�� ���·� �������� ���ش�
    out[2] = 0.0; // ������ ���ߵ� 3��� 3���� ��� ������ 0���� �����̹Ƿ�, ��갪�� 0�̱� ������ output���� 3��° ���� �ݵ�� 0�� ���´�.
    for (int i = 0; i < 3; i++)
        cout << out[i] << " ";
    cout << endl;
    return 0;
}