#define _USE_MATH_DEFINES // 상수 (파이) 값을 사용하기 위해 정의
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// 변수 선언
	double degree, x, y, z, nx, ny, nz;

	// 각도 및 좌표 입력
	cout << "Degrees : ";
	cin >> degree;
	cout << "Coordinate : ";
	cin >> x >> y >> z;

	// 행렬곱 계산
	nx = -cos(degree * (M_PI/180)) * x + sin(degree * (M_PI / 180)) * y;
	ny = sin(degree * (M_PI / 180)) * x + cos(degree * (M_PI / 180)) * y;
	nz = 0;
	
	// 계산한 값을 출력
	cout << nx << " " << ny << " " << nz;
	return 0;
}