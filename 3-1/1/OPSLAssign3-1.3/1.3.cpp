#include <iostream>
#include <cstring>

class Node {

private:
	Node* m_pNext;	// ���� ��带 ����Ű�� ������
	int m_Data;		// ��忡 ����� ������

public:
	Node();
	~Node() {};

	void SetData(int n);		// ��忡 ������ ����
	void SetNext(Node* pNext);	// ����� ���� ��带 ����(set) 
	int GetData();				// ��忡 ����� �����͸� ������
	Node* GetNext();			// ����� ���� ��带 ������
};

///////////////////////////////////////////////////////////////////////////////

Node::Node()
{
	m_pNext = nullptr;	// �������� Node* �� nullptr�� �ʱ�ȭ
	m_Data = 0;			// �ʱ� ������ = 0;
}

void Node::SetData(int n)
{
	m_Data = n;			// ������ = �Է°� n
}

void Node::SetNext(Node* pNext)
{
	m_pNext = pNext;	// ����� ���� ��带 pNext�� ����
}

int Node::GetData()
{
	return m_Data;		// ��忡 ����� �����͸� ��ȯ
}

Node* Node::GetNext()
{
	return m_pNext;		// ����� ���� ��带 ��ȯ
}

///////////////////////////////////////////////////////////////////////////////

class Queue {

private:
	Node* m_pHead;	// head ���
	Node* m_pTail;	// tail ���
	int m_size;					// ť�� ������
	int m_NumElement;			// ť�� ����Ǿ� �ִ� ���� ����

public:
	Queue();
	~Queue();

	void SetSize(int n);		// ť�� ������ ����
	bool IsEmpty();				// ť�� ����ִ��� Ȯ��
	bool IsFull();				// ť�� ���� ���ִ��� Ȯ��
	bool Push(Node* pNode);		// ť�� ���ο� ��� �����͸� �Է�
	Node* Pop();				// ť�� ��带 ����
	void PrintQueue();			// ť�� ��忡 ����� ������ ���
};

///////////////////////////////////////////////////////////////////////////////

Queue::Queue()
{
	m_pHead = nullptr;	// �������� Node* �� nullptr�� �ʱ�ȭ
	m_pTail = nullptr;	// �������� Node* �� nullptr�� �ʱ�ȭ
	m_size = 0;			// ť ������ = 0
	m_NumElement = 0;	// ť ���� ���� = 0
}

Queue::~Queue()
{
	while (!IsEmpty())	// ������� �� ���� ť�� ��带 ����
	{
		Pop();
	}
}

void Queue::SetSize(int n)
{
	m_size = n;		// ť�� ������ = n
}

bool Queue::IsEmpty()
{
	return m_NumElement == 0;	// ť�� ����Ǿ� �ִ� ���� ������ 0 ���� Ȯ��
}

bool Queue::IsFull()
{
	return m_NumElement == m_size;	// ť�� ����Ǿ� �ִ� ���� ������ ť�� ������� ���� �� Ȯ��
}

bool Queue::Push(Node* pNode)
{
	if (IsFull())
	{
		return false;	// ť�� ���� �� ��� ����ó�� �۵��ϱ� ���� false ��ȯ
	}
	pNode->SetNext(nullptr);	// pNode�� ���� ���� nullptr (ť�� ��)���� ����

	if (IsEmpty())
	{
		m_pHead = pNode;		// ����ִ� ��� Head�� Tail ��� �Է��� ��带 ����Ų��.
		m_pTail = pNode;		// ����ִ� ��� Head�� Tail ��� �Է��� ��带 ����Ų��.
	}
	else
	{
		m_pTail->SetNext(pNode);	// ������ tail ����� ���� ��带 pNode�� ����
		m_pTail = pNode;			// 
	}
	m_NumElement++;		// ť�� ����Ǿ� �ִ� �� ���� (��� ��)����

	return true;
}

Node* Queue::Pop()
{
	if (IsEmpty())
	{
		return nullptr;		// ť�� ����ִ� ��� ����ó�� �۵��ϱ� ���� nullptr ��ȯ
	}
	Node* temp = m_pHead;	// ���� head ��带 temp�� ����

	m_pHead = m_pHead->GetNext();	// head ��尡 head�� ���� ��尡 �ǵ��� �Ѵ�

	m_NumElement--;			// ť�� ����Ǿ� �ִ� �� ���� (��� ��)����

	return temp;
}

void Queue::PrintQueue()
{
	Node* temp = m_pHead;	// head ��尡 ����Ű�� ������ ����ؼ� GetData()�� ����� ���� ����ϰ�
	// GetNext()�� ���� ��带 �ҷ����� ���� ��尡 nullptr (tail ����� ���� ���)�� �� ���� �ݺ�

	while (temp != nullptr)
	{
		std::cout << temp->GetData() << " ";
		temp = temp->GetNext();
	}
	std::cout << std::endl;
}

///////////////////////////////////////////////////////////////////////////////

int main()
{
	Queue q;
	int size;

	do {
		std::cout << "Size of queue: ";	// ť�� ������ ����, 0 ���� ū ���� �Էµ� ������ �ݺ�
		std::cin >> size;
	} while (size <= 0);

	q.SetSize(size);	// ť�� ������ ����

	std::cout << "command : push (value)  pop  print  exit" << std::endl;

	char command[64];
	while (std::cin >> command)
	{
		if (!strcmp(command, "push"))
		{
			int value;
			std::cin >> value;

			Node* newNode = new Node();	// ���ο� ��� �޸� �Ҵ�
			newNode->SetData(value);	// ���ο� ��忡 �� �Ҵ�

			if (!q.Push(newNode))	// ť�� ���� �� ��� false�� ��ȯ�ϹǷ� �� ��� ť�� ���� á�ٴ� �޽��� ǥ��
			{
				std::cout << "Queue is full." << std::endl;
				delete newNode;
			}
		}

		else if (!strcmp(command, "pop"))
		{
			Node* temp = q.Pop();	// temp�� �����ϰ� �� head ��带 �޴´�

			if (temp == nullptr)	// temp�� nullptr ���� Ȯ��(ť�� �������)
			{
				std::cout << "Queue is empty." << std::endl;
			}
			else
			{
				std::cout << temp->GetData() << std::endl;
				delete temp;	// ����ϰ� �ӽ� temp�� ����
			}
		}

		else if (!strcmp(command, "print"))	// ť�� ��� ���
			q.PrintQueue();

		else if (!strcmp(command, "exit"))	// exit �Է� �� break(����)
			break;

		else
			std::cout << "Invalid command" << std::endl;	// �̿��� ��ɾ�� ����
	}
	return 0;
}