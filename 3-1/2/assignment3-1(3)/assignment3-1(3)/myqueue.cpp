#include"myqueue.h"

myqueue::myqueue()
{
	// 생성자. 포인터와 사이즈를 초기화해준다.
	m_pHead = nullptr;
	m_pTail = nullptr;
	m_Size = 0;
}

myqueue::~myqueue()
{
	// 소멸자. m_pHead를 할당 해제한다.
	// 모든 노드를 순회하며 할당 해제
	Node* temp;
	while (m_pHead != nullptr)
	{
		temp = m_pHead;
		m_pHead = m_pHead->getNext();
		delete temp;
	}
}

void myqueue::setSize(int n)
{
	// setSize. 사이즈가 0인 경우 입력된 정수로 사이즈값을 설정한다.
	if (m_Size == 0)
		m_Size = n;
	else
	{
		// 아닌 경우 메모리를 할당 해제하고 새 사이즈의 큐를 만든다.
		Node* temp;
		while (m_pHead != nullptr)
		{
			temp = m_pHead;
			m_pHead = m_pHead->getNext();
			delete temp;
		}
		m_pTail = nullptr;
		m_Size = n;
	}
}

bool myqueue::isEmpty()
{
	// isEmpty. head가 가리키는 것이 nullptr이면 비었으므로 true, 아니면 false를 반환한다.
	if (m_pHead == nullptr)
		return true;
	else
		return false;
}

bool myqueue::isFull()
{
	// isFull. 큐의 요소를 세고 꽉찼는지 판단한다.
	int count = 0;
	Node* temp = m_pHead;
	while (temp != nullptr)
	{
		count++;
		temp = temp->getNext();
	}

	// 총 개수가 m_Size랑 같으면 꽉찼으므로 true 반환
	if (count == m_Size)
		return true;
	else
		return false;
}

bool myqueue::push(Node* pNode)
{
	// push_back. 큐에 여유가 있을 때 연결리스트의 가장 끝에 삽입한다.
	// 삽입에 성공하면 true, 실패하면 false를 반환한다.
	if (isFull() == true)
		return false;

	// 비어있을 땐 head와 tail을 같게 설정해준다.
	if (isEmpty() == true)
	{
		m_pHead = pNode;
		m_pTail = pNode;
	}
	// 그렇지 않을 땐 tail만 변경해 연결해준다.
	else
	{
		m_pTail->setNext(pNode);
		m_pTail = pNode;
	}
	
	return true;
}

Node* myqueue::pop()
{
	// pop. 가장 먼저 들어온 데이터의 주소를 반환하고 제거한다.
	// push로 인해 m_pTail이 가리키는 노드가 가장 먼저 들어온 데이터이다.
	// 확인을 위해 cout으로 삭제할 데이터를 출력한다.
	if (isEmpty() == true)
		return nullptr;

	Node* temp = m_pHead;
	m_pHead = m_pHead->getNext();

	if (m_pHead == nullptr)
		m_pTail = nullptr;

	cout << temp->getData() << endl;
	return temp;
}

void myqueue::printqueue()
{
	// printqueue. 큐의 모든 요소를 출력한다.
	if (isEmpty() == true)
		return;

	Node* temp = m_pHead;
	while (temp != nullptr)
	{
		cout << temp->getData() << " ";
		temp = temp->getNext();
	}
	cout << endl;
}

Node::Node()
{
	// 생성자. link를 nullptr로 설정한다.
	m_pNext = nullptr;
	m_Data = 0;
}

Node::~Node()
{
	// 소멸자. 메모리는 ~myqueue에서 모두 할당 해제된다.
}

void Node::setData(int n)
{
	m_Data = n;
}

void Node::setNext(Node* pNext)
{
	m_pNext = pNext;
}

int Node::getData()
{
	return m_Data;
}

Node* Node::getNext()
{
	return m_pNext;
}