#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

class NewString { // 클래스 생성
private:
    char* string_content; // 멤버 변수: 문자열
    int string_length; // 멤버 변수: 문자열의 길이
public:
    // 메소드
    NewString(void); // 생성자
    NewString(const char* string_content); // 생성자
    NewString(const NewString& reference); // 복사 생성자
    ~NewString(); // 소멸자
    NewString& operator=(const NewString& reference); // 연산자 오버로딩: = 연산자 정의
    NewString operator+(const NewString& reference); // 연산자 오버로딩: + 연산자 정의
    bool operator==(const NewString& reference); // 연산자 오버로딩: == 연산자 정의
    char at(int i) const; // i번째 인덱스의 원소를 반환하는 메소드

    friend std::ostream& operator<<(std::ostream& os, const NewString& reference); // friend 함수, 멤버를 공유받음, 여기서는 << 연산자
    friend std::istream& operator>>(std::istream& is, NewString& reference); // friend 함수, 멤버를 공유받음, 여기서는 >> 연산자
};

NewString::NewString() : string_content(nullptr), string_length(0) {}; // 생성자
NewString::NewString(const char* string_content) : string_length(strlen(string_content) + 1) { // 생성자, 문자열의 길이는 NULL값까지 받아들이기 위해 +1
    this->string_content = new char[string_length]; // 문자열 길이만큼 메모리 할당
    strcpy(this->string_content, string_content); // 문자열 생성
}
NewString::NewString(const NewString& reference) : string_length(reference.string_length) { // 복사 생성자
    string_content = new char[string_length]; // 문자열 길이만큼 메모리 할당
    strcpy(string_content, reference.string_content); // 문자열 생성
}
NewString::~NewString() { // 소멸자
    if (string_content == nullptr) { // 이미 메모리가 해제되있을 경우 예외처리
        return;
    }
    delete[] string_content; // 메모리 해제
}
NewString& NewString::operator=(const NewString& reference) { // 연산자 오버로딩: = 연산자 정의
    if (string_content != nullptr) { // 문자열을 대입시키기 위해 기존 문자열 해제
        delete[] string_content;
    }
    string_length = reference.string_length; // 문자열 길이 측정
    string_content = new char[string_length]; // 문자열 길이만큼 메모리 할당
    strcpy(string_content, reference.string_content); // 문자열 생성
    return *this; // 생성된 문자열의 주소값 반환
}
NewString NewString::operator+(const NewString& reference) { // 연산자 오버로딩: + 연산자 정의
    int length = this->string_length + reference.string_length - 1; // 합쳐지는 문자열의 길이는 합칠 두 개의 문자열의 길이에서 NULL값 하나만큼 빼줌
    char* temp = new char[length]; // 합쳐지는 문자열의 길이만큼 메모리 할당
    strcpy(temp, string_content); // 한 개의 문자열 먼저 대입
    strcat(temp, reference.string_content); // 나머지 문자열을 붙임
    NewString strTemp(temp); // 클래스 생성
    delete[] temp; // 메모리 해제
    return strTemp; // 생성된 클래스 반환
}
bool NewString::operator==(const NewString& reference) { // 연산자 오버로딩: == 연산자 정의
    return strcmp(string_content, reference.string_content) ? false : true; // 두 개의 문자열을 비교해서 참과 거짓 둘 중의 하나 값을 반환
}
char NewString::at(int i) const { // i번째 문자를 반환하는 메소드
    if (i >= string_length || i < 0) { // i가 문자열을 벗어나는 인덱스 값일 경우 예외 처리
        return NULL;
    }
    else {
        return string_content[i]; // i번째 인덱스의 원소를 반환
    }
}
std::ostream& operator<<(std::ostream& os, const NewString& reference) { // ostream 클래스의 멤버중 연산자<<를 공유받음
    os << reference.string_content; // ostream으로 문자열을 보냄
    return os;
}
std::istream& operator>>(std::istream& is, NewString& reference) { // istream 클래스의 멤버중 연산자>>를 공유받음
    char temp[100];
    is >> temp; // istream 에서 문자열을 받아옴
    reference = NewString(temp); // 클래스 생성
    return is;
}

NewString str1;
NewString str2;
NewString str3;
// 다른 함수에서도 사용하기 위해 전역 변수로 선언

int match(char a) {
    // 해당하는 문자가 문자열에 얼마나 있는지 카운트해줌

    int count = 0;
    // 카운터를 0으로 초기화
    for (int i = 0; str3.at(i) != '\0'; i++) {
        if (str3.at(i) == a) {
            // 문자와 문자열의 문자가 같으면 카운터를 +1
            count++;
        }
    }
    return count;
    // 카운터 값을 반환
}

void printOutput() {
    // 특정한 패턴에 따라 문자열을 찍음

    int count = 0;
    // 현재 문자가 그 전에 출력되었는지를 카운트해줌
    for (int i = 0; str3.at(i) != '\0'; i++) {
        for (int j = 0; j < i; j++) {
            // 현재 문자가 그 전에 출력되었는지 확인하기 위함
            if (str3.at(i) == str3.at(j)) {
                count++; // 현재 문자가 그 전에 출력되었으면 카운트
                break; // 반복문을 벗어남
            }
        }
        if (count == 1) {
            // 현재 문자가 그 전에 출력되었으면
            count = 0; // 카운터 초기화
            continue; // 현재 문자는 패턴을 출력하지 않고 넘어감
        }
        std::cout << str3.at(i) << match(str3.at(i));
        // 현재 문자와 그 문자가 문자열에 몇 번 들어있는지 출력함
    }

    return;
    // 함수 종료
}

int main()
{
    std::cout << "Input 2 integer numbers: ";
    std::cin >> str1, std::cin >> str2;
    // 두 개의 문자열을 입력
    str3 = str1 + str2;
    // 두 개의 문자열을 하나로 합침

    printOutput();
    // 특정한 패턴을 찍는 함수를 호출

    return 0;
    // 정상적인 종료시
}