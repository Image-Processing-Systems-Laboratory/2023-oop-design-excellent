#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node* next;
};

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';
    return ch;
}

bool my_compare(const string& a, const string& b) // ��ҹ��� ���� ���� ��
{
    for (size_t i = 0; i < a.length() && i < b.length(); i++) // a,b�� ���� ��ŭ ��
    {
        char lower_a = toLower(a[i]); // a�� �ҹ��ڷ�
        char lower_b = toLower(b[i]); // b�� �ҹ��ڷ�
        if (lower_a < lower_b) // a�� �� ������ 
            return true; // true
        else if (lower_a > lower_b) // a�� �� ũ��       
            return false; // false
    }
}

Node* sortList(Node* head)
{
    if (head == nullptr) // head�� ���̸� ����ִ� ����Ʈ�̹Ƿ�
        return nullptr; // nullptr ��ȯ

    Node* sort = nullptr; // ������ ����� �ʱ�ȭ
    while (head != nullptr) // ����Ʈ�� ���� ���� ������ 
    {
        Node* Cur = head; // ���� ���� head��
        head = head->next; // ���� ���� ���� 

        if (sort == nullptr || my_compare(Cur->data, sort->data)) // ���ĵ� ����Ʈ�� ����ְų� ���� ��尡 ���ĵ� ����Ʈ�� ��庸�� �������
        {
            Cur->next = sort; // ���� ���� ���ĵ� ��� ó�� ����
            sort = Cur; // ���ĵ� ��忡 ���� ���� ����
        }
        else // ��� ���� �ʰų� ������ ���ڿ��� �� ū ���
        {
            Node* temp = sort;// ���ĵ� ���� �����ϰ�
            while (temp->next != nullptr && my_compare(temp->next->data, Cur->data)) // ���ĵ� ����Ʈ�� ���� �ƴҶ�����            
                temp = temp->next; // �� ���� ������ ����         
            Cur->next = temp->next; // ���� temp�� ���� ���� ���� ������ ����
            temp->next = Cur; // temp�� ���� ���������� ����
        }
    }
    return sort;
}

Node* Merge_List(Node* p1, Node* p2, Node* p3) // ���� ����Ʈ
{
    p1 = sortList(p1); // �� ���� ���ĵ� ����Ʈ
    p2 = sortList(p2);

    while (p1 != nullptr && p2 != nullptr) // �� ����Ʈ�� ������ ������
    {
        Node* newNode; // ���ο� ��� ����
        if (my_compare(p1->data, p2->data)) // ����Ʈ�� ���� ��
        {
            newNode = new Node{ p1->data, nullptr }; // true�� �����̴� p1�� ������ �̵�
            p1 = p1->next; // �� ���� ������
        }
        else
        {
            newNode = new Node{ p2->data, nullptr }; // false �϶��� p2�� ��ũ�Ƿ�
            p2 = p2->next; // ���� ���� �̵�
        }
        if (p3 == nullptr)
            p3 = newNode;
        else // �ι��ڰ� �ƴϸ�
        {
            Node* temp = p3; // ���ο� ��带 �߰��� ��ġ
            while (temp->next != nullptr) // �ι��ڰ� ����������
                temp = temp->next; // ���� ���� �̵�
            temp->next = newNode; // ���ο� ���� ��� �߰�
        }
    }

    Node* remaining; // �����ִ� ��� �߰�
    if (p1 != nullptr) // �ι��ڰ� �ƴϸ�
        remaining = p1;   // p1 ��ȯ
    else  // �ι��ڸ�
        remaining = p2; // p2 ��ȯ
    
    while (remaining != nullptr)
    {
        Node* newNode = new Node{ remaining->data, nullptr }; // �� ��� ����
        Node* temp = p3; // ���ο� ��带 �߰��� ��ġ
        while (temp->next != nullptr) // ����Ʈ�� ���� ������ ������ �ݺ�
            temp = temp->next; // ���� ���� �̵�
        temp->next = newNode; // ��带 ��� �߰�
        remaining = remaining->next; // ���� ����Ʈ���� ���� ���� �̵�
    }
    return p3; // ��ġ�� ���ĵ� ����Ʈ ��ȯ
}

Node* strchangeNode(const string& input) // �Է��� ��Ʈ���� ����
{
    Node* head = nullptr; // ó���� �� �ʱ�ȭ
    Node* tail = nullptr;
    string word; // ���ڿ����� ���� ó�� ���� �ܾ ������ ����

    for (char ch : input)
    {
        if (ch != ' ') // ������ ����������
            word += ch; // �ܾ� ��� �޾ƿ�
        else // �����̸�
        {
            if (word.length() > 0) // �� �ܾ��� ���̰� 0���� ũ��
            {
                Node* newNode = new Node{ word, nullptr }; // �� ��� ������ ����   
                if (head == nullptr) // �ι��ڸ�
                    head = newNode; // ���ο� ��带 ó������ ����
                else // �ι��ڰ� �ƴϸ�
                    tail->next = newNode; // �� �������� ����Ű�� ����� ����Ű����
                tail = newNode; // �Ǹ������� ��� ��
                word = ""; // �ܾ� �ʱ�ȭ
            }
        }
    }
    if (word.length() > 0) // �� �������ܾ�
    {
        Node* newNode = new Node{ word, nullptr }; // �� ��� �����ϰ� �ܾ ����
        if (head == nullptr) // ���� ����Ʈ�� ����ִ� ���
            head = newNode; // ���ο� ��带 ����Ʈ�� ó������ ����
        else // ���� ����Ʈ�� ������� ���� ���
            tail->next = newNode; // ���� ������ ����� ���� ���� �� ��带 ����
        tail = newNode; // ���ο� ��带 ������ ���� ����
    }
    return head; // �� ó������Ű�� head ��ȯ
}

int main()
{
    string input1, input2; // �Է��� �� ���ڿ�
    cout << "Input>>" << endl;
    cout << "Input list 1:";
    getline(cin, input1);
    cout << "Input list 2:";
    getline(cin, input2);

    Node* p1 = strchangeNode(input1); // ��� ���·� �ٲ���
    Node* p2 = strchangeNode(input2);
    Node* result = nullptr; // ��� ��带 �ʱ�ȭ
    result = Merge_List(p1, p2, result);

    cout << "Output>>" << endl;
    cout << "Result: ";
    Node* current = result; // ��� ���
    while (current != nullptr)
    {
        cout << current->data;
        if (current->next != nullptr)
            cout << " ";     
        current = current->next;
    }

    return 0;
}