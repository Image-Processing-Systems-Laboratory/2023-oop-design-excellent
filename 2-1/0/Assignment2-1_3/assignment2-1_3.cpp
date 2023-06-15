#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "oopstd.h"
#include<cstdlib>
#include<string.h>
using namespace std;

//헤더파일에 선언된 함수들과 oopstd.h에 직접 구현한 함수들을 비교
int main()
{
	//char형 및 int형 배열 선언
	char str1[] = "123.45A56df";
	char str2[] = "123.45A56dd";
	char str3[100];
	char str4[100];
	char str5[100];
	char str6[100];
	int str_int1[] = { 1,2,3,4,5,6,7,8,9,0 };

	//memset 비교
	cout << "memset" << endl;
	cout << memset(str_int1, 0, 3*sizeof(int)) << endl;	//str_int1의 주소값 출력 및 3번째 배열칸까지 0으로 초기화
	//배열 출력
	for (int i = 0; i < 10; i++)
		cout << str_int1[i];
	cout << endl;
	cout << "oopstd::memset" << endl;
	cout << oopstd::memset(str_int1, 0, 3 * sizeof(int)) << endl;	//str_int1의 주소값 출력 및 3번째 배열칸까지 0으로 초기화
	//배열 출력
	for (int i = 0; i < 10; i++)
		cout << str_int1[i];
	cout << endl << endl;

	//memcpy 비교
	cout << "memcpy" << endl;
	cout << memcpy(str5, str1, strlen(str1) + 1) << endl;	//str5의 주소값 출력 및 str1의 메모리를 str5에 복사
	cout << str5 << endl;	//str5 출력
	cout << "oopstd::memcpy" << endl;
	cout << oopstd::memcpy(str5, str1, strlen(str1) + 1) << endl;	//str5의 주소값 출력 및 str1의 메모리를 str5에 복사
	cout << str5 << endl;	//str5 출력
	cout << endl;

	//strcmp 비교
	cout << "strcmp" << endl;
	cout << strcmp(str1, str2) << endl;		//str1과 str2의 값 비교후 같으면 0 다를때 str1이 크면 1 str2가 크면 -1 출력
	cout << "oopstd::strcmp" << endl;
	cout << oopstd::strcmp(str1, str2) << endl << endl;	//str1과 str2의 값 비교후 같으면 0 다를때 str1이 크면 1 str2가 크면 -1 출력

	//strncmp 비교
	cout << "strncmp" << endl;
	cout << strncmp(str1, str2, 4) << endl;		//str1과 str2의 값 4까지 비교 후 같으면 0 다를때 str1이 크면 1 str2가 크면 -1 출력
	cout << "oopstd::strncmp" << endl;
	cout << oopstd::strncmp(str1, str2, 4) << endl << endl;		//str1과 str2의 값 4까지 비교 후 같으면 0 다를때 str1이 크면 1 str2가 크면 -1 출력

	//strcpy 비교
	cout << "strcpy" << endl;
	cout << strcpy(str3, str1) << endl;			//str1에 저장된 값을 str3에 복사 후 str3 출력
	cout << "oopstd::strcpy" << endl;
	cout << oopstd::strcpy(str4, str1) << endl << endl;	//str1에 저장된 값을 str4에 복사 후 str4 출력

	//strncpy 비교
	cout << "strncpy" << endl;
	cout << strncpy(str5, str2, 11) << endl;	//str2에 저장된 값을 11까지 str5에 복사 후 str5 출력
	cout << "oopstd::strncpy" << endl;
	cout << oopstd::strncpy(str5, str2, 11) << endl << endl;	//str2에 저장된 값을 11까지 str5에 복사 후 str5 출력

	//strlen 비교
	cout << "strlen" << endl;
	cout << strlen(str1) << endl;		//str1의 문자 길이 출력
	cout << "oopstd::strlen" << endl;
	cout << oopstd::strlen(str1) << endl << endl;	//str1의 문자 길이 출력

	//atoi 비교
	cout << "atoi" << endl;
	cout << atoi(str1) << endl;		//str1에 저장된 정수 값 출력
	cout << "oopstd::atoi" << endl;
	cout << oopstd::atoi(str1) << endl << endl;		//str1에 저장된 정수 값 출력

	//atof 비교
	cout << "atof" << endl;
	cout << atof(str2) << endl;		//str2에 저장된 실수 값 출력
	cout << "oopstd::atof" << endl;
	cout << oopstd::atof(str2) << endl << endl;		//str2에 저장된 실수 값 출력

	return 0;
}
