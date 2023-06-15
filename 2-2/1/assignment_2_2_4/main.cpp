#include "Clock.h"
#include <iostream>

using namespace std;

int main()
{
    Clock c; // 인스턴스 생성
    int sec; // 반복문마다 입력받을 초

    while (1)
    {
        cout << "set second(exit: -1): ";
        cin >> sec;
        if (sec == -1) // 종료 조건
            break;
        c.setTime(sec); // 멤버 변수 업데이트
        c.printTime(); // 시간 출력
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
        // 시, 분, 초 각각 sec마다 달라질 수 있는 값만큼 증가시킴
    }
    return (0);
}