#include <iostream>

using namespace std;

class Score { // 노드
private:
    Score* m_pNext; // 다음 노드를 가리키는 포인터
    Score* m_pPrev; // 이전 노드를 가리키는 포인터
    double m_Avg; // 평균 점수

public:
    Score() : m_Avg(0), m_pNext(nullptr), m_pPrev(nullptr) {} // 생성자
    ~Score() {} // 소멸자

    void SetAvg(double math, double english, double science) { m_Avg = (math + english + science) / 3; } // 평균 점수 설정
    void SetNext(Score* pNext) { m_pNext = pNext; } // 다음 노드 설정
    void SetPrev(Score* pPrev) { m_pPrev = pPrev; } // 이전 노드 설정

    double GetAvg() { return m_Avg; } // 평균 점수 반환
    Score* GetNext() { return m_pNext; } // 다음 노드 반환
    Score* GetPrev() { return m_pPrev; } // 이전 노드 반환
};

class StudentScoreList { // 더블 링크드 리스트
private:
    Score* m_pHead; // 헤드 노드
    Score* m_pTail; // 테일 노드

public:
    StudentScoreList() : m_pHead(nullptr), m_pTail(nullptr) {} // 생성자
    ~StudentScoreList() {        				// 소멸자
        while (m_pHead) { // 헤드 노드가 nullptr이 아닐 때까지
            Score* toDelete = m_pHead; 
            m_pHead = m_pHead->GetNext();
            delete toDelete;
        }
        m_pTail = nullptr;
    }

    void Insert(Score* pScore) { // 노드 삽입
        if (m_pHead == nullptr) { // 헤드 노드가 nullptr이면
            m_pHead = m_pTail = pScore;
            return;
        }

        Score* curr = m_pHead; // 현재 노드를 헤드 노드로 설정
        while (curr && curr->GetAvg() < pScore->GetAvg()) {
            curr = curr->GetNext();
        }

        if (curr == m_pHead) { // 현재 노드가 헤드 노드이면
            pScore->SetNext(m_pHead); // 삽입할 노드의 다음 노드를 헤드 노드로 설정
            m_pHead->SetPrev(pScore); // 헤드 노드의 이전 노드를 삽입할 노드로 설정
            m_pHead = pScore; // 헤드 노드를 삽입할 노드로 설정
        }
        else if (curr == nullptr) { // 현재 노드가 nullptr이면
            m_pTail->SetNext(pScore); // 테일 노드의 다음 노드를 삽입할 노드로 설정
            pScore->SetPrev(m_pTail); // 삽입할 노드의 이전 노드를 테일 노드로 설정
            m_pTail = pScore; // 테일 노드를 삽입할 노드로 설정
        }
        else { // 그 외의 경우
            pScore->SetNext(curr);  // 삽입할 노드의 다음 노드를 현재 노드로 설정
            pScore->SetPrev(curr->GetPrev()); // 삽입할 노드의 이전 노드를 현재 노드의 이전 노드로 설정
            curr->GetPrev()->SetNext(pScore);   // 현재 노드의 이전 노드의 다음 노드를 삽입할 노드로 설정
            curr->SetPrev(pScore); // 현재 노드의 이전 노드를 삽입할 노드로 설정
        }
    }

    void PrintList(bool isAscending) { // 노드 출력
        Score* curr = isAscending ? m_pHead : m_pTail; // 현재 노드를 헤드 노드 또는 테일 노드로 설정
        while (curr) { // 현재 노드가 nullptr이 아닐 때까지
            cout << "Average Score: " << curr->GetAvg() << endl; // 평균 점수 출력
            curr = isAscending ? curr->GetNext() : curr->GetPrev(); // 현재 노드를 다음 노드 또는 이전 노드로 설정
        }
    }
};

int main() { // 메인 함수
    StudentScoreList list;
    int numStudents;
    double mathScore, englishScore, scienceScore;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter the math score for student " << (i + 1) << ": ";
        cin >> mathScore;
        cout << "Enter the English score for student " << (i + 1) << ": ";
        cin >> englishScore;
        cout << "Enter the science score for student " << (i + 1) << ": ";
        cin >> scienceScore;

        Score* newScore = new Score;
        newScore->SetAvg(mathScore, englishScore, scienceScore);
        list.Insert(newScore);
    }

    cout << "Scores in ascending order:" << endl;
    list.PrintList(true);

    cout << "Scores in descending order:" << endl;
    list.PrintList(false);

    return 0;
}
