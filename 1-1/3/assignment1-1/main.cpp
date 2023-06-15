#include <iostream>
#include <cmath>
using namespace std;

void	make_sire(char arr[][3 * 256 - 1], unsigned char k, int x, int y);
// �ÿ����ɽ�Ű �ﰢ���� ����� ����Լ�, x, y�� �ﰢ�� �׸��⸦ ������ ��ǥ

int main()
{
	char arr[3 * 128][3 * 256 - 1] = { 0, };
	// �ÿ����ɽ�Ű �ﰢ���� �׷� ���� ������ �迭
	// 1 <= k <= 8 �̹Ƿ� �ﰢ���� �ִ� ũ��[3 * 2 ^ (k - 1), 3 * 2 ^ k - 1]��ŭ �Ҵ�
	unsigned char k;

	cout << "Input: ";
	// ǥ�� ���
	cin >> k;
	// ǥ�� �Է����� ���� unsigned char ���� k�� �������
	make_sire(arr, k, 0, 3 * pow(2, k - '1') - 1);
	// �ﰢ���� ��� ������ ��ǥ ����(ù ��° ��, 3 * 2 ^ (k - 1) ��° ��, �ﰢ���� ��� �κ�)
	for (int i = 0; i < 3 * pow(2, k - '1'); i++)
	{
		for (int j = 0; j < 3 * pow(2, k - '0') - 1; j++)
		{
			if (arr[i][j] == '$')
				cout << arr[i][j];
			else
				cout << ' ';
			// ������ �迭�� $�� ���� ������ �״�� ����ϰ�, �ƴϸ� ���� ���
		}
		cout << endl; // ���� ���
	}
	return (0);
}

void	make_sire(char arr[][3 * 256 - 1], unsigned char k, int x, int y)
{
	if (k == '1')
	{
		arr[x][y] = '$';
		arr[x + 1][y - 1] = '$';
		arr[x + 1][y + 1] = '$';
		for (int i = 0; i < 5; i++)
			arr[x + 2][y - 2 + i] = '$';
		// ���� ���� �ﰢ���� �� �� ���������� ��
		return;
	}
	// k != 1 �̸� k - 1�� �ﰢ���� 3��(���� �ϳ�, �Ʒ� 2��) �׷��� ��
	make_sire(arr, k - 1, x, y); // �� �� �ﰢ��
	make_sire(arr, k - 1, x + 3 * pow(2, k - '2'), y - 3 * pow(2, k - '2')); // �Ʒ� ���� �ﰢ��
	make_sire(arr, k - 1, x + 3 * pow(2, k - '2'), y + 3 * pow(2, k - '2')); // �Ʒ� ������ �ﰢ��
}