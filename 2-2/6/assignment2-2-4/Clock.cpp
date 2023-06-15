#include "Clock.h"

// 생성자 | 변수 초기화
Clock::Clock()
{
	hour = 0;
	minute = 0;
	second = 0;
}

// 소멸자 | 마지막 시간 출력
Clock::~Clock()
{
	std::cout << this->hour << ":" << this->minute << ":" << this->second << std::endl;
}

// 시 증가
void Clock::increaseHour()
{
	if (++hour == 24)	hour = 0;
	std::cout << this->hour << ":" << this->minute << ":" << this->second << std::endl;
	return;
}

// 분 증가
void Clock::increaseMinute()
{
	if (++minute == 60)
	{
		minute = 0;
		Clock::increaseHour();
	}
	std::cout << this->hour << ":" << this->minute << ":" << this->second << std::endl;
	return;
}

// 초 증가
void Clock::increaseSecond()
{
	if (++second == 60)
	{
		second = 0;
		Clock::increaseMinute();
	}
	std::cout << this->hour << ":" << this->minute << ":" << this->second << std::endl;
	return;
}

// 초 입력 받아 시간 설정
void Clock::setTime(int second)
{
	Clock::setSecond(second % 60);
	second /= 60;
	Clock::setMinute(second % 60);
	second /= 60;
	Clock::setHour(second % 24);
	std::cout << this->hour << ":" << this->minute << ":" << this->second << std::endl;
	return;
}

// 시 설정
void Clock::setHour(int hour)
{
	this->hour = hour;
	return;
}

// 분 설정
void Clock::setMinute(int minute)
{
	this->minute = minute;
	return;
}

// 초 설정
void Clock::setSecond(int second)
{
	this->second = second;
	return;
}