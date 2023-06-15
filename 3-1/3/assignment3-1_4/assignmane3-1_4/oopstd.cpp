#include<iostream>
#include"oopstd.h"

namespace oopstd {
	Node::Node() {              //노드 클래스의 생성자
        m_Data = 0;             //클래스의 멤버들을 초기화한다.
        m_pNext = nullptr;
    }
    Node::~Node() {             //노드 클래스의 소멸자
    }

    void Node::SetData(int n) {     //입력받은 값으로 노드의 값을 저장해주는 함수
        m_Data = n;
    }
    void Node::SetNext(Node* pNext) {       //다음 노드를 기리켜주는 함수
        m_pNext = pNext;    //현재 노드가 입력받은 노드를 가리키게 한다.
    }
    int Node::GetData() {       //현재 노드의 데이터를 반환해주는 함수
        return m_Data;      //데이터를 반환해줌
    }
    Node* Node::GetNext() {     //현재 노드가 가리키는 노드를 반환해주는 함수
        return m_pNext;     //다음 노드를 반환해줌
    }

	Stack::Stack() {		//스택 클래스의 생성자
		m_pHead = nullptr;
		m_NumElement = 0;
		m_Size = 0;			//각 멤저들을 초기화해준다.
	}
	Stack::~Stack() {		//스택 클래스의 소멸자
		while (IsEmpty() == false) {		//모두 비워질때까지
			Node* temp = Pop();		//노드를 pop함수로 추출해서 동적할당 해제해준다.
			delete temp;
		}
	}

	void Stack::SetSize(int n) {		//스택 클래스의 사이즈 조절함수
		m_Size = n;     //사이즈 값 저장
	}
	bool Stack::IsEmpty() {         //스택이 비었는지 여부를 반환하는 함수
		return m_NumElement == 0;      //요소의 개수가 0이면 true반환 아니라면 false반환
	}
	bool Stack::IsFull() {      //스택이 가득 차있는지 여부를 반환하는 함수
		return m_NumElement == m_Size;  //요소의 개수가 사이즈와 같다면 true반환 아니라면 false반환
	}
	bool Stack::Push(Node* pNode) {		//스택에 노드를 추가해주는 함수
		if (IsFull() == true) {		//가득 차있으면 추가해주지 않는다.
			return false;
		}
		if (IsEmpty() == true) {       //아예 비어있는 스택이라면 
			m_pHead = pNode;       //불러온 노드를 head와 tail이 가리키도록 해준다.
			m_pTail = pNode;
		}
		else {                          //위 두 조건이 모두 아니라면
			m_pTail->SetNext(pNode);        //tail뒤에 불러온 노드를 추가해준다.
			m_pTail = pNode;               //tail을 불러온 노드로 옮겨준다. 
		}
		m_NumElement++;         //요소의 개수를 1 추가해준다.
		return true;            //값 넣기가 성공했음을 반환해준다.
	}
	Node* Stack::Pop() {        //데이터를 추출해주는 함수
		if (IsEmpty() == true) {        //비어있다면 nullptr 반환
			return nullptr;
		}
		Node* temp = m_pTail;			//temp는 끝 노드를 가리키도록 함
		if (m_pHead == m_pTail) {		//만약 첫노드가 마지막 노드라면
			m_pHead = nullptr;			//두 포인터 모두 nullptr을 가리키도록 함
			m_pTail = nullptr;
		}
		else {							//아니라면
			Node* Present_Tail = m_pHead;				//끝노드의서 한칸 앞 노드를 가리킬 포인터 선언
			while (Present_Tail->GetNext()!= m_pTail) {	//끝노드를 가리키도록 반복문(다음 노드가 끝노드가 아닐때동안)
				Present_Tail = Present_Tail->GetNext();	//다음 노드로 넘어가기
			}
			m_pTail = Present_Tail;		//끝 노드는 끝노드의 이전 노드로 바꿔줌
			m_pTail->SetNext(nullptr);	//끝 노드를 가리키던 것을 없애줌
		}
		m_NumElement--;				//요소 개수 1 빼기
		return temp;				//temp를 반환
	}
	void Stack::PrintStack() {              //스택에 들어있는 모든 데이터를 출력해주는 함수
		Node* current = m_pHead;            //current함수 선언 후 처음 노드를 가리키도록 함
		while (current != nullptr) {       //current가 nullptr이 아닐때까지 반복문을 반복
			std::cout << current->GetData() << " ";     //현재 노드의 데이터를 출력
			current = current->GetNext();       //다음 노드를 가리킴
		}
	}
}