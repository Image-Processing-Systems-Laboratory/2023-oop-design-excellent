#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack stack;
    stack.SetSize(5); //stack사이즈 설정
    //1을stack에 넣음
    Node* pNode = new Node();
    pNode->SetData(1);
    stack.push(pNode);

    //2을 stack에 넣음
    pNode = new Node();
    pNode->SetData(2);
    stack.push(pNode);

    //1을stack에 넣음
    pNode = new Node();
    pNode->SetData(3);
    stack.push(pNode);

    //5을stack에 넣음
    pNode = new Node();
    pNode->SetData(5);
    stack.push(pNode);

    //8을stack에 넣음
    pNode = new Node();
    pNode->SetData(8);
    stack.push(pNode);

    //10을stack에 넣음
    pNode = new Node();
    pNode->SetData(10);
    stack.push(pNode);
    stack.PrintStack();

    //pop으로 숫자제거
    pNode = stack.pop();
    cout << "제거된 숫자: " << pNode->GetData() << endl;
    delete pNode;

    //pop으로 숫자제거
    pNode = stack.pop();
    cout << "제거된 숫자: " << pNode->GetData() << endl;
    delete pNode;

    //pop으로 숫자제거
    pNode = stack.pop();
    cout << "제거된 숫자: " << pNode->GetData() << endl;
    delete pNode;

    //남아있는 원소 출력
    cout << "남아있는 원소 " << endl;
    stack.PrintStack();

    //pop으로 숫자제거
    pNode = stack.pop();
    cout << "제거된 숫자: " << pNode->GetData() << endl;
    delete pNode;

    //pop으로 숫자제거
    pNode = stack.pop();
    cout << "제거된 숫자: " << pNode->GetData() << endl;
    delete pNode;


    //pop으로 숫자 제거
    pNode = stack.pop();
    delete pNode;

    return 0;
}