#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "oopstd.h"
#include<cstdlib>
#include<string.h>
using namespace std;

//������Ͽ� ����� �Լ���� oopstd.h�� ���� ������ �Լ����� ��
int main()
{
	//char�� �� int�� �迭 ����
	char str1[] = "123.45A56df";
	char str2[] = "123.45A56dd";
	char str3[100];
	char str4[100];
	char str5[100];
	char str6[100];
	int str_int1[] = { 1,2,3,4,5,6,7,8,9,0 };

	//memset ��
	cout << "memset" << endl;
	cout << memset(str_int1, 0, 3*sizeof(int)) << endl;	//str_int1�� �ּҰ� ��� �� 3��° �迭ĭ���� 0���� �ʱ�ȭ
	//�迭 ���
	for (int i = 0; i < 10; i++)
		cout << str_int1[i];
	cout << endl;
	cout << "oopstd::memset" << endl;
	cout << oopstd::memset(str_int1, 0, 3 * sizeof(int)) << endl;	//str_int1�� �ּҰ� ��� �� 3��° �迭ĭ���� 0���� �ʱ�ȭ
	//�迭 ���
	for (int i = 0; i < 10; i++)
		cout << str_int1[i];
	cout << endl << endl;

	//memcpy ��
	cout << "memcpy" << endl;
	cout << memcpy(str5, str1, strlen(str1) + 1) << endl;	//str5�� �ּҰ� ��� �� str1�� �޸𸮸� str5�� ����
	cout << str5 << endl;	//str5 ���
	cout << "oopstd::memcpy" << endl;
	cout << oopstd::memcpy(str5, str1, strlen(str1) + 1) << endl;	//str5�� �ּҰ� ��� �� str1�� �޸𸮸� str5�� ����
	cout << str5 << endl;	//str5 ���
	cout << endl;

	//strcmp ��
	cout << "strcmp" << endl;
	cout << strcmp(str1, str2) << endl;		//str1�� str2�� �� ���� ������ 0 �ٸ��� str1�� ũ�� 1 str2�� ũ�� -1 ���
	cout << "oopstd::strcmp" << endl;
	cout << oopstd::strcmp(str1, str2) << endl << endl;	//str1�� str2�� �� ���� ������ 0 �ٸ��� str1�� ũ�� 1 str2�� ũ�� -1 ���

	//strncmp ��
	cout << "strncmp" << endl;
	cout << strncmp(str1, str2, 4) << endl;		//str1�� str2�� �� 4���� �� �� ������ 0 �ٸ��� str1�� ũ�� 1 str2�� ũ�� -1 ���
	cout << "oopstd::strncmp" << endl;
	cout << oopstd::strncmp(str1, str2, 4) << endl << endl;		//str1�� str2�� �� 4���� �� �� ������ 0 �ٸ��� str1�� ũ�� 1 str2�� ũ�� -1 ���

	//strcpy ��
	cout << "strcpy" << endl;
	cout << strcpy(str3, str1) << endl;			//str1�� ����� ���� str3�� ���� �� str3 ���
	cout << "oopstd::strcpy" << endl;
	cout << oopstd::strcpy(str4, str1) << endl << endl;	//str1�� ����� ���� str4�� ���� �� str4 ���

	//strncpy ��
	cout << "strncpy" << endl;
	cout << strncpy(str5, str2, 11) << endl;	//str2�� ����� ���� 11���� str5�� ���� �� str5 ���
	cout << "oopstd::strncpy" << endl;
	cout << oopstd::strncpy(str5, str2, 11) << endl << endl;	//str2�� ����� ���� 11���� str5�� ���� �� str5 ���

	//strlen ��
	cout << "strlen" << endl;
	cout << strlen(str1) << endl;		//str1�� ���� ���� ���
	cout << "oopstd::strlen" << endl;
	cout << oopstd::strlen(str1) << endl << endl;	//str1�� ���� ���� ���

	//atoi ��
	cout << "atoi" << endl;
	cout << atoi(str1) << endl;		//str1�� ����� ���� �� ���
	cout << "oopstd::atoi" << endl;
	cout << oopstd::atoi(str1) << endl << endl;		//str1�� ����� ���� �� ���

	//atof ��
	cout << "atof" << endl;
	cout << atof(str2) << endl;		//str2�� ����� �Ǽ� �� ���
	cout << "oopstd::atof" << endl;
	cout << oopstd::atof(str2) << endl << endl;		//str2�� ����� �Ǽ� �� ���

	return 0;
}
