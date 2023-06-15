#include <iostream>
#include <cmath>

using namespace std;

//������ �迭 space�� ��͸� �̿��� '$'�� ������ ��ġ�� ����� �Լ�
void Sierpinski(char** space, int n, int x, int y) {
	if (n == 1) {	//'$'�� �ﰢ���� �����.
		space[x][y] = '$';
		space[x + 1][y + 1] = '$';
		space[x + 1][y - 1] = '$';
		for (int i = 0; i < 5; i++)
			space[x + 2][y - 2 + i] = '$';
	}
	else {
		int d = static_cast<int>(3 * std::pow(2, n - 2));
		Sierpinski(space, n - 1, x, y);		//���� �ﰢ��
		Sierpinski(space, n - 1, x + d, y - d);		//���� �ﰢ��
		Sierpinski(space, n - 1, x + d, y + d);		//������ �ﰢ��
	}
	return;
}

int main() {
	unsigned char k;	//�Է°��� ������ ����
	cout << "--> ";
	cin >> k;
	int num = k - '0';	//int�� ��ȯ
	int col = static_cast<int>(3 * std::pow(2, num) - 1);	//������ �ִ� ����
	int row = static_cast<int>(3 * std::pow(2, num - 1));	//������ �ִ� ����

	//�ÿ����ɽ�Ű �ﰢ���� �׸� ������ �����Ҵ�
	char** space = new char* [row];	//�� ���� �Ҵ�
	for (int i = 0; i < row; i++) {	//�� ���� �Ҵ�
		space[i] = new char[col];
		for (int j = 0; j < col; j++) {	//���� ���ΰ� " "���� �ʱ�ȭ
			space[i][j] = ' ';
		}
	}

	Sierpinski(space, num, 0, col / 2);

	//���
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << space[i][j];
		}
		cout << endl;
	}

	//�޸� ����
	for (int i = 0; i < row; i++) {	//�� ���� ����
		delete[] space[i];
	}
	delete[] space;		//�� ���� ����
	return 0;
}