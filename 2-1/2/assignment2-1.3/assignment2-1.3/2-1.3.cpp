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
}person, person_copy, person2, person_copy2; //출력 예시를 위한 구조체 선언

int main()
{	
	cout << "Memset Function" << endl; //Memset 함수 비교
	char str1[] = "I can make the memset Function myself!"; //문자열 초기화
	char str2[] = "I can make the memset Function myself!";
	cout << "Original String: " << str1 << endl; //원래 문자열 출력
	memset(str1, '-', 6); //문자열 앞 6자리에 '-' 넣기
	cout << "Using Memset: " << str1 << endl;
	oopstd::mymemset(str2, '-', 6); //동일하게 앞 6자리에 '-' 넣기
	cout << "Using My Memset: " << str2 << endl;
	

	cout << endl<<"Memcpy Function" << endl; //Memcpy 함수 비교
	char myname[] = "Lee Jong Hyeok";
	memcpy(person.name, myname, strlen(myname)+1); //person.name에 myname의 데이터 복사
	person.age = 23; //person.age를 23으로 설정
	memcpy(&person_copy, &person, sizeof(person)); //person에 있는 데이터를 person_copy로 복사
	printf("person_copy: %s, %d", person_copy.name, person_copy.age); //person_copy의 요소들 출력
	cout << endl;
	char myname2[] = "Iron Man"; 
	oopstd::mymemcpy(person2.name, myname2, strlen(myname2)+1); //mymemcpy를 이용해 person2.name에 myname2 데이터 복사
	person2.age = 50; //person2.age를 50으로 설정
	oopstd::mymemcpy(&person_copy2, &person2, sizeof(person2)); //mymemcpy를 이용해 person2의 데이터를 person_copy2로 복사
	printf("person_copy2: %s, %d", person_copy2.name, person_copy2.age); //복사된 요소들 출력
	
	
	cout << endl << endl<<"Strcmp Function" << endl; //strcmp 함수 비교
	char key[] = "kwangwoon"; //답: kwangwoon
	char buffer[30]; //답을 입력받을 문자열
	cout << "<Quiz Using strcmp function>" << endl;
	do {
		cout << "Guess my university!: ";
		cin >> buffer;
	} while (strcmp(key, buffer) != 0); //key와 buffer가 같지 않은 상태일 때 반복
	cout << "Correct answer!"<<endl;
	
	char key1[] = "computer"; //답: computer
	char buffer1[30]; //답을 입력받을 문자열
	cout << endl << "<Quiz Using my strcmp function>" << endl;
	do {
		cout << "Guess my major!: ";
		cin >> buffer1;
	} while (oopstd::mystrcmp(key1, buffer1) != 0); //mystrcmp를 사용해 두 문자열이 같은지 비교
	cout << "Correct answer!" << endl;
	

	cout << endl << "Strncmp Function" << endl; //strncmp 함수 비교
	char str[][5] = { "1234","1278","1298","3456","7891" }; //비교할 숫자들
	cout << "Found Number start with '12'"<<endl;
	for (int i = 0; i < 5; i++) //기존 strncmp 함수 사용
	{
		if (strncmp(str[i], "12XX", 2) == 0) //만약 앞 두자리가 동일하면
			cout << "Found: " << str[i] << endl; //그 문자열 전체를 출력
	}
	cout << "Found Number start with '12' by using mystrncmp" << endl;
	for (int i = 0; i < 5; i++) //mystrncmp 함수 사용
	{
		if (oopstd::mystrncmp(str[i], "12XX", 2) == 0) //만약 앞 두자리가 동일하면
			cout << "Found: " << str[i] << endl; //그 문자열 전체를 출력
	}

	
	
	cout << endl << "Strcpy Function" << endl; //strcpy 함수 비교
	char original[] = "Copy this Sentence."; //원본 문장
	char char1[50];
	char char2[50]; //복사를 받을 문자열들
	strcpy(char1, original); //char1에 original 복사
	strcpy(char2, "I can copy like this."); //char2에 해당 문자열 복사
	cout << "Original: " << original << endl << "Copied from Original: " << char1 << endl << "Copied from Sentence: " << char2 << endl;
	char original2[] = "Mystrcpy Function is good!"; //원본 문장 2
	oopstd::mystrcpy(char1, original2); //mystrcpy를 사용하여 original2를 char1에 복사
	oopstd::mystrcpy(char2, "Wow I can copy like this!"); //mystrcpy를 이용하여 해당 문자열을 char2에 복사
	cout << "Original: " << original2 << endl << "Copied from Original: " << char1 << endl << "Copied from Sentence: " << char2 << endl;
	

	
	cout << endl << "Strncpy Function" << endl; //strncpy 함수 비교
	char original3[] = "Copy this sentence,too"; //원본 문장
	char char3[50];
	char char4[50]; //복사를 받을 문자열들
	char original4[] = "This sentence copied by using Mystrncpy Function"; //원본 문장 2
	strncpy(char3, original3, sizeof(char3)); //char3에 original3을 끝까지 복사
	strncpy(char4, original3, 4); //char4에 original3을 4까지 복사
	char4[4] = '\0'; //마지막 널 문자 추가
	cout << original3 << endl << char3 << endl << char4 << endl; //결과 출력
	oopstd::mystrncpy(char3, original4, sizeof(char3)); //mystrncpy를 이용해서 char3에 original4를 끝까지 복사
	oopstd::mystrncpy(char4, original4, 4); //mystrncpy를 이용해서 char3에 original4를 4까지 복사
	char4[4] = '\0'; //마지막 널 문자 추가
	cout << original4 << endl << char3 << endl << char4 << endl; //결과 출력

	
	cout << endl << "Strlen Function" << endl; //strlen 함수 비교
	char lengthinput[256];
	cout << "Enter the sentence: ";
	gets_s(lengthinput, sizeof(lengthinput));
	cout << "The sentence entered is " << (unsigned)strlen(lengthinput) << " characters long." << endl;
	cout << "Mystrlen Function" << endl;
	cout << "The sentence entered is " << (unsigned)oopstd::mystrlen(lengthinput) << " characters long."<<endl;
	

	cout << endl << "Atoi Function" << endl; //atoi 함수 비교
	int result; //결과값을 위한 변수
	char number[256]; //입력받을 문자열 선언
	char number2[256]; //입력받을 문자열 선언
	cout << "Enter the number: ";
	fgets(number, 256, stdin); //문자열 입력받기
	result = atoi(number); //문자열을 atoi를 시용해 int로 변환
	cout << "The double value entered is " << result * 2<<endl; //결과값의 2를 곱한 수를 출력
	cout << "Enter the number: ";
	fgets(number2, 256, stdin); //문자열 입력받기
	result = oopstd::myatoi(number2); //문자열을 atoi를 시용해 int로 변환
	cout << "The double value entered is " << result * 2<<endl; //결과값의 2를 곱한 수를 출력

	

	cout << endl << "Atof Function" << endl;
	double result2; //결과값을 위한 변수
	char number3[256]; //입력받을 문자열 선언
	char number4[256]; //입력받을 문자열 선언
	cout << "Enter the number: ";
	fgets(number3, 256, stdin); //문자열 입력받기
	result2 = atof(number3);
	printf("Num: %f.\n", result2); //atof을 사용해 결과값 출력
	cout << "Enter the number: ";
	fgets(number4, 256, stdin); //문자열 입력받기
	result2 = oopstd::myatof(number4);
	printf("Num: %f.\n", result2); //myatof을 사용해 결과값 출력
	
	return 0; //0의 반환
} //main함수 종료