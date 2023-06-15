#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long GCD(int x, int y) // 최대공약수 함수
{
    if (y == 0) // 만약 y가 0이라면
        return x; // x가 최대공약수가 된다.
    else
        return GCD(y, x % y); // GCD(y, x%y)를 반환한다. 즉 재귀함수로써, y가 0이 될때까지 계속해서 GCD함수를 반복하는 것이다. 
}

// 최소공배수는 최대공약수에 두 수를 최대공약수로 나눈 몫을 곱해주면 된다. 이는 소인수분해 과정을 생각해보면 알 수 있다.
// 위 식은 결국 두 수의 곱을 최대공약수로 나눈 값과 같고, 이 식이 더 간결하므로 이 식을 사용한다.

long long LCM(int x, int y) // 최소공배수 함수
{
    return (x * (y / GCD(x, y))); // 위에서 말한 식 사용하여 최소공배수 구하기. 이때 자료형과 식에 대해 얘기해야되는데 이는 고찰에서 다루도록 하겠다.
}

int main()
{
    int x, y;
    long long result;
    cout << "Input: ";
    cin >> x >> y;
    result = LCM(x, y); // result에 LCM(num1, num2)값을 저장, 즉 result에 LCM함수를 통해 구한 최소공배수를 저장
    if (result == 0)
        return 0;
    cout << "LCM of " << x << " and " << y << " is " << result << endl;
    return 0;
}