#include "Clock.h"
#include <iostream>

using namespace std;

Clock::Clock() 
{
	cout << "clock class is created!" << endl; //생성자
}

Clock::~Clock() 
{
	cout << "Clock class is destroyed!" << endl; //파괴자
}

void Clock::increaseHour() //시간 증가
{
	hour++; 
	if (hour >= 24)
	{
		hour %= 24;
	}

	cout << hour << " : " << minute << " : " << second << endl;
}

void Clock::increaseMinute()
{
	minute++; //+1 증가
	if (minute == 60)  //60초 = 1분
	{
		minute = 0;
		hour++;
	}

	if (hour == 24) //24시간 = 0
	{
		hour = 0;
	}

	cout << hour << " : " << minute << " : " << second << endl;
}
void Clock::increaseSecond()
{
	second++; //+1 증가
	if (second == 60) //60초 = 1분
	{
		second = 0;
		minute++;
	}

	if (minute == 60) //60분 = 1시간
	{
		minute = 0;
		hour++;
	}

	if (hour == 24) //24시간 = 0으로 변환
	{
		hour = 0;
	}

	cout << hour << " : " << minute << " : " << second << endl;
}

void Clock::setTime(int second)
{
	int h = 0;
	int m = 0;
	int s = 0;

	m = second / 60; //분 계산
	s = second % 60; //남는 초
	h = m / 60; //시간 계산
	m = m % 60; //남는 분 저장

	if (h >= 24)
	{
		h %= 24;
	}

	setHour(h); //시간 설정
	setMinute(m); //분 설정
	setSecond(s); //초 설정

	cout << "Time => " << h << " : " << m << " : " << s << endl;
}

void Clock::setHour(int hour)
{
	this->hour = hour; //hour변수에 대입
}
void Clock::setMinute(int minute)
{
	this->minute = minute; //minute변수에 대입
}
void Clock::setSecond(int second)
{
	this->second = second; //second변수에 대입
}