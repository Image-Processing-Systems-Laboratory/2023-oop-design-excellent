#include <iostream>

using namespace std;

//두 정수의 최대공약수를 리턴하는 함수
int gcd(int x, int y);
//두 정수의 최소공배수를 리턴하는 함수
int lcm(int x, int y);

int main() {
	int x, y;		//두 정수를 입력 받을 변수
	cout << "Enter the numbers." << endl;
	cin >> x >> y;
	cout << "LCM of two numbers is " << lcm(x, y) << endl;		//최소공배수 출력
}

int gcd(int x, int y) {
	//유클리드 호제법 이용
	if (y == 0)
		return x;
	return gcd(y, x % y);		//재귀적으로 정의
}

int lcm(int x, int y) {
	//gcd를 이용
	return (x / gcd(x, y)) * y;		// (x * y) / gcd(x,y)의 경우 x * y에서 오버플로우가 일어나기 쉽다.
}