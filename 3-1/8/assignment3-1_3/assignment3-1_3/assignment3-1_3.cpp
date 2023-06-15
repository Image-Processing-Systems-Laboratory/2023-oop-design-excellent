#include <iostream>
#include "Queue.h"

using namespace std;
int main()
{
	Queue queue; // ť
    int size, num; // ť�� ������� �Է��� ����
    string Command; // ��ɾ�� ���� ť ������Ʈ
    cout << "Queue size input : "; // ť�� ũ��
	cin >> size;
	queue.SetSize(size);

    while (1)
    {
        cin >> Command;
        if (Command == "push") // push �ԷµǸ�
        {
            cin >> num; // ���� �Է� ��
            Node* pNode = new Node(); // �� ��� ����
            pNode->SetData(num); // �Է��� ���� ��� ����
            queue.Push(pNode); // ť�� ������ �߰�
        }
        else if (Command == "pop") 
        {
            Node* pPopNode = queue.Pop(); // �������� ��� 
            if (pPopNode != nullptr) // nullptr�� �ƴϸ� 
                cout << "Pop: " << pPopNode->GetData() << endl; // �������� ������ ���
        }
        else if (Command == "exit") // ���α׷� ����
            break;
        else if (Command == "print") // ���� ť ������ ���
            queue.PrintQueue();
        else if (Command == "empty") // ����ִ��� Ȯ��
        {
            if (queue.IsEmpty())
                cout << "Empty" << endl;
            else
                cout << "No Empty" << endl;
        }
        else if (Command == "full") // ���� ���� Ȯ��
        {
            if (queue.IsFull())
                cout << "Full" << endl;
            else
                cout << "No Full" << endl;
        }
        else // ������ ��ɾ�� ����
            cout << "error" << endl;
    }
    return 0;
}