#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Node //Node class
{
public:
    char data[100]; // ���ڿ� ������
    Node* next; // ���� ��带 ����Ű�� ������
    Node() // ����Ʈ ������
    {
        next = NULL; // ���� ��� �ʱ�ȭ
    }
    Node(char* temp) // ������
    {
        strcpy(data, temp); // ���ڿ� ����
        next = NULL; // ���� ��� �ʱ�ȭ
    }
    ~Node() {} // �Ҹ���
};

Node* Merge_List(Node* p1, Node* p2, Node* p3) // �� ���� ���� ����Ʈ ���� �Լ�
{
    Node* curr = p3;  // p3�� ���� ��ġ
    while (p1 != NULL && p2 != NULL) // �ϳ��� ���� �� ���� �ݺ�
    {
        if (_stricmp(p1->data, p2->data) < 0) // p1�� �����Ͱ� �� ������
        {
            curr->next = p1; // p1 ����
            p1 = p1->next; // ���� ���� �̵�
        }
        else // p2�� �����Ͱ� �� ������
        {
            curr->next = p2; // p2�� ����
            p2 = p2->next; // ���� ���� �̵�
        }
        curr = curr->next; // ���� ���� �̵�
    }
    if (p1 == NULL) // p1�� ������
    {
        curr->next = p2; // p2 ����
    }
    else // p2�� ������
    {
        curr->next = p1; // p1 ����
    }
    curr = p3; // curr�� p3���� �ʱ�ȭ
    p3 = p3->next; // p3�� ���� ���� �̵�
    delete curr; // curr �޸� ����
    return p3; // p3 ��ȯ
}

int main()
{
    // ���ڿ� �Է� ����
    char str1[100], str2[100];
    cout << "Input>>" << endl;
    cout << "Input list 1:";
    cin.getline(str1, 100);
    cout << "Input list 2:";
    cin.getline(str2, 100);

    Node* p1; // ù��° ����Ʈ ���� ����Ʈ
    Node* p2; // �ι�° ����Ʈ ���� ����Ʈ
    Node* p1_tail; // p1�� ������ ��带 ����Ű�� ������
    Node* p2_tail; // p2�� ������ ��带 ����Ű�� ������
    // ���ڿ� �Ľ̽� ����� ������ ����
    char* temp1 = NULL; 
    char* temp2 = NULL;

    // ù��° ����Ʈ �Ľ��Ͽ� ���� ����Ʈ�� �߰�
    temp1 = strtok(str1, " ");
    Node* tok1 = new Node{ temp1 };
    p1 = tok1;
    p1_tail = p1;
    while (temp1 = strtok(NULL, " "))
    {
        tok1 = new Node{ temp1 }; // ��� ����
        Node* p1_tail_next = p1_tail->next;
        while (p1_tail != NULL)
        {
            if (_stricmp(p1_tail->data, tok1->data) < 0) // p1_tail�� ���� ��庸�� tok1�� ������ ����
            {
                if (p1_tail_next == NULL) // p1_tail�� ���� ��尡 ���� ��� tok1�� �߰�
                {
                    p1_tail->next = tok1;
                    break;
                }
                else if (_stricmp(p1_tail_next->data, tok1->data) < 0) // p1_tail�� ���� ��尡 ���� ��� �� ū ��带 ã�� ������ ���� ���� �̵�
                {
                    p1_tail = p1_tail->next;
                    p1_tail_next = p1_tail_next->next;
                    continue;
                }
                else // p1_tail�� p1_tail_next ���̿� tok1 ����
                {
                    p1_tail->next = tok1;
                    tok1->next = p1_tail_next;
                    break;
                }
            }
            else  // tok1�� p1_tail���� ���� ��� ù��° ���� ����
            {
                p1 = tok1;
                p1->next = p1_tail;
                break;
            }   
        }
        p1_tail = p1;
    }
   
    // �ι�° ����Ʈ �Ľ��Ͽ� ���� ����Ʈ�� �߰�
    temp2 = strtok(str2, " ");
    Node* tok2 = new Node{ temp2 };
    p2 = tok2;
    p2_tail = p2;
    while (temp2 = strtok(NULL, " "))
    {
        tok2 = new Node{ temp2 }; // ��� ����
        Node* p2_tail_next = p2_tail->next;
        while (p2_tail != NULL)
        {
            if (_stricmp(p2_tail->data, tok2->data) < 0) // p2_tail�� ���� ��庸�� tok2�� ������ ����
            {
                if (p2_tail_next == NULL) // p2_tail�� ���� ��尡 ���� ��� tok2�� �߰�
                {
                    p2_tail->next = tok2;
                    break;
                }
                else if (_stricmp(p2_tail_next->data, tok2->data) < 0) // p2_tail�� ���� ��尡 ���� ��� �� ū ��带 ã�� ������ ���� ���� �̵�
                {
                    p2_tail = p2_tail->next;
                    p2_tail_next = p2_tail_next->next;
                    continue;
                }
                else // p2_tail�� p2_tail_next ���̿� tok2 ����
                {
                    p2_tail->next = tok2;
                    tok2->next = p2_tail_next;
                    break;
                }
            }
            else // tok2�� p2_tail���� ���� ��� ù��° ���� ����
            {
                p2 = tok2;
                p2->next = p2_tail;
                break;
            }
        }
        p2_tail = p2;
    }
    Node* p3 = new Node{  }; // ��� ������ ���� ����Ʈ ����

    Node* node = Merge_List(p1, p2, p3); // �� ���� ����Ʈ ������ p3�� ����

    cout << "Output>>" << endl;
    cout << "Result:";
    while (node != NULL)
    {
        cout << node->data << " "; // p3�� ������ ���
        node = node->next; // ���� ���� �̵�
    }
    return 0;
}