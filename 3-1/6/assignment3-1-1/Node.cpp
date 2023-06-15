#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Node.h"

int my_strcmp(const char* str1,const char* str2)
{
	//�Ű������� const ������ �޾ƿԱ⶧���� �� ���ڿ� �����Ҵ� �� �����ؼ� ��
	char* str1_ = new char[strlen(str1)];
	char* str2_ = new char[strlen(str2)];
	strcpy(str1_, str1);
	strcpy(str2_, str2);

	int i = 0; //���ڿ��� ÷�� ����

	while (i <= strlen(str1) || i <= strlen(str2))
	{
		//�빮�ڸ� �ҹ��ڷ� �ٲ㼭 ��
		if (str1_[i] >= 65 && str1_[i] <= 90)
			str1_[i] += 32;
		if (str2_[i] >= 65 && str2_[i] <= 90)
			str2_[i] += 32;

		// ù��° ���ڿ��� �տ� �;��ϸ� ���� ��ȯ
		// �ι�° ���ڿ��� �տ� �;��ϸ� ��� ��ȯ
		if (str1_[i] != str2_[i]) {
			if (str1_[i] - str2_[i] > 0)
				return 1;
			else if (str1_[i] - str2_[i] < 0)
				return -1;
		}
		i++;
	}

	// ù��° ���ڿ��� �ι�° ���ڿ��� ������ 0 ��ȯ
	return 0;
}
/*

	Node

*/
void Node::setKey(char* key)
{
	// ������� key �����Ҵ� �� key�� ����
	this->key = new char[strlen(key) + 1];
	strcpy(this->key, key);
}

void Node::setNext(Node* pNext)
{
	// ������� pNext�� �Ű����� pNext�� �ֱ�
	this->pNext = pNext;
}

char* Node::getKey()
{
	//������� key ��ȯ
	return key;
}

Node* Node::getNext()
{
	//������� pNext ��ȯ
	return pNext;
}



/*

	LinkedList

*/
bool LinkedList::add(char* key)
{
	//node ���� �� key�� �ֱ�
	Node* pNew = new Node;
	if (pNew == nullptr)
		return false;
	pNew->setKey(key);
	cnt_node++;
	pPre = this->pHead;

	// ��带 ù��° ������ ������ ���
	if (pPre == nullptr ) { // ����� ������ 0���� ��
		pNew->setNext(this->pHead);	//pHead�� ����Ű�� �ִ� ��带 �� ��尡 ����Ű�� ��
		this->pHead = pNew; // pHead�� �� ��带 ����Ű�� ��
		return true; 
	}
	if (my_strcmp(key, pPre->getKey()) < 0) { // ������ ��尡 ù��° ��庸�� ���� �־�� �� ��
		pNew->setNext(this->pHead); //pHead�� ����Ű�� �ִ� ��带 �� ��尡 ����Ű�� ��
		this->pHead = pNew; //pHead�� �� ��带 ��Ű���� ��
		return true;
	}

	// pPre�� pCur�� shift�ϸ鼭 ��� ������ �� ã��
	pCur = pPre->getNext();
	while (pCur)
	{
		// ������ ��ġ ã�� ��� �ݺ��� Ż��
		if (my_strcmp(key, pCur->getKey()) <= 0)
			break;
		else {
			//shift
			pPre = pCur;
			pCur = pCur->getNext();
		}
	}
	// ��� ����
	pNew->setNext(pCur);
	pPre->setNext(pNew);


	return true;
}

void LinkedList::print()
{
	pCur = pHead;
	pPre = nullptr;
	// ��� �ϳ� ��� �� pPre�� pCur shift
	while (pCur) {
		std::cout << pCur->getKey() << " ";
		pPre = pCur;
		pCur = pCur->getNext();
	}
	std::cout << std::endl;
}

