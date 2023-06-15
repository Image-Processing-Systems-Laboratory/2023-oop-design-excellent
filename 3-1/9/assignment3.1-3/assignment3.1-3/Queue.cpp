#include <iostream>
#include "Queue.h"
using namespace std;

Node::Node() { //Node class ������ ���� �ʱ�ȭ
    m_pNext = NULL;
    m_Data = 0;
}

Node::~Node() {} //�Ҹ���

void Node::SetData(int n) { //private�� m_Data ���� �����ϱ� ���� �Լ�
    m_Data = n;
}

void Node::SetNext(Node* pNext) {//private�� m_pNext ���� �����ϱ� ���� �Լ�
    m_pNext = pNext;
}

int Node::GetData() {//private�� m_Data ���� �����ϱ� ���� �Լ�
    return m_Data;
}

Node* Node::GetNext() {//private�� m_pNext ���� �����ϱ� ���� �Լ�
    return m_pNext;
}

Queue::Queue() { //Queue class ������ ���� �ʱ�ȭ
    m_pHead = NULL;
    m_pTail = NULL;
    m_size = 0;
    m_NumElement = 0;
}

Queue::~Queue() { //�Ҹ���
    Node* pTemp;
    while (m_pHead != NULL) {//���Ḯ��Ʈ ��带 ����
        pTemp = m_pHead; //��带 �ӽ� ����
        m_pHead = m_pHead->GetNext(); //���� ��带 ���� ����
        delete pTemp; //���� ��� ����
    }
}

void Queue::SetSize(int n) {
    m_size = n; //ť ������ ����
    cout << "ť ������: " << n << endl;
}

bool Queue::isEmpty() {
    return (m_NumElement == 0); //ť�� ����ִ��� ���� ��ȯ
}

bool Queue::isFull() {
    return (m_NumElement == m_size); //ť�� ���� á���� ���� ��ȯ
}


bool Queue::push(Node*pNode) {
    if (isFull()) {//ť�� ���� ��������
        cout << "������ ������ ���õ� ���� �ֽ��ϴ�." << endl;
        return false; //��ȯ
    }
    pNode->SetNext(NULL); //����� ���� �����͸� �η� ����
    if (isEmpty()) { //ť�� ���������
        m_pHead = pNode; //��忡 ��� �߰�
    }
    else {//�ƴϸ�
        m_pTail->SetNext(pNode);//���� ����� ���� ���� �߰�
    }
    m_pTail = pNode; //���� ��带 �߰��� ���� ����
    m_NumElement++; //���� ���� ����
    return true;
}

Node* Queue::pop() { 
    if (isEmpty()) { //ť�� ��� ������
        cout << "���� �� ���Ұ� �����ϴ�." << endl; //���� �޼��� ���
        return NULL;
    }
    Node* pTemp = m_pHead; //��� ��带 �ӽ� ����
    m_pHead = m_pHead->GetNext(); //��带 ���� ���� ����
    m_NumElement--; //���� ���� ����
    return pTemp; //��� ��� ��ȯ
}
void Queue::PrintQueue() {
    Node* pTemp = m_pHead; //���� ��带 ���� ����
    while (pTemp != NULL) { //���Ḯ��Ʈ ��带 ���� ���
        cout << pTemp->GetData() << " ";
        pTemp = pTemp->GetNext(); //���� ���� �̵�
    }
    cout << endl;
}

