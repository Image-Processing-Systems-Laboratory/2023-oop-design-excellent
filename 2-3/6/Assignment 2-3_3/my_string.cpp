#include "my_string.h"
#include <cstring>

namespace my_oopstd
{
    // 문자열의 길이를 구하는 함수
    size_t string_length(const char* s)
    {
        size_t len = 0;     // 문자열의 길이를 저장할 변수
        while (*s++)
        {
            ++len;      // 문자열의 길이를 1씩 증가
        }
        return len;     // 문자열의 길이 반환
    }

    // 생성자
    my_string::my_string() : s(nullptr), len(0) {}

    // 문자열을 받아서 my_string 객체를 생성하는 생성자
    my_string::my_string(const char* s)
    {
        len = string_length(s);     // 문자열의 길이를 구함
        this->s = new char[len + 1];        // 문자열의 길이 + 1만큼 동적 할당
        for (size_t i = 0; i < len; ++i)
        {
            this->s[i] = s[i];
        }
        this->s[len] = '\0';        // 문자열의 끝에 널 문자를 추가
    }

    // 복사 생성자
    my_string::my_string(const my_string& str)
    {
        len = str.len;      // 문자열의 길이를 구함
        s = new char[len + 1];	  // 문자열의 길이 + 1만큼 동적 할당
        for (size_t i = 0; i < len; ++i)
        {
            s[i] = str.s[i];        // 문자열을 복사
        }
        s[len] = '\0';      // 문자열의 끝에 널 문자를 추가
    }

    // 소멸자
    my_string::~my_string()
    {
        delete[] s;     // 동적 할당한 메모리를 해제
    }

    // 대입 연산자
    my_string& my_string::my_assign(const my_string& str)
    {
        // 자기 자신과의 대입을 방지
        if (this == &str)
        {
            return *this;       // 자기 자신을 반환
        }
        delete[] s;     // 동적 할당한 메모리를 해제

        len = str.len;
        s = new char[len + 1];      // 문자열의 길이 + 1만큼 동적 할당
        for (size_t i = 0; i < len; ++i)
        {
            s[i] = str.s[i];
        }
        s[len] = '\0';

        return *this;    // 자기 자신을 반환
    }

    // pos 위치의 문자를 반환하는 함수
    char& my_string::my_at(size_t pos)
    {
        return s[pos];      // pos 위치의 문자를 반환
    }

    // 문자열을 반환하는 함수
    const char* my_string::my_c_str() const 
   {
        return s;       // 문자열을 반환
    }

    // 문자열을 비우는 함수
    void my_string::my_clear()
    {
        delete[] s;     // 동적 할당한 메모리를 해제
        s = nullptr;        // 포인터를 널 포인터로 초기화
        len = 0;        // 문자열의 길이를 0으로 초기화

        cout << "string is cleared" << endl;
    }

    // 문자를 뒤에 추가하는 함수
    void my_string::my_push_back(char c)
    {
        char* new_s = new char[len + 2];        // 문자열의 길이 + 1만큼 동적 할당
        for (size_t i = 0; i < len; ++i)
        {
            new_s[i] = s[i];
        }
        new_s[len] = c;     // 문자를 추가
        new_s[len + 1] = '\0';      // 문자열의 끝에 널 문자를 추가
        delete[] s;     // 동적 할당한 메모리를 해제
        s = new_s;      // 새로 할당한 메모리를 s에 저장
        ++len;      // 문자열의 길이를 1 증가
    }

    // 문자열을 비교하는 함수
    int my_string::my_compare(const my_string* str) const
    {
        size_t i = 0;       // 반복문에서 사용할 변수
        while (i < len && i < str->len)
        {
            if (s[i] < str->s[i])
            {
                return -1;      // s가 str보다 사전순으로 앞에 있음
            }
            else if (s[i] > str->s[i])
            {
                return 1;       // s가 str보다 사전순으로 뒤에 있음
            }
            ++i;		// 반복문의 조건식에 사용할 변수를 1 증가
        }

        if (len < str->len)
        {
            return -1;      // s가 str보다 사전순으로 앞에 있음
        }
        else if (len > str->len)
        {
            return 1;       // s가 str보다 사전순으로 뒤에 있음
        }

        return 0;       // s와 str이 같음
    }

