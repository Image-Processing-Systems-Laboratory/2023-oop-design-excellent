#include "Clock.h"
using namespace std;

int main() {

	Clock clock;

	cout << "setTime(82739)" << endl;
	clock.setTime(82739);
	clock.print();
	cout << endl;
	cout << "increaseSecond" << endl;		//초,분,시 올림 작동 여부 확인
	clock.increaseSecond();
	clock.print();
	cout << endl;
	cout << "increaseMinute" << endl;
	clock.increaseMinute();
	clock.print();
	cout << endl;
	cout << "increaseHour" << endl;
	clock.increaseHour();
	clock.print();
	cout << endl;
}