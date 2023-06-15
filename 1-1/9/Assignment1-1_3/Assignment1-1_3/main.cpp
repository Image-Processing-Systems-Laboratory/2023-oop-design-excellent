#include <iostream>
#include <cstdlib>

void	input_err(void) // �Է� ����
{
	std::cerr << "Invalid input!" << std::endl;
	exit(EXIT_FAILURE);
}

int	gcd(int a, int b) // ��Ŭ���� ȣ���� Ȱ���� �ִ����� ��� �Լ�
{
	if (b == 0) // b�� 0�� ��� a�� �ִ�����
		return (a >= 0 ? a : -a);
	// �ִ������� ����̴�
	// �ش� �Լ������� ���� a�� b�� ������ ���� ���� ��� �ִ������� ������ ���� �� �ִ�.
	// �׷��� ������ ��� ������ ���� ����� -1�� ���μ��� ������ �ִ� ���·� ������ �� �����Ƿ�, 
	// ������ ���� ��� �ִ������� ����. 
	return (gcd(b, a % b));
}

long long	lcm(int a, int b) // �ּҰ������ ���ϴ� �Լ�
{
	int			gcd_val; // �ִ������� int���� �ȿ� ������ ����ȴ�
	long long	lcm_val; // �ּҰ������ overflow�߻� ���ɼ� �����Ƿ� 64bit �ڷ��� ���

	gcd_val = gcd(a, b);
	if (gcd_val == 0)
		return (0);
	lcm_val = (long long)a * (b / gcd_val); // �� ���� �ּҰ���� = �� ���� �� / �� ���� �ִ�����
	return (lcm_val < 0 ? -lcm_val : lcm_val);
	// ���� �ּҰ������ ���� ���Ѵ�� �߻��ϱ� ������, ��� �������� �ٷ��. 
	// ���� ���� ���� ���� �ּҰ������ ������ ���ϸ� ���� �ּҰ������ �ȴ�.
}

int	main(void)
{
	int	a;
	int	b;

	std::cin >> a;     // a�� �Է¹���
	if (!std::cin)     // ��ȿ���� ���� �Է�(int���°� �ƴ� �Է�)�� ��� ����ó��
		input_err();
	std::cin >> b;     // b�� �Է¹���
	if (!std::cin)     // ��ȿ���� ���� �Է�(int���°� �ƴ� �Է�)�� ��� ����ó��
		input_err();
	std::cout << "The least common multiple of " << a << " and " << b
		<< " is " << lcm(a, b) << '\n'; // �ּҰ���� ���
	return (0);
}