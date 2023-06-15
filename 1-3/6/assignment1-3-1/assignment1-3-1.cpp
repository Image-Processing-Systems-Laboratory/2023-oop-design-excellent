#include <iostream>
#include <cmath>
#define PI 3.1415926535897932384626433832795
using namespace std;

int main()
{
    double theta, xi, yi, zi, xo, yo, zo;

    // 입력
    cout << "Degrees: ";
    cin >> theta;
    cout << "Coordinate: ";
    cin >> xi >> yi >> zi;

    // DEG를 RAD로
    theta *= (PI / 180);

    // 계산
    xo = (-cos(theta) * xi + sin(theta) * yi);
    yo = (sin(theta) * xi + cos(theta) * yi);
    zo = 0;

    // 출력
    cout << xo << ' ' << yo << ' ' << zo;

    // 종료
    return 0;
}