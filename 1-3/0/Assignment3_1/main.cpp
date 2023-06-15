#include<iostream>
#include<cmath>
using namespace std;

int main(void)
{
	double PI = acos(-1);
	
	double degree = 0;
	double x = 0, y = 0, z = 0;

	// 원하는 값을 입력받음
	cout << "Degrees: ";
	cin >> degree;
	cout << "Coordinate: ";
	cin >> x >> y >> z;

	while (degree > 360)	// 오차를 줄이기 위한 반복문
		degree -= 360;
	while (degree < -360)
		degree += 360;

	// 문제에서 제시된 행렬에 따라 matrix transformation을 출력함
	cout << (-1) * x * cos((PI) / 180*degree) + sin((PI) / 180 * degree) * y<<' ';
	cout << x * sin((PI) / 180 * degree) + y * cos((PI) / 180 * degree)<<' ';
	cout << 0;

	return 0;

}