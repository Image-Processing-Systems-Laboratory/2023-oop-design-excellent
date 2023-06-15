#include "NestedArray.h"
#include <iostream>

// 문자열 비교 strncmp
int compareString(const char* str1, const char* str2, size_t num)
{
    int i = 0;
    while (i < num - 1)
    {
        if (!str1[i] || !str2[i] || str1[i] != str2[i])	break;
        i++;
    }
    return ((str1[i] - str2[i]) ? ((str1[i] > str2[i]) ? 1 : -1) : 0);
}

// 문자열을 정수로 변환 atoi
int stringToInt(const char* str)
{
    int i = 0, result = 0, minus = 0;
    
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
    {
        i++;
    }
    
    if (str[i] == '-')
    {
        minus = 1;
        i++;
    }
    else if (str[i] == '+') i++;
    
    while (str[i] >= '0' && str[i] <= '9')
    {
        result *= 10;
        result += (str[i] - '0');
        i++;
    }
    return (minus ? -result : result);
}

// start부터 end까지 배열 출력
void printNestedArray(NestedArray* start, NestedArray* end)
{
    // 시작 지점이 NULL이면 중단
    if (!start) return;
    // 포인터를 시작 배열로 이동
    NestedArray* ptr = start;
    // 출력
    while (ptr != end && ptr)
    {
        // 문자열이면 출력
        if (ptr->isString())
        {
            std::cout << (char*)(ptr->getElement());
        }
        else
        {
            // 요소가 있는 배열일 경우
            if (ptr->getElement())
            {
                // 포인터를 요소로 이동 후 다시 확인
                ptr = (NestedArray*)(ptr->getElement());
                std::cout << "[";
                continue;
            }
        }

        // 출력이 끝났으면 다음 배열로
        if (ptr->getNextArray())
        {
            ptr = ptr->getNextArray();
            if (ptr != end)   std::cout << ", ";
        }
        // 다음 배열이 없을 경우 상위 배열로 이동
        else
        {
            // 다음 배열이 있는 상위 배열까지 이동
            while (!(ptr->getNextArray()))
            {
                ptr = ptr->getParentArray();
                if (!ptr || ptr == end)   break;
                std::cout << "]";
            }
            // 다음 배열로 이동
            if (ptr != end && ptr)
            {
                ptr = ptr->getNextArray();
                if (ptr != end)   std::cout << ", ";
            }
        }
    }
    // 출력이 끝나면 개행
    std::cout << std::endl;
}

