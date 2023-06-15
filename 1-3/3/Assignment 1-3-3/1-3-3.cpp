#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
void DecToBin(unsigned int n) 
{
	// 10진수를 2진수로 바꾸는 재귀함수
	if (n / 2 != 0) {
		DecToBin(n / 2);
	}
	cout << n % 2;
}
void DecToOct(unsigned int n)
{
	// 10진수를 8진수로 바꾸는 재귀함수
	if (n / 8 != 0) {
		DecToOct(n / 8);
	}
	cout << n % 8;
}
void DecToHexa(unsigned int n)
{
	// 10진수를 16진수로 바꾸는 함수
	char h[100];
	int i = 0;
	// 수를 16으로 나누어 배열에 저장하는 과정을 반복
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
	// 바꾼 값을 출력
	for (int j = i - 1; j >= 0; j--)
		cout << h[j];
}
int BinToDec(unsigned int n)
{
	// 2진수를 10진수로 변환하는 함수
	int d = 0, i = 0;
	// 10으로 나눈 나머지에 2를 곱해서 10진수 변환
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
	// 8진수를 10진수로 변환하는 함수
	int d = 0, i = 0;
	// 10으로 나눈 나머지에 8을 곱해서 10진수 변환
	while (n != 0)
	{
		d += (n % 10) * pow(8, i);
		++i;
		n /= 10;
	}
	return d;
}
int HexToDec(char h[], int len) {
	// 16진수를 10진수로 변환하는 함수
	int d = 0, base = 1;
	// 각 배열을 16진수로 되돌림
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

	// 입력받은 값이 2진수인 경우
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
	// 입력받은 값이 8진수인 경우
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
	// 입력받은 값이 10진수인 경우
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
	// 입력받은 값이 16진수인 경우
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