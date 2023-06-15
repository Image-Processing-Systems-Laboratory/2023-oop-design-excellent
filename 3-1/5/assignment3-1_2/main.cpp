#include <iostream>

using namespace std;

char* my_strtok(char* str);               //문자열 str을 '@'와 '.'으로 구분하는 함수

int main(void) {
	char str[100];                        //tokenize할 문자열
	char* token;                          //my_strtok 함수의 반환 값을 저장할 변수

	cin >> str;

	while (1) {
		token = my_strtok(str);           //my_strtok 함수 호출 후 반환 값(token의 주소) 저장

		if (token == NULL) {              //NULL문자를 반환했을 경우 문자열을 끝까지 분석한 것이므로 반복 종료
			break;
		}
		else {
			cout << token << endl;        //token 출력
		}
	}

	return 0;
}

//문자열 str을 '@'와 '.'으로 구분하는 함수
char* my_strtok(char* str) {
	static char* ptr = str;               //static pointer
	char* address = ptr;                  //token의 주소
	str = ptr;

	//문자열 분석
	while (*address) {
		if (*str == '@' || *str == '.') { //'@' 또는 '.' 또는 NULL 문자를 만났을 경우
			*str = '\0';				  //해당 위치에 NULL 문자 대입
			str++;
			ptr = str;					  //ptr에 str 저장
			return address;				  //token의 주소 반환 (매개변수 str은 token을 제외한 나머지 문자열의 주소를 가리키게 된다.)
		}

		if (*str == '\0') {               //문자열의 끝에 도달했을 경우
			ptr = str;					  //ptr에 str 저장
			return address;				  //token의 주소 반환 (매개변수 str은 token을 제외한 나머지 문자열의 주소를 가리키게 된다.)
		}
		
		str++;							  //다음 문자로 이동
	}

	return NULL;                          //문자열을 모두 분석했을 경우 NULL 반환
}