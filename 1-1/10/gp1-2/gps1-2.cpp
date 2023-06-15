#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a = 0;
    float b = 0;
    float c = 0;
    float x1 = 0;
    float x2 = 0;
    cin >> a >> b >> c;
    if (b > 0)
    {
        // x1 = ((-1 * b + sqrt(pow(b, 2) - (4 * a * c))) / 2 * a); 원래는 이 형태지만
        x1 = 2 * c / (-1 * b - sqrt(pow(b, 2) - (4 * a * c))); // 분모 분자에 -b-sqrt(pow(b,2)-(4*a*c))를 곱해서 뺄셈 연산을 덧셈 형태로 바꿔서 오차 해결
        x2 = ((-1 * b - sqrt(pow(b, 2) - (4 * a * c))) / 2 * a); // 애초에 덧셈 형태로 돼있으므로 그대로 연산
        // 여기서 덧셈이란 -1을 인자를 빼냈을때 + 형태로 바뀌기에 덧셈형태라고 하는 것이다.
    }
    else // 대신에 만약에 b가 음수면 결국 -b-sqrt(b^2-4ac)가 비슷한 값끼리의 뺄셈 연산이므로 이때는 역으로 x1을 그대로 사용하고 x2를 유리화해줘야 한다.
    {
        x1 = ((-1 * b + sqrt(pow(b, 2) - (4 * a * c))) / 2 * a);
        x2 = 2 * c / (-1 * b + sqrt(pow(b, 2) - (4 * a * c)));
    }
    cout << "the roots of " << a << "x^2" << " + " << b << "x" << " + " << c << " = 0 : " << endl << endl;
    if (a == 0) // a가 0인 경우(분모가 0)
        cout << "Unexpected factor of a quadratic term" << endl;
    else if (pow(b, 2) - (4 * a * c) < 0) // 루트 내부 식의 값이 음수일 경우
        cout << "The equation has no real number solutions." << endl;
    else if (x1 == x2) // x1과 x2가 같은 값이 나올 경우(double root는 이중근을 말함)
        cout << "x1, x2: " << x1 << "(double root)" << endl;
    else // 일반적인 경우
        cout << "X1: " << x1 << ", X2: " << x2 << endl;
    return 0;
}