#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a, b, c, discriminant, x1, x2;

	// 입력값 받기 (a, b, c)
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	// a, b, c로 판별식 계산 후 discriminant에 저장
	discriminant = pow(b, 2) - 4 * a * c;

	cout << endl << "the roots of " << a << "x^2 + " << b << "x + " << c << " = 0 :" << endl << endl;

	// a가 0이면 문구 출력 후 프로그램 종료
	if (a == 0)
	{
		cout << "Unexpected factor of a quadratic term" << endl;
		return 0;
	}
	
	// 판별식이 0이면 중근을 출력
	if (discriminant == 0)
	{
		cout << "X1, X2: " << -b / (2 * a) << " (double root)" << endl;
	}
	// 판별식이 0보다 작으면 근이 없다고 출력
	else if (discriminant < 0)
	{
		cout << "The equation has no real number solutions." << endl;
	}
	// 판별식이 0 초과일 때 
	else
	{
		// b가 양수인 경우 근의공식 사용
		if (b > 0)
		{
			// x1을 유리화해서 계산하고, x2를 그대로 계산
			x1 = (-2 * c) / (b + sqrt(discriminant));
			x2 = (-b - sqrt(discriminant)) / (2 * a);
		}
		// b가 음수인 경우 (b == 0 이면 판별식도 음수이므로 고려 x
		else
		{
			// x1을 그대로 계산하고, x2를 유리화해서 계산
			x1 = (-b + sqrt(discriminant)) / (2 * a);
			x2 = (-2 * c) / (b - sqrt(discriminant));
		}
		// 결과 출력
		cout << "X1: " << x1 << ", X2: " << x2 << endl;
	}

	return 0;
}