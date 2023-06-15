#include "Clock.h"
using namespace std;


Clock::Clock() {	//������
	cout << "Clock is created." << endl;
	hour = 0;
	minute = 0;
	second = 0;
}
Clock::~Clock() {	//�Ҹ���
	cout << "Clock is destroyed." << endl;
}


void Clock::increaseHour() {	//�� 1 ����
	if (++hour >= 24) {				//������ ���� 24 �̻��̸� 0���� ����
		hour = 0;
	}
}
void Clock::increaseMinute() {	//�� 1 ����
	if (++minute >= 60) {			//������ ���� 60 �̻��̸�
		increaseHour();					//�� �����Լ� ����
		minute = 0;						//�� 0���� ����
	}
}
void Clock::increaseSecond() {	//�� 1 ����
	if (++second >= 60) {			//������ ���� 60 �̻��̸�
		increaseMinute();				//�� �����Լ� ����
		second = 0;						//�� 0���� ����
	}
}


void Clock::setTime(int second) {
	int hour = 0;
	int minute = 0;

	hour += (second / 3600) % 24;	//��ü �ð��� 3600���� ���� ���� 24�� ���� �������� �ÿ� ����
	setHour(hour);
	minute += (second % 3600) / 60;	//��ü �ð��� 3600���� ���� �������� 60���� ���� ���� �п� ����
	setMinute(minute);
	setSecond(second % 60);	//��ü �ð��� 60���� ���� �������� �ʿ� ����
}
void Clock::print() {
	cout << hour << ":" << minute << ":" << second << endl;	// hh:mm:ss �������� �ð� ���
}


void Clock::setHour(int hour) {		//Ŭ���� ���� ������ ����
	this->hour = hour;
}
void Clock::setMinute(int minute) {	//Ŭ���� ���� ������ ����
	this->minute = minute;
}
void Clock::setSecond(int second) {	//Ŭ���� ���� ������ ����
	this->second = second;
}
