#include"oopstd.h"
#include<iostream>

namespace oopstd {
    Queue::Queue() {        //ť Ŭ������ ������
        m_pHead = nullptr;
        m_pTail = nullptr;
        m_NumElement = 0;
        m_Size = 0;     //�� ������� �ʱ�ȭ���ش�.
    }
    Queue::~Queue() {       //ť Ŭ������ �Ҹ���
        while (IsEmpty()==false) {      //��� �����������
            Node* temp = Pop();     //��带 pop�Լ��� �����ؼ� �����Ҵ� �������ش�.
            delete temp;
        }
    }

    void Queue::SetSize(int n) {        //ť Ŭ������ ������ �����Լ�
        m_Size = n;     //������ �� ����
    }

    bool Queue::IsEmpty() {         //ť�� ������� ���θ� ��ȯ�ϴ� �Լ�
        return m_NumElement == 0;       //����� ������ 0�̸� true��ȯ �ƴ϶�� false��ȯ
    }

    bool Queue::IsFull() {      //ť�� ���� ���ִ��� ���θ� ��ȯ�ϴ� �Լ�
        return m_NumElement == m_Size;  //����� ������ ������� ���ٸ� true��ȯ �ƴ϶�� false��ȯ
    }

    bool Queue::Push(Node* pNode) {     //ť�� ��带 �߰����ִ� �Լ�
        if (IsFull() == true) {         //���� �������� �߰������� �ʰ� false��ȯ
            return false;
        }
        if (IsEmpty() == true) {        //�ƿ� ����ִ� ť��� 
                m_pHead = pNode;        //�ҷ��� ��带 head�� tail�� ����Ű���� ���ش�.
                m_pTail = pNode;
        }
        else {                          //�� �� ������ ��� �ƴ϶��
                m_pTail->SetNext(pNode);        //tail�ڿ� �ҷ��� ��带 �߰����ش�.
                m_pTail = pNode;                //tail�� �ҷ��� ���� �Ű��ش�. 
        }
        m_NumElement++;         //����� ������ 1 �߰����ش�.
        return true;            //�� �ֱⰡ ���������� ��ȯ���ش�.
    }
    Node* Queue::Pop() {        //�����͸� �������ִ� �Լ�
        if (IsEmpty() == true) {        //����ִٸ� nullptr ��ȯ
            return nullptr;
        }
        else {                          //�ƴ϶��
            Node* temp = m_pHead;           //temp���� �� temp�� ù ��� ����Ű���� ��
            m_pHead=m_pHead->GetNext();     //head�� ������带 ����Ű�� ��
            m_NumElement--;                 //��� ���� 1 ����
            return temp;                    //temp�� ��ȯ
        }
    }
    void Queue::PrintQueue() {              //ť�� ����ִ� ��� �����͸� ������ִ� �Լ�
        Node* current = m_pHead;            //current�Լ� ���� �� ó�� ��带 ����Ű���� ��
        while (current != nullptr) {        //current�� nullptr�� �ƴҶ����� �ݺ����� �ݺ�
            std::cout << current->GetData() << " ";     //���� ����� �����͸� ���
            current = current->GetNext();       //���� ��带 ����Ŵ
        }
    }


    Node::Node() {              //��� Ŭ������ ������
        m_Data = 0;             //Ŭ������ ������� �ʱ�ȭ�Ѵ�.
        m_pNext = nullptr;
    }
    Node::~Node() {             //��� Ŭ������ �Ҹ���
    }

    void Node::SetData(int n) {     //�Է¹��� ������ ����� ���� �������ִ� �Լ�
        m_Data = n;
    }
    void Node::SetNext(Node* pNext) {       //���� ��带 �⸮���ִ� �Լ�
        m_pNext = pNext;    //���� ��尡 �Է¹��� ��带 ����Ű�� �Ѵ�.
    }
    int Node::GetData() {       //���� ����� �����͸� ��ȯ���ִ� �Լ�
        return m_Data;      //�����͸� ��ȯ����
    }
    Node* Node::GetNext() {     //���� ��尡 ����Ű�� ��带 ��ȯ���ִ� �Լ�
        return m_pNext;     //���� ��带 ��ȯ����
    }
}