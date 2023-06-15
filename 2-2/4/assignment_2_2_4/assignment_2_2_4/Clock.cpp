#include "Clock.h"
using namespace std;


Clock::Clock() {	//생성자
	cout << "Clock is created." << endl;
	hour = 0;
	minute = 0;
	second = 0;
}
Clock::~Clock() {	//소멸자
	cout << "Clock is destroyed." << endl;
}


void Clock::increaseHour() {	//시 1 증가
	if (++hour >= 24) {				//증가된 값이 24 이상이면 0으로 저장
		hour = 0;
	}
}
void Clock::increaseMinute() {	//분 1 증가
	if (++minute >= 60) {			//증가된 값이 60 이상이면
		increaseHour();					//시 증가함수 실행
		minute = 0;						//분 0으로 저장
	}
}
void Clock::increaseSecond() {	//초 1 증가
	if (++second >= 60) {			//증가된 값이 60 이상이면
		increaseMinute();				//분 증가함수 실행
		second = 0;						//초 0으로 저장
	}
}


void Clock::setTime(int second) {
	int hour = 0;
	int minute = 0;

	hour += (second / 3600) % 24;	//전체 시간을 3600으로 나눈 몫을 24로 나눈 나머지를 시에 저장
	setHour(hour);
	minute += (second % 3600) / 60;	//전체 시간을 3600으로 나눈 나머지를 60으로 나눈 몫을 분에 저장
	setMinute(minute);
	setSecond(second % 60);	//전체 시간을 60으로 나눈 나머지를 초에 저장
}
void Clock::print() {
	cout << hour << ":" << minute << ":" << second << endl;	// hh:mm:ss 형식으로 시간 출력
}


void Clock::setHour(int hour) {		//클래스 내부 변수에 저장
	this->hour = hour;
}
void Clock::setMinute(int minute) {	//클래스 내부 변수에 저장
	this->minute = minute;
}
void Clock::setSecond(int second) {	//클래스 내부 변수에 저장
	this->second = second;
}
