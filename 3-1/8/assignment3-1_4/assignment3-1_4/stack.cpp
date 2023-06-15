#include "Stack.h"	// 큐 헤더파일 참조
using namespace std;

Node::Node() // 생성자 
{
	m_pNext = nullptr; // 노드를 nullptr로 초기화
	m_Data = 0; // 원소 값을 0으로 초기화
}

Node::~Node() // 소멸자
{
	
}

void Node::SetData(int n) // 데이터 설정
{
	m_Data = n; // 입력한 n을 원소로
}

void Node::SetNext(Node* pNext) // 다음 노드
{
	m_pNext = pNext; // 다음 노드로 설정
}

int Node::GetData() // 데이터 반환
{
	return m_Data;
}

Node* Node::GetNext() // 노드 반환
{
	return m_pNext;
}

Stack::Stack() // 스택 생성자
{
	m_pHead = nullptr; // 맨 처음 값
	m_Size = 0; // 큐의 크기
	m_NumElement = 0; // 스택의 데이터 개수
}

Stack::~Stack() // 소멸자
{
	Node* pNode = m_pHead; // 맨 위 값
	Node* nextNode = nullptr; // 다음 노드를 널문자로 초기화

	while (pNode != nullptr) // 맨 아래 까지 가기전에
	{
		nextNode = pNode->GetNext();
		delete pNode; // 순차적으로 할당해제
		pNode = nextNode;
	}
}

void Stack::SetSize(int n) // 스택 크기 설정
{
	m_Size = n; // n의 크기로 스택 크기 설정
}

bool Stack::IsEmpty() // 스택이 비어있는지 체크
{
	if (m_NumElement == 0) // 스택의 데이터  개수가 0이면 
		return true; // 빈 스택이므로 true 반환
	else // 그렇지 않으면
		return false; // false 반환
}

bool Stack::IsFull() // 스택이 꽉 차있는지 체크
{
	if (m_NumElement == m_Size) // 입력한 스택의 크기와 스택의 데이터 개수가 같다면
		return true; // true 반환
	else // 그렇지 않으면
		return false; // false 반환
}

bool Stack::Push(Node* pNode) // 스택의 데이터 입력
{
	if (IsFull()) // 꽉 차있으면 데이터를 넣지 못하므로
	{
		cout << "Full" << endl; // 오류 출력
		return false; // false 반환
	}

	pNode->SetNext(m_pHead); // 입력한 노드의 다음노드는 phead가 가르키는 노드
	m_pHead = pNode; // phead는 입력한 노드
	m_NumElement++; // 개수 증가

	return true;
}

Node* Stack::Pop() // 스택의 데이터 하나씩 빼기
{
	if (IsEmpty()) // 스택이 비어있다면 데이터를 뺄 수 없으므로
	{
		cout << "Empty" << endl; // Empty 출력
		return nullptr; // nullptr 반환
	}

	Node* pNode = m_pHead; // pNode를 pHead의 맨 처음 값으로 
	m_pHead = m_pHead->GetNext(); // 맨 처음 값이 빠져나가고 그 다음 값으로 pHead 설정
	m_NumElement--; // 스택의 데이터 개수 감소

	return pNode; // phead 반환
}

void Stack::PrintStack() // 스택 출력
{
	if (IsEmpty()) // 스택 비어있다면 
	{
		cout << "Empty" << endl; // Empty 출력
		return;
	}

	Node* pNode = m_pHead; // 뒤 값부터 출력해야하므로 

	while (pNode != nullptr) // nullptr이 오기 전까지 
	{
		cout << pNode->GetData() << " "; // 얻어온 데이터 출력 
		pNode = pNode->GetNext(); // 노드는 다음 노드로 업데이트
	}
	cout << endl; // 개행
}

