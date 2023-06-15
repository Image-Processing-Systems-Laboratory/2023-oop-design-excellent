#include "List.h"
#include <iostream>

//(Node Class)������
Node::Node()
{
	key = nullptr;
	pNext = nullptr;
}

//(Node Class)�ı���
Node::~Node()
{
	delete[] key;           //key�� ����Ű�� �޸� ����
}

//(Node Class)Key ���� �Լ�
void Node::setKey(char* key)
{
	this->key = new char[100];  //char �ڷ��� �迭 ���� �Ҵ�

	int i = 0;

	//�� �����Ͽ� ����
	while (1)
	{
		this->key[i] = key[i];

		if (key[i] == '\0')
		{
			break;
		}
		i++;
	}
}

//(Node Class)Link ���� �Լ�
void Node::setNext(Node* pNext)
{
	this->pNext = pNext;
}

//(Node Class)Key ��ȯ �Լ�
char* Node::getKey()
{
	return key;
}

//(Node Class)Link ��ȯ �Լ�
Node* Node::getNext()
{
	return pNext;
}


//(Linked List Class)������
LinkedList::LinkedList()
{
	pHead = nullptr;
}

//(Linked List Class)�ı���
LinkedList::~LinkedList()
{
	pHead = nullptr;
}

//(Linked List Class)Node �߰� �Լ�
bool LinkedList::add(char* key)
{
	Node* pNew = new Node;       //���ο� Node �Ҵ�
	if (pNew == nullptr)
	{
		return false;            //�Ҵ� ����
	}

	pNew->setKey(key);           //key ����

	if (pHead == nullptr)        //ó�� Node�� �߰��� ���
	{
		pNew->setNext(pHead);
		pHead = pNew;
	}
	else
	{
		Node* pCur = pHead;      //Node Ž�� ��ġ
		Node* pPre = nullptr;    //pCur ���� Node

		int index;                      //÷��
		char ch_Cur, ch_New;            //���ڸ� �ӽ� ������ ����

		//���ĺ� ������ �����ϱ� ���� �˸��� ��ġ ã��
		while (pCur != nullptr)
		{
			index = -1;
			
			do {
				index++;                               //���� ���ڷ� �̵�

				ch_Cur = pCur->getKey()[index];        //pCur�� ���� �ӽ� ����
				if (ch_Cur >= 'A' && ch_Cur <= 'Z')    //�빮���� ��� �ҹ��ڷ� ��ȯ
				{
					ch_Cur = ch_Cur + ('a' - 'A');
				}

				ch_New = pNew->getKey()[index];        //pNew�� ���� �ӽ� ����
				if (ch_New >= 'A' && ch_New <= 'Z')    //�빮���� ��� �ҹ��ڷ� ��ȯ
				{
					ch_New = ch_New + ('a' - 'A');
				}

				if (ch_Cur == '\0' && ch_New == '\0')   //�� ���ڿ��� ��ġ�ϴ� ���
				{
					break;
				}
			} while (ch_Cur == ch_New);                 //���� ������ ��� ���� ���ڷ� �̵�
			
			//pCur ������ �ƽ�Ű �ڵ� ���� �� ũ�ų� �� ���ڿ��� ��ġ�ϴ� ���
			if ((ch_Cur > ch_New) || (ch_Cur == '\0' && ch_New == '\0'))
			{
				if (ch_Cur == '\0' && ch_New == '\0')   //�� ���ڿ��� ��ġ�ϴ� ��� �ش� ��� ������ ���ο� ��� �߰�
				{
					pNew->setNext(pCur->getNext());
					pCur->setNext(pNew);
				}
				else
				{
					if (pCur == pHead) //ù ��° ��� �տ� �߰��� ���
					{
						pNew->setNext(pCur);
						pHead = pNew;
					}
					else               //�߰� �κп� �߰��� ��� �ش� ���� ���� ��� ���̿� ���ο� ��� �߰�
					{
						pNew->setNext(pPre->getNext());
						pPre->setNext(pNew);
					}
				}
				return true;
			}

			//���� ���� �̵�
			pPre = pCur;
			pCur = pCur->getNext();
		}

		//�� �������� ���ο� ��带 �߰�
		pNew->setNext(pPre->getNext());
		pPre->setNext(pNew);

	}

	return true;
}

//(Linked List Class)pHead ��ȯ �Լ�
Node* LinkedList::get_pHead()
{
	return pHead;
}

//(Linked List Class)pHead ���� �Լ�
void LinkedList::set_pHead(Node* p)
{
	pHead = p;
}

//Linked List ��� �Լ�
void LinkedList::print()
{
	Node* pCur = pHead;

	while (pCur != nullptr)
	{
		std::cout << pCur->getKey() << ' ';      //Ű �� ���
		pCur = pCur->getNext();                  //���� ���� �̵�
	}
}


