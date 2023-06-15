#include "Clock.h"

// ������ | ���� �ʱ�ȭ
Clock::Clock()
{
	hour = 0;
	minute = 0;
	second = 0;
}

// �Ҹ��� | ������ �ð� ���
Clock::~Clock()
{
	std::cout << this->hour << ":" << this->minute << ":" << this->second << std::endl;
}

// �� ����
void Clock::increaseHour()
{
	if (++hour == 24)	hour = 0;
	std::cout << this->hour << ":" << this->minute << ":" << this->second << std::endl;
	return;
}

// �� ����
void Clock::increaseMinute()
{
	if (++minute == 60)
	{
		minute = 0;
		Clock::increaseHour();
	}
	std::cout << this->hour << ":" << this->minute << ":" << this->second << std::endl;
	return;
}

// �� ����
void Clock::increaseSecond()
{
	if (++second == 60)
	{
		second = 0;
		Clock::increaseMinute();
	}
	std::cout << this->hour << ":" << this->minute << ":" << this->second << std::endl;
	return;
}

// �� �Է� �޾� �ð� ����
void Clock::setTime(int second)
{
	Clock::setSecond(second % 60);
	second /= 60;
	Clock::setMinute(second % 60);
	second /= 60;
	Clock::setHour(second % 24);
	std::cout << this->hour << ":" << this->minute << ":" << this->second << std::endl;
	return;
}

// �� ����
void Clock::setHour(int hour)
{
	this->hour = hour;
	return;
}

// �� ����
void Clock::setMinute(int minute)
{
	this->minute = minute;
	return;
}

// �� ����
void Clock::setSecond(int second)
{
	this->second = second;
	return;
}