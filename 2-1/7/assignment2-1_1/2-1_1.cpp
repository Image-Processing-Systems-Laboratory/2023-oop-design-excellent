#include <iostream>
using namespace std;

class Node // ���� Ŭ������ ����� ���� ������ ���� �̷���� �����Ƿ� ��� Ŭ������ ���� �������� �Ѵ�
{
private:
    int value; // ��� �� ������ ��
    Node* next; // ���� ���(��� ������ ���·� ����)
    Node* prev; // ���� ���

public:
    Node() // ������(�ʱⰪ)
    {
        this->value = 0; // ó�� ������ ���� 0
        this->next = NULL; // ���� ���� NULL
        this->prev = NULL; // ���� ��� ���� NULL
    }
    void setValue(int data) // ��� �� ����
    {
        this->value = data;
    }
    int getValue() // ��� �� ��ȯ
    {
        return this->value;
    }
    void setNext(Node* nextNode) // ���� ��� ����
    {
        this->next = nextNode;
    }
    Node* getNext() // ���� ��� ��ȯ
    {
        return this->next;
    }
    void setPrev(Node* prevNode) // ���� ��� ����
    {
        this->prev = prevNode;
    }
    Node* getPrev() // ���� ��� ��ȯ
    {
        return this->prev;
    }
};

class Stack // ������ ���� ��� Ŭ������ �̿��� ���� Ŭ����
{
private:
    // ������ top�� bottom���� �̷���� �ִ�
    Node* top; // top ���
    Node* bottom; // bottom ���
    int size; // ���� ������ ũ��
public:
    Stack() // ������(�ʱⰪ)
    {
        this->top = NULL; // ó�� ���� ������ top ���� NULL
        this->bottom = NULL; // bottom ��� ���� NULL
        this->size = 0; // ���� ũ��� 0(���� �߰��� ��尡 �����Ƿ�)
    }

    bool Empty() // ������ ����ִ��� üũ���ִ� bool �Լ�
    {
        if (this->size == 0) // ���� ũ�Ⱑ 0�̸�
            return true; // true�� ��ȯ(1)
        else // 0�� �ƴ϶��
            return false; // false�� ��ȯ(0)
    }

    void push(int data) // push�� bottom�� ��带 �߰����ִ°��� ���Ѵ�. 
    {
        if (size == 128) // ���� ũ��� �ִ� 128�̹Ƿ�
            return;
        Node* newNode = new Node; // ��� �����Ҵ�
        newNode->setValue(data); // ����ڿ��� ���ڷ� ���� ���� �� ��忡 ��������

        if (Empty()) // ���࿡ ����ִٸ�
        {
            top = bottom = newNode; // �� ��尡 ó�� ������ ����̹Ƿ� top�� ���ÿ� bottom�� ��尡 �ȴ�
            this->size++; // ũ�� 1 ����
        }
        else // �̹� �ٸ� ������ �����Ѵٸ�
        {
            top->setNext(newNode); // �� ��带 top ���� ���� �������ְ�
            newNode->setPrev(top); // �ݴ�� top ���� ��带 ������ �������� ����
            top = top->getNext(); // top�� ���� ���� �ű��. �� top�� �� ��尡 �Ǵ� ���̴�
            this->size++; // ũ�� 1 ����
        }
    }

    void pop() // ������ ���Լ���(LIFO)���� �̹Ƿ� ����(pop) �ÿ��� top���� �����Ѵ�(���� �ֱٿ� ����)
    {
        if (Empty()) // ������ ����ִ� ���� ����ó��
            return;
        else
        {
            if (this->size == 1) // ��尡 �ϳ��� �����Ѵٸ�(�� ���� top�� ���ÿ� bottom�� ���̴�)
            {
                delete bottom; // bottom�� �����
                bottom = NULL; // bottom��
                top = NULL; // top�� ��� NULL ó�����ش�
                this->size--; // ũ�� 1 ����
                return;
            }
            Node* popNode = top; // ���� ����� popNode�� �����ѵڿ� top���� �������ش�
            top = top->getPrev(); // �׸��� top�� ���� ���� �Ű��ش�
            delete popNode; // �׸��� popNode�� �����ְ�
            top->setNext(NULL); // top �������(���� popNode�� �ִ� ��ġ)�� NULL ó�����ش�
            this->size--; // ũ�� 1 ����
            // �̷��� �ϴ� ������ ������ ���Լ��� �����̹Ƿ� pop(��������)�ÿ��� top�� ��������� �ϴµ�, ���(top)�� �ٷ� delete �� �� ���� �����̴�
            // ���� ������ ���� popNode�� ���� �����ؼ� �̸� �̿��� ���� top�� �������ְ�, top�� �� ���� ��ġ�� �Ű��ش�
        }
    }

    void printTop() // top ���
    {
        Node* curNode = top; // curNode�� top���� �������ְ�
        cout << curNode->getValue() << endl; // ��� Ŭ������ getValue �Լ��� ���� ��尪�� ����Ѵ�.
    }

    void printAll(int count) // ���� ���� ��� ��� �� ���(��¼����� bottom���� top����)
    {
        Node* curNode = bottom; // ���� ��带 bottom���� �����ϰ�
        while (curNode != NULL) // bottom�������� NULL�� ������ ������, �� top����
        {
            cout << curNode->getValue() << " "; // getValue �Լ��� ���� ��尪�� ����ϰ�
            curNode = curNode->getNext(); // �������� �Ѿ��
        }
        cout << endl;
    }
};

int main(void)
{
    char input[6];
    int data = 0;
    Stack* stack = new Stack; // ��ü ����
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

    delete stack; // ����(��ü) �޸� ����

    return 0;
}