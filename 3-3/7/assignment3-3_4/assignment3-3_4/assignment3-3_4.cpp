#include <iostream>
using namespace std;
class Score // 점수 클래스
{
private:
    Score* m_pNext; // 다음 점수
    Score* m_pPrev; // 이전 점수
    double m_Avg; // 평균

public:
    Score() // 생성자 
    {
        m_Avg = 0.0;
        m_pNext = nullptr;
        m_pPrev = nullptr;
    }
   
    ~Score() 
    {

    }

    void SetAvg(double avg) // 평균 설정
    {
        m_Avg = avg; // 입력한 평균으로 초기화
    }
     
    void SetNext(Score* pNext) // 다음 점수 설정
    {
        m_pNext = pNext; // 다음 점수로 초기화
    }

    void SetPrev(Score* pPrev) // 이전 점수 설정
    {
        m_pPrev = pPrev; // 이전 점수로 초기화
    }

    double GetAvr() // 평균 얻어오기
    {
        return m_Avg; // 평균 반환
    }
     
    Score* GetNext() // 다음 점수 얻어오기
    {
        return m_pNext; // 다음 점수 반환
    }

    Score* GetPrev() // 이전 점수 얻어오기
    {
        return m_pPrev; // 이전 점수 반환
    }
};

class StudentScoreList 
{
private:
    Score* m_pHead; // 맨 앞 노드
    Score* m_pTail; // 맨 끝 노드

public:
    StudentScoreList() // 생성자
    {
        m_pHead = nullptr;
        m_pTail = nullptr;
    }

    ~StudentScoreList() // 소멸자
    {
        Score* pNode = m_pHead; // 처음 값부터
        Score* pNext = nullptr; // 다음 노드를 널문자로 초기화

        while (pNode != nullptr) // 맨 끝에 오기전까지
        {
            pNext = pNode->GetNext();
            delete pNode;  // 순차적으로 할당 해제
            pNode = pNext;
        }
        m_pTail = nullptr; // 맨 끝 노드를 널문자로 초기화
    }

    void Insert(Score* pScore) // 삽입 연산
    {
        if (m_pHead == nullptr) // 처음 노드가 널문자이면
        {
            m_pHead = pScore; // 입력한 점수로 초기화
            m_pTail = pScore; // 입력한 점수로 초기화
            return;
        }

        Score* m_pCur = m_pHead; // 현재 노드를 처음 노드로 초기화

        while (m_pCur != nullptr && m_pCur->GetAvr() < pScore->GetAvr()) // 삽입할 점수 위치 찾기  
            m_pCur = m_pCur->GetNext(); // 노드를 다음 노드로 업데이트
        
        if (m_pCur == m_pHead) // 현재 노드가 처음 노드일 경우
        {
            pScore->SetNext(m_pHead); // 입력한 점수가 더 작으므로 입력한 노드의 다음 노드로 처음 노드 설정
            m_pHead->SetPrev(pScore); // 처음 노드는 입력한 노드의 다음 노드로
            m_pHead = pScore; // 처음 노드는 입력한 노드
        }
        else if (m_pCur == nullptr) // 맨 마지막인 경우
        {
            m_pTail->SetNext(pScore); // 맨 마지막 노드의 다음 노드를 입력한 노드로
            pScore->SetPrev(m_pTail); // 입력한 노드의 전 노드는 마지막 노드로 
            m_pTail = pScore; // 맨 마지막 노드 업데이트
        }
        else  // 중간에 삽입
        {
            pScore->SetNext(m_pCur); // 입력한 노드의 다음 노드를 현재 노드로 
            pScore->SetPrev(m_pCur->GetPrev()); // 입력한 노드의 이전 노드를 현재 노드의 이전 노드로 
            m_pCur->GetPrev()->SetNext(pScore); // 현재 노드의 이전 노드의 다음 노드를 입력한 노드로 
            m_pCur->SetPrev(pScore);  // 현재 노드의 이전 노드를 입력한 노드로 
        }
    }

    void PrintList(bool isAscending) // 리스트 출력
    {
        if (isAscending) // 오름차순이면
        {
            Score* m_pCur = m_pHead; // 처음 노드로 초기화
            while (m_pCur != nullptr) // 널포인터가 아닐때까지
            {
                cout << m_pCur->GetAvr() << endl; // 현재 노드의 평균 출력
                m_pCur = m_pCur->GetNext(); // 다음 노드로 업데이트
            }
        }
        else // 내림차순이면
        {
            Score* m_pCur = m_pTail; // 마지막 노드로 초기화
            while (m_pCur != nullptr) // 널포인터가 아닐때까지
            {
                cout << m_pCur->GetAvr() << endl; // 현재 노드의 평균 출력
                m_pCur = m_pCur->GetPrev(); // 이전 노드로 업데이트
            }
        }
    }
};

int main()
{
    StudentScoreList StudentList; // 학생 리스트
    double MathScore, EnglishScore, ScienceScore; // 과목 점수
    double Avg; // 평균
    int number; // 학생 수
    cout << "Students number: "; // 학생 수 입력
    cin >> number;

    for (int i = 0; i < number; i++)
    {
        cout << "Student " << i + 1 << " Score" << endl;
        cout << "Math: "; // 수학 점수 입력
        cin >> MathScore;
        cout << "English: "; // 영어 점수 입력
        cin >> EnglishScore;
        cout << "Science: "; // 과학 점수 입력
        cin >> ScienceScore;
        Avg = (MathScore + EnglishScore + ScienceScore) / 3.0; // 평균 계산
        cout << "Stduent " << i + 1 << " Avg is " << Avg << endl << endl; // 평균 출력
        Score* STudent = new Score; // 점수 객체생성
        STudent->SetAvg(Avg);  // 평균 설정
        StudentList.Insert(STudent); // 리스트에 넣기
    }

    cout << "Ascending order:" << endl; // 오름차순 출력
    StudentList.PrintList(true);
    cout << "Descending order:" << endl; // 내림차순 출력
    StudentList.PrintList(false);

    return 0;
}
