#include <iostream>
#include <string>
using namespace std;

//하나의 다항식을 구성하는 하나의 항을 표현하는 클래스
class Term { //Term class
private:
    int m_Coefficient; //계수
    int m_Exponent; //지수
    Term* m_pNext; //연결 리스트의 다음 노드를 가리키는 포인터
public:
    Term() { //생성자 //초기화
        m_Coefficient = 0;
        m_Exponent = 0;
        m_pNext = NULL;
    }
    ~Term() {} //소멸자

    void SetCoeff(int coeff) {  //계수 설정
        m_Coefficient = coeff; } 

    void SetExponent(int exponent) { //지수 설정
        m_Exponent = exponent; } 

    void SetNext(Term* pNext) {  //다음 노드 설정
        m_pNext = pNext; }

    int GetCoeff() { //계수 반환
        return m_Coefficient; }

    int GetExponent() { //지수 반환
        return m_Exponent; } 

    Term* GetNext() { //다음 노드 반환
        return m_pNext; } 
};

class Polynomial { //Polynomial class
private:
    Term* m_pHead; //연결 리스트의 첫 번째 노드를 가리키는 포인터

public:
    Polynomial() {  //생성자
        m_pHead = NULL; }

    ~Polynomial() {} //소멸자

    void Insert(Term* pTerm) { //항을 추가하는 함수
        Term* pCurr = m_pHead;
        Term* pPrev = NULL;

        while (pCurr != NULL && pTerm->GetExponent() < pCurr->GetExponent()) { //삽입할 항의 지수가 더 작은 노드를 찾기
            pPrev = pCurr;
            pCurr = pCurr->GetNext();
        }
        if (pCurr != NULL && pTerm->GetExponent() == pCurr->GetExponent()) { //같은 지수를 가진 노드가 이미 있는 경우 계수를 더한다
            pCurr->SetCoeff(pCurr->GetCoeff() + pTerm->GetCoeff());
            delete pTerm; //중복된 항은 삭제
        }
        else { //그 외의 경우 새로운 노드를 삽입
            if (pPrev == NULL) {
                m_pHead = pTerm; //연결 리스트가 비어있는 경우
            }
            else {
                pPrev->SetNext(pTerm); //중간에 삽입하는 경우
            }
            pTerm->SetNext(pCurr);
        }
    }

    void PrintList() { //다항식 출력 함수
        //m_pHead는 다항식의 첫번째 항을 가리키는 포인터
        //pCurr은 현재 처리 중인 항을 가리키는 포인터
        Term* pCurr = m_pHead;
        while (pCurr != NULL) {
            //만약 현재 처리 중인 항이 첫번째 항이 아니고, 계수가 양수인 경우 "+"를 출력
            if (pCurr != m_pHead && pCurr->GetCoeff() > 0) {
                cout << "+";
            }
            //현재 처리 중인 항의 계수와 차수를 출력합니다.
            cout << pCurr->GetCoeff() << "x^" << pCurr->GetExponent();
            //다음 항을 처리하기 위해 pCurr을 다음 항으로 이동
            pCurr = pCurr->GetNext();
        }
        cout << endl;
    }

    void Add(Polynomial& poly) { //다항식 더하기 함수
        Term* pCurr1 = m_pHead; //첫 번째 다항식의 현재 항을 가리키는 포인터
        Term* pCurr2 = poly.m_pHead; //두 번째 다항식의 현재 항을 가리키는 포인터

        // 현재 다항식과 더해지는 다른 다항식의 모든 항을 처리합니다.
        while (pCurr1 != NULL && pCurr2 != NULL) {
            //현재 다항식의 현재 항의 차수가 더해지는 다른 다항식의 현재 항의 차수보다 작은 경우
            //현재 다항식의 다음 항을 처리
            if (pCurr1->GetExponent() < pCurr2->GetExponent()) {
                pCurr1 = pCurr1->GetNext();
            }
            //현재 다항식의 현재 항의 차수가 더해지는 다른 다항식의 현재 항의 차수보다 큰 경우
            //더해지는 다른 다항식의 현재 항을 현재 다항식에 추가
            else if (pCurr1->GetExponent() > pCurr2->GetExponent()) {
                //새로운 항을 생성
                Term* pTerm = new Term;
                //생성한 항에 더해지는 다른 다항식의 현재 항의 계수와 차수를 설정
                pTerm->SetCoeff(pCurr2->GetCoeff());
                pTerm->SetExponent(pCurr2->GetExponent());
                //현재 다항식에 새로운 항을 삽입
                Insert(pTerm);
                //더해지는 다른 다항식의 다음 항을 처리하기 위해 포인터를 이동
                pCurr2 = pCurr2->GetNext();
            }
            else { //첫 번째 다항식과 두 번째 다항식의 현재 항의 차수가 같은 경우
                pCurr1->SetCoeff(pCurr1->GetCoeff() + pCurr2->GetCoeff()); //두 다항식의 해당 항의 계수를 더한다

                pCurr1 = pCurr1->GetNext(); //두 다항식의 다음 항으로
                pCurr2 = pCurr2->GetNext();
            }
        }

        while (pCurr2 != NULL) { //두 번째 다항식이 끝나고 첫 번째 다항식에 항을 추가해야 하는 경우
            Term* pTerm = new Term;
            pTerm->SetCoeff(pCurr2->GetCoeff());
            pTerm->SetExponent(pCurr2->GetExponent());

            Insert(pTerm); //현재 다항식에 새로운 항을 삽입
            pCurr2 = pCurr2->GetNext(); //더해지는 다른 다항식의 다음 항을 처리하기 위해 포인터를 이동
        }
    }

