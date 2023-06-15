#include <iostream>

using namespace std;

char* my_strtok(char* str, const char* delimiter) { // 사용자 정의 strtok 함수
	static char* p;
	if (str != NULL) p = str; // str이 NULL이 아니면 p에 str을 대입
	else if (p == NULL) return NULL; // p가 NULL이면 NULL 반환
	char* ret = p;
	while (*p != '\0') { // p가 가리키는 문자가 NULL이 아닐 때까지 반복
		const char* d = delimiter;
		while (*d != '\0') { // d가 가리키는 문자가 NULL이 아닐 때까지 반복
			if (*p == *d) {
				*p = '\0';
				p++;
				return ret;
			}
			d++;
		}
		p++;
	}
	p = NULL;
	return ret;
}

bool isValidEmail(const char* email) { // 이메일 주소가 유효한지 검사하는 함수
	int at_count = 0;
	for (int i = 0; email[i] != '\0'; i++) {
		if (email[i] == '@') {
			at_count++;
		}
	}
	return at_count == 1;	
}

int main() { 

	char email[50];

	cin >> email;

	if (!isValidEmail(email)) { // 이메일 주소가 유효하지 않으면 에러 메시지 출력
		cout << "Error: Invalid email format (multiple '@' characters detected)." << endl;
		return 1;
	}

	char* token = my_strtok(email, "@"); // @를 기준으로 토큰 분리

	while (token != NULL) { // 토큰이 NULL이 아닐 때까지 반복
		cout << token << endl;
		token = my_strtok(NULL, ".");
	}
	return 0;
}
