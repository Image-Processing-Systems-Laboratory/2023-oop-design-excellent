#include "Clock.h"

using namespace std;

Clock::Clock() // 생성자
{
	hour = 0;
	minute = 0;
	second = 0;
}

Clock::~Clock() // 소멸자
{
	hour = 0;
	minute = 0;
	second = 0;
}

void Clock::increaseHour()
{
	hour++; // 1시간 증가
	hour %= 24; // hour가 24이상이면 0으로
}

void Clock::increaseMinute()
{
	minute++; // 1분 증가
	if (minute == 60) // 60분이 되면
		increaseHour(); // 1시간 증가
	minute %= 60; // 60분이면 0분으로
}

void Clock::increaseSecond()
{
	second++; // 1초 증가
	if (second == 60) // 60초가 되면
		increaseMinute(); // 1분 증가
	second %= 60; // 60초면 0초로
}

void Clock::setTime(int second)
{
	setSecond(second % 60); // 입력 값(초)를 60으로 나눈 나머지(0~59)
	setMinute((second / 60) % 60); // 입력 값을 60으로 나누고(분 단위) 이를 60으로 나눈 나머지
	setHour(second / 3600); // 입력 값을 60*60으로 나눔(시 단위)
}

void Clock::printTime() // 시간 출력
{
	cout << "It's " << hour << " hour " << minute << " minute " << second << " second" << endl;
}

void Clock::setHour(int hour)
{
	Clock::hour = hour % 24; // setTime에서 시 단위의 수만 넘겨 줬으므로 hour >= 24일수도
	// 따라서 나머지 연산으로 0~23의 수로 만들어야 함
}

void Clock::setMinute(int minute)
{
	Clock::minute = minute; // setTime에서 나머지 연산 해서 넘김
}

void Clock::setSecond(int second)
{
	Clock::second = second; // setTime에서 나머지 연산 해서 넘김
}