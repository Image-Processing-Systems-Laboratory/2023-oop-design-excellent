#include <iostream>
using namespace std;

void draw(int row, int col);
void draw_triangle(int len, int row, int col);

char arr[384][767]; // k가 8일때 최대 행 384, 열 767

int main()
{
    unsigned char k; // 입력값 받을 변수
    int N, num, row, col, i, j;

    cin >> k;

    num = k - 48; // 입력받은 숫자의 ASKII 코드로 숫자로 만들기
    N = pow(2, num - 1); 
    row = 3 * N;
    col = 2 * row - 1;

    // 행과 열만큼 반복문 돌려서 해당 위치에 공백 추가
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            arr[i][j] = ' ';

    // arr 배열에 좌표처럼 찍는 재귀함수 첫 호출
    // 첫번째 매개변수로 열을 그대로 전달하여 반복횟수 계산
    // 두번째 매개변수로 삼각형의 상단부터 그릴 것이므로 0 전달
    // 세번째 매개변수로 삼각형의 좌우 방향으로 이동하면서 출력할 col을 row - 1로 전달
    draw_triangle(row, 0 ,row - 1);

    // 이중 반복문으로 이중배열 출력
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << arr[i][j];
        cout << endl;
    }

    return 0;
}


// 삼각형 모양으로 기호를 찍는 함수
void draw(int row, int col)
{
    // 첫번째 줄 가운데
    arr[row][col] = '$';

    // 두번째 줄 양 옆
    arr[row + 1][col - 1] = '$';
    arr[row + 1][col + 1] = '$';

    // 마지막줄 5개
    for (int i = 0; i < 5; i++)
        arr[row + 2][col - 2 + i] = '$';
}

// 좌표적으로 접근하여 삼각형을 그리는 재귀함수
void draw_triangle(int len, int row, int col)
{
    // len이 3이면 draw 함수를 통해 삼각형모양으로 기호 찍기
    if (len == 3)
    {
        draw(row, col);
        return;
    }

    // 재귀함수 조건부
    draw_triangle(len / 2, row, col); // len을 2로 나누어 행, 열과 함께 매개변수로 전달

    // len을 2로 나누어 행에 더한 값과 열에 뺀값을 함께 매개변수로 전달
    // 시에르핀스키 삼각형의 왼쪽부분
    draw_triangle(len / 2, row + len / 2, col - len / 2);

    // len을 2로 나누어 행에 더한 값과 열에 더한 값을 함께 매개변수로 전달
    // 시에르핀스키 삼각형의 오른쪽 부분
    draw_triangle(len / 2, row + len / 2, col + len / 2);

}