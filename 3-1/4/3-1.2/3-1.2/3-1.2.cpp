#include <iostream>

using namespace std;

char* my_strtok(char* str); //입력받은 문자열에서 이메일 주소(@ .)를 구분하는 함수
void print(char* input); //입력받은 문자열에서 토큰을 구분하고 각 토큰을 출력하는 함수

int main() {
    char input[100]; //입력받을 문자열 input 변수 선언
    cout << "Enter the email address: ";
    cin >> input; //input 입력받기
    print(input); //print 함수 호출해 결과 값 출력

    return 0; //종료
}

char* my_strtok(char* str) {
    static char* last = NULL; //마지막 토큰을 저장하기 위한 정적 변수 last 선언
    char* token = NULL; //현재 토큰 저장하기 위한 변수 token 선언
    int i = 0; //문자열의 인덱스를 저장하기 위한 변수 i 선언
    
    if (str == NULL && last == NULL) { //입력받은 문자열이 NULL이고 마지막 토큰이 NULL이면
        return NULL; //NULL 반환
    }
    if (str != NULL) { //입력받은 문자열이 NULL이 아니면
        last = str; //last에 str 값 저장
    }
    while (*last == '@' || *last == '.') { //처음부터 '@' 또는 '.'인 경우 건너뛰기
        last++;
    }
    if (*last == '\0') { //마지막 토큰이 NULL이면
        return NULL; //NULL 반환
    }

    token = last; //현재 위치부터 토큰 처리

    while (*last != '\0' && *last != '@' && *last != '.') { //'@' 또는 '.'이 나타나기 전까지 토큰 읽기
        last++;
    }
    if (*last == '\0') { //문자열의 끝이면
        last = NULL; //last를 NULL값으로
    }
    else { //'@' 또는 '.'이면
        *last = '\0'; //현재 위치의 문자를 NULL로
        last++; //마지막 토큰의 시작 위치를 다음 문자로 이동
    }

    return token; //token 반환
}

void print(char* input) {
    char* token = my_strtok(input); //my_strtok함수 호출해 문자열에서 첫 번째 토큰을 받아옴
    while (token != NULL) { //토큰이 NULL이 아닌 동안 반복
        cout << token << endl; //현재 토큰 출력
        token = my_strtok(NULL); //다음 토큰 받아옴
    }
}