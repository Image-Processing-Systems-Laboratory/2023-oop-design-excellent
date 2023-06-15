#include <iostream>
using namespace std;

int GCD(int x, int y); // 최대공약수 구하는 함수 프로토콜

int main()
{
	int a, b, gcd;
	long long lcm; // 최소공배수 저장변수. overflow 방지로 long long형 선언

	// 두 입력값 저장
	cout << "Enter two number ";
	cin >> a >> b;

	// a가 b보다 작으면 서로 위치 바꿈
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	// gcd 변수에 최대공약수 구하는 함수 호출하여 저장
	gcd = GCD(a, b);
	// lcm 변수에 a와 b의 곱을 최대공약수로 나누어 저장
	lcm = static_cast<long long>(a) * b / gcd;

	// 결과 출력
	cout << endl << "GCD : " << gcd << endl << "LCD : " << lcm << endl;

	return 0;
}

// 최대공약수 구하는 함수. 유클리드 호제법
// 앞 매개변수인 x가 뒤 매개변수인 y보다 커야함
int GCD(int x, int y)
{
	// 두번째 매개변수가 0이되면 첫번째 매개변수가 최대공약수
	if (y == 0)
		return x;
	// 두번째 매개변수가 0이 아니면 GCD 함수 재호출 (재귀함수)
	// 첫번째 매개변수로 y를, 두번째 매개변수로 x를 y로 나눈 나머지 전달
	else
		return GCD(y, x % y);
}