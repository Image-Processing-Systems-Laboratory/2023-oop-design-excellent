#include "Clock.h"
#include <iostream>

using namespace std;


int main() {
	Clock time;

	time.setTime(82739);
	time.increaseSecond();//�� ����
	time.print();//���
	time.increaseMinute();//�� ����
	time.print();//���
	time.increaseHour();//�ð� ����
	time.print();//���



}