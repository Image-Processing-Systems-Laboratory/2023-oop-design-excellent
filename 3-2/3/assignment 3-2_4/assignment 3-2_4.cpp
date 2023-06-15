#include "PolyTerm.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void InputPolynomial(Polynomial& Poly);     // 다항식을 입력받는 함수

int main()
{
    Polynomial poly1, poly2;        // 두 개의 다항식 객체 생성

    cout << "Input first polynomial: ";
    InputPolynomial(poly1);     // 첫 번째 다항식 입력받기
    cout << "Input second polynomial: ";
    InputPolynomial(poly2);     // 두 번째 다항식 입력받기

    cout << endl;

    cout << "First polynomial: ";
    poly1.PrintList();      // 첫 번째 다항식 출력
    cout << "Second polynomial: ";
    poly2.PrintList();      // 두 번째 다항식 출력

    cout << endl;

    Polynomial sumPoly, subPoly;        // 두 다항식의 합과 차를 저장할 객체 생성

    sumPoly.Add(poly1);     // 첫 번째 다항식을 더하기
    sumPoly.Add(poly2);     // 두 번째 다항식을 더하기

    subPoly.Add(poly1);     // 첫 번째 다항식을 더하기
    subPoly.Sub(poly2);     // 두 번째 다항식을 빼기

    cout << "Test Add Function poly1 + poly2: ";
    sumPoly.PrintList();        // 두 다항식의 합 출력
    cout << "Test Sub Function poly1 - poly2: ";
    subPoly.PrintList();        // 두 다항식의 차 출력

    return 0;
}

void InputPolynomial(Polynomial& Poly)
{
    string input;       // 다항식을 입력받을 문자열
    getline(cin, input);        // 공백을 포함하여 문자열 입력받기

    stringstream str(input);        // 문자열을 stringstream 객체로 변환
    bool isNegative = false;        // 음수인지 확인하는 변수
    int coefficient = 0;        // 계수를 저장할 변수
    int exponent = 0;       // 차수를 저장할 변수
    bool coeffRead = false;     // 계수를 읽었는지 확인하는 변수

    // 문자열을 한 글자씩 읽어들이면서 다항식을 구성하는 항을 하나씩 읽어들임
    while (true)
    {
        char c;     // 문자를 저장할 변수
        str >> c;       // 문자 하나 읽어들이기

        // 문자열의 끝에 도달하면 반복문 종료
        if (str.eof())
        {
            // 마지막 항을 다항식에 추가
            Term* term = new Term();        // 새로운 항을 저장할 노드 생성
            term->SetCoeff(coefficient);        // 계수 설정
            term->SetExponent(exponent);        // 차수 설정
            Poly.Insert(term);      // 다항식에 항 추가
            break;
        }

        // 공백 문자는 무시
        if (c == ' ')
        {
            continue;
        }

        // 음수 부호인 경우
        if (c == '-')
        {
            isNegative = true;      // 음수 부호임을 표시
            continue;
        }

        // 양수 부호인 경우
        if (isdigit(c))
        {
            str.unget();        // 읽어들인 문자를 다시 입력 스트림에 되돌림
            str >> coefficient;     // 계수를 읽어들임
            // 음수 부호가 있었으면 계수에 음수를 붙임
            if (isNegative)
            {
                coefficient = -coefficient;     // 계수에 음수를 붙임
            }
            coeffRead = true;       // 계수를 읽었음을 표시

            // 계수 뒤에 'x'가 오는 경우
            if (str.peek() != 'x')
            {
                exponent = 0;       // 차수는 0으로 설정
                Term* term = new Term();        // 새로운 항을 저장할 노드 생성
                term->SetCoeff(coefficient);        // 계수 설정
                term->SetExponent(exponent);        // 차수 설정
                Poly.Insert(term);      // 다항식에 항 추가

                isNegative = false;     // 음수 부호로 초기화
                coefficient = 0;        // 계수 초기화
                exponent = 0;       // 차수 초기화
                coeffRead = false;      // 계수를 읽지 않았음을 표시
            }
            continue;
        }

        // 'x'인 경우
        if (c == 'x')
        {
            // 계수를 읽지 않았으면 계수는 1
            if (!coeffRead)
            {
                coefficient = 1;        // 계수를 1로 설정
                // 음수 부호가 있었으면 계수에 음수를 붙임   
                if (isNegative)
                {
                    coefficient = -coefficient;     // 계수에 음수를 붙임
                }
            }

            // 차수를 읽어들임
            if (str.peek() == '^')
            {
                str >> c;       // '^' 문자를 읽어들임
                bool isExpNegative = false;     // 지수가 음수인지 확인하는 변수

                // 지수가 음수인 경우
                if (str.peek() == '-')
                {
                    isExpNegative = true;       // 지수가 음수임을 표시
                    str.get();      // '-' 문자를 읽어들임
                }

                string strExp;      // 지수를 저장할 문자열
                // 지수를 읽어들임
                while (isdigit(str.peek()))
                {
                    strExp.push_back(str.get());        // 문자를 읽어들여 문자열에 추가
                }

                exponent = stoi(strExp);        // 문자열을 정수로 변환
                // 지수가 음수였으면 지수에 음수를 붙임
                if (isExpNegative)
                {
                    exponent = -exponent;       // 지수에 음수를 붙임
                }
            }
            // 차수가 없는 경우
            else
            {
                exponent = 1;       // 차수를 1로 설정
            }

            Term* term = new Term();        // 새로운 항을 저장할 노드 생성
            term->SetCoeff(coefficient);        // 계수 설정
            term->SetExponent(exponent);        // 차수 설정
            Poly.Insert(term);      // 다항식에 항 추가

            isNegative = false;     // 음수 부호로 초기화
            coefficient = 0;        // 계수 초기화
            exponent = 0;       // 차수 초기화
            coeffRead = false;      // 계수를 읽지 않았음을 표시
        }
    }
}
