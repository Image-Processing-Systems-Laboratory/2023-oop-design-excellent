#include <iostream>
#include <cmath>
using namespace std;
void root(float x, float y, float z);      //이차방정식의 실근을 구하고 출력하는 함수 선언

int main()
{
    float a, b, c;        //float형 변수 선언
    cout << "a : ";
    cin >> a;             //이차항 계수 입력 받기
    cout << "b : ";
    cin >> b;             //일차항 계수 입력 받기
    cout << "c : ";
    cin >> c;             //상수항 입력 받기
    cout << endl;
    if (a == 0)   //이차항 계수가 0이라면(이차항이 없다면)
        cout << "Unexpected factor of a quadratic term" << endl;  //이차항이 존재하지 않음을 출력
    else          //이차항이 존재한다면
        root(a, b, c);   //함수 호출

    return 0;
}

void root(float x, float y, float z)   //이차방정식의 실근을 구하고 출력하는 함수 정의
{
    float D = y * y - 4 * x * z;  //판별식을 의미하는 변수 선언 후 판별식 값으로 초기화
    float x1, x2;                 //두 근을 의미하는 변수 선언
    if (y > 0)                    //일차항이 양수일 때
    {
        x1 = (2 * z) / (-y - sqrt(D));   //에러를 막기 위해 근의 공식 변형
        x2 = (-y - sqrt(D)) / (2 * x);   //근의 공식
    }
    else                          //일차항이 음수일 때
    {
        x1 = (-y + sqrt(D)) / (2 * x);   //근의 공식
        x2 = (2 * z) / (-y + sqrt(D));   //에러를 막기 위해 근의 공식 변형
    }

    if (D == 0)     //중근을 가질 때(판별식이 0일 때)
        cout << "X1, X2 : " << x1 << " (double root)" << endl;  //중근 출력
    else if (D > 0)  //두 개의 실근을 가질 때(판별식이 0보다 클 때)
        cout << "X1: " << x1 << ", X2: " << x2 << endl;  //두 실근 출력
    else            //두 개의 허근을 가질 때(판별식이 0보다 작을 때)
        cout << "The equation has no real number solutions." << endl;  //실근이 없음을 출력
}
