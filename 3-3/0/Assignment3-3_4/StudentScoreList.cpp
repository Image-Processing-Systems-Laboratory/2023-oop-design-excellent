#include "StudentScoreList.h"


//����Ʈ ������
Score::Score() {
	//���� �ʱ�ȭ
	this->m_Avg = 0;
	this->m_pNext = nullptr;
	this->m_pPrev = nullptr;
}
//�Ҹ���
Score::~Score() {}

//��հ� �����ϴ� �Լ�
void Score::SetAvg(double avg) {
	this->m_Avg = avg;				//��հ� ����
}
//������ �����ϴ� �Լ�
void Score::SetNext(Score* pNext) {
	this->m_pNext = pNext;			//���� �ּ� ����
}
//������ �����ϴ� �Լ�
void Score::SetPrev(Score* pPrev) {
	this->m_pPrev = pPrev;			//���� �ּ� ����
}

//��հ��� ��ȯ�ϴ� �Լ�
double Score::GetAvg() {
	return this->m_Avg;				//��հ� ��ȯ
}
//���� �ּҸ� ��ȯ�ϴ� �Լ�
Score* Score::GetNext() {
	return this->m_pNext;			//���� �ּ� ��ȯ
}
//���� �ּҸ� ��ȯ�ϴ� �Լ�
Score* Score::GetPrev() {
	return this->m_pPrev;			//���� �ּ� ��ȯ
}


//����Ʈ ������
StudentScoreList::StudentScoreList() {
	//���� �ʱ�ȭ
	this->m_pHead = nullptr;
	this->m_pTail = nullptr;
}
//�Ҹ���
StudentScoreList::~StudentScoreList() {}

//Score�� �߰���  �������ִ� �Լ�
void StudentScoreList::Insert(Score* pScore) {

	//m_pHead�� NULL�̶��
	if (this->m_pHead == NULL) {
		this->m_pHead = pScore;		//pScore�� �ּ� ����
		this->m_pTail = pScore;		//pScore�� �ּ� ����
		return;
	}
	Score* pCur = this->m_pHead;

	//Null�� ������ ������ �ݺ�
	while (pCur) {
		if (pCur->GetAvg() > pScore->GetAvg())
		{
			//�� �տ� ����
			if (pCur == this->m_pHead)
			{
				pScore->SetNext(this->m_pHead);		//pScore�� ������ m_pHead�� ����
				this->m_pHead->SetPrev(pScore);		//m_pHead�� ������ pScore�� ����
				this->m_pHead = pScore;		//pScore�� �ּ� ����
				return;
			}
			//�߰��� ����
			else {
				pScore->SetNext(pCur);				//pScore�� ������ pCur�� ����
				pScore->SetPrev(pCur->GetPrev());	//pScore�� ������ pCur �������� ����
				pCur->GetPrev()->SetNext(pScore);	//pCur�� ������ ������ pScore�� ����
				pCur->SetPrev(pScore);				//pCur�� ������ pScore�� ����
				return;
			}
		}
		pCur = pCur->GetNext();						//pCur�� ���� �ּ� ����
	}
	//���� ����
	this->m_pTail->SetNext(pScore);			//m_pTail�� ������ pScore�� ����
	pScore->SetPrev(this->m_pTail);			//pScore�� ������ m_pTail����
	this->m_pTail = pScore;					//m_pTail�ּҿ� pScore �ּ�����
	return;
}

//�������� �Ǵ� ������������ ������ִ� �Լ�
void StudentScoreList::PrintList(bool isAscending) {

	if (isAscending == 1)			//���������϶�
	{
		Score* pCur = this->m_pHead;	//�Ǿ� �ּ� ����

		//�Ǿտ������� NULL�� ������ ������ �ݺ�
		while (pCur) {
			std::cout << pCur->GetAvg() << " ";
			pCur = pCur->GetNext();
		}
	}
	else {							//���������϶�
		Score* pCur = this->m_pTail;	//�ǳ� �ּ� ����

		//�ǳ��������� NULL�� ������ ������ �ݺ�
		while (pCur) {
			std::cout << pCur->GetAvg() << " ";
			pCur = pCur->GetPrev();
		}
	}
	
	std::cout << std::endl;
}
