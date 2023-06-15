#include "my_string.h"
#include <cstring>

namespace my_oopstd
{
    // ���ڿ��� ���̸� ���ϴ� �Լ�
    size_t string_length(const char* s)
    {
        size_t len = 0;     // ���ڿ��� ���̸� ������ ����
        while (*s++)
        {
            ++len;      // ���ڿ��� ���̸� 1�� ����
        }
        return len;     // ���ڿ��� ���� ��ȯ
    }

    // ������
    my_string::my_string() : s(nullptr), len(0) {}

    // ���ڿ��� �޾Ƽ� my_string ��ü�� �����ϴ� ������
    my_string::my_string(const char* s)
    {
        len = string_length(s);     // ���ڿ��� ���̸� ����
        this->s = new char[len + 1];        // ���ڿ��� ���� + 1��ŭ ���� �Ҵ�
        for (size_t i = 0; i < len; ++i)
        {
            this->s[i] = s[i];
        }
        this->s[len] = '\0';        // ���ڿ��� ���� �� ���ڸ� �߰�
    }

    // ���� ������
    my_string::my_string(const my_string& str)
    {
        len = str.len;      // ���ڿ��� ���̸� ����
        s = new char[len + 1];	  // ���ڿ��� ���� + 1��ŭ ���� �Ҵ�
        for (size_t i = 0; i < len; ++i)
        {
            s[i] = str.s[i];        // ���ڿ��� ����
        }
        s[len] = '\0';      // ���ڿ��� ���� �� ���ڸ� �߰�
    }

    // �Ҹ���
    my_string::~my_string()
    {
        delete[] s;     // ���� �Ҵ��� �޸𸮸� ����
    }

    // ���� ������
    my_string& my_string::my_assign(const my_string& str)
    {
        // �ڱ� �ڽŰ��� ������ ����
        if (this == &str)
        {
            return *this;       // �ڱ� �ڽ��� ��ȯ
        }
        delete[] s;     // ���� �Ҵ��� �޸𸮸� ����

        len = str.len;
        s = new char[len + 1];      // ���ڿ��� ���� + 1��ŭ ���� �Ҵ�
        for (size_t i = 0; i < len; ++i)
        {
            s[i] = str.s[i];
        }
        s[len] = '\0';

        return *this;    // �ڱ� �ڽ��� ��ȯ
    }

    // pos ��ġ�� ���ڸ� ��ȯ�ϴ� �Լ�
    char& my_string::my_at(size_t pos)
    {
        return s[pos];      // pos ��ġ�� ���ڸ� ��ȯ
    }

    // ���ڿ��� ��ȯ�ϴ� �Լ�
    const char* my_string::my_c_str() const 
   {
        return s;       // ���ڿ��� ��ȯ
    }

    // ���ڿ��� ���� �Լ�
    void my_string::my_clear()
    {
        delete[] s;     // ���� �Ҵ��� �޸𸮸� ����
        s = nullptr;        // �����͸� �� �����ͷ� �ʱ�ȭ
        len = 0;        // ���ڿ��� ���̸� 0���� �ʱ�ȭ

        cout << "string is cleared" << endl;
    }

    // ���ڸ� �ڿ� �߰��ϴ� �Լ�
    void my_string::my_push_back(char c)
    {
        char* new_s = new char[len + 2];        // ���ڿ��� ���� + 1��ŭ ���� �Ҵ�
        for (size_t i = 0; i < len; ++i)
        {
            new_s[i] = s[i];
        }
        new_s[len] = c;     // ���ڸ� �߰�
        new_s[len + 1] = '\0';      // ���ڿ��� ���� �� ���ڸ� �߰�
        delete[] s;     // ���� �Ҵ��� �޸𸮸� ����
        s = new_s;      // ���� �Ҵ��� �޸𸮸� s�� ����
        ++len;      // ���ڿ��� ���̸� 1 ����
    }

    // ���ڿ��� ���ϴ� �Լ�
    int my_string::my_compare(const my_string* str) const
    {
        size_t i = 0;       // �ݺ������� ����� ����
        while (i < len && i < str->len)
        {
            if (s[i] < str->s[i])
            {
                return -1;      // s�� str���� ���������� �տ� ����
            }
            else if (s[i] > str->s[i])
            {
                return 1;       // s�� str���� ���������� �ڿ� ����
            }
            ++i;		// �ݺ����� ���ǽĿ� ����� ������ 1 ����
        }

        if (len < str->len)
        {
            return -1;      // s�� str���� ���������� �տ� ����
        }
        else if (len > str->len)
        {
            return 1;       // s�� str���� ���������� �ڿ� ����
        }

        return 0;       // s�� str�� ����
    }

