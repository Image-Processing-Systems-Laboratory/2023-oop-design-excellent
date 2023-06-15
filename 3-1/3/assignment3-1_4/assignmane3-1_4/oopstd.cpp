#include<iostream>
#include"oopstd.h"

namespace oopstd {
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

	Stack::Stack() {		//���� Ŭ������ ������
		m_pHead = nullptr;
		m_NumElement = 0;
		m_Size = 0;			//�� �������� �ʱ�ȭ���ش�.
	}
	Stack::~Stack() {		//���� Ŭ������ �Ҹ���
		while (IsEmpty() == false) {		//��� �����������
			Node* temp = Pop();		//��带 pop�Լ��� �����ؼ� �����Ҵ� �������ش�.
			delete temp;
		}
	}

	void Stack::SetSize(int n) {		//���� Ŭ������ ������ �����Լ�
		m_Size = n;     //������ �� ����
	}
	bool Stack::IsEmpty() {         //������ ������� ���θ� ��ȯ�ϴ� �Լ�
		return m_NumElement == 0;      //����� ������ 0�̸� true��ȯ �ƴ϶�� false��ȯ
	}
	bool Stack::IsFull() {      //������ ���� ���ִ��� ���θ� ��ȯ�ϴ� �Լ�
		return m_NumElement == m_Size;  //����� ������ ������� ���ٸ� true��ȯ �ƴ϶�� false��ȯ
	}
	bool Stack::Push(Node* pNode) {		//���ÿ� ��带 �߰����ִ� �Լ�
		if (IsFull() == true) {		//���� �������� �߰������� �ʴ´�.
			return false;
		}
		if (IsEmpty() == true) {       //�ƿ� ����ִ� �����̶�� 
			m_pHead = pNode;       //�ҷ��� ��带 head�� tail�� ����Ű���� ���ش�.
			m_pTail = pNode;
		}
		else {                          //�� �� ������ ��� �ƴ϶��
			m_pTail->SetNext(pNode);        //tail�ڿ� �ҷ��� ��带 �߰����ش�.
			m_pTail = pNode;               //tail�� �ҷ��� ���� �Ű��ش�. 
		}
		m_NumElement++;         //����� ������ 1 �߰����ش�.
		return true;            //�� �ֱⰡ ���������� ��ȯ���ش�.
	}
	Node* Stack::Pop() {        //�����͸� �������ִ� �Լ�
		if (IsEmpty() == true) {        //����ִٸ� nullptr ��ȯ
			return nullptr;
		}
		Node* temp = m_pTail;			//temp�� �� ��带 ����Ű���� ��
		if (m_pHead == m_pTail) {		//���� ù��尡 ������ �����
			m_pHead = nullptr;			//�� ������ ��� nullptr�� ����Ű���� ��
			m_pTail = nullptr;
		}
		else {							//�ƴ϶��
			Node* Present_Tail = m_pHead;				//������Ǽ� ��ĭ �� ��带 ����ų ������ ����
			while (Present_Tail->GetNext()!= m_pTail) {	//����带 ����Ű���� �ݺ���(���� ��尡 ����尡 �ƴҶ�����)
				Present_Tail = Present_Tail->GetNext();	//���� ���� �Ѿ��
			}
			m_pTail = Present_Tail;		//�� ���� ������� ���� ���� �ٲ���
			m_pTail->SetNext(nullptr);	//�� ��带 ����Ű�� ���� ������
		}
		m_NumElement--;				//��� ���� 1 ����
		return temp;				//temp�� ��ȯ
	}
	void Stack::PrintStack() {              //���ÿ� ����ִ� ��� �����͸� ������ִ� �Լ�
		Node* current = m_pHead;            //current�Լ� ���� �� ó�� ��带 ����Ű���� ��
		while (current != nullptr) {       //current�� nullptr�� �ƴҶ����� �ݺ����� �ݺ�
			std::cout << current->GetData() << " ";     //���� ����� �����͸� ���
			current = current->GetNext();       //���� ��带 ����Ŵ
		}
	}
}