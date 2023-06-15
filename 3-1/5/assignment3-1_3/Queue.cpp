#include "Queue.h"
#include <iostream>

//Node Class member function
Node::Node()
{
	//��� ���� �ʱ�ȭ
	m_pNext = nullptr;
	m_Data = 0;
}

Node::~Node()
{
	m_pNext = nullptr;
	m_Data = 0;
}

void Node::SetData(int n)            //Data ����
{
	m_Data = n;
}

void Node::SetNext(Node* pNext)      //Link ����
{
	m_pNext = pNext;
}

int Node::GetData()                  //Data ��ȯ
{
	return m_Data;
}

Node* Node::GetNext()                //Link ��ȯ
{
	return m_pNext;
}


//Queue Class member function
Queue::Queue()
{
	//��� ���� �ʱ�ȭ
	m_pHead = nullptr;
	m_pTail = nullptr;
	m_Size = 0;
	m_NumElement = 0;
}

Queue::~Queue()
{
	Node* pPre;

	//Queue�� ������� ���� ��� ��� ����� �޸� ����
	while (m_pHead != nullptr) {
		pPre = m_pHead;
		m_pHead = m_pHead->GetNext();

		delete pPre;
	}
}

void Queue::SetSize(int n)            //m_Size ����
{
	m_Size = n;
}

bool Queue::IsEmpty()                 //Queue�� ����ִ� ����(element�� ������ 0�� ����)�̸� true, �׷��� ������ false ��ȯ
{
	if (m_NumElement == 0) {
		return true;      //��� �ִ� ���
	}
	else {
		return false;     //��� ���� ���� ���
	}
}

bool Queue::IsFull()                  //Queue�� ���� �� ����(element�� ������ Queue�� ũ��� ���� ����)�̸� ture, �׷��� ������ false ��ȯ
{
	if (m_NumElement == m_Size) {
		return true;      //���� �� ������ ���
	}
	else {
		return false;     //���� ���� ���� ������ ���
	}
}

bool Queue::Push(Node* pNode)         //element �߰�
{
	//Queue�� ���� �� ��� false ��ȯ
	if (m_Size == m_NumElement) {
		return false;
	}

	pNode->SetNext(nullptr);     //Link�� nullptr ����

	//���ο� ��� �߰� ����
	if (m_pHead == nullptr) {    //ù ��° ����� ���
		m_pHead = pNode;
		m_pTail = pNode;
	}
	else {
		m_pTail->SetNext(pNode);
		m_pTail = pNode;
	}

	m_NumElement++;

	return true;
}

Node* Queue::Pop()                    //element ���� (���� ���� ��� �� element���� ����)
{
	if (m_NumElement > 0) {
		Node* pPre = m_pHead;

		if (m_NumElement == 1) {    //��尡 1���� ���
			m_pHead = nullptr;
			m_pTail = nullptr;
		}
		else {
			m_pHead = m_pHead->GetNext();     //Head�� ���� ���� ����
		}

		m_NumElement--;

		return pPre;                      //Queue���� ������ ��� ��ȯ
	}
	else {                          //Queue�� ��尡 ���� ���
		return nullptr;
	}
}

void Queue::PrintQueue()              //Queue�� element�� ��� ���(���� ���� ���� element���� ���)
{
	Node* pCur = m_pHead;

	//Queue�� ������ ������ ������ �� ����� data ���
	while (pCur != nullptr) {
		std::cout << pCur->GetData() << std::endl;
		pCur = pCur->GetNext();  //���� ���� �̵�
	}
}