    // ���ڿ��� �Ϻθ� �ٸ� ���ڿ��� ��ü�Ͽ� ��ȯ�ϴ� �Լ�
    my_string& my_string::my_replace(size_t pos, size_t len, const my_string* str)
    {
        if (pos >= this->len)
        {
			return *this;       // pos�� ���ڿ��� ���̺��� ũ�ų� ������ �ڱ� �ڽ��� ��ȯ
		}

        if (pos + len > this->len)
        {
			len = this->len - pos;      // len�� ���ڿ��� ���̸� �Ѿ�� len�� ���ڿ��� ���̿��� pos�� �� ������ ����
		}

		size_t new_len = this->len - len + str->len;        // ���ο� ���ڿ��� ���̸� ����
		char* new_s = new char[new_len + 1];        // ���ο� ���ڿ��� ���� + 1��ŭ ���� �Ҵ�
        for (size_t i = 0; i < pos; ++i)
        {
			new_s[i] = s[i];        // ���ڿ��� �߰�
		}

        for (size_t i = 0; i < str->len; ++i)
        {
			new_s[pos + i] = str->s[i];     // ���ڿ��� �߰�
		}

        for (size_t i = pos + len; i < this->len; ++i)
        {
			new_s[i + str->len - len] = s[i];       // ���ڿ��� �߰�
		}

		new_s[new_len] = '\0';
		delete[] s;     // ���� �Ҵ��� �޸𸮸� ����

		s = new_s;      // ���� �Ҵ��� �޸𸮸� s�� ����
		this->len = new_len;        // ���ڿ��� ���̸� ���ο� ���ڿ��� ���̷� ����
		return *this;       // �ڱ� �ڽ��� ��ȯ
    }

    // ���ڿ��� �Ϻθ� ��ȯ�ϴ� �Լ�
    my_string my_string::my_substr(size_t pos, size_t len) const
    {
        if (pos >= this->len)
        {
            return my_string();     // pos�� ���ڿ��� ���̺��� ũ�ų� ������ �� ���ڿ��� ��ȯ
        }

        if (pos + len > this->len)
        {
            len = this->len - pos;      // len�� ���ڿ��� ���̸� �Ѿ�� len�� ���ڿ��� ���̿��� pos�� �� ������ ����
        }

        my_string result;       // ��ȯ�� ���ڿ�
        result.len = len;       // ���ڿ��� ���̸� ����
        result.s = new char[len + 1];       // ���ڿ��� ���� + 1��ŭ ���� �Ҵ�

        for (size_t i = 0; i < len; ++i)
        {
            result.s[i] = s[pos + i];       // ���ڿ��� �߰�
        }

        result.s[len] = '\0';

        return result;      // ���ڿ��� ��ȯ
    }

    // ���ڿ����� ó�� str�� ������ ��ġ�� ��ȯ�ϴ� �Լ�
    size_t my_string::my_find(const my_string& str, size_t pos) const
    {
        if (pos >= this->len || str.len > this->len || str.len == 0)
        {
            return std::string::npos;       // pos�� ���ڿ��� ���̺��� ũ�ų� ���ų� ã�� ���ڿ��� ���̰� ���ڿ��� ���̺��� ũ�ų� ���ų� ã�� ���ڿ��� ���̰� 0�̸� npos�� ��ȯ
        }

        for (size_t i = pos; i <= this->len - str.len; ++i)
        {
            bool found = true;      // ���ڿ��� ã�Ҵ��� Ȯ���ϴ� ����
            for (size_t j = 0; j < str.len; ++j)
            {
                if (s[i + j] != str.s[j])
                {
                    found = false;      // ���ڿ��� ã�� ����
                    break;
                }
            }

            if (found)
            {
                return i;       // ���ڿ��� ã��
            }
        }

        return std::string::npos;       // ���ڿ��� ã�� ����
    }

