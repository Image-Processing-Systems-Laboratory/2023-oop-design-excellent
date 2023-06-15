#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float   a, b, c;
	float 	x1, x2;

	cout << "Input(a, b, c): ";
	cin >> a >> b >> c; // a, b, c를 공백을 기준으로 순차적으로 입력받음(scanf처럼)
	if (a == 0)
		cout << "Unexpected factor of a quadratic term" << endl;
	// a == 0이면 근의 공식에서 분모가 0이 되므로 성립 불가
	else if (pow(b, 2) - 4 * a * c < 0)
		cout << "The equation has no real number solutions." << endl;
	// b^2 -4ac < 0이면 근의 공식에서 루트 안이 음수가 되므로 허수가 생겨 실근은 없음
	else
	{
		if (b < 0)
		{
			x1 = (-1 * b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
			x2 = (4 * a * c) / (2 * a * (-1 * b + sqrt(pow(b, 2) - 4 * a * c)));
		}
		// b < 0일 때, 루트 앞에 -가 붙는 근(x2)을 계산하면 유사한 수의 뺄셈이 이루어 질 수 있음
		// (예: a = 1, b = -62.1, c = 1)
		// 이때 분자를 유리화 해서 유사한 수의 뺄셈을 유사한 수의 덧셈으로 바꾸면 오차 최소화
		else
		{
			x1 = (-4 * a * c) / (2 * a * (b + sqrt(pow(b, 2) - 4 * a * c)));
			x2 = (-1 * b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		}
		// b >= 0일 때, 루트 앞에 +가 붙는 근(x2)을 계산하면 유사한 수의 뺄셈이 이루어 질 수 있음
		// (예: a = 1, b = 62.1, c = 1)
		// 이때 분자를 유리화 해서 유사한 수의 뺄셈을 유사한 수의 덧셈으로 바꾸면 오차 최소화
		if (x1 == x2)
			cout << "x1, x2: " << x1 << "(double root)" << endl;
		else
			cout << "x1: " << x1 << " x2: " << x2 << endl;
	}
	return (0);
}