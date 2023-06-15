#include <iostream>
#include "Clock.h"

//������
Clock::Clock() {
	//0���� �ʱ�ȭ
	hour = 0;
	minute = 0;
	second = 0;
}

//�ı���
Clock::~Clock() {
	std::cout << hour << ':' << minute << ':' << second << std::endl << std::endl;  //�ð� ���
}

//1�ð� ������Ű�� �Լ�
void Clock::increaseHour() {
	hour++;

	if (hour >= 24) {   //24 �̻��� ��� 0���� �ٽ� ����
		hour = 0;
	}
}

//1�� ������Ű�� �Լ�
void Clock::increaseMinute() {
	minute++;
	if (minute >= 60) {  //60 �̻��� ��� 0���� �ٽ� �����ϰ� hour 1 ����
		increaseHour();

		minute = 0;
	}
}

//1�� ������Ű�� �Լ�
void Clock::increaseSecond() {
	second++;

	if (second >= 60) {  //60 �̻��� ��� 0���� �ٽ� �����ϰ� minute 1 ����
		increaseMinute();

		second = 0;
	}
}

//�ð��� �����ϴ� �Լ�
void Clock::setTime(int second) {
	setHour(second / 3600);  //�� ����
	second %= 3600;

	setMinute(second / 60);  //�� ����
	second %= 60;

	setSecond(second);       //�� ����
}

//�ø� �����ϴ� �Լ�
void Clock::setHour(int hour) {
	if (hour >= 0 && hour < 24) {
		this->hour = hour;  //�� ����
	}
	else {
		this->hour = hour % 24;  //24 �̻��� ��� 0���� �ٽ� ����
	}
}

//���� �����ϴ� �Լ�
void Clock::setMinute(int minute) {
	this->minute = minute;  //�� ����
}

//�ʸ� �����ϴ� �Լ�
void Clock::setSecond(int second) {
	this->second = second;  //�� ����
}