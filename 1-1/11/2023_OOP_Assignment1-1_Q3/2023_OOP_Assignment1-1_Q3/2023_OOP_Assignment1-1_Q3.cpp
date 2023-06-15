// 2023_OOP_Assignment1-1_Q3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//
//최대공약수를 사용하여, 두 수의 최소공배수 구하기

#include <iostream>
using namespace std;

int gcd(int y, int x) { //최대공약수를 구하는 함수 gcd선언

    if (x == 0) {   //x가 0이면
        return y;   //y값을 반환한다.
    }
    return gcd(x, y % x);   //재귀함수, 유클리드 호제법을 이용
}


int main()
{
    int integer1, integer2, num_gcd;      //int형 변수 integer1, integer2, num_gcd 선언
    long long num_lcm;                      //long long형 변수 num_lcm 선언 

    cout << "두 정수를 입력: ";       //"두 정수를 입력: " 문장 출력

    cin >> integer1, cin >> integer2;       //integer1, integer2에 입력한 정수 저장

    num_gcd = gcd(integer2, integer1);    //integer1와 integer2의 최대공약수 계산 및 저장.

    num_lcm = (long long)integer1 * integer2 / num_gcd;   //최소공배수를 계산하여 형변환 후 저장
    
    cout << "\n두 정수의 LCM은 " << num_lcm << "이다." << endl;    //LCM 출력
   
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
