#include "Clock.h"
#include <iostream>

using namespace std;

Clock::Clock() 
{
	cout << "clock class is created!" << endl; //������
}

Clock::~Clock() 
{
	cout << "Clock class is destroyed!" << endl; //�ı���
}

void Clock::increaseHour() //�ð� ����
{
	hour++; 
	if (hour >= 24)
	{
		hour %= 24;
	}

	cout << hour << " : " << minute << " : " << second << endl;
}

void Clock::increaseMinute()
{
	minute++; //+1 ����
	if (minute == 60)  //60�� = 1��
	{
		minute = 0;
		hour++;
	}

	if (hour == 24) //24�ð� = 0
	{
		hour = 0;
	}

	cout << hour << " : " << minute << " : " << second << endl;
}
void Clock::increaseSecond()
{
	second++; //+1 ����
	if (second == 60) //60�� = 1��
	{
		second = 0;
		minute++;
	}

	if (minute == 60) //60�� = 1�ð�
	{
		minute = 0;
		hour++;
	}

	if (hour == 24) //24�ð� = 0���� ��ȯ
	{
		hour = 0;
	}

	cout << hour << " : " << minute << " : " << second << endl;
}

void Clock::setTime(int second)
{
	int h = 0;
	int m = 0;
	int s = 0;

	m = second / 60; //�� ���
	s = second % 60; //���� ��
	h = m / 60; //�ð� ���
	m = m % 60; //���� �� ����

	if (h >= 24)
	{
		h %= 24;
	}

	setHour(h); //�ð� ����
	setMinute(m); //�� ����
	setSecond(s); //�� ����

	cout << "Time => " << h << " : " << m << " : " << s << endl;
}

void Clock::setHour(int hour)
{
	this->hour = hour; //hour������ ����
}
void Clock::setMinute(int minute)
{
	this->minute = minute; //minute������ ����
}
void Clock::setSecond(int second)
{
	this->second = second; //second������ ����
}