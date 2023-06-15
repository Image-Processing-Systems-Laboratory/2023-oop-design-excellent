#include "Clock.hpp"
#include <iostream>

Clock::Clock() // ������
{
	setTime(0); // �ð��� 0���� ����
}

Clock::~Clock() {} // �Ҹ���

void Clock::setHour(int hour) // �ð� ����
{
	Clock::hour = hour; // ��ü�� hour �Ӽ��� ���ڷ� ���� hour�� ����
}

void Clock::setMinute(int minute)
{
	Clock::minute = minute; // ��ü�� minute �Ӽ��� ���ڷ� ���� minute�� ����
}

void Clock::setSecond(int second)
{
	Clock::second = second; // ��ü�� second �Ӽ��� ���ڷ� ���� second�� ����
}

void Clock::setTime(int second) // �ð� ����, ���ڷδ� �ʸ� ����
{
	// �ð��� ���� �� ���� 24�ð� ���� ū �ð��̸� �� ������ ���� 24�� ���� �������� ����
	setHour(((second / 60) / 60) % 24);
	// �ø� ���� ����� ���� ����
	setMinute((second / 60) % 60);
	// �ÿ� ���� ���� ����� �ʸ� ����
	setSecond(second % 60);
}

void Clock::increaseHour()
{
	setHour((hour + 1) % 24); // �ð��� 1�ð� �ø�. �� �� 24�� �����ϸ� 0���� ����
}

void Clock::increaseMinute() // 1�� ����
{
	if (minute == 59) // 59���� ��� ���� 0���� ����� �ð��� �ø�
	{
		setMinute(0);
		increaseHour();
	}
	else
		setMinute(minute + 1);
}

void Clock::increaseSecond() // 1�� ����
{
	if (second == 59) // 59���� ��� �ʸ� 0���� ����� ���� �ø�
	{
		setSecond(0);
		increaseMinute();
	}
	else
		setSecond(second + 1);
}

void Clock::viewTimeForDebug(void) // �ð� ��� �Լ�, �� �� �� ������ ���
{
	std::cout << '(' << hour << "h " << minute << "m " << second << "s)" << std::endl;
}