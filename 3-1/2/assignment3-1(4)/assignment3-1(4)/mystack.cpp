#include"mystack.h"

mystack::mystack()
{
	// ������. �����Ϳ� ����� �ʱ�ȭ���ش�.
	m_pHead = nullptr;
	m_Size = 0;
}

mystack::~mystack()
{
	// �Ҹ���. m_pHead�� �Ҵ� �����Ѵ�.
	//  ��� ��带 ��ȸ�ϸ� �Ҵ� ����
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
	// setSize. ����� 0�� ��� �Էµ� ������ ������� �����Ѵ�.
	if (m_Size == 0)
		m_Size = n;
	else
	{
		// �ƴ� ��� �޸𸮸� �Ҵ� �����ϰ� �� �������� ������ �����.
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
	// isEmpty. head�� ����Ű�� ���� nullptr�̸� ������Ƿ� true, �ƴϸ� false�� ��ȯ�Ѵ�.
	if (m_pHead == nullptr)
		return true;
	else
		return false;
}
bool mystack::isFull()
{
	// isFull. ������ ��Ҹ� ���� ��á���� �Ǵ��Ѵ�.
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

bool mystack::push(Node* pNode)
{
	// push_front. ���ÿ� ������ ���� �� ���Ḯ��Ʈ�� ���� ���� �����Ѵ�.
	// ���Կ� �����ϸ� true, �����ϸ� false�� ��ȯ�Ѵ�.
	if (isFull() == true)
		return false;

	pNode->setNext(m_pHead);
	m_pHead = pNode;

	return true;
}

Node* mystack::pop()
{
	// pop. ���� ���߿� �� �ڷḦ ��ȯ�ϰ� ���ÿ��� ����
	// push�� ���� m_pHead�� ����Ű�� ��尡 ��¡ ���߿� ���� �������̴�.
	// Ȯ���� ���� cout���� ������ �����͸� ����Ѵ�.
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
	// printstack. ������ ��� ��Ҹ� ����Ѵ�.
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
	// ������. link�� nullptr�� �����Ѵ�.
	m_pNext = nullptr;
	m_Data = 0;
}

Node::~Node()
{
	// �Ҹ���. �޸𸮴� ~mystack���� ��� �Ҵ� �����ȴ�.
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