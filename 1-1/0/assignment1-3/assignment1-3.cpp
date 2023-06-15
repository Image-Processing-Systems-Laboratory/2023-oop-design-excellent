#include<iostream>

using namespace std;		//std ���̺귯���� ���Ե� ������� ���

//�Լ� ����
void swap(int& x, int& y);	//�� ���� ���� �������ִ� �Լ�
int GCD( int x,  int y);		//�� ���� �ִ������� ��ȯ�ϴ� �Լ�

int main()
{
	int x, y, LCM;				//unsigned int�� �Լ� ����
	cout << "x,y: ";
	cin >> x >> y;					//x�� y���� �Է� ����

	if (y > x)				//y�� x���� Ŭ ��쿡
		swap(x, y);		//x�� y���� �ڹٲ۴�.

	LCM = x / GCD(x, y) * y;			//LCM�� �ּҰ���� ������ �ʱ�ȭ
	cout << "GCD: " << GCD(x, y) << endl;
	cout << "LCM: " << LCM;				//�ּ� ����� �� ���
	return 0;
}
/*  x�� y���� �ڹٲ��ִ� �Լ�  */
void swap(int& x, int& y) {
	int temp = x;		//x�� ���� temp�� ����
	x = y;			//y�� ���� x�� ����
	y = temp;			//temp�� ���� y�� ����
}
/*  x�� y�� �ִ������� ��ȯ���ִ� �Լ�  */
int GCD(int x1,  int y1) {
	if (y1 == 0)		//y�� 0�϶�
		return x1;	//x�� ��ȯ��
	GCD(y1, x1 % y1);	//����Լ� ȣ��
}