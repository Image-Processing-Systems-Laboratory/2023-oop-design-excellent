#include "Queue.h"
#include <iostream>
/*
	Node
*/

Node::Node()
{

}

Node::~Node()
{

}

void Node::SetData(int n)
{
	this->m_Data = n;  //노드의 멤버변수에 key값 대입
}

void Node::SetNext(Node* pNext)
{
	this->m_pNext = pNext; //노드의 멤버변수에 링크값 대입
}

int Node::GetData()
{
	return m_Data; //노드의 key값 반환
}

Node* Node::GetNext()
{
	return m_pNext; //노드의 링크값 반환
}

/*
	Queue
*/

Queue::Queue()
{
	// 큐 객체를 생성했을때 처음 사이즈와 노드의 개수는 0
	m_Size = 0;
	m_NumElement = 0;
}

Queue::~Queue()
{

}

void Queue::SetSize(int n)
{
	this->m_Size = n; // 큐의 최대 사이즈 설정
}

bool Queue::IsEmpty()
{
	if (m_NumElement == 0) { //현재 노드의 개수가 0개이면 비어있음 -> true 출력
		return true;
	}
	else {
		return false;
	}
}

bool Queue::IsFull()
{
	if (m_NumElement == m_Size) { //현재 노드의 개수가 큐의 최대 사이즈와 같으면 꽉 차있음 -> true 출력
		return true;
	}
	else {
		return false;
	}
}

bool Queue::Push(Node* pNode)
{
	if (pNode == nullptr) //예외처리
		return false;
	if (IsEmpty() == true) { // 현재 노드의 개수가 0일 때
		// pHead와 pTail이 가리키는 노드는 같음
		m_pHead = pNode;
		m_pTail = pNode;
	}
	else { // 현재 노드의 개수가 0이 아닐 때
		// 기존에 pTail이 가리키던 노드의 링크값을 새 노드를 가리키도록 설정하고 pTail도 새 노드를 가키리도록 설정
		m_pTail->SetNext(pNode);
		m_pTail = pNode;
	}
	m_NumElement++; //노드 개수 추가
	return true;

}

void Queue::PrintQueue()
{
	Node* pCur = m_pHead; // 노드를 하나씩 가리키는 역할 
	while (pCur)
	{
		//노드의 key값 출력 후 다음 노드로 옮김
		std::cout << pCur->GetData() << " ";
		pCur = pCur->GetNext();
	}
	std::cout << std::endl;
}

Node* Queue::Pop()
{
	Node* delNode = new Node; //삭제할 노드 옮겨놓는 역할
	delNode->SetData(m_pHead->GetData()); // 삭제할 노드의 key값 복사
	delNode->SetNext(m_pHead->GetNext()); // 삭제할 노드의 링크값 복사

	Node* temp = m_pHead->GetNext(); // 삭제할 노드 다음 노드 가리키는 역할
	delete m_pHead; // 처음 노드 삭제
	m_pHead = temp; //pHead가 삭제한 노드의 다음 노드 가리키게 함
	m_NumElement--; //노드 개수 감소
	return delNode; //삭제한 노드 반환
}