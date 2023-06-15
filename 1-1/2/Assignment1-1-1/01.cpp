#include<iostream>
#include<cmath>
using namespace std;

/*input�� �ִ��� ���� ������ ũ��, ��� ��� 0���� �ʱ�ȭ*/
char matrix[384][767] = { 0 };

void makeTri(int N, int x, int y);
void drawTri(int N);

int main()
{
	unsigned char k;
	int N;

	cout << "Input k: ";
	cin >> k;
	k -= 48; // ���� 0�� ���� 0�� �ƽ�Ű�� ���̰� 48

	N = pow(2, k - 1);
	
	makeTri(N, 0, 0);
	drawTri(N);

	return 0;
}

/*matrix�� �ÿ����ɽ�Ű �ﰢ�� �����. x, y�� 0���� ����*/
void makeTri(int N, int x, int y) {
	if (N == 1)
	{
		/*1��*/
		matrix[x][y + 2] = '$';
		/*2��*/
		matrix[x + 1][y + 1] = '$';
		matrix[x + 1][y + 3] = '$';
		/*3��*/
		matrix[x + 2][y] = '$';
		matrix[x + 2][y + 1] = '$';
		matrix[x + 2][y + 2] = '$';
		matrix[x + 2][y + 3] = '$';
		matrix[x + 2][y + 4] = '$';

		return;
	}
	makeTri(N / 2, x, y + 3 * N / 2); // �����ﰢ��
	makeTri(N / 2, x + 3 * N / 2, y); // �����ϴܻﰢ��
	makeTri(N / 2, x + 3 * N / 2, y + 6 * N / 2); // �����ϴܻﰢ��
}

/*�ÿ����ɽ�Ű �ﰢ�� ���*/
void drawTri(int N) {
	for (int i = 0; i < N * 3; i++) // �� ���� 3N
	{
		for (int j = 0; j < 6 * N - 1; j++) // �� �ʺ� 6N - 1
		{
			if (matrix[i][j] == 0) // $���ڰ� �������� ���� �κ��� ���� ���
				cout << ' ';
			else
				cout << matrix[i][j];
		}
		cout << endl;
	}
}