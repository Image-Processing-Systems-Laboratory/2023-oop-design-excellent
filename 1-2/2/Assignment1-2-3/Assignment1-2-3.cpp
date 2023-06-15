#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>

std::ifstream fin;
// 다른 함수에서도 사용하기 위해 전역 변수로 선언

bool match(char* str1, char* str2) {
    // 문자열과 패턴이 일치하는지 확인 후 일치하면 true를 일치하지 않으면 false를 반환

    int str_1_size = strlen(str1); // 데이터의 길이 
    int str_2_size = strlen(str2); // 패턴의 길이
    bool T[101][101] = {}; 
    // 행의 크기는 입력받을 데이터의 최대값의 +1
    // 열의 크기는 입력받을 패턴의 최대값의 +1
    // +1하는 이유는 길이가 0일때 예외처리를 위함
    // FALSE값으로 초기화

    T[0][0] = true;
    // 데이터와 패턴 모두 길이가 0일 때 예외처리

    for (int j = 1; j <= str_2_size; j++) {
        if (str2[j - 1] == '*') {
            // *가 입력되면
            T[0][j] = T[0][j - 1]; // 지금까지 참이었으면 참, 한번이라도 거짓이었으면 거짓
        }
    }
    // 데이터의 길이가 0이고 패턴은 길이가 있을 때 예외처리

    for (int i = 1; i <= str_1_size; i++) {
        for (int j = 1; j <= str_2_size; j++) {
            // 데이터와 패턴을 비교함
            // *가 입력되면 데이터와 패턴의 길이가 달라도 되므로 이중 반복문을 돔
            if (str2[j - 1] == '*') {
                // 패턴에 *가 입력되면
                T[i][j] = (T[i - 1][j] || T[i][j - 1]); // 해당하는 데이터가 없거나 더 많아도 지금까지 참이었다면 참, 한번이라도 거짓이었다면 거짓
            }
            else if ((str2[j - 1] == '?') || (str1[i - 1] == str2[j - 1])) {
                // 패턴에 ?가 입력되거나 패턴과 문자가 같으면
                T[i][j] = T[i - 1][j - 1]; // 지금까지 참이었으면 참, 한번이라도 거짓이었으면 거짓
            }
        }
    }
    // 데이터와 패턴의 길이가 0이 아니면 이 반복문을 돔

    return T[str_1_size][str_2_size];
    // 문자열과 패턴이 일치하면 true를 일치하지 않으면 false를 반환
}

void find_name(void) {
    // 패턴을 입력받아서 문자열과 일치하면 출력

    char data[100];
    char pattern[100];

    std::cout << "Enter the pattern: ";
    std::cin >> pattern;
    // 패턴을 입력받음

    while (!fin.eof()) {
        // 파일의 끝이 아니면 반복
        fin.getline(data, 100);
        // 파일로부터 한 줄씩 문자열을 입력받음
        if (match(data, pattern)) {
            // 문자열과 패턴이 일치하면
            std::cout << data << std::endl; // 문자열을 출력
        }
    }
    
    return;
    // 함수 종료
}

int main()
{
    int num;
    char* file_name = NULL;

    file_name = new char[100]; // 최대 100자의 문자를 받기 위해 메모리 할당

    std::cout << "Input file name: ";
    std::cin >> file_name;
    // 파일 이름을 입력받음

    fin.open(file_name);
    // 파일이 존재하는지 확인하기 위해 열음

    if (!fin) {
        // fin == 0
        std::cout << "Opening file failure" << std::endl;
        return -1;
    }
    // 파일을 찾지 못했을 경우 예외처리

    fin.close();
    // 파일이 존재하는지 확인만 하기 위해 열었으므로 다시 닫아줌

    std::cout << "Number of times to find: ";
    std::cin >> num;
    // 문자열을 몇 번 찾을지 입력받음

    if (num < 0) {
        std::cout << "The number entered is negative" << std::endl;
        return -1;
    }
    // 음수가 입력될 경우 예외처리

    while (num--) {
        // 입력 받은 숫자만큼 반복
        fin.open(file_name);
        // 파일을 열음
        find_name();
        // 문자열을 찾는 함수를 호출
        fin.close();
        // 파일을 닫음
    }

    delete[] file_name; // 메모리 해제

    return 0;
    // 정상적인 종료시
}