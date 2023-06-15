// �� �ҽ������� oopstd.h ������� ������ namespace �� �Լ����� ������ ������ �����̴�
#include <iostream>
#include "oopstd.h" // oopstd ��������� include
using namespace std;

void* oopstd::memset(void* ptr, int value, size_t num) // ptr�� value�� num��ŭ �ٲ��ִ� �Լ�
{
    char* str = (char*)ptr; // void ������ ptr�� char* ������ str�� �־��ֱ� ���� (char*)�� �̿��Ͽ� �ڷ����� �ٲ��ش�
    char c = (char)value; // ���������� (char)�� �̿��Ͽ� �ڷ����� �ٲ��ش�
    for (size_t i = 0; i < num; i++) // int i�� �ƴ������� �ΰ����� �ִ�. �ϳ��� �������� �����ε� ���࿡ num�� int ������ �Ѿ�� ũ���
        // int i�� ������ overflow�� �߻��Ѵ�. ����� size_t�� int���� ������ ũ��(�����Ϸ����� �ٸ��� �Ϲ������� unsigned long long)
        // �ι�° ������ �������� ������, �Ϲ������� ũ�⸦ ǥ���Ҷ��� unsigned�� ����ϴµ� size_t�� int�� �ٸ��� unsigned��.
        str[i] = c;
    return ptr;
}

void* oopstd::memcpy(void* destination, const void* source, size_t num) // destination�� source�� num��ŭ �������ִ� �Լ�
{
    char* de = (char*)destination;
    char* so = (char*)source;
    for (size_t i = 0; i < num; i++)
        de[i] = so[i]; // memset�� ���� ����ε� ���� value ��ſ� source�� ���� ���̻��̴�
    return de;
}

int oopstd::strcmp(const char* str1, const char* str2) // ���ڷ� ���� �� �迭�� ���� �迭������ �����ִ� �Լ�
{
    while (*str1 && *str2) // �ϴ� *str1�� *str2�� ��� 0�� �ƴϿ��� �Ѵ�. �߰��� ������ ���ڿ��� �����(��) �ٷ� �ݺ����� �����
    {
        if (*str1 != *str2) // *str1�� * str2�� �ٸ���
            return ((unsigned char)*str1 - (unsigned char)*str2); // �ٷ� ���̰��� ��ȯ�Ѵ�. str1�� ��ũ�� ���� ��, str2�� �� ũ�� ���� ���� ���� ���̴�
        str1++; // ���ٸ� ���� �����ͷ� �Ѿ��
        str2++;
    }
    return ((unsigned char)*str1 - (unsigned char)*str2); // while���� ���������� �������� ���������� �������� ���̰��� ��ȯ���ش�
}

int oopstd::strncmp(const char* str1, const char* str2, size_t num) // strcmp�� ������ ���� ���ǿ� num�� �߰� �Ǵ� ���̴�
{
    if (!num) // �ϴ� num�� 0�̸�
        return 0; // �ٷ� 0�� ��ȯ�Ѵ�. ������ strncmp���� 0���� ���ڸ� ���ϸ� �ݵ�� 0�� ������ش�
    else
    {
        while (*str1 && *str2 && --num) // �������� �ѱ��� �����ٶ����� num�� 1�� ���ҽ�Ų�ٴ� ���̴�. num�� 0�� �Ǹ� �ڿ������� while���� ����������
        {
            if (*str1 != *str2)
                return ((unsigned char)*str1 - (unsigned char)*str2);
            str1++;
            str2++;
        }
    }
    return ((unsigned char)*str1 - (unsigned char)*str2);
}

char* oopstd::strcpy(char* destination, const char* source) // strcpy�� destination�� source�� �������ִ� �Լ���
{
    int len = oopstd::strlen(source) + 1; // ���̴� �ι��ڸ� �����ؼ� 1�� ��������Ѵ�(strlen�� �� ������ ������ֹǷ�)
    for (int i = 0; i < len; i++) // �������� memcpy�� ����. memcpy�� �������� ������ �ڷ����� void*�� �ƴ϶� char*��� ���̴�. ���� ���� �ڷ����� ��ȯ���� �ʿ䰡 ����
        destination[i] = source[i];
    return destination;
}

char* oopstd::strncpy(char* destination, const char* source, size_t num) // strcpy�� ������, num�� �߰��ȴ�. num��ŭ �������ش�
{
    int len = oopstd::strlen(source) + 1;
    if (len > num) // �׻� ���̰� �� ª�� ���ڸ� �����ؼ� �������ش�.
        len = num; // len�� �� ũ�ٸ� num��ŭ �������ְ�, num�� �� ũ�ٸ� len��ŭ �������ִ� ���̴�
    for (int i = 0; i < len; i++)
        destination[i] = source[i];
    if (len < num) // strncpy�� ���࿡ source�� ���̰� num���� ũ�� �� ���ڸ� �־����� ������, source�� ���̰� num���� ������ num������ ��� ���� ä����� �Ѵ�
        while (len == num)
            destination[len++] = '\0';
    return destination;
}

size_t oopstd::strlen(const char* str) // strlen�� ���� ��� �Լ���
{
    size_t len = 0;
    for (int i = 0; str[i] != '\0'; i++) // ���ڿ��� ���� �ι����̹Ƿ� �ι��ڸ� ������ ������ len�� ��� �����ش�
        len++; // �̶� strlen�� �ι��������� ����ϹǷ� �ι��ڸ� �����ؼ� 1�� �� �������� �ʾƵ� �ȴ�
    return len;
}

int oopstd::atoi(const char* str) // atoi�� �ڷ����� ���ڿ����� ����(������)���� �ٲ��ִ� �Լ���
{
    int result = 0;
    int sign = 1; // ��ȣ(�ƹ� ��ȣ�� �� �پ������� ����̹Ƿ� �ϴ� �⺻ ��ȣ�� ���)
    while ((*str >= 9 && *str <= 13) || *str == ' ') // 9, 10, 11, 12, 13�� ����, ���� �� white space�� �ǹ��ϴ� �ƽ�Ű �ڵ��.
        str++; // atoi �Լ��� ó�� �����ϴ� white space�� �����ϱ� ������ white space�� ���������� �ǳʶڴ�
    if (*str == '+' || *str == '-') // ���࿡ ��ȣ�� �����ϸ�(ó���� -30, +300 �̷����� ���� ��ȣ�� �����ϴ� ��ȣ)
    {
        if (*str == '-') // -��
            sign = -1; // ��ȣ ������ -1�� �־��ش�. +��, �ƹ� ��ȣ�� ���� ���� +�̹Ƿ� �����ص� ��
        str++;
    }
    while (*str >= '0' && *str <= '9') // ���ڰ� ������ ���
    {
        result *= 10; // ó�� ���ڸ� ã�������� 10�� �������� �ȵǱ� ������ ó�� result�� 0���� ����ش�
        result += (*str - '0') * sign;
        // ���⼭ sign�� ���������� ���� result�� �����൵ �Ǵµ� ���� �̷��� ����Ҷ� �����ִ� ����
        // n��Ʈ���� overflow�� �߻����� �ʴ� ������ [-2^n, 2^n-1]�ε�, ���࿡ ���� -2^n�̶�� �Ѵٸ� overflow�� �߻����� �ʴ´�.
        // �ٵ� ���࿡ result�� ���� ���ϰ� ��ȣ�� �����ָ� ����� �� result�� 128�� ���� overflow�� �߻��ϰ� �ȴ�.
        // ��ſ� ���� ���Ҷ����� ��ȣ�� �����༭ ���ϸ� ���������� -128�� ������ ������ overflow�� �߻����� �ʰԵȴ�. �̸� ���ؼ� ���Ҷ����� ��ȣ�� �����ִ� ���̴�.
        str++;
    }
    return result;
}

float oopstd::atof(const char* str) // atof�� atoi�� ���� ����ε� �������� �ƴ϶� �Ǽ������� �ٲ��ش�. 
                                    // ���� ������ �ڷ����� �ڵ忡�� �Ҽ����� ������ ��츸 ������ָ� �ȴ�
{
    float result = 0;
    int sign = 1;
    bool dot = 0; // bool�� �Ҽ��� ����
    float dotcal = 1.0; // ����Ҷ� �ڷ��� �����ֱ� ���� float���� ����(�Ҽ��� ���� ����)
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
        if (*str == '.') // ���࿡ �Ҽ����� ������
        {
            // if (dot) --> .�� �������� �����°��(����)
               // return result;
            dot = 1; // �Ҽ��� ������ 1�� ���ش�
            str++;
            continue;
        }
        if (dot) // �Ҽ��� ������ 1�̸�
        {
            dotcal /= 10.0; // dotcal�� 10���� �����ְ�
            result += (*str - '0') * dotcal * sign; // ���Ҷ� dotcal�� ���ؼ� �����ش�.
            // ���� ��� �Ҽ��� �Ʒ� ���ڸ����� 0.1�� ��������, �Ҽ��� �Ʒ� ���ڸ����� 0.01�� ��������...�̷� ��
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
    // �߰�������, atof �Լ��� ���, �߰��� ������ ������ �� �������� ����� ���ش�. �װ� ���� �������ִ�. while(���� || �Ҽ���)�� �������� �����Ƿ� �ٷ� result�� return���ֱ� �����̴�
}