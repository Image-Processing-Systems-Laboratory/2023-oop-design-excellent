#include "Clock.h"
#include <iostream>

using namespace std;

int main()
{
    Clock c; // �ν��Ͻ� ����
    int sec; // �ݺ������� �Է¹��� ��

    while (1)
    {
        cout << "set second(exit: -1): ";
        cin >> sec;
        if (sec == -1) // ���� ����
            break;
        c.setTime(sec); // ��� ���� ������Ʈ
        c.printTime(); // �ð� ���
        for (int i = 0; i < sec % 161; i++)
            c.increaseSecond();
        cout << endl << "increased " << sec % 161 << " seconds: " << endl;
        c.printTime();
        for (int i = 0; i < sec % 89; i++)
            c.increaseMinute();
        cout << endl << "increased " << sec % 89 << " minutes: " << endl;
        c.printTime();
        for (int i = 0; i < sec % 42; i++)
            c.increaseHour();
        cout << endl << "increased " <<  sec % 42 << " hours: " << endl;
        c.printTime();
        // ��, ��, �� ���� sec���� �޶��� �� �ִ� ����ŭ ������Ŵ
    }
    return (0);
}