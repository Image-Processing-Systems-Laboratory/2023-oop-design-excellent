#include <iostream>
#include <cstdlib>

void	input_err(void) // 입력 에러
{
	std::cerr << "Invalid input!" << std::endl;
	exit(EXIT_FAILURE);
}

int	gcd(int a, int b) // 유클리드 호제법 활용한 최대공약수 계산 함수
{
	if (b == 0) // b가 0일 경우 a가 최대공약수
		return (a >= 0 ? a : -a);
	// 최대공약수는 양수이다
	// 해당 함수에서는 만약 a나 b중 음수가 섞여 있을 경우 최대공약수가 음수가 나올 수 있다.
	// 그러나 음수의 경우 절댓값이 같은 양수에 -1이 소인수로 곱해져 있는 형태로 생각할 수 있으므로, 
	// 절댓값을 취할 경우 최대공약수와 같다. 
	return (gcd(b, a % b));
}

long long	lcm(int a, int b) // 최소공배수를 구하는 함수
{
	int			gcd_val; // 최대공약수는 int범위 안에 있음이 보장된다
	long long	lcm_val; // 최소공배수는 overflow발생 가능성 있으므로 64bit 자료형 사용

	gcd_val = gcd(a, b);
	if (gcd_val == 0)
		return (0);
	lcm_val = (long long)a * (b / gcd_val); // 두 수의 최소공배수 = 두 수의 곱 / 두 수의 최대공약수
	return (lcm_val < 0 ? -lcm_val : lcm_val);
	// 음수 최소공배수는 음의 무한대로 발산하기 때문에, 양수 범위에서 다룬다. 
	// 위와 같은 논리로 계산된 최소공배수에 절댓값을 취하면 실제 최소공배수가 된다.
}

int	main(void)
{
	int	a;
	int	b;

	std::cin >> a;     // a를 입력받음
	if (!std::cin)     // 유효하지 않은 입력(int형태가 아닌 입력)일 경우 예외처리
		input_err();
	std::cin >> b;     // b를 입력받음
	if (!std::cin)     // 유효하지 않은 입력(int형태가 아닌 입력)일 경우 예외처리
		input_err();
	std::cout << "The least common multiple of " << a << " and " << b
		<< " is " << lcm(a, b) << '\n'; // 최소공배수 출력
	return (0);
}