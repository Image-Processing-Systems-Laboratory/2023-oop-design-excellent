#include <iostream>
#include <cmath>
using namespace std;

void	make_sire(char arr[][3 * 256 - 1], unsigned char k, int x, int y);
// 시에르핀스키 삼각형을 만드는 재귀함수, x, y는 삼각형 그리기를 시작할 좌표

int main()
{
	char arr[3 * 128][3 * 256 - 1] = { 0, };
	// 시에르핀스키 삼각형을 그려 넣을 이차원 배열
	// 1 <= k <= 8 이므로 삼각형의 최대 크기[3 * 2 ^ (k - 1), 3 * 2 ^ k - 1]만큼 할당
	unsigned char k;

	cout << "Input: ";
	// 표준 출력
	cin >> k;
	// 표준 입력으로 값을 unsigned char 변수 k에 집어넣음
	make_sire(arr, k, 0, 3 * pow(2, k - '1') - 1);
	// 삼각형을 찍기 시작할 좌표 설정(첫 번째 행, 3 * 2 ^ (k - 1) 번째 열, 삼각형의 가운데 부분)
	for (int i = 0; i < 3 * pow(2, k - '1'); i++)
	{
		for (int j = 0; j < 3 * pow(2, k - '0') - 1; j++)
		{
			if (arr[i][j] == '$')
				cout << arr[i][j];
			else
				cout << ' ';
			// 이차원 배열에 $가 찍혀 있으면 그대로 출력하고, 아니면 공백 출력
		}
		cout << endl; // 개행 출력
	}
	return (0);
}

void	make_sire(char arr[][3 * 256 - 1], unsigned char k, int x, int y)
{
	if (k == '1')
	{
		arr[x][y] = '$';
		arr[x + 1][y - 1] = '$';
		arr[x + 1][y + 1] = '$';
		for (int i = 0; i < 5; i++)
			arr[x + 2][y - 2 + i] = '$';
		// 제일 작은 삼각형을 맨 위 꼭짓점부터 찍어냄
		return;
	}
	// k != 1 이면 k - 1의 삼각형을 3개(위에 하나, 아래 2개) 그려야 함
	make_sire(arr, k - 1, x, y); // 맨 위 삼각형
	make_sire(arr, k - 1, x + 3 * pow(2, k - '2'), y - 3 * pow(2, k - '2')); // 아래 왼쪽 삼각형
	make_sire(arr, k - 1, x + 3 * pow(2, k - '2'), y + 3 * pow(2, k - '2')); // 아래 오른쪽 삼각형
}