#include "Clock.h"

Clock::Clock()    // 생성자 정의
{
	hour = 0;       // 사용하는 변수들을 전부 초기화 해줌
	minute = 0;
	second = 0;
}
Clock::~Clock()     // 파괴자 정의
{
	hour = 0;       // 사용하는 변수들을 전부 초기화 해줌
	minute = 0;
	second = 0;
}

void Clock::increaseHour()  // hour 값을 1올려주는 함수 정의
{
	hour = hour+1;         // hour 값을 1더함
	if (hour >= 24)      //만약 24을 넘을 경우
	{
		hour = hour % 24;  // hour를 24로 나눈 나머지 값을 hour로 함
	}
}
void Clock::increaseMinute()  // minute 값을 1올려주는 함수 정의
{
	minute = minute+1;        // minute 값을 1더함
	if (minute >= 60)         //만약 60을 넘을 경우
	{
		minute = minute % 60;    // minute를 60으로 나눈 나머지 값을 minute로 하고 hour를 1올려줌
		increaseHour();
	}
	
}
void Clock::increaseSecond()   // second 값을 1올려주는 함수 정의
{
	second = second+1;     // second 값을 1더함
	if (second >= 60)       //만약 60을 넘을 경우
	{
		second = second % 60;   // second을 60으로 나눈 나머지 값을 second로 하고 minute를 1올려줌
		increaseMinute(); 
	}
}

void Clock::setTime(int second)     // 사용자에게 임의의 수를 받아 그 수를 초로 하여 시간을 설정하는 함수 정의
{
	Clock::setSecond(second % 60);       // 사용자가 입력한 값을 60으로 나눈 나머지로 second로 설정 
	second = second / 60;                // 사용자가 입력한 값을 60으로 나누어줌
	Clock::setMinute(second % 60);       // 사용자가 입력한 값을 60으로 나눈 나머지로 minute 설정
	second = second / 60;                 // 사용자가 입력한 값을 60으로 나누어줌
	Clock::setHour(second);               // 사용자가 입력한 값으로 hour 설정
	cout << hour << ' ' << minute << ' ' << this->second << endl;   // 사용자가 설정한 hour, minute, second 값 출력
}

void Clock::setHour(int hour)      // hour을 결정하는 함수
{
	if (hour >= 24)            //만약 24을 넘을 경우
	{
		hour = hour % 24;    // hour를 24로 나눈 나머지 값을 hour로 함
	}
	this->hour = hour;     // 매개변수 값을 hour로 함
}
void Clock::setMinute(int minute)  // hour을 결정하는 함수
{
	this->minute = minute;   // 매개변수 값을 minute로 함
}
void Clock::setSecond(int second)    // hour을 결정하는 함수
{
	this->second = second;    // 매개변수 값을 second로 함
}