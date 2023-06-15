#include "Score.h"

using namespace std;

StudentScoreList::StudentScoreList() : m_pHead(nullptr), m_pTail(nullptr) { };

StudentScoreList::~StudentScoreList()
{
    Score* pNode = m_pHead;
    while (pNode != nullptr)
    {
        Score* pNext = pNode->GetNext();
        delete pNode;
        pNode = pNext;
    }
};

void StudentScoreList::Insert(Score* pScore)
{
	if (m_pHead == nullptr) // 처음 넣는 경우
	{
		m_pHead = pScore;
		m_pTail = pScore;
	}
	else // 처음 넣는 게 아닌 경우
	{
        Score* pCurrent = m_pHead;
		Score* pPrev = nullptr;

		// 새로 들어갈 Score Node의 위치 찾기
		while (pCurrent != nullptr && pCurrent->GetAvr() < pScore->GetAvr()) 
		{
			pPrev = pCurrent;
			pCurrent = pCurrent->GetNext();
		}

        // 찾은 위치를 바탕으로 삽입
        if (pPrev == nullptr) 
        {
            // 가장 처음에 넣는 경우
            // 즉 Head 정보가 갱신되는 경우
            pScore->SetNext(m_pHead);
            pScore->SetPrev(nullptr);
            m_pHead->SetPrev(pScore);
            m_pHead = pScore;
        }
        else if (pCurrent == nullptr) 
        {
            // 가장 마지막에 넣는 경우
            // 즉 tail 정보가 갱신되는 경우
            pScore->SetNext(nullptr);
            pScore->SetPrev(m_pTail);
            m_pTail->SetNext(pScore);
            m_pTail = pScore;
        }
        else 
        {
            // 중간에 넣는 경우
            pScore->SetNext(pCurrent);
            pScore->SetPrev(pPrev);
            pPrev->SetNext(pScore);
            pCurrent->SetPrev(pScore);
        }
	} // 기본적으로 Node는 오름차순으로 정렬된다.
}

void StudentScoreList::printlist(bool isAscending) const
{
    Score* pPrint = isAscending ? m_pHead : m_pTail;
    while (pPrint != nullptr)
    {
        cout << pPrint->GetAvr() << " ";
        pPrint = isAscending ? pPrint->GetNext() : pPrint->GetPrev();
    }
    cout << endl;
}
// isAcending이 True면 오름차순 출력을 원하는 것이므로 m_pHead를 그대로 가져와서 출력한다.
// false면 내림차순 출력을 원하는 것이므로 Tail 정보를 가져온다.
// Tail 정보를 가져온 경우 다음 Node가 Next가 아닌 Prev이므로 이 부분 또한 주의해야 한다.

bool StudentScoreList::islistempty() const { return m_pHead == nullptr ? true : false; };
// m_pHead가 Nullptr인 경우는 리스트가 빈 경우에 해당

Score::Score() : m_pNext(nullptr), m_pPrev(nullptr), m_Avg(0) { };

Score::~Score() { };

void Score::SetNext(Score* pNext) { m_pNext = pNext; };

void Score::SetPrev(Score* pPrev) { m_pPrev = pPrev; };

void Score::SetAvg(double num) { m_Avg = num; };

double Score::GetAvr() const { return m_Avg; };

Score* Score::GetNext() const { return m_pNext; };

Score* Score::GetPrev() const { return m_pPrev; };
