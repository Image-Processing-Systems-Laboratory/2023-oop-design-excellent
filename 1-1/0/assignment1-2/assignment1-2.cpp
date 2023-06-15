#include<iostream>
#include<cmath>

using namespace std;		//std 라이브러리에 포함된 내용들을 사용
//함수 선언
void CheckEquaSolu(float a, float b, float c);	//a,b,c에 관한 이차방정식의 해에 대한 결과를 출력하는 함수
void Print_Question(float a,float b,float c);	//a,b,c에 관한 이차방정식을 출력하는 함수
float X1(float a, float b, float c);			//a,b,c에 관한 이차방정식의 첫번째 해 X1을 반환하는 함수
float X2(float a, float b, float c);			//a,b,c에 관한 이차방정식의 첫번째 해 X2를 반환하는 함수

int main()
{
	float a, b, c;			//float형 변수 선언
	cout << "a: "; cin >> a;		//a의 값을 입력받음
	cout << "b: "; cin >> b;		//b의 값을 입력받음
	cout << "c: "; cin >> c;		//c의 값을 입력받음
	Print_Question(a, b, c);		//a,b,c에 관한 이차방정식을 출력
	CheckEquaSolu(a, b, c);			//a,b,c에 관한 이차방정식의 해에 대한 결과를 출력
	return 0;
}
/*  a,b,c에 관한 이차방정식의 해에 대한 결과를 출력하는 함수  */
void CheckEquaSolu(float a, float b, float c) {
	float D = b * b - 4 * a * c;		//판별식을 float형 변수 D에 저장
	if (a == 0)			//a가 0일 경우
	{
		cout << "Unexpected factor of a quadratic term" << endl;
		exit(0);		//프로그램을 종료함
	}
	if (D < 0)		//판별식이 음수일 경우 (허근)
	{
		cout << "The equation has no real number solutions." << endl;
		exit(0);
	}
	else if (D > 0)		//판별식이 양수일 경우 (실근)
		cout << "X1: " << X1(a, b, c) << ", X2: " << X2(a, b, c) << endl;
	else				//판별식이 0일 경우 (중근)
		cout << "X1,X2: " << X1(a, b, c) << "(double root)" << endl;
}
/*  a,b,c에 관한 이차방정식을 출력하는 함수  */
void Print_Question(float a, float b, float c) {
	cout << "the roots of " << a << "x^2";
	if (b > 0)		//b가 양수일경우
		cout << " +";
	cout << ' ' << b << "x";
	if (c > 0)		//c가 양수일경우
		cout << " +";
	cout << ' ' << c << " = 0" << endl;
}
/*  a,b,c에 관한 이차방정식의 첫번째 해 X1을 반환하는 함수  */
float X1(float a, float b, float c) {
	float Sqrt_D = sqrt(b * b - 4 * a * c);
	float q;
	if (b > 0)			//b가 양수라면
		return (2 * c) / (-b - Sqrt_D);			//(2 * c) / (-b - Sqrt_D)를 반환함
	else if (b < 0)		//b가 음수라면
		return (2 * c) / (-b + Sqrt_D);			//(2 * c) / (-b + Sqrt_D)를 반환함
}	
/*  a,b,c에 관한 이차방정식의 첫번째 해 X2를 반환하는 함수  */
float X2(float a, float b, float c) {
	float Sqrt_D = sqrt(b * b - 4 * a * c);
	float q;
	if (b > 0)			//b가 양수라면
		return  (-b - Sqrt_D) / (2 * a);		//(-b - Sqrt_D) / (2 * a)를 반환함
	else if (b < 0)		//b가 음수라면
		return  (-b + Sqrt_D) / (2 * a);		//(-b + Sqrt_D) / (2 * a)를 반환함
}