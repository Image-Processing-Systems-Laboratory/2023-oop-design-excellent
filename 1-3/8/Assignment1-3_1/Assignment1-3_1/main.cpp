#include <iostream>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

struct Vec3 // ��ǥ ������ ���� ����ü ����
{
	double x;
	double y;
	double z;
};

int main(void)
{
	double degree; // ȸ���� ����
	Vec3 coo; // �ʱ� ��ǥ

	std::cout << "Degrees: ";
	std::cin >> degree; // 60�й� ���� �Է�
	std::cout << "Coordinate: ";
	std::cin >> coo.x >> coo.y >> coo.z; // �ʱ� ��ǥ �Է�
	if (!std::cin) // �Է� ���� �� ���α׷� ����
	{
		std::cerr << "Invalid input" << std::endl;
		return (EXIT_FAILURE);
	}
	degree *= M_PI / 180; // 60�й��� ȣ�������� ��ȯ
	double sin_val = sin(degree); // �ش� ���� sin�� ����
	double cos_val = cos(degree); // �ش� ���� cos�� ����
	std::cout << -cos_val * coo.x + sin_val * coo.y << ' '
		<< sin_val * coo.x + cos_val * coo.y << ' '
		<< '0' << std::endl;
	// ��İ��� ���ؼ� ����� x, y, z��ǥ ������ ���
	return (0);
}