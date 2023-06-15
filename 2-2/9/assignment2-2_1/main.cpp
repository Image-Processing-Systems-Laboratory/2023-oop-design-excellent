#include <iostream>
#include <cstdio>
#include "NestedArray.h"

using namespace std;

char input[100000];                                     //명령어를 저장할 배열

int compare_str(const char* str1, const char* str2);    //두 문자열을 비교하는 함수
NestedArray* allocation(int index);                     //메모리 할당 및 값 저장 함수
void find(NestedArray* arr, int index);                 //입력한 명령어의 첨자에 따라 해당 값을 찾는 함수
void printStr(NestedArray* arr);                        //문자열 출력 함수
void printArray(NestedArray* arr);                      //배열 출력 함수
void memory_free(NestedArray* arr);                     //할당된 메모리 해제 함수

int main(void) {
	NestedArray* nestedarray;                    //NestedArray 클래스의 포인터 변수 생성
	int i, j;
	char temp[5];                                //문자열을 임시 저장할 배열

	gets_s(input, 100000);                       //배열 생성 명령어 입력 받기

	i = 0;
	while (input[i] == ' ') {                    //공백 무시하기
		i++;
	}

	nestedarray = allocation(i + 1);             //메모리 할당
	
	while (1) {
		gets_s(input, 100000);                   //배열 접근 명령어 입력
		i = 0;
		j = 0;

		while (input[i] == ' ') {                //공백 무시하기
			i++;
		}

		while ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {   //영어 소문자 또는 대문자일 경우
			temp[j] = input[i];                  //temp에 임시 저장
			j++;
			i++;
		}
		temp[j] = '\0';                          //temp의 마지막에 NULL 문자 대입

		if (!compare_str(temp, "exit")) {        //exit 입력할 경우
			break;                               //반복문 종료
		}
		else if (!compare_str(temp, "arr")) {    //입력한 문자열의 첫부분이 arr일 경우
			while (input[i] == ' ') {            //공백 무시하기
				i++;
			}

			if (input[i] == '[') {               //첨자가 있을 경우
				find(nestedarray, i + 1);        //첨자에 맞는 값 찾기

				cout << endl;
			}
			else if (input[i] == '\0') {         //첨자가 없는 경우
				printArray(nestedarray);         //배열의 모든 값 출력

				cout << endl;
			}
		}
	}

	memory_free(nestedarray);                    //메모리 해제

	return 0;
}

//두 문자열을 비교하는 함수
int compare_str(const char* str1, const char* str2) {
	int i = 0;

	while (1) {
		if (str1[i] != str2[i] || (str1[i] == '\0' && str2[i] == '\0')) {  //문자열이 끝나거나 같지 않은 문자를 만날 때까지 반복
			if (str1[i] > str2[i]) {         //str1[i]의 아스키코드 값이 str2[i]보다 큰 경우 1 반환
				return 1;
			}
			else if (str1[i] < str2[i]) {    //str2[i]의 아스키코드 값이 str1[i]보다 큰 경우 -1 반환
				return -1;
			}
			else {                           //같은 문자열이면 0 반환
				return 0;
			}

		}

		i++;
	}
}

//메모리 할당 및 값 저장 함수
NestedArray* allocation(int index) {
	NestedArray* address;             //할당한 메모리를 저장할 포인터 변수
	int num_in_bracket = 0;           //input에서 배열 안에 배열이 있는지 판별
	int count = 0;                    //한 배열의 콤마 개수
	static int current;               //현재 위치의 첨자
	char temp_str[21];                //문자열을 임시 저장할 배열
	int i = 0, j = 0;

	//값의 개수 조사
	current = index;
	while (1) {
		if (input[current] == '[') {             //여는 대괄호를 만났을 경우(array안에 array가 존재)
			num_in_bracket++;
		}
		else if (input[current] == ']') {        //닫는 대괄호를 만났을 경우
			if (num_in_bracket == 0) {           //가장 바깥 대괄호였을 경우 반복문 종료
				break;
			}
			else {                               //array안에 존재하는 array의 대괄호였을 경우
				num_in_bracket--;
			}
		}
		else if (input[current] == ',') {        //콤마를 만났을 경우
			if (num_in_bracket == 0) {           //속의 배열의 콤마가 아닐 경우
				count++;
			}
		}

		current++;
	}     // -> count는 배열의 값의 수(array는 하나의 값으로 취급)보다 1 작은 값을 가지게 된다.
	
	address = new NestedArray[count + 1];            //값의 수만큼 메모리 할당
	address[count].setEnd();                         //마지막 요소에 마지막임을 표시

	//할당한 메모리에 문자열 또는 배열 저장하기
	current = index;
	while (1) {
		if ((input[current] >= 'a' && input[current] <= 'z') || (input[current] >= 'A' && input[current] <= 'Z')) {  //영어 대문자 또는 소문자일 경우
			temp_str[i] = input[current];                  //temp_str에 임시 저장 
			i++;
		}
		else if (input[current] == '[') {                  //여는 대괄호일 경우
			address[j].setArray(allocation(current + 1));  //allocation 함수를 재귀 호출하여 배열 할당 후 그 주소를 저장
			j++;
			current++;
			while (input[current] == ' ') {                //공백 무시하기
				current++;
			}
			if (input[current] == ']') {                   //닫는 대괄호일 경우 반복문 종료
				break;
			}
		}
		else if (input[current] == ',' || input[current] == ']') {   //닫는 대괄호 또는 콤마일 경우
			temp_str[i] = '\0';                  //마지막에 NULL 문자 대입
			address[j].setStr(temp_str);         //문자열 저장

			i = 0;
			j++;
			if (input[current] == ']') {         //닫는 대괄호일 경우 반복문 종료
				break;
			}
		}

		current++;
	}

	return address;                              //할당한 메모리의 주소 반환
}

