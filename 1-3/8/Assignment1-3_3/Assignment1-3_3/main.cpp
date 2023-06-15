#include <iostream>
#include <string.h>

bool valid_num(const char* str, int base) // 진법에 대한 유효한 수 검증
{
	int i;

	i = 0;
	while (str[i]) // 문자열 순회
	{
		if (base <= 10 && (str[i] < '0' || str[i] > '0' + base - 1))
		{ // 만약 10 이하의 진법일 경우, 0 ~ base - 1 의 숫자를 가짐
			return (false);
		}
		else if (base > 10
			&& (str[i] < '0' || str[i] > '9')
			&& (str[i] < 'a' || str[i] > 'a' + base - 11)
			&& (str[i] < 'A' || str[i] > 'A' + base - 11))
		{ // 만약 10 이상의 진법일 경우, 0 ~ 9의 숫자와 a(A)부터 순서대로 base - 10개의 알파벳을 사용
			return (false);
		}
		i++;
	}
	return (true); // 유효한 입력
}

int	atoi_base(const char* input, int base)
{ // 문자열을 특정한 진법을 기준으로 해석하여 정수로 변환
	int res = 0;
	int i = 0;

	while (input[i]) // 최상위 자릿수부터 시작
	{
		res *= base; // 해당 진법에서 한 자릿수를 늘림
		if (input[i] >= '0' && input[i] <= '9') // 숫자일 경우 해당 숫자를 더함
			res += input[i] - '0';
		// 영어의 경우는 해당 영문자에 해당하는 값을 더함
		else if (input[i] >= 'a' && input[i] <= 'f')
			res += input[i] - 'a' + 10;
		else if (input[i] >= 'A' && input[i] <= 'F')
			res += input[i] - 'A' + 10;
		i++; // 다음 자리로 이동
	}
	return (res); // 결과 반환
}

void change_base_recursion(int input, int base)
{ // 정수를 특정한 진법으로 출력하는 함수에서 재귀부 해당
	if (input < base) // 만약 input이 한 자리로 표기가능하다면
	{
		if (input < 10) // (십진수 기준)10보다 작을 경우 그냥 수 표기
			std::cout << input;
		else // 아닐 경우 해당 값에 대응하는 영문자 표기
			std::cout << (char)('A' + (input - 10));
	}
	else // 만약 input이 두 자리 이상으로 표현된다면
	{
		change_base_recursion(input / base, base); // 일의 자리 제외한 앞부분 출력(재귀)
		if (input % base < 10) // 1의 자리 값 계산했을 때 (십진수)10보다 작을 경우
			std::cout << input % base; // 해당 수 출력
		else // 1의 자리가 (십진수에서의)10보다 큰 경우 해당하는 영문자 출력
			std::cout << (char)('A' + (input % base - 10));
	}
}

void change_base(int input, int base)
{ // input을 특정한 진법으로 출력하고, 개행을 출력
	change_base_recursion(input, base);
	std::cout << std::endl;
}

int main(void)
{
	char input[100]; // 입력을 받을 문자열
	int input_base; // 입력받는 진법
	int output_base; // 출력할 진법
	int deci_input; // 입력 문자열을 정수로 변환한 값

	// 입력할 수와 입력의 진법, 출력할 진법을 입력받음
	std::cin >> input >> input_base >> output_base;
	if (!std::cin\
		|| input_base < 2 || input_base > 16
		|| output_base < 2 || output_base > 16
		|| !valid_num(input, input_base))
	{ // 유효하지 않은 입력일 경우
		std::cerr << "Invalid input" << std::endl;
		exit(EXIT_FAILURE);
	}
	deci_input = atoi_base(input, input_base); // 입력을 입력 진법으로 해석하여 저장
	change_base(deci_input, output_base); // 입력된 값을 출력 진법으로 출력
	return (0);
}