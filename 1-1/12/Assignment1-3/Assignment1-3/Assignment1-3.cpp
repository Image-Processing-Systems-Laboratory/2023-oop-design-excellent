#include <iostream>
using namespace std;
void swap(int& num1, int& num2);  //두 수를 교환하는 함수 선언
int GCD(int a, int b);    //최대공약수를 구하는 함수 선언

int main()                //main 함수 정의
{
	int x, y, LCM;        //두 수와 최소공배수를 의미하는 int형 변수 선언
	cout << "input : ";
	cin >> x >> y;        //두 수 입력받기
	if (x == 0 || y == 0)  //두 수 중 하나라도 0이라면
		cout << "The LCM does not exist." << endl;  //최소공배수가 존재하지 않음(없음)을 출력
	else        //두 수가 모두 0이 아니라면
	{
		if (x < 0 && y < 0)    //두 수가 모두 음수일 때
		{
			LCM = -1 * x / GCD(x, y) * y;           //(-)를 곱한다
			cout << "output : " << LCM << endl;     //최소공배수 출력
		}
		else if (x < y)  //y가 x보다 클 경우
		{
			swap(x, y);       //두 수 교환
			if (x < 0)
				x = -x;
			else if (y < 0)
				y = -y;
			LCM = x / GCD(x, y) * y;    //최소공배수 구하기
			cout << "output : " << LCM << endl;          //최소공배수 출력
		}
		else
		{
			if (x < 0)
				x = -x;
			else if (y < 0)
				y = -y;
			LCM = x / GCD(x, y) * y;    //최소공배수 구하기
			cout << "output : " << LCM << endl;          //최소공배수 출력
		}
	}
	return 0;
}

void swap(int& num1, int& num2)  //두 수를 교환하는 함수 정의
{
	int temp = num1;        //교환을 위해 필요한 변수 선언 후 num1로 초기화
	num1 = num2;            //num1에 num2 값 대입
	num2 = temp;            //num2에 temp 값 대입
}

int GCD(int a, int b)     //최대공약수를 구하는 함수 정의
{

	if (b == 0)           //처음엔 작은 수 그 후에는 나머지를 나타내는 변수가 0이라면
		return a;         //최대공약수 반환

	else                  //나머지가 0이 아니라면
	{
		int c = a % b;    //나머지를 의미하는 int형 변수 c 선언 후 a를 b로 나눈 나머지로 초기화
		a = b;            //a에 b값 대입
		b = c;            //b에 c값 대입
		return GCD(a, b); //나머지가 0이 될 때까지(최대공약수를 구할 때까지) 재귀
	}
}
