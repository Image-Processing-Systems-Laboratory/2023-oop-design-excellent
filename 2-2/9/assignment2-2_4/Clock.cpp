#include <iostream>
#include "Clock.h"

//생성자
Clock::Clock() {
	//0으로 초기화
	hour = 0;
	minute = 0;
	second = 0;
}

//파괴자
Clock::~Clock() {
	std::cout << hour << ':' << minute << ':' << second << std::endl << std::endl;  //시간 출력
}

//1시간 증가시키는 함수
void Clock::increaseHour() {
	hour++;

	if (hour >= 24) {   //24 이상일 경우 0부터 다시 시작
		hour = 0;
	}
}

//1분 증가시키는 함수
void Clock::increaseMinute() {
	minute++;
	if (minute >= 60) {  //60 이상일 경우 0부터 다시 시작하고 hour 1 증가
		increaseHour();

		minute = 0;
	}
}

//1초 증가시키는 함수
void Clock::increaseSecond() {
	second++;

	if (second >= 60) {  //60 이상일 경우 0부터 다시 시작하고 minute 1 증가
		increaseMinute();

		second = 0;
	}
}

//시간을 설정하는 함수
void Clock::setTime(int second) {
	setHour(second / 3600);  //시 설정
	second %= 3600;

	setMinute(second / 60);  //분 설정
	second %= 60;

	setSecond(second);       //초 설정
}

//시를 설정하는 함수
void Clock::setHour(int hour) {
	if (hour >= 0 && hour < 24) {
		this->hour = hour;  //시 대입
	}
	else {
		this->hour = hour % 24;  //24 이상일 경우 0부터 다시 시작
	}
}

//분을 설정하는 함수
void Clock::setMinute(int minute) {
	this->minute = minute;  //분 대입
}

//초를 설정하는 함수
void Clock::setSecond(int second) {
	this->second = second;  //초 대입
}