#include <iostream>
#include <cmath>

using namespace std;

const int MAX_HEIGHT = 384; // ���� ��� ����
const int MAX_BASE = 767; // ���� ��� ����

char coordinate[MAX_HEIGHT][MAX_BASE]; // 2���� �迭�� ����

void triangle(int height, int x, int y); // �ﰢ���� �׸��� �Լ�

int main(void)
{

    int height, base; // ���� ����(height�� ����, base�� �غ�)
    unsigned char k; // ���� ����(k�� �Է¹޴� ��)
    cout << "Input: "; // �Է��� ����
    cin >> k;
    k = k - 48; // �������� ���������� ��ȯ

    height = 3 * pow(2, (k - 1)); // ���̸� ���
    base = 3 * pow(2, k) - 1; // �غ��� ���

    for (int i = 0; i < height; i++) // 2���� �迭�� �������� �ʱ�ȭ
    {
        for (int j = 0; j < base; j++)
        {
            coordinate[i][j] = ' ';
        }
    }

    triangle(height - 1, 0, height); // �ﰢ���� �׸�

    for (int i = 0; i < height; i++) // �ﰢ���� ���
    {
        for (int j = 0; j < base; j++)
        {
            cout << coordinate[i][j];
        }
        cout << endl;
    }

    return 0;
}

void triangle(int x, int y, int height) // �ﰢ���� �׸��� �Լ�
{

    if (height == 3) // ���̰� 3�� ��
    {
        coordinate[y][x] = '$'; //�� ���� ���� ����
        coordinate[y + 1][x - 1] = '$'; // �� ĭ �������� �������� �� ĭ ����
        coordinate[y + 1][x + 1] = '$'; // �� ĭ �������� ���������� �� ĭ ����
        coordinate[y + 2][x - 2] = '$'; // �� ĭ �������� ���ʿ��� �� ��° ĭ ����
        coordinate[y + 2][x - 1] = '$'; // �� ĭ �������� ���ʿ��� ù ��° ĭ ����
        coordinate[y + 2][x] = '$'; // �� ĭ �������� ��� ����
        coordinate[y + 2][x + 1] = '$'; // �� ĭ �������� �����ʿ��� ù ��° ĭ ����
        coordinate[y + 2][x + 2] = '$'; // �� ĭ �������� �����ʿ��� �� ��° ĭ ����

        return; // �Լ� ����
    }

    triangle(x, y, height / 2); // ���� �ﰢ���� �׸�
    triangle(x - (height / 2), y + height / 2, height / 2); // ���� �ﰢ���� �׸�
    triangle(x + (height / 2), y + height / 2, height / 2); // ������ �ﰢ���� �׸�
}
