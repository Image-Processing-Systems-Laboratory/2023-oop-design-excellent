#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // float과 double 모두 사용가능한데, double이 float보다 두배의 정밀함을 가지므로 오차가 더 적은 double을 택했다
    double d; // 이후에 계산시에 라디안형태로 계산하려면 double형으로 선언해줘야 한다
    const double PI = M_PI;
    cout << "Degrees: ";
    cin >> d;
    while (d >= 360) // 360도를 넘어가면 아주 약간의 오차가 발생하게 되는데, 이를 해결하기 위해 while문을 통해 항상 각도를 360도 아래로 해준다.
    {
        d -= 360;
    }
    double Mat[2][2]; // 원래 행렬 자체는 3x3 행렬이지만, 3행과 3열의 값이 모두 0이므로, 제외해도 계산 결과에는 영향이 없어 다음과 같이 2x2로 해주었다
    Mat[0][0] = -1 * cos((d / 180) * PI); // cmath 내에 있는 삼각함수 계산 기능을 이용해 각도를 라디안형태로 변경하여 계산해준다
    Mat[0][1] = sin((d / 180) * PI);
    Mat[1][0] = Mat[0][1];
    Mat[1][1] = -1 * Mat[0][0];
    double co[3];
    cout << "Coordinate: ";
    for (int i = 0; i < 3; i++)
        cin >> co[i];
    double out[3];
    for (int i = 0; i < 2; i++)
        out[i] = (Mat[i][0] * co[0]) + (Mat[i][1] * co[1]); // 행렬 곱은 다음과 같이 기역자 형태로 곱연산을 해준다
    out[2] = 0.0; // 위에서 말했듯 3행과 3열은 모든 값들이 0으로 고정이므로, 계산값도 0이기 때문에 output에서 3번째 값은 반드시 0이 나온다.
    for (int i = 0; i < 3; i++)
        cout << out[i] << " ";
    cout << endl;
    return 0;
}