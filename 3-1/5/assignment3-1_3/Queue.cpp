#include "Queue.h"
#include <iostream>

//Node Class member function
Node::Node()
{
	//멤버 변수 초기화
	m_pNext = nullptr;
	m_Data = 0;
}

Node::~Node()
{
	m_pNext = nullptr;
	m_Data = 0;
}

void Node::SetData(int n)            //Data 설정
{
	m_Data = n;
}

void Node::SetNext(Node* pNext)      //Link 설정
{
	m_pNext = pNext;
}

int Node::GetData()                  //Data 반환
{
	return m_Data;
}

Node* Node::GetNext()                //Link 반환
{
	return m_pNext;
}


//Queue Class member function
Queue::Queue()
{
	//멤버 변수 초기화
	m_pHead = nullptr;
	m_pTail = nullptr;
	m_Size = 0;
	m_NumElement = 0;
}

Queue::~Queue()
{
	Node* pPre;

	//Queue가 비어있지 않은 경우 모든 노드의 메모리 해제
	while (m_pHead != nullptr) {
		pPre = m_pHead;
		m_pHead = m_pHead->GetNext();

		delete pPre;
	}
}

void Queue::SetSize(int n)            //m_Size 설정
{
	m_Size = n;
}

bool Queue::IsEmpty()                 //Queue가 비어있는 상태(element의 개수가 0인 상태)이면 true, 그렇지 않으면 false 반환
{
	if (m_NumElement == 0) {
		return true;      //비어 있는 경우
	}
	else {
		return false;     //비어 있지 않은 경우
	}
}

bool Queue::IsFull()                  //Queue가 가득 찬 상태(element의 개수가 Queue의 크기와 같은 상태)이면 ture, 그렇지 않으면 false 반환
{
	if (m_NumElement == m_Size) {
		return true;      //가득 찬 상태인 경우
	}
	else {
		return false;     //가득 차지 않은 상태인 경우
	}
}

bool Queue::Push(Node* pNode)         //element 추가
{
	//Queue가 가득 찬 경우 false 반환
	if (m_Size == m_NumElement) {
		return false;
	}

	pNode->SetNext(nullptr);     //Link에 nullptr 대입

	//새로운 노드 추가 과정
	if (m_pHead == nullptr) {    //첫 번째 노드인 경우
		m_pHead = pNode;
		m_pTail = pNode;
	}
	else {
		m_pTail->SetNext(pNode);
		m_pTail = pNode;
	}

	m_NumElement++;

	return true;
}

Node* Queue::Pop()                    //element 삭제 (가장 먼저 들어 온 element부터 삭제)
{
	if (m_NumElement > 0) {
		Node* pPre = m_pHead;

		if (m_NumElement == 1) {    //노드가 1개일 경우
			m_pHead = nullptr;
			m_pTail = nullptr;
		}
		else {
			m_pHead = m_pHead->GetNext();     //Head를 다음 노드로 변경
		}

		m_NumElement--;

		return pPre;                      //Queue에서 삭제한 노드 반환
	}
	else {                          //Queue에 노드가 없을 경우
		return nullptr;
	}
}

void Queue::PrintQueue()              //Queue의 element를 모두 출력(가장 먼저 들어온 element부터 출력)
{
	Node* pCur = m_pHead;

	//Queue의 끝까지 도달할 때까지 각 노드의 data 출력
	while (pCur != nullptr) {
		std::cout << pCur->GetData() << std::endl;
		pCur = pCur->GetNext();  //다음 노드로 이동
	}
}