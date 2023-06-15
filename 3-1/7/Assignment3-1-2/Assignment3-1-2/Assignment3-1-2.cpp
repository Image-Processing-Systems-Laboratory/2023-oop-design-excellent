#include <iostream>
using namespace std;

char* my_strtok(char* str) 
{
    static char* ptr; // 정적 변수로 선언
    if (str != NULL) // str이 NULL이 아니면
    {
        ptr = str; // ptr은 str을 가리킴
    }
    char* token_start = ptr; // token의 시작 위치를 ptr로 지정함
    while (*ptr != '\0') // ptr이 가리키는 값이 NULL이 아니면
    {
        if (*ptr == '@' || *ptr == '.') // ptr이 가리키는 값이 @ or . 일 경우
        {
            *ptr = '\0'; // ptr이 가리키는 값 NULL로 설정
            ptr++; // 이동
            return token_start; // token 시작 위치 반환
        }
        ptr++; // 다음 위치 이동
    }
    if (token_start != ptr) // token이 있으면
    {
        return token_start; //token 시작 위치 반환
    }
    return NULL; // 없으면 NULL 반환
}

int main() 
{
    // 이메일 입력 받음
    char email[100];
    cout << "Enter an email address: ";
    cin >> email;

    char* token = my_strtok(email); // 문자열 토큰화 해서 첫 번째 토큰의 시작 위치 반환
    while (token != NULL) // 반환된 값이 NULL이 아니면
    {
        cout << token << endl; // 토큰 출력
        token = my_strtok(NULL); // 다음 토큰 시작 위치 반환
    }
    return 0;
}