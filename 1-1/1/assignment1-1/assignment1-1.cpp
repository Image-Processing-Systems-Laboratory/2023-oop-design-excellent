#include <iostream>
#include <cmath>

using namespace std;

const int MAX_HEIGHT = 384; // 정적 상수 선언
const int MAX_BASE = 767; // 정적 상수 선언

char coordinate[MAX_HEIGHT][MAX_BASE]; // 2차원 배열의 선언

void triangle(int height, int x, int y); // 삼각형을 그리는 함수

int main(void)
{

    int height, base; // 변수 선언(height는 높이, base는 밑변)
    unsigned char k; // 변수 선언(k는 입력받는 값)
    cout << "Input: "; // 입력을 받음
    cin >> k;
    k = k - 48; // 문자형을 숫자형으로 변환

    height = 3 * pow(2, (k - 1)); // 높이를 계산
    base = 3 * pow(2, k) - 1; // 밑변을 계산

    for (int i = 0; i < height; i++) // 2차원 배열을 공백으로 초기화
    {
        for (int j = 0; j < base; j++)
        {
            coordinate[i][j] = ' ';
        }
    }

    triangle(height - 1, 0, height); // 삼각형을 그림

    for (int i = 0; i < height; i++) // 삼각형을 출력
    {
        for (int j = 0; j < base; j++)
        {
            cout << coordinate[i][j];
        }
        cout << endl;
    }

    return 0;
}

void triangle(int x, int y, int height) // 삼각형을 그리는 함수
{

    if (height == 3) // 높이가 3일 때
    {
        coordinate[y][x] = '$'; //젤 위에 점을 찍음
        coordinate[y + 1][x - 1] = '$'; // 한 칸 내려가서 왼쪽으로 한 칸 찍음
        coordinate[y + 1][x + 1] = '$'; // 한 칸 내려가서 오른쪽으로 한 칸 찍음
        coordinate[y + 2][x - 2] = '$'; // 두 칸 내려가서 왼쪽에서 두 번째 칸 찍음
        coordinate[y + 2][x - 1] = '$'; // 두 칸 내려가서 왼쪽에서 첫 번째 칸 찍음
        coordinate[y + 2][x] = '$'; // 두 칸 내려가서 가운데 찍음
        coordinate[y + 2][x + 1] = '$'; // 두 칸 내려가서 오른쪽에서 첫 번째 칸 찍음
        coordinate[y + 2][x + 2] = '$'; // 두 칸 내려가서 오른쪽에서 두 번째 칸 찍음

        return; // 함수 종료
    }

    triangle(x, y, height / 2); // 위쪽 삼각형을 그림
    triangle(x - (height / 2), y + height / 2, height / 2); // 왼쪽 삼각형을 그림
    triangle(x + (height / 2), y + height / 2, height / 2); // 오른쪽 삼각형을 그림
}
