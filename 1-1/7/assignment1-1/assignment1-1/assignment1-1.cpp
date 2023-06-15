#include<iostream>

char map[384][768];		//k=8 �� k ���� �ִ��� �� �����Ǵ� �ﰢ���� ���̴� 384    �غ��� ���� 767 + NULL�� �� ����=768

void put_dollar(int high, int y, int x);

int main()
{
	int k;
	int high;
	int i, j;
	std::cout << "input:";
	std::cin >> k;		//�Է¹ޱ�

	for (i = 0; i < 384; i++)
		for (j = 0; j < 767; j++)
			map[i][j] = ' ';		//map�� ���� �������� ä������

	high = 3;				//k=1 �϶� �ﰢ���� ����

	for (i = 1; i < k; i++)
		high *= 2;			//k>1 �϶� �ﰢ���� ����

	put_dollar(high, 0, high - 1);		// ��� �������� y=0,x=high-1

	for (i = 0; i < high; i++)		//���
	{
		for (j = 0; j < 2 * high; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << "\n";
	}
	return 0;
}

void put_dollar(int high, int y, int x)
{
	if (high == 3)		//����� ������ => �ﰢ���� �׸�
	{
		map[y][x] = '$';
		map[y + 1][x - 1] = '$';
		map[y + 1][x + 1] = '$';
		for (int i = 0; i < 5; i++)
			map[y + 2][x - 2 + i] = '$';
		return;
	}
	high /= 2;
	put_dollar(high, y, x);		//3��� �Ǵ� �ﰢ���� ����
	put_dollar(high, y + high, x - high);		//����
	put_dollar(high, y + high, x + high);		//������
}