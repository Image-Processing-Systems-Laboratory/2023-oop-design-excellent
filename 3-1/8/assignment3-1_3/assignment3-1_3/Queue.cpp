#include "Queue.h"	// 큐 헤더파일 참조
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

Queue::Queue() // 큐 생성자
{
	m_pHead = nullptr; // 맨 처음 값
	m_pTail = nullptr; // 맨 끝 값을 둘 다 nullptr로 초기화
	m_Size = 0; // 큐의 크기
	m_NumElement = 0; // 큐의 데이터 개수
}

Queue::~Queue() // 소멸자
{
	Node* pNode = m_pHead; // 처음 값 부터
	Node* pNext = nullptr; // 다음 노드를 널문자로 초기화

	while (pNode != nullptr) // 맨 끝에 오기전까지
	{
		pNext = pNode->GetNext(); 
		delete pNode;  // 순차적으로 할당해제
		pNode = pNext;
	}
}

void Queue::SetSize(int n) // 큐 크기 설정
{
	m_Size = n; // n의 크기로 큐 크기 설정
}

bool Queue::IsEmpty() // 큐가 비어있는지 체크
{
	if (m_NumElement == 0) // 큐의 데이터  개수가 0이면 
		return true; // 빈 큐이므로 true 반환
	else // 그렇지 않으면
		return false; // false 반환
}

bool Queue::IsFull() // 큐가 꽉 차있는지 체크
{
	if (m_NumElement == m_Size) // 입력한 큐의 크기와 큐의 데이터 개수가 같다면
		return true; // true 반환
	else // 그렇지 않으면
		return false; // false 반환
}

bool Queue::Push(Node* pNode) // 큐의 데이터 입력
{
	if (IsFull()) // 꽉 차있으면 데이터를 넣지 못하므로
	{
		cout << "Full" << endl; // 오류 출력
		return false; // false 반환
	}
	if (m_pHead == nullptr) // 맨 처음 값이 nullptr 이면 빈 큐 인 상태이므로
	{
		m_pHead = pNode; // 입력할 노드를 맨 처음값과 
		m_pTail = pNode; // 맨 끝값으로 바꿈
	}
	else // 처음 값이 nullptr이 아니면
	{
		m_pTail->SetNext(pNode); // 맨 끝 값은 계속 다음 노드의 값으로 변경해야함
		m_pTail = pNode; // 다음 값
	}

	m_NumElement++; // 큐의 개수 증가

	return true; 
}

Node* Queue::Pop() // 큐의 데이터 하나씩 빼기
{
	if (IsEmpty()) // 큐가 비어있다면 데이터를 뺄 수 없으므로
	{
		cout << "Empty" << endl; // Empty 출력
		return nullptr; // nullptr 반환
	}

	Node* pNode = m_pHead; // 맨 처음 값이 먼저 나가므로 pop노드는 맨 처음값으로 설정
	m_pHead = m_pHead->GetNext(); // 맨 처음 값이 빠져나가고 다음 값이 pHead로 설정
	m_NumElement--; // 큐의 데이터 개수 감소

	return pNode; // 빠져나간 큐의 데이터 반환
}

void Queue::PrintQueue() // 큐 출력
{
	if (IsEmpty()) // 큐가 비어있다면 
	{
		cout << "Empty" << endl; // Empty 출력
		return;
	}

	Node* pNode = m_pHead; // pHead 부터 출력해야하므로 

	while (pNode != nullptr) // nullptr이 오기 전까지 
	{
		cout << pNode->GetData() << " "; // 얻어온 데이터 출력 
		pNode = pNode->GetNext(); // 노드는 다음 노드로 업데이트
	}
	cout << endl; // 개행
}