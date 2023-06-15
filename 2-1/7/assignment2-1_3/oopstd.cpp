// 이 소스파일은 oopstd.h 헤더에서 선언한 namespace 속 함수들의 내용을 적어준 파일이다
#include <iostream>
#include "oopstd.h" // oopstd 헤더파일을 include
using namespace std;

void* oopstd::memset(void* ptr, int value, size_t num) // ptr을 value로 num만큼 바꿔주는 함수
{
    char* str = (char*)ptr; // void 형태의 ptr을 char* 형태의 str에 넣어주기 위해 (char*)를 이용하여 자료형을 바꿔준다
    char c = (char)value; // 마찬가지로 (char)을 이용하여 자료형을 바꿔준다
    for (size_t i = 0; i < num; i++) // int i가 아닌이유는 두가지가 있다. 하나는 문법적인 내용인데 만약에 num이 int 범위를 넘어가는 크기면
        // int i로 했을때 overflow가 발생한다. 참고로 size_t는 int보다 범위가 크다(컴파일러마다 다른데 일반적으로 unsigned long long)
        // 두번째 이유는 관례적인 이윤데, 일반적으로 크기를 표현할때는 unsigned를 사용하는데 size_t는 int와 다르게 unsigned다.
        str[i] = c;
    return ptr;
}

void* oopstd::memcpy(void* destination, const void* source, size_t num) // destination에 source를 num만큼 복사해주는 함수
{
    char* de = (char*)destination;
    char* so = (char*)source;
    for (size_t i = 0; i < num; i++)
        de[i] = so[i]; // memset과 같은 방식인데 단지 value 대신에 source가 들어가는 차이뿐이다
    return de;
}

int oopstd::strcmp(const char* str1, const char* str2) // 인자로 받은 두 배열이 같은 배열인지를 비교해주는 함수
{
    while (*str1 && *str2) // 일단 *str1과 *str2가 모두 0이 아니여야 한다. 중간에 누군가 문자열이 끊기면(널) 바로 반복문을 벗어난다
    {
        if (*str1 != *str2) // *str1과 * str2가 다르면
            return ((unsigned char)*str1 - (unsigned char)*str2); // 바로 차이값을 반환한다. str1이 더크면 양의 값, str2가 더 크면 음의 값이 나올 것이다
        str1++; // 같다면 다음 포인터로 넘어간다
        str2++;
    }
    return ((unsigned char)*str1 - (unsigned char)*str2); // while문을 최종적으로 문제없이 빠져나오면 최종적인 차이값을 반환해준다
}

int oopstd::strncmp(const char* str1, const char* str2, size_t num) // strcmp와 같은데 단지 조건에 num이 추가 되는 것이다
{
    if (!num) // 일단 num이 0이면
        return 0; // 바로 0을 반환한다. 실제로 strncmp에서 0개의 문자를 비교하면 반드시 0을 출력해준다
    else
    {
        while (*str1 && *str2 && --num) // 차이점은 한글자 비교해줄때마다 num을 1씩 감소시킨다는 것이다. num이 0이 되면 자연스럽게 while문을 빠져나간다
        {
            if (*str1 != *str2)
                return ((unsigned char)*str1 - (unsigned char)*str2);
            str1++;
            str2++;
        }
    }
    return ((unsigned char)*str1 - (unsigned char)*str2);
}

char* oopstd::strcpy(char* destination, const char* source) // strcpy는 destination에 source를 복사해주는 함수다
{
    int len = oopstd::strlen(source) + 1; // 길이는 널문자를 생각해서 1을 더해줘야한다(strlen은 널 전까지 계산해주므로)
    for (int i = 0; i < len; i++) // 나머지는 memcpy와 같다. memcpy의 차이점은 인자의 자료형이 void*가 아니라 char*라는 것이다. 따라서 굳이 자료형을 변환해줄 필요가 없다
        destination[i] = source[i];
    return destination;
}

char* oopstd::strncpy(char* destination, const char* source, size_t num) // strcpy와 같은데, num이 추가된다. num만큼 복사해준다
{
    int len = oopstd::strlen(source) + 1;
    if (len > num) // 항상 길이가 더 짧은 인자를 선택해서 복사해준다.
        len = num; // len이 더 크다면 num만큼 복사해주고, num이 더 크다면 len만큼 복사해주는 것이다
    for (int i = 0; i < len; i++)
        destination[i] = source[i];
    if (len < num) // strncpy는 만약에 source의 길이가 num보다 크면 널 문자를 넣어주지 않지만, source의 길이가 num보다 작으면 num까지는 계속 널을 채워줘야 한다
        while (len == num)
            destination[len++] = '\0';
    return destination;
}

