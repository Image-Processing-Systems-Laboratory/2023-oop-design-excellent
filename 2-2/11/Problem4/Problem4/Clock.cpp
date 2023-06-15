#include "Clock.h"

//Clock 클래스의 정의부

//생성자
Clock::Clock()
{
	//private 맴버 변수 초기화
	hour = 0;
	minute = 0;
	second = 0;
}

//소멸자
Clock::~Clock()
{
	//값들을 출력 (:로 구별)
	cout << hour << " : " << minute << " : " << second << endl;
}

//시 증가
void Clock::increaseHour() {
	//시 증가
	hour++;
	//24 이상이면 0으로 초기화
	if (hour > 23) {
		hour = 0;
	}
}
//분 증가
void Clock::increaseMinute() {
	//1분 증가
	minute++;
	//60 이상이면 0으로 초기화, increaseHour 호출
	if (minute > 59) {
		minute = 0;
		increaseHour();
	}
		
}
//초 증가
void Clock::increaseSecond() {
	//1초 증가
	second++;
	//60 이상이면 0으로 초기화, increaseMinute 호출
	if (second > 59) {
		second = 0;
		increaseMinute();
	}
}

//시간 설정
void Clock::setTime(int second) {
	//60으로 나누어 나머지 값을 초로 설정
	setSecond(second % 60);
	//초를 60으로 나누어 분으로 변환
	second /= 60;
	//60으로 나누어 나머지 값을 분으로 설정
	setMinute(second % 60);
	//분을 60으로 나누어 시으로 변환
	second /= 60;
	//분을 24로 나누어 시으로 설정
	setHour(second % 24);
}
//시 설정
void Clock::setHour(int hour) {
	//24로 나누어 넘치는 것을 방지
	this->hour = hour % 24;
}
//분 설정
void Clock::setMinute(int minute) {
	//60으로 나누어 넘치는 것을 방지
	this->minute = minute % 60;
}
//초 설정
void Clock::setSecond(int second) {
	//60으로 나누어 넘치는 것 을 방지
	this->second = second % 60;
}