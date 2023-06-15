#include <iostream>
using namespace std;

class Node
{
private:
	Node* m_pNext; // ���� ��带 ����Ű�� ������
	int m_Data;  // ��忡 ����� ������ ��
public: 
	Node() // ������ - �ʱ�ȭ ��
	{
		m_pNext = NULL; // ���� ��带 ����Ű�� ������
		m_Data = 0; // ������ 0���� �ʱ�ȭ
	}
	~Node(){} // �Ҹ���
	void SetData(int n)
	{
		m_Data = n; // ��忡 ������ ����
	}
	void SetNext(Node* pNext)
	{
		m_pNext = pNext; // ���� ��带 ����Ű�� ������ ����
	}
	int GetData()
	{
		return m_Data; // ����� ������ ��ȯ
	}
	Node* GetNext()
	{
		return m_pNext; // ���� ��带 ����Ű�� ������ ��ȯ
	}
};

class Stack
{
private:
	Node* m_pHead; // stack�� head
	int m_Size;  // stack�� ũ��
	int m_NumElement; // stack�� ���� element�� ��
public:
	Stack() // ������ - �ʱ�ȭ ��
	{
		m_pHead = NULL;  // head �����͸� NULL�� �ʱ�ȭ
		m_Size = 0; // stack�� ũ�⸦ 0���� �ʱ�ȭ
		m_NumElement = 0; // stack�� ���� element�� ���� 0���� �ʱ�ȭ
	}
	~Stack() {} // �Ҹ���

	void SetSize(int n)
	{
		m_Size = n; // stack�� ���� element�� �� ����
	}
	bool IsEmpty() 
	{
		return m_NumElement == 0; // stack�� ����ִ��� ���θ� ��ȯ
	}
	bool IsFull()
	{
		return m_NumElement == m_Size; // stack�� ���� á���� ���θ� ��ȯ
	}
	bool Push(Node* pNode)
	{
		if (IsFull()) // stack�� ���� á�� ��
		{
			cout << "Stack is full." << endl;
			return false;
		}
		pNode->SetNext(m_pHead); // Node�� ���� Node�� ������ top���� ����
		m_pHead = pNode; // top�� �߰��� Node�� ����
		++m_NumElement; // ���� ����
		return true;
	}
	Node* Pop()
	{
		if (IsEmpty()) // stack�� ����� ��
		{
			cout << "Stack is empty." << endl;
			return NULL;
		}

		Node* pPop = m_pHead; // ������ Node�� ����
		m_pHead = m_pHead->GetNext(); // top�� ���� Node�� ����
		--m_NumElement; // ����� ���� ����
		return pPop; // ������ Node ��ȯ
	}
	void PrintStack()
	{
		Node* pNode = m_pHead;

		while (pNode) // ��� Node ��ȸ
		{
			cout << pNode->GetData() << " "; // Node�� ������ ���
			pNode = pNode->GetNext(); // ���� Node�� �̵�
		}

		cout << std::endl;
	}
};

int main() 
{
	Stack stack; // ��ü ����

	// stack ũ�� �Է� ����
	int size;
	cout << "Enter the size of stack: ";
	cin >> size;
	stack.SetSize(size); // stack ũ�� ����

	cout << "Push" << endl;
	for (int i = 0; i < size; ++i) // stack�� size ��ŭ
	{
		Node* pNode = new Node(); // ���ο� Node ��ü �����Ҵ�
		int data;
		cout << "Enter a value to push: ";
		cin >> data;
		pNode->SetData(data); // Node�� ������ ����
		stack.Push(pNode); // stack�� Node �߰�
	}
	
	cout << "Print" << endl;
	stack.PrintStack();  // stack�� ��� ��� ���

	cout << "Pop" << endl;
	while (!stack.IsEmpty())  // stack�� ������� ���� ����
	{
		Node* pNode = stack.Pop(); // stack�� head ��带 �����ϰ� �� ����� �ּ� ��ȯ
		cout << "Pop element: " << pNode->GetData() << endl; // ������ ����� ������ ���
		delete pNode; // ��� ����
	}
	return 0;
}