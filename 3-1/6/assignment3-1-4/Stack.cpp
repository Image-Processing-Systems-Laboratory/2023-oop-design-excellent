#include "Stack.h"
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
	Stack
*/

Stack::Stack()
{
	// ���� ��ü�� ���������� ó�� ������� ����� ������ 0
	m_Size = 0;
	m_NumElement = 0;

	m_pHead = nullptr;
	first = nullptr;
}

Stack::~Stack()
{

}

void Stack::SetSize(int n)
{
	this->m_Size = n; // ������ �ִ� ������ ����
}

bool Stack::IsEmpty()
{
	if (m_NumElement == 0) { //���� ����� ������ 0���̸� ������� -> true ���
		return true;
	}
	else {
		return false;
	}
}

bool Stack::IsFull()
{
	if (m_NumElement == m_Size) { //���� ����� ������ ������ �ִ� ������� ������ �� ������ -> true ���
		return true;
	}
	else {
		return false;
	}
}

bool Stack::Push(Node* pNode)
{
	if (pNode == nullptr) //����ó��
		return false;
	if (IsEmpty() == true) { // ���� ����� ������ 0�� ��
		m_pHead = pNode;
		first = pNode;
	}
	else { // ���� ����� ������ 0�� �ƴ� ��
		m_pHead->SetNext(pNode);
		m_pHead = pNode;
	}
	m_NumElement++; //��� ���� �߰�
	return true;

}

void Stack::PrintStack()
{
	Node* pCur = first; //��� �ϳ��� ����Ű�� ����

	while (pCur)
	{
		std::cout << pCur->GetData() << " ";
		pCur = pCur->GetNext();
	}
	std::cout << std::endl;
}

Node* Stack::Pop()
{
	Node* delNode = new Node; //������ ��� �Űܳ��� ����
	Node* pCur = first; // ��� �ϳ��� ����Ű�� ����

	// ������ ��带 �����ص�
	delNode->SetData(m_pHead->GetData());
	delNode->SetNext(nullptr);

	// pCur�� ������ ����� �� ��带 ����Ű���� ��
	while (pCur->GetNext() != m_pHead)
	{
		if (m_NumElement == 1) { // ���� �� ����� ������ 1�̸� pCur�� nullptr�� ����Ŵ
			pCur = nullptr;
			break;
		}
		pCur = pCur->GetNext(); // ���� ��� ����Ű�� ��
	}

	delete m_pHead; //��� ����
	m_pHead = pCur; //pHead�� ������ ��� �� ��带 ����Ű�� ��
	if (m_NumElement != 1) { // ���� �� ����� ������ 1�� �ƴϸ� pHead�� ����Ű�� ����� ��ũ���� nullptr�� ����
		m_pHead->SetNext(nullptr);
	}
	else { //���� �� ����� ������ 1�̸� ���� �Ŀ� ��尡 �����Ƿ� first�� ���� nullptr
		first = nullptr;
	}
	m_NumElement--; //��� ���� ����
	return delNode; //������ ��� ��ȯ
}