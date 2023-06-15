#include <iostream>
#include <cmath>
using namespace std;

void    swap(int* a, int* b);
// a와 b를 Call-by-reference로 바꿔주는 함수
void	get_gcd(int a, int b, int* ret);
// 최대공약수를 구해서 ret 포인터가 가리키는 변수에 저장하는 재귀함수

int main()
{
	int a, b;
	long long num;
	int gcd;
	long long lcm;
	// num(a * b)과 lcm(최소공배수)를 long long 변수로 만듦
	// 이는 a * b가 int의 범위를 벗어나 오버플로우가 일어나는 것을 막기 위해
	// 8byte 자료형 long long을 쓴 것임
	cout << "Input: ";
	cin >> a >> b;

	if (a < b)
		swap(&a, &b);
	if (b == 0)
		gcd = a;
	// 두 수 중 작은 수가 0이면 최대공약수는 큰 수
	else
		get_gcd(a, b, &gcd);
	if (a == 0)
		lcm = 0;
	// 공식을 이용해 LCM을 구할 때 0으로 나누는 것을 막기 위함
	else
	{
		num = (long long)a * b;
		lcm = num / (long long)gcd;
	}
	cout << "LCM: " << lcm << endl;
	return (0);
}

void	swap(int* a, int* b)
{
	int		temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void	get_gcd(int a, int b, int* ret)
{
	if (a % b == 0)
		*ret = b;
	else
		get_gcd(b, a % b, ret);
	// 첫 번째 인자와 두 번째 인자의 나머지 연산의 결과가 0일 때까지 재귀적으로 함수를 호출
}