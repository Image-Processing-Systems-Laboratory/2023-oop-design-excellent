#include <iostream>
#include "Clock.h"

using namespace std;

int main()
{
	int input_second = 0;
	cout << "Enter the value of second: ";
	cin >> input_second;

	Clock clk;
	clk.setTime(input_second);


	/*clk.increaseHour();*/
	clk.increaseMinute();
	clk.increaseSecond();

	

	return 0;
}