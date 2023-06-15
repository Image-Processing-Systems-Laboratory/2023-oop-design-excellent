#include <iostream>

using namespace std;

class Score {
private:
	Score* m_pNext;
	Score* m_pPrev;
	double m_Avg;

public:
	Score();
	~Score();
	void SetAvg(double avg);
	void SetNext(Score* pNext);
	void SetPrev(Score* pPrev);
	double GetAvg();
	Score* GetNext();
	Score* GetPrev();
};

// Score class�� ������, ���� �ʱ�ȭ
Score::Score():m_pNext(nullptr), m_pPrev(nullptr), m_Avg(0){}
// Score class�� �Ҹ��� 
Score::~Score(){}

// SetAvg() �Լ�  m_Avg�� avg �� ����
void Score::SetAvg(double avg) { m_Avg = avg; }
// SetNext() �Լ� m_pNext�� pNext ����
void Score::SetNext(Score* pNext) { m_pNext = pNext; }
// SetPrev() �Լ� m_pPrev�� pPrev ����
void Score::SetPrev(Score* pPrev) { m_pPrev = pPrev; }
// GetAvg() �Լ� m_Avg���� return
double Score::GetAvg() { return m_Avg; }
// GetNext() �Լ� m_pNext return
Score* Score::GetNext() {	return m_pNext; }
// GetPrev() �Լ� m_pPrev return
Score* Score::GetPrev() { 	return m_pPrev; }

class StudentScoreList {
private:
	Score* m_pHead;
	Score* m_pTail;

public:
	StudentScoreList();
	~StudentScoreList();
	void Insert(Score* pScore);
	void PrintList(bool isAscending);
};

// StudentScoreList class ������, ���� �ʱ�ȭ
StudentScoreList::StudentScoreList():m_pHead(nullptr), m_pTail(nullptr){}
// StudentScoreList class �Ҹ���
StudentScoreList::~StudentScoreList(){
    while (m_pHead != nullptr) {
        Score* pNext = m_pHead->GetNext();
        delete m_pHead;
        m_pHead = pNext;
    }
    m_pTail = nullptr;
}

// StudentScoreList�� Insert() �Լ�
void StudentScoreList::Insert(Score* pScore) {
    // list�� ����ִ��� Ȯ��
    if (m_pHead == nullptr) {
        // ���������  pHead�� pTail pScore�� ����
        m_pHead = pScore;
        m_pTail = pScore;
    }
    // �׷��� �ʴٸ� score�� �� ������ ��ġ ã���ֱ�
    else {
        Score* pCurrent = m_pHead;
        // pCurrent�� avg�� pScore�� avg���� ���� ���϶����� �ݺ�
        while (pCurrent != nullptr && pCurrent->GetAvg() < pScore->GetAvg()) {
            // pCurrent �� ���� ���� ������ ����
            pCurrent = pCurrent->GetNext();
        }
        // ù��°�� ������ ��
        if (pCurrent == m_pHead) {
            // next �����͸�  m_pHead�� ���� 
            // prev �����͸� pScore�� ����
            pScore->SetNext(m_pHead);
            m_pHead->SetPrev(pScore);
            // pScore �������� m_pHead  ����
            m_pHead = pScore;
        }
        // �������� ������ ��
        else if (pCurrent == nullptr) {
            // next �����͸� pScore�� ����
            // prev �����͸� m_pTail�� ����
            m_pTail->SetNext(pScore);
            pScore->SetPrev(m_pTail);
            // pScore�� ����Ű���� m_pTail ����
            m_pTail = pScore;
        }
        // �� ���� �ڸ��� ������ ��
        else {
            // pScore�� prev�� next �����͸� 
            // pCurrent�� score�� prev score�� ����
            pScore->SetPrev(pCurrent->GetPrev());
            pScore->SetNext(pCurrent);
            pCurrent->GetPrev()->SetNext(pScore);
            pCurrent->SetPrev(pScore);
        }
    }
}

// isAscending�� �̿��� ����Ʈ ���
void StudentScoreList::PrintList(bool isAscending) {
    if (isAscending) {
        // ������������ �����ؾ��Ѵٸ�
        // m_pHead�� ���� next�� ���� ���� ���
        Score* pCurrent = m_pHead;
        while (pCurrent != nullptr) {
            cout << pCurrent->GetAvg() << " ";
            pCurrent = pCurrent->GetNext();
        }
    }
    else {
        // ������������ �����ؾ��Ѵٸ�
        // m_pTail�� ���� prev�� ���� ���� ���
        Score* pCurrent = m_pTail;
        while (pCurrent != nullptr) {
            cout << pCurrent->GetAvg() << " ";
            pCurrent = pCurrent->GetPrev();
        }
    }
    cout << endl;
}

int main() {
    StudentScoreList scoreList;

    double scores[][3] = { {85.0, 90.0, 92.0},
                          {90.0, 85.0, 80.0},
                          {78.0, 90.0, 95.0} };

    for (int i = 0; i < 3; i++) {
        double avgScore = (scores[i][0] + scores[i][1] + scores[i][2]) / 3.0;
        Score* score = new Score();
        score->SetAvg(avgScore);

        scoreList.Insert(score);
    }
    
    cout << "isAscending : true " << endl;
    scoreList.PrintList(true);
    cout << "isAscending : false " << endl;
    scoreList.PrintList(false);
        
    return 0;
}
