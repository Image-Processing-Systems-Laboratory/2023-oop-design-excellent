#include <iostream>
using namespace std;

const int MAX_SIZE = 128;
//Stack class 선언
class Stack {
    //private-비공개 멤버 class내부에서만 접근 가능 
private:
    int stack[MAX_SIZE];
    int top_index;
    //public-공개 멤버 class외부에서도 접근 가능
public:
    //Stack 객체가 생성될 때 호출 top_index를 0으로 초기화
    Stack() : top_index(0) {}
    //스택이 비어있으면 true, 아니면 false
    bool isEmpty() {
        if (top_index == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    //스택이 꽉차있으면 true, 아니면 false
    bool isFull() {
        if (top_index == MAX_SIZE) {
            return true;
        }
        else {
            return false;
        }
    }
    //스택이 꽉차 있지 않으면 stack[top++]에 value저장
    void push(int value) {
        if (!isFull()) {
            stack[top_index++] = value;
        }
        else {
            cout << "Stack is full." << endl;
        }
    }
    //스택에서 가장 위에 있는 값 보여줌, top_index 값 변화 X
    void top() {
        if (!isEmpty()) {
            cout << stack[top_index-1] << endl;
        }
        else {
            cout << "Stack is empty." << endl;
        }
    }
    //스택에서 가장 위에 있는 값 보여주고 제거, top_index 1감소
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty"<<endl;
            return;
        }
        else {
            cout << stack[top_index-1] << endl;
            stack[top_index--] = 0; // 요소를 0으로 초기화하고 top_index 감소
        }
    }
    //stack에 있는 원소 모두 출력
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        for (int i = 0; i <top_index; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    char cmd[10];

    while (true) {
        cin >> cmd;

        if (strcmp(cmd, "push") == 0) {
            int value;
            cin >> value;
            stack.push(value);
        }
        else if (strcmp(cmd,"top")==0) {
            stack.top();
        }
        else if (strcmp(cmd,"pop")==0) {
            stack.pop();
        }
        else if (strcmp(cmd,"print")==0) {
            stack.print();
        }
        else if (strcmp(cmd,"empty")==0) {
            if (stack.isEmpty()==true) {
                cout << 1<<endl;
            }
            else {
                cout << 0<<endl;
            }
        }
        else if (strcmp(cmd,"exit")==0) {
            break;
        }
        else {
            cout << "Unknown command." << endl;
        }
    }

    return 0;
}

