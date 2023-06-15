#include "Clock.h"

Clock::Clock()
{
	int sec;
	cin >> sec;
	setTime(sec);
}
void Clock::setTime(int se)
{
	Clock::setSecond(se);
	Clock::setMinute(se);
	Clock::setHour(se);
}
void Clock::setHour(int h)
{
	hour = h / 3600%24;
}
void Clock::setMinute(int m)
{
	hour = hour + (m % 3600) / 60/60;
	minute = (m % 3600) / 60%60;
}
void Clock::setSecond(int s)
{
	minute = minute + (s % 3600 % 60) / 60;
	second = (s % 3600 % 60)%60;
}
void Clock::increaseHour()
{
	hour = hour + 1;
	hour = hour % 24;
}
void Clock::increaseMinute()
{
	minute = minute +1;
	hour = hour + minute / 60;
	hour = hour % 24;
	minute = minute % 60;

}
void Clock::increaseSecond()
{
	second = second +1;
	minute = minute + second / 60;
	hour = hour + minute / 60;
	hour = hour % 24;
	minute = minute % 60;
	second = second % 60;
}
void Clock::Cout()
{
	cout << hour << " : " << minute << " : " << second<<endl;
}
Clock::~Clock()
{
	cout << hour << " : " << minute << " : " << second<<endl;
}