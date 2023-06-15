#include "Clock.h"
#include <iostream>

using namespace std;


int main() {
	Clock time;

	time.setTime(82739);
	time.increaseSecond();//초 증가
	time.print();//출력
	time.increaseMinute();//분 증가
	time.print();//출력
	time.increaseHour();//시간 증가
	time.print();//출력



}