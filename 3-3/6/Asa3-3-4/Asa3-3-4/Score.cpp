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
	if (m_pHead == nullptr) // ó�� �ִ� ���
	{
		m_pHead = pScore;
		m_pTail = pScore;
	}
	else // ó�� �ִ� �� �ƴ� ���
	{
        Score* pCurrent = m_pHead;
		Score* pPrev = nullptr;

		// ���� �� Score Node�� ��ġ ã��
		while (pCurrent != nullptr && pCurrent->GetAvr() < pScore->GetAvr()) 
		{
			pPrev = pCurrent;
			pCurrent = pCurrent->GetNext();
		}

        // ã�� ��ġ�� �������� ����
        if (pPrev == nullptr) 
        {
            // ���� ó���� �ִ� ���
            // �� Head ������ ���ŵǴ� ���
            pScore->SetNext(m_pHead);
            pScore->SetPrev(nullptr);
            m_pHead->SetPrev(pScore);
            m_pHead = pScore;
        }
        else if (pCurrent == nullptr) 
        {
            // ���� �������� �ִ� ���
            // �� tail ������ ���ŵǴ� ���
            pScore->SetNext(nullptr);
            pScore->SetPrev(m_pTail);
            m_pTail->SetNext(pScore);
            m_pTail = pScore;
        }
        else 
        {
            // �߰��� �ִ� ���
            pScore->SetNext(pCurrent);
            pScore->SetPrev(pPrev);
            pPrev->SetNext(pScore);
            pCurrent->SetPrev(pScore);
        }
	} // �⺻������ Node�� ������������ ���ĵȴ�.
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
// isAcending�� True�� �������� ����� ���ϴ� ���̹Ƿ� m_pHead�� �״�� �����ͼ� ����Ѵ�.
// false�� �������� ����� ���ϴ� ���̹Ƿ� Tail ������ �����´�.
// Tail ������ ������ ��� ���� Node�� Next�� �ƴ� Prev�̹Ƿ� �� �κ� ���� �����ؾ� �Ѵ�.

bool StudentScoreList::islistempty() const { return m_pHead == nullptr ? true : false; };
// m_pHead�� Nullptr�� ���� ����Ʈ�� �� ��쿡 �ش�

Score::Score() : m_pNext(nullptr), m_pPrev(nullptr), m_Avg(0) { };

Score::~Score() { };

void Score::SetNext(Score* pNext) { m_pNext = pNext; };

void Score::SetPrev(Score* pPrev) { m_pPrev = pPrev; };

void Score::SetAvg(double num) { m_Avg = num; };

double Score::GetAvr() const { return m_Avg; };

Score* Score::GetNext() const { return m_pNext; };

Score* Score::GetPrev() const { return m_pPrev; };