int main()
{
    // 참일 경우 문자열이 알파벳만 수용 | 기본값 true
    const bool ALPHABET_ONLY = true;
    // 버퍼의 크기 | 문자열 & 명령어 | 기본값 20 + 1
    const int BUFFER_SIZE = 21;
    // 다용도
    int i = 0;
    // 배열 생성 시 잘 닫혀있는지 추적하는 변수
    int check = 0;
    // 입력 버퍼
    char buffer[BUFFER_SIZE];
    char input;
    // 최상위 배열
    NestedArray* top = new NestedArray;
    // 포인터
    NestedArray* ptr = top;

    // 파싱
    while (1)
    {
        // 한 글자씩 입력
        input = std::cin.get();

        // 첫 번째 줄이 끝날 경우 입력 종료
        if (input == '\n')  break;
        // 배열의 시작
        else if (input == '[')
        {
            // 하위 배열 생성 및 포인터 이동
            ptr = ptr->createArrayElement();
            check++;
        }
        // 배열의 끝
        else if (input == ']')
        {
            // 문자열 입력 중이었다면 마무리
            if (i)
            {
                buffer[i++] = NULL;
                ptr->createStringElement(buffer, i);
                i = 0;
            }
            else
            {
                // 버퍼가 빈 경우 값을 넣기 위해 미리 할당해둔 배열 삭제
                if (ptr && ptr->getPreviousArray())
                {
                    // 비어있지만 혹시 모르니 일단 요소 삭제
                    ptr->deleteElement();
                    // 삭제 전 포인터를 이전 배열로 이동
                    ptr = ptr->getPreviousArray();
                    // 이유를 알 수 없는 C6011
                    delete ptr->getNextArray();
                    ptr->setNextArray(0);
                }
            }
            // 상위 배열로 이동
            if (ptr && ptr->getParentArray())
            {
                ptr = ptr->getParentArray();
                check--;
            }
            // 최상위 배열이 아닐 경우 다음 배열 생성
            if (ptr != top)
            {
                ptr = ptr->createNextArray();
            }
        }
        // 요소 구분
        else if (input == ',' || i >= BUFFER_SIZE)
        {
            // 입력 버퍼가 가득 찰 경우 경고
            if (i >= BUFFER_SIZE)   std::cout << "Buffer overrun detected. The maximum number of characters is " << BUFFER_SIZE - 1 << ".\n";
            // 버퍼에 뭔가 있을 경우 문자열 요소 생성
            if (i)
            {
                buffer[i++] = NULL;
                ptr->createStringElement(buffer, i);
                ptr = ptr->createNextArray();
                i = 0;
            }
        }
        // 입력 버퍼
        else
        {
            // 알파벳 대문자와 소문자만 받을 경우
            if (ALPHABET_ONLY)
            {
                // 값 확인 후 버퍼에 추가
                if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))   buffer[i++] = input;
            }
            // 덤
            else    buffer[i++] = input;
        }
    }

    // 배열 닫힘 확인
    if (check != 0)
    {
        std::cout << "Invalid Array. Enter 'exit' to exit.\n";
    }
    
    // 배열 접근
    while (1)
    {
        // 입력
        std::cin.getline(buffer, 5);

        // 입력이 exit인 경우 종료
        if (!compareString(buffer, "exit", 4))
        {
            break;
        }
        // 입력이 arr인 경우 전체 출력
        else if (!compareString(buffer, "arr", 4))
        {
            printNestedArray(top, 0);
        }
        // 입력이 arr[인 경우
        else if (!compareString(buffer, "arr[", 4))
        {
            ptr = top;
            std::cin.clear();
            input = '[';
            while (1)
            {
                // '['가 들어온 경우 포인터 이동
                if (input == '[')
                {
                    // [가 들어오면 하위 배열로 접근
                    if (ptr->getElement())  ptr = (NestedArray*)(ptr->getElement());
                    else
                    {
                        // 하위 배열 없을 경우 돌아감
                        std::cout << "Unable to access the array.\n";
                        break;
                    }
                    // [ 다음에 오는 숫자들 입력 받은 뒤 정수로 변환
                    std::cin.getline(buffer, BUFFER_SIZE, ']');
                    i = stringToInt(buffer);
                    // 포인터 이동
                    for (; i > 0; i--)
                    {
                        // 다음 배열이 있을 경우 이동
                        if (ptr->getNextArray())    ptr = ptr->getNextArray();
                        else
                        {
                            // 없을 경우 아래 if (i) break;를 통해 돌아감
                            std::cout << "Unable to access the array.\n";
                            break;
                        }
                    }
                    // 접근 불가능할 경우 돌아감
                    if (i)  break;
                }
                // 개행 문자가 들어온 경우 출력
                else if (input == '\n')
                {
                    // 다음 배열이 있는 경우 포인터부터 다음 배열까지 출력
                    if (ptr->getNextArray())    printNestedArray(ptr, ptr->getNextArray());
                    // 다음 배열이 없는 경우 포인터부터 상위 배열까지 출력
                    else    printNestedArray(ptr, ptr->getParentArray());
                    // 출력 후 돌아감
                    break;
                }

                // 한 글자씩 입력
                input = std::cin.get();
            }
        }
        // 혹시 모를 오류 무시용
        std::cin.clear();
    }
    
    // 배열 제거
    top->deleteElement();
    delete top;

    // 종료
    return 0;
}