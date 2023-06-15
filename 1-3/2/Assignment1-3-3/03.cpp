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
	/*10���� ������ �����ϱ�*/
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
			/* 0 ~ 9 ����*/
			if ('0' <= num[i] && num[i] <= '9')
				demical += (num[i] - '0');
			/* A ~ F ����*/
			else if ('A' <= num[i] && num[i] <= 'F')
				demical += (num[i] - 55); // 'A' �ƽ�Ű�ڵ尡 65
			/* a ~ f ����(�ҹ��� �Է½� ����ó��)*/
			else
				demical += (num[i] - 87);
		}
		break;
	}

	/* 10������ ���ϴ� �������� ��ȯ (num �迭�� �Ųٷ� ����)*/
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
			/* �������� 0 ~ 9 ����*/
			if (0 <= mod && mod <= 9)
				num[i] = mod + '0';
			/* �������� 10 ~ 15 ����*/
			else {
				num[i] = mod + 55; // 'A' �ƽ�Ű�ڵ尡 65
			}
			demical /= 16;
		}
		num[i] = 0;
		break;
	}

	/* ���� �迭�� ���� �Ųٷ� ���������Ƿ� �Ųٷ� ���*/
	cout << "Output: ";
	for (int i = strlen(num) - 1; i >= 0; i--) {
		cout << num[i];
	}
	cout << endl;
}