#include<iostream>

using namespace std;		//std 라이브러리에 포함된 내용들을 사용

//함수 선언
void swap(int& x, int& y);	//두 수의 값을 변경해주는 함수
int GCD( int x,  int y);		//두 수의 최대공약수를 반환하는 함수

int main()
{
	int x, y, LCM;				//unsigned int형 함수 선언
	cout << "x,y: ";
	cin >> x >> y;					//x와 y값을 입력 받음

	if (y > x)				//y가 x보다 클 경우에
		swap(x, y);		//x와 y값을 뒤바꾼다.

	LCM = x / GCD(x, y) * y;			//LCM을 최소공배수 값으로 초기화
	cout << "GCD: " << GCD(x, y) << endl;
	cout << "LCM: " << LCM;				//최소 공배수 값 출력
	return 0;
}
/*  x와 y값을 뒤바꿔주는 함수  */
void swap(int& x, int& y) {
	int temp = x;		//x의 값을 temp에 저장
	x = y;			//y의 값을 x에 저장
	y = temp;			//temp의 값을 y에 저장
}
/*  x와 y의 최대공약수를 반환해주는 함수  */
int GCD(int x1,  int y1) {
	if (y1 == 0)		//y가 0일때
		return x1;	//x를 반환함
	GCD(y1, x1 % y1);	//재귀함수 호출
}