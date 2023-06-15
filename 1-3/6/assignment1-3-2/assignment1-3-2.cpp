#include <iostream>
#define MAX_LENGTH 64
using namespace std;

int main()
{
    double Vs, R1, R2, RL;
    int previous = 0, i = 0;
    char numbers[MAX_LENGTH];

    // 입력
    cout << "Vs: ";
    cin >> Vs;
    cout << "R1: ";
    cin >> R1;
    cout << "R2: ";
    cin >> R2;
    cout << "R(Load): ";
    cin >> RL;

    // 출력
    if (RL)
    {
        // {numerator}/{denominator}
        cout << "Vout: " << (R2 * Vs) << "/" << (R1 + R2 + R1 * R2 / RL) << " = ";
        
        // a form of decimal or a form of repeating decimal
        sprintf_s(numbers, "%f", (R2 * Vs) / (R1 + R2 + R1 * R2 / RL));
        for (; numbers[i] != '.' && numbers[i] != NULL; i++)
        {
            cout << numbers[i];
        }
        cout << "(";
        for (; numbers[i] != NULL && numbers[i] != previous; i++)
        {
            previous = numbers[i];
            cout << numbers[i];
        }
        cout << ")" << endl;

        // Power Ratio
        printf("Load power ratio: %.2f%%\n", (((R2 * Vs) / (R1 + R2 + R1 * R2 / RL) * (R2 / (R2 + RL)) / Vs) * 100));
    }
    else
    {
        // {numerator}/{denominator}
        cout << "Vout: " << (R2 * Vs) << "/" << (R1 + R2) << " = ";

        // a form of decimal or a form of repeating decimal
        sprintf_s(numbers, "%f", (R2 * Vs) / (R1 + R2));
        for (; numbers[i] != '.' && numbers[i] != NULL; i++)
        {
            cout << numbers[i];
        }
        cout << "(";
        for (; numbers[i] != NULL && numbers[i] != previous; i++)
        {
            previous = numbers[i];
            cout << numbers[i];
        }
        cout << ")" << endl;
        
    }

    // 종료
    return 0;
}