    // ���ڿ��� int���� ���� ��ȯ�ϴ� �Լ�
    int my_stoi(const my_string& str, size_t* idx, int base)
    {
        size_t start = idx ? *idx : 0;      // idx�� nullptr�� �ƴϸ� idx�� ����Ű�� ���� start�� ����
        int result = 0;     // ��ȯ�� int���� ��
        bool negative = false;      // �������� Ȯ���ϴ� ����

        if (start >= str.len)
        {
            return 0;    // start�� ���ڿ��� ���̺��� ũ�ų� ������ 0�� ��ȯ
        }

        // �������� Ȯ��
        if (str.s[start] == '-')
        {
            negative = true;
            ++start;
        }
        // ������� Ȯ��
        else if (str.s[start] == '+')
        {
            ++start;
        }

        for (size_t i = start; i < str.len; ++i)
        {
            char c = str.s[i];      // ���ڿ��� ����
            int digit;      // ���ڿ��� ���ڸ� ���ڷ� ��ȯ�� ��

            // ���ڿ��� ���ڸ� ���ڷ� ��ȯ
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
                    *idx = i;       // idx�� nullptr�� �ƴϸ� idx�� ����Ű�� ���� i�� ����
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

            result = result * base + digit;     // result�� �ڸ�����ŭ�� ���� ����
        }

        return negative ? -result : result;     // ��ȣ�� ���� result�� ��ȯ
    }

    // ���ڿ��� float���� ���� ��ȯ�ϴ� �Լ�
    float my_stof(const my_string& str, size_t* idx)
    {
        size_t start = idx ? *idx : 0;      // idx�� nullptr�� �ƴϸ� idx�� ����Ű�� ���� start�� ����
        float result = 0;    // ��ȯ�� float���� ��
        bool negative = false;      // �������� Ȯ���ϴ� ����
        bool decimal = false;       // �Ҽ������� Ȯ���ϴ� ����
        float decimal_multiplier = 1;       // �Ҽ����� �ڸ���

        if (start >= str.len)
        {
            return 0.0f;        // start�� ���ڿ��� ���̺��� ũ�ų� ������ 0.0f�� ��ȯ
        }

        // �������� Ȯ��
        if (str.s[start] == '-')
        {
            negative = true;
            ++start;
        }
        // ������� Ȯ��
        else if (str.s[start] == '+')
        {
            ++start;
        }

        for (size_t i = start; i < str.len; ++i)
        {
            char c = str.s[i];      // ���ڿ��� ����

            // ���ڿ��� ���ڰ� �������� Ȯ��
            if (c >= '0' && c <= '9')
            {
                // �Ҽ����� �ƴ� ���
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
            // ���ڿ��� ���ڰ� �Ҽ������� Ȯ��
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

        return negative ? -result : result;     // ��ȣ�� ���� result�� ��ȯ
    }

    // �־��� int���� ���� ���ڿ��� �ٲٴ� �Լ�
    my_string my_to_string(int val)
    {
        bool negative = val < 0;		// �������� Ȯ���ϴ� ����
        // ������ ��� ����� �ٲ�
        if (negative)
        {
            val = -val;
        }

        char buffer[12];        // �ִ� ���̸� ���� int���� ���� ������ ����
        size_t pos = 0;     // ������ �ε���

        do
        {
            buffer[pos++] = '0' + val % 10;     // val�� ���� �ڸ��� ���ۿ� ����
            val /= 10;      // val�� ���� �ڸ��� ����
        } while (val > 0);      // val�� 0���� ũ�� �ݺ�

        if (negative)
        {
            buffer[pos++] = '-';
        }

        // ������ ���ڿ��� ������
        for (size_t i = 0; i < pos / 2; ++i)
        {
            char temp = buffer[i];
            buffer[i] = buffer[pos - 1 - i];
            buffer[pos - 1 - i] = temp;
        }

        buffer[pos] = '\0';     // ������ �������� �� ���ڸ� �߰�

        return my_string(buffer);       // ���۸� ���ڿ��� ��ȯ�Ͽ� ��ȯ
    }

    // �־��� float���� ���� ���ڿ��� �ٲٴ� �Լ�
    my_string my_to_string(float val)
    {
        char buffer[64]; // float���� ���� ������ ����
        snprintf(buffer, sizeof(buffer), "%.6g", val); // ���ۿ� val�� ���ڿ��� ���� ��ȿ���ڸ� 6�ڸ��� ����
        return my_string(buffer);       // ���۸� ���ڿ��� ��ȯ�Ͽ� ��ȯ
    }
}