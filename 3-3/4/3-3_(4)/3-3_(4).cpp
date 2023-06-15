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

// Score class의 생성자, 변수 초기화
Score::Score():m_pNext(nullptr), m_pPrev(nullptr), m_Avg(0){}
// Score class의 소멸자 
Score::~Score(){}

// SetAvg() 함수  m_Avg에 avg 값 저장
void Score::SetAvg(double avg) { m_Avg = avg; }
// SetNext() 함수 m_pNext에 pNext 지정
void Score::SetNext(Score* pNext) { m_pNext = pNext; }
// SetPrev() 함수 m_pPrev에 pPrev 지정
void Score::SetPrev(Score* pPrev) { m_pPrev = pPrev; }
// GetAvg() 함수 m_Avg값을 return
double Score::GetAvg() { return m_Avg; }
// GetNext() 함수 m_pNext return
Score* Score::GetNext() {	return m_pNext; }
// GetPrev() 함수 m_pPrev return
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

// StudentScoreList class 생성자, 변수 초기화
StudentScoreList::StudentScoreList():m_pHead(nullptr), m_pTail(nullptr){}
// StudentScoreList class 소멸자
StudentScoreList::~StudentScoreList(){
    while (m_pHead != nullptr) {
        Score* pNext = m_pHead->GetNext();
        delete m_pHead;
        m_pHead = pNext;
    }
    m_pTail = nullptr;
}

// StudentScoreList의 Insert() 함수
void StudentScoreList::Insert(Score* pScore) {
    // list가 비어있는지 확인
    if (m_pHead == nullptr) {
        // 비어있으면  pHead와 pTail pScore로 설정
        m_pHead = pScore;
        m_pTail = pScore;
    }
    // 그렇지 않다면 score가 들어갈 적절한 위치 찾아주기
    else {
        Score* pCurrent = m_pHead;
        // pCurrent의 avg가 pScore의 avg보다 작은 값일때까지 반복
        while (pCurrent != nullptr && pCurrent->GetAvg() < pScore->GetAvg()) {
            // pCurrent 의 값을 다음 값으로 설정
            pCurrent = pCurrent->GetNext();
        }
        // 첫번째에 들어가야할 때
        if (pCurrent == m_pHead) {
            // next 포인터를  m_pHead로 설정 
            // prev 포인터를 pScore로 설정
            pScore->SetNext(m_pHead);
            m_pHead->SetPrev(pScore);
            // pScore 가리도록 m_pHead  설정
            m_pHead = pScore;
        }
        // 마지막에 들어가야할 때
        else if (pCurrent == nullptr) {
            // next 포인터를 pScore로 설정
            // prev 포인터를 m_pTail로 설정
            m_pTail->SetNext(pScore);
            pScore->SetPrev(m_pTail);
            // pScore을 가리키도록 m_pTail 설정
            m_pTail = pScore;
        }
        // 그 외의 자리에 들어가야할 때
        else {
            // pScore의 prev와 next 포인터를 
            // pCurrent의 score과 prev score로 연결
            pScore->SetPrev(pCurrent->GetPrev());
            pScore->SetNext(pCurrent);
            pCurrent->GetPrev()->SetNext(pScore);
            pCurrent->SetPrev(pScore);
        }
    }
}

// isAscending을 이용한 리스트 출력
void StudentScoreList::PrintList(bool isAscending) {
    if (isAscending) {
        // 오름차순으로 정렬해야한다면
        // m_pHead로 부터 next로 가며 점수 출력
        Score* pCurrent = m_pHead;
        while (pCurrent != nullptr) {
            cout << pCurrent->GetAvg() << " ";
            pCurrent = pCurrent->GetNext();
        }
    }
    else {
        // 내림차순으로 정렬해야한다면
        // m_pTail로 부터 prev로 가며 점수 출력
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