    void Sub(Polynomial& poly) { //다항식 빼기 함수
        Term* pCurr1 = m_pHead; //첫 번째 다항식의 현재 항을 가리키는 포인터
        Term* pCurr2 = poly.m_pHead; //두 번째 다항식의 현재 항을 가리키는 포인터
        //두 다항식의 현재 항을 비교하여 작은 차수의 항이 있는 다항식의 현재 항을 다음 항으로 이동시키며 처리
        while (pCurr1 != NULL && pCurr2 != NULL) {  //두 다항식의 노드가 모두 NULL이 아닐 때까지 반복
            if (pCurr1->GetExponent() < pCurr2->GetExponent()) { //첫 번째 다항식의 지수가 더 작은 경우
                pCurr1 = pCurr1->GetNext();
            }
            else if (pCurr1->GetExponent() > pCurr2->GetExponent()) { //두 번째 다항식의 지수가 더 작은 경우
                Term* pTerm = new Term;
                pTerm->SetCoeff(-(pCurr2->GetCoeff())); //두 번째 다항식의 각 항의 계수를 음수로
                pTerm->SetExponent(pCurr2->GetExponent());
                Insert(pTerm); //새로운 항을 결과 다항식에 추가
                pCurr2 = pCurr2->GetNext(); //두 번째 다항식의 다음 노드로
            }
            else { //두 다항식의 지수가 같은 경우
                pCurr1->SetCoeff(pCurr1->GetCoeff() - pCurr2->GetCoeff()); //두 번째 다항식의 각 항의 계수를 음수로

                pCurr1 = pCurr1->GetNext(); //두 다항식의 다음 노드로
                pCurr2 = pCurr2->GetNext();
            }
        }
        //두 번째 다항식이 먼저 끝난 경우, 남은 첫 번째 다항식의 모든 항에 대해서 처리
        while (pCurr2 != NULL) { //두 번째 다항식이 남은 경우
            Term* pTerm = new Term;
            pTerm->SetCoeff(-(pCurr2->GetCoeff())); //두 번째 다항식의 각 항의 계수를 음수로
            pTerm->SetExponent(pCurr2->GetExponent());

            Insert(pTerm); //새로운 항을 결과 다항식에 추가
            pCurr2 = pCurr2->GetNext(); //두 번째 다항식의 다음 노드로
        }
        //계수가 0인 항을 삭제
        Term* pCurr = m_pHead;
        while (pCurr != NULL) { //결과 다항식을 반복하며
            if (pCurr->GetCoeff() == 0) {  //계수가 0인 항을 찾으면
                if (pCurr == m_pHead) { //첫 번째 항이라면 해당 항을 삭제하고 다음 항을 첫 번째 항으로 지정
                    m_pHead = pCurr->GetNext();
                    delete pCurr;
                    pCurr = m_pHead;
                }
                else { //그 외의 경우이면 이전 항과 다음 항을 연결
                    Term* pPrev = m_pHead; 
                    while (pPrev->GetNext() != pCurr) {
                        pPrev = pPrev->GetNext();
                    }
                    //해당 항을 삭제하고 다음 항으로 이동
                    pPrev->SetNext(pCurr->GetNext());
                    delete pCurr;
                    pCurr = pPrev->GetNext();
                }
            }
            else {
                pCurr = pCurr->GetNext();
            }
        }
    }
};

