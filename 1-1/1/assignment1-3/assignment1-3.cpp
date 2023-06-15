#include <iostream>
using namespace std;

int gcd(int x, int y); // 최대공약수 함수 선언
long long int lcm(int x, int y); // 최소공배수 함수 선언

int main()
{
    int x, y; // 두 수를 입력받을 변수 선언
    cout << "Enter x and y : ";
    cin >> x >> y; // 두 수 입력받기
    cout << "LCM of " << x << " and " << y << " is " << lcm(x, y) << endl; // 최소공배수 출력
    return 0;
}

int gcd(int x, int y) // 최대공약수 함수 정의
{
    if (y == 0) // y가 0이면 x가 최대공약수
    {
        return x; // x 반환
    }
    else // y가 0이 아니면
    {
        return gcd(y, x % y); // y와 x를 y로 나눈 나머지를 인자로 하는 gcd 함수 호출 (재귀를 이용한 유클리드 호제법)
    }
}

long long int lcm(int x, int y) // 최소공배수 함수 정의
{
    long long int gcd1 = gcd(x, y); // gcd1에 gcd 함수의 반환값 저장
    return (x / gcd1) * y; // 최소공배수 반환
}