size_t oopstd::strlen(const char* str) // strlen은 길이 계산 함수다
{
    size_t len = 0;
    for (int i = 0; str[i] != '\0'; i++) // 문자열의 끝은 널문자이므로 널문자를 만나기 전까지 len을 계속 더해준다
        len++; // 이때 strlen은 널문자전까지 계산하므로 널문자를 생각해서 1을 더 더해주지 않아도 된다
    return len;
}

int oopstd::atoi(const char* str) // atoi는 자료형을 문자열에서 숫자(정수형)으로 바꿔주는 함수다
{
    int result = 0;
    int sign = 1; // 부호(아무 부호도 안 붙어있으면 양수이므로 일단 기본 부호는 양수)
    while ((*str >= 9 && *str <= 13) || *str == ' ') // 9, 10, 11, 12, 13은 공백, 개행 등 white space를 의미하는 아스키 코드다.
        str++; // atoi 함수는 처음 등장하는 white space는 무시하기 때문에 white space가 없을때까지 건너뛴다
    if (*str == '+' || *str == '-') // 만약에 부호가 등장하면(처음에 -30, +300 이런식의 값의 부호를 결정하는 부호)
    {
        if (*str == '-') // -면
            sign = -1; // 부호 변수에 -1을 넣어준다. +나, 아무 부호도 없는 경우는 +이므로 무시해도 된
        str++;
    }
    while (*str >= '0' && *str <= '9') // 숫자가 등장할 경우
    {
        result *= 10; // 처음 숫자를 찾았을때는 10이 곱해지면 안되기 때문에 처음 result를 0으로 잡아준다
        result += (*str - '0') * sign;
        // 여기서 sign을 최종적으로 구한 result에 곱해줘도 되는데 굳이 이렇게 계산할때 곱해주는 이유
        // n비트에서 overflow가 발생하지 않는 범위가 [-2^n, 2^n-1]인데, 만약에 값이 -2^n이라고 한다면 overflow가 발생하지 않는다.
        // 근데 만약에 result를 먼저 구하고 부호를 씌워주면 씌우기 전 result가 128이 나와 overflow가 발생하게 된다.
        // 대신에 값을 더할때마다 부호를 곱해줘서 더하면 정상적으로 -128이 나오기 때문에 overflow가 발생하지 않게된다. 이를 위해서 더할때마다 부호를 곱해주는 것이다.
        str++;
    }
    return result;
}

float oopstd::atof(const char* str) // atof는 atoi와 같은 기능인데 정수형이 아니라 실수형으로 바꿔준다. 
                                    // 따라서 변수의 자료형과 코드에서 소수점을 만났을 경우만 고려해주면 된다
{
    float result = 0;
    int sign = 1;
    bool dot = 0; // bool형 소수점 변수
    float dotcal = 1.0; // 계산할때 자료형 맞춰주기 위해 float으로 선언(소수점 계산용 변수)
    while ((*str >= 9 && *str <= 13) || *str == ' ')
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while ((*str >= '0' && *str <= '9') || *str == '.')
    {
        if (*str == '.') // 만약에 소수점을 만나면
        {
            // if (dot) --> .이 연속으로 나오는경우(예외)
               // return result;
            dot = 1; // 소수점 변수를 1로 해준다
            str++;
            continue;
        }
        if (dot) // 소수점 변수가 1이면
        {
            dotcal /= 10.0; // dotcal을 10으로 나눠주고
            result += (*str - '0') * dotcal * sign; // 더할때 dotcal을 곱해서 더해준다.
            // 예를 들어 소수점 아래 한자리수면 0.1이 곱해지고, 소수점 아래 두자리수면 0.01이 곱해지고...이런 식
            str++;
        }
        else
        {
            result *= 10;
            result += (*str - '0') * sign;
            str++;
        }
    }
    return result;
    // 추가적으로, atof 함수의 경우, 중간에 공백을 만나면 그 전까지만 출력을 해준다. 그것 역시 구현돼있다. while(숫자 || 소수점)을 만족하지 않으므로 바로 result를 return해주기 때문이다
}