void LinkedList::compare(LinkedList* p1, LinkedList* p2, LinkedList* p3)
{
	pCur = pHead; 
	pPre = nullptr; 

	Node* p1_cur = p1->pHead; // p1�� ���� ��� ����Ű�� ����
	Node* p2_cur = p2->pHead; // p2�� ���� ��� ����Ű�� ����
	Node* p1_pre = nullptr; // p1�� ���� ��� �� ��� ����Ű�� ����
	Node* p2_pre = nullptr; // p2�� ���� ��� �� ��� ����Ű�� ����

	while (p1_cur != nullptr || p2_cur != nullptr) // p1�� p2�� ��� ����� �񱳸� ������ Ż��
	{
		if (p1_cur == nullptr) { // p1�� ������ �񱳸� ���°� p2�� ��尡 ���� ���
			//p3�� p2�� �����ִ� ��� �߰� �� p2�� ��� ����
			p3->add(p2_cur->getKey());
			p2_pre = p2_cur;
			p2_cur = p2_cur->getNext();
			//p2 ��� ����
			p2->del(p2_pre->getKey());

		}
		else if (p2_cur == nullptr) { //p2�� ������ �񱳸� ���°� p1�� ��尡 ���� ���
			//p3�� p1�� �����ִ� ��� �߰� �� p1�� ��� ����
			p3->add(p1_cur->getKey());
			p1_pre = p1_cur;
			p1_cur = p1_cur->getNext();
			p1->del(p1_pre->getKey());

		}
		else {
			//p1�� ��尡 p2�� ��庸�� ���� �;��ϴ� ���
			if (my_strcmp(p1_cur->getKey(), p2_cur->getKey()) < 0) {
				//p3�� p1�� ��� �߰� �� p1���� shift
				p3->add(p1_cur->getKey());
				p1_pre = p1_cur;
				p1_cur = p1_cur->getNext();
				//p1 ��� ����
				p1->del(p1_pre->getKey());
		
			}
			//p2�� ��尡 p1�� ��庸�� ���� �;��ϴ� ���
			else if (my_strcmp(p1_cur->getKey(), p2_cur->getKey()) > 0) {
				//p3�� p2�� ��� �߰� �� p2���� shift
				p3->add(p2_cur->getKey());
				p2_pre = p2_cur;
				p2_cur = p2_cur->getNext();
				//p2 ��� ����
				p2->del(p2_pre->getKey());

			}
			//p1�� ���� p2�� ����� key���� ���� ���
			else {
				//p3�� p1, p2�� ��� �߰� �� p1,p2���� shift
				p3->add(p1_cur->getKey());
				p3->add(p2_cur->getKey());
				p1_pre = p1_cur;
				p1_cur = p1_cur->getNext();
				//p1 ��� ����
				p1->del(p1_pre->getKey());

				p2_pre = p2_cur;
				p2_cur = p2_cur->getNext();
				//p2 ��� ����
				p2->del(p2_pre->getKey());
	
			}
		}
	}
}

bool LinkedList::del(char* key)
{
	pCur = this->pHead; // ���� ��� ����Ű�� ����
	pPre = nullptr; //������� �� ��� ����Ű�� ����

	//��ȸ�ϸ� ���� ��� ã��
	while (pCur)
	{
		// �Ű������� ���� key���� ����� key���� ������ (������ ��带 ã������) �ݺ��� Ż��
		if (strcmp(pCur->getKey(), key) == 0)
			break;
		//shift
		pPre = pCur;
		pCur = pCur->getNext();
	}
	//pCur�� ��ȸ ������ nullptr�̸� ����
	if (pCur == nullptr)
		return false;

	if (pCur == pHead) 	//ù��° ��� �����ϴ� ���
		this->pHead = pCur->getNext();
	else
		pPre->setNext(pCur->getNext());

	delete pCur; //����
	return true;
}

void LinkedList::nullcheck()
{
	//pHead�� ����Ű�� ��尡 ������ "NULL" ���
	if (pHead == nullptr)
		std::cout << "NULL" << std::endl;
}