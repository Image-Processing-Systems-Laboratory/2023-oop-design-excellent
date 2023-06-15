#include"StudentScoreList.h"

Node::Node()
{
	// ������
	m_pNext = nullptr;
	m_pPrev = nullptr;
	m_Avg = 0;
}

Node::Node(double avg)
{
	m_pNext = nullptr;
	m_pPrev = nullptr;
	m_Avg = avg;
}

Node::~Node() {}

void Node::setAvg(double avg)
{
	m_Avg = avg;
}

void Node::setNext(Node* pNext)
{
	m_pNext = pNext;
}

void Node::setPrev(Node* pPrev)
{
	m_pPrev = pPrev;
}

double Node::getAvg()
{
	return m_Avg;
}

Node* Node::getNext()
{
	return m_pNext;
}

Node* Node::getPrev()
{
	return m_pPrev;
}

StudentScoreList::StudentScoreList()
{
	// ����Ʈ ������
	m_pHead = nullptr;
	m_pTail = nullptr;
}

StudentScoreList::~StudentScoreList()
{
	while (m_pHead != nullptr)
	{
		Node* temp = m_pHead;
		m_pHead = m_pHead->getNext();
		delete temp;
	}
}

void StudentScoreList::Insert(Node* pNode)
{
	// ������������ ���Ḯ��Ʈ�� ����

	// ����Ʈ�� ����� ��
	if (m_pHead == nullptr)
	{
		m_pHead = pNode;
		m_pTail = pNode;
		pNode->setNext(nullptr);
		pNode->setPrev(nullptr);
		return;
	}

	// ù ��Һ��� ���� ��, ���ο� ���� ����
	if (pNode->getAvg() < m_pHead->getAvg())
	{
		pNode->setNext(m_pHead);
		m_pHead->setPrev(pNode);
		pNode->setPrev(nullptr);
		m_pHead = pNode;
		return;
	}

	// ���� ��ġ Ž��
	Node* temp = m_pHead;
	while (temp != nullptr && pNode->getAvg() >= temp->getAvg())
		temp = temp->getNext();

	// Ž���ߴ��� ���� ������ ��� ���ο� ���Ϸ� ����
	if (temp == nullptr)
	{
		m_pTail->setNext(pNode);
		pNode->setPrev(m_pTail);
		pNode->setNext(nullptr);
		m_pTail = pNode;
	}
	else
	{
		// Ž���� ��ġ�� �� ��带 �߰��� ����
		Node* prev = temp->getPrev();
		prev->setNext(pNode);
		pNode->setPrev(prev);
		pNode->setNext(temp);
		temp->setPrev(pNode);
	}
}

void StudentScoreList::printlist(bool isAscending)
{
	// �Է°��� ���̸� ��������(= �Ӹ�����)���
	// �Է°��� �����̸� ��������(= ��������)���

	// �� ����Ʈ ����ó��
	if (m_pHead == nullptr)
	{
		cout << "List is empty. " << endl;
		return;
	}

	if (isAscending == true)
	{
		cout << "Printing list in ascending order." << endl;
		Node* temp = m_pHead;
		while (temp != nullptr)
		{
			cout << temp->getAvg() << " ";
			temp = temp->getNext();
		}
	}
	else
	{
		cout << "Printing list in descending order." << endl;
		Node* temp = m_pTail;
		while (temp != nullptr)
		{
			cout << temp->getAvg() << " ";
			temp = temp->getPrev();
		}
	}
	cout << endl;
}