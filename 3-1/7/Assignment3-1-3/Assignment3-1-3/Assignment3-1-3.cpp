#include <iostream>
using namespace std;

class Node
{
private:
	Node* m_pNext; // ���� ��带 ����Ű�� ������
	int m_Data; // ��忡 ����� ������ ��
public:
	Node() // ������ - �ʱ�ȭ ��
	{
		m_pNext = NULL; // ���� ��带 ����Ű�� ������
		m_Data = 0; // ������ 0���� �ʱ�ȭ
	}
	~Node() {} // �Ҹ���
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

class Queue
{
private:
	Node* m_pHead; // Queue�� head
	Node* m_pTail; // Queue�� tail
	int m_Size; // Queue�� ũ��
	int m_NumElment; // Queue�� ���� element�� ��
public:
	Queue() // ������ - �ʱ�ȭ ��
	{
		m_pHead = NULL; // head �����͸� NULL�� �ʱ�ȭ
		m_pTail = NULL; // tail �����͸� NULL�� �ʱ�ȭ
		m_Size = 0;  // Queue�� ũ�⸦ 0���� �ʱ�ȭ
		m_NumElment = 0; // Queue�� ���� element�� ���� 0���� �ʱ�ȭ
	}
	~Queue(){} // �Ҹ���

	void SetSize(int n)
	{
		m_NumElment = n; // Queue�� ���� element�� �� ����
	}
	bool IsEmpty()
	{
		return (m_Size == 0); // Queue�� ����ִ��� ���θ� ��ȯ
	}
	bool IsFull()
	{
		return (m_Size == m_NumElment); // Queue�� ���� á���� ���θ� ��ȯ
	}
	bool Push(Node* pNode)
	{
		if (IsFull()) // Queue�� ���� á�� ��
		{
			cout << "Queue is full." << endl;
			return false;
		}
		if (IsEmpty()) // Queue�� ������� ��
		{
			m_pHead = pNode; // head�� ���� �߰��� ���� ����
			m_pTail = pNode; // tail�� ���� �߰��� ���� ����
		}
		else // Queue�� ������� ���� ��
		{
			m_pTail->SetNext(pNode); // ���� tail ����� ���� ��带 ���� �߰��� ���� ����
			m_pTail = pNode; // tail�� ���� �߰��� ���� ����
		}
		m_Size++; // ũ�� ����
		return true;
	}
	Node* Pop()
	{
		if (IsEmpty()) // Qeueu�� ��� ���� ��
		{
			cout << "Queue is empty." << endl;
			return NULL;
		}
		Node* pNode = m_pHead; // head node�� ����
		m_pHead = m_pHead->GetNext(); // head ������ �̵�
		m_Size--;
		return pNode;
	}
	void PrintQueue()
	{
		if (IsEmpty()) // Queue�� ��� ���� ��
		{
			cout << "Queue is empty." << endl;
			return;
		}
		Node* pNode = m_pHead; // head node�� ����
		while (pNode != NULL) // ��� node ��ȸ
		{
			cout << pNode->GetData() << " "; // �� ���
			pNode = pNode->GetNext();
		}
		cout << endl;
	}
};

int main() 
{
	Queue queue; // ��ü ����

	//Queue ũ�� �Է� ����
	int size;
	cout << "Enter the size of queue: ";
	cin >> size;
	queue.SetSize(size); //queue ũ�� ����

	cout << "Push" << endl;
	for (int i = 0; i < size; i++) // queue�� size ��ŭ
	{
		int data;
		cout << "Enter a value to push: "; // ���� �� �Է� �ޱ�
		cin >> data;
		Node* pNode = new Node(); // ���ο� Node ��ü �����Ҵ�
		pNode->SetData(data); // Node�� ������ ����
		queue.Push(pNode); // Queue�� Node �߰�
	}

	cout << "Print" << endl;
	queue.PrintQueue(); // Queue�� ��� ��� ���

	cout << "Pop" << endl;
	while (!queue.IsEmpty())  // Queue�� ������� ���� ����
	{
		Node* pNode = queue.Pop(); // Queue�� head ��带 �����ϰ� �� ����� �ּ� ��ȯ
		cout << "Pop element: " << pNode->GetData() << endl; // ������ ����� ������ ���
		delete pNode; // ��� ����
	}
	return 0;
}