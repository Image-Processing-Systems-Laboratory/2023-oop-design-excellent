#include"Clock.h"
#include<iostream>
int main(void)
{
	Clock clk;
	// 출력확인을 위한 메서드 호출
	clk.setTime(92200);
	clk.print();
	clk.increaseSecond();
	clk.print();
	clk.increaseHour();
	clk.print();
	
	return 0;
}