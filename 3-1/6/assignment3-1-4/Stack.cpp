#include "Stack.h"
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
	Stack
*/

Stack::Stack()
{
	// 스택 객체를 생성했을때 처음 사이즈와 노드의 개수는 0
	m_Size = 0;
	m_NumElement = 0;

	m_pHead = nullptr;
	first = nullptr;
}

Stack::~Stack()
{

}

void Stack::SetSize(int n)
{
	this->m_Size = n; // 스택의 최대 사이즈 설정
}

bool Stack::IsEmpty()
{
	if (m_NumElement == 0) { //현재 노드의 개수가 0개이면 비어있음 -> true 출력
		return true;
	}
	else {
		return false;
	}
}

bool Stack::IsFull()
{
	if (m_NumElement == m_Size) { //현재 노드의 개수가 스택의 최대 사이즈와 같으면 꽉 차있음 -> true 출력
		return true;
	}
	else {
		return false;
	}
}

bool Stack::Push(Node* pNode)
{
	if (pNode == nullptr) //예외처리
		return false;
	if (IsEmpty() == true) { // 현재 노드의 개수가 0일 때
		m_pHead = pNode;
		first = pNode;
	}
	else { // 현재 노드의 개수가 0이 아닐 때
		m_pHead->SetNext(pNode);
		m_pHead = pNode;
	}
	m_NumElement++; //노드 개수 추가
	return true;

}

void Stack::PrintStack()
{
	Node* pCur = first; //노드 하나씩 가리키는 역할

	while (pCur)
	{
		std::cout << pCur->GetData() << " ";
		pCur = pCur->GetNext();
	}
	std::cout << std::endl;
}

Node* Stack::Pop()
{
	Node* delNode = new Node; //삭제할 노드 옮겨놓는 역할
	Node* pCur = first; // 노드 하나씩 가리키는 역할

	// 삭제할 노드를 복사해둠
	delNode->SetData(m_pHead->GetData());
	delNode->SetNext(nullptr);

	// pCur가 삭제할 노드의 전 노드를 가리키도록 함
	while (pCur->GetNext() != m_pHead)
	{
		if (m_NumElement == 1) { // 삭제 전 노드의 개수가 1이면 pCur은 nullptr을 가리킴
			pCur = nullptr;
			break;
		}
		pCur = pCur->GetNext(); // 다음 노드 가리키게 함
	}

	delete m_pHead; //노드 삭제
	m_pHead = pCur; //pHead가 삭제한 노드 전 노드를 가리키게 함
	if (m_NumElement != 1) { // 삭제 전 노드의 개수가 1이 아니면 pHead가 가리키는 노드의 링크값을 nullptr로 설정
		m_pHead->SetNext(nullptr);
	}
	else { //삭제 전 노드의 개수가 1이면 삭제 후엔 노드가 없으므로 first의 값은 nullptr
		first = nullptr;
	}
	m_NumElement--; //노드 개수 감소
	return delNode; //삭제한 노드 반환
}