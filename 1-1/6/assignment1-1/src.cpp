#include <iostream>
#include <cmath>

using namespace std;

//이차원 배열 space에 재귀를 이용해 '$'를 적절한 위치에 새기는 함수
void Sierpinski(char** space, int n, int x, int y) {
	if (n == 1) {	//'$'로 삼각형을 새긴다.
		space[x][y] = '$';
		space[x + 1][y + 1] = '$';
		space[x + 1][y - 1] = '$';
		for (int i = 0; i < 5; i++)
			space[x + 2][y - 2 + i] = '$';
	}
	else {
		int d = static_cast<int>(3 * std::pow(2, n - 2));
		Sierpinski(space, n - 1, x, y);		//위쪽 삼각형
		Sierpinski(space, n - 1, x + d, y - d);		//왼쪽 삼각형
		Sierpinski(space, n - 1, x + d, y + d);		//오른쪽 삼각형
	}
	return;
}

int main() {
	unsigned char k;	//입력값을 저장할 변수
	cout << "--> ";
	cin >> k;
	int num = k - '0';	//int로 변환
	int col = static_cast<int>(3 * std::pow(2, num) - 1);	//공간의 최대 길이
	int row = static_cast<int>(3 * std::pow(2, num - 1));	//공간의 최대 높이

	//시에르핀스키 삼각형을 그릴 공간을 동적할당
	char** space = new char* [row];	//행 공간 할당
	for (int i = 0; i < row; i++) {	//열 공간 할당
		space[i] = new char[col];
		for (int j = 0; j < col; j++) {	//공간 내부값 " "으로 초기화
			space[i][j] = ' ';
		}
	}

	Sierpinski(space, num, 0, col / 2);

	//출력
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << space[i][j];
		}
		cout << endl;
	}

	//메모리 해제
	for (int i = 0; i < row; i++) {	//열 공간 해제
		delete[] space[i];
	}
	delete[] space;		//행 공간 해제
	return 0;
}