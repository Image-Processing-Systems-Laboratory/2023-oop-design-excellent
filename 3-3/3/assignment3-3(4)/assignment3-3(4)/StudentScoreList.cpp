#include"StudentScoreList.h"

Node::Node()
{
	// 생성자
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
	// 리스트 생성자
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
	// 오름차순으로 연결리스트에 삽입

	// 리스트가 비었을 때
	if (m_pHead == nullptr)
	{
		m_pHead = pNode;
		m_pTail = pNode;
		pNode->setNext(nullptr);
		pNode->setPrev(nullptr);
		return;
	}

	// 첫 요소보다 작을 때, 새로운 헤드로 삽입
	if (pNode->getAvg() < m_pHead->getAvg())
	{
		pNode->setNext(m_pHead);
		m_pHead->setPrev(pNode);
		pNode->setPrev(nullptr);
		m_pHead = pNode;
		return;
	}

	// 삽입 위치 탐색
	Node* temp = m_pHead;
	while (temp != nullptr && pNode->getAvg() >= temp->getAvg())
		temp = temp->getNext();

	// 탐색했더니 끝에 도달한 경우 새로운 테일로 삽입
	if (temp == nullptr)
	{
		m_pTail->setNext(pNode);
		pNode->setPrev(m_pTail);
		pNode->setNext(nullptr);
		m_pTail = pNode;
	}
	else
	{
		// 탐색한 위치에 새 노드를 중간에 삽입
		Node* prev = temp->getPrev();
		prev->setNext(pNode);
		pNode->setPrev(prev);
		pNode->setNext(temp);
		temp->setPrev(pNode);
	}
}

void StudentScoreList::printlist(bool isAscending)
{
	// 입력값이 참이면 오름차순(= 머리부터)출력
	// 입력값이 거짓이면 내림차순(= 꼬리부터)출력

	// 빈 리스트 예외처리
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