//입력한 명령어의 첨자에 따라 해당 값을 찾는 함수
void find(NestedArray* arr, int index) {
	int number = 0;                 //입력한 첨자를 정수로 변환하여 저장
	int start;                      //숫자의 시작 위치
	int exponent = 1;               //자릿수
	bool end = true;                //입력한 첨자가 모두 끝났음을 표시

	while (input[index] == ' ') {      //공백 무시하기
		index++;
	}

	start = index;  //숫자의 시작 위치 설정

	//숫자의 마지막 위치로 이동
	while (input[index] >= '0' && input[index] <= '9') {
		index++;
	}

	//정수 계산
	for (int j = index - 1; j >= start; j--) {
		number = number + (input[j] - '0') * exponent;  //해당 자릿수를 곱하여 구하기
		exponent *= 10;
	}

	//공백 또는 닫는 대괄호 조사하기
	while (input[index] == ' ' || input[index] == ']') {
		index++;
	}

	//여는 대괄호가 있을 경우 (다음 첨자가 존재)
	if (input[index] == '[') {
		find((arr + number)->getArray(), index + 1);  //첨자에 해당하는 주소에 저장된 속 배열의 주소를 인자로 전달하여 find 함수 재귀 호출
		end = false;                                  //끝이 아님을 표시
	}

	if (end) {                                           //입력한 첨자가 끝났을 경우
		if ((arr + number)->getStr()[0] != '\0') {       //첨자에 해당하는 주소에 저장된 문자열의 첫번째 값이 NULL 문자가 아닐 경우(문자열이 저장되어 있는 객체)
			printStr(arr + number);                      //첨자에 해당하는 주소에 저장된 문자열 출력
		}
		else {                                           //속 배열의 주소 값이 저장되어 있거나 빈 배열
			printArray((arr + number)->getArray());      //배열 출력
		}
	}
}

//문자열 출력 함수
void printStr(NestedArray* arr) {
	cout << arr->getStr();             //arr 주소의 객체의 문자열 출력
}

//배열 출력 함수
void printArray(NestedArray* arr) {
	int i = 0;
	
	cout << '[';

	while (1) {
		if ((arr + i)->getArray() != NULL) {                //arr + i 주소의 객체에 속의 배열의 주소가 저장되어 있을 때
			printArray((arr + i)->getArray());              //속의 배열의 주소를 인자로 전달하여 printArray 함수 재귀 호출 -> 속 배열 출력
		}
		else if ((arr + i)->getStr()[0] != '\0') {          //arr + i 주소의 객체에 문자열이 저장되어 있을 때
			printStr(arr + i);                              //해당 문자열 출력
		}
		else {                                              //빈 배열일 경우 반복문 종료
			break;
		}
		
		if ((arr + i)->getEnd() == true) {                  //arr + i 주소의 객체가 마지막 요소일 경우 반복문 종료
			break;
		}
		else {                                              //arr + i 주소의 객체가 마지막 요소가 아닐 경우
			cout << ", ";
		}

		i++;
	}

	cout << ']';
}

//할당된 메모리 해제 함수
void memory_free(NestedArray* arr) {
	int i = 0;

	while (1) {
		if ((arr + i)->getArray() != NULL){              //arr + i 주소의 객체에 속의 배열의 주소가 저장되어 있을 때
			memory_free((arr + i)->getArray());          //속의 배열의 주소를 인자로 전달하여 memory_free 함수 재귀 호출 -> 속 배열의 메모리 해제
		}

		if ((arr + i)->getEnd() == true) {               //arr + i 주소의 객체가 마지막 요소일 경우 반복문 종료
			break;
		}

		i++;
	}

	delete[] arr;                                         //arr 메모리 해제
}