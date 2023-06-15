// 2023_OOP_Assignment1-1_Q2_ver2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>        //pow, sqrt 사용
using namespace std;


int main()
{
    float a, b, c;      //변수 a, b, c선언
    float b4ac = 0, b4ac_root; //float형으로 루트값을 저장할 변수 선언

    float x1, x2;  //두 근을 저장할 변수 선언
    cout << "a: "; cin >> a;        //변수 a 입력 및 저장
    cout << "b: "; cin >> b;        //변수 b 입력 및 저장
    cout << "c: "; cin >> c;        //변수 c 입력 및 저장


    if (a == 0) {           //a가 0일 때
        cout << "Unexpected factor of a quadratic term" << endl;    //문장 출력 후 종료

    }
    else               //a가 0이 아닐 때
    {
        b4ac = pow(b, 2) - (4 * pow(a, 2) * pow(c, 2)) / (a * c);    //루트 안 값 저장. pow함수 사용, 산술 오버플로 방지 코드


        if (b4ac > 0) {                     //루트 안 값이 양수일 때 (서로 다른 두 실근을 가질 때)
            b4ac_root = sqrt(b4ac);         //루트 값 저장, sqrt함수 사용

            {
                if (b > 0) {    //b가 양수일 때와 음수일 때, round-off error가 발생하는 조건을 나누어서 확인.

                    x1 = 2 * c / (-b - b4ac_root);  //식 변형(round-off error 방지)
                                                    //x1 = (-b + b4ac_root) / 2 * a; // 식을 그대로 사용하면 오차가 뜬다. 이유:round-off error

                    x2 = (-b - b4ac_root) / (2 * a);    //x2값 저장

                    cout << "X1: " << x1 << ",";        //x1값 출력
                    cout << " X2: " << x2 << endl;
                }     //x2값 출력

                else      //b가 음수일 때
                {
                    x1 = (-b + b4ac_root) / (2 * a);    //x1값 저장

                    //x2 = (-b - b4ac_root) / 2 * a;    // 식을 그대로 사용하면 오차가 뜬다. 이유:round-off error
                    x2 = 2 * c / (-b + b4ac_root);    //식 변형(round-off error 방지)
                    cout << " X2: " << x2 << endl;
                }

            }
        }
        else if (b4ac == 0) {//루트 안 값이 0일 때(중근을 가질 때)
            x1 = (-b) / (2 * a);    //x1값 계산 및 저장
            x2 = x1;                //x2값 저장
            cout << "X1, X2: " << x1 << " (double root)" << endl;   //x1,x2값 출력 및 중근 표시
        }
        else                 //루트 안 값이 음수일 때(허근을 가질 때
            cout << "The equation has no real number solutions." << endl;   //해당 문장 출력
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
