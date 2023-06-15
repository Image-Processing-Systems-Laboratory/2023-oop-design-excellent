#include "Clock.h"

Clock::Clock() {

}

Clock::~Clock() {

}
void Clock:: setTime(int second) {
	
	 setSec(second);
	 setMin(second /60);
	 setHour(second / 3600);

	 std::cout << hour << " " << minute << " " << this->second<<std::endl;

}



void Clock::setHour(int hour) {

	this->hour = hour % 24;

}

void Clock::setMin(int min) {
	minute = min % 60;

}

void Clock::setSec(int sec) {

	second = sec % 60;



}



void Clock:: increaseSecond() {

	second ++;
	minute += second / 60;
	hour += minute / 60;
	hour %= 24;
	minute %= 60;
	second %= 60;


}


void Clock:: increaseMinute() {

	minute++;
	hour += minute / 60;
	minute %= 60;
	hour = hour % 24;



}

void Clock:: increaseHour() {

	hour++;

	hour %= 24;





}



void Clock::print() {

	std::cout << hour << " " << minute << " " << second <<std::endl;


}

