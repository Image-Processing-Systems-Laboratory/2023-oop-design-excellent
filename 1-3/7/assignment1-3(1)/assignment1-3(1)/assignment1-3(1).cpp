#include<iostream>
#include<cmath>

using namespace std;


int main()
{
	const double PI = 3.1415926;
	double degree;
	double sin_;
	double cos_;
	double x, y, z;		//z�� ��ǻ� �ǹ� ���� ��
	double result_x, result_y;

	//�Է�
	cout << "Degrees:";
	cin >> degree;
	cout << "Coordinate:";
	cin >> x >> y >> z;
	
	// degree ������ �������� ġȯ �� �ݿø�
	sin_ = sin(degree * PI / 180);
	cos_ = cos(degree * PI / 180);
	sin_ = round(sin_ * 10000) / 10000;
	cos_ = round(cos_ * 10000) / 10000;
	
	//��Ĵ�� ���� �� ���
	result_x = (-1 * cos_ * x) + (sin_ * y);
	result_y = (sin_ * x) + (cos_ * y);
	if (result_x == 0)
		result_x = 0;
	if (result_y == 0)
		result_y = 0;
	cout << result_x << " " << result_y << " " << 0;
}