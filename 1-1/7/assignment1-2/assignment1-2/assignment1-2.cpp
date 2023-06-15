#include<iostream>
#include<cmath>		//pow,sqrt�Լ� ���
int main()
{
	float a, b, c;
	float D;		//�Ǻ��� b^2-4ac
	std::cout << "a:";
	std::cin >> a;
	std::cout << "b:";
	std::cin >> b;
	std::cout << "c:";
	std::cin >> c;

	D = pow(b, 2) - (4 * a * c);

	if (a == 0)				//���ǰ��� �غ��� 0�϶�
		std::cout << "Unexpected factor of a quadratic term";
	else if (D < 0)			//�Ǻ����� 0���� ���� ��(���)
		std::cout << "The equation has no real number solutions";
	else if (D == 0)		//�Ǻ����� 0�� �� �߱�(double root)
	{
		if (-b / (2 * a) == 0)		//���� -0 �϶� �״�� ��µǹǷ� ����ó��
			std::cout << "X1,X2:0 (double root)";
		else
			std::cout << "X1,X2:" << -b / (2 * a) << " (double root)";
	}
	else
	{
		if (b > 0)		//b�� 0���� ũ��  -b+sqrt(D)�� ���� ������ �Ǳ� ������ ����,�и� b+sqrt(D)�� ���ؼ� ������������ �ٲ��ش�. =>��б��� �ϸ� (-2*c)/(b+sqrt(D))
			std::cout << "X1:" << (-2 * c) / (b + sqrt(D)) << ",X2:" << (-b - sqrt(D)) / (2 * a);
		else if (b < 0)		//b�� 0���� ������ -b-sqrt(D)�� ���� ������ �Ǳ� ������ ����,�и� b-sqrt(D)�� ���ؼ� ������������ �ٲ��ش�.
			std::cout << "X1:" << (-b + sqrt(D)) / (2 * a) << ", X2:" << (-2 * c) / (b - sqrt(D));
		else
			std::cout << "X1:" << -sqrt(D) / (2 * a) << ",X2:" << sqrt(D) / (2 * a);		//b�� 0�� �� 
	}
	return 0;
}