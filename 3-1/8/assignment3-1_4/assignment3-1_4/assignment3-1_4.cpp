#include <iostream>
#include "Stack.h"

using namespace std;
int main()
{
    Stack stack; // ����
    int size, num; // ������ ������� �Է��� ����
    string Command; // ��ɾ�� ���� ���� ������Ʈ
    cout << "Stack size input : "; // ������ ũ��
    cin >> size;
    stack.SetSize(size);

    while (1)
    {
        cin >> Command;
        if (Command == "push") // push �ԷµǸ�
        {
            cin >> num; // ���� �Է� ��
            Node* pNode = new Node(); // �� ��� ����
            pNode->SetData(num); // �Է��� ���� ��� ����
            stack.Push(pNode); // ������ ������ �߰�
        }
        else if (Command == "pop")
        {
            Node* pPopNode = stack.Pop(); // �������� ��� 
            if (pPopNode != nullptr) // nullptr�� �ƴϸ� 
                cout << "Pop: " << pPopNode->GetData() << endl; // �������� ������ ���
        }
        else if (Command == "exit") // ���α׷� ����
            break;
        else if (Command == "print") // ���� ���� ������ ���
            stack.PrintStack();
        else if (Command == "empty") // ����ִ��� Ȯ��
        {
            if (stack.IsEmpty())
                cout << "Empty" << endl;
            else
                cout << "No Empty" << endl;
        }
        else if (Command == "full") // ���� ���� Ȯ��
        {
            if (stack.IsFull())
                cout << "Full" << endl;
            else
                cout << "No Full" << endl;
        }
        else // ������ ��ɾ�� ����
            cout << "error" << endl;
    }
    return 0;
}