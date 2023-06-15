﻿// 2023_OOP_Assignment1-1_Q1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
//
#include <iostream>
#include <cmath>            //pow 사용위해서 선언

using namespace std;

char arr[384][768];       //전역변수로 배열을 크게 선언 후 0으로 초기화(384=3*2^7)
                                //삼각형 높이=len, 한 변의 길이=2*len-1

void triangle(int len, int x, int y) {    //$을 그리는 함수

    if (len == 3) {   //len = 3일 때 더이상 삼각형을 쪼갤 수 없으므로 재귀멈춤

        //'$'로 이루어진 삼각형을 그린다.(가장 작은 기본 삼각형)
        arr[y][x] = '$';            //첫번째 줄 (꼭짓점에 $ 1개)
        arr[y + 1][x - 1] = '$';    //두번째 줄 ($ 2개)
        arr[y + 1][x + 1] = '$';
        arr[y + 2][x - 2] = '$';    //세번째 줄 ($ 5개)
        arr[y + 2][x - 1] = '$';
        arr[y + 2][x] = '$';
        arr[y + 2][x + 1] = '$';
        arr[y + 2][x + 2] = '$';

        return;
    }
    else {
        triangle(len / 2, x, y);                  //세부함수
        triangle(len / 2, x - (len / 2), y + (len / 2));      //큰 삼각형 3개 각각 중심으로
        triangle(len / 2, x + (len / 2), y + (len / 2));      //나누어서 그림
    }
}

int main()
{
    unsigned char k;        //unsigned char형 변수 k 선언
    int a, N, len;      //int형 변수 a, len, N 선언
    int i, j;


    cout << "Input k: ";        //k를 입력하시오
    cin >> k;                   //k를 입력하여 저장


    a = k - 48; //int형으로 형 변환 후 저장

    N = pow(2, (a - 1));          //N=2^(k-1)

    len = 3 * N;                //삼각형의 높이.

    for (i = 0; i < len; i++) {       //배열 초기화
        for (j = 0; j < 2 * len; j++) {
            arr[i][j] = ' ';        //배열의 끝에 공백 넣기
        }
    }


    triangle(len, len - 1, 0);  // $ 찍기. 큰 삼각형부터 시작.

    // 출력 

    for (int i = 0; i < len; i++) {       //arr을 출력하여 보여줌.
        for (int j = 0; j < 2 * len - 1; j++) {
            cout << arr[i][j];      //배열 출력
        }
        cout << "\n";           //개행 출력
    }

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.