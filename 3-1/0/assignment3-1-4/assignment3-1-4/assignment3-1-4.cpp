#include <iostream>

using namespace std;

class Node { //노드 클래스 정의

private:
    int m_Data; //데이터를 저장하는 변수
    Node* m_pNext; //다음 노드를 가리키는 포인터

public:
    Node() { //생성자
        m_Data = 0;
        m_pNext = NULL;
    }
    ~Node() {} //소멸자

    void SetData(int n) { //데이터를 저장하는 함수
        m_Data = n;
    }
    void SetNext(Node* pNext) { //다음 노드를 가리키는 포인터를 설정하는 함수
        m_pNext = pNext;
    }
    int GetData() {     //데이터를 반환하는 함수
        return m_Data;
    }
    Node* GetNext() {   //다음 노드를 가리키는 포인터를 반환하는 함수
        return m_pNext;
    }
};

class Stack { //스택 클래스 정의

private:
    Node* m_pHead; //스택의 맨 위 노드를 가리키는 포인터
    int m_NumElement; //스택에 저장된 노드의 개수
    int m_Size; //스택의 최대 크기

public:
    Stack(int maxSize) { //생성자
        m_pHead = nullptr; //스택의 맨 위 노드를 가리키는 포인터를 NULL로 초기화
        m_NumElement = 0; //스택에 저장된 노드의 개수를 0으로 초기화
        m_Size = maxSize; //스택의 최대 크기를 maxSize로 초기화
    }
    ~Stack() { //소멸자
        Node* toDelete = nullptr; //삭제할 노드를 가리키는 포인터를 NULL로 초기화
        while (!IsEmpty()) {
            Node* toDelete = Pop();
            delete toDelete;
        }
    }
    void SetSize(int n) { //스택의 최대 크기를 설정하는 함수
        m_Size = n;
    }
    bool IsEmpty() { //스택이 비어있는지 확인하는 함수
        return m_pHead == NULL;
    }
    bool IsFull() { //스택이 가득 차있는지 확인하는 함수
        if (m_Size == 0) {
            return false;
        }
        return m_NumElement == m_Size;
    }
    bool Push(int data) { //스택에 노드를 삽입하는 함수
        if (IsFull()) {
            cout << "Stack is full" << endl;
            return false;
        }

        Node* newNode = new Node(); //삽입할 노드를 동적 할당
        newNode->SetData(data); //노드에 데이터 저장
        newNode->SetNext(m_pHead); //노드의 다음 노드를 현재 스택의 맨 위 노드로 설정

        m_pHead = newNode; //스택의 맨 위 노드를 새로 삽입한 노드로 설정
        m_NumElement++; //스택에 저장된 노드의 개수를 1 증가

        return true; //노드 삽입 성공
    }
    Node* Pop() { //스택의 맨 위 노드를 삭제하는 함수
        if (IsEmpty()) { //스택이 비어있는 경우
            return NULL;
        }
        Node* pNode = m_pHead; //삭제할 노드를 가리키는 포인터를 스택의 맨 위 노드로 설정
        m_pHead = m_pHead->GetNext(); //스택의 맨 위 노드를 삭제할 노드의 다음 노드로 설정
        m_NumElement--;
        return pNode; //삭제할 노드를 반환
    }
    void PrintStack() { //스택의 모든 노드를 출력하는 함수
        Node* temp = m_pHead;
        while (temp) {
            cout << temp->GetData() << " ";
            temp = temp->GetNext();
        }
        cout << endl;
    }
};

int main() {
    int maxSize;

    cout << "Enter the maximum stack size: "; //스택의 최대 크기를 입력받음
    cin >> maxSize;

    Stack myStack(maxSize); //스택 객체 생성

    char input[20];
    int num;

    cout << "Running Program : Enter the command" << endl;

    while (1) {
        cin >> input;

        if (strcmp(input, "exit") == 0) { //입력이 "exit"인 경우
            cout << "Program is now terminated." << endl;
            return 0;
        }
        else if (strcmp(input, "push") == 0) { //입력이 "push"인 경우
            cin >> num;
            myStack.Push(num);
        }
        else if (strcmp(input, "pop") == 0) { // 입력이 "pop"인 경우
            if (myStack.IsEmpty() == false) {
                Node* poppedNode = myStack.Pop();
                cout << "Popped: " << poppedNode->GetData() << endl;
                delete poppedNode; // 메모리 해제
            }
            else {
                cout << "Stack is empty" << endl;
            }
        }
        else if (strcmp(input, "print") == 0) { //입력이 "print"인 경우
            cout << "Current Stack: ";
            myStack.PrintStack();
        }
    }
    return 0;
}

