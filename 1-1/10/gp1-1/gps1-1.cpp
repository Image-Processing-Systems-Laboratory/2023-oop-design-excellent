#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std; // namespace를 이용하여 std를 이름공간에 저장. 이로 인해 cout이나 cin, endl 등 사용시 앞에 std::를 붙이지 않아도 됨

int result = 1; // 전역변수 result(제곱 함수에서 사용)

char big[385][385]; // 삼각형들(의 기호 $)을 저장할 전체배열. 385는 k가 8일때 값에 문자열 배열이므로 +1 해준것이다.

char tri[3][6] = { "  $  ",
				   " $ $ ",
				   "$$$$$" }; // 삼각형 한 세트 만들기(전역으로)

int doub(int k) // 재귀함수를 이용한 제곱함수. N, 즉 2^(k-1)을 구하기 위해 쓰는것이므로, 2의 k 제곱이 아니라 k-1제곱을 반환해주는 함수다(pow를 사용해도 되지만 직접 코드를 짜봤다).
{
	if (k == 1) // k가 1이 되면
		return result; // 계산결과를 반환한다
	result *= 2; // result에 2를 계속 곱해나가는 방식
	return doub(k-1); // k가 1일때 반환하기 때문에, k가 1이 될때까지 함수를 한번 돌때마다 1씩 줄여준다.
}

void print(int a, int b) // 이중반복문을 통해 삼각형 한세트를 전체배열에 저장하는 함수
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
			big[i+a][j+b] = tri[i][j]; // 삼각형의 위치를 a와 b를 이용해서 정해서 전체배열 알맞은 위치에 저장(기준은 삼각형 위 꼭짓점)
}

void sitri(int i, int j, int hei) // (삼각형 위 꼭짓점의) i(세로), j(가로), 삼각형의 높이
{
	if (hei == 3) // 높이가 3, 즉 단위삼각형이 될 경우
		print(i,j); // print로 넘어간다
	else
	{
		sitri(i, j, hei / 2); // 위쪽 삼각형
		sitri(i + hei / 2, j - hei / 2, hei / 2); // 왼쪽 아래 삼각형
		sitri(i + hei / 2, j + hei / 2, hei / 2); // 오른쪽 아래 삼각형
	}
}

int main()
{
	unsigned char k; // input(k) 자체는 unsigned char 형태로 받는다
	cout << "Input: ";
	cin >> k; // k 입력받기
	int h = k - 48; // unsigned char형태로 받았기 때문에, int형으로 바꿔주기 위해 아스키 코드값을 이용해 h에 저장했다. k - '0'과 같은 의미이다.
	int N = doub(h); // N은 2^(k-1). 제곱은 doub 함수를 통해 표현
	sitri(0, 3*N-1, 3*N); // 인자로는 삼각형 위 꼭짓점의 행위치(세로), 열위치(가로), 삼각형의 높이가 들어간다.
	for (int i = 0; i < 3*N; i++) // 이중반복문을 이용해 $기호가 있는 요소를 제외한 모든 요소를 공백으로 처리한다(고찰에서 자세히 다루겠지만 안할시 널처리돼버림)
		for (int j = 0; j < 385; j++)
			if (big[i][j] != '$')
				big[i][j] = ' ';
	for (int i = 0; i < 3*N; i++) // 전체 출력
	{
		for (int j = 0; j < 6*N+1; j++) // 6*N+1까지인 이유는, 일단 아래 총 길이가 6N-1이고 시작점이 원점, 즉 big[0][0]이 아니고 big[0][2]이기 때문에 +2를 해주었다. 이는 고찰에서 다시 다루겠다
			cout << big[i][j];
		cout << endl;
	}
	return 0;
}