/*
int main() {
    Polynomial poly1;
    Term* pTerm = new Term;
    pTerm->SetCoeff(3);
    pTerm->SetExponent(3);
    poly1.Insert(pTerm);
    pTerm = new Term;
    pTerm->SetCoeff(2);
    pTerm->SetExponent(2);
    poly1.Insert(pTerm);

    pTerm = new Term;
    pTerm->SetCoeff(-4);
    pTerm->SetExponent(1);
    poly1.Insert(pTerm);

    Polynomial poly2;
    pTerm = new Term;
    pTerm->SetCoeff(-2);
    pTerm->SetExponent(4);
    poly2.Insert(pTerm);

    pTerm = new Term;
    pTerm->SetCoeff(-1);
    pTerm->SetExponent(2);
    poly2.Insert(pTerm);

    pTerm = new Term;
    pTerm->SetCoeff(1);
    pTerm->SetExponent(1);
    poly2.Insert(pTerm);

    cout << "Poly1: ";
    poly1.PrintList();

    cout << "Poly2: ";
    poly2.PrintList();

    poly1.Add(poly2);

    cout << "Poly1 + Poly2: ";
    poly1.PrintList();

    Polynomial poly3;
    Term* pTerm2 = new Term;
    pTerm2->SetCoeff(3);
    pTerm2->SetExponent(3);
    poly3.Insert(pTerm2);
    pTerm2 = new Term;
    pTerm2->SetCoeff(2);
    pTerm2->SetExponent(2);
    poly3.Insert(pTerm2);
    pTerm2 = new Term;
    pTerm2->SetCoeff(-4);
    pTerm2->SetExponent(1);
    poly3.Insert(pTerm2);

    Polynomial poly4;
    pTerm2 = new Term;
    pTerm2->SetCoeff(-2);
    pTerm2->SetExponent(4);
    poly4.Insert(pTerm2);
    pTerm2 = new Term;
    pTerm2->SetCoeff(-1);
    pTerm2->SetExponent(2);
    poly4.Insert(pTerm2);
    pTerm2 = new Term;
    pTerm2->SetCoeff(1);
    pTerm2->SetExponent(1);
    poly4.Insert(pTerm2);

    poly3.Sub(poly4);

    cout << "Poly1 - Poly2: ";
    poly3.PrintList();

    return 0;
}
*/


