#include "Clock.h"

Clock::Clock()    // ������ ����
{
	hour = 0;       // ����ϴ� �������� ���� �ʱ�ȭ ����
	minute = 0;
	second = 0;
}
Clock::~Clock()     // �ı��� ����
{
	hour = 0;       // ����ϴ� �������� ���� �ʱ�ȭ ����
	minute = 0;
	second = 0;
}

void Clock::increaseHour()  // hour ���� 1�÷��ִ� �Լ� ����
{
	hour = hour+1;         // hour ���� 1����
	if (hour >= 24)      //���� 24�� ���� ���
	{
		hour = hour % 24;  // hour�� 24�� ���� ������ ���� hour�� ��
	}
}
void Clock::increaseMinute()  // minute ���� 1�÷��ִ� �Լ� ����
{
	minute = minute+1;        // minute ���� 1����
	if (minute >= 60)         //���� 60�� ���� ���
	{
		minute = minute % 60;    // minute�� 60���� ���� ������ ���� minute�� �ϰ� hour�� 1�÷���
		increaseHour();
	}
	
}
void Clock::increaseSecond()   // second ���� 1�÷��ִ� �Լ� ����
{
	second = second+1;     // second ���� 1����
	if (second >= 60)       //���� 60�� ���� ���
	{
		second = second % 60;   // second�� 60���� ���� ������ ���� second�� �ϰ� minute�� 1�÷���
		increaseMinute(); 
	}
}

void Clock::setTime(int second)     // ����ڿ��� ������ ���� �޾� �� ���� �ʷ� �Ͽ� �ð��� �����ϴ� �Լ� ����
{
	Clock::setSecond(second % 60);       // ����ڰ� �Է��� ���� 60���� ���� �������� second�� ���� 
	second = second / 60;                // ����ڰ� �Է��� ���� 60���� ��������
	Clock::setMinute(second % 60);       // ����ڰ� �Է��� ���� 60���� ���� �������� minute ����
	second = second / 60;                 // ����ڰ� �Է��� ���� 60���� ��������
	Clock::setHour(second);               // ����ڰ� �Է��� ������ hour ����
	cout << hour << ' ' << minute << ' ' << this->second << endl;   // ����ڰ� ������ hour, minute, second �� ���
}

void Clock::setHour(int hour)      // hour�� �����ϴ� �Լ�
{
	if (hour >= 24)            //���� 24�� ���� ���
	{
		hour = hour % 24;    // hour�� 24�� ���� ������ ���� hour�� ��
	}
	this->hour = hour;     // �Ű����� ���� hour�� ��
}
void Clock::setMinute(int minute)  // hour�� �����ϴ� �Լ�
{
	this->minute = minute;   // �Ű����� ���� minute�� ��
}
void Clock::setSecond(int second)    // hour�� �����ϴ� �Լ�
{
	this->second = second;    // �Ű����� ���� second�� ��
}