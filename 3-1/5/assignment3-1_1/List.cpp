#include "List.h"
#include <iostream>

//(Node Class)생성자
Node::Node()
{
	key = nullptr;
	pNext = nullptr;
}

//(Node Class)파괴자
Node::~Node()
{
	delete[] key;           //key가 가리키는 메모리 해제
}

//(Node Class)Key 설정 함수
void Node::setKey(char* key)
{
	this->key = new char[100];  //char 자료형 배열 동적 할당

	int i = 0;

	//값 복사하여 저장
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

//(Node Class)Link 설정 함수
void Node::setNext(Node* pNext)
{
	this->pNext = pNext;
}

//(Node Class)Key 반환 함수
char* Node::getKey()
{
	return key;
}

//(Node Class)Link 반환 함수
Node* Node::getNext()
{
	return pNext;
}


//(Linked List Class)생성자
LinkedList::LinkedList()
{
	pHead = nullptr;
}

//(Linked List Class)파괴자
LinkedList::~LinkedList()
{
	pHead = nullptr;
}

//(Linked List Class)Node 추가 함수
bool LinkedList::add(char* key)
{
	Node* pNew = new Node;       //새로운 Node 할당
	if (pNew == nullptr)
	{
		return false;            //할당 실패
	}

	pNew->setKey(key);           //key 설정

	if (pHead == nullptr)        //처음 Node를 추가할 경우
	{
		pNew->setNext(pHead);
		pHead = pNew;
	}
	else
	{
		Node* pCur = pHead;      //Node 탐색 위치
		Node* pPre = nullptr;    //pCur 이전 Node

		int index;                      //첨자
		char ch_Cur, ch_New;            //문자를 임시 저장할 변수

		//알파벳 순서로 정렬하기 위해 알맞은 위치 찾기
		while (pCur != nullptr)
		{
			index = -1;
			
			do {
				index++;                               //다음 문자로 이동

				ch_Cur = pCur->getKey()[index];        //pCur의 문자 임시 저장
				if (ch_Cur >= 'A' && ch_Cur <= 'Z')    //대문자인 경우 소문자로 변환
				{
					ch_Cur = ch_Cur + ('a' - 'A');
				}

				ch_New = pNew->getKey()[index];        //pNew의 문자 임시 저장
				if (ch_New >= 'A' && ch_New <= 'Z')    //대문자인 경우 소문자로 변환
				{
					ch_New = ch_New + ('a' - 'A');
				}

				if (ch_Cur == '\0' && ch_New == '\0')   //두 문자열이 일치하는 경우
				{
					break;
				}
			} while (ch_Cur == ch_New);                 //같은 문자인 경우 다음 문자로 이동
			
			//pCur 문자의 아스키 코드 값이 더 크거나 두 문자열이 일치하는 경우
			if ((ch_Cur > ch_New) || (ch_Cur == '\0' && ch_New == '\0'))
			{
				if (ch_Cur == '\0' && ch_New == '\0')   //두 문자열이 일치하는 경우 해당 노드 다음에 새로운 노드 추가
				{
					pNew->setNext(pCur->getNext());
					pCur->setNext(pNew);
				}
				else
				{
					if (pCur == pHead) //첫 번째 노드 앞에 추가할 경우
					{
						pNew->setNext(pCur);
						pHead = pNew;
					}
					else               //중간 부분에 추가할 경우 해당 노드와 이전 노드 사이에 새로운 노드 추가
					{
						pNew->setNext(pPre->getNext());
						pPre->setNext(pNew);
					}
				}
				return true;
			}

			//다음 노드로 이동
			pPre = pCur;
			pCur = pCur->getNext();
		}

		//맨 마지막에 새로운 노드를 추가
		pNew->setNext(pPre->getNext());
		pPre->setNext(pNew);

	}

	return true;
}

//(Linked List Class)pHead 반환 함수
Node* LinkedList::get_pHead()
{
	return pHead;
}

//(Linked List Class)pHead 설정 함수
void LinkedList::set_pHead(Node* p)
{
	pHead = p;
}

//Linked List 출력 함수
void LinkedList::print()
{
	Node* pCur = pHead;

	while (pCur != nullptr)
	{
		std::cout << pCur->getKey() << ' ';      //키 값 출력
		pCur = pCur->getNext();                  //다음 노드로 이동
	}
}


//p1과 p2를 정렬하며 합쳐 p3를 구성하는 함수
Node* Merge_List(Node* p1, Node* p2, Node* p3)
{
	Node* pPre1 = nullptr;      //p1 이전 노드
	Node* pPre2 = nullptr;      //p2 이전 노드
	Node* pPre3 = nullptr;      //p3 이전 노드

	Node* pNew;                 //p3의 새로운 노드

	char ch1, ch2;

	//p1과 p2를 오름차순으로 정렬하여 p3에 저장(두 List 중 하나가 끝에 도달할 때까지 반복)
	while (p1 != nullptr && p2 != nullptr)
	{
		int index = 0;          //첨자

		while (1)
		{
			ch1 = p1->getKey()[index];     //p1 문자 임시 저장
			if (ch1 >= 'A' && ch1 <= 'Z')       //대문자인 경우 소문자로 변환
			{
				ch1 = ch1 + ('a' - 'A');
			}

			ch2 = p2->getKey()[index];     //p2 문자 임시 저장
			if (ch2 >= 'A' && ch2 <= 'Z')       //대문자인 경우 소문자로 변환
			{
				ch2 = ch2 + ('a' - 'A');
			}

			//두 문자가 일치하지 않거나 두 문자열이 모두 끝에 도달했을 경우
			if ((ch1 != ch2) || (ch1 == '\0' && ch2 == '\0'))
			{
				pNew = new Node;                 //동적 할당
				if (pNew == nullptr)
				{
					//각각 메모리 해제
					free_LinkedList(p1);
					free_LinkedList(p2);
					free_LinkedList(p3);

					return nullptr;
				}

				if (ch1 < ch2)                       //p1의 아스키코드 값이 더 작은 경우
				{
					pNew->setKey(p1->getKey());
					pPre1 = p1;
					p1 = p1->getNext();              //p1을 다음 노드로 이동

					delete pPre1;                    //메모리 해제
				}
				else if (ch1 > ch2)                  //p2의 아스키코드 값이 더 작은 경우
				{
					pNew->setKey(p2->getKey());
					pPre2 = p2;
					p2 = p2->getNext();              //p2를 다음 노드로 이동

					delete pPre2;                    //메모리 해제
				}
				else                                 //p1과 p2가 같은 문자열일 경우
				{
					//p1 값을 p3에 저장
					pNew->setKey(p1->getKey());
					pNew->setNext(nullptr);
					pPre1 = p1;
					p1 = p1->getNext();              //p1을 다음 노드로 이동
					delete pPre1;

					if (p3 == nullptr)               //첫 번째 노드인 경우
					{
						p3 = pNew;
						pPre3 = pNew;
					}
					else
					{
						pPre3->setNext(pNew);        //이전 노드와 연결
						pPre3 = pNew;
					}

					//p2 값을 p3에 저장
					pNew = new Node;                 //동적 할당
					if (pNew == nullptr)
					{
						//각각 메모리 해제
						free_LinkedList(p1);
						free_LinkedList(p2);
						free_LinkedList(p3);

						return nullptr;
					}

					pNew->setKey(p2->getKey());
					pPre2 = p2;
					p2 = p2->getNext();              //p2를 다음 노드로 이동
					delete pPre2;
				}

				pNew->setNext(nullptr);

				if (p3 == nullptr)               //첫 번째 노드인 경우
				{
					p3 = pNew;
					pPre3 = pNew;
				}
				else
				{
					pPre3->setNext(pNew);        //이전 노드와 연결
					pPre3 = pNew;
				}

				break;
			}

			index++;
		}
	}

	//p1이 끝나지 않은 경우 반복
	while (p1 != nullptr)
	{
		pNew = new Node;                 //동적 할당
		if (pNew == nullptr)
		{
			//각각 메모리 해제
			free_LinkedList(p1);
			free_LinkedList(p2);
			free_LinkedList(p3);

			return nullptr;
		}

		pNew->setKey(p1->getKey());
		pNew->setNext(nullptr);
		pPre1 = p1;
		p1 = p1->getNext();              //p1을 다음 노드로 이동

		delete pPre1;                    //메모리 해제

		if (p3 == nullptr)               //첫 번째 노드인 경우
		{
			p3 = pNew;
			pPre3 = pNew;
		}
		else
		{
			pPre3->setNext(pNew);        //이전 노드와 연결
			pPre3 = pNew;
		}
	}

	//p2이 끝나지 않은 경우 반복
	while (p2 != nullptr)
	{
		pNew = new Node;                 //동적 할당
		if (pNew == nullptr)
		{
			//각각 메모리 해제
			free_LinkedList(p1);
			free_LinkedList(p2);
			free_LinkedList(p3);

			return nullptr;
		}

		pNew->setKey(p2->getKey());
		pNew->setNext(nullptr);
		pPre2 = p2;
		p2 = p2->getNext();              //p1을 다음 노드로 이동

		delete pPre2;                    //메모리 해제

		if (p3 == nullptr)               //첫 번째 노드인 경우
		{
			p3 = pNew;
			pPre3 = pNew;
		}
		else
		{
			pPre3->setNext(pNew);        //이전 노드와 연결
			pPre3 = pNew;
		}
	}

	return p3;
}

//Linked List 메모리 해제 함수
void free_LinkedList(Node* p)
{
	if (p != nullptr)       //p가 가리키는 노드가 존재할 경우
	{
		Node* pCur = p;
		Node* pPre = nullptr;

		//모든 노드 메모리 해제
		while (pCur)
		{
			pPre = pCur;
			pCur = pCur->getNext();
			delete pPre;
		}
	}
}