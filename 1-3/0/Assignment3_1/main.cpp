#include<iostream>
#include<cmath>
using namespace std;

int main(void)
{
	double PI = acos(-1);
	
	double degree = 0;
	double x = 0, y = 0, z = 0;

	// ���ϴ� ���� �Է¹���
	cout << "Degrees: ";
	cin >> degree;
	cout << "Coordinate: ";
	cin >> x >> y >> z;

	while (degree > 360)	// ������ ���̱� ���� �ݺ���
		degree -= 360;
	while (degree < -360)
		degree += 360;

	// �������� ���õ� ��Ŀ� ���� matrix transformation�� �����
	cout << (-1) * x * cos((PI) / 180*degree) + sin((PI) / 180 * degree) * y<<' ';
	cout << x * sin((PI) / 180 * degree) + y * cos((PI) / 180 * degree)<<' ';
	cout << 0;

	return 0;

}