#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node     // Node ����ü
{
    int data;       // �����͸� �����ϴ� ����
    Node* next;     // ���� ��带 ����Ű�� ������
};

// Node�� �߰��ϴ� �Լ�
Node* addNode(int data)
{
    Node* newNode = new Node();     // ���ο� ��� ����
    newNode->data = data;		   // ������ ����
    newNode->next = nullptr;        // ���� ��带 nullptr�� �ʱ�ȭ
    return newNode;     // ���ο� ����� ������ ��ȯ
}

// Node�� �����ϴ��� Ȯ���ϴ� �Լ�
bool Existence(Node* head, int data)
{
    Node* current = head;       // ���� ��带 ����Ű�� ������
    // ���� ��尡 nullptr�� ������ �ݺ�
    while (current)
    {
        if (current->data == data)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Node�� �����ϴ� �Լ�
void insertNode(Node*& head, int data)
{
    Node* newNode = addNode(data);      // ���ο� ��� ����
    newNode->next = head;       // ���ο� ����� ���� ��带 head�� ����
    head = newNode;     // head�� ���ο� ���� ����
}

// Node�� ����ϴ� �Լ�
void printLinkedList(Node* head)
{
    Node* temp = head;      // ���� ��带 ����Ű�� ������
    // ���� ��尡 nullptr�� ������ �ݺ�
    while (temp)
    {
        cout << temp->data << " ";      // ���� ����� ������ ���
        temp = temp->next;      // ���� ��带 ���� ���� �̵�
    }
    cout << endl;
}

// ������ ���ڷ� ������ Node�� �����ϴ� �Լ�
Node* randomList()
{
    Node* head = nullptr;       // head�� nullptr�� �ʱ�ȭ
    int count = 0;	  // ���� ��� ������ �����ϴ� ����
    srand(time(0));     // ���� ������ �ʱ�ȭ

    // 16���� ��带 ���� ������ �ݺ�
    while (count < 16)
    {
        int randomNumber = rand() % 201;        // 0~200 ������ ���� ����
        // ������ ������ �������� ���� ���
        if (!Existence(head, randomNumber))
        {
            insertNode(head, randomNumber);     // ������ ������ ����
            count++;		// ���� ��� ���� 1 ����
        }
    }
    return head;    // head�� ��ȯ
}

// Node�� �����ϴ� �Լ�
void InsertionSort(Node*& head)
{
    if (!head || !head->next)       // ��尡 0�� �Ǵ� 1���� ���
        return;	 // �Լ� ����

    Node* sorted = nullptr;     // ���ĵ� ��带 ����Ű�� ������

    // head�� nullptr�� ������ �ݺ�
    while (head)
    {
        Node* current = head;       // ���� ��带 ����Ű�� ������
        head = head->next;      // head�� ���� ���� �̵�

        // ���ĵ� ��尡 ���ų� ���� ����� �����Ͱ� ���ĵ� ����� �����ͺ��� ���� ���
        if (!sorted || current->data > sorted->data)
        {
            current->next = sorted;     // ���� ����� ���� ��带 ���ĵ� ���� ����
            sorted = current;       // ���ĵ� ��带 ���� ���� ����
        }
        // ���ĵ� ����� �����ͺ��� ���� ����� �����Ͱ� Ŭ ���
        else
        {
            Node* temp = sorted;        // ���� ��带 ������ ��ġ�� ã�� ������
            // ���� ��带 ������ ��ġ�� ã�� ������ �ݺ�
            while (temp->next && temp->next->data > current->data)
            {
                temp = temp->next;      // ���� ���� �̵�
            }
            current->next = temp->next;     // ���� ����� ���� ��带 temp�� ���� ���� ����
            temp->next = current;       // temp�� ���� ��带 ���� ���� ����
        }
    }

    head = sorted;      // head�� ���ĵ� ���� ����
}

// Node�� ���̸� ��ȯ�ϴ� �Լ�
int listLength(Node* head)
{
    int length = 0;     // Node�� ���̸� �����ϴ� ����
    Node* current = head;       // ���� ��带 ����Ű�� ������
    // ���� ��尡 nullptr�� ������ �ݺ�
    while (current)
    {
        length++;       // ���� 1 ����
        current = current->next;        // ���� ���� �̵�
    }
    return length;      // ���� ��ȯ
}

// Node�� ��ġ�� ��ȯ�ϴ� �Լ�
Node* NodeAt(Node* head, int index)
{
    Node* current = head;       // ���� ��带 ����Ű�� ������
    int currentIndex = 0;	   // ���� ����� ��ġ�� �����ϴ� ����
    // ���� ��尡 nullptr�� �ƴϰ� ���� ����� ��ġ�� index���� ���� ��� �ݺ�
    while (current && currentIndex < index)
    {
        current = current->next;        // ���� ���� �̵�
        currentIndex++;     // ���� ����� ��ġ 1 ����
    }
    return current;     // ���� ��� ��ȯ
}

// Node���� ���ϴ� ���� ã�� �Լ�
Node* Binary_Search(Node* head, int target)
{
    InsertionSort(head);        // Node�� ����
    cout << "Sorted List: ";
    printLinkedList(head);      // ���ĵ� Node ���

    int low = 0;        // Low point�� �����ϴ� ����
    int high = listLength(head) - 1;        // High point�� �����ϴ� ����

    // low�� high���� �۰ų� ���� ��� �ݺ�
    while (low <= high)
    {
        int mid = (low + high) / 2;     // �߰� ��ġ�� �����ϴ� ����
        Node* midNode = NodeAt(head, mid);      // �߰� ��ġ�� Node�� ����Ű�� ������

        // �߰� ��ġ�� Node�� �����Ͱ� target�� ���� ���
        if (midNode->data == target) 
        {
            return midNode;     // �߰� ��ġ�� Node ��ȯ
        }
        // �߰� ��ġ�� Node�� �����Ͱ� target���� Ŭ ���
        else if (midNode->data < target)
        {
            high = mid - 1;
        }
        // �߰� ��ġ�� Node�� �����Ͱ� target���� ���� ���
        else
        {
            low = mid + 1;
        }
    }

    Node* closestNode;	  // ���� ����� Node�� ����Ű�� ������
    Node* lowNode = NodeAt(head, low);      // low ��ġ�� Node�� ����Ű�� ������
    Node* highNode = NodeAt(head, high);        // high ��ġ�� Node�� ����Ű�� ������

    // low�� 0���� ���� ���
    if (high < 0)
    {
        closestNode = lowNode;      // lowNode�� ���� ����� Node�� ����
    }
    // high�� Node�� ���̺��� Ŭ ���
    else if (low >= listLength(head))
    {
        closestNode = highNode;     // highNode�� ���� ����� Node�� ����
    }
    // lowNode�� highNode�� �������� ���̰� ���� ���
    else
    {
        closestNode = (abs(target - lowNode->data) <= abs(target - highNode->data)) ? lowNode : highNode;       // ���� ����� Node�� ����
    }
    
    // ���� ����� Node�� �����Ͱ� target���� Ŭ ���
    if(closestNode->data > target)
    {
		cout << "Node not found, below node does not exist" << endl;
        cout << "Closest node is result " << endl;
        return closestNode;
	}

    cout << "Node not found, below node is result " << endl;

    return closestNode;     // ���� ����� Node ��ȯ
}

int main()
{
    Node* head = randomList();      // ������ �����͸� ���� Node�� ����
    cout << "List: ";
    printLinkedList(head);      // Node ���

    int target = 0;     // Ž���� �����͸� �����ϴ� ����
    cout << "Write Binary Search: ";
    cin >> target;	  // Ž���� �����͸� �Է¹���
    Node* result = Binary_Search(head, target);		// Node�� Ž��

    cout << "Result: " << result->data << endl;		// Ž�� ��� ���

    return 0;
}