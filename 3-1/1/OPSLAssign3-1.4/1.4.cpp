#include <iostream>

class Node {

private:
    Node* m_pNext;	// 다음 노드를 가리키는 포인터
    int m_Data;		// 노드에 저장된 데이터

public:
    Node();
    ~Node() {};

    void SetData(int n);		// 노드에 데이터 저장
    void SetNext(Node* pNext);	// 노드의 다음 노드를 수정(set) 
    int GetData();				// 노드에 저장된 데이터를 가져옴
    Node* GetNext();			// 노드의 다음 노드를 가져옴
};

///////////////////////////////////////////////////////////////////////////////

Node::Node()
{
    m_pNext = nullptr;	// 포인터인 Node* 를 nullptr로 초기화
    m_Data = 0;			// 초기 데이터 = 0;
}

void Node::SetData(int n)
{
    m_Data = n;			// 데이터 = 입력값 n
}

void Node::SetNext(Node* pNext)
{
    m_pNext = pNext;	// 노드의 다음 노드를 pNext로 수정
}

int Node::GetData()
{
    return m_Data;		// 노드에 저장된 데이터를 반환
}

Node* Node::GetNext()
{
    return m_pNext;		// 노드의 다음 노드를 반환
}

///////////////////////////////////////////////////////////////////////////////

class Stack {

private:
	Node* m_pHead;	// head 노드
	int m_size;					// 스택의 사이즈
	int m_NumElement;			// 스택에 저장되어 있는 값의 개수

public:
	Stack();
	~Stack();

	void SetSize(int n);		// 스택의 사이즈 설정
	bool IsEmpty();				// 스택이 비어있는지 확인
	bool IsFull();				// 스택이 가득 차있는지 확인
	bool Push(Node* pNode);		// 스택에 새로운 노드 포인터를 입력
	Node* Pop();				// 스택의 노드를 제거
	void PrintStack();			// 스택의 노드에 저장된 정보를 출력
};

///////////////////////////////////////////////////////////////////////////////

Stack::Stack()
{
    m_pHead = nullptr;	// 포인터인 Node* 를 nullptr로 초기화
    m_size = 0;			// 스택 사이즈 = 0
    m_NumElement = 0;	// 스택 값의 개수 = 0
}

Stack::~Stack()
{
    while (!IsEmpty())	// 비어있을 때까지 스택의 노드를 제거
    {
        Pop();
    }
}

void Stack::SetSize(int n)
{
    m_size = n;			// 스택의 사이즈 = n
}

bool Stack::IsEmpty()
{
    return m_NumElement == 0;	// 스택에 저장되어 있는 값의 개수가 0 인지 확인
}

bool Stack::IsFull()
{
    return m_NumElement == m_size;	// 스택에 저장되어 있는 값의 개수가 스택의 사이즈와 같은 지 확인
}

bool Stack::Push(Node* pNode)
{
    if (IsFull())
    {
        return false;	// 스택이 가득 찬 경우 오류처럼 작동하기 위해 false 반환
    }

    pNode->SetNext(m_pHead);
    m_pHead = pNode;

    m_NumElement++;		// 스택에 저장되어 있는 값 개수 (노드 수)증가

    return true;
}

Node* Stack::Pop()
{
    if (IsEmpty())
    {
        return nullptr;		// 스택이 비어있는 경우 오류처럼 작동하기 위해 nullptr 반환
    }
    Node* temp = m_pHead;

    m_pHead = m_pHead->GetNext();	// head 노드가 head의 다음 노드가 되도록 한다

    m_NumElement--;			// 스택에 저장되어 있는 값 개수 (노드 수)감소

    return temp;
}

void Stack::PrintStack()
{
    Node* temp = m_pHead;	// head 노드가 가리키는 값부터 계속해서 GetData()로 노드의 값을 출력하고
	// GetNext()로 다음 노드를 불러오며 다음 노드가 nullptr일 때 까지 반복
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
        std::cout << "Size of stack: ";	// 스택의 사이즈 결정, 0 보다 큰 값이 입력될 때까지 반복
        std::cin >> size;
    } while (size <= 0);

    s.SetSize(size);	// 스택의 사이즈 지정

    char command[64];

    std::cout << "command : push (value)  pop  print  exit" << std::endl;

    while (std::cin >> command)
    {
        if (!strcmp(command, "push"))
        {
            int value;
            std::cin >> value;

            Node* newNode = new Node();	// 새로운 노드 메모리 할당
            newNode->SetData(value);	// 새로운 노드에 값 할당

            if (!s.Push(newNode))	// 스택이 가득 찬 경우 false를 반환하므로 이 경우 큐가 가득 찼다는 메시지 표시
            {
                std::cout << "Stack is full." << std::endl;
                delete newNode;
            }
        }

        else if (!strcmp(command, "pop"))
        {
            Node* temp = s.Pop();	// temp에 삭제하게 될 head 노드를 받는다

			if (temp == nullptr)	// temp가 nullptr 인지 확인(큐가 비어있음)
			{
				std::cout << "Stack is empty." << std::endl;
			}
			else
			{
				std::cout << temp->GetData() << std::endl;
				delete temp;	// 출력하고 임시 temp는 삭제
			}
        }

        else if (!strcmp(command, "print"))	// 스택의 요소 출력
            s.PrintStack();

        else if (!strcmp(command, "exit"))	// exit 입력 시 break(종료)
            break;

        else
            std::cout << "Invalid command" << std::endl;	// 이외의 명령어는 오류
    }
    return 0;
}