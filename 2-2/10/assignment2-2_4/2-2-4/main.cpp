#include "Clock.hpp"

int main(void)
{
	Clock clock; // clock ��ü ����

	clock.setTime(92200); // 92200�ʴ� 1�� 1�ð� 36�� 40��
	clock.increaseHour(); // 1�ð� ������Ŵ
	clock.viewTimeForDebug(); // ���� �ð�(2�ð� 36�� 40��) ǥ��
	return (0);
}