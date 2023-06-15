#include <iostream>
#include <cmath>

int pow_int(int num, int power) // ���� ���� �Լ�
{
	int res = 1;

	while (power--) // power��ŭ num�� �����ش�
	{
		res *= num;
	}
	return (res); // num�� power���� ��ȯ
}

// �Ҽ� ��� �Լ�
// �� �ڸ����� ���� ����ִ� �迭, ��ȯ ������, ��ȯ ������, �Ҽ��� ��ġ�� ���ڷ� ����
void print_repeating(int* num, int start, int stop, int point)
{
	if (point == 0) // ���� 1���� ���� ���
		std::cout << '0'; // �Ǿ��ڸ� 0���
	if (start == -1) // ��ȯ�Ҽ��� �ƴ� ���(���ѼҼ� �� ���)
	{
		for (int i = 0; i <= stop; i++) // �ڸ��� ���� ��ȸ, �� ��� stop�� ���� ������ �ڸ�
		{
			if (i == point) // �Ҽ��� ��ġ��� �Ҽ��� ���
				std::cout << '.';
			std::cout << num[i]; // �� �ڸ����� �� ���
		}
		std::cout << std::endl;
		return;
	}
	for (int i = 0; i <= stop; i++) // ��ȯ�Ҽ��� ���
	{
		if (i == point) // �Ҽ��� ��ġ���� �Ҽ��� ǥ��
			std::cout << '.';
		if (i == start) // ��ȯ ���������� ���� ��ȣ ǥ��
			std::cout << '(';
		std::cout << num[i]; // �� �ڸ����� �� ���
	}
	std::cout << ')'; // ��ȯ ������ ǥ��
	std::cout << std::endl;
}

int point_loc(int num, int div) // �Ҽ����� ��ġ Ž��
{
	int res = 0;

	while (num >= div) // num�� div���� ū ���
	{
		res++;
		div *= 10; // div�� 10�� ���ϸ�(���� �ڸ����� �þ) ��� �ݺ�
	}
	return (res); // �������� ���̸� ����
}

void calculate_repeating(int num, int div)
{
	int remain[100] = { num };
	int result[100] = { 0 };
	int result_idx = 0;
	int point = point_loc(num, div);

	if (num == 0) // ���� ���� 0�� ��� 0���
	{
		print_repeating(result, -1, 0, -1);
		return;
	}
	if (div == 0) // 0���� ������ ��� ����
	{
		std::cout << "Cannot be divided by zero" << std::endl;
		return;
	}
	while (result_idx < 100) // �ִ� 100�ڸ��� ��ȿ���ڸ� ������
	{
		int temp_multi = 1; // 10^���� �ڸ��� (�����ο����� ���)

		if (result_idx < point) // �������� ���
			temp_multi = pow_int(10, point - result_idx - 1); // ���� �ڸ�����ŭ ����
		else // �Ҽ����� ��� �� �ڸ� �� ������ num�� 10�� ����
			num *= 10;
		result[result_idx] = (num / temp_multi) / div; // �ش� �ڸ��������� �� ���
		remain[result_idx + 1] = num % (div * temp_multi); // ���� �ڸ����� �ѱ� ������ ���
		num = remain[result_idx + 1]; // num���� �������� ����
		if (num == 0 && result_idx >= point - 1) // ���� ������ ����� ������ num�� 0�̸�(������ ��������) ���
		{
			print_repeating(result, -1, result_idx, point); // ���ѼҼ�(�Ǵ� ����)�� ���
			return;
		}
		else if (result_idx >= point) // ������ ����� ���� ��� ��ȯ�Ҽ� Ž��
		{
			for (int i = 0; i <= result_idx; i++) // ���ݱ����� ������ Ž��
			{
				// ���� ���� ���� �������� ������ �������� ���� ���, �ش� ��ġ���� ���� ��ġ���� ��ȯ ����
				if (remain[i] == remain[result_idx + 1])
				{
					print_repeating(result, i, result_idx, point); // ��ȯ ������ ���ڷ� �Ѱ� ���
					return;
				}
			}
		}
		result_idx++; // ���� �ڸ� ���
	}
}

int main(void)
{
	int Vs, R1, R2, RL;
	double Is;

	std::cout << "Vs: "; // �ҽ��� ������ �Է¹���
	std::cin >> Vs;
	std::cout << "R1: "; // R1�� ������ �Է¹���
	std::cin >> R1;
	std::cout << "R2: "; // R2�� ������ �Է¹���
	std::cin >> R2;
	std::cout << "R(Load): "; // Rload�� ������ �Է¹���
	std::cin >> RL;
	if (!std::cin) // �Է� ������ ������ ��
	{
		std::cerr << "Invalid input!" << std::endl;
		return (EXIT_FAILURE);
	}
	if (RL) // Rload �� ���� ���
	{
		std::cout << "Vout: " << Vs * R2 * RL << "/" << R1 * (R2 + RL) + R2 * RL << " = ";
		calculate_repeating(Vs * R2 * RL, R1 * (R2 + RL) + R2 * RL); // ������� ��ȯ�Ҽ� ��� �� ���
		Is = (double)Vs / (R1 + ((R2 * RL) / (R2 + RL)));
		std::cout << "Load power ratio: ";
		std::cout << std::fixed;
		std::cout.precision(2); // ��ȿ���� �Ҽ� �� ��° �ڸ����� ���
		std::cout << round(
			((Is * (((double)Vs * R2 * RL) / (R1 * (R2 + RL) + R2 * RL)) * R2 / (R2 + RL)) * 10000) / (Vs * Is)
		) / 100 << "%" << std::endl; // �Ŀ� ���� ��� �� ���
	}
	else // Rload �� ���� ���
	{
		std::cout << "Vout: " << Vs * R2 << "/" << R1 + R2 << " = ";
		calculate_repeating(Vs * R2, R1 + R2); // ������� ��ȯ�Ҽ� ��� �� ���
	}
	return (0);
}