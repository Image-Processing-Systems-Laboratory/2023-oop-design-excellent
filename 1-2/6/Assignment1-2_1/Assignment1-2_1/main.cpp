#include <iostream>

void	input_err(void) // ���� ó�� �Լ�
{
	std::cerr << "Invaild input!" << std::endl;
	exit(EXIT_FAILURE);
}

int main(void)
{
	char	input1[100]; // ù ��° �Է�
	char	input2[100]; // �� ��° �Է�
	int		count[10] = { 0 }; // ���� ���� ������ ��
	bool	exist[10] = { 0 }; // ���� ������ ���� Ȯ��
	int		order[10] = { // �պ��� ���� ���� ���ʷ� ä��
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1
	};
	int		order_idx = 0; // ���� ������ ����
	int		i; // �ε���

	std::cin >> input1 >> input2; // �� �Է��� ����
	if (!std::cin) // �Է� ����
		input_err();
	i = 0;
	while (input1[i]) // ù ��° �Է� ��ȸ
	{
		if (input1[i] < '0' || input1[i] > '9') // ���� �ƴ� ��� ����
			input_err();
		count[input1[i] - '0']++; // �ش��ϴ� ���� ī��Ʈ
		if (exist[input1[i] - '0']) // ���� �̹� ���Դ� ���ڸ� �Ѿ
		{
			i++;
			continue;
		}
		exist[input1[i] - '0'] = true; // ó�� ������ ���� ���
		order[order_idx++] = input1[i] - '0'; // �� ��°�� ���Դ��� ���
		i++;
	}
	// input2�� ���ؼ��� input1�� ���� ���� �ݺ�
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
	while (i < 10 && order[i] != -1) // ���� ���� ������� ��ȸ
	{
		std::cout << order[i] << count[order[i]]; // ���� ���� ���� ������ ���
		i++;
	}
	std::cout << std::endl;
	return (0);
}