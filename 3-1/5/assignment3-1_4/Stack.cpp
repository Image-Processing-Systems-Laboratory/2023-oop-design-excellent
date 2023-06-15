#include "Stack.h"
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


//Stack Class member function
Stack::Stack()
{
	//��� ���� �ʱ�ȭ
	m_pHead = nullptr;
	m_Size = 0;
	m_NumElement = 0;
}

Stack::~Stack()
{
	Node* pPre;

	//Stack�� ������� ���� ��� ��� ����� �޸� ����
	while (m_pHead != nullptr) {
		pPre = m_pHead;
		m_pHead = m_pHead->GetNext();

		delete pPre;
	}
}

void Stack::SetSize(int n)            //m_Size ����
{
	m_Size = n;
}

bool Stack::IsEmpty()                 //Stack�� ����ִ� ����(element�� ������ 0�� ����)�̸� true, �׷��� ������ false ��ȯ
{
	if (m_NumElement == 0) {
		return true;      //��� �ִ� ���
	}
	else {
		return false;     //��� ���� ���� ���
	}
}

bool Stack::IsFull()                  //Stack�� ���� �� ����(element�� ������ Stack�� ũ��� ���� ����)�̸� ture, �׷��� ������ false ��ȯ
{
	if (m_NumElement == m_Size) {
		return true;      //���� �� ������ ���
	}
	else {
		return false;     //���� ���� ���� ������ ���
	}
}

bool Stack::Push(Node* pNode)         //element �߰�
{
	//Stack�� ���� �� ��� false ��ȯ
	if (m_Size == m_NumElement) {
		return false;
	}

	//���ο� ��� �߰� ����
	if (m_pHead == nullptr) {    //ù ��° ����� ���
		m_pHead = pNode;
		pNode->SetNext(nullptr);
	}
	else {
		pNode->SetNext(m_pHead);
		m_pHead = pNode;
	}

	m_NumElement++;

	return true;
}

Node* Stack::Pop()                    //element ���� (���� ���߿� ��� �� element���� ����)
{
	if (m_NumElement > 0) {
		Node* pPre = m_pHead;

		if (m_NumElement == 1) {    //��尡 1���� ���
			m_pHead = nullptr;
		}
		else {
			m_pHead = m_pHead->GetNext();     //Head�� ���� ���� ����
		}

		m_NumElement--;

		return pPre;                      //Stack���� ������ ��� ��ȯ
	}
	else {                          //Stack�� ��尡 ���� ���
		return nullptr;
	}
}

void Stack::PrintStack()              //Stack�� element�� ��� ���(���� ���߿� ���� element���� ���)
{
	Node* pCur = m_pHead;

	//Stack�� ������ ������ ������ �� ����� data ���
	while (pCur != nullptr) {
		std::cout << pCur->GetData() << std::endl;
		pCur = pCur->GetNext();  //���� ���� �̵�
	}
}