    // 문자열의 일부를 다른 문자열로 대체하여 반환하는 함수
    my_string& my_string::my_replace(size_t pos, size_t len, const my_string* str)
    {
        if (pos >= this->len)
        {
			return *this;       // pos가 문자열의 길이보다 크거나 같으면 자기 자신을 반환
		}

        if (pos + len > this->len)
        {
			len = this->len - pos;      // len이 문자열의 길이를 넘어가면 len을 문자열의 길이에서 pos를 뺀 값으로 변경
		}

		size_t new_len = this->len - len + str->len;        // 새로운 문자열의 길이를 구함
		char* new_s = new char[new_len + 1];        // 새로운 문자열의 길이 + 1만큼 동적 할당
        for (size_t i = 0; i < pos; ++i)
        {
			new_s[i] = s[i];        // 문자열을 추가
		}

        for (size_t i = 0; i < str->len; ++i)
        {
			new_s[pos + i] = str->s[i];     // 문자열을 추가
		}

        for (size_t i = pos + len; i < this->len; ++i)
        {
			new_s[i + str->len - len] = s[i];       // 문자열을 추가
		}

		new_s[new_len] = '\0';
		delete[] s;     // 동적 할당한 메모리를 해제

		s = new_s;      // 새로 할당한 메모리를 s에 저장
		this->len = new_len;        // 문자열의 길이를 새로운 문자열의 길이로 변경
		return *this;       // 자기 자신을 반환
    }

    // 문자열의 일부를 반환하는 함수
    my_string my_string::my_substr(size_t pos, size_t len) const
    {
        if (pos >= this->len)
        {
            return my_string();     // pos가 문자열의 길이보다 크거나 같으면 빈 문자열을 반환
        }

        if (pos + len > this->len)
        {
            len = this->len - pos;      // len이 문자열의 길이를 넘어가면 len을 문자열의 길이에서 pos를 뺀 값으로 변경
        }

        my_string result;       // 반환할 문자열
        result.len = len;       // 문자열의 길이를 설정
        result.s = new char[len + 1];       // 문자열의 길이 + 1만큼 동적 할당

        for (size_t i = 0; i < len; ++i)
        {
            result.s[i] = s[pos + i];       // 문자열을 추가
        }

        result.s[len] = '\0';

        return result;      // 문자열을 반환
    }

    // 문자열에서 처음 str이 나오는 위치를 반환하는 함수
    size_t my_string::my_find(const my_string& str, size_t pos) const
    {
        if (pos >= this->len || str.len > this->len || str.len == 0)
        {
            return std::string::npos;       // pos가 문자열의 길이보다 크거나 같거나 찾을 문자열의 길이가 문자열의 길이보다 크거나 같거나 찾을 문자열의 길이가 0이면 npos를 반환
        }

        for (size_t i = pos; i <= this->len - str.len; ++i)
        {
            bool found = true;      // 문자열을 찾았는지 확인하는 변수
            for (size_t j = 0; j < str.len; ++j)
            {
                if (s[i + j] != str.s[j])
                {
                    found = false;      // 문자열을 찾지 못함
                    break;
                }
            }

            if (found)
            {
                return i;       // 문자열을 찾음
            }
        }

        return std::string::npos;       // 문자열을 찾지 못함
    }

