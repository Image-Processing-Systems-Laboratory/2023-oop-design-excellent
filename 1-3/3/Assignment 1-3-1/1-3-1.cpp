#define _USE_MATH_DEFINES // ��� (����) ���� ����ϱ� ���� ����
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// ���� ����
	double degree, x, y, z, nx, ny, nz;

	// ���� �� ��ǥ �Է�
	cout << "Degrees : ";
	cin >> degree;
	cout << "Coordinate : ";
	cin >> x >> y >> z;

	// ��İ� ���
	nx = -cos(degree * (M_PI/180)) * x + sin(degree * (M_PI / 180)) * y;
	ny = sin(degree * (M_PI / 180)) * x + cos(degree * (M_PI / 180)) * y;
	nz = 0;
	
	// ����� ���� ���
	cout << nx << " " << ny << " " << nz;
	return 0;
}