#include "Clock.h"

//Clock Ŭ������ ���Ǻ�

//������
Clock::Clock()
{
	//private �ɹ� ���� �ʱ�ȭ
	hour = 0;
	minute = 0;
	second = 0;
}

//�Ҹ���
Clock::~Clock()
{
	//������ ��� (:�� ����)
	cout << hour << " : " << minute << " : " << second << endl;
}

//�� ����
void Clock::increaseHour() {
	//�� ����
	hour++;
	//24 �̻��̸� 0���� �ʱ�ȭ
	if (hour > 23) {
		hour = 0;
	}
}
//�� ����
void Clock::increaseMinute() {
	//1�� ����
	minute++;
	//60 �̻��̸� 0���� �ʱ�ȭ, increaseHour ȣ��
	if (minute > 59) {
		minute = 0;
		increaseHour();
	}
		
}
//�� ����
void Clock::increaseSecond() {
	//1�� ����
	second++;
	//60 �̻��̸� 0���� �ʱ�ȭ, increaseMinute ȣ��
	if (second > 59) {
		second = 0;
		increaseMinute();
	}
}

//�ð� ����
void Clock::setTime(int second) {
	//60���� ������ ������ ���� �ʷ� ����
	setSecond(second % 60);
	//�ʸ� 60���� ������ ������ ��ȯ
	second /= 60;
	//60���� ������ ������ ���� ������ ����
	setMinute(second % 60);
	//���� 60���� ������ ������ ��ȯ
	second /= 60;
	//���� 24�� ������ ������ ����
	setHour(second % 24);
}
//�� ����
void Clock::setHour(int hour) {
	//24�� ������ ��ġ�� ���� ����
	this->hour = hour % 24;
}
//�� ����
void Clock::setMinute(int minute) {
	//60���� ������ ��ġ�� ���� ����
	this->minute = minute % 60;
}
//�� ����
void Clock::setSecond(int second) {
	//60���� ������ ��ġ�� �� �� ����
	this->second = second % 60;
}