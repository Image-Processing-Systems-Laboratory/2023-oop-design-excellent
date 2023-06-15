#include <iostream>
using namespace std;

class Node
{
private:
	Node* m_pNext; // 다음 노드를 가리키는 포인터
	int m_Data; // 노드에 저장된 데이터 값
public:
	Node() // 생성자 - 초기화 함
	{
		m_pNext = NULL; // 다음 노드를 가리키는 포인터
		m_Data = 0; // 데이터 0으로 초기화
	}
	~Node() {} // 소멸자
	void SetData(int n)
	{
		m_Data = n; // 노드에 데이터 저장
	}
	void SetNext(Node* pNext)
	{
		m_pNext = pNext; // 다음 노드를 가리키는 포인터 설정
	}
	int GetData()
	{
		return m_Data; // 노드의 데이터 반환
	}
	Node* GetNext()
	{
		return m_pNext; // 다음 노드를 가리키는 포인터 반환
	}
};

class Queue
{
private:
	Node* m_pHead; // Queue의 head
	Node* m_pTail; // Queue의 tail
	int m_Size; // Queue의 크기
	int m_NumElment; // Queue에 넣을 element의 수
public:
	Queue() // 생성자 - 초기화 함
	{
		m_pHead = NULL; // head 포인터를 NULL로 초기화
		m_pTail = NULL; // tail 포인터를 NULL로 초기화
		m_Size = 0;  // Queue의 크기를 0으로 초기화
		m_NumElment = 0; // Queue에 넣을 element의 수를 0으로 초기화
	}
	~Queue(){} // 소멸자

	void SetSize(int n)
	{
		m_NumElment = n; // Queue에 넣을 element의 수 설정
	}
	bool IsEmpty()
	{
		return (m_Size == 0); // Queue가 비어있는지 여부를 반환
	}
	bool IsFull()
	{
		return (m_Size == m_NumElment); // Queue가 가득 찼는지 여부를 반환
	}
	bool Push(Node* pNode)
	{
		if (IsFull()) // Queue가 가득 찼을 때
		{
			cout << "Queue is full." << endl;
			return false;
		}
		if (IsEmpty()) // Queue가 비어있을 때
		{
			m_pHead = pNode; // head를 새로 추가된 노드로 설정
			m_pTail = pNode; // tail을 새로 추가된 노드로 설정
		}
		else // Queue가 비어있지 않을 때
		{
			m_pTail->SetNext(pNode); // 기존 tail 노드의 다음 노드를 새로 추가된 노드로 설정
			m_pTail = pNode; // tail을 새로 추가된 노드로 설정
		}
		m_Size++; // 크기 증가
		return true;
	}
	Node* Pop()
	{
		if (IsEmpty()) // Qeueu가 비어 있을 때
		{
			cout << "Queue is empty." << endl;
			return NULL;
		}
		Node* pNode = m_pHead; // head node를 저장
		m_pHead = m_pHead->GetNext(); // head 포인터 이동
		m_Size--;
		return pNode;
	}
	void PrintQueue()
	{
		if (IsEmpty()) // Queue가 비어 있을 때
		{
			cout << "Queue is empty." << endl;
			return;
		}
		Node* pNode = m_pHead; // head node를 저장
		while (pNode != NULL) // 모든 node 순회
		{
			cout << pNode->GetData() << " "; // 값 출력
			pNode = pNode->GetNext();
		}
		cout << endl;
	}
};

int main() 
{
	Queue queue; // 객체 생성

	//Queue 크기 입력 받음
	int size;
	cout << "Enter the size of queue: ";
	cin >> size;
	queue.SetSize(size); //queue 크기 설정

	cout << "Push" << endl;
	for (int i = 0; i < size; i++) // queue의 size 만큼
	{
		int data;
		cout << "Enter a value to push: "; // 넣을 값 입력 받기
		cin >> data;
		Node* pNode = new Node(); // 새로운 Node 객체 동적할당
		pNode->SetData(data); // Node에 데이터 설정
		queue.Push(pNode); // Queue에 Node 추가
	}

	cout << "Print" << endl;
	queue.PrintQueue(); // Queue의 모든 요소 출력

	cout << "Pop" << endl;
	while (!queue.IsEmpty())  // Queue가 비어있지 않은 동안
	{
		Node* pNode = queue.Pop(); // Queue의 head 노드를 삭제하고 그 노드의 주소 반환
		cout << "Pop element: " << pNode->GetData() << endl; // 삭제된 노드의 데이터 출력
		delete pNode; // 노드 삭제
	}
	return 0;
}