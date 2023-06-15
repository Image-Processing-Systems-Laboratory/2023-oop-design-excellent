#include <iostream>

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

class Stack {

private:
	Node* m_pHead;	// head ���
	int m_size;					// ������ ������
	int m_NumElement;			// ���ÿ� ����Ǿ� �ִ� ���� ����

public:
	Stack();
	~Stack();

	void SetSize(int n);		// ������ ������ ����
	bool IsEmpty();				// ������ ����ִ��� Ȯ��
	bool IsFull();				// ������ ���� ���ִ��� Ȯ��
	bool Push(Node* pNode);		// ���ÿ� ���ο� ��� �����͸� �Է�
	Node* Pop();				// ������ ��带 ����
	void PrintStack();			// ������ ��忡 ����� ������ ���
};

///////////////////////////////////////////////////////////////////////////////

Stack::Stack()
{
    m_pHead = nullptr;	// �������� Node* �� nullptr�� �ʱ�ȭ
    m_size = 0;			// ���� ������ = 0
    m_NumElement = 0;	// ���� ���� ���� = 0
}

Stack::~Stack()
{
    while (!IsEmpty())	// ������� ������ ������ ��带 ����
    {
        Pop();
    }
}

void Stack::SetSize(int n)
{
    m_size = n;			// ������ ������ = n
}

bool Stack::IsEmpty()
{
    return m_NumElement == 0;	// ���ÿ� ����Ǿ� �ִ� ���� ������ 0 ���� Ȯ��
}

bool Stack::IsFull()
{
    return m_NumElement == m_size;	// ���ÿ� ����Ǿ� �ִ� ���� ������ ������ ������� ���� �� Ȯ��
}

bool Stack::Push(Node* pNode)
{
    if (IsFull())
    {
        return false;	// ������ ���� �� ��� ����ó�� �۵��ϱ� ���� false ��ȯ
    }

    pNode->SetNext(m_pHead);
    m_pHead = pNode;

    m_NumElement++;		// ���ÿ� ����Ǿ� �ִ� �� ���� (��� ��)����

    return true;
}

Node* Stack::Pop()
{
    if (IsEmpty())
    {
        return nullptr;		// ������ ����ִ� ��� ����ó�� �۵��ϱ� ���� nullptr ��ȯ
    }
    Node* temp = m_pHead;

    m_pHead = m_pHead->GetNext();	// head ��尡 head�� ���� ��尡 �ǵ��� �Ѵ�

    m_NumElement--;			// ���ÿ� ����Ǿ� �ִ� �� ���� (��� ��)����

    return temp;
}

void Stack::PrintStack()
{
    Node* temp = m_pHead;	// head ��尡 ����Ű�� ������ ����ؼ� GetData()�� ����� ���� ����ϰ�
	// GetNext()�� ���� ��带 �ҷ����� ���� ��尡 nullptr�� �� ���� �ݺ�
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
    Stack s;
    int size;

    do
    {
        std::cout << "Size of stack: ";	// ������ ������ ����, 0 ���� ū ���� �Էµ� ������ �ݺ�
        std::cin >> size;
    } while (size <= 0);

    s.SetSize(size);	// ������ ������ ����

    char command[64];

    std::cout << "command : push (value)  pop  print  exit" << std::endl;

    while (std::cin >> command)
    {
        if (!strcmp(command, "push"))
        {
            int value;
            std::cin >> value;

            Node* newNode = new Node();	// ���ο� ��� �޸� �Ҵ�
            newNode->SetData(value);	// ���ο� ��忡 �� �Ҵ�

            if (!s.Push(newNode))	// ������ ���� �� ��� false�� ��ȯ�ϹǷ� �� ��� ť�� ���� á�ٴ� �޽��� ǥ��
            {
                std::cout << "Stack is full." << std::endl;
                delete newNode;
            }
        }

        else if (!strcmp(command, "pop"))
        {
            Node* temp = s.Pop();	// temp�� �����ϰ� �� head ��带 �޴´�

			if (temp == nullptr)	// temp�� nullptr ���� Ȯ��(ť�� �������)
			{
				std::cout << "Stack is empty." << std::endl;
			}
			else
			{
				std::cout << temp->GetData() << std::endl;
				delete temp;	// ����ϰ� �ӽ� temp�� ����
			}
        }

        else if (!strcmp(command, "print"))	// ������ ��� ���
            s.PrintStack();

        else if (!strcmp(command, "exit"))	// exit �Է� �� break(����)
            break;

        else
            std::cout << "Invalid command" << std::endl;	// �̿��� ��ɾ�� ����
    }
    return 0;
}