int main() {
    Polynomial poly1, poly2, poly3, poly4; //Polynomial 객체 생성
    Term* pTerm; //Term 포인터 변수 선언
    Term* pTerm2; //또 다른 Term 포인터 변수 선언
    int coeff, exponent; //계수와 지수를 저장할 변수
    string inputStr; //입력받은 문자열을 저장할 변수
    char oper; //연산자를 저장할 변수

    cout << "poly1: ";
    getline(cin, inputStr); //문자열 입력받기
    for (int i = 0; i < inputStr.length();) {
        pTerm = new Term; //Term 객체 동적 할당
        coeff = 0;
        exponent = 0;
        while (inputStr[i] != '+' && inputStr[i] != '-') { //입력받은 문자열에서 '+'나 '-'를 만날 때까지 반복
            if (inputStr[i] == 'x') { //'x'를 만나면
                i += 2; //'x'와 '^' 다음의 문자를 건너뛴다
                break;
            }
            coeff = coeff * 10 + (inputStr[i] - '0'); //문자열을 정수로 변환하여 계수 저장
            i++; //다음 문자로 이동
        }
        if (coeff == 0)
            coeff = 1; //계수가 0인 경우 1로 저장
        if (i == inputStr.length())
            exponent = 0; //문자열의 끝까지 탐색한 경우 지수를 0으로 저장
        else {
            while (inputStr[i] != '+' && inputStr[i] != '-') { //'+'나 '-'를 만날 때까지 반복
                exponent = exponent * 10 + (inputStr[i] - '0'); //문자열을 정수로 변환하여 지수 저장
                i++; //다음 문자로 이동
                if (i == inputStr.length()) { //문자열의 끝까지 탐색한 경우
                    break; //반복 종료
                }
            }
        }
        pTerm->SetCoeff(coeff); //Term 객체에 계수 저장
        pTerm->SetExponent(exponent); //Term 객체에 지수 저장
        poly1.Insert(pTerm); //Polynomial 객체에 Term 객체 추가
        if (i != inputStr.length()) { //연산자가 있다면 저장
            oper = inputStr[i];
            i++;
        }
    }

    cout << "poly2: ";
    getline(cin, inputStr); //문자열 입력받기
    for (int i = 0; i < inputStr.length();) { 
        pTerm = new Term; //Term 객체 동적 할당
        coeff = 0;
        exponent = 0;
        while (inputStr[i] != '+' && inputStr[i] != '-') { //입력받은 문자열에서 '+'나 '-'를 만날 때까지 반복
            if (inputStr[i] == 'x') { //'x'를 만나면
                i += 2; //'x'와 '^' 다음의 문자를 건너뛴다
                break;
            }
            coeff = coeff * 10 + (inputStr[i] - '0'); //문자열을 정수로 변환하여 계수 저장
            i++; //다음 문자로 이동
        }
        if (coeff == 0)
            coeff = 1; //계수가 0인 경우 1로 저장
        if (i == inputStr.length())
            exponent = 0; //문자열의 끝까지 탐색한 경우 지수를 0으로 저장
        else {
            while (inputStr[i] != '+' && inputStr[i] != '-') { //'+'나 '-'를 만날 때까지 반복
                exponent = exponent * 10 + (inputStr[i] - '0'); //문자열을 정수로 변환하여 지수 저장
                i++;
                if (i == inputStr.length()) { //문자열의 끝까지 탐색한 경우
                    break; //반복 종료
                }
            }
        }
        pTerm->SetCoeff(coeff); //Term 객체에 계수 저장
        pTerm->SetExponent(exponent); //Term 객체에 지수 저장
        poly2.Insert(pTerm); //Polynomial 객체에 Term 객체 추가
        if (i != inputStr.length()) { //연산자가 있다면 저장
            oper = inputStr[i];
            i++;
        }
    }

    cout << "sum: "; //Polynomial 객체에 poly2를 더하는 메소드 호출
    poly1.Add(poly2);
    poly1.PrintList(); //Polynomial 객체 출력하는 메소드 호출

    cout << "poly1: ";
    getline(cin, inputStr);  //문자열 입력받기
    for (int i = 0; i < inputStr.length();) {
        pTerm2 = new Term; //Term 객체 동적 할당
        coeff = 0;
        exponent = 0;
        while (inputStr[i] != '+' && inputStr[i] != '-') { //입력받은 문자열에서 
            if (inputStr[i] == 'x') { //'x'를 만나면
                i += 2; //'x'와 '^' 다음의 문자를 건너뛴다
                break;
            }
            coeff = coeff * 10 + (inputStr[i] - '0'); //문자열을 정수로 변환하여 계수 저장
            i++;
        }
        if (coeff == 0)
            coeff = 1; ///계수가 0인 경우 1로 저장
        if (i == inputStr.length())
            exponent = 0; //문자열의 끝까지 탐색한 경우 지수를 0으로 저장
        else {
            while (inputStr[i] != '+' && inputStr[i] != '-') { //'+'나 '-'를 만날 때까지 반복
                exponent = exponent * 10 + (inputStr[i] - '0'); //문자열을 정수로 변환하여 지수 저장
                i++; //다음 문자로 이동
                if (i == inputStr.length()) { //문자열의 끝까지 탐색한 경우
                    break; //반복 종료
                }
            }
        }
        pTerm2->SetCoeff(coeff); //Term 객체에 계수 저장
        pTerm2->SetExponent(exponent); //Term 객체에 지수 저장
        poly3.Insert(pTerm2); //Polynomial 객체에 Term 객체 추가
        if (i != inputStr.length()) { //연산자가 있다면 저장
            oper = inputStr[i];
            i++;
        }
    }

    cout << "poly2: ";
    getline(cin, inputStr); //문자열 입력받기
    for (int i = 0; i < inputStr.length();) {
        pTerm2 = new Term; //Term 객체 동적 할당
        coeff = 0;
        exponent = 0;
        while (inputStr[i] != '+' && inputStr[i] != '-') {  //입력받은 문자열에서 '+'나 '-'를 만날 때까지 반복
            if (inputStr[i] == 'x') { //'x'를 만나면
                i += 2; //'x'와 '^' 다음의 문자를 건너뛴다
                break;
            }
            coeff = coeff * 10 + (inputStr[i] - '0'); //문자열을 정수로 변환하여 계수 저장
            i++; //다음 문자로 이동
        }
        if (coeff == 0)
            coeff = 1; //계수가 0인 경우 1로 저장
        if (i == inputStr.length()) //문자열의 끝까지 탐색한 경우 지수를 0으로 저장
            exponent = 0;
        else {
            while (inputStr[i] != '+' && inputStr[i] != '-') { //'+'나 '-'를 만날 때까지 반복
                exponent = exponent * 10 + (inputStr[i] - '0');  //문자열을 정수로 변환하여 지수 저장
                i++;
                if (i == inputStr.length()) { //문자열의 끝까지 탐색한 경우
                    break; //반복 종료
                }
            }
        }
        pTerm2->SetCoeff(coeff); //Term 객체에 계수 저장
        pTerm2->SetExponent(exponent);  //Term 객체에 지수 저장
        poly4.Insert(pTerm2); //Polynomial 객체에 Term 객체 추가
        if (i != inputStr.length()) { //연산자가 있다면 저장
            oper = inputStr[i];
            i++;
        }
    }
    cout << "sub: "; //Polynomial 객체에 poly4를 빼는 메소드 호출
    poly3.Sub(poly4); 
    poly3.PrintList();  //Polynomial 객체 출력하는 메소드 호출

    return 0;
}