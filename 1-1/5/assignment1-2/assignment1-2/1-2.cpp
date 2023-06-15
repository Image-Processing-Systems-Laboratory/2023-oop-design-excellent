#include <iostream> //iostream 선언
#include<cmath> //cmath 선언
using namespace std; //namespace std 선언

int main() //main함수 시작
{
	float a, b, c = 0; //실수 
	cout << "Enter a,b,c(ax^2+bx+c=0)" << endl; //안내문 출력
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c; //여기까지 이차방정식의 각 항의 계수를 입력받습니다.

	float d = pow(b, 2) - 4.0 * a * c; //판별식을 d라고 정의했습니다.
	float result1 = 0;
	float result2 = 0; //결과값 변수 선언

	if (b > 0)
	{
		result1 = 2 * c / ((-b) - sqrt(d));
		result2 = (-b - sqrt(d)) / (a * 2);
	}
	else
	{
		result1 = (-b + sqrt(d)) / (a * 2);
		result2 = 2 * c / ((-b) + sqrt(d));
	}
	//유사한 두 숫자 간 뺄셈 연산을 피하기 위해 b에 부호에 따라 식을 바꿨습니다.
	//자세한 계산과정은 보고서에 적었습니다.

	if (a == 0) //a가 0이었을 때
		cout << "Unexpected factor of a quadratic term"; //조건에 맞게 안내문 출력
	else if (d > 0) //판별식이 양수이면
		cout << "X1: " << result1 << ", X2: " << result2 << endl; //두 개의 근을 출력
	else if (d == 0) // 판별식이 0이면
		cout << "X1, X2: " << result1<<" (double root)" << endl; //중근을 출력
	else //그 외의 경우, 판별식이 음수이면
		cout << "The equation has no real number solutions"; //안내문 출력

	return 0; //0의 반환
}//main 함수 종료