    // 문자열의 int형의 값을 반환하는 함수
    int my_stoi(const my_string& str, size_t* idx, int base)
    {
        size_t start = idx ? *idx : 0;      // idx가 nullptr이 아니면 idx가 가리키는 값을 start에 저장
        int result = 0;     // 반환할 int형의 값
        bool negative = false;      // 음수인지 확인하는 변수

        if (start >= str.len)
        {
            return 0;    // start가 문자열의 길이보다 크거나 같으면 0을 반환
        }

        // 음수인지 확인
        if (str.s[start] == '-')
        {
            negative = true;
            ++start;
        }
        // 양수인지 확인
        else if (str.s[start] == '+')
        {
            ++start;
        }

        for (size_t i = start; i < str.len; ++i)
        {
            char c = str.s[i];      // 문자열의 문자
            int digit;      // 문자열의 문자를 숫자로 변환한 값

            // 문자열의 문자를 숫자로 변환
            if (c >= '0' && c <= '9')
            {
                digit = c - '0';
            }
            else if (c >= 'A' && c <= 'Z')
            {
                digit = c - 'A' + 10;
            }
            else if (c >= 'a' && c <= 'z')
            {
                digit = c - 'a' + 10;
            }
            else
            {
                if (idx)
                {
                    *idx = i;       // idx가 nullptr이 아니면 idx가 가리키는 값을 i로 변경
                }
                break;
            }

            if (digit >= base)
            {
                if (idx)
                {
                    *idx = i;
                }
                break;
            }

            result = result * base + digit;     // result에 자릿수만큼의 수를 저장
        }

        return negative ? -result : result;     // 부호에 따라 result를 반환
    }

    // 문자열의 float형의 값을 반환하는 함수
    float my_stof(const my_string& str, size_t* idx)
    {
        size_t start = idx ? *idx : 0;      // idx가 nullptr이 아니면 idx가 가리키는 값을 start에 저장
        float result = 0;    // 반환할 float형의 값
        bool negative = false;      // 음수인지 확인하는 변수
        bool decimal = false;       // 소수점인지 확인하는 변수
        float decimal_multiplier = 1;       // 소수점의 자릿수

        if (start >= str.len)
        {
            return 0.0f;        // start가 문자열의 길이보다 크거나 같으면 0.0f를 반환
        }

        // 음수인지 확인
        if (str.s[start] == '-')
        {
            negative = true;
            ++start;
        }
        // 양수인지 확인
        else if (str.s[start] == '+')
        {
            ++start;
        }

        for (size_t i = start; i < str.len; ++i)
        {
            char c = str.s[i];      // 문자열의 문자

            // 문자열의 문자가 숫자인지 확인
            if (c >= '0' && c <= '9')
            {
                // 소수점이 아닌 경우
                if (!decimal)
                {
                    result = result * 10 + (c - '0');
                }
                else
                {
                    decimal_multiplier /= 10;
                    result += decimal_multiplier * (c - '0');
                }
            }
            // 문자열의 문자가 소수점인지 확인
            else if (c == '.' && !decimal)
            {
                decimal = true;
            }
            else
            {
                if (idx)
                {
                    *idx = i;
                }
                break;
            }
        }

        return negative ? -result : result;     // 부호에 따라 result를 반환
    }

    // 주어진 int형의 수를 문자열로 바꾸는 함수
    my_string my_to_string(int val)
    {
        bool negative = val < 0;		// 음수인지 확인하는 변수
        // 음수인 경우 양수로 바꿈
        if (negative)
        {
            val = -val;
        }

        char buffer[12];        // 최대 길이를 가진 int형의 수를 저장할 버퍼
        size_t pos = 0;     // 버퍼의 인덱스

        do
        {
            buffer[pos++] = '0' + val % 10;     // val의 일의 자리를 버퍼에 저장
            val /= 10;      // val의 일의 자리를 제거
        } while (val > 0);      // val이 0보다 크면 반복

        if (negative)
        {
            buffer[pos++] = '-';
        }

        // 버퍼의 문자열을 뒤집음
        for (size_t i = 0; i < pos / 2; ++i)
        {
            char temp = buffer[i];
            buffer[i] = buffer[pos - 1 - i];
            buffer[pos - 1 - i] = temp;
        }

        buffer[pos] = '\0';     // 버퍼의 마지막에 널 문자를 추가

        return my_string(buffer);       // 버퍼를 문자열로 변환하여 반환
    }

    // 주어진 float형의 값을 문자열로 바꾸는 함수
    my_string my_to_string(float val)
    {
        char buffer[64]; // float형의 값을 저장할 버퍼
        snprintf(buffer, sizeof(buffer), "%.6g", val); // 버퍼에 val을 문자열로 저장 유효숫자를 6자리로 제한
        return my_string(buffer);       // 버퍼를 문자열로 변환하여 반환
    }
}