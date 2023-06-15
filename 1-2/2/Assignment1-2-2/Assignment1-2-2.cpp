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
    int length(const NewString& reference); // 문자열의 길이를 반환
    operator const char* () const; // const char*로 형변환

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
int NewString::length(const NewString& reference) { // 문자열의 길이를 반환
    return strlen(string_content);
}
NewString::operator const char* () const { // const char*로 형변환
    return string_content;
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

NewString numInput; // 사용자가 입력한 문자열 
NewString divide = "11011"; // 5bit binary divisor
// 다른 함수에서도 사용하기 위해 전역 변수로 선언

NewString toBinary(long long num) {
    // 정수를 2진수 문자열로 바꿔주는 함수
    // 1의 자리부터 비교해서 정수를 오른쪽으로 시프트해가며 문자열을 계산

    NewString bin = "";
    NewString ONE = "1";
    NewString ZERO = "0";
    // 문자열을 비어있게 초기화
    while (num) {
        // 입력된 정수가 0이 아닐 동안
        if (num & 1) {
            // 입력된 정수와 정수 1과의 AND연산, 입력된 정수의 1의자리가 1일 경우
            bin = ONE + bin;
        }
        else {
            // 입력된 정수의 1의자리가 0일 경우
            bin = ZERO + bin;
        }
        num = num >> 1;
        // 입력된 정수를 시프트
        // 시프트된 정수를 다시 반복문에 대입
    }
    return bin;
    // 계산된 2진수 문자열을 반환
}

int toDecimal(NewString bin) {
    // 2진수 문자열을 정수로 바꿔주는 함수
    // 0번째 원소부터 비교해서 그 자릿수만큼의 값을 계속 더해주며 정수를 계산

    int dec = 0;
    for (int i = 0; i < bin.length(bin); i++) {
        // 문자열의 길이만큼
        if (bin.at(i) == '1') {
            // 특정 문자열의 원소가 1이면
            dec += (1 << (bin.length(bin) - i - 1));
            // 정수 1을 시프트해서 num에 덧셈
        }
    }
    return dec;
    // 계산된 정수를 반환
}

void receiver(const char* str) {

    std::cout << "Received frame: " << str << std::endl;
    // Received frame 출력

    NewString rec_data = str; // 함수 사용을 위해 string으로 형변환
    long long num1_dec = toDecimal(rec_data); // Received frame을 정수로 변환
    long long divide_dec = toDecimal(divide); // 5bit binary divisor를 정수로 변환
    long long dividend = num1_dec << 4; // 최종 Remainder

    std::cout << "Reconstructed data: " << toBinary(num1_dec >> 4) << std::endl;
    // Reconstructed data 출력

    long long shft = static_cast<long long>(ceill(log2l(dividend + 1))) - 5; // 얼만큼 시프트할지 나머지로 결정, 가장 왼쪽에 있는 1의 위치에 따라 시프트 거리가 결정
    long long result; // XOR 연산의 결과

    while ((dividend >= divide_dec) || (shft >= 0)) {
        // 나누어질 수가 divisor보다 클 때 
        // 혹은 시프트가 0보다 클 때, 즉 나머지가 divisor보다 클 때

        result = (dividend >> shft) ^ divide_dec; // 가장 왼쪽의 1부터 5자리까지 divisor와 XOR 연산 
        dividend = (result << shft) | (dividend & ((static_cast<long long>(1) << shft) - 1)); // XOR 연산 결과에 연산하지 않은 나머지 자리를 붙여주는 연산

        shft = static_cast<long long>(ceill(log2l(dividend + 1))) - 5; // 얼만큼 시프트할지 나머지로 결정, 가장 왼쪽에 있는 1의 위치에 따라 시프트 거리가 결정
    }

    if (dividend == 0) {
        // 나머지가 0일 경우
        std::cout << "No detected error";
        // 에러가 발생하지 않음
    }
    else {
        // 나머지가 0이 아닐 경우
        std::cout << "Receiver has detected error";
        // 에러가 발생함
    }

    return;
    // 함수 종료
}

void transmission_channel(const char* str) {

    char* str_1 = new char[100]; // 메모리 할당
    strcpy(str_1, str);
    
    for (int i = 0; i < 16; i++) {
        // 각 bit마다 계산
        srand(static_cast<unsigned int>(time(NULL)));
        if (rand() % 20 == 0) {
            // 약 5%확률로 참
            if (str_1[i] == '1') {
                // 1이면
                str_1[i] = '0';
                // 0으로 바꿔줌
            }
            else {
                // 0이면
                str_1[i] = '1';
                // 1로 바꿔줌
            }
        }
    }

    const char* str_1_1 = str_1;

    receiver(str_1_1);
    // received frame 전달

    delete[] str_1; // 메모리 해제

    return;
    // 함수 종료
}

void sender(void) {

    long long num1_dec = toDecimal(numInput); // 입력된 문자열을 정수로 변환
    long long divide_dec = toDecimal(divide); // 5bit binary divisor를 정수로 변환
    long long dividend = num1_dec << 4; // 최종 Remainder

    long long shft = static_cast<long long>(ceill(log2l(dividend + 1))) - 5; // 얼만큼 시프트할지 나머지로 결정, 가장 왼쪽에 있는 1의 위치에 따라 시프트 거리가 결정
    long long result; // XOR 연산의 결과

    while ((dividend >= divide_dec) || (shft >= 0)) {
        // 나누어질 수가 divisor보다 클 때 
        // 혹은 시프트가 0보다 클 때, 즉 나머지가 divisor보다 클 때

        result = (dividend >> shft) ^ divide_dec; // 가장 왼쪽의 1부터 5자리까지 divisor와 XOR 연산 
        dividend = (result << shft) | (dividend & ((static_cast<long long>(1) << shft) - 1)); // XOR 연산 결과에 연산하지 않은 나머지 자리를 붙여주는 연산
        
        shft = static_cast<long long>(ceill(log2l(dividend + 1))) - 5; // 얼만큼 시프트할지 나머지로 결정, 가장 왼쪽에 있는 1의 위치에 따라 시프트 거리가 결정
    }

    long long frame = (num1_dec << 4) | dividend; // Coded frame 값

    NewString str_1 = toBinary(frame); // 문자열로 변환
    const char* str = str_1; // 다른 함수로 전달하기 위해 형 변환

    std::cout << "Coded frame: " << str << std::endl;
    // Coded frame 출력

    transmission_channel(str);
    // Coded frame 전달

    return;
    // 함수 종료
}

int main()
{
    std::cout << "Data: ";
    std::cin >> numInput;
    // 사용자로부터 2진수 값을 받아 문자열로 저장

    if (numInput.length(numInput) != 12) {
        std::cout << "12bit 데이터가 입력되지 않았습니다.";
        return 0;
    }
    // 12bit아닌 데이터가 입력되었을 때 예외처리

    sender();
    // 함수 호출

    return 0;
    // 정상적인 종료시
}