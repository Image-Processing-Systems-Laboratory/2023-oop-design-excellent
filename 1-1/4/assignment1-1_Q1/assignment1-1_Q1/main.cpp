#include <iostream>
using namespace std;

void draw(int row, int col);
void draw_triangle(int len, int row, int col);

char arr[384][767]; // k�� 8�϶� �ִ� �� 384, �� 767

int main()
{
    unsigned char k; // �Է°� ���� ����
    int N, num, row, col, i, j;

    cin >> k;

    num = k - 48; // �Է¹��� ������ ASKII �ڵ�� ���ڷ� �����
    N = pow(2, num - 1); 
    row = 3 * N;
    col = 2 * row - 1;

    // ��� ����ŭ �ݺ��� ������ �ش� ��ġ�� ���� �߰�
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            arr[i][j] = ' ';

    // arr �迭�� ��ǥó�� ��� ����Լ� ù ȣ��
    // ù��° �Ű������� ���� �״�� �����Ͽ� �ݺ�Ƚ�� ���
    // �ι�° �Ű������� �ﰢ���� ��ܺ��� �׸� ���̹Ƿ� 0 ����
    // ����° �Ű������� �ﰢ���� �¿� �������� �̵��ϸ鼭 ����� col�� row - 1�� ����
    draw_triangle(row, 0 ,row - 1);

    // ���� �ݺ������� ���߹迭 ���
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << arr[i][j];
        cout << endl;
    }

    return 0;
}


// �ﰢ�� ������� ��ȣ�� ��� �Լ�
void draw(int row, int col)
{
    // ù��° �� ���
    arr[row][col] = '$';

    // �ι�° �� �� ��
    arr[row + 1][col - 1] = '$';
    arr[row + 1][col + 1] = '$';

    // �������� 5��
    for (int i = 0; i < 5; i++)
        arr[row + 2][col - 2 + i] = '$';
}

// ��ǥ������ �����Ͽ� �ﰢ���� �׸��� ����Լ�
void draw_triangle(int len, int row, int col)
{
    // len�� 3�̸� draw �Լ��� ���� �ﰢ��������� ��ȣ ���
    if (len == 3)
    {
        draw(row, col);
        return;
    }

    // ����Լ� ���Ǻ�
    draw_triangle(len / 2, row, col); // len�� 2�� ������ ��, ���� �Բ� �Ű������� ����

    // len�� 2�� ������ �࿡ ���� ���� ���� ������ �Բ� �Ű������� ����
    // �ÿ����ɽ�Ű �ﰢ���� ���ʺκ�
    draw_triangle(len / 2, row + len / 2, col - len / 2);

    // len�� 2�� ������ �࿡ ���� ���� ���� ���� ���� �Բ� �Ű������� ����
    // �ÿ����ɽ�Ű �ﰢ���� ������ �κ�
    draw_triangle(len / 2, row + len / 2, col + len / 2);

}