#include "Clock.hpp"
#include <iostream>

Clock::Clock() // 생성자
{
	setTime(0); // 시간을 0으로 설정
}

Clock::~Clock() {} // 소멸자

void Clock::setHour(int hour) // 시간 설정
{
	Clock::hour = hour; // 객체의 hour 속성을 인자로 받은 hour로 설정
}

void Clock::setMinute(int minute)
{
	Clock::minute = minute; // 객체의 minute 속성을 인자로 받은 minute로 설정
}

void Clock::setSecond(int second)
{
	Clock::second = second; // 객체의 second 속성을 인자로 받은 second로 설정
}

void Clock::setTime(int second) // 시간 설정, 인자로는 초를 받음
{
	// 시간을 구한 후 만약 24시간 보다 큰 시간이면 일 단위를 제한 24로 나눈 나머지를 받음
	setHour(((second / 60) / 60) % 24);
	// 시를 제한 경우의 분을 구함
	setMinute((second / 60) % 60);
	// 시와 분을 제할 경우의 초를 구함
	setSecond(second % 60);
}

void Clock::increaseHour()
{
	setHour((hour + 1) % 24); // 시간을 1시간 늘림. 이 때 24에 도달하면 0으로 설정
}

void Clock::increaseMinute() // 1분 증가
{
	if (minute == 59) // 59분일 경우 분을 0으로 만들고 시간을 올림
	{
		setMinute(0);
		increaseHour();
	}
	else
		setMinute(minute + 1);
}

void Clock::increaseSecond() // 1초 증가
{
	if (second == 59) // 59초인 경우 초를 0으로 만들고 분을 올림
	{
		setSecond(0);
		increaseMinute();
	}
	else
		setSecond(second + 1);
}

void Clock::viewTimeForDebug(void) // 시간 출력 함수, 시 분 초 단위로 출력
{
	std::cout << '(' << hour << "h " << minute << "m " << second << "s)" << std::endl;
}