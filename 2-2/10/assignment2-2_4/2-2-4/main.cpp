#include "Clock.hpp"

int main(void)
{
	Clock clock; // clock 객체 생성

	clock.setTime(92200); // 92200초는 1일 1시간 36분 40초
	clock.increaseHour(); // 1시간 증가시킴
	clock.viewTimeForDebug(); // 현재 시간(2시간 36분 40초) 표시
	return (0);
}