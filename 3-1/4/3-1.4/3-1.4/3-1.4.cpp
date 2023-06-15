#include <iostream>

using namespace std;

class Node {
private:
    Node* m_pNext; //다음 노드를 가리키는 포인터
    int m_Data; //노드의 데이터
public:
    Node() { //노드 생성자 //포인터와 데이터 초기화
        m_pNext = nullptr;
        m_Data = 0;
    }
    ~Node() {} //노드 소멸자

    void SetData(int n) { //데이터 설정
        m_Data = n;
    }
    void SetNext(Node* pNext) { //다음 노드 설정
        m_pNext = pNext;
    }
    int GetData() { //m_Data 반환
        return m_Data;
    }
    Node* GetNext() { //m_pNext 반환
        return m_pNext;
    }
};

class Stack { //Stack class
private: 
    Node* m_pHead; //스택의 첫 번째 노드를 가리키는 포인터
    int m_Size; //스택의 크기
    int m_NumElement; //스택에 있는 노드의 개수
public:
    Stack() { //스택 생성자
        m_pHead = nullptr; //포인터 초기화
        m_Size = 0; //크기 초기화
        m_NumElement = 0; //노드 개수 초기화
    }

    ~Stack() {} //스택 소멸자

    void SetSize(int n) { //스택 크기 설정 함수
        m_Size = n; //크기 값 할당
    }

    bool IsEmpty() { //스택이 비어 있는지 확인하는 함수
        return m_pHead == nullptr; //스택의 첫 번째 노드 포인터가 nullptr이면 true 반환
    }

    bool IsFull() { //스택이 가득 차있는지 확인하는 함수
        return m_NumElement == m_Size; //스택에 있는 노드 개수와 큐의 크기가 같으면 true 반환
    }

    bool Push(Node* pNode) { //스택에 노드를 추가하는 함수
        if (m_pHead == nullptr) { //스택이 비어있으면
            m_pHead = pNode; //헤드 노드 설정
        }
        else { //Stack이 비어있지 않으면
            pNode->SetNext(m_pHead); //새로운 노드의 다음 노드를 헤드 노드로 설정
            m_pHead = pNode; //새로운 노드를 헤드 노드로 설정
        }
        m_NumElement++; //Stack에 있는 노드 개수 1 증가

        return true;
    }

    Node* Pop() { //Stack에서 Node를 삭제하고 반환하는 함수
        if (m_pHead == nullptr) { //스택이 비어있으면
            return nullptr; //nullptr 반환
        }
        Node* pNode = m_pHead; //헤드 노드를 pNode에 저장
        m_pHead = m_pHead->GetNext(); //헤드 노드를 pNode의 다음 노드로
        pNode->SetNext(nullptr); // pNode의 다음 노드를 null로 설정
        m_NumElement--; //Stack에 있는 노드 개수 1 감소
        return pNode; //삭제한 노드 반환
    }

    void PrintStack() { //Stack에 있는 노드들을 출력하는 함수
        cout << "Stack Elements: ";
        Node* pNode = m_pHead; //pNode 초기화
        while (pNode != nullptr) { //pNode가 nullptr가 아니면 반복
            cout << pNode->GetData() << " "; //pNode가 가리키는 노드의 데이터 출력
            pNode = pNode->GetNext(); //pNode를 다음 노드로
        }
        cout << endl; //개행
    }
};

int main() {
    Stack stack; //stack 객체 선언
    int size;
    cout << "Enter the size: "; 
    cin >> size; //크기 입력받아 SetSize로 크기 설정
    stack.SetSize(size);

    string command; //입력받은 command 변수 선언
    cout << "push/pop/print/empty/full/break" << endl; //사용자에게 입력 가능한 명령어들을 알려주기 위해 출력

    while (true) {
        cin >> command; //command 입력받기

        if (command == "push") { //push 입력받으면
            if (stack.IsFull()) { //스택이 가득 찼는지 확인
                cout << "Stack is full." << endl;
            }
            else { //스택이 가득 차지 않았으면
                int num;
                cin >> num; //스택에 추가할 값 입력받기
                Node* pNode = new Node(); //새로운 노드 객체 생성
                pNode->SetData(num); //노드의 데이터를 입력받은 num으로 설정
                stack.Push(pNode); //Push() 호출해 스택에 노드 추가
            }
        }
        else if (command == "pop") { //pop 입력받으면
            if (stack.IsEmpty()) { //스택이 비어있는지 확인
                cout << "Stack is empty." << endl;
            }
            else {
                Node* pNode = stack.Pop(); //Pop() 호출해 스택에서 노드 제거
                cout << pNode->GetData() << endl; //제거한 노드 데이터 출력
                delete pNode; //제거한 노드 메모리 해제
            }
        }
        else if (command == "print") { //print 입력받으면
            stack.PrintStack(); //PrintQueue() 호출해 스택 elements 출력
        }
        else if (command == "empty") { //empty 입력받으면
            if (stack.IsEmpty()) { //비어있으면
                cout << "Stack is empty." << endl; //비었다고 텍스트 출력
            }
            else { //비어있지 않으면
                cout << "Stack is not empty." << endl; //비어있지 않다고 텍스트 출력
            }
        }
        else if (command == "full") { //full 입력받으면
            if (stack.IsFull()) { //가득 차있으면
                cout << "Stack is full." << endl; //가득 찼다고 텍스트 출력
            }
            else { //가득 차있지 않으면
                cout << "Stack is not full." << endl; //가득 차지 않았다고 텍스트 출력
            }
        }
        else if (command == "break") { //break 입력받으면
            break; //프로그램 종료
        }
    }
    return 0; //종료
}


