#include <iostream>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cfloat>

bool	eq_f(float a, float b) // �ε��Ҽ����� ��ȣ ���� ���, �ε��Ҽ��� ������ ����Ͽ� ���Ͽ��� �Ѵ�. 
{
	// �ε��Ҽ����� ������ elsilon������ ������ ����ȴ�. 
	if (a >= b)
		return (a - b < FLT_EPSILON); 
	else
		return (b - a < FLT_EPSILON);
}

void	input_err(void) // �Է� ���� �� ���α׷� ����
{
	std::cerr << "Invalid input" << std::endl;
	exit(EXIT_FAILURE);
}

void	equation_solve(float a, float b, float c)
{
	float	det;

	if (eq_f(a, 0)) // a == 0�� ��� �������������μ� ��ȿ���� ����
	{
		std::cout << "Unexpected factor of a quadratic term\n";
		return ;
	}
	det = b * b - 4 * a * c; // �Ǻ��� ���
	if (det < 0) // �Ǻ����� 0���� ������ �Ǳ� ����
		std::cout << "The equation has no real number solutions.\n";
	else if (eq_f(det, 0)) // �Ǻ��� == 0 �� ��� �߱�
		std::cout << "X1, X2: " << (-b - sqrt(det)) / (2 * a) << " (double root)\n"; // ���� ���� ���
	else // �� ���� ���� ����
	{
		// b�� ��ȣ�� ���� ������ ���� ���� ������ �����ϱ� ���� ���� ���� ���� ���(���� �۾�������)
		if (b >= 0)
			std::cout << "X1: " << 2 * c / (-b - sqrt(det)) \
					<< ", X2: " << (-b - sqrt(det)) / (2 * a) << "\n";
		else
			std::cout << "X1: " << (-b + sqrt(det)) / (2 * a) \
					<< ", X2: " << 2 * c / (-b + sqrt(det)) << "\n";
	}
		
}

int	main(void)
{
	float	a;
	float	b;
	float	c;

	// a, b, c�� �Է¹���
	std::cout << "a: "; // ������Ʈ
	std::cin >> a;     // a�� �Է¹���
	if (!std::cin)     // ��ȿ���� ���� �Է�(float���°� �ƴ� �Է�)�� ��� ����ó��
		input_err();
	std::cout << "b: ";
	std::cin >> b;
	if (!std::cin)
		input_err();
	std::cout << "c: ";
	std::cin >> c;
	if (!std::cin)
		input_err();
	equation_solve(a, b, c); // a, b, c�� ����� ������ ������������ ���� ���
}