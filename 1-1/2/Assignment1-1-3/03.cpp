#include<iostream>
using namespace std;

void swap(int& x, int& y);
void makePositive(int& x, int& y);
int getGCD(int x, int y);
long long getLCM(int x, int y);

int main()
{
	int x, y;

	cout << "x: "; cin >> x;
	cout << "y: "; cin >> y;
	
	cout << "최소공배수: " << getLCM(x, y) << endl;
}

/*두 수를 양수로 만들어 준다.*/
void makePositive(int& x, int& y)
{
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
}
/*변수 x, y에 저장된 값을 서로 바꿔준다.*/
void swap(int& x, int& y)
{
	int tmp;

	tmp = x;
	x = y;
	y = tmp;
}

/*유클리드 호제법으로 최대공약수 구하기*/
int getGCD(int x, int y)
{
	if (x < y)
		swap(x, y);
	if (y == 0)
		return x;
	else
		return getGCD(y, x % y);
}

/* (x, y의 최소공배수) = (x * y / 최대공약수) 를 적용 */
long long getLCM(int x, int y)
{
	long long lcm;

	makePositive(x, y); //음수가 입력돼도 양수처럼 취급
	lcm = (long long)x * (long long)y;
	lcm /= getGCD(x, y);
	
	return lcm;
}