#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	const double PI = 3.14159265358979323846264338327950;

	double T[3][3] = { 0 }; // matrix T를 담을 3x3 배열을 0으로 초기화
	double coordinate[3]; // Coordinate 값 3개를 담을 길이가 3인 배열
	double degrees; // Degrees값을 저장할 변수
	
	/*degrees 입력, 라디안으로 변환*/
	cout << "Degrees: "; cin >> degrees;
	degrees = PI * degrees / 180;

	/*coordinate 입력*/
	cout << "Coordinate: ";
	for (int i = 0; i < 3; i++)
		cin >> coordinate[i];
	
	/*matrix T를 조건에 맞게 채워줌*/
	T[0][0] = -cos(degrees); T[0][1] = sin(degrees);
	T[1][0] = sin(degrees); T[1][1] = cos(degrees);
	
	/*행렬곱은 전행렬의 행의 요소들과 후행렬의 열의 요소들을 곱해 더하는 과정이다.*/
	for (int i = 0; i < 3; i++) { // i는 matrix T의 행
		double sum = 0;
		for (int j = 0; j < 3; j++) { // j는 matrix T의 열이자 coordinate의 행
			sum += T[i][j] * coordinate[j];
		}
		cout << round(sum) << " ";
	}
}