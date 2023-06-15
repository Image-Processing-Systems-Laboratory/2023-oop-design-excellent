#include <iostream> // 헤더파일 선언
#include <cmath> // pow와 sqrt를 쓰기 위한 헤더파일 선언
using namespace std; // 표준 라이브러리 사용


int main() //메인함수 선언
{

	float a, b, c; // 실수형 변수 a,b,c를 선언
	cin >> a >> b >> c; // a,b,c에 사용자의 입력값을 입력받음
	
	float x1, x2; // 실수형인 두 근 x1,x2를 선언
	if(b>=0) // b가 0 이상일 경우
	{
		x1 = (2*c)/( -b - sqrt(pow(b, 2) - 4 * a * c)); // 분모와 분자에 b+√b2-4ac를 곱해 근의 공식을 변형시킨 후 
		                                                // 입력받은 a,b,c를 대입 후 x1 구하기
	                                                    // x1을 변형시키는 이유는 -b+sqrt(pow(b,2)-4*a*c)를 계산하는 과정에서
	                                                    // 유사한 두 값을 빼면서 오버플로우가 발생해 출력값에 오차가 발생하기 때문
		x2 = (-b - sqrt(pow(b,2) - 4 * a * c)) / 2 * a; // 근의 공식에 입력받은 a,b,c를 대입 후 x2 구하기
	}
	else  // b가 음수일 경우 
	{
		x1= (-b + sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;   // b가 0 이상일 경우와 반대로 x1을 그냥 근의 공식에 넣고 
		x2= (2 * c) / (-b + sqrt(pow(b, 2) - 4 * a * c)); // x2를 변형시켜야 오버플로우를 방지할 수 있음
	}


	if (a == 0) // a에 0이 입력되면
		cout << "Unexpected factor of a quadratic term"; // 근의 공식에서 a는 0이 아닌 실수여야하므로 오류메세지 출력
	else if (x1 == x2) // 근의 공식을 적용 후 x1과 x2가 같으면
		cout << "X1,X2:" << x1 << "(double root)"; // 값을 출력 후 중근임을 출력
	else if (pow(b,2) - 4 * a * c < 0) // b^2-4ac가 음수일 경우
		cout << "The equation has no real number solutions."; // 실수 해가 없음을 출력
	else // 위의 경우들에 모두 해당되지 않으면
		cout << "X1:" << x1 << ", X2:" << x2; // 두 근의 값을 출력

	return 0; // 프로그램 종료

}
