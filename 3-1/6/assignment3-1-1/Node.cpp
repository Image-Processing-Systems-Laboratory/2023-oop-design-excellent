#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Node.h"

int my_strcmp(const char* str1,const char* str2)
{
	//매개변수로 const 변수를 받아왔기때문데 새 문자열 동적할당 후 복사해서 비교
	char* str1_ = new char[strlen(str1)];
	char* str2_ = new char[strlen(str2)];
	strcpy(str1_, str1);
	strcpy(str2_, str2);

	int i = 0; //문자열의 첨자 접근

	while (i <= strlen(str1) || i <= strlen(str2))
	{
		//대문자면 소문자로 바꿔서 비교
		if (str1_[i] >= 65 && str1_[i] <= 90)
			str1_[i] += 32;
		if (str2_[i] >= 65 && str2_[i] <= 90)
			str2_[i] += 32;

		// 첫번째 문자열이 앞에 와야하면 음수 반환
		// 두번째 문자열이 앞에 와야하면 양수 반환
		if (str1_[i] != str2_[i]) {
			if (str1_[i] - str2_[i] > 0)
				return 1;
			else if (str1_[i] - str2_[i] < 0)
				return -1;
		}
		i++;
	}

	// 첫번째 문자열과 두번째 문자열이 같으면 0 반환
	return 0;
}
/*

	Node

*/
void Node::setKey(char* key)
{
	// 멤버변수 key 동적할당 후 key값 복사
	this->key = new char[strlen(key) + 1];
	strcpy(this->key, key);
}

void Node::setNext(Node* pNext)
{
	// 멤버변수 pNext에 매개변수 pNext값 넣기
	this->pNext = pNext;
}

char* Node::getKey()
{
	//멤버변수 key 반환
	return key;
}

Node* Node::getNext()
{
	//멤버변수 pNext 반환
	return pNext;
}



/*

	LinkedList

*/
bool LinkedList::add(char* key)
{
	//node 생성 및 key값 넣기
	Node* pNew = new Node;
	if (pNew == nullptr)
		return false;
	pNew->setKey(key);
	cnt_node++;
	pPre = this->pHead;

	// 노드를 첫번째 순서에 삽입할 경우
	if (pPre == nullptr ) { // 노드의 개수가 0개일 때
		pNew->setNext(this->pHead);	//pHead가 가리키고 있는 노드를 새 노드가 가리키게 함
		this->pHead = pNew; // pHead가 새 노드를 가리키게 함
		return true; 
	}
	if (my_strcmp(key, pPre->getKey()) < 0) { // 삽입할 노드가 첫번째 노드보다 먼저 있어야 할 때
		pNew->setNext(this->pHead); //pHead가 가리키고 있는 노드를 새 노드가 가리키게 함
		this->pHead = pNew; //pHead가 새 노드를 가키리게 함
		return true;
	}

	// pPre와 pCur를 shift하면서 노드 삽입할 곳 찾기
	pCur = pPre->getNext();
	while (pCur)
	{
		// 삽입할 위치 찾은 경우 반복문 탈출
		if (my_strcmp(key, pCur->getKey()) <= 0)
			break;
		else {
			//shift
			pPre = pCur;
			pCur = pCur->getNext();
		}
	}
	// 노드 삽입
	pNew->setNext(pCur);
	pPre->setNext(pNew);


	return true;
}

void LinkedList::print()
{
	pCur = pHead;
	pPre = nullptr;
	// 노드 하나 출력 후 pPre와 pCur shift
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

	Node* p1_cur = p1->pHead; // p1의 비교할 노드 가리키는 역할
	Node* p2_cur = p2->pHead; // p2의 비교할 노드 가리키는 역할
	Node* p1_pre = nullptr; // p1의 비교할 노드 전 노드 가리키는 역할
	Node* p2_pre = nullptr; // p2의 비교할 노드 전 노드 가리키는 역할

	while (p1_cur != nullptr || p2_cur != nullptr) // p1과 p2의 모든 노드의 비교를 끝내면 탈출
	{
		if (p1_cur == nullptr) { // p1의 노드들은 비교를 끝냈고 p2의 노드가 남은 경우
			//p3에 p2에 남아있는 노드 추가 후 p2의 노드 삭제
			p3->add(p2_cur->getKey());
			p2_pre = p2_cur;
			p2_cur = p2_cur->getNext();
			//p2 노드 삭제
			p2->del(p2_pre->getKey());

		}
		else if (p2_cur == nullptr) { //p2의 노드들은 비교를 끝냈고 p1의 노드가 남은 경우
			//p3에 p1에 남아있는 노드 추가 후 p1의 노드 삭제
			p3->add(p1_cur->getKey());
			p1_pre = p1_cur;
			p1_cur = p1_cur->getNext();
			p1->del(p1_pre->getKey());

		}
		else {
			//p1의 노드가 p2의 노드보다 먼저 와야하는 경우
			if (my_strcmp(p1_cur->getKey(), p2_cur->getKey()) < 0) {
				//p3에 p1의 노드 추가 후 p1에서 shift
				p3->add(p1_cur->getKey());
				p1_pre = p1_cur;
				p1_cur = p1_cur->getNext();
				//p1 노드 삭제
				p1->del(p1_pre->getKey());
		
			}
			//p2의 노드가 p1의 노드보다 먼저 와야하는 경우
			else if (my_strcmp(p1_cur->getKey(), p2_cur->getKey()) > 0) {
				//p3에 p2의 노드 추가 후 p2에서 shift
				p3->add(p2_cur->getKey());
				p2_pre = p2_cur;
				p2_cur = p2_cur->getNext();
				//p2 노드 삭제
				p2->del(p2_pre->getKey());

			}
			//p1의 노드와 p2의 노드의 key값이 같은 경우
			else {
				//p3에 p1, p2의 노드 추가 후 p1,p2에서 shift
				p3->add(p1_cur->getKey());
				p3->add(p2_cur->getKey());
				p1_pre = p1_cur;
				p1_cur = p1_cur->getNext();
				//p1 노드 삭제
				p1->del(p1_pre->getKey());

				p2_pre = p2_cur;
				p2_cur = p2_cur->getNext();
				//p2 노드 삭제
				p2->del(p2_pre->getKey());
	
			}
		}
	}
}

bool LinkedList::del(char* key)
{
	pCur = this->pHead; // 지울 노드 가리키는 역할
	pPre = nullptr; //지울거의 전 노드 가리키는 역할

	//순회하며 지울 노드 찾기
	while (pCur)
	{
		// 매개변수로 받은 key값과 노드의 key값이 같으면 (삭제할 노드를 찾았으면) 반복문 탈출
		if (strcmp(pCur->getKey(), key) == 0)
			break;
		//shift
		pPre = pCur;
		pCur = pCur->getNext();
	}
	//pCur이 순회 전부터 nullptr이면 실패
	if (pCur == nullptr)
		return false;

	if (pCur == pHead) 	//첫번째 노드 삭제하는 경우
		this->pHead = pCur->getNext();
	else
		pPre->setNext(pCur->getNext());

	delete pCur; //삭제
	return true;
}

void LinkedList::nullcheck()
{
	//pHead가 가리키는 노드가 없으면 "NULL" 출력
	if (pHead == nullptr)
		std::cout << "NULL" << std::endl;
}