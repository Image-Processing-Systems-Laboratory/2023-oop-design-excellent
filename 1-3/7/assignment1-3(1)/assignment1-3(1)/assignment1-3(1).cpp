#include<iostream>
#include<cmath>

using namespace std;


int main()
{
	const double PI = 3.1415926;
	double degree;
	double sin_;
	double cos_;
	double x, y, z;		//z는 사실상 의미 없는 값
	double result_x, result_y;

	//입력
	cout << "Degrees:";
	cin >> degree;
	cout << "Coordinate:";
	cin >> x >> y >> z;
	
	// degree 단위를 라디안으로 치환 후 반올림
	sin_ = sin(degree * PI / 180);
	cos_ = cos(degree * PI / 180);
	sin_ = round(sin_ * 10000) / 10000;
	cos_ = round(cos_ * 10000) / 10000;
	
	//행렬대로 연산 후 출력
	result_x = (-1 * cos_ * x) + (sin_ * y);
	result_y = (sin_ * x) + (cos_ * y);
	if (result_x == 0)
		result_x = 0;
	if (result_y == 0)
		result_y = 0;
	cout << result_x << " " << result_y << " " << 0;
}