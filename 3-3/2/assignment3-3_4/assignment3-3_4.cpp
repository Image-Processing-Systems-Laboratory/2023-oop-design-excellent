#include <iostream>
using namespace std;

class Score // score Ŭ���� ����
{
private: // private ��� ���� ����
	Score* m_pNext; // ���� ��带 ����Ű�� ������
	Score* m_pPrev; // ���� ��带 ����Ű�� ������
	double m_Avg; // ����� �����ϴ� ����

public: // public ��� ���� ����
	Score(); // ������
	~Score(); // �Ҹ���

	void SetAvg(double avg); // ����� �����ϴ� �Լ�
	void SetNext(Score* pNext); // ���� ��带 ����Ű�� �Լ�
	void SetPrev(Score* pPrev); // ���� ��带 ����Ű�� �Լ�
	double GetAvr(); // ����� ��ȯ�ϴ� �Լ�
	Score* GetNext(); // ���� ��带 ��ȯ�ϴ� �Լ�
	Score* GetPrev(); // ���� ��带 ��ȯ�ϴ� �Լ�
};

Score::Score() // ������
{
	m_pNext = NULL; // ���� ��带 ����Ű�� �����͸� NULL�� �ʱ�ȭ
	m_pPrev = NULL; // ���� ��带 ����Ű�� �����͸� NULL�� �ʱ�ȭ
	m_Avg = 0; // ����� �����ϴ� ������ 0���� �ʱ�ȭ
}

Score::~Score() // �Ҹ���
{
}

void Score::SetAvg(double avg) // ����� �����ϴ� �Լ�
{
	m_Avg = avg; // ����� �����ϴ� ������ �Ű������� ���� ���� ����
}

void Score::SetNext(Score* pNext) // ���� ��带 ����Ű�� �Լ�
{
	m_pNext = pNext; // ���� ��带 ����Ű�� �����Ϳ� �Ű������� ���� ���� ����
}

void Score::SetPrev(Score* pPrev) // ���� ��带 ����Ű�� �Լ�
{
	m_pPrev = pPrev; // ���� ��带 ����Ű�� �����Ϳ� �Ű������� ���� ���� ����
}

double Score::GetAvr() // ����� ��ȯ�ϴ� �Լ�
{
	return m_Avg; // ����� �����ϴ� ������ ��ȯ
}

Score* Score::GetNext() // ���� ��带 ��ȯ�ϴ� �Լ�
{
	return m_pNext; // ���� ��带 ����Ű�� �����͸� ��ȯ
}

Score* Score::GetPrev() // ���� ��带 ��ȯ�ϴ� �Լ�
{
	return m_pPrev; // ���� ��带 ����Ű�� �����͸� ��ȯ
}

class StudentScoreList // studentscorelist Ŭ���� ����
{
private: // private ��� ���� ����
	Score* m_pHead; // ��� ��带 ����Ű�� ������
	Score* m_pTail; // ���� ��带 ����Ű�� ������
	
public: // public ��� ���� ����
	StudentScoreList(); // ������
	~StudentScoreList(); // �Ҹ���
	
	void Insert(Score* pScore); // ��带 �����ϴ� �Լ�
	void PrintList(bool isAscending); // ����Ʈ�� ����ϴ� �Լ�
};

StudentScoreList::StudentScoreList() // ������
{
	m_pHead = NULL; // ��� ��带 ����Ű�� �����͸� NULL�� �ʱ�ȭ
	m_pTail = NULL; // ���� ��带 ����Ű�� �����͸� NULL�� �ʱ�ȭ
}

StudentScoreList::~StudentScoreList() // �Ҹ���
{
}

void StudentScoreList::Insert(Score* pScore) // ��带 �����ϴ� �Լ�
{
	if (m_pHead == NULL) // ��� ��尡 NULL�̸�
	{
		m_pHead = pScore; // ��� ��带 �����ϴ� ���� ����
		m_pTail = pScore; // ���� ��带 �����ϴ� ���� ����
	}
	else // �� ���̸�
	{
		Score* pCur = m_pHead; // ���� ��带 ��� ���� ����
		while (pCur != NULL) // ���� ��尡 NULL�� �ƴϸ�
		{
			if (pCur->GetAvr() > pScore->GetAvr()) // ���� ����� ����� �����ϴ� ����� ��պ��� ũ��
			{
				if (pCur == m_pHead) // ���� ��尡 ��� ����
				{
					pScore->SetNext(m_pHead); // �����ϴ� ����� ���� ��带 ��� ���� ����
					m_pHead->SetPrev(pScore); // ��� ����� ���� ��带 �����ϴ� ���� ����
					m_pHead = pScore; // ��� ��带 �����ϴ� ���� ����
				}
				else // �� ���̸�
				{
					pScore->SetNext(pCur); // �����ϴ� ����� ���� ��带 ���� ���� ����
					pScore->SetPrev(pCur->GetPrev()); // �����ϴ� ����� ���� ��带 ���� ����� ���� ���� ����
					pCur->GetPrev()->SetNext(pScore); // ���� ����� ���� ����� ���� ��带 �����ϴ� ���� ����
					pCur->SetPrev(pScore); // ���� ����� ���� ��带 �����ϴ� ���� ����
				}
				break; // �ݺ��� Ż��
			}
			else if (pCur == m_pTail) // ���� ��尡 ���� ����
			{
				pScore->SetPrev(m_pTail); // �����ϴ� ����� ���� ��带 ���� ���� ����
				m_pTail->SetNext(pScore); // ���� ����� ���� ��带 �����ϴ� ���� ����
				m_pTail = pScore; // ���� ��带 �����ϴ� ���� ����
				break; // �ݺ��� Ż��
			}
			pCur = pCur->GetNext(); // ���� ��带 ���� ���� ����
		}
	}
}

void StudentScoreList::PrintList(bool isAscending) // ����Ʈ�� ����ϴ� �Լ�
{
	if (isAscending) // ������������ ����ϸ�
	{
		Score* pCur = m_pHead; // ���� ��带 ��� ���� ����
		while (pCur != NULL) // ���� ��尡 NULL�� �ƴϸ�
		{
			cout << pCur->GetAvr() << endl; // ���� ����� ����� ���
			pCur = pCur->GetNext(); // ���� ��带 ���� ���� ����
		}
	}
	else // �� ���̸�
	{
		Score* pCur = m_pTail; // ���� ��带 ���� ���� ����
		while (pCur != NULL) // ���� ��尡 NULL�� �ƴϸ�
		{
			cout << pCur->GetAvr() << endl; // ���� ����� ����� ���
			pCur = pCur->GetPrev(); // ���� ��带 ���� ���� ����
		}
	}
}

int main()
{
	cout << "�л� ���� �Է��ϼ���: "; // �л� ���� �Է��϶�� �޽��� ���
	int nStudent; // �л� ���� ������ ���� ����
	double math, english, science; // ����, ����, ���� ������ ������ ���� ����
	cin >> nStudent; // �л� �� �Է�
	
	StudentScoreList list; // �л� ���� ����Ʈ ��ü ����
	for (int i = 0; i < nStudent; i++) // �л� ����ŭ �ݺ�
	{
		cout << "�л� " << i + 1 << "�� ����, ����, ���� ������ �Է��ϼ���: " << endl; // �л��� ����, ����, ���� ������ �Է��϶�� �޽��� ���
		cin >> math >> english >> science; // ����, ����, ���� ���� �Է�
		Score* pScore = new Score(); // ���� ��ü ����
		pScore->SetAvg((math + english + science) / 3); // ���� ��ü�� ����� ����Ͽ� ����
		list.Insert(pScore); // ����Ʈ�� ���� ��ü ����
	}

	cout << "�������� ���� ���: " << endl; // �������� ���� ����� ����϶�� �޽��� ���
	list.PrintList(true); // ����Ʈ�� ������������ ���
	cout << "�������� ���� ���: " << endl; // �������� ���� ����� ����϶�� �޽��� ���
	list.PrintList(false); // ����Ʈ�� ������������ ���
	
}




