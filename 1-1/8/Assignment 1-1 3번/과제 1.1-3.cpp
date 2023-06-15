#include <iostream> // 헤더파일 선언
using namespace std; // 표준 라이브러리 선언
long long gcd(int a, int b) // 최대공약수 구하는 함수 선언 및 정의
							// gcd를 long long으로 선언한 이유는 input값이 클 때 오버플로우가 발생하는 것을
	                        // 방지하기 위해서임
{
	if (b == 0) // b가 0이면
		return a; // 최대공약수는 a이므로 a 반환받고 재귀함수 탈출
	else // b가 0이 아니면
		return gcd(b, a % b); // 재귀함수를 이용해 gcd(y,x%y)꼴로 바꾼 후 다시 최대공약수 구하기(y가 0이 될 때까지)
}


int main() // 메인함수 선언
{
	int x, y; // 정수형 변수 x,y 선언
	cin >> x >> y; // 사용자로부터 x,y값 입력받기
	
	long long LCM = x * (y / gcd(x, y)); // x,y의 최소공배수는 두 수를 곱한 값을 최대공약수로 나눈 것과 같으므로 최소공배수 LCM 선언 후
	                               // 맞는 값 지정
	                                // y/gcd(x,y)를 먼저 하기 위해 소괄호로 묶어줌. 이유는 큰 수를 넣었을 때, x*y를 먼저 계산하면
								   // 오버플로우가 발생할 수 있기 때문에 나눗셈을 먼저 함으로써 이를 방지함.
	                               // 나눗셈 먼저 해도 오버플로우가 발생할 정도로 큰 수를 넣었을 때를 위해
	                                // LCM을 long long 형으로 선언해줌

	cout << LCM; // 최소공배수 출력




	return 0; // 프로그램 종료	
}
