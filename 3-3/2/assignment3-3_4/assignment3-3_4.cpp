#include <iostream>
using namespace std;

class Score // score 클래스 정의
{
private: // private 멤버 변수 선언
	Score* m_pNext; // 다음 노드를 가리키는 포인터
	Score* m_pPrev; // 이전 노드를 가리키는 포인터
	double m_Avg; // 평균을 저장하는 변수

public: // public 멤버 변수 선언
	Score(); // 생성자
	~Score(); // 소멸자

	void SetAvg(double avg); // 평균을 저장하는 함수
	void SetNext(Score* pNext); // 다음 노드를 가리키는 함수
	void SetPrev(Score* pPrev); // 이전 노드를 가리키는 함수
	double GetAvr(); // 평균을 반환하는 함수
	Score* GetNext(); // 다음 노드를 반환하는 함수
	Score* GetPrev(); // 이전 노드를 반환하는 함수
};

Score::Score() // 생성자
{
	m_pNext = NULL; // 다음 노드를 가리키는 포인터를 NULL로 초기화
	m_pPrev = NULL; // 이전 노드를 가리키는 포인터를 NULL로 초기화
	m_Avg = 0; // 평균을 저장하는 변수를 0으로 초기화
}

Score::~Score() // 소멸자
{
}

void Score::SetAvg(double avg) // 평균을 저장하는 함수
{
	m_Avg = avg; // 평균을 저장하는 변수에 매개변수로 받은 값을 저장
}

void Score::SetNext(Score* pNext) // 다음 노드를 가리키는 함수
{
	m_pNext = pNext; // 다음 노드를 가리키는 포인터에 매개변수로 받은 값을 저장
}

void Score::SetPrev(Score* pPrev) // 이전 노드를 가리키는 함수
{
	m_pPrev = pPrev; // 이전 노드를 가리키는 포인터에 매개변수로 받은 값을 저장
}

double Score::GetAvr() // 평균을 반환하는 함수
{
	return m_Avg; // 평균을 저장하는 변수를 반환
}

Score* Score::GetNext() // 다음 노드를 반환하는 함수
{
	return m_pNext; // 다음 노드를 가리키는 포인터를 반환
}

Score* Score::GetPrev() // 이전 노드를 반환하는 함수
{
	return m_pPrev; // 이전 노드를 가리키는 포인터를 반환
}

class StudentScoreList // studentscorelist 클래스 정의
{
private: // private 멤버 변수 선언
	Score* m_pHead; // 헤드 노드를 가리키는 포인터
	Score* m_pTail; // 테일 노드를 가리키는 포인터
	
public: // public 멤버 변수 선언
	StudentScoreList(); // 생성자
	~StudentScoreList(); // 소멸자
	
	void Insert(Score* pScore); // 노드를 삽입하는 함수
	void PrintList(bool isAscending); // 리스트를 출력하는 함수
};

StudentScoreList::StudentScoreList() // 생성자
{
	m_pHead = NULL; // 헤드 노드를 가리키는 포인터를 NULL로 초기화
	m_pTail = NULL; // 테일 노드를 가리키는 포인터를 NULL로 초기화
}

StudentScoreList::~StudentScoreList() // 소멸자
{
}

void StudentScoreList::Insert(Score* pScore) // 노드를 삽입하는 함수
{
	if (m_pHead == NULL) // 헤드 노드가 NULL이면
	{
		m_pHead = pScore; // 헤드 노드를 삽입하는 노드로 설정
		m_pTail = pScore; // 테일 노드를 삽입하는 노드로 설정
	}
	else // 그 외이면
	{
		Score* pCur = m_pHead; // 현재 노드를 헤드 노드로 설정
		while (pCur != NULL) // 현재 노드가 NULL이 아니면
		{
			if (pCur->GetAvr() > pScore->GetAvr()) // 현재 노드의 평균이 삽입하는 노드의 평균보다 크면
			{
				if (pCur == m_pHead) // 현재 노드가 헤드 노드면
				{
					pScore->SetNext(m_pHead); // 삽입하는 노드의 다음 노드를 헤드 노드로 설정
					m_pHead->SetPrev(pScore); // 헤드 노드의 이전 노드를 삽입하는 노드로 설정
					m_pHead = pScore; // 헤드 노드를 삽입하는 노드로 설정
				}
				else // 그 외이면
				{
					pScore->SetNext(pCur); // 삽입하는 노드의 다음 노드를 현재 노드로 설정
					pScore->SetPrev(pCur->GetPrev()); // 삽입하는 노드의 이전 노드를 현재 노드의 이전 노드로 설정
					pCur->GetPrev()->SetNext(pScore); // 현재 노드의 이전 노드의 다음 노드를 삽입하는 노드로 설정
					pCur->SetPrev(pScore); // 현재 노드의 이전 노드를 삽입하는 노드로 설정
				}
				break; // 반복문 탈출
			}
			else if (pCur == m_pTail) // 현재 노드가 테일 노드면
			{
				pScore->SetPrev(m_pTail); // 삽입하는 노드의 이전 노드를 테일 노드로 설정
				m_pTail->SetNext(pScore); // 테일 노드의 다음 노드를 삽입하는 노드로 설정
				m_pTail = pScore; // 테일 노드를 삽입하는 노드로 설정
				break; // 반복문 탈출
			}
			pCur = pCur->GetNext(); // 현재 노드를 다음 노드로 설정
		}
	}
}

void StudentScoreList::PrintList(bool isAscending) // 리스트를 출력하는 함수
{
	if (isAscending) // 오름차순으로 출력하면
	{
		Score* pCur = m_pHead; // 현재 노드를 헤드 노드로 설정
		while (pCur != NULL) // 현재 노드가 NULL이 아니면
		{
			cout << pCur->GetAvr() << endl; // 현재 노드의 평균을 출력
			pCur = pCur->GetNext(); // 현재 노드를 다음 노드로 설정
		}
	}
	else // 그 외이면
	{
		Score* pCur = m_pTail; // 현재 노드를 테일 노드로 설정
		while (pCur != NULL) // 현재 노드가 NULL이 아니면
		{
			cout << pCur->GetAvr() << endl; // 현재 노드의 평균을 출력
			pCur = pCur->GetPrev(); // 현재 노드를 이전 노드로 설정
		}
	}
}

int main()
{
	cout << "학생 수를 입력하세요: "; // 학생 수를 입력하라는 메시지 출력
	int nStudent; // 학생 수를 저장할 변수 선언
	double math, english, science; // 수학, 영어, 과학 점수를 저장할 변수 선언
	cin >> nStudent; // 학생 수 입력
	
	StudentScoreList list; // 학생 점수 리스트 객체 생성
	for (int i = 0; i < nStudent; i++) // 학생 수만큼 반복
	{
		cout << "학생 " << i + 1 << "의 수학, 영어, 과학 점수를 입력하세요: " << endl; // 학생의 수학, 영어, 과학 점수를 입력하라는 메시지 출력
		cin >> math >> english >> science; // 수학, 영어, 과학 점수 입력
		Score* pScore = new Score(); // 점수 객체 생성
		pScore->SetAvg((math + english + science) / 3); // 점수 객체의 평균을 계산하여 저장
		list.Insert(pScore); // 리스트에 점수 객체 삽입
	}

	cout << "오름차순 정렬 결과: " << endl; // 오름차순 정렬 결과를 출력하라는 메시지 출력
	list.PrintList(true); // 리스트를 오름차순으로 출력
	cout << "내림차순 정렬 결과: " << endl; // 내림차순 정렬 결과를 출력하라는 메시지 출력
	list.PrintList(false); // 리스트를 내림차순으로 출력
	
}




