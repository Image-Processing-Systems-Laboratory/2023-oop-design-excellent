#include<iostream>
#include<cmath>

using namespace std;
void calculate(float a, float b, float c); // 함수 선언

int main()
{
    float a, b, c; // 이차방정식 계수들

    cout << "a: ";
    cin >> a; // a 입력

    cout << "b: ";
    cin >> b; // b 입력

    cout << "c: ";
    cin >> c; // c 입력

    if (a == 0) // a가 0이라면 이차방정식이 아니므로 글 출력 후 종료
    {
        cout << "Unexpected factor of a quadratic term" << endl;
        return 0;
    }
    calculate(a, b, c); // 함수 호출

    return 0;
}

void calculate(float a, float b, float c)
{
    float  x1, x2, x3, D; // x1, x2, x3는 근, D는 판별식

    D = b * b - 4 * a * c; // 판별식

    if (D > 0) // 판별식이 0보다 클 때
    {
        if (b > 0) // b의 값이 0보다 클 때
        {
            x1 = (-2 * c) / (b + sqrt(D)); // x1의 값
            x2 = (-b - sqrt(D)) / (2 * a); // x2의 값

            cout << "X1:" << x1 << "," << "X2:" << x2 << endl; // x1, x2 출력
        }
        else // 그외의 값일 때
        {
            x1 = (-b + sqrt(D)) / (2 * a); // x1의 값
            x2 = (-2 * c) / (b - sqrt(D)); // x2의 값

            cout << "X1:" << x1 << "," << "X2:" << x2 << endl; // x1, x2 출력
        }
    }
    else if (D == 0) // 판별식이 0일 때
    {
        x3 = b / (-2.0 * a); // x3의 값
        cout << "X1,X2:" << x3 << " (double root)"; // x3 출력
    }
    else if (D < 0) // 판별식이 0보다 작을 때
    {
        cout << "The equation has no real number solutions."; // 실근이 없다는 글 출력
    }
}