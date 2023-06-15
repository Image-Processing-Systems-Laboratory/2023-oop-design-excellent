#include"mylinkedlist.h"

mylinkedlist::mylinkedlist()
{
	// ������
	m_pHead = nullptr;
	m_pTail = nullptr;
}

mylinkedlist::~mylinkedlist()
{
	// �Ҹ���
	// ��� ��带 ��ȸ�ϸ� �޸𸮸� �Ҵ������Ѵ�.
	Node* temp;
	while (m_pHead != nullptr)
	{
		temp = m_pHead;
		m_pHead = m_pHead->getNext();
		delete temp;
	}
}

bool mylinkedlist::push_back(char* data)
{
	// push_back, ����Ʈ ���� �����͸� �߰��Ѵ�.
	// �Ҵ� ���� ����ó��
	Node* pNode = new Node;
	if (pNode == nullptr)
		return false;

	// ����Ʈ�� �� ��� ��忡 �߰��ϰ� ���� ���� ��� ����Ű�� �Ѵ�.
	// �̹� ��Ұ� �ִ� ��� �� ��� �ڷ� �ڷḦ �߰��Ѵ�.
	pNode->setData(data);
	if (m_pHead == nullptr)
	{
		m_pHead = pNode;
		m_pTail = pNode;
		return true;
	}
	else
	{
		m_pTail->setNext(pNode);
		m_pTail = pNode;
		return true;
	}
}

void mylinkedlist::printlist()
{
	// ���Ḯ��Ʈ�� ��� ��Ҹ� ����Ѵ�.
	Node* temp = m_pHead;
	while (temp != nullptr)
	{
		cout << temp->getData() << " ";
		temp = temp->getNext();
	}
}

void mylinkedlist::sortlist()
{
	// ����Ʈ�� ������������ ��ҹ��ڸ� �����ϰ� ����
	// ����ó��
	if (m_pHead == nullptr) {
		return;
	}

	Node* cur = m_pHead;
	Node* index = nullptr;
	char* temp = nullptr;

	while (cur != nullptr) {
		index = cur->getNext();

		while (index != nullptr) {
			// ��ҹ��ڸ� �����ϰ� �� �� ������ �ʿ��ϸ� ����
			if (strcasecmp(cur->getData(), index->getData()) > 0) {
				temp = new char[strlen(cur->getData()) + 1];

				strcpy(temp, cur->getData());
				cur->setData(index->getData());
				index->setData(temp);
			}
			index = index->getNext();
		}
		cur = cur->getNext();
	}
}


Node* mylinkedlist::getHead()
{
	// ��� �����Ϳ� ������ �� �ִ� �Լ�
	return m_pHead;
}

Node::Node()
{
	// ������
	m_pNext = nullptr;
	m_Data = new char[1];
	m_Data[0] = NULL;
}

Node::~Node()
{
	// �Ҹ���
}

void Node::setData(char* data)
{
	strcpy(m_Data, data);
}

void Node::setNext(Node* pNext)
{
	m_pNext = pNext;
}

char* Node::getData()
{
	return m_Data;
}

Node* Node::getNext()
{
	return m_pNext;
}

int strcasecmp(char* s1, char* s2)
{
	// ���ڿ��� ���� �� ��ҹ��ڸ� �����ϰ� ����.
	while (*s1 != '\0' && *s2 != '\0')
	{
		// �ҹ��ڷ� �����ϰ� ����, �ٸ��� �� ��ȯ
		int dif = tolower(*s1) - tolower(*s2);
		if (dif != 0)
			return dif;
		++s1;
		++s2;
	}
	return tolower(*s1) - tolower(*s2);
}