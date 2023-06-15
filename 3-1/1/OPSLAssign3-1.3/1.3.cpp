#include <iostream>
#include <cstring>

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

class Queue {

private:
	Node* m_pHead;	// head 노드
	Node* m_pTail;	// tail 노드
	int m_size;					// 큐의 사이즈
	int m_NumElement;			// 큐에 저장되어 있는 값의 개수

public:
	Queue();
	~Queue();

	void SetSize(int n);		// 큐의 사이즈 설정
	bool IsEmpty();				// 큐가 비어있는지 확인
	bool IsFull();				// 큐가 가득 차있는지 확인
	bool Push(Node* pNode);		// 큐에 새로운 노드 포인터를 입력
	Node* Pop();				// 큐의 노드를 제거
	void PrintQueue();			// 큐의 노드에 저장된 정보를 출력
};

///////////////////////////////////////////////////////////////////////////////

Queue::Queue()
{
	m_pHead = nullptr;	// 포인터인 Node* 를 nullptr로 초기화
	m_pTail = nullptr;	// 포인터인 Node* 를 nullptr로 초기화
	m_size = 0;			// 큐 사이즈 = 0
	m_NumElement = 0;	// 큐 값의 개수 = 0
}

Queue::~Queue()
{
	while (!IsEmpty())	// 비어있을 때 까지 큐의 노드를 제거
	{
		Pop();
	}
}

void Queue::SetSize(int n)
{
	m_size = n;		// 큐의 사이즈 = n
}

bool Queue::IsEmpty()
{
	return m_NumElement == 0;	// 큐에 저장되어 있는 값의 개수가 0 인지 확인
}

bool Queue::IsFull()
{
	return m_NumElement == m_size;	// 큐에 저장되어 있는 값의 개수가 큐의 사이즈와 같은 지 확인
}

bool Queue::Push(Node* pNode)
{
	if (IsFull())
	{
		return false;	// 큐가 가득 찬 경우 오류처럼 작동하기 위해 false 반환
	}
	pNode->SetNext(nullptr);	// pNode의 다음 노드는 nullptr (큐의 끝)으로 설정

	if (IsEmpty())
	{
		m_pHead = pNode;		// 비어있는 경우 Head와 Tail 모두 입력한 노드를 가리킨다.
		m_pTail = pNode;		// 비어있는 경우 Head와 Tail 모두 입력한 노드를 가리킨다.
	}
	else
	{
		m_pTail->SetNext(pNode);	// 기존의 tail 노드의 다음 노드를 pNode로 설정
		m_pTail = pNode;			// 
	}
	m_NumElement++;		// 큐에 저장되어 있는 값 개수 (노드 수)증가

	return true;
}

Node* Queue::Pop()
{
	if (IsEmpty())
	{
		return nullptr;		// 큐가 비어있는 경우 오류처럼 작동하기 위해 nullptr 반환
	}
	Node* temp = m_pHead;	// 현재 head 노드를 temp에 저장

	m_pHead = m_pHead->GetNext();	// head 노드가 head의 다음 노드가 되도록 한다

	m_NumElement--;			// 큐에 저장되어 있는 값 개수 (노드 수)감소

	return temp;
}

void Queue::PrintQueue()
{
	Node* temp = m_pHead;	// head 노드가 가리키는 값부터 계속해서 GetData()로 노드의 값을 출력하고
	// GetNext()로 다음 노드를 불러오며 다음 노드가 nullptr (tail 노드의 다음 노드)일 때 까지 반복

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
		std::cout << "Size of queue: ";	// 큐의 사이즈 결정, 0 보다 큰 값이 입력될 때까지 반복
		std::cin >> size;
	} while (size <= 0);

	q.SetSize(size);	// 큐의 사이즈 지정

	std::cout << "command : push (value)  pop  print  exit" << std::endl;

	char command[64];
	while (std::cin >> command)
	{
		if (!strcmp(command, "push"))
		{
			int value;
			std::cin >> value;

			Node* newNode = new Node();	// 새로운 노드 메모리 할당
			newNode->SetData(value);	// 새로운 노드에 값 할당

			if (!q.Push(newNode))	// 큐가 가득 찬 경우 false를 반환하므로 이 경우 큐가 가득 찼다는 메시지 표시
			{
				std::cout << "Queue is full." << std::endl;
				delete newNode;
			}
		}

		else if (!strcmp(command, "pop"))
		{
			Node* temp = q.Pop();	// temp에 삭제하게 될 head 노드를 받는다

			if (temp == nullptr)	// temp가 nullptr 인지 확인(큐가 비어있음)
			{
				std::cout << "Queue is empty." << std::endl;
			}
			else
			{
				std::cout << temp->GetData() << std::endl;
				delete temp;	// 출력하고 임시 temp는 삭제
			}
		}

		else if (!strcmp(command, "print"))	// 큐의 요소 출력
			q.PrintQueue();

		else if (!strcmp(command, "exit"))	// exit 입력 시 break(종료)
			break;

		else
			std::cout << "Invalid command" << std::endl;	// 이외의 명령어는 오류
	}
	return 0;
}