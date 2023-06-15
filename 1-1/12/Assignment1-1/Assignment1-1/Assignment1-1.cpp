#include <iostream>
#include <cmath>
using namespace std;

void shape(int row, int col);     //배열에 모양을 넣는 함수 선언
void func(int z, int x, int y);   //높이가 3이 될 때 문자를 배열에 넣고 반환하는 함수 선언
char triangle[384][768];         //문자를 넣을 2차원 배열 선언

int main()
{
    unsigned char k;              //unsigned char형 변수 선언, 사용자로부터 입력받는다
    cout << "Input : ";           //사용자로부터 입력받기
    cin >> k;                     //저장
    cout << "";

    if (k == '0' || k == '9')     //입력 받은 수가 범위에서 벗어난다면
    {
        cout << "It's out of range." << endl;   //범위에 벗어난 수임을 출력
        return 0;
    }

    int l = k - '0';              //아스키코드 변환식 이용
    k = l;                        //정수형 숫자 저장

    int N = int(pow(2, k - 1));        //2의 거듭제곱 계산 
    int size = 3 * N;             //높이
    int d = 2 * size - 1;         //밑변
    int i, j;                     //반복을 위한 변수

    for (i = 0;i < size;i++)   //배열을 공백으로 초기화
    {
        for (j = 0;j < d;j++)

            triangle[i][j] = ' ';

    }

    func(size, size - 1, 0);  //func 함수 호출(높이, 행, 열)

    for (i = 0;i < size;i++)   //삼각형 출력하기
    {
        for (j = 0;j < d;j++)
            cout << triangle[i][j];
        cout << endl;
    }


    return 0;
}

void shape(int row, int col)  //배열에 문자를 넣는 함수 정의
{
    //문자를 배열에 저장
    triangle[col][row] = '$';
    triangle[col + 1][row - 1] = '$';
    triangle[col + 1][row + 1] = '$';
    triangle[col + 2][row - 2] = '$';
    triangle[col + 2][row - 1] = '$';
    triangle[col + 2][row] = '$';
    triangle[col + 2][row + 1] = '$';
    triangle[col + 2][row + 2] = '$';
}

void func(int sz, int x, int y)   //높이가 3이 될 때 문자를 배열에 넣고 반환하는 함수 선언
{
    if (sz == 3)  //높이가 3이라면(삼각형을 그릴 수 있는 조건)
    {
        shape(x, y);
        return;
    }
    else
    {
        func(sz / 2, x, y);  //큰 삼각형을 3개로 쪼갠 삼각형들 중 제일 위에 위치한 삼각형
        func(sz / 2, x - (sz / 2), y + (sz / 2));  //아래에 있는 삼각형들 중 왼쪽에 위치한 삼각형
        func(sz / 2, x + (sz / 2), y + (sz / 2));  //아래에 있는 삼각형들 중 오른쪽에 위치한 삼각형
    }
}

