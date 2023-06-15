#include "Queue.h"
#include <iostream>
/*
	Node
*/

Node::Node()
{

}

Node::~Node()
{

}

void Node::SetData(int n)
{
	this->m_Data = n;  //����� ��������� key�� ����
}

void Node::SetNext(Node* pNext)
{
	this->m_pNext = pNext; //����� ��������� ��ũ�� ����
}

int Node::GetData()
{
	return m_Data; //����� key�� ��ȯ
}

Node* Node::GetNext()
{
	return m_pNext; //����� ��ũ�� ��ȯ
}

/*
	Queue
*/

Queue::Queue()
{
	// ť ��ü�� ���������� ó�� ������� ����� ������ 0
	m_Size = 0;
	m_NumElement = 0;
}

Queue::~Queue()
{

}

void Queue::SetSize(int n)
{
	this->m_Size = n; // ť�� �ִ� ������ ����
}

bool Queue::IsEmpty()
{
	if (m_NumElement == 0) { //���� ����� ������ 0���̸� ������� -> true ���
		return true;
	}
	else {
		return false;
	}
}

bool Queue::IsFull()
{
	if (m_NumElement == m_Size) { //���� ����� ������ ť�� �ִ� ������� ������ �� ������ -> true ���
		return true;
	}
	else {
		return false;
	}
}

bool Queue::Push(Node* pNode)
{
	if (pNode == nullptr) //����ó��
		return false;
	if (IsEmpty() == true) { // ���� ����� ������ 0�� ��
		// pHead�� pTail�� ����Ű�� ���� ����
		m_pHead = pNode;
		m_pTail = pNode;
	}
	else { // ���� ����� ������ 0�� �ƴ� ��
		// ������ pTail�� ����Ű�� ����� ��ũ���� �� ��带 ����Ű���� �����ϰ� pTail�� �� ��带 ��Ű������ ����
		m_pTail->SetNext(pNode);
		m_pTail = pNode;
	}
	m_NumElement++; //��� ���� �߰�
	return true;

}

void Queue::PrintQueue()
{
	Node* pCur = m_pHead; // ��带 �ϳ��� ����Ű�� ���� 
	while (pCur)
	{
		//����� key�� ��� �� ���� ���� �ű�
		std::cout << pCur->GetData() << " ";
		pCur = pCur->GetNext();
	}
	std::cout << std::endl;
}

Node* Queue::Pop()
{
	Node* delNode = new Node; //������ ��� �Űܳ��� ����
	delNode->SetData(m_pHead->GetData()); // ������ ����� key�� ����
	delNode->SetNext(m_pHead->GetNext()); // ������ ����� ��ũ�� ����

	Node* temp = m_pHead->GetNext(); // ������ ��� ���� ��� ����Ű�� ����
	delete m_pHead; // ó�� ��� ����
	m_pHead = temp; //pHead�� ������ ����� ���� ��� ����Ű�� ��
	m_NumElement--; //��� ���� ����
	return delNode; //������ ��� ��ȯ
}