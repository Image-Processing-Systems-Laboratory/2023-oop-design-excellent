#include <iostream>
#include "Clock.h"

using namespace std;

int main(void) {
	int time;
	Clock clock;

	//�ð� ����
	cout << "������ �ð��� �� ������ �Է��ϼ���: ";
	cin >> time;
	clock.setTime(time);

	//�Է� ���� �� ��ŭ �� ����
	cout << "�� �� ������ų���? ";
	cin >> time;
	for (int i = 0; i < time; i++) {
		clock.increaseSecond();
	}

	//�Է� ���� �� ��ŭ �� ����
	cout << "�� �� ������ų���? ";
	cin >> time;
	for (int i = 0; i < time; i++) {
		clock.increaseMinute();
	}

	//�Է� ���� �� ��ŭ �� ����
	cout << "�� �� ������ų���? ";
	cin >> time;
	for (int i = 0; i < time; i++) {
		clock.increaseHour();
	}

	return 0;
}