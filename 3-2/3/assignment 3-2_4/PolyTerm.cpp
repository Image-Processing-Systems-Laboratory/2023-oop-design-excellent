#include "PolyTerm.h"
#include <iostream>

using namespace std;

Term::Term()
{
	// 계수와 차수를 0으로 초기화, 다음 노드는 nullptr로 초기화
	m_Coefficient = 0;
	m_Exponent = 0;
	m_pNext = nullptr;
}

Term::~Term()
{
}

// 계수를 설정하는 함수
void Term::SetCoeff(int coeff)
{
	m_Coefficient = coeff;		// 계수 설정
}

// 차수를 설정하는 함수
void Term::SetExponent(int exponent)
{
	m_Exponent = exponent;		// 차수 설정
}

// 계수를 반환하는 함수
int Term::GetCoeff()
{
	return m_Coefficient;		// 계수 반환
}

// 차수를 반환하는 함수
int Term::GetExponent()
{
	return m_Exponent;		// 차수 반환
}

// 다음 노드를 설정하는 함수
void Term::SetNext(Term* pNext)
{
	m_pNext = pNext;		// 다음 노드 설정
}

// 다음 노드를 반환하는 함수
Term* Term::GetNext()
{
	return m_pNext;		// 다음 노드 반환
}

// 다항식을 초기화하는 생성자
Polynomial::Polynomial()
{
	m_pHead = nullptr;		// 다항식의 첫 번째 노드를 nullptr로 초기화
}

// 소멸자
Polynomial::~Polynomial()
{
	Term* pTerm = m_pHead;		// 다항식의 첫 번째 노드를 pTerm에 저장
	// 다항식의 모든 노드를 삭제
	while (pTerm != nullptr)
	{
		Term* pNext = pTerm->GetNext();
		delete pTerm;
		pTerm = pNext;
	}
}

// 다항식에 항을 추가하는 함수
void Polynomial::Insert(Term* pTerm)
{
	// 다항식이 비어있는 경우
	if (m_pHead == nullptr)
	{
		m_pHead = pTerm;
		return;
	}

	Term* pCurrent = m_pHead;		// 다항식의 첫 번째 노드를 pCurrent에 저장
	Term* pPrev = nullptr;		// pCurrent의 이전 노드를 nullptr로 초기화

	// 다항식의 모든 노드를 확인하며 항을 추가할 위치를 찾음
	while (pCurrent != nullptr && pCurrent->GetExponent() > pTerm->GetExponent())
	{
		pPrev = pCurrent;		// pCurrent를 pPrev에 저장
		pCurrent = pCurrent->GetNext();		// pCurrent를 다음 노드로 이동
	}

	// 추가할 항의 차수가 이미 존재하는 경우
	if (pCurrent != nullptr && pCurrent->GetExponent() == pTerm->GetExponent())
	{
		pCurrent->SetCoeff(pCurrent->GetCoeff() + pTerm->GetCoeff());		// 계수를 더함
		delete pTerm;		// 추가할 항을 삭제
		// 계수가 0이 되면 항을 삭제
		if (pCurrent->GetCoeff() == 0.0)
		{
			// 삭제할 항이 첫 번째 항인 경우
			if (pPrev == nullptr)
			{
				m_pHead = pCurrent->GetNext();		// 첫 번째 항을 다음 노드로 변경
			}
			// 삭제할 항이 첫 번째 항이 아닌 경우
			else
			{
				pPrev->SetNext(pCurrent->GetNext());		// 이전 노드의 다음 노드를 다음 노드로 변경
			}
			delete pCurrent;		// 삭제할 항을 삭제
		}
	}
	// 추가할 항의 차수가 존재하지 않는 경우
	else
	{
		pTerm->SetNext(pCurrent);		// 추가할 항의 다음 노드를 pCurrent로 설정
		// 추가할 항이 첫 번째 항인 경우
		if (pPrev == nullptr)
		{
			m_pHead = pTerm;		// 첫 번째 항을 추가할 항으로 변경
		}
		// 추가할 항이 첫 번째 항이 아닌 경우
		else
		{
			pPrev->SetNext(pTerm);		// 이전 노드의 다음 노드를 추가할 항으로 변경
		}
	}
}

// 다항식을 출력하는 함수
void Polynomial::PrintList()
{
	Term* pTerm = m_pHead;		// 다항식의 첫 번째 노드를 pTerm에 저장
	bool isFirstTerm = true;		// 첫 번째 항인지 확인하는 변수
	// 다항식의 모든 노드를 확인하며 항을 출력
	while (pTerm != nullptr)
	{
		// 계수가 0인 항은 출력하지 않음
		if (pTerm->GetCoeff() == 0)
		{
			pTerm = pTerm->GetNext();		// pTerm을 다음 노드로 이동
			continue;		// 다음 노드로 이동
		}

		// 첫 번째 항이 아닌 경우
		if (!isFirstTerm)
		{
			// 계수가 양수인 경우
			if (pTerm->GetCoeff() > 0)
			{
				cout << " + ";		// + 출력
			}
			// 계수가 음수인 경우
			else if (pTerm->GetCoeff() < 0)
			{
				cout << " - ";		//	- 출력
			}
		}
		// 계수가 음수이면서 첫 번째 항인 경우
		else if (pTerm->GetCoeff() < 0)
		{
			cout << "-";		// - 출력
		}

		// 계수가 1이 아니면서 지수가 0인 경우
		if (pTerm->GetExponent() == 0 || abs(pTerm->GetCoeff()) != 1)
		{
			cout << abs(pTerm->GetCoeff());		// 계수 출력
		}

		// 차수가 0이 아닌 경우
		if (pTerm->GetExponent() != 0)
		{
			cout << "x";		// x 출력
			// 차수가 1이 아닌 경우
			if (pTerm->GetExponent() != 1)
			{
				cout << "^" << pTerm->GetExponent();		// 차수 출력
			}
		}

		isFirstTerm = false;		// 첫 번째 항이 아님을 표시
		pTerm = pTerm->GetNext();		// pTerm을 다음 노드로 이동
	}
	cout << endl;
}

// 다항식을 더하는 함수
void Polynomial::Add(Polynomial& poly)
{
	Term* pTerm = poly.m_pHead;		// 다항식의 첫 번째 노드를 pTerm에 저장
	// 다항식의 모든 노드를 확인하며 항을 추가
	while (pTerm != nullptr)
	{
		Term* newTerm = new Term();		// 추가할 항을 저장할 노드 생성
		newTerm->SetCoeff(pTerm->GetCoeff());		// 계수 설정
		newTerm->SetExponent(pTerm->GetExponent());		// 차수 설정
		Insert(newTerm);		// 항 추가
		pTerm = pTerm->GetNext();		// pTerm을 다음 노드로 이동
	}
}

// 다항식을 빼는 함수
void Polynomial::Sub(Polynomial& poly)
{
	Term* pTerm = poly.m_pHead;		// 다항식의 첫 번째 노드를 pTerm에 저장
	// 다항식의 모든 노드를 확인하며 항을 추가
	while (pTerm != nullptr)
	{
		Term* newTerm = new Term();		// 추가할 항을 저장할 노드 생성
		newTerm->SetCoeff(-pTerm->GetCoeff());		// 계수 설정
		newTerm->SetExponent(pTerm->GetExponent());		// 차수 설정
		Insert(newTerm);		// 항 추가
		pTerm = pTerm->GetNext();		// pTerm을 다음 노드로 이동
	}
}