//p1�� p2�� �����ϸ� ���� p3�� �����ϴ� �Լ�
Node* Merge_List(Node* p1, Node* p2, Node* p3)
{
	Node* pPre1 = nullptr;      //p1 ���� ���
	Node* pPre2 = nullptr;      //p2 ���� ���
	Node* pPre3 = nullptr;      //p3 ���� ���

	Node* pNew;                 //p3�� ���ο� ���

	char ch1, ch2;

	//p1�� p2�� ������������ �����Ͽ� p3�� ����(�� List �� �ϳ��� ���� ������ ������ �ݺ�)
	while (p1 != nullptr && p2 != nullptr)
	{
		int index = 0;          //÷��

		while (1)
		{
			ch1 = p1->getKey()[index];     //p1 ���� �ӽ� ����
			if (ch1 >= 'A' && ch1 <= 'Z')       //�빮���� ��� �ҹ��ڷ� ��ȯ
			{
				ch1 = ch1 + ('a' - 'A');
			}

			ch2 = p2->getKey()[index];     //p2 ���� �ӽ� ����
			if (ch2 >= 'A' && ch2 <= 'Z')       //�빮���� ��� �ҹ��ڷ� ��ȯ
			{
				ch2 = ch2 + ('a' - 'A');
			}

			//�� ���ڰ� ��ġ���� �ʰų� �� ���ڿ��� ��� ���� �������� ���
			if ((ch1 != ch2) || (ch1 == '\0' && ch2 == '\0'))
			{
				pNew = new Node;                 //���� �Ҵ�
				if (pNew == nullptr)
				{
					//���� �޸� ����
					free_LinkedList(p1);
					free_LinkedList(p2);
					free_LinkedList(p3);

					return nullptr;
				}

				if (ch1 < ch2)                       //p1�� �ƽ�Ű�ڵ� ���� �� ���� ���
				{
					pNew->setKey(p1->getKey());
					pPre1 = p1;
					p1 = p1->getNext();              //p1�� ���� ���� �̵�

					delete pPre1;                    //�޸� ����
				}
				else if (ch1 > ch2)                  //p2�� �ƽ�Ű�ڵ� ���� �� ���� ���
				{
					pNew->setKey(p2->getKey());
					pPre2 = p2;
					p2 = p2->getNext();              //p2�� ���� ���� �̵�

					delete pPre2;                    //�޸� ����
				}
				else                                 //p1�� p2�� ���� ���ڿ��� ���
				{
					//p1 ���� p3�� ����
					pNew->setKey(p1->getKey());
					pNew->setNext(nullptr);
					pPre1 = p1;
					p1 = p1->getNext();              //p1�� ���� ���� �̵�
					delete pPre1;

					if (p3 == nullptr)               //ù ��° ����� ���
					{
						p3 = pNew;
						pPre3 = pNew;
					}
					else
					{
						pPre3->setNext(pNew);        //���� ���� ����
						pPre3 = pNew;
					}

					//p2 ���� p3�� ����
					pNew = new Node;                 //���� �Ҵ�
					if (pNew == nullptr)
					{
						//���� �޸� ����
						free_LinkedList(p1);
						free_LinkedList(p2);
						free_LinkedList(p3);

						return nullptr;
					}

					pNew->setKey(p2->getKey());
					pPre2 = p2;
					p2 = p2->getNext();              //p2�� ���� ���� �̵�
					delete pPre2;
				}

				pNew->setNext(nullptr);

				if (p3 == nullptr)               //ù ��° ����� ���
				{
					p3 = pNew;
					pPre3 = pNew;
				}
				else
				{
					pPre3->setNext(pNew);        //���� ���� ����
					pPre3 = pNew;
				}

				break;
			}

			index++;
		}
	}

	//p1�� ������ ���� ��� �ݺ�
	while (p1 != nullptr)
	{
		pNew = new Node;                 //���� �Ҵ�
		if (pNew == nullptr)
		{
			//���� �޸� ����
			free_LinkedList(p1);
			free_LinkedList(p2);
			free_LinkedList(p3);

			return nullptr;
		}

		pNew->setKey(p1->getKey());
		pNew->setNext(nullptr);
		pPre1 = p1;
		p1 = p1->getNext();              //p1�� ���� ���� �̵�

		delete pPre1;                    //�޸� ����

		if (p3 == nullptr)               //ù ��° ����� ���
		{
			p3 = pNew;
			pPre3 = pNew;
		}
		else
		{
			pPre3->setNext(pNew);        //���� ���� ����
			pPre3 = pNew;
		}
	}

	//p2�� ������ ���� ��� �ݺ�
	while (p2 != nullptr)
	{
		pNew = new Node;                 //���� �Ҵ�
		if (pNew == nullptr)
		{
			//���� �޸� ����
			free_LinkedList(p1);
			free_LinkedList(p2);
			free_LinkedList(p3);

			return nullptr;
		}

		pNew->setKey(p2->getKey());
		pNew->setNext(nullptr);
		pPre2 = p2;
		p2 = p2->getNext();              //p1�� ���� ���� �̵�

		delete pPre2;                    //�޸� ����

		if (p3 == nullptr)               //ù ��° ����� ���
		{
			p3 = pNew;
			pPre3 = pNew;
		}
		else
		{
			pPre3->setNext(pNew);        //���� ���� ����
			pPre3 = pNew;
		}
	}

	return p3;
}

//Linked List �޸� ���� �Լ�
void free_LinkedList(Node* p)
{
	if (p != nullptr)       //p�� ����Ű�� ��尡 ������ ���
	{
		Node* pCur = p;
		Node* pPre = nullptr;

		//��� ��� �޸� ����
		while (pCur)
		{
			pPre = pCur;
			pCur = pCur->getNext();
			delete pPre;
		}
	}
}