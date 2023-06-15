#include <iostream> //iostream ����
#include<cmath> //cmath ����
using namespace std; //namespace std ����

int main() //main�Լ� ����
{
	float a, b, c = 0; //�Ǽ� 
	cout << "Enter a,b,c(ax^2+bx+c=0)" << endl; //�ȳ��� ���
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c; //������� ������������ �� ���� ����� �Է¹޽��ϴ�.

	float d = pow(b, 2) - 4.0 * a * c; //�Ǻ����� d��� �����߽��ϴ�.
	float result1 = 0;
	float result2 = 0; //����� ���� ����

	if (b > 0)
	{
		result1 = 2 * c / ((-b) - sqrt(d));
		result2 = (-b - sqrt(d)) / (a * 2);
	}
	else
	{
		result1 = (-b + sqrt(d)) / (a * 2);
		result2 = 2 * c / ((-b) + sqrt(d));
	}
	//������ �� ���� �� ���� ������ ���ϱ� ���� b�� ��ȣ�� ���� ���� �ٲ���ϴ�.
	//�ڼ��� �������� ������ �������ϴ�.

	if (a == 0) //a�� 0�̾��� ��
		cout << "Unexpected factor of a quadratic term"; //���ǿ� �°� �ȳ��� ���
	else if (d > 0) //�Ǻ����� ����̸�
		cout << "X1: " << result1 << ", X2: " << result2 << endl; //�� ���� ���� ���
	else if (d == 0) // �Ǻ����� 0�̸�
		cout << "X1, X2: " << result1<<" (double root)" << endl; //�߱��� ���
	else //�� ���� ���, �Ǻ����� �����̸�
		cout << "The equation has no real number solutions"; //�ȳ��� ���

	return 0; //0�� ��ȯ
}//main �Լ� ����