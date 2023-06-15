#include <iostream>
#include <string>

using namespace std;
//����Ʈ ����ü
struct Node {
    string data;//������
    Node* next;//���� ����� ������
};
//���Ḯ��Ʈ�� ��带 �߰��ϴ� �Լ�
void Insert(Node*& head, string value) {
    Node* newNode = new Node; //�� ��� ���� �Ҵ�
    newNode->data = value; //��忡 ������ �߰�
    newNode->next = nullptr; //�� ��� ���� �����ʹ� Null
   //���� ����Ʈ�� ���������
    if (head == nullptr) {// �� ��带 Head��
        head = newNode;
    }
    else {//������� �ʴٸ� ������ ��忡 �� ��� �߰�
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
//�� ���Ḯ��Ʈ�� �ϳ��� ��ġ�� �Լ�
void Merge_List(Node* p1, Node* p2, Node*& p3) {
    //���� �ϳ��� ��������� p3�� �ϳ��� �״�� ����
    if (!p1) {
        p3 = p2;
        return;
    }
    if (!p2) {
        p3 = p1;
        return;
    }
   
    string data1 = p1->data;
    string data2 = p2->data;
    // ��� ���ڿ��� �ҹ��ڷ� ��ȯ
    for (int i = 0; i < data1.size(); i++) {
        data1[i] = tolower(data1[i]);
    }
    for (int i = 0; i < data2.size(); i++) {
        data2[i] = tolower(data2[i]);
    }
    //data1�� data2���� �۰ų� ���� �� p1��带 p3�� �߰��ϰ� p1 ���� ���� p2��带 ��
    if (data1 <= data2) {
        p3 = p1;
        Merge_List(p1->next, p2, p3->next);
    }
    //data2�� data1���� �۰ų� ���� �� p1��带 p3�� �߰��ϰ� p1 ���� ���� p2��带 ��
    else {
        p3 = p2;
        Merge_List(p1, p2->next, p3->next);
    }
}
// ����Ʈ�� �����ϴ� �Լ�
Node* MergeSort(Node* head) {
    //���Ḯ��Ʈ ũ�Ⱑ0�̳� 1�̸� ��ȯ
    if (!head || !head->next) {
        return head;
    }

    Node* sub1 = head;
    Node* sub2 = head->next;

    while (sub2 && sub2->next) {//sub1�� �ѹ��� ��ĭ sub2�� �ѹ��� ��ĭ���̵�
        sub1 = sub1->next;  //sub1�� ������ ���������� �߰��� �ճ�带 ����Ŵ
        sub2 = sub2->next->next;
    }

    Node* rightHead = sub1->next;
    sub1->next = nullptr;
    //�������ȣ��
    Node* left = MergeSort(head);
    Node* right = MergeSort(rightHead);
    Node* sorted = nullptr;
    //�ϳ��� ��ġ�� ���� �Լ� ȣ��
    Merge_List(left, right, sorted);

    return sorted;
}

//����Ʈ�� ����ϴ� �Լ�
void PrintList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    Node* addList = nullptr;
    //�Է¹޴� ���ڿ� ����
    string input1;
    string input2;
    cout << "input1 : ";
    //���͸� ġ�� ������ input1�� ���� �ݺ� �Է�
    while (cin >> input1) {
        Insert(list1, input1); //input1�� list1�� ����
        if (cin.get() == '\n') {
            break;
        }
    }
    //���͸� ġ�� ������ input2�� ���� �ݺ� �Է�
    cout << "input2 : ";
    while (cin >> input2) {
        Insert(list2, input2); //input2�� list2�� ����
        if (cin.get() == '\n') {
            break;
        }
    }
    //
    list1 = MergeSort(list1);//list1����
    list2 = MergeSort(list2);//list2 ����
    Merge_List(list1, list2, addList);//1�� 2�� ���� �ϳ��� ���ĵ� addlist�� ����

    cout << "Resilt: ";
    PrintList(addList);//���

    return 0;
}