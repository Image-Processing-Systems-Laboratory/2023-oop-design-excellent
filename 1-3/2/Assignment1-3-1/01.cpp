#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	const double PI = 3.14159265358979323846264338327950;

	double T[3][3] = { 0 }; // matrix T�� ���� 3x3 �迭�� 0���� �ʱ�ȭ
	double coordinate[3]; // Coordinate �� 3���� ���� ���̰� 3�� �迭
	double degrees; // Degrees���� ������ ����
	
	/*degrees �Է�, �������� ��ȯ*/
	cout << "Degrees: "; cin >> degrees;
	degrees = PI * degrees / 180;

	/*coordinate �Է�*/
	cout << "Coordinate: ";
	for (int i = 0; i < 3; i++)
		cin >> coordinate[i];
	
	/*matrix T�� ���ǿ� �°� ä����*/
	T[0][0] = -cos(degrees); T[0][1] = sin(degrees);
	T[1][0] = sin(degrees); T[1][1] = cos(degrees);
	
	/*��İ��� ������� ���� ��ҵ�� ������� ���� ��ҵ��� ���� ���ϴ� �����̴�.*/
	for (int i = 0; i < 3; i++) { // i�� matrix T�� ��
		double sum = 0;
		for (int j = 0; j < 3; j++) { // j�� matrix T�� ������ coordinate�� ��
			sum += T[i][j] * coordinate[j];
		}
		cout << round(sum) << " ";
	}
}