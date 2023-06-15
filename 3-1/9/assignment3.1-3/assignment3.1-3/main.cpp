#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue queue;
    queue.SetSize(5); //queue사이즈 설정
    //1을queue에 넣음
    Node* pNode = new Node();
    pNode->SetData(1);
    queue.push(pNode);
    
    //2을 queue에 넣음
    pNode = new Node();
    pNode->SetData(2);
    queue.push(pNode);
    
    //1을queue에 넣음
    pNode = new Node();
    pNode->SetData(3);
    queue.push(pNode);
    
    //5을queue에 넣음
    pNode = new Node();
    pNode->SetData(5);
    queue.push(pNode);

    //8을queue에 넣음
    pNode = new Node();
    pNode->SetData(8);
    queue.push(pNode);

    //10을queue에 넣음
    pNode = new Node();
    pNode->SetData(10);
    queue.push(pNode);
    queue.PrintQueue();

    //pop으로 숫자제거
    pNode = queue.pop();
    cout << "제거된 숫자: " << pNode->GetData() << endl;
    delete pNode;

    //pop으로 숫자제거
    pNode = queue.pop();
    cout << "제거된 숫자: " << pNode->GetData() << endl;
    delete pNode;

    //pop으로 숫자제거
    pNode = queue.pop();
    cout << "제거된 숫자: " << pNode->GetData() << endl;
    delete pNode;

    //남아있는 원소 출력
    cout << "남아있는 원소 " << endl;
    queue.PrintQueue();

    //pop으로 숫자제거
    pNode = queue.pop();
    cout << "제거된 숫자: " << pNode->GetData() << endl;
    delete pNode;
    
    //pop으로 숫자제거
    pNode = queue.pop();
    cout << "제거된 숫자: " << pNode->GetData() << endl;
    delete pNode;

    //pop으로 숫자 제거
    pNode = queue.pop();
    delete pNode;

    return 0;
}