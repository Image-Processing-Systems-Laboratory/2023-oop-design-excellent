#include <iostream>
using namespace std;

class Node
{
private:
	Node* m_pNext; // 다음 노드를 가리키는 포인터
	int m_Data;  // 노드에 저장된 데이터 값
public: 
	Node() // 생성자 - 초기화 함
	{
		m_pNext = NULL; // 다음 노드를 가리키는 포인터
		m_Data = 0; // 데이터 0으로 초기화
	}
	~Node(){} // 소멸자
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

class Stack
{
private:
	Node* m_pHead; // stack의 head
	int m_Size;  // stack의 크기
	int m_NumElement; // stack에 넣을 element의 수
public:
	Stack() // 생성자 - 초기화 함
	{
		m_pHead = NULL;  // head 포인터를 NULL로 초기화
		m_Size = 0; // stack의 크기를 0으로 초기화
		m_NumElement = 0; // stack에 넣을 element의 수를 0으로 초기화
	}
	~Stack() {} // 소멸자

	void SetSize(int n)
	{
		m_Size = n; // stack에 넣을 element의 수 설정
	}
	bool IsEmpty() 
	{
		return m_NumElement == 0; // stack이 비어있는지 여부를 반환
	}
	bool IsFull()
	{
		return m_NumElement == m_Size; // stack이 가득 찼는지 여부를 반환
	}
	bool Push(Node* pNode)
	{
		if (IsFull()) // stack이 가득 찼을 때
		{
			cout << "Stack is full." << endl;
			return false;
		}
		pNode->SetNext(m_pHead); // Node의 다음 Node를 현재의 top으로 설정
		m_pHead = pNode; // top을 추가된 Node로 설정
		++m_NumElement; // 개수 증가
		return true;
	}
	Node* Pop()
	{
		if (IsEmpty()) // stack이 비었을 때
		{
			cout << "Stack is empty." << endl;
			return NULL;
		}

		Node* pPop = m_pHead; // 제거할 Node를 저장
		m_pHead = m_pHead->GetNext(); // top을 다음 Node로 변경
		--m_NumElement; // 요소의 개수 감소
		return pPop; // 제거한 Node 반환
	}
	void PrintStack()
	{
		Node* pNode = m_pHead;

		while (pNode) // 모든 Node 순회
		{
			cout << pNode->GetData() << " "; // Node의 데이터 출력
			pNode = pNode->GetNext(); // 다음 Node로 이동
		}

		cout << std::endl;
	}
};

int main() 
{
	Stack stack; // 객체 생성

	// stack 크기 입력 받음
	int size;
	cout << "Enter the size of stack: ";
	cin >> size;
	stack.SetSize(size); // stack 크기 지정

	cout << "Push" << endl;
	for (int i = 0; i < size; ++i) // stack의 size 만큼
	{
		Node* pNode = new Node(); // 새로운 Node 객체 동적할당
		int data;
		cout << "Enter a value to push: ";
		cin >> data;
		pNode->SetData(data); // Node에 데이터 설정
		stack.Push(pNode); // stack에 Node 추가
	}
	
	cout << "Print" << endl;
	stack.PrintStack();  // stack의 모든 요소 출력

	cout << "Pop" << endl;
	while (!stack.IsEmpty())  // stack이 비어있지 않은 동안
	{
		Node* pNode = stack.Pop(); // stack의 head 노드를 삭제하고 그 노드의 주소 반환
		cout << "Pop element: " << pNode->GetData() << endl; // 삭제된 노드의 데이터 출력
		delete pNode; // 노드 삭제
	}
	return 0;
}