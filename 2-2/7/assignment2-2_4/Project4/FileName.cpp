
#include"Clock.h"

int main()
{
	int second = 0;  // ����ڿ��� �Է¹��� ���� ���� �� �ʱ�ȭ
	cin >> second;   // ����ڰ� ������ ���� �Է¹���
	Clock clock;     // Ŭ���� ��ü ����
	clock.setTime(second);   // ����ڰ� �Է��� ������ �ð� ����
	clock.increaseHour();    // hour ���� 1�ø�
	clock.increaseSecond();  // second ���� 1�ø�
	clock.increaseMinute();  // minute ���� 1�ø�

	return 0;
}
