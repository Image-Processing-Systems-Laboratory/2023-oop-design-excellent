#include<iostream>

int gcd(int x, int y)		//유클리드 호재법을 재귀적으로 수행
{
	if (y == 0)			//y가 0이 되면 종료
		return x;
	else
		return gcd(y, x % y);
}

int main()
{
	int x, y;
	int g;		//최대공약수
	int divided_x, divided_y;		//x와y에 최대공약수를 나눈 값
	long long result;
	std::cout << "x:";
	std::cin >> x;
	std::cout << "y:";
	std::cin >> y;
	if (y > x)		//y가 x보다 크면 바꿔줌
	{
		int temp;
		temp = x;
		x = y;
		y = temp;
	}
	g = gcd(x, y);
	divided_x = x / g;
	divided_y = y / g;
	result = (long long)g * (long long)divided_x * (long long)divided_y;		//자료형 변환을 이용해 계산
	std::cout << result;
}