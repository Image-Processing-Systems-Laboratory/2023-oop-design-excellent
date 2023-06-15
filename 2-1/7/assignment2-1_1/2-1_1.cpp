#include <iostream>
using namespace std;

class Node // 스택 클래스를 만들기 전에 스택은 노드로 이루어져 있으므로 노드 클래스를 먼저 만들어줘야 한다
{
private:
    int value; // 노드 속 데이터 값
    Node* next; // 다음 노드(노드 포인터 형태로 선언)
    Node* prev; // 이전 노드

public:
    Node() // 생성자(초기값)
    {
        this->value = 0; // 처음 생성시 값은 0
        this->next = NULL; // 다음 노드는 NULL
        this->prev = NULL; // 이전 노드 역시 NULL
    }
    void setValue(int data) // 노드 값 설정
    {
        this->value = data;
    }
    int getValue() // 노드 값 반환
    {
        return this->value;
    }
    void setNext(Node* nextNode) // 다음 노드 설정
    {
        this->next = nextNode;
    }
    Node* getNext() // 다음 노드 반환
    {
        return this->next;
    }
    void setPrev(Node* prevNode) // 이전 노드 설정
    {
        this->prev = prevNode;
    }
    Node* getPrev() // 이전 노드 반환
    {
        return this->prev;
    }
};

class Stack // 위에서 만든 노드 클래스를 이용한 스택 클래스
{
private:
    // 스택은 top과 bottom으로 이루어져 있다
    Node* top; // top 노드
    Node* bottom; // bottom 노드
    int size; // 현재 스택의 크기
public:
    Stack() // 생성자(초기값)
    {
        this->top = NULL; // 처음 스택 생성시 top 노드는 NULL
        this->bottom = NULL; // bottom 노드 역시 NULL
        this->size = 0; // 스택 크기는 0(아직 추가된 노드가 없으므로)
    }

    bool Empty() // 스택이 비어있는지 체크해주는 bool 함수
    {
        if (this->size == 0) // 스택 크기가 0이면
            return true; // true를 반환(1)
        else // 0이 아니라면
            return false; // false를 반환(0)
    }

    void push(int data) // push는 bottom에 노드를 추가해주는것을 말한다. 
    {
        if (size == 128) // 스택 크기는 최대 128이므로
            return;
        Node* newNode = new Node; // 노드 동적할당
        newNode->setValue(data); // 사용자에게 인자로 받은 값을 새 노드에 설정해줌

        if (Empty()) // 만약에 비어있다면
        {
            top = bottom = newNode; // 이 노드가 처음 들어오는 노드이므로 top인 동시에 bottom인 노드가 된다
            this->size++; // 크기 1 증가
        }
        else // 이미 다른 노드들이 존재한다면
        {
            top->setNext(newNode); // 새 노드를 top 다음 노드로 지정해주고
            newNode->setPrev(top); // 반대로 top 이전 노드를 새노드로 지정해준 다음
            top = top->getNext(); // top을 다음 노드로 옮긴다. 즉 top은 새 노드가 되는 것이다
            this->size++; // 크기 1 증가
        }
    }

    void pop() // 스택은 후입선출(LIFO)구조 이므로 삭제(pop) 시에는 top부터 삭제한다(가장 최근에 들어온)
    {
        if (Empty()) // 스택이 비어있는 경우는 예외처리
            return;
        else
        {
            if (this->size == 1) // 노드가 하나만 존재한다면(그 노드는 top인 동시에 bottom일 것이다)
            {
                delete bottom; // bottom을 지우고
                bottom = NULL; // bottom과
                top = NULL; // top을 모두 NULL 처리해준다
                this->size--; // 크기 1 감소
                return;
            }
            Node* popNode = top; // 지울 노드인 popNode를 선언한뒤에 top으로 설정해준다
            top = top->getPrev(); // 그리고 top을 이전 노드로 옮겨준다
            delete popNode; // 그리고 popNode를 지워주고
            top->setNext(NULL); // top 다음노드(원래 popNode가 있던 위치)를 NULL 처리해준다
            this->size--; // 크기 1 감소
            // 이렇게 하는 이유는 스택은 후입선출 구조이므로 pop(삭제연산)시에도 top에 접근해줘야 하는데, 노드(top)는 바로 delete 할 수 없기 때문이다
            // 따라서 다음과 같이 popNode를 따로 선언해서 이를 이용해 원래 top을 삭제해주고, top을 그 이전 위치로 옮겨준다
        }
    }

    void printTop() // top 출력
    {
        Node* curNode = top; // curNode를 top으로 설정해주고
        cout << curNode->getValue() << endl; // 노드 클래스의 getValue 함수를 통해 노드값을 출력한다.
    }

    void printAll(int count) // 스택 내의 모든 노드 값 출력(출력순서는 bottom에서 top으로)
    {
        Node* curNode = bottom; // 현재 노드를 bottom으로 설정하고
        while (curNode != NULL) // bottom에서부터 NULL을 만나기 전까지, 즉 top까지
        {
            cout << curNode->getValue() << " "; // getValue 함수를 통해 노드값을 출력하고
            curNode = curNode->getNext(); // 다음노드로 넘어간다
        }
        cout << endl;
    }
};

int main(void)
{
    char input[6];
    int data = 0;
    Stack* stack = new Stack; // 객체 생성
    int count = 0;
    int cnt = 0;

    while (count<=128)
    {
        cin >> input;

        if (strcmp(input, "push") == 0)
        {
            cin >> data;
            stack->push(data);
            count++;
        }
        else if (strcmp(input, "pop") == 0)
        {
            stack->printTop();
            stack->pop();
            count--;
        }
        else if (strcmp(input, "top") == 0)
        {
            stack->printTop();
        }
        else if (strcmp(input, "print") == 0)
        {
            stack->printAll(count);
        }
        else if (strcmp(input, "empty") == 0)
        {
            bool b = stack->Empty();
            cout << b << endl;
        }
        else if (strcmp(input, "exit") == 0)
            break;
    }

    delete stack; // 스택(객체) 메모리 해제

    return 0;
}