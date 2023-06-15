#include<iostream>
#include<cmath>		//pow,sqrt함수 사용
int main()
{
	float a, b, c;
	float D;		//판별식 b^2-4ac
	std::cout << "a:";
	std::cin >> a;
	std::cout << "b:";
	std::cin >> b;
	std::cout << "c:";
	std::cin >> c;

	D = pow(b, 2) - (4 * a * c);

	if (a == 0)				//근의공식 밑변이 0일때
		std::cout << "Unexpected factor of a quadratic term";
	else if (D < 0)			//판별식이 0보다 작을 때(허근)
		std::cout << "The equation has no real number solutions";
	else if (D == 0)		//판별식이 0일 때 중근(double root)
	{
		if (-b / (2 * a) == 0)		//값이 -0 일때 그대로 출력되므로 예외처리
			std::cout << "X1,X2:0 (double root)";
		else
			std::cout << "X1,X2:" << -b / (2 * a) << " (double root)";
	}
	else
	{
		if (b > 0)		//b가 0보다 크면  -b+sqrt(D)가 뺄셈 연산이 되기 때문에 분자,분모에 b+sqrt(D)를 곱해서 덧셈형식으로 바꿔준다. =>약분까지 하면 (-2*c)/(b+sqrt(D))
			std::cout << "X1:" << (-2 * c) / (b + sqrt(D)) << ",X2:" << (-b - sqrt(D)) / (2 * a);
		else if (b < 0)		//b가 0보다 작으면 -b-sqrt(D)가 뺄셈 연산이 되기 떄문에 분자,분모에 b-sqrt(D)를 곱해서 덧셈형식으로 바꿔준다.
			std::cout << "X1:" << (-b + sqrt(D)) / (2 * a) << ", X2:" << (-2 * c) / (b - sqrt(D));
		else
			std::cout << "X1:" << -sqrt(D) / (2 * a) << ",X2:" << sqrt(D) / (2 * a);		//b가 0일 때 
	}
	return 0;
}