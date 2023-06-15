#include "DoublyLinkedList.h"
#include <iostream>

//member function of Score class
Score::Score()                                  //��� ������ �ʱ�ȭ �ϴ� ������
{
	m_pNext = nullptr;
	m_pPrev = nullptr;
	m_Avg = 0;
}

Score::~Score()                                 //�ı���
{
	m_pNext = nullptr;
	m_pPrev = nullptr;
	m_Avg = 0;
}

void Score::SetAvg(double avg)                  //���� ��� ����
{
	m_Avg = avg;
}

void Score::SetNext(Score* pNext)               //���� ��� ����
{
	m_pNext = pNext;
}

void Score::SetPrev(Score* pPrev)               //���� ��� ����
{
	m_pPrev = pPrev;
}

double Score::GetAvg()                          //���� ��� ��ȯ
{
	return m_Avg;
}

Score* Score::GetNext()                         //���� ����� �ּ� ��ȯ
{
	return m_pNext;
}

Score* Score::GetPrev()                         //���� ����� �ּ� ��ȯ
{
	return m_pPrev;
}


//member function of StudentScoreList class
StudentScoreList::StudentScoreList()                       //��� ������ �ʱ�ȭ�ϴ� ������
{
	m_pHead = nullptr;
	m_pTail = nullptr;
}

StudentScoreList::~StudentScoreList()                      //��忡 �Ҵ�� �޸𸮸� �����ϴ� �ı���
{
	Score* pPre = nullptr;        //���� ���

	//m_pHead�� nullptr�� ������ ������ �޸� ����
	while (m_pHead != nullptr) {
		pPre = m_pHead;
		m_pHead = m_pHead->GetNext();  //���� ���� �̵�

		delete pPre;
	}
}

void StudentScoreList::Insert(Score* pScore)               //���ο� ��带 ������������ �����ϸ� �߰�
{
	if (m_pHead != nullptr && m_pTail != nullptr) {  //ù ��° ��� �߰��� �ƴ� ���
		Score* pCur = m_pHead;

		while (pCur != nullptr) {
			if (pCur->GetAvg() > pScore->GetAvg()) { //Doubly Linked List �� m_Avg ���� �� ū ��带 ������ �� ������ ���ο� ��� �߰� 
				if (pCur == m_pHead) {            //ù ��° ��� ������ �߰��� ���
					pScore->SetNext(m_pHead);  //���ο� ����� Next pointer -> ������ ù ��° ���
					m_pHead->SetPrev(pScore);  //������ ù��° ����� Prev pointer -> ���ο� ���
					m_pHead = pScore;          //Head pointer -> ���ο� ���
				}
				else {                            //�߰��� ��带 �߰��� ���
					pCur->GetPrev()->SetNext(pScore);   //pCur�� ���� ����� Next pointer -> ���ο� ���
					pScore->SetPrev(pCur->GetPrev());   //���ο� ����� Prev pointer -> pCur�� ���� ���
					pCur->SetPrev(pScore);              //pCur�� Prev pointer -> ���ο� ���
					pScore->SetNext(pCur);              //���ο� ����� Next pointer -> pCur
				}

				return;
			}

			pCur = pCur->GetNext();       //���� ���� �̵�
		}

		/*while �ݺ����� ���� ������ ��� �߰��� ���� �ʾ� �Լ��� ������� ������
		���ο� ����� m_Avg ���� ���� ū ���̹Ƿ� ���� �������� ��� �߰�*/
		m_pTail->SetNext(pScore);     //������ ������ ����� Next pointer -> ���ο� ���
		pScore->SetPrev(m_pTail);     //���ο� ����� Prev pointer -> ������ ������ ���
		m_pTail = pScore;             //Tail pointer -> ���ο� ���
	}
	else {                                           //ù ��° ��� �߰��� ���
		m_pHead = pScore;
		m_pTail = pScore;
	}

	return;
}

void StudentScoreList::PrintList(bool isAscending)         //��������(isAscending == true) �Ǵ� ��������(isAscending == false)���� Linked List�� ��� ��带 ���
{
	Score* pCur;

	if (isAscending) {       //������������ ��� (ù ��° ��� -> ������ ���)
		pCur = m_pHead;

		//������ ��忡 ������ ������ �� ����� m_Avg �� ���
		while (pCur != nullptr) {
			std::cout << pCur->GetAvg() << std::endl;
			pCur = pCur->GetNext();  //���� ���� �̵�
		}
	}
	else {                   //������������ ��� (������ ��� -> ù ��° ���)
		pCur = m_pTail;

		//ù ��° ��忡 ������ ������ �� ����� m_Avg �� ���
		while (pCur != nullptr) {
			std::cout << pCur->GetAvg() << std::endl;
			pCur = pCur->GetPrev();   //���� ���� �̵�
		}
	}
}