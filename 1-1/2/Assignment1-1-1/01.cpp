#include<iostream>
#include<cmath>
using namespace std;

/*input이 최대일 때를 가장한 크기, 모든 요소 0으로 초기화*/
char matrix[384][767] = { 0 };

void makeTri(int N, int x, int y);
void drawTri(int N);

int main()
{
	unsigned char k;
	int N;

	cout << "Input k: ";
	cin >> k;
	k -= 48; // 문자 0과 숫자 0의 아스키값 차이가 48

	N = pow(2, k - 1);
	
	makeTri(N, 0, 0);
	drawTri(N);

	return 0;
}

/*matrix에 시에르핀스키 삼각형 새기기. x, y는 0부터 시작*/
void makeTri(int N, int x, int y) {
	if (N == 1)
	{
		/*1행*/
		matrix[x][y + 2] = '$';
		/*2행*/
		matrix[x + 1][y + 1] = '$';
		matrix[x + 1][y + 3] = '$';
		/*3행*/
		matrix[x + 2][y] = '$';
		matrix[x + 2][y + 1] = '$';
		matrix[x + 2][y + 2] = '$';
		matrix[x + 2][y + 3] = '$';
		matrix[x + 2][y + 4] = '$';

		return;
	}
	makeTri(N / 2, x, y + 3 * N / 2); // 꼭대기삼각형
	makeTri(N / 2, x + 3 * N / 2, y); // 좌측하단삼각형
	makeTri(N / 2, x + 3 * N / 2, y + 6 * N / 2); // 우측하단삼각형
}

/*시에르핀스키 삼각형 출력*/
void drawTri(int N) {
	for (int i = 0; i < N * 3; i++) // 행 높이 3N
	{
		for (int j = 0; j < 6 * N - 1; j++) // 열 너비 6N - 1
		{
			if (matrix[i][j] == 0) // $문자가 새겨지지 않은 부분은 공백 출력
				cout << ' ';
			else
				cout << matrix[i][j];
		}
		cout << endl;
	}
}