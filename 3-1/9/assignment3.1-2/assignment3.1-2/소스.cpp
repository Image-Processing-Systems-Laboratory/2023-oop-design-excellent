#include <iostream>
using namespace std;
char* my_strtok(char* str) {
    //스태틱 변수를 사용해 반환한 위치를 기억
    static char* p = nullptr;
    //매개변수로 받은 str1이 null이 아니면
    if (str != nullptr) {
        p = str;
    }
    //p가 null이면
    if (p == nullptr) {
        return nullptr;
    }
    
    char* token = p;
    //'@', '.' 을 만날경우 그 공간에 널문자를 삽입 후 다음 위치를 가르키게 설정
    while (*p != '\0') {
        if (*p == '@' || *p == '.') {
            *p = '\0';
            p++;
            break;
        }
        p++;
    }
    if (*token == '\0') { //토큰이 빈 문자열이면 
        return nullptr;
    }
    return token;
}

int main() {
    char email[100];
    cout << "이메일을 입력하세요: ";
    cin >> email;

    char* token; 
    //문자열을 구분하여  null이 아닐때까지 반복해가며 출력
    for (token = my_strtok(email); token != nullptr; token = my_strtok(nullptr)) {
        cout << token << endl;
    }

    return 0;
}