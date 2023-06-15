#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int** arr = new int* [3]; // ����ڿ��� ���� ���� ������ �迭(���) �����Ҵ����� ����
    for (int i = 0; i < 3; i++)
        arr[i] = new int[3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];

    double** nar = new double* [3]; // ����� ���� ������ �迭(���) �����Ҵ����� ����
    for (int i = 0; i < 3; i++)
        nar[i] = new double[3];

    int det = arr[0][0] * (arr[1][1] * arr[2][2] - arr[1][2] * arr[2][1]) // determinant ���ϱ�(���Ŀ� ��½ÿ� det�� ������ ���)
        - arr[0][1] * (arr[1][0] * arr[2][2] - arr[1][2] * arr[2][0])
        + arr[0][2] * (arr[1][0] * arr[2][1] - arr[1][1] * arr[2][0]);

    if (det == 0) // determinant�� 0�̸� �и� 0�̵ż� ������� �������� ����
    {
        cout << "The inverse Matrix does not exist.";
        return 0;
    }

    // ���μ� ����� ���ϰ� �ڹٲٴ� ����. �ڵ带 ����ȭ�ϱ� ���� ���ϰ� �ٲٴ� ������ �ѹ��� ��� �����ߴ�.
    nar[0][0] = (arr[1][1] * arr[2][2] - arr[1][2] * arr[2][1]);
    nar[0][1] = -(arr[0][1] * arr[2][2] - arr[0][2] * arr[2][1]);
    nar[0][2] = (arr[0][1] * arr[1][2] - arr[0][2] * arr[1][1]);
    nar[1][0] = -(arr[1][0] * arr[2][2] - arr[1][2] * arr[2][0]);
    nar[1][1] = (arr[0][0] * arr[2][2] - arr[0][2] * arr[2][0]);
    nar[1][2] = -(arr[0][0] * arr[1][2] - arr[1][0] * arr[0][2]);
    nar[2][0] = (arr[1][0] * arr[2][1] - arr[2][0] * arr[1][1]);
    nar[2][1] = -(arr[0][0] * arr[2][1] - arr[2][0] * arr[0][1]);
    nar[2][2] = (arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1]);

    for (int i = 0; i < 3; i++) // ��ü���
    {
        for (int j = 0; j < 3; j++)
        {
            nar[i][j] /= det; // det�� �����ֱ�
            cout << nar[i][j] << '\t'; // ��� Ʋ�� ���߱� ���� '\t' ���
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) // delete ���ֱ�
        delete[] arr[i];
    delete[] arr;

    for (int i = 0; i < 3; i++) // delete
        delete[] nar[i];
    delete[] nar;
    return 0;
}