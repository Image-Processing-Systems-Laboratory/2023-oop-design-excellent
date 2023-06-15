#include "DoublyLinkedList.h"
#include <iostream>

//member function of Score class
Score::Score()                                  //멤버 변수를 초기화 하는 생성자
{
	m_pNext = nullptr;
	m_pPrev = nullptr;
	m_Avg = 0;
}

Score::~Score()                                 //파괴자
{
	m_pNext = nullptr;
	m_pPrev = nullptr;
	m_Avg = 0;
}

void Score::SetAvg(double avg)                  //과목 평균 설정
{
	m_Avg = avg;
}

void Score::SetNext(Score* pNext)               //다음 노드 연결
{
	m_pNext = pNext;
}

void Score::SetPrev(Score* pPrev)               //이전 노드 연결
{
	m_pPrev = pPrev;
}

double Score::GetAvg()                          //과목 평균 반환
{
	return m_Avg;
}

Score* Score::GetNext()                         //다음 노드의 주소 반환
{
	return m_pNext;
}

Score* Score::GetPrev()                         //이전 노드의 주소 반환
{
	return m_pPrev;
}


//member function of StudentScoreList class
StudentScoreList::StudentScoreList()                       //멤버 변수를 초기화하는 생성자
{
	m_pHead = nullptr;
	m_pTail = nullptr;
}

StudentScoreList::~StudentScoreList()                      //노드에 할당된 메모리를 해제하는 파괴자
{
	Score* pPre = nullptr;        //이전 노드

	//m_pHead가 nullptr에 도달할 때까지 메모리 해제
	while (m_pHead != nullptr) {
		pPre = m_pHead;
		m_pHead = m_pHead->GetNext();  //다음 노드로 이동

		delete pPre;
	}
}

void StudentScoreList::Insert(Score* pScore)               //새로운 노드를 오름차순으로 정렬하며 추가
{
	if (m_pHead != nullptr && m_pTail != nullptr) {  //첫 번째 노드 추가가 아닌 경우
		Score* pCur = m_pHead;

		while (pCur != nullptr) {
			if (pCur->GetAvg() > pScore->GetAvg()) { //Doubly Linked List 중 m_Avg 값이 더 큰 노드를 만나면 그 이전에 새로운 노드 추가 
				if (pCur == m_pHead) {            //첫 번째 노드 이전에 추가할 경우
					pScore->SetNext(m_pHead);  //새로운 노드의 Next pointer -> 기존의 첫 번째 노드
					m_pHead->SetPrev(pScore);  //기존의 첫번째 노드의 Prev pointer -> 새로운 노드
					m_pHead = pScore;          //Head pointer -> 새로운 노드
				}
				else {                            //중간에 노드를 추가할 경우
					pCur->GetPrev()->SetNext(pScore);   //pCur의 이전 노드의 Next pointer -> 새로운 노드
					pScore->SetPrev(pCur->GetPrev());   //새로운 노드의 Prev pointer -> pCur의 이전 노드
					pCur->SetPrev(pScore);              //pCur의 Prev pointer -> 새로운 노드
					pScore->SetNext(pCur);              //새로운 노드의 Next pointer -> pCur
				}

				return;
			}

			pCur = pCur->GetNext();       //다음 노드로 이동
		}

		/*while 반복문이 끝날 때까지 노드 추가를 하지 않아 함수가 종료되지 않으면
		새로운 노드의 m_Avg 값이 가장 큰 것이므로 가장 마지막에 노드 추가*/
		m_pTail->SetNext(pScore);     //기존의 마지막 노드의 Next pointer -> 새로운 노드
		pScore->SetPrev(m_pTail);     //새로운 노드의 Prev pointer -> 기존의 마지막 노드
		m_pTail = pScore;             //Tail pointer -> 새로운 노드
	}
	else {                                           //첫 번째 노드 추가인 경우
		m_pHead = pScore;
		m_pTail = pScore;
	}

	return;
}

void StudentScoreList::PrintList(bool isAscending)         //오름차순(isAscending == true) 또는 내림차순(isAscending == false)으로 Linked List의 모든 노드를 출력
{
	Score* pCur;

	if (isAscending) {       //오름차순으로 출력 (첫 번째 노드 -> 마지막 노드)
		pCur = m_pHead;

		//마지막 노드에 도달할 때까지 각 노드의 m_Avg 값 출력
		while (pCur != nullptr) {
			std::cout << pCur->GetAvg() << std::endl;
			pCur = pCur->GetNext();  //다음 노드로 이동
		}
	}
	else {                   //내림차순으로 출력 (마지막 노드 -> 첫 번째 노드)
		pCur = m_pTail;

		//첫 번째 노드에 도달할 때까지 각 노드의 m_Avg 값 출력
		while (pCur != nullptr) {
			std::cout << pCur->GetAvg() << std::endl;
			pCur = pCur->GetPrev();   //이전 노드로 이동
		}
	}
}