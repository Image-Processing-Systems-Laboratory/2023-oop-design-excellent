#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265358979 // 파이값

int main() {
	double degrees;// degree는 int 인가?
	int x, y, z;

	cout << "Degrees: ";
	cin >> degrees;

	degrees = degrees * PI / 180; //라디안 값으로 변경
	double T[3][3] = { {-cos(degrees), sin(degrees), 0}, {sin(degrees), cos(degrees), 0}, {0, 0, 0} }; // 문제에 주어진 정의에 따른 행렬

	cout << "Coordinate: ";
	cin >> x >> y >> z; // 좌표 입력

	for (int i = 0; i < 3; i++) {
		T[i][0] = T[i][0] * x + T[i][1] * y + T[i][2] * z;

		//소수 다섯째 자리까지 반올림하기
		T[i][0] *= 100000;
		T[i][0] = floor(T[i][0] + 0.5);
		T[i][0] /= 100000;

	}

	// 출력
	cout << endl << endl << "output: " << T[0][0] << ' ' << T[1][0] << ' ' << T[2][0] << endl << endl;

}