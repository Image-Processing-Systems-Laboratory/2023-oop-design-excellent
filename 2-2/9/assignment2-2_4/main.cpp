#include <iostream>
#include "Clock.h"

using namespace std;

int main(void) {
	int time;
	Clock clock;

	//시간 설정
	cout << "설정할 시간을 초 단위로 입력하세요: ";
	cin >> time;
	clock.setTime(time);

	//입력 받은 값 만큼 초 증가
	cout << "몇 초 증가시킬까요? ";
	cin >> time;
	for (int i = 0; i < time; i++) {
		clock.increaseSecond();
	}

	//입력 받은 값 만큼 분 증가
	cout << "몇 분 증가시킬까요? ";
	cin >> time;
	for (int i = 0; i < time; i++) {
		clock.increaseMinute();
	}

	//입력 받은 값 만큼 시 증가
	cout << "몇 시 증가시킬까요? ";
	cin >> time;
	for (int i = 0; i < time; i++) {
		clock.increaseHour();
	}

	return 0;
}