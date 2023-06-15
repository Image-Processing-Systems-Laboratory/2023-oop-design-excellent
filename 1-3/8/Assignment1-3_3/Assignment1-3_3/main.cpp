#include <iostream>
#include <string.h>

bool valid_num(const char* str, int base) // ������ ���� ��ȿ�� �� ����
{
	int i;

	i = 0;
	while (str[i]) // ���ڿ� ��ȸ
	{
		if (base <= 10 && (str[i] < '0' || str[i] > '0' + base - 1))
		{ // ���� 10 ������ ������ ���, 0 ~ base - 1 �� ���ڸ� ����
			return (false);
		}
		else if (base > 10
			&& (str[i] < '0' || str[i] > '9')
			&& (str[i] < 'a' || str[i] > 'a' + base - 11)
			&& (str[i] < 'A' || str[i] > 'A' + base - 11))
		{ // ���� 10 �̻��� ������ ���, 0 ~ 9�� ���ڿ� a(A)���� ������� base - 10���� ���ĺ��� ���
			return (false);
		}
		i++;
	}
	return (true); // ��ȿ�� �Է�
}

int	atoi_base(const char* input, int base)
{ // ���ڿ��� Ư���� ������ �������� �ؼ��Ͽ� ������ ��ȯ
	int res = 0;
	int i = 0;

	while (input[i]) // �ֻ��� �ڸ������� ����
	{
		res *= base; // �ش� �������� �� �ڸ����� �ø�
		if (input[i] >= '0' && input[i] <= '9') // ������ ��� �ش� ���ڸ� ����
			res += input[i] - '0';
		// ������ ���� �ش� �����ڿ� �ش��ϴ� ���� ����
		else if (input[i] >= 'a' && input[i] <= 'f')
			res += input[i] - 'a' + 10;
		else if (input[i] >= 'A' && input[i] <= 'F')
			res += input[i] - 'A' + 10;
		i++; // ���� �ڸ��� �̵�
	}
	return (res); // ��� ��ȯ
}

void change_base_recursion(int input, int base)
{ // ������ Ư���� �������� ����ϴ� �Լ����� ��ͺ� �ش�
	if (input < base) // ���� input�� �� �ڸ��� ǥ�Ⱑ���ϴٸ�
	{
		if (input < 10) // (������ ����)10���� ���� ��� �׳� �� ǥ��
			std::cout << input;
		else // �ƴ� ��� �ش� ���� �����ϴ� ������ ǥ��
			std::cout << (char)('A' + (input - 10));
	}
	else // ���� input�� �� �ڸ� �̻����� ǥ���ȴٸ�
	{
		change_base_recursion(input / base, base); // ���� �ڸ� ������ �պκ� ���(���)
		if (input % base < 10) // 1�� �ڸ� �� ������� �� (������)10���� ���� ���
			std::cout << input % base; // �ش� �� ���
		else // 1�� �ڸ��� (������������)10���� ū ��� �ش��ϴ� ������ ���
			std::cout << (char)('A' + (input % base - 10));
	}
}

void change_base(int input, int base)
{ // input�� Ư���� �������� ����ϰ�, ������ ���
	change_base_recursion(input, base);
	std::cout << std::endl;
}

int main(void)
{
	char input[100]; // �Է��� ���� ���ڿ�
	int input_base; // �Է¹޴� ����
	int output_base; // ����� ����
	int deci_input; // �Է� ���ڿ��� ������ ��ȯ�� ��

	// �Է��� ���� �Է��� ����, ����� ������ �Է¹���
	std::cin >> input >> input_base >> output_base;
	if (!std::cin\
		|| input_base < 2 || input_base > 16
		|| output_base < 2 || output_base > 16
		|| !valid_num(input, input_base))
	{ // ��ȿ���� ���� �Է��� ���
		std::cerr << "Invalid input" << std::endl;
		exit(EXIT_FAILURE);
	}
	deci_input = atoi_base(input, input_base); // �Է��� �Է� �������� �ؼ��Ͽ� ����
	change_base(deci_input, output_base); // �Էµ� ���� ��� �������� ���
	return (0);
}