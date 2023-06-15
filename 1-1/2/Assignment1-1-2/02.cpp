#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	float a, b, c;

	cout << "a: "; cin >> a; //x제곱의 계수
	cout << "b: "; cin >> b; // x의 계수
	cout << "c: "; cin >> c; // 상수

	if (a == 0) // a = 0이면 일차방정식이 된다.
		cout << "Unexpected factor of a quadratic term" << endl;
	else if (pow(b, 2) < 4 * a * c) // 판별식 D < 0 이면 해가 존재하지 않음
		cout << "The equation has no real number solutions." << endl;
	else if (pow(b, 2) == 4 * a * c) // 판별식 D = 0 이면 중근을 가진다.
		cout << "X1, X2: " << (-b  / (2 * a)) << " (double root)" << endl;
	else // 판별식 D > 0 이면 서로 다른 두 실근을 가진다.
	{
		cout << "X1: " << (-4 * a * c) / ((2 * a) * (b + (sqrt(pow(b, 2) - 4 * a * c)))) << ", ";
		cout << "X2: " << (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) << endl;
	}
}