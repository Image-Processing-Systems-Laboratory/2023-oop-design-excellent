#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "oopstd.h"

using namespace std;

struct {
	char name[70];
	int age;
}person, person_copy, person2, person_copy2; //��� ���ø� ���� ����ü ����

int main()
{	
	cout << "Memset Function" << endl; //Memset �Լ� ��
	char str1[] = "I can make the memset Function myself!"; //���ڿ� �ʱ�ȭ
	char str2[] = "I can make the memset Function myself!";
	cout << "Original String: " << str1 << endl; //���� ���ڿ� ���
	memset(str1, '-', 6); //���ڿ� �� 6�ڸ��� '-' �ֱ�
	cout << "Using Memset: " << str1 << endl;
	oopstd::mymemset(str2, '-', 6); //�����ϰ� �� 6�ڸ��� '-' �ֱ�
	cout << "Using My Memset: " << str2 << endl;
	

	cout << endl<<"Memcpy Function" << endl; //Memcpy �Լ� ��
	char myname[] = "Lee Jong Hyeok";
	memcpy(person.name, myname, strlen(myname)+1); //person.name�� myname�� ������ ����
	person.age = 23; //person.age�� 23���� ����
	memcpy(&person_copy, &person, sizeof(person)); //person�� �ִ� �����͸� person_copy�� ����
	printf("person_copy: %s, %d", person_copy.name, person_copy.age); //person_copy�� ��ҵ� ���
	cout << endl;
	char myname2[] = "Iron Man"; 
	oopstd::mymemcpy(person2.name, myname2, strlen(myname2)+1); //mymemcpy�� �̿��� person2.name�� myname2 ������ ����
	person2.age = 50; //person2.age�� 50���� ����
	oopstd::mymemcpy(&person_copy2, &person2, sizeof(person2)); //mymemcpy�� �̿��� person2�� �����͸� person_copy2�� ����
	printf("person_copy2: %s, %d", person_copy2.name, person_copy2.age); //����� ��ҵ� ���
	
	
	cout << endl << endl<<"Strcmp Function" << endl; //strcmp �Լ� ��
	char key[] = "kwangwoon"; //��: kwangwoon
	char buffer[30]; //���� �Է¹��� ���ڿ�
	cout << "<Quiz Using strcmp function>" << endl;
	do {
		cout << "Guess my university!: ";
		cin >> buffer;
	} while (strcmp(key, buffer) != 0); //key�� buffer�� ���� ���� ������ �� �ݺ�
	cout << "Correct answer!"<<endl;
	
	char key1[] = "computer"; //��: computer
	char buffer1[30]; //���� �Է¹��� ���ڿ�
	cout << endl << "<Quiz Using my strcmp function>" << endl;
	do {
		cout << "Guess my major!: ";
		cin >> buffer1;
	} while (oopstd::mystrcmp(key1, buffer1) != 0); //mystrcmp�� ����� �� ���ڿ��� ������ ��
	cout << "Correct answer!" << endl;
	

	cout << endl << "Strncmp Function" << endl; //strncmp �Լ� ��
	char str[][5] = { "1234","1278","1298","3456","7891" }; //���� ���ڵ�
	cout << "Found Number start with '12'"<<endl;
	for (int i = 0; i < 5; i++) //���� strncmp �Լ� ���
	{
		if (strncmp(str[i], "12XX", 2) == 0) //���� �� ���ڸ��� �����ϸ�
			cout << "Found: " << str[i] << endl; //�� ���ڿ� ��ü�� ���
	}
	cout << "Found Number start with '12' by using mystrncmp" << endl;
	for (int i = 0; i < 5; i++) //mystrncmp �Լ� ���
	{
		if (oopstd::mystrncmp(str[i], "12XX", 2) == 0) //���� �� ���ڸ��� �����ϸ�
			cout << "Found: " << str[i] << endl; //�� ���ڿ� ��ü�� ���
	}

	
	
	cout << endl << "Strcpy Function" << endl; //strcpy �Լ� ��
	char original[] = "Copy this Sentence."; //���� ����
	char char1[50];
	char char2[50]; //���縦 ���� ���ڿ���
	strcpy(char1, original); //char1�� original ����
	strcpy(char2, "I can copy like this."); //char2�� �ش� ���ڿ� ����
	cout << "Original: " << original << endl << "Copied from Original: " << char1 << endl << "Copied from Sentence: " << char2 << endl;
	char original2[] = "Mystrcpy Function is good!"; //���� ���� 2
	oopstd::mystrcpy(char1, original2); //mystrcpy�� ����Ͽ� original2�� char1�� ����
	oopstd::mystrcpy(char2, "Wow I can copy like this!"); //mystrcpy�� �̿��Ͽ� �ش� ���ڿ��� char2�� ����
	cout << "Original: " << original2 << endl << "Copied from Original: " << char1 << endl << "Copied from Sentence: " << char2 << endl;
	

	
	cout << endl << "Strncpy Function" << endl; //strncpy �Լ� ��
	char original3[] = "Copy this sentence,too"; //���� ����
	char char3[50];
	char char4[50]; //���縦 ���� ���ڿ���
	char original4[] = "This sentence copied by using Mystrncpy Function"; //���� ���� 2
	strncpy(char3, original3, sizeof(char3)); //char3�� original3�� ������ ����
	strncpy(char4, original3, 4); //char4�� original3�� 4���� ����
	char4[4] = '\0'; //������ �� ���� �߰�
	cout << original3 << endl << char3 << endl << char4 << endl; //��� ���
	oopstd::mystrncpy(char3, original4, sizeof(char3)); //mystrncpy�� �̿��ؼ� char3�� original4�� ������ ����
	oopstd::mystrncpy(char4, original4, 4); //mystrncpy�� �̿��ؼ� char3�� original4�� 4���� ����
	char4[4] = '\0'; //������ �� ���� �߰�
	cout << original4 << endl << char3 << endl << char4 << endl; //��� ���

	
	cout << endl << "Strlen Function" << endl; //strlen �Լ� ��
	char lengthinput[256];
	cout << "Enter the sentence: ";
	gets_s(lengthinput, sizeof(lengthinput));
	cout << "The sentence entered is " << (unsigned)strlen(lengthinput) << " characters long." << endl;
	cout << "Mystrlen Function" << endl;
	cout << "The sentence entered is " << (unsigned)oopstd::mystrlen(lengthinput) << " characters long."<<endl;
	

	cout << endl << "Atoi Function" << endl; //atoi �Լ� ��
	int result; //������� ���� ����
	char number[256]; //�Է¹��� ���ڿ� ����
	char number2[256]; //�Է¹��� ���ڿ� ����
	cout << "Enter the number: ";
	fgets(number, 256, stdin); //���ڿ� �Է¹ޱ�
	result = atoi(number); //���ڿ��� atoi�� �ÿ��� int�� ��ȯ
	cout << "The double value entered is " << result * 2<<endl; //������� 2�� ���� ���� ���
	cout << "Enter the number: ";
	fgets(number2, 256, stdin); //���ڿ� �Է¹ޱ�
	result = oopstd::myatoi(number2); //���ڿ��� atoi�� �ÿ��� int�� ��ȯ
	cout << "The double value entered is " << result * 2<<endl; //������� 2�� ���� ���� ���

	

	cout << endl << "Atof Function" << endl;
	double result2; //������� ���� ����
	char number3[256]; //�Է¹��� ���ڿ� ����
	char number4[256]; //�Է¹��� ���ڿ� ����
	cout << "Enter the number: ";
	fgets(number3, 256, stdin); //���ڿ� �Է¹ޱ�
	result2 = atof(number3);
	printf("Num: %f.\n", result2); //atof�� ����� ����� ���
	cout << "Enter the number: ";
	fgets(number4, 256, stdin); //���ڿ� �Է¹ޱ�
	result2 = oopstd::myatof(number4);
	printf("Num: %f.\n", result2); //myatof�� ����� ����� ���
	
	return 0; //0�� ��ȯ
} //main�Լ� ����