#include <iostream>
#include <cmath>

int pow_int(int num, int power) // 정수 제곱 함수
{
	int res = 1;

	while (power--) // power만큼 num을 곱해준다
	{
		res *= num;
	}
	return (res); // num의 power제곱 반환
}

// 소수 출력 함수
// 각 자릿수의 수가 들어있는 배열, 순환 시작점, 순환 종료점, 소숫점 위치를 인자로 받음
void print_repeating(int* num, int start, int stop, int point)
{
	if (point == 0) // 수가 1보다 작은 경우
		std::cout << '0'; // 맨앞자리 0출력
	if (start == -1) // 순환소수가 아닌 경우(유한소수 인 경우)
	{
		for (int i = 0; i <= stop; i++) // 자릿수 값을 순회, 이 경우 stop이 수의 마지막 자리
		{
			if (i == point) // 소수점 위치라면 소수점 출력
				std::cout << '.';
			std::cout << num[i]; // 각 자릿수별 값 출력
		}
		std::cout << std::endl;
		return;
	}
	for (int i = 0; i <= stop; i++) // 순환소수의 경우
	{
		if (i == point) // 소수점 위치에서 소수점 표시
			std::cout << '.';
		if (i == start) // 순환 시작점에서 여는 괄호 표시
			std::cout << '(';
		std::cout << num[i]; // 각 자릿수의 수 출력
	}
	std::cout << ')'; // 순환 종료점 표기
	std::cout << std::endl;
}

int point_loc(int num, int div) // 소수점의 위치 탐색
{
	int res = 0;

	while (num >= div) // num이 div보다 큰 경우
	{
		res++;
		div *= 10; // div에 10을 곱하며(몫의 자릿수가 늘어남) 계속 반복
	}
	return (res); // 정수부의 길이를 리턴
}

void calculate_repeating(int num, int div)
{
	int remain[100] = { num };
	int result[100] = { 0 };
	int result_idx = 0;
	int point = point_loc(num, div);

	if (num == 0) // 나눌 수가 0인 경우 0출력
	{
		print_repeating(result, -1, 0, -1);
		return;
	}
	if (div == 0) // 0으로 나누는 경우 에러
	{
		std::cout << "Cannot be divided by zero" << std::endl;
		return;
	}
	while (result_idx < 100) // 최대 100자리의 유효숫자를 인지함
	{
		int temp_multi = 1; // 10^현재 자릿수 (정수부에서만 사용)

		if (result_idx < point) // 정수부의 경우
			temp_multi = pow_int(10, point - result_idx - 1); // 현재 자릿수만큼 제곱
		else // 소수부의 경우 한 자리 갈 때마다 num에 10을 곱함
			num *= 10;
		result[result_idx] = (num / temp_multi) / div; // 해당 자릿수에서의 몫 계산
		remain[result_idx + 1] = num % (div * temp_multi); // 다음 자릿수로 넘길 나머지 계산
		num = remain[result_idx + 1]; // num에는 나머지만 남음
		if (num == 0 && result_idx >= point - 1) // 만약 정수부 계산이 끝났고 num이 0이면(나누어 떨어지면) 출력
		{
			print_repeating(result, -1, result_idx, point); // 유한소소(또는 정수)의 출력
			return;
		}
		else if (result_idx >= point) // 정수부 계산이 끝난 경우 순환소수 탐색
		{
			for (int i = 0; i <= result_idx; i++) // 지금까지의 나머지 탐색
			{
				// 만약 현재 나온 나머지와 동일한 나머지가 있을 경우, 해당 위치부터 현재 위치까지 순환 구간
				if (remain[i] == remain[result_idx + 1])
				{
					print_repeating(result, i, result_idx, point); // 순환 구간을 인자로 넘겨 출력
					return;
				}
			}
		}
		result_idx++; // 다음 자리 계산
	}
}

int main(void)
{
	int Vs, R1, R2, RL;
	double Is;

	std::cout << "Vs: "; // 소스의 전압을 입력받음
	std::cin >> Vs;
	std::cout << "R1: "; // R1의 저항을 입력받음
	std::cin >> R1;
	std::cout << "R2: "; // R2의 저항을 입력받음
	std::cin >> R2;
	std::cout << "R(Load): "; // Rload의 저항을 입력받음
	std::cin >> RL;
	if (!std::cin) // 입력 오류가 생겼을 때
	{
		std::cerr << "Invalid input!" << std::endl;
		return (EXIT_FAILURE);
	}
	if (RL) // Rload 가 있을 경우
	{
		std::cout << "Vout: " << Vs * R2 * RL << "/" << R1 * (R2 + RL) + R2 * RL << " = ";
		calculate_repeating(Vs * R2 * RL, R1 * (R2 + RL) + R2 * RL); // 출력전압 순환소수 계산 및 출력
		Is = (double)Vs / (R1 + ((R2 * RL) / (R2 + RL)));
		std::cout << "Load power ratio: ";
		std::cout << std::fixed;
		std::cout.precision(2); // 유효숫자 소수 두 번째 자리까지 출력
		std::cout << round(
			((Is * (((double)Vs * R2 * RL) / (R1 * (R2 + RL) + R2 * RL)) * R2 / (R2 + RL)) * 10000) / (Vs * Is)
		) / 100 << "%" << std::endl; // 파워 비율 계산 및 출력
	}
	else // Rload 가 없을 경우
	{
		std::cout << "Vout: " << Vs * R2 << "/" << R1 + R2 << " = ";
		calculate_repeating(Vs * R2, R1 + R2); // 출력전압 순환소수 계산 및 출력
	}
	return (0);
}