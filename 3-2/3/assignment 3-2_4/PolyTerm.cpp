#include "PolyTerm.h"
#include <iostream>

using namespace std;

Term::Term()
{
	// ����� ������ 0���� �ʱ�ȭ, ���� ���� nullptr�� �ʱ�ȭ
	m_Coefficient = 0;
	m_Exponent = 0;
	m_pNext = nullptr;
}

Term::~Term()
{
}

// ����� �����ϴ� �Լ�
void Term::SetCoeff(int coeff)
{
	m_Coefficient = coeff;		// ��� ����
}

// ������ �����ϴ� �Լ�
void Term::SetExponent(int exponent)
{
	m_Exponent = exponent;		// ���� ����
}

// ����� ��ȯ�ϴ� �Լ�
int Term::GetCoeff()
{
	return m_Coefficient;		// ��� ��ȯ
}

// ������ ��ȯ�ϴ� �Լ�
int Term::GetExponent()
{
	return m_Exponent;		// ���� ��ȯ
}

// ���� ��带 �����ϴ� �Լ�
void Term::SetNext(Term* pNext)
{
	m_pNext = pNext;		// ���� ��� ����
}

// ���� ��带 ��ȯ�ϴ� �Լ�
Term* Term::GetNext()
{
	return m_pNext;		// ���� ��� ��ȯ
}

// ���׽��� �ʱ�ȭ�ϴ� ������
Polynomial::Polynomial()
{
	m_pHead = nullptr;		// ���׽��� ù ��° ��带 nullptr�� �ʱ�ȭ
}

// �Ҹ���
Polynomial::~Polynomial()
{
	Term* pTerm = m_pHead;		// ���׽��� ù ��° ��带 pTerm�� ����
	// ���׽��� ��� ��带 ����
	while (pTerm != nullptr)
	{
		Term* pNext = pTerm->GetNext();
		delete pTerm;
		pTerm = pNext;
	}
}

// ���׽Ŀ� ���� �߰��ϴ� �Լ�
void Polynomial::Insert(Term* pTerm)
{
	// ���׽��� ����ִ� ���
	if (m_pHead == nullptr)
	{
		m_pHead = pTerm;
		return;
	}

	Term* pCurrent = m_pHead;		// ���׽��� ù ��° ��带 pCurrent�� ����
	Term* pPrev = nullptr;		// pCurrent�� ���� ��带 nullptr�� �ʱ�ȭ

	// ���׽��� ��� ��带 Ȯ���ϸ� ���� �߰��� ��ġ�� ã��
	while (pCurrent != nullptr && pCurrent->GetExponent() > pTerm->GetExponent())
	{
		pPrev = pCurrent;		// pCurrent�� pPrev�� ����
		pCurrent = pCurrent->GetNext();		// pCurrent�� ���� ���� �̵�
	}

	// �߰��� ���� ������ �̹� �����ϴ� ���
	if (pCurrent != nullptr && pCurrent->GetExponent() == pTerm->GetExponent())
	{
		pCurrent->SetCoeff(pCurrent->GetCoeff() + pTerm->GetCoeff());		// ����� ����
		delete pTerm;		// �߰��� ���� ����
		// ����� 0�� �Ǹ� ���� ����
		if (pCurrent->GetCoeff() == 0.0)
		{
			// ������ ���� ù ��° ���� ���
			if (pPrev == nullptr)
			{
				m_pHead = pCurrent->GetNext();		// ù ��° ���� ���� ���� ����
			}
			// ������ ���� ù ��° ���� �ƴ� ���
			else
			{
				pPrev->SetNext(pCurrent->GetNext());		// ���� ����� ���� ��带 ���� ���� ����
			}
			delete pCurrent;		// ������ ���� ����
		}
	}
	// �߰��� ���� ������ �������� �ʴ� ���
	else
	{
		pTerm->SetNext(pCurrent);		// �߰��� ���� ���� ��带 pCurrent�� ����
		// �߰��� ���� ù ��° ���� ���
		if (pPrev == nullptr)
		{
			m_pHead = pTerm;		// ù ��° ���� �߰��� ������ ����
		}
		// �߰��� ���� ù ��° ���� �ƴ� ���
		else
		{
			pPrev->SetNext(pTerm);		// ���� ����� ���� ��带 �߰��� ������ ����
		}
	}
}

// ���׽��� ����ϴ� �Լ�
void Polynomial::PrintList()
{
	Term* pTerm = m_pHead;		// ���׽��� ù ��° ��带 pTerm�� ����
	bool isFirstTerm = true;		// ù ��° ������ Ȯ���ϴ� ����
	// ���׽��� ��� ��带 Ȯ���ϸ� ���� ���
	while (pTerm != nullptr)
	{
		// ����� 0�� ���� ������� ����
		if (pTerm->GetCoeff() == 0)
		{
			pTerm = pTerm->GetNext();		// pTerm�� ���� ���� �̵�
			continue;		// ���� ���� �̵�
		}

		// ù ��° ���� �ƴ� ���
		if (!isFirstTerm)
		{
			// ����� ����� ���
			if (pTerm->GetCoeff() > 0)
			{
				cout << " + ";		// + ���
			}
			// ����� ������ ���
			else if (pTerm->GetCoeff() < 0)
			{
				cout << " - ";		//	- ���
			}
		}
		// ����� �����̸鼭 ù ��° ���� ���
		else if (pTerm->GetCoeff() < 0)
		{
			cout << "-";		// - ���
		}

		// ����� 1�� �ƴϸ鼭 ������ 0�� ���
		if (pTerm->GetExponent() == 0 || abs(pTerm->GetCoeff()) != 1)
		{
			cout << abs(pTerm->GetCoeff());		// ��� ���
		}

		// ������ 0�� �ƴ� ���
		if (pTerm->GetExponent() != 0)
		{
			cout << "x";		// x ���
			// ������ 1�� �ƴ� ���
			if (pTerm->GetExponent() != 1)
			{
				cout << "^" << pTerm->GetExponent();		// ���� ���
			}
		}

		isFirstTerm = false;		// ù ��° ���� �ƴ��� ǥ��
		pTerm = pTerm->GetNext();		// pTerm�� ���� ���� �̵�
	}
	cout << endl;
}

// ���׽��� ���ϴ� �Լ�
void Polynomial::Add(Polynomial& poly)
{
	Term* pTerm = poly.m_pHead;		// ���׽��� ù ��° ��带 pTerm�� ����
	// ���׽��� ��� ��带 Ȯ���ϸ� ���� �߰�
	while (pTerm != nullptr)
	{
		Term* newTerm = new Term();		// �߰��� ���� ������ ��� ����
		newTerm->SetCoeff(pTerm->GetCoeff());		// ��� ����
		newTerm->SetExponent(pTerm->GetExponent());		// ���� ����
		Insert(newTerm);		// �� �߰�
		pTerm = pTerm->GetNext();		// pTerm�� ���� ���� �̵�
	}
}

// ���׽��� ���� �Լ�
void Polynomial::Sub(Polynomial& poly)
{
	Term* pTerm = poly.m_pHead;		// ���׽��� ù ��° ��带 pTerm�� ����
	// ���׽��� ��� ��带 Ȯ���ϸ� ���� �߰�
	while (pTerm != nullptr)
	{
		Term* newTerm = new Term();		// �߰��� ���� ������ ��� ����
		newTerm->SetCoeff(-pTerm->GetCoeff());		// ��� ����
		newTerm->SetExponent(pTerm->GetExponent());		// ���� ����
		Insert(newTerm);		// �� �߰�
		pTerm = pTerm->GetNext();		// pTerm�� ���� ���� �̵�
	}
}