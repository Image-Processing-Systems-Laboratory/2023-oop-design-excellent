#include"Clock.h"
#include<iostream>
int main(void)
{
	Clock clk;
	// ���Ȯ���� ���� �޼��� ȣ��
	clk.setTime(92200);
	clk.print();
	clk.increaseSecond();
	clk.print();
	clk.increaseHour();
	clk.print();
	
	return 0;
}