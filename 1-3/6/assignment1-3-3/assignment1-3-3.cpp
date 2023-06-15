#include <iostream>
#define MAX_LENGTH 32
using namespace std;

int power(int x, int n);

int main()
{
    char input[MAX_LENGTH];
    int base_input, base_output, length = 0, num = 0;

    // 입력
    cout << "[INPUT] number current_base target_base\n[INPUT] ";
    cin >> input >> base_input >> base_output;
    while (input[length] != NULL)    length++;

    // base_input진수를 십진수로 변환
    switch (base_input)
    {
    case 2:
        for (int i = 0; i < length; i++)
        {
            if (input[i] == '1')    num += (1 << (length - 1 - i));
        }
        break;
    case 8:
        for (int i = 0; i < length; i++)
        {
            num += (input[i] - '0') * power(8, length - 1 - i);
        }
        break;
    case 16:
        for (int i = 0; i < length; i++)
        {
            if (input[i] >= 'A' && input[i] <= 'F')
            {
                num += (input[i] - 'A' + 10) * power(16, length - 1 - i);
            }
            else if (input[i] >= '0' && input[i] <= '9')
            {
                num += (input[i] - '0') * power(16, length - 1 - i);
            }
        }
        break;
    case 10:
    default:
        for (int i = 0; i < length; i++)
        {
            num += (input[i] - '0') * power(10, length - 1 - i);
        }
        break;
    }

    // base_output진수로 출력
    switch (base_output)
    {
    case 2:
        length = 0;
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            if (num & (1 << (MAX_LENGTH - 1 - i)))
            {
                length = 1;
                cout << 1;
            }
            else if (length)
            {
                cout << 0;
            }
        }
        break;
    case 8:
        length = 0;
        for (int i = 0; num; i++, num /= 8, length++)
        {
            input[i] = (num % 8) + '0';
        }
        for (int i = length - 1; i >= 0; i--)
        {
            cout << input[i];
        }
        break;
    case 16:
        length = 0;
        for (int i = 0; num; i++, num /= 16, length++)
        {
            if ((num % 16) > 9)
            {
                input[i] = (num % 16) - 10 + 'A';
            }
            else
            {
                input[i] = (num % 16) + '0';
            }
        }
        for (int i = length - 1; i >= 0; i--)
        {
            cout << input[i];
        }
        break;
    case 10:
    default:
        cout << num;
        break;
    }
    cout << endl;

    // 종료
    return 0;
}

// power
int power(int x, int n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= x;
    }
    return result;
}