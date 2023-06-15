#include "Clock.h"

using namespace std;

Clock::Clock() // ������
{
	hour = 0;
	minute = 0;
	second = 0;
}

Clock::~Clock() // �Ҹ���
{
	hour = 0;
	minute = 0;
	second = 0;
}

void Clock::increaseHour()
{
	hour++; // 1�ð� ����
	hour %= 24; // hour�� 24�̻��̸� 0����
}

void Clock::increaseMinute()
{
	minute++; // 1�� ����
	if (minute == 60) // 60���� �Ǹ�
		increaseHour(); // 1�ð� ����
	minute %= 60; // 60���̸� 0������
}

void Clock::increaseSecond()
{
	second++; // 1�� ����
	if (second == 60) // 60�ʰ� �Ǹ�
		increaseMinute(); // 1�� ����
	second %= 60; // 60�ʸ� 0�ʷ�
}

void Clock::setTime(int second)
{
	setSecond(second % 60); // �Է� ��(��)�� 60���� ���� ������(0~59)
	setMinute((second / 60) % 60); // �Է� ���� 60���� ������(�� ����) �̸� 60���� ���� ������
	setHour(second / 3600); // �Է� ���� 60*60���� ����(�� ����)
}

void Clock::printTime() // �ð� ���
{
	cout << "It's " << hour << " hour " << minute << " minute " << second << " second" << endl;
}

void Clock::setHour(int hour)
{
	Clock::hour = hour % 24; // setTime���� �� ������ ���� �Ѱ� �����Ƿ� hour >= 24�ϼ���
	// ���� ������ �������� 0~23�� ���� ������ ��
}

void Clock::setMinute(int minute)
{
	Clock::minute = minute; // setTime���� ������ ���� �ؼ� �ѱ�
}

void Clock::setSecond(int second)
{
	Clock::second = second; // setTime���� ������ ���� �ؼ� �ѱ�
}