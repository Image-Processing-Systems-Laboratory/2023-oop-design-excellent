#include <iostream>

void	input_err(void) // 에러 처리 함수
{
	std::cerr << "Invaild input!" << std::endl;
	exit(EXIT_FAILURE);
}

int main(void)
{
	char	input1[100]; // 첫 번째 입력
	char	input2[100]; // 두 번째 입력
	int		count[10] = { 0 }; // 나온 수의 갯수를 셈
	bool	exist[10] = { 0 }; // 수가 나온지 여부 확인
	int		order[10] = { // 앞부터 수가 나온 차례로 채움
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1
	};
	int		order_idx = 0; // 나온 숫자의 종류
	int		i; // 인덱스

	std::cin >> input1 >> input2; // 두 입력을 받음
	if (!std::cin) // 입력 에러
		input_err();
	i = 0;
	while (input1[i]) // 첫 번째 입력 순회
	{
		if (input1[i] < '0' || input1[i] > '9') // 수가 아닐 경우 에러
			input_err();
		count[input1[i] - '0']++; // 해당하는 수를 카운트
		if (exist[input1[i] - '0']) // 만약 이미 나왔던 숫자면 넘어감
		{
			i++;
			continue;
		}
		exist[input1[i] - '0'] = true; // 처음 나오는 수면 기록
		order[order_idx++] = input1[i] - '0'; // 몇 번째로 나왔는지 기록
		i++;
	}
	// input2에 대해서도 input1과 같은 과정 반복
	i = 0;
	while (input2[i])
	{
		if (input2[i] < '0' || input2[i] > '9')
			input_err();
		count[input2[i] - '0']++;
		if (exist[input2[i] - '0'])
		{
			i++;
			continue;
		}
		exist[input2[i] - '0'] = true;
		order[order_idx++] = input2[i] - '0';
		i++;
	}
	i = 0;
	while (i < 10 && order[i] != -1) // 나온 수를 순서대로 순회
	{
		std::cout << order[i] << count[order[i]]; // 나온 수와 나온 갯수를 출력
		i++;
	}
	std::cout << std::endl;
	return (0);
}