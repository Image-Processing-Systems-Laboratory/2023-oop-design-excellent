#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
void DecToBin(unsigned int n) 
{
	// 10������ 2������ �ٲٴ� ����Լ�
	if (n / 2 != 0) {
		DecToBin(n / 2);
	}
	cout << n % 2;
}
void DecToOct(unsigned int n)
{
	// 10������ 8������ �ٲٴ� ����Լ�
	if (n / 8 != 0) {
		DecToOct(n / 8);
	}
	cout << n % 8;
}
void DecToHexa(unsigned int n)
{
	// 10������ 16������ �ٲٴ� �Լ�
	char h[100];
	int i = 0;
	// ���� 16���� ������ �迭�� �����ϴ� ������ �ݺ�
	while (n != 0)
	{
		int temp = 0;
		temp = n % 16;
		if (temp < 10)
		{
			h[i] = temp + 48;
			i++;
		}
		else
		{
			h[i] = temp + 55;
			i++;
		}
		n = n / 16;
	}
	// �ٲ� ���� ���
	for (int j = i - 1; j >= 0; j--)
		cout << h[j];
}
int BinToDec(unsigned int n)
{
	// 2������ 10������ ��ȯ�ϴ� �Լ�
	int d = 0, i = 0;
	// 10���� ���� �������� 2�� ���ؼ� 10���� ��ȯ
	while (n != 0)
	{
		d += (n % 10) * pow(2, i);
		++i;
		n /= 10;
	}
	return d;
}
int OctToDec(unsigned int n)
{
	// 8������ 10������ ��ȯ�ϴ� �Լ�
	int d = 0, i = 0;
	// 10���� ���� �������� 8�� ���ؼ� 10���� ��ȯ
	while (n != 0)
	{
		d += (n % 10) * pow(8, i);
		++i;
		n /= 10;
	}
	return d;
}
int HexToDec(char h[], int len) {
	// 16������ 10������ ��ȯ�ϴ� �Լ�
	int d = 0, base = 1;
	// �� �迭�� 16������ �ǵ���
	for (int i = len - 1; i >= 0; i--) {
		if (h[i] >= '0' && h[i] <= '9')
			{
				d += (h[i] - 48) * base;
				base *= 16;
			}
			else if (h[i] >= 'A' && h[i] <= 'F')
			{
				d += (h[i] - 55) * base;
				base *= 16;
			}
		}
	return d;
}


int main() {
	int before, after;
	char cnum[100];
	cin >> cnum >> before >> after;
	int number;

	// �Է¹��� ���� 2������ ���
	if (before == 2) {
		number = atoi(cnum);
		if (after == 8) {
			DecToOct(BinToDec(number));
		}
		else if (after == 10) {
			cout << BinToDec(number);
		}
		else if (after == 16) {
			DecToHexa(BinToDec(number));
		}
	}
	// �Է¹��� ���� 8������ ���
	else if (before == 8) {
		number = atoi(cnum);
		if (after == 2) {
			DecToBin(OctToDec(number));
		}
		else if (after == 10) {
			cout << OctToDec(number);
		}
		else if (after == 16) {
			DecToHexa(OctToDec(number));
		}
	}
	// �Է¹��� ���� 10������ ���
	else if (before == 10) {
		number = atoi(cnum);
		if (after == 2) {
			DecToBin(number);
			return 0;
		}
		else if (after == 8) {
			DecToOct(number);
			return 0;
		}
		else if (after == 16) {
			DecToHexa(number);
		}
	}
	// �Է¹��� ���� 16������ ���
	else if (before == 16) {

		if (after == 2) {
			DecToBin((HexToDec(cnum, strlen(cnum))));
		}
		else if (after == 8) {
			DecToOct((HexToDec(cnum, strlen(cnum))));
		}
		else if (after == 10) {
			cout << HexToDec(cnum, strlen(cnum));
		}
	}
	return 0;
}