#include "Queue.h"	// ť ������� ����
using namespace std;

Node::Node() // ������ 
{
	m_pNext = nullptr; // ��带 nullptr�� �ʱ�ȭ
	m_Data = 0; // ���� ���� 0���� �ʱ�ȭ
}

Node::~Node() // �Ҹ���
{
	
}

void Node::SetData(int n) // ������ ����
{
	m_Data = n; // �Է��� n�� ���ҷ�
}

void Node::SetNext(Node* pNext) // ���� ���
{
	m_pNext = pNext; // ���� ���� ����
}

int Node::GetData() // ������ ��ȯ
{
	return m_Data; 
}
 
Node* Node::GetNext() // ��� ��ȯ
{
	return m_pNext;
}

Queue::Queue() // ť ������
{
	m_pHead = nullptr; // �� ó�� ��
	m_pTail = nullptr; // �� �� ���� �� �� nullptr�� �ʱ�ȭ
	m_Size = 0; // ť�� ũ��
	m_NumElement = 0; // ť�� ������ ����
}

Queue::~Queue() // �Ҹ���
{
	Node* pNode = m_pHead; // ó�� �� ����
	Node* pNext = nullptr; // ���� ��带 �ι��ڷ� �ʱ�ȭ

	while (pNode != nullptr) // �� ���� ����������
	{
		pNext = pNode->GetNext(); 
		delete pNode;  // ���������� �Ҵ�����
		pNode = pNext;
	}
}

void Queue::SetSize(int n) // ť ũ�� ����
{
	m_Size = n; // n�� ũ��� ť ũ�� ����
}

bool Queue::IsEmpty() // ť�� ����ִ��� üũ
{
	if (m_NumElement == 0) // ť�� ������  ������ 0�̸� 
		return true; // �� ť�̹Ƿ� true ��ȯ
	else // �׷��� ������
		return false; // false ��ȯ
}

bool Queue::IsFull() // ť�� �� ���ִ��� üũ
{
	if (m_NumElement == m_Size) // �Է��� ť�� ũ��� ť�� ������ ������ ���ٸ�
		return true; // true ��ȯ
	else // �׷��� ������
		return false; // false ��ȯ
}

bool Queue::Push(Node* pNode) // ť�� ������ �Է�
{
	if (IsFull()) // �� �������� �����͸� ���� ���ϹǷ�
	{
		cout << "Full" << endl; // ���� ���
		return false; // false ��ȯ
	}
	if (m_pHead == nullptr) // �� ó�� ���� nullptr �̸� �� ť �� �����̹Ƿ�
	{
		m_pHead = pNode; // �Է��� ��带 �� ó������ 
		m_pTail = pNode; // �� �������� �ٲ�
	}
	else // ó�� ���� nullptr�� �ƴϸ�
	{
		m_pTail->SetNext(pNode); // �� �� ���� ��� ���� ����� ������ �����ؾ���
		m_pTail = pNode; // ���� ��
	}

	m_NumElement++; // ť�� ���� ����

	return true; 
}

Node* Queue::Pop() // ť�� ������ �ϳ��� ����
{
	if (IsEmpty()) // ť�� ����ִٸ� �����͸� �� �� �����Ƿ�
	{
		cout << "Empty" << endl; // Empty ���
		return nullptr; // nullptr ��ȯ
	}

	Node* pNode = m_pHead; // �� ó�� ���� ���� �����Ƿ� pop���� �� ó�������� ����
	m_pHead = m_pHead->GetNext(); // �� ó�� ���� ���������� ���� ���� pHead�� ����
	m_NumElement--; // ť�� ������ ���� ����

	return pNode; // �������� ť�� ������ ��ȯ
}

void Queue::PrintQueue() // ť ���
{
	if (IsEmpty()) // ť�� ����ִٸ� 
	{
		cout << "Empty" << endl; // Empty ���
		return;
	}

	Node* pNode = m_pHead; // pHead ���� ����ؾ��ϹǷ� 

	while (pNode != nullptr) // nullptr�� ���� ������ 
	{
		cout << pNode->GetData() << " "; // ���� ������ ��� 
		pNode = pNode->GetNext(); // ���� ���� ���� ������Ʈ
	}
	cout << endl; // ����
}