#include<iostream>
#include<cmath>

using namespace std;		//std ���̺귯���� ���Ե� ������� ���
//�Լ� ����
void CheckEquaSolu(float a, float b, float c);	//a,b,c�� ���� ������������ �ؿ� ���� ����� ����ϴ� �Լ�
void Print_Question(float a,float b,float c);	//a,b,c�� ���� ������������ ����ϴ� �Լ�
float X1(float a, float b, float c);			//a,b,c�� ���� ������������ ù��° �� X1�� ��ȯ�ϴ� �Լ�
float X2(float a, float b, float c);			//a,b,c�� ���� ������������ ù��° �� X2�� ��ȯ�ϴ� �Լ�

int main()
{
	float a, b, c;			//float�� ���� ����
	cout << "a: "; cin >> a;		//a�� ���� �Է¹���
	cout << "b: "; cin >> b;		//b�� ���� �Է¹���
	cout << "c: "; cin >> c;		//c�� ���� �Է¹���
	Print_Question(a, b, c);		//a,b,c�� ���� ������������ ���
	CheckEquaSolu(a, b, c);			//a,b,c�� ���� ������������ �ؿ� ���� ����� ���
	return 0;
}
/*  a,b,c�� ���� ������������ �ؿ� ���� ����� ����ϴ� �Լ�  */
void CheckEquaSolu(float a, float b, float c) {
	float D = b * b - 4 * a * c;		//�Ǻ����� float�� ���� D�� ����
	if (a == 0)			//a�� 0�� ���
	{
		cout << "Unexpected factor of a quadratic term" << endl;
		exit(0);		//���α׷��� ������
	}
	if (D < 0)		//�Ǻ����� ������ ��� (���)
	{
		cout << "The equation has no real number solutions." << endl;
		exit(0);
	}
	else if (D > 0)		//�Ǻ����� ����� ��� (�Ǳ�)
		cout << "X1: " << X1(a, b, c) << ", X2: " << X2(a, b, c) << endl;
	else				//�Ǻ����� 0�� ��� (�߱�)
		cout << "X1,X2: " << X1(a, b, c) << "(double root)" << endl;
}
/*  a,b,c�� ���� ������������ ����ϴ� �Լ�  */
void Print_Question(float a, float b, float c) {
	cout << "the roots of " << a << "x^2";
	if (b > 0)		//b�� ����ϰ��
		cout << " +";
	cout << ' ' << b << "x";
	if (c > 0)		//c�� ����ϰ��
		cout << " +";
	cout << ' ' << c << " = 0" << endl;
}
/*  a,b,c�� ���� ������������ ù��° �� X1�� ��ȯ�ϴ� �Լ�  */
float X1(float a, float b, float c) {
	float Sqrt_D = sqrt(b * b - 4 * a * c);
	float q;
	if (b > 0)			//b�� ������
		return (2 * c) / (-b - Sqrt_D);			//(2 * c) / (-b - Sqrt_D)�� ��ȯ��
	else if (b < 0)		//b�� �������
		return (2 * c) / (-b + Sqrt_D);			//(2 * c) / (-b + Sqrt_D)�� ��ȯ��
}	
/*  a,b,c�� ���� ������������ ù��° �� X2�� ��ȯ�ϴ� �Լ�  */
float X2(float a, float b, float c) {
	float Sqrt_D = sqrt(b * b - 4 * a * c);
	float q;
	if (b > 0)			//b�� ������
		return  (-b - Sqrt_D) / (2 * a);		//(-b - Sqrt_D) / (2 * a)�� ��ȯ��
	else if (b < 0)		//b�� �������
		return  (-b + Sqrt_D) / (2 * a);		//(-b + Sqrt_D) / (2 * a)�� ��ȯ��
}