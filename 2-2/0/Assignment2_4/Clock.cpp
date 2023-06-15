#include"Clock.h"
#include<iostream>

using namespace std;

Clock::Clock()	// 생성자로 멤버변수 초기화
{
	hour = 0;
	minute = 0;
	second = 0;
}

Clock::~Clock()	// 소멸자에서는 별도로 관리할 것이 없음
{
}

void Clock::increaseHour()	// 1시간증가후 정렬
{
	hour++;
	setTime(second);
	return;
}
void Clock::increaseMinute()	// 1분증가후 정렬
{
	minute++;
	setTime(second);
	return;
}
void Clock::increaseSecond()	// 1초 증가 후 정렬
{
	second++;
	setTime(second);
	return;
}
void Clock::setTime(int second)	// 시간을 정렬함, 
{
	this->second = second;
	setSecond(second);
	setMinute(minute);
	setHour(hour);
	return;
}

void Clock::setHour(int hour)	// 시가 24시간 이상이면 0으로 만듬
{
	if (hour > 23)
		this->hour -= 24;
	return;
}
void Clock::setMinute(int minute)	// 분이 60이하의 값을 갖도록함
{
	this->hour += minute / 60;
	this->minute = minute % 60;
	return;
}
void Clock::setSecond(int second)	// 초가 60이하의 값을 갖도록함
{
	this->minute += second / 60;
	this->second = second % 60;
	return;
}
void Clock::print(void)	// 출력하는 메서드
{
	cout << "Hour: " << hour << endl;
	cout << "Minute: " << minute << endl;
	cout << "Second: " << second << endl<<endl;
	return;
}
