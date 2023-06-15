#include <iostream>

void	input_err(void) // 입력 에러 시 프로그램 종료
{
	std::cerr << "Invalid input" << std::endl;
	exit(EXIT_FAILURE);
}

int	cofactor(int input[3][3], int i, int j) // 여인수 계산
{
	int	minor[4]; // 소행렬, 1차원배열이나 논리적으로 2*2 행렬을 표현한다 
	/*
	minor[0] minor[1]
	minor[2] minor[3]
	으로 2*2 행렬 표현
	*/
	int	minor_i; // 소행렬 구성을 위한 인덱스

	minor_i = 0;
	for (int k = 0; k < 3; k++) // 입력 행렬을 순회하며 소행렬을 구한다
	{
		if (k == i)
			continue;
		for (int l = 0; l < 3; l++)
		{
			if (l == j)
				continue;
			minor[minor_i++] = input[k][l];
		}
	}
	return (minor[0] * minor[3] - minor[1] * minor[2]); // 여인수를 계산하여 출력한다
}

// 행렬식 계산 : 첫 번째 행 각 원소의 여인수들을 사용하여 구한다.
int	determinant(int input[3][3])
{
	return (input[0][0] * cofactor(input, 0, 0)
		- input[0][1] * cofactor(input, 0, 1)
		+ input[0][2] * cofactor(input, 0, 2));
}

int main(void)
{
	int		input[3][3]; // 3*3크기의 정수형 배열로 행렬 표현
	int		det; // 행렬식

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cin >> input[i][j]; // 행렬을 입력받음
			if (!std::cin)
				input_err();
		}
	}
	det = determinant(input); // 행렬식 계산
	if (det == 0) // 행렬식이 0일 경우 역행렬 존재 x
	{
		std::cout << "The inverse matrix does not exist." << std::endl; // 역행렬 없음 출력하고 종료
		return (0);
	}
	for (int i = 0; i < 3; i++) // 역행렬의 원소 계산
	{
		for (int j = 0; j < 3; j++)
		{
			//역행렬의 (i, j)원소는 (-1)^(i+j) * 입력의 (j, i)의 여인수 / 행렬식 이다 
			if ((i + j) % 2) // -1을 곱해줌
				std::cout << -cofactor(input, j, i) / (double)det << ' ';
			else
				std::cout << cofactor(input, j, i) / (double)det << ' ';
		}
		std::cout << std::endl; // 한 행 마다 개행 출력
	}
	return (0);
}