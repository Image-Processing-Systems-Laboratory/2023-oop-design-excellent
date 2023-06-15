#include"mystack.h"

mystack::mystack()
{
	// 생성자. 포인터와 사이즈를 초기화해준다.
	m_pHead = nullptr;
	m_Size = 0;
}

mystack::~mystack()
{
	// 소멸자. m_pHead를 할당 해제한다.
	//  모든 노드를 순회하며 할당 해제
	Node* temp;
	while (m_pHead != nullptr)
	{
		temp = m_pHead;
		m_pHead = m_pHead->getNext();
		delete temp;
	}
}

void mystack::setSize(int n)
{
	// setSize. 사이즈가 0인 경우 입력된 정수로 사이즈값을 설정한다.
	if (m_Size == 0)
		m_Size = n;
	else
	{
		// 아닌 경우 메모리를 할당 해제하고 새 사이즈의 스택을 만든다.
		Node* temp;
		while (m_pHead != nullptr)
		{
			temp = m_pHead;
			m_pHead = m_pHead->getNext();
			delete temp;
		}
		m_pHead = nullptr;
		m_Size = n;
	}
}

bool mystack::isEmpty()
{
	// isEmpty. head가 가리키는 것이 nullptr이면 비었으므로 true, 아니면 false를 반환한다.
	if (m_pHead == nullptr)
		return true;
	else
		return false;
}
bool mystack::isFull()
{
	// isFull. 스택의 요소를 세고 꽉찼는지 판단한다.
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

bool mystack::push(Node* pNode)
{
	// push_front. 스택에 여유가 있을 때 연결리스트의 가장 끝에 삽입한다.
	// 삽입에 성공하면 true, 실패하면 false를 반환한다.
	if (isFull() == true)
		return false;

	pNode->setNext(m_pHead);
	m_pHead = pNode;

	return true;
}

Node* mystack::pop()
{
	// pop. 제일 나중에 들어간 자료를 반환하고 스택에서 삭제
	// push로 인해 m_pHead가 가리키는 노드가 가징 나중에 들어온 데이터이다.
	// 확인을 위해 cout으로 삭제할 데이터를 출력한다.
	if (m_pHead == NULL)
		return nullptr;

	Node* temp = m_pHead;
	m_pHead = m_pHead->getNext();
	temp->setNext(nullptr);

	cout << temp->getData() << endl;
	return temp;
}

void mystack::printstack()
{
	// printstack. 스택의 모든 요소를 출력한다.
	if (isEmpty() == true)
		return;

	Node* temp = m_pHead;
	while (temp != NULL)
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
	// 소멸자. 메모리는 ~mystack에서 모두 할당 해제된다.
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