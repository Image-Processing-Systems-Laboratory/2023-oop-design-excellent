// 01반_02반_2022202078_조영훈 2-2주차 4번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Clock.h"
int main()
{
	Clock Clock; //생성자 호출
	Clock.Cout();	//처음 입력 값 출력
	Clock.increaseHour();	//시+1
	Clock.increaseMinute();//분+1
	Clock.increaseSecond();	//초+1
	//destroyed에서 증가한 값 출력
}

