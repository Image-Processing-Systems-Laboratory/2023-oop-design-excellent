#include <iostream>
#include <cmath>      //sin, cos값을 계산하기위해 sin(),cos()함수를 포함하는 헤더파일 선언

using namespace std;

int main()
{
	int degrees;   //각도를 입력받아 저장할 변수
	double x, y, z;   //입력받을 x, y, z좌표
	double arr[3];    //결과를 저장할 배열
	double pi = 3.14;
	double radian = pi / 180;

	cout << "Degrees: ";
	cin >> degrees;

	cout << "Coordinate: ";
	cin >> x >> y >> z;

	cout << endl;

	arr[0] = x * (-1) * cos(degrees * radian) + y * sin(degrees * radian);  //행렬식 곱의 결과 z의 값과는 상관없이 z는 항상 0이 나옴
	arr[1] = x * sin(degrees * radian) + y * cos(degrees * radian);
	arr[2] = 0;     //행렬 T의 3행 성분이 모두 0이므로 행렬곱을 계산한 3행 1열 성분읜 항상 0이 나옴

	for (int i = 0; i < 3; i++)  //행력곱을 계산하여 출력함
	{
		cout << arr[i] << " ";
	}
}    