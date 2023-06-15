#include <iostream>

void	input_err(void) // �Է� ���� �� ���α׷� ����
{
	std::cerr << "Invalid input" << std::endl;
	exit(EXIT_FAILURE);
}

int	cofactor(int input[3][3], int i, int j) // ���μ� ���
{
	int	minor[4]; // �����, 1�����迭�̳� �������� 2*2 ����� ǥ���Ѵ� 
	/*
	minor[0] minor[1]
	minor[2] minor[3]
	���� 2*2 ��� ǥ��
	*/
	int	minor_i; // ����� ������ ���� �ε���

	minor_i = 0;
	for (int k = 0; k < 3; k++) // �Է� ����� ��ȸ�ϸ� ������� ���Ѵ�
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
	return (minor[0] * minor[3] - minor[1] * minor[2]); // ���μ��� ����Ͽ� ����Ѵ�
}

// ��Ľ� ��� : ù ��° �� �� ������ ���μ����� ����Ͽ� ���Ѵ�.
int	determinant(int input[3][3])
{
	return (input[0][0] * cofactor(input, 0, 0)
		- input[0][1] * cofactor(input, 0, 1)
		+ input[0][2] * cofactor(input, 0, 2));
}

int main(void)
{
	int		input[3][3]; // 3*3ũ���� ������ �迭�� ��� ǥ��
	int		det; // ��Ľ�

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cin >> input[i][j]; // ����� �Է¹���
			if (!std::cin)
				input_err();
		}
	}
	det = determinant(input); // ��Ľ� ���
	if (det == 0) // ��Ľ��� 0�� ��� ����� ���� x
	{
		std::cout << "The inverse matrix does not exist." << std::endl; // ����� ���� ����ϰ� ����
		return (0);
	}
	for (int i = 0; i < 3; i++) // ������� ���� ���
	{
		for (int j = 0; j < 3; j++)
		{
			//������� (i, j)���Ҵ� (-1)^(i+j) * �Է��� (j, i)�� ���μ� / ��Ľ� �̴� 
			if ((i + j) % 2) // -1�� ������
				std::cout << -cofactor(input, j, i) / (double)det << ' ';
			else
				std::cout << cofactor(input, j, i) / (double)det << ' ';
		}
		std::cout << std::endl; // �� �� ���� ���� ���
	}
	return (0);
}