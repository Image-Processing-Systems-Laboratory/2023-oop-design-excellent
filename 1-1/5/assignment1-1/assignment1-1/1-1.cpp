#include <iostream> //iostream ����
#include <cmath> //cmath ����
using namespace std; //namespace std ����
char triangle[384][768]; //�ﰢ�� ����� ���� �迭 ����(���� 2X368ĭ, ���� 368ĭ)
void basictriangle(int y, int x); //���� ���� �ﰢ���� ���� �Լ� ����
void getposition(int y, int x, int size); //�˸��� �������� �°� ���� ����Լ� ����
void printarr(int size); //�ﰢ���� ���� �迭 ��� �Լ� ����
void resetarr(int size); //�ﰢ���� ���� �迭 �ʱ�ȭ �Լ� ����

int main() //main�Լ��� ����
{
	unsigned char k; //unsigned char�� ���� ����
	cout << "Input: ";
	cin >> k; //�ȳ��� ��� �� k �Է¹ޱ�
	int K = k - 48; //������ ���� unsigned char�� k������ 48�� �� ������ K�� ����
	int n = pow(2,K - 1); //N�� ���� pow�Լ��� �̿��Ͽ� ���ϱ�
	resetarr(3 * n); //3n�� ���� resetarr�Լ��� �����Ͽ� �迭�� ���鹮�� �ֱ�
	
	getposition(0, 3 * n, 3 * n); //3n ���̸�ŭ�� ���� ū �ﰢ���� �������� ���� ������ �ɰ��� �Լ� ����
	
	printarr(3 * n); //�迭�� ����� ���� ����Ͽ� ���ϴ� ����� �ﰢ�� �����

	return 0; //0�� ��ȯ
}

void basictriangle(int y, int x) //���� ���� ������ �ﰢ���� ����� �Լ�
{
	triangle[y][x] = '$';

	triangle[y + 1][x + 1] = '$';
	triangle[y + 1][x - 1] = '$';

	triangle[y + 2][x - 2] = '$';
	triangle[y + 2][x - 1] = '$';
	triangle[y + 2][x] = '$';
	triangle[y + 2][x + 1] = '$';
	triangle[y + 2][x + 2] = '$';
	
	return;
} //basictriangle �Լ� ����

void getposition(int y, int x, int size) //���� ū �ﰢ���� �������� ���� ���� ������ �ﰢ������ �ɰ��� �Լ�
{
	if (size == 3) //���� ���� ������ �Ǿ��� ��
	{
		basictriangle(y, x); //basictriangle�� ���
		return;
	}
	getposition(y, x, size / 2); //�� �κ����� �ɰ��� �� �� �κ�
	getposition(y + size / 2, x - size / 2, size / 2); //�� �κ����� �ɰ��� �� �Ʒ��� ���� �κ�
	getposition(y + size / 2, x + size / 2, size / 2); //�� �κ����� �ɰ��� �� �Ʒ��� ������ �κ�
} //getposition �Լ� ����

void printarr(int size) //�迭�� �̿��� �ﰢ���� ����ϱ� ���� �Լ�
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size*2; j++)
		{
			cout << triangle[i][j];
		}
		cout << endl;
	} //������ ����(���δ� size��ŭ, ���δ� 2size��ŭ)�� �°� �迭�� ����Ѵ�.
	return;
} //printarr�Լ� ����

void resetarr(int size) //�迭 ��ü�� ������ �־��ִ� �Լ�
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size*2; j++)
		{
			triangle[i][j] = ' ';
		}
	} //������ ����(���δ� size��ŭ, ���δ� 2size��ŭ)�� �°� ������ �־��ش�. �ʱ�ȭ ����
	return;
} //resetarr�Լ� ����

