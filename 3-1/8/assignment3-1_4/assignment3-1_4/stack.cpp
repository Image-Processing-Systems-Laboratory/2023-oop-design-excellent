#include "Stack.h"	// ť ������� ����
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

Stack::Stack() // ���� ������
{
	m_pHead = nullptr; // �� ó�� ��
	m_Size = 0; // ť�� ũ��
	m_NumElement = 0; // ������ ������ ����
}

Stack::~Stack() // �Ҹ���
{
	Node* pNode = m_pHead; // �� �� ��
	Node* nextNode = nullptr; // ���� ��带 �ι��ڷ� �ʱ�ȭ

	while (pNode != nullptr) // �� �Ʒ� ���� ��������
	{
		nextNode = pNode->GetNext();
		delete pNode; // ���������� �Ҵ�����
		pNode = nextNode;
	}
}

void Stack::SetSize(int n) // ���� ũ�� ����
{
	m_Size = n; // n�� ũ��� ���� ũ�� ����
}

bool Stack::IsEmpty() // ������ ����ִ��� üũ
{
	if (m_NumElement == 0) // ������ ������  ������ 0�̸� 
		return true; // �� �����̹Ƿ� true ��ȯ
	else // �׷��� ������
		return false; // false ��ȯ
}

bool Stack::IsFull() // ������ �� ���ִ��� üũ
{
	if (m_NumElement == m_Size) // �Է��� ������ ũ��� ������ ������ ������ ���ٸ�
		return true; // true ��ȯ
	else // �׷��� ������
		return false; // false ��ȯ
}

bool Stack::Push(Node* pNode) // ������ ������ �Է�
{
	if (IsFull()) // �� �������� �����͸� ���� ���ϹǷ�
	{
		cout << "Full" << endl; // ���� ���
		return false; // false ��ȯ
	}

	pNode->SetNext(m_pHead); // �Է��� ����� �������� phead�� ����Ű�� ���
	m_pHead = pNode; // phead�� �Է��� ���
	m_NumElement++; // ���� ����

	return true;
}

Node* Stack::Pop() // ������ ������ �ϳ��� ����
{
	if (IsEmpty()) // ������ ����ִٸ� �����͸� �� �� �����Ƿ�
	{
		cout << "Empty" << endl; // Empty ���
		return nullptr; // nullptr ��ȯ
	}

	Node* pNode = m_pHead; // pNode�� pHead�� �� ó�� ������ 
	m_pHead = m_pHead->GetNext(); // �� ó�� ���� ���������� �� ���� ������ pHead ����
	m_NumElement--; // ������ ������ ���� ����

	return pNode; // phead ��ȯ
}

void Stack::PrintStack() // ���� ���
{
	if (IsEmpty()) // ���� ����ִٸ� 
	{
		cout << "Empty" << endl; // Empty ���
		return;
	}

	Node* pNode = m_pHead; // �� ������ ����ؾ��ϹǷ� 

	while (pNode != nullptr) // nullptr�� ���� ������ 
	{
		cout << pNode->GetData() << " "; // ���� ������ ��� 
		pNode = pNode->GetNext(); // ���� ���� ���� ������Ʈ
	}
	cout << endl; // ����
}

