#include"mylinkedlist.h"

mylinkedlist::mylinkedlist()
{
	// 생성자
	m_pHead = nullptr;
	m_pTail = nullptr;
}

mylinkedlist::~mylinkedlist()
{
	// 소멸자
	// 모든 노드를 순회하며 메모리를 할당해제한다.
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
	// push_back, 리스트 끝에 데이터를 추가한다.
	// 할당 실패 예외처리
	Node* pNode = new Node;
	if (pNode == nullptr)
		return false;

	// 리스트가 빈 경우 헤드에 추가하고 헤드와 테일 모두 가리키게 한다.
	// 이미 요소가 있는 경우 그 요소 뒤로 자료를 추가한다.
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
	// 연결리스트의 모든 요소를 출력한다.
	Node* temp = m_pHead;
	while (temp != nullptr)
	{
		cout << temp->getData() << " ";
		temp = temp->getNext();
	}
}

void mylinkedlist::sortlist()
{
	// 리스트를 오름차순으로 대소문자를 무시하고 정렬
	// 예외처리
	if (m_pHead == nullptr) {
		return;
	}

	Node* cur = m_pHead;
	Node* index = nullptr;
	char* temp = nullptr;

	while (cur != nullptr) {
		index = cur->getNext();

		while (index != nullptr) {
			// 대소문자를 무시하고 비교 후 정렬이 필요하면 스왑
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
	// 헤드 포인터에 접근할 수 있는 함수
	return m_pHead;
}

Node::Node()
{
	// 생성자
	m_pNext = nullptr;
	m_Data = new char[1];
	m_Data[0] = NULL;
}

Node::~Node()
{
	// 소멸자
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
	// 문자열을 비교할 때 대소문자를 무시하고 비교함.
	while (*s1 != '\0' && *s2 != '\0')
	{
		// 소문자로 설정하고 비교함, 다르면 값 반환
		int dif = tolower(*s1) - tolower(*s2);
		if (dif != 0)
			return dif;
		++s1;
		++s2;
	}
	return tolower(*s1) - tolower(*s2);
}