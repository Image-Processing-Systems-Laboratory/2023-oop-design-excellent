#include "Clock.h"

int main()
{
    // Clock
    Clock watch;

    // 92200초 설정
    watch.setTime(92200);

    // 59초에서 1초씩 2번 증가
    watch.setTime(59);
    watch.increaseSecond();
    watch.increaseSecond();

    // 59분에서 1분씩 2번 증가
    watch.setTime(3540);
    watch.increaseMinute();
    watch.increaseMinute();

    // 23시에서 1시간씩 2번 증가
    watch.setTime(82800);
    watch.increaseHour();
    watch.increaseHour();

    // 종료
    return 0;
}