#include <iostream> 
#include <cmath> 
#define PI 3.141592 // PI ���� ����� ����

using namespace std;

int main()
{
    double theta; // ����ڷκ��� �Է¹��� ���� ��
    double matrix3x1[3] = { 0 }; // 3x1 ����� ǥ���ϱ� ���� �迭

    cout << "Degrees: ";
    cin >> theta;

    cout << "Coordinate: ";
    cin >> matrix3x1[0] >> matrix3x1[1] >> matrix3x1[2];

    double radian = theta * PI / 180.0; // �Է¹��� ���� ���� �������� ��ȯ
    double cosine = cos(radian); // ���� ���� �ﰢ�Լ� ����� ���� cosine ������ ��ȯ
    double sine = sin(radian); // ���� ���� �ﰢ�Լ� ����� ���� sine ������ ��ȯ
    double matrix3x3[3][3] = // 3x3 ���
    {
     {-cosine , sine , 0},
     {sine , cosine , 0},
     {0, 0, 0}
    };

    // ������ ��� ���� ����� ���Ұ����� 10000�� ���� �� �ݿø��Ͽ� �ٽ� 10000���� ������
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix3x3[i][j] *= 10000;
            matrix3x3[i][j] = round(matrix3x3[i][j]);
            matrix3x3[i][j] /= 10000;
        }
    }

    double result[3] = { 0, 0, 0 }; // ������� ������ 3x1 ����� ǥ���ϱ� ���� �迭

    for (int i = 0; i < 3; i++)
    {
        double temp = 0;
        for (int j = 0; j < 3; j++)
        {
            temp += matrix3x3[i][j] * matrix3x1[j];
        }
        result[i] = temp;
    }

    // ����� ���
    cout << "Result: " << result[0] << " " << result[1] << " " << result[2] << endl;

    return 0; // ���α׷� ����
}