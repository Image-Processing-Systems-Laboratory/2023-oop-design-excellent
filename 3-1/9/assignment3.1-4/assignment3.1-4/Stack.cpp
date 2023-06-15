#include <iostream>
#include "Stack.h"
using namespace std;

Node::Node() { //Node class 생성자 변수 초기화
     m_pNext = NULL;
     m_Data = 0;
}

Node::~Node() { //소멸자
}

void Node::SetData(int n) {//private한 m_Data 값을 변경하기 위한 함수
    m_Data = n;
}

void Node::SetNext(Node* pNext) { //private한 m_pNext 값을 변경하기 위한 함수
    m_pNext = pNext;
}

int Node::GetData() { //private한 m_Data 값을 변경하기 위한 함수
    return m_Data;
}

Node* Node::GetNext() {//private한 m_pNext 값을 변경하기 위한 함수
    return m_pNext;
}

Stack::Stack() {//Stack class 생성자 변수 초기화
    m_pHead = NULL; 
    m_size = 0;
    m_NumElement = 0;
}

Stack::~Stack() {//소멸자
    Node* pTemp;
    while (m_pHead != NULL) { //연결리스트 노드를 제거
        pTemp = m_pHead; //노드를 임시 저장
        m_pHead = m_pHead->GetNext();//다음 노드를 헤드로 변경
        delete pTemp;//현재 노드 제거
    }
}

void Stack::SetSize(int n) {
    m_size = n; //스택 사이즈 설정
    cout << "스택 사이즈: " << n << endl;
}

bool Stack::isEmpty() { 
    return (m_NumElement == 0);  //스택이 비어있는지 여부 반환
}

bool Stack::isFull() { //안이 가득 채워져 있을때
    return (m_NumElement == m_size); //스택이 가득 찼는지 여부 반환
}

bool Stack::push(Node* pNode) { 
    if (isFull()) {//스택이 꽉 차있다면
        cout << "공간이 꽉차서 무시된 값이 있습니다." << endl;
        return false; //반환
    }

    pNode->SetNext(m_pHead);//노드의 다음 포인터를 헤드로 설정
    m_pHead = pNode; //헤드 노드를 추가한 노드로 변경
    m_NumElement++;//원소 갯수 증가
    return true;
}

Node* Stack::pop() { 
    if (isEmpty()) {//스택이 비어 있으면
        cout << "제거 할 원소가 없습니다." << endl; //오류 메세지 출력
        return NULL;
    }
    Node* pTemp = m_pHead;//헤드 노드를 임시 저장
    m_pHead = m_pHead->GetNext();//헤드를 다음 노드로 변경
    m_NumElement--;//원소 갯수 감소
    return pTemp;//헤드 노드 반환
}

void Stack::PrintStack() {
    Node* pTemp = m_pHead; //현재 노드를 헤드로 설정
    while (pTemp != NULL) {//연결리스트 노드를 전부 출력
        cout << pTemp->GetData() << endl;
        pTemp = pTemp->GetNext();//다음 노드로 이동
    }
    cout << endl;
}

