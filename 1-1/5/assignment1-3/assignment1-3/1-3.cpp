#include <iostream> //iostream 선언
using namespace std; //namespace std 선언
int gcd(int n1, int n2); //gcd함수 선언

int main() //main함수 시작
{
	int x, y = 0; //두 정수 x와 y 선언

	cout << "Input x = ";
	cin >> x;
	cout << "Input y = ";
	cin >> y;
	//두 정수 x와 y 입력받기

	int resgcd = 0; //최대공약수의 값을 받을 변수 선언

	if (x < y) //x가 y보다 작을 때
	{
		int swap = x;
		x = y;
		y = swap;
	} //swap을 통해 x와 y값 서로 교환

	resgcd = gcd(x, y); //두 수의 최대공약수 값을 변수에 저장

	long long reslcd = (static_cast<long long> (x) / resgcd) * y; //overflow 방지를 위해 연산 순서와 변수 타입을 변경, 최소공배수 연산

	cout << "GCD = " << resgcd << endl; //최대공약수 출력
	cout << "LCD = " << reslcd << endl; //최소공배수 출력

	return 0; //0의 반환
} //main함수 종료

int gcd(int n1, int n2) //최대공약수를 구하는 함수
{
	int u = 0;
	while (n2 != 0)
	{
		u = n1 % n2;
		n1 = n2;
		n2 = u;
	} //Euclidean algorithm 이용
	return n1;
} //gcd함수 종료