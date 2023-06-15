#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	char num[100];
	int baseInput, baseOutput;
	
	cout << "Input: ";
	cin >> num >> baseInput >> baseOutput;
	
	int demical = 0;
	/*10진수 정수로 저장하기*/
	switch (baseInput) {
	case 2: // 2 -> 10
		for (int i = 0; i < strlen(num); i++) {
			demical *= 2;
			demical += (num[i] - '0');
		}
		break;
	case 8: // 8 -> 10
		for (int i = 0; i < strlen(num); i++) {
			demical *= 8;
			demical += (num[i] - '0');
		}
		break;
	case 10: // 10 -> 10
		for (int i = 0; i < strlen(num); i++) {
			demical *= 10;
			demical += (num[i] - '0');
		}
		break;
	case 16: // 16 -> 10
		for (int i = 0; i < strlen(num); i++) {
			demical *= 16;
			/* 0 ~ 9 사이*/
			if ('0' <= num[i] && num[i] <= '9')
				demical += (num[i] - '0');
			/* A ~ F 사이*/
			else if ('A' <= num[i] && num[i] <= 'F')
				demical += (num[i] - 55); // 'A' 아스키코드가 65
			/* a ~ f 사이(소문자 입력시 예외처리)*/
			else
				demical += (num[i] - 87);
		}
		break;
	}

	/* 10진수를 원하는 진법으로 변환 (num 배열에 거꾸로 저장)*/
	int i = 0;
	switch (baseOutput) {
	case 2: // 10 -> 2
		for (i = 0; demical != 0; i++) {
			num[i] = demical % 2 + '0';
			demical /= 2;
		}
		num[i] = 0;
		break;

	case 8: // 10 -> 8
		for (i = 0; demical != 0; i++) {
			num[i] = demical % 8 + '0';
			demical /= 8;
		}
		num[i] = 0;
		break;

	case 10: // 10 -> 10
		for (i = 0; demical != 0; i++) {
			num[i] = demical % 10 + '0';
			demical /= 10;
		}
		num[i] = 0;
		break;

	case 16: // 10 -> 16
		for (i = 0; demical != 0; i++) {
			int mod = demical % 16;
			/* 나머지가 0 ~ 9 사이*/
			if (0 <= mod && mod <= 9)
				num[i] = mod + '0';
			/* 나머지가 10 ~ 15 사이*/
			else {
				num[i] = mod + 55; // 'A' 아스키코드가 65
			}
			demical /= 16;
		}
		num[i] = 0;
		break;
	}

	/* 수를 배열에 순서 거꾸로 대입했으므로 거꾸로 출력*/
	cout << "Output: ";
	for (int i = strlen(num) - 1; i >= 0; i--) {
		cout << num[i];
	}
	cout << endl;
}