#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "oopstd.h"

using namespace oopstd;
using namespace std;


int main() {
    cout << "Example of memset (std)" << endl << endl;

    char str_1[20] = "hello world";
    std :: memset(str_1, '*', 5); // str의 앞 5글자를 '*'로 초기화
    cout << str_1 << endl << endl;

    cout << "Example of memset (oopstd)" << endl << endl;

    char str[20] = "hello world";
    oopstd::memset(str, '*', 5); // str의 앞 5글자를 '*'로 초기화
    cout << str << endl << endl;

    cout << "---------------------------------------------" << endl << endl;
    
    cout << "Example of memcpy (std)" << endl << endl;

    char str_2[] = "hello world";
    char result_1[20];
    std :: memcpy(result_1, str_2, sizeof(str_2)); // str2를 result에 복사
    cout << result_1 << endl << endl;

    cout << "Example of memcpy (oopstd)" << endl << endl;

    char str2[] = "hello world";
    char result1[20];
    oopstd::memcpy(result1, str2, sizeof(str2)); // str2를 result에 복사
    cout << result1 << endl << endl;

    cout << "---------------------------------------------" << endl << endl;

    cout << "Example of strcmp(std)" << endl << endl;
    char str_3[] = "hello";
    char str_4[] = "world";
    int result_2 = std :: strcmp(str_3, str_4); // 두 문자열을 비교하여 결과를 반환
    if (result_2 == 0) {
		cout << "The strings are equal." << endl << endl;
	}
    else if (result_2 < 0) {
		cout << "The first string is smaller." << endl << endl;
	}
    else {
		cout << "The first string is larger." << endl << endl;
	}

    cout << "Example of strcmp(oopstd)" << endl << endl;

    char str3[] = "hello";
    char str4[] = "world";

    int result2 = oopstd :: strcmp(str3, str4); // 두 문자열을 비교하여 결과를 반환
    if (result2 == 0) {
        cout << "The strings are equal." << endl << endl;
    }
    else if (result2 < 0) {
        cout << "The first string is smaller." << endl << endl;
    }
    else {
        cout << "The first string is larger." << endl << endl;
    }

    cout << "---------------------------------------------" << endl << endl;

    cout << "Example of strncmp (std)" << endl << endl;
    char str_5[] = "hello world";
    char str_6[] = "hello";
    int result_3 = std :: strncmp(str_5, str_6, 5); // 두 문자열을 5개의 문자만큼 비교하여 결과를 반환
    if (result_3 == 0) {
        cout << "The strings are equal." << endl << endl;
    }
    else if (result_3 < 0) {
        cout << "The first string is smaller." << endl << endl;
    }
    else {
        cout << "The first string is larger." << endl << endl;

    }
 
    cout << "Example of strncmp (oopstd)" << endl << endl;

    char str5[] = "hello world";
    char str6[] = "hello";
    int result3 = oopstd :: strncmp(str5, str6, 5); // 두 문자열을 5개의 문자만큼 비교하여 결과를 반환
    if (result3 == 0) {
        cout << "The strings are equal." << endl << endl;
    }
    else if (result3 < 0) {
        cout << "The first string is smaller." << endl << endl;
    }
    else {
        cout << "The first string is larger." << endl << endl;
    }

    cout << "---------------------------------------------" << endl << endl;

    cout << "Example of strcpy (std)" << endl << endl;

    char str_7[] = "hello world";
    char result_4[20];
    std :: strcpy(result_4, str_7); // str7을 result4에 복사
    cout << result_4 << endl << endl;

    cout << "Example of strcpy (oopstd)" << endl << endl;

    char str7[] = "hello world";
    char result4[20];
    oopstd :: strcpy(result4, str7); // str7을 result4에 복사
    cout << result4 << endl << endl;

    cout << "---------------------------------------------" << endl << endl;

    cout << "Example of strncpy(std)" << endl << endl;
    char str_8[] = "hello world";
    char result_5[20];
    result_5[6] = '\0'; // result5의 6번째 문자를 NULL로 초기화 [6번째 문자는 NULL이 아닌 문자로 초기화되어 있음]
    std :: strncpy(result_5, str_8, 6); // str8을 result5에 5개의 문자만큼 복사
    cout << result_5 << endl << endl;

    cout << "Example of strncpy(oopstd)" << endl << endl;

    char str8[] = "hello world";
    char result5[20];

    oopstd :: strncpy(result5, str8, 5); // str8을 result5에 5개의 문자만큼 복사
    cout << result5 << endl << endl;

    cout << "---------------------------------------------" << endl << endl;

    cout << "Example of strlen (std)" << endl << endl;

    char str_9[] = "hello world";
    int result_6 = std :: strlen(str_9); // str9의 길이를 반환
    cout << result_6 << endl << endl;


    cout << "Example of strlen (oopstd)" << endl << endl;

    char str9[] = "hello world";
    int result6 = oopstd :: strlen(str9); // str9의 길이를 반환
    cout << result6 << endl << endl;

    cout << "---------------------------------------------" << endl << endl;

    cout << "Example of atoi (std)" << endl << endl;

    char str_10[] = "12345";
    int result_7 = std :: atoi(str_10); // str9를 정수로 변환
    cout << result_7 << endl << endl;

    cout << "Example of atoi (oopstd)" << endl << endl;

    char str10[] = "12345";
    int result7 = oopstd :: atoi(str10); // str9를 정수로 변환
    cout << result7 << endl << endl;

    cout << "---------------------------------------------" << endl << endl;

    cout << "Example of atof (std)" << endl << endl;

    char str_11[] = "123.45";
    float result_8 = std :: atof(str_11); // str9를 실수로 변환
    cout << result_8 << endl << endl;

    cout << "Example of atof (oopstd)" << endl << endl;

    char str11[] = "123.45";
    float result8 = oopstd :: atof(str11); // str9를 실수로 변환
    cout << result8 << endl << endl;

    return 0;

}