#include "Clock.h"


//�׽�Ʈ �Լ��� ������ �ִ� ����� �����ϴ�.
void clockTest1() {
	cout << "Clock test 1" << endl;
	Clock  c1;
	c1.setTime(92200);
}

void clockTest2() {
	cout << "Clock test 2" << endl;
	Clock  c1;
	c1.setTime(82739);
}
void clockTest3() {
	cout << "Clock test 3" << endl;
	Clock  c1;
	c1.setTime(82739);
	c1.increaseSecond();
	c1.increaseMinute();
	c1.increaseHour();
}

//�׽�Ʈ �Լ� ȣ��
int main() {
	clockTest1();
	clockTest2();
	clockTest3();

	return 0;
}