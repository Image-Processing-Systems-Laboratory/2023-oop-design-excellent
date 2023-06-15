#include "StudentScoreList.h"


//디폴트 생성자
Score::Score() {
	//변수 초기화
	this->m_Avg = 0;
	this->m_pNext = nullptr;
	this->m_pPrev = nullptr;
}
//소멸자
Score::~Score() {}

//평균값 저장하는 함수
void Score::SetAvg(double avg) {
	this->m_Avg = avg;				//평균값 저장
}
//다음을 저장하는 함수
void Score::SetNext(Score* pNext) {
	this->m_pNext = pNext;			//다음 주소 저장
}
//이전을 저장하는 함수
void Score::SetPrev(Score* pPrev) {
	this->m_pPrev = pPrev;			//이전 주소 저장
}

//평균값을 반환하는 함수
double Score::GetAvg() {
	return this->m_Avg;				//평균값 반환
}
//다음 주소를 반환하는 함수
Score* Score::GetNext() {
	return this->m_pNext;			//다음 주소 반환
}
//이전 주소를 반환하는 함수
Score* Score::GetPrev() {
	return this->m_pPrev;			//이전 주소 반환
}


//디폴트 생성자
StudentScoreList::StudentScoreList() {
	//변수 초기화
	this->m_pHead = nullptr;
	this->m_pTail = nullptr;
}
//소멸자
StudentScoreList::~StudentScoreList() {}

//Score를 추가해  연결해주는 함수
void StudentScoreList::Insert(Score* pScore) {

	//m_pHead가 NULL이라면
	if (this->m_pHead == NULL) {
		this->m_pHead = pScore;		//pScore의 주소 저장
		this->m_pTail = pScore;		//pScore의 주소 저장
		return;
	}
	Score* pCur = this->m_pHead;

	//Null을 만나기 전까지 반복
	while (pCur) {
		if (pCur->GetAvg() > pScore->GetAvg())
		{
			//맨 앞에 들어갈때
			if (pCur == this->m_pHead)
			{
				pScore->SetNext(this->m_pHead);		//pScore의 다음을 m_pHead로 저장
				this->m_pHead->SetPrev(pScore);		//m_pHead의 이전을 pScore로 저장
				this->m_pHead = pScore;		//pScore의 주소 저장
				return;
			}
			//중간에 들어갈때
			else {
				pScore->SetNext(pCur);				//pScore의 다음을 pCur로 저장
				pScore->SetPrev(pCur->GetPrev());	//pScore의 이전을 pCur 이전으로 저장
				pCur->GetPrev()->SetNext(pScore);	//pCur의 이전의 다음을 pScore로 저장
				pCur->SetPrev(pScore);				//pCur의 이전을 pScore로 저장
				return;
			}
		}
		pCur = pCur->GetNext();						//pCur에 다음 주소 저장
	}
	//끝에 들어갈때
	this->m_pTail->SetNext(pScore);			//m_pTail의 다음을 pScore로 저장
	pScore->SetPrev(this->m_pTail);			//pScore의 이전을 m_pTail저장
	this->m_pTail = pScore;					//m_pTail주소에 pScore 주소저장
	return;
}

//오름차순 또는 내림차순으로 출력해주는 함수
void StudentScoreList::PrintList(bool isAscending) {

	if (isAscending == 1)			//오름차순일때
	{
		Score* pCur = this->m_pHead;	//맨앞 주소 저장

		//맨앞에서부터 NULL이 나오기 전까지 반복
		while (pCur) {
			std::cout << pCur->GetAvg() << " ";
			pCur = pCur->GetNext();
		}
	}
	else {							//내림차순일때
		Score* pCur = this->m_pTail;	//맨끝 주소 저장

		//맨끝에서부터 NULL이 나오기 전까지 반복
		while (pCur) {
			std::cout << pCur->GetAvg() << " ";
			pCur = pCur->GetPrev();
		}
	}
	
	std::cout << std::endl;
}
