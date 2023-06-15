#include"myqueue.h"

myqueue::myqueue()
{
	// ������. �����Ϳ� ����� �ʱ�ȭ���ش�.
	m_pHead = nullptr;
	m_pTail = nullptr;
	m_Size = 0;
}

myqueue::~myqueue()
{
	// �Ҹ���. m_pHead�� �Ҵ� �����Ѵ�.
	// ��� ��带 ��ȸ�ϸ� �Ҵ� ����
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
	// setSize. ����� 0�� ��� �Էµ� ������ ������� �����Ѵ�.
	if (m_Size == 0)
		m_Size = n;
	else
	{
		// �ƴ� ��� �޸𸮸� �Ҵ� �����ϰ� �� �������� ť�� �����.
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
	// isEmpty. head�� ����Ű�� ���� nullptr�̸� ������Ƿ� true, �ƴϸ� false�� ��ȯ�Ѵ�.
	if (m_pHead == nullptr)
		return true;
	else
		return false;
}

bool myqueue::isFull()
{
	// isFull. ť�� ��Ҹ� ���� ��á���� �Ǵ��Ѵ�.
	int count = 0;
	Node* temp = m_pHead;
	while (temp != nullptr)
	{
		count++;
		temp = temp->getNext();
	}

	// �� ������ m_Size�� ������ ��á���Ƿ� true ��ȯ
	if (count == m_Size)
		return true;
	else
		return false;
}

bool myqueue::push(Node* pNode)
{
	// push_back. ť�� ������ ���� �� ���Ḯ��Ʈ�� ���� ���� �����Ѵ�.
	// ���Կ� �����ϸ� true, �����ϸ� false�� ��ȯ�Ѵ�.
	if (isFull() == true)
		return false;

	// ������� �� head�� tail�� ���� �������ش�.
	if (isEmpty() == true)
	{
		m_pHead = pNode;
		m_pTail = pNode;
	}
	// �׷��� ���� �� tail�� ������ �������ش�.
	else
	{
		m_pTail->setNext(pNode);
		m_pTail = pNode;
	}
	
	return true;
}

Node* myqueue::pop()
{
	// pop. ���� ���� ���� �������� �ּҸ� ��ȯ�ϰ� �����Ѵ�.
	// push�� ���� m_pTail�� ����Ű�� ��尡 ���� ���� ���� �������̴�.
	// Ȯ���� ���� cout���� ������ �����͸� ����Ѵ�.
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
	// printqueue. ť�� ��� ��Ҹ� ����Ѵ�.
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
	// ������. link�� nullptr�� �����Ѵ�.
	m_pNext = nullptr;
	m_Data = 0;
}

Node::~Node()
{
	// �Ҹ���. �޸𸮴� ~myqueue���� ��� �Ҵ� �����ȴ�.
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