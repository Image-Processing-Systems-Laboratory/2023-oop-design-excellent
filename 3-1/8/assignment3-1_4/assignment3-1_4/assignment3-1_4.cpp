#include <iostream>
#include "Stack.h"

using namespace std;
int main()
{
    Stack stack; // 스택
    int size, num; // 스택의 사이즈와 입력할 숫자
    string Command; // 명령어로 통해 스택 업데이트
    cout << "Stack size input : "; // 스택의 크기
    cin >> size;
    stack.SetSize(size);

    while (1)
    {
        cin >> Command;
        if (Command == "push") // push 입력되면
        {
            cin >> num; // 숫자 입력 후
            Node* pNode = new Node(); // 새 노드 생성
            pNode->SetData(num); // 입력한 수로 노드 생성
            stack.Push(pNode); // 스택의 데이터 추가
        }
        else if (Command == "pop")
        {
            Node* pPopNode = stack.Pop(); // 빠져나갈 노드 
            if (pPopNode != nullptr) // nullptr이 아니면 
                cout << "Pop: " << pPopNode->GetData() << endl; // 빠져나간 데이터 출력
        }
        else if (Command == "exit") // 프로그램 종료
            break;
        else if (Command == "print") // 현재 스택 데이터 출력
            stack.PrintStack();
        else if (Command == "empty") // 비어있는지 확인
        {
            if (stack.IsEmpty())
                cout << "Empty" << endl;
            else
                cout << "No Empty" << endl;
        }
        else if (Command == "full") // 가득 찬지 확인
        {
            if (stack.IsFull())
                cout << "Full" << endl;
            else
                cout << "No Full" << endl;
        }
        else // 나머지 명령어는 오류
            cout << "error" << endl;
    }
    return 0;
}