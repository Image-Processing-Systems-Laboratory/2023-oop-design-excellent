#include"Clock.h"
#include<iostream>

using namespace std;

Clock::Clock()	// �����ڷ� ������� �ʱ�ȭ
{
	hour = 0;
	minute = 0;
	second = 0;
}

Clock::~Clock()	// �Ҹ��ڿ����� ������ ������ ���� ����
{
}

void Clock::increaseHour()	// 1�ð������� ����
{
	hour++;
	setTime(second);
	return;
}
void Clock::increaseMinute()	// 1�������� ����
{
	minute++;
	setTime(second);
	return;
}
void Clock::increaseSecond()	// 1�� ���� �� ����
{
	second++;
	setTime(second);
	return;
}
void Clock::setTime(int second)	// �ð��� ������, 
{
	this->second = second;
	setSecond(second);
	setMinute(minute);
	setHour(hour);
	return;
}

void Clock::setHour(int hour)	// �ð� 24�ð� �̻��̸� 0���� ����
{
	if (hour > 23)
		this->hour -= 24;
	return;
}
void Clock::setMinute(int minute)	// ���� 60������ ���� ��������
{
	this->hour += minute / 60;
	this->minute = minute % 60;
	return;
}
void Clock::setSecond(int second)	// �ʰ� 60������ ���� ��������
{
	this->minute += second / 60;
	this->second = second % 60;
	return;
}
void Clock::print(void)	// ����ϴ� �޼���
{
	cout << "Hour: " << hour << endl;
	cout << "Minute: " << minute << endl;
	cout << "Second: " << second << endl<<endl;
	return;
}
