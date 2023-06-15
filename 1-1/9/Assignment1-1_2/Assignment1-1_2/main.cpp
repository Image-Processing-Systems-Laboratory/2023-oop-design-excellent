#include <iostream>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cfloat>

bool	eq_f(float a, float b) // 부동소수점의 등호 비교의 경우, 부동소수점 오차를 고려하여 비교하여야 한다. 
{
	// 부동소수점의 오차는 elsilon값보다 작음이 보장된다. 
	if (a >= b)
		return (a - b < FLT_EPSILON); 
	else
		return (b - a < FLT_EPSILON);
}

void	input_err(void) // 입력 에러 시 프로그램 종료
{
	std::cerr << "Invalid input" << std::endl;
	exit(EXIT_FAILURE);
}

void	equation_solve(float a, float b, float c)
{
	float	det;

	if (eq_f(a, 0)) // a == 0인 경우 이차방정식으로서 유효하지 않음
	{
		std::cout << "Unexpected factor of a quadratic term\n";
		return ;
	}
	det = b * b - 4 * a * c; // 판별식 계산
	if (det < 0) // 판별식이 0보다 작으면 실근 없음
		std::cout << "The equation has no real number solutions.\n";
	else if (eq_f(det, 0)) // 판별식 == 0 일 경우 중근
		std::cout << "X1, X2: " << (-b - sqrt(det)) / (2 * a) << " (double root)\n"; // 근의 공식 사용
	else // 두 개의 근을 가짐
	{
		// b의 부호에 따라 유사한 수의 뺄셈 연산을 방지하기 위해 근의 공식 변형 사용(오차 작아지도록)
		if (b >= 0)
			std::cout << "X1: " << 2 * c / (-b - sqrt(det)) \
					<< ", X2: " << (-b - sqrt(det)) / (2 * a) << "\n";
		else
			std::cout << "X1: " << (-b + sqrt(det)) / (2 * a) \
					<< ", X2: " << 2 * c / (-b + sqrt(det)) << "\n";
	}
		
}

int	main(void)
{
	float	a;
	float	b;
	float	c;

	// a, b, c를 입력받음
	std::cout << "a: "; // 프롬프트
	std::cin >> a;     // a를 입력받음
	if (!std::cin)     // 유효하지 않은 입력(float형태가 아닌 입력)일 경우 예외처리
		input_err();
	std::cout << "b: ";
	std::cin >> b;
	if (!std::cin)
		input_err();
	std::cout << "c: ";
	std::cin >> c;
	if (!std::cin)
		input_err();
	equation_solve(a, b, c); // a, b, c를 계수로 가지는 이차방정식의 근을 출력
}