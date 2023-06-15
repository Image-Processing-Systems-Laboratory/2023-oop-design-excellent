#include <iostream>
using namespace std;
class Score // ���� Ŭ����
{
private:
    Score* m_pNext; // ���� ����
    Score* m_pPrev; // ���� ����
    double m_Avg; // ���

public:
    Score() // ������ 
    {
        m_Avg = 0.0;
        m_pNext = nullptr;
        m_pPrev = nullptr;
    }
   
    ~Score() 
    {

    }

    void SetAvg(double avg) // ��� ����
    {
        m_Avg = avg; // �Է��� ������� �ʱ�ȭ
    }
     
    void SetNext(Score* pNext) // ���� ���� ����
    {
        m_pNext = pNext; // ���� ������ �ʱ�ȭ
    }

    void SetPrev(Score* pPrev) // ���� ���� ����
    {
        m_pPrev = pPrev; // ���� ������ �ʱ�ȭ
    }

    double GetAvr() // ��� ������
    {
        return m_Avg; // ��� ��ȯ
    }
     
    Score* GetNext() // ���� ���� ������
    {
        return m_pNext; // ���� ���� ��ȯ
    }

    Score* GetPrev() // ���� ���� ������
    {
        return m_pPrev; // ���� ���� ��ȯ
    }
};

class StudentScoreList 
{
private:
    Score* m_pHead; // �� �� ���
    Score* m_pTail; // �� �� ���

public:
    StudentScoreList() // ������
    {
        m_pHead = nullptr;
        m_pTail = nullptr;
    }

    ~StudentScoreList() // �Ҹ���
    {
        Score* pNode = m_pHead; // ó�� ������
        Score* pNext = nullptr; // ���� ��带 �ι��ڷ� �ʱ�ȭ

        while (pNode != nullptr) // �� ���� ����������
        {
            pNext = pNode->GetNext();
            delete pNode;  // ���������� �Ҵ� ����
            pNode = pNext;
        }
        m_pTail = nullptr; // �� �� ��带 �ι��ڷ� �ʱ�ȭ
    }

    void Insert(Score* pScore) // ���� ����
    {
        if (m_pHead == nullptr) // ó�� ��尡 �ι����̸�
        {
            m_pHead = pScore; // �Է��� ������ �ʱ�ȭ
            m_pTail = pScore; // �Է��� ������ �ʱ�ȭ
            return;
        }

        Score* m_pCur = m_pHead; // ���� ��带 ó�� ���� �ʱ�ȭ

        while (m_pCur != nullptr && m_pCur->GetAvr() < pScore->GetAvr()) // ������ ���� ��ġ ã��  
            m_pCur = m_pCur->GetNext(); // ��带 ���� ���� ������Ʈ
        
        if (m_pCur == m_pHead) // ���� ��尡 ó�� ����� ���
        {
            pScore->SetNext(m_pHead); // �Է��� ������ �� �����Ƿ� �Է��� ����� ���� ���� ó�� ��� ����
            m_pHead->SetPrev(pScore); // ó�� ���� �Է��� ����� ���� ����
            m_pHead = pScore; // ó�� ���� �Է��� ���
        }
        else if (m_pCur == nullptr) // �� �������� ���
        {
            m_pTail->SetNext(pScore); // �� ������ ����� ���� ��带 �Է��� ����
            pScore->SetPrev(m_pTail); // �Է��� ����� �� ���� ������ ���� 
            m_pTail = pScore; // �� ������ ��� ������Ʈ
        }
        else  // �߰��� ����
        {
            pScore->SetNext(m_pCur); // �Է��� ����� ���� ��带 ���� ���� 
            pScore->SetPrev(m_pCur->GetPrev()); // �Է��� ����� ���� ��带 ���� ����� ���� ���� 
            m_pCur->GetPrev()->SetNext(pScore); // ���� ����� ���� ����� ���� ��带 �Է��� ���� 
            m_pCur->SetPrev(pScore);  // ���� ����� ���� ��带 �Է��� ���� 
        }
    }

    void PrintList(bool isAscending) // ����Ʈ ���
    {
        if (isAscending) // ���������̸�
        {
            Score* m_pCur = m_pHead; // ó�� ���� �ʱ�ȭ
            while (m_pCur != nullptr) // �������Ͱ� �ƴҶ�����
            {
                cout << m_pCur->GetAvr() << endl; // ���� ����� ��� ���
                m_pCur = m_pCur->GetNext(); // ���� ���� ������Ʈ
            }
        }
        else // ���������̸�
        {
            Score* m_pCur = m_pTail; // ������ ���� �ʱ�ȭ
            while (m_pCur != nullptr) // �������Ͱ� �ƴҶ�����
            {
                cout << m_pCur->GetAvr() << endl; // ���� ����� ��� ���
                m_pCur = m_pCur->GetPrev(); // ���� ���� ������Ʈ
            }
        }
    }
};

int main()
{
    StudentScoreList StudentList; // �л� ����Ʈ
    double MathScore, EnglishScore, ScienceScore; // ���� ����
    double Avg; // ���
    int number; // �л� ��
    cout << "Students number: "; // �л� �� �Է�
    cin >> number;

    for (int i = 0; i < number; i++)
    {
        cout << "Student " << i + 1 << " Score" << endl;
        cout << "Math: "; // ���� ���� �Է�
        cin >> MathScore;
        cout << "English: "; // ���� ���� �Է�
        cin >> EnglishScore;
        cout << "Science: "; // ���� ���� �Է�
        cin >> ScienceScore;
        Avg = (MathScore + EnglishScore + ScienceScore) / 3.0; // ��� ���
        cout << "Stduent " << i + 1 << " Avg is " << Avg << endl << endl; // ��� ���
        Score* STudent = new Score; // ���� ��ü����
        STudent->SetAvg(Avg);  // ��� ����
        StudentList.Insert(STudent); // ����Ʈ�� �ֱ�
    }

    cout << "Ascending order:" << endl; // �������� ���
    StudentList.PrintList(true);
    cout << "Descending order:" << endl; // �������� ���
    StudentList.PrintList(false);

    return 0;
}
