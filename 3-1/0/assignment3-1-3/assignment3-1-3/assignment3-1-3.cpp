#include<iostream>


using namespace std;

class Node { // 노드 클래스

private:
    int m_Data;
    Node* m_pNext;

public:
    Node() { // 생성자
        m_Data = 0;
        m_pNext = NULL;
    }
    ~Node() {} // 소멸자

    void SetData(int n) { // 데이터 설정
        m_Data = n;
    }
    void SetNext(Node* pNext) { // 다음 노드 설정
        m_pNext = pNext;
    }
    int GetData() { // 데이터 반환
        return m_Data;
    }
    Node* GetNext() { // 다음 노드 반환
        return m_pNext;
    }
};

class Queue { // 큐 클래스

private:
    Node* m_pHead; // 큐의 헤드 노드
    Node* m_pTail; // 큐의 테일 노드
    int m_Size; // 큐의 크기
    int m_MaxSize; // 큐의 최대 크기

public:
    Queue(int maxSize) { // 생성자
        m_pHead = NULL;
        m_pTail = NULL;
        m_Size = 0;
        m_MaxSize = maxSize;
    }

    ~Queue() { // 소멸자
        Node* toDelete = nullptr;
        while (!IsEmpty()) { // 큐가 비어있지 않은 경우
            Node* toDelete = Pop();
            delete toDelete;
        }
    }
    void SetSize(int n) { // 큐의 크기 설정
        m_Size = n;
    }
    bool IsEmpty() { // 큐가 비어있는지 확인
        return m_pHead == NULL;
    }
    bool IsFull() {
        return m_Size == m_MaxSize; // 큐가 가득 차있는지 확인
    }
    bool Push(int data) { // 큐에 데이터 삽입
        if (IsFull()) {
            cout << "Queue is full" << endl;
            return false;
        }

        Node* newNode = new Node; // 새로운 노드 생성
        newNode->SetData(data); // 새로운 노드의 데이터 설정
        newNode->SetNext(nullptr); // 새로운 노드의 다음 노드를 NULL로 설정

        if (IsEmpty()) { // 큐가 비어있는 경우
            m_pHead = newNode;
            m_pTail = newNode;
        }
        else {  // 큐가 비어있지 않은 경우
            m_pTail->SetNext(newNode);
            m_pTail = newNode;
        }
        m_Size++;

        return true; // 데이터 삽입 성공
    }
    Node* Pop() { // 큐에서 데이터 삭제
        if (IsEmpty()) {
            return NULL;
        }
        Node* temp = m_pHead; // 삭제할 노드 임시 저장
        m_pHead = m_pHead->GetNext(); // 헤드 노드를 다음 노드로 설정
        m_Size--;
        return temp;

    }
    void PrintQueue() { // 큐 출력
        Node* temp = m_pHead;
        while (temp) {
            cout << temp->GetData() << " "; // 노드의 데이터 출력
            temp = temp->GetNext(); // 다음 노드로 이동
        }
        cout << endl;
    }
};

int main() {

    int maxSize;

    cout << "Enter the maximum queue size: ";
    cin >> maxSize;

    Queue myQueue(maxSize);

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
            myQueue.Push(num);
        }
        else if (strcmp(input, "pop") == 0) { // 입력이 "pop"인 경우
            if (myQueue.IsEmpty() == false) {
                Node* poppedNode = myQueue.Pop();
                cout << "Popped: " << poppedNode->GetData() << endl;
                delete poppedNode; // 메모리 해제
            }
            else {
                cout << "Queue is empty" << endl;
            }
        }
        else if (strcmp(input, "print") == 0) { //입력이 "print"인 경우
            cout << "Current queue: ";
            myQueue.PrintQueue();
        }
    }
    return 0;
}
