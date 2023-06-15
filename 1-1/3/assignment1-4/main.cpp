#include <iostream>
using namespace std;

void    swap(double *a, double *b);
int     get_det(int arr[][3]); // �־��� ����� ��Ľ��� ��ȯ�ϴ� �Լ�
void    make_adj(int arr[][3], double adj[][3]);
// �־��� ����� ���� ����� ������ִ� �Լ�

int main()
{
    int arr[3][3];
    double adj[3][3]; // ������ ���� ���
    int det;

    cout << "Input: ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }
    det = get_det(arr);
    if (det == 0)
    {
        cout << "The inverse matrix does not exist" << endl;
        return (0);
        // ����� ����: (1 / (��Ľ�)) *(���� ���)
        // ��Ľ� ���� 0�̸� �и� 0�̹Ƿ� ����� ������� �� ����
    }
    make_adj(arr, adj); // �Է¹��� arr�� ��������� adj�� �Է�
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            adj[i][j] /= det;
    }// ���� ����� �� ���� ��Ľ� ������ ����(����� ����)
    cout << "Output: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    return (0);
}

void	swap(double *a, double *b)
{
    double		temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int get_det(int arr[][3])
{
    int a, b;

    a = 0, b = 0;
    for (int i = 0; i < 3; i++)
        a += arr[0][i] * arr[1][(i + 1) % 3] * arr[2][(i + 2) % 3];
    for (int i = 0; i < 3; i++)
        b += arr[0][i] * arr[1][(i + 2) % 3] * arr[2][(i + 1) % 3];
    // 3 X 3 ��Ľ��� ����: (a_11*a_22*a_33 + a_12*a_23*a_31 + a_13*a_21*a_32)
    //                      - (a_11*a_23*a_32 + a_12*a_21*a_33 + a_13*a_22*a_31)
    // �ε����� �׳� 1�� ������Ű�� �ִ� �ε���(2)�� �Ѿ����, �̸� 3���� ������ �����ϸ�
    // 0 ~ 2�� ���� �ݺ���
    return (a - b);
}

void    make_adj(int arr[][3], double adj[][3])
{
    // ���� ��� == ���μ� ����� ��ġ ���
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            adj[j][i] = (arr[(i + 1) % 3][(j + 1) % 3]
                * arr[(i + 2) % 3][(j + 2) % 3]
                - arr[(i + 2) % 3][(j + 1) % 3]
                * arr[(i + 1) % 3][(j + 2) % 3]);
        }
        // ���μ� ����� ���� �̿�
        // adj[i][j]�� �ƴ� [j][i]�� �ۼ��� ������
        // ���μ� ��ĸ� ����� ���ÿ� ��ġ����� �����ϱ� ����
    }
}