#include <iostream>
#include "Stack.h"
using namespace std;

Node::Node() { //Node class ������ ���� �ʱ�ȭ
     m_pNext = NULL;
     m_Data = 0;
}

Node::~Node() { //�Ҹ���
}

void Node::SetData(int n) {//private�� m_Data ���� �����ϱ� ���� �Լ�
    m_Data = n;
}

void Node::SetNext(Node* pNext) { //private�� m_pNext ���� �����ϱ� ���� �Լ�
    m_pNext = pNext;
}

int Node::GetData() { //private�� m_Data ���� �����ϱ� ���� �Լ�
    return m_Data;
}

Node* Node::GetNext() {//private�� m_pNext ���� �����ϱ� ���� �Լ�
    return m_pNext;
}

Stack::Stack() {//Stack class ������ ���� �ʱ�ȭ
    m_pHead = NULL; 
    m_size = 0;
    m_NumElement = 0;
}

Stack::~Stack() {//�Ҹ���
    Node* pTemp;
    while (m_pHead != NULL) { //���Ḯ��Ʈ ��带 ����
        pTemp = m_pHead; //��带 �ӽ� ����
        m_pHead = m_pHead->GetNext();//���� ��带 ���� ����
        delete pTemp;//���� ��� ����
    }
}

void Stack::SetSize(int n) {
    m_size = n; //���� ������ ����
    cout << "���� ������: " << n << endl;
}

bool Stack::isEmpty() { 
    return (m_NumElement == 0);  //������ ����ִ��� ���� ��ȯ
}

bool Stack::isFull() { //���� ���� ä���� ������
    return (m_NumElement == m_size); //������ ���� á���� ���� ��ȯ
}

bool Stack::push(Node* pNode) { 
    if (isFull()) {//������ �� ���ִٸ�
        cout << "������ ������ ���õ� ���� �ֽ��ϴ�." << endl;
        return false; //��ȯ
    }

    pNode->SetNext(m_pHead);//����� ���� �����͸� ���� ����
    m_pHead = pNode; //��� ��带 �߰��� ���� ����
    m_NumElement++;//���� ���� ����
    return true;
}

Node* Stack::pop() { 
    if (isEmpty()) {//������ ��� ������
        cout << "���� �� ���Ұ� �����ϴ�." << endl; //���� �޼��� ���
        return NULL;
    }
    Node* pTemp = m_pHead;//��� ��带 �ӽ� ����
    m_pHead = m_pHead->GetNext();//��带 ���� ���� ����
    m_NumElement--;//���� ���� ����
    return pTemp;//��� ��� ��ȯ
}

void Stack::PrintStack() {
    Node* pTemp = m_pHead; //���� ��带 ���� ����
    while (pTemp != NULL) {//���Ḯ��Ʈ ��带 ���� ���
        cout << pTemp->GetData() << endl;
        pTemp = pTemp->GetNext();//���� ���� �̵�
    }
    cout << endl;
}

