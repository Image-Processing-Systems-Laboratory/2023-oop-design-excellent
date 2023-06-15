#include <iostream>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

struct Vec3 // 좌표 정보를 담을 구조체 정의
{
	double x;
	double y;
	double z;
};

int main(void)
{
	double degree; // 회전할 각도
	Vec3 coo; // 초기 좌표

	std::cout << "Degrees: ";
	std::cin >> degree; // 60분법 각도 입력
	std::cout << "Coordinate: ";
	std::cin >> coo.x >> coo.y >> coo.z; // 초기 좌표 입력
	if (!std::cin) // 입력 오류 시 프로그램 종료
	{
		std::cerr << "Invalid input" << std::endl;
		return (EXIT_FAILURE);
	}
	degree *= M_PI / 180; // 60분법을 호도법으로 변환
	double sin_val = sin(degree); // 해당 각의 sin값 구함
	double cos_val = cos(degree); // 해당 각의 cos값 구함
	std::cout << -cos_val * coo.x + sin_val * coo.y << ' '
		<< sin_val * coo.x + cos_val * coo.y << ' '
		<< '0' << std::endl;
	// 행렬곱을 구해서 결과를 x, y, z좌표 순으로 출력
	return (0);
}