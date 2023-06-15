
#include"Clock.h"

int main()
{
	int second = 0;  // 사용자에게 입력받을 변수 선언 및 초기화
	cin >> second;   // 사용자게 임의의 값을 입력받음
	Clock clock;     // 클래스 객체 선언
	clock.setTime(second);   // 사용자가 입력한 값으로 시간 설정
	clock.increaseHour();    // hour 값을 1올림
	clock.increaseSecond();  // second 값을 1올림
	clock.increaseMinute();  // minute 값을 1올림

	return 0;
}
