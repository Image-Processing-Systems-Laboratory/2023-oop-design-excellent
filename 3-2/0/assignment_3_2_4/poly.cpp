#include "poly.h"

Term::Term()
{
	m_Coefficient = 0;
	m_Exponent = 0;
	m_pNext = 0; // 멤버 변수 초기화
}

Term::~Term()
{
	m_Coefficient = 0;
	m_Exponent = 0;
	m_pNext = 0; // 동적할당된 메모리가 없으므로 사실상 필요 X
}

void Term::SetCoeff(int coeff)
{
	m_Coefficient = coeff; // 멤버 변수에 값 할당
}

void Term::SetExponent(int exponent)
{
	m_Exponent = exponent;
}

int Term::GetCoeff()
{
	return m_Coefficient; // 멤버 변수 반환
}

int Term::GetExponent()
{
	return m_Exponent;
}

void Term::SetNext(Term* pNext)
{
	m_pNext = pNext; // 값 할당
}

Term* Term::GetNext()
{
	return m_pNext; // 반환
}

Polynomial::Polynomial()
{
	m_pHead = 0; // 멤버 변수 초기화
}

Polynomial::~Polynomial()
{
	Term* tmp;

	while (m_pHead)
	{
		tmp = m_pHead;
		m_pHead = m_pHead->GetNext();
		delete tmp; // m_pHead부터 마지막 노드까지 메모리 해제
	}
}

void Polynomial::Insert(Term* pTerm)
{
	Term* prev;

	if (!m_pHead) // 리스트가 비어있으면
	{
		m_pHead = pTerm; // pTerm이 head
		return;
	}
	if (m_pHead->GetExponent() < pTerm->GetExponent()) // pTerm이 head보다 차수가 높으면
	{
		pTerm->SetNext(m_pHead); // pTerm의 다음이 head
		m_pHead = pTerm; // pTerm이 새 head
		return;
	}
	for (prev = m_pHead; prev->GetNext(); prev = prev->GetNext())
	{
		if (prev->GetNext()->GetExponent() < pTerm->GetExponent()) // pTerm의 위치를 찾으면
		{
			pTerm->SetNext(prev->GetNext()); // pTerm의 다음이 prev의 다음 노드
			prev->SetNext(pTerm); // prev의 다음 노드가 pTerm
			return;
		}
	}
	prev->SetNext(pTerm); // prev가 마지막 노드까지 가면 prev의 다음 노드가 pTerm
}

void Polynomial::PrintList()
{
	for (Term* tmp = m_pHead; tmp; tmp = tmp->GetNext())
	{
		if (tmp != m_pHead && tmp->GetCoeff() > 0)
			std::cout << "+"; // 시작 항이 아닌데 계수가 양수면 + 출력
		if (tmp->GetCoeff() != 1 || tmp->GetExponent() == 0)
		{ // 계수가 1이 아니거나 차수가 0이 아닐 때 출력
			if (tmp->GetCoeff() == -1 && tmp->GetExponent() != 0) // 상수항이 아닌데 계수가 -1
				std::cout << '-'; // -만 출력
			else
				std::cout << tmp->GetCoeff(); // 계수 출력
		}
		if (tmp->GetExponent() != 0) // 차수가 0이 아니면
			std::cout << "x^" << tmp->GetExponent(); // x^(차수)출력
	}
	std::cout << std::endl;
}

void Polynomial::Add(Polynomial& poly)
{
	Term* tem;
	Term* prev;
	bool flag;

	for (Term* tmp = poly.m_pHead; tmp; tmp = tmp->GetNext()) // 항 하나씩 추가
	{
		prev = m_pHead;
		flag = false; // 동일한 차수의 항이 있는지를 판별하는 플래그
		for (Term* tmp2 = m_pHead;
			tmp2 && tmp2->GetExponent() >= tmp->GetExponent();
			prev = tmp2, tmp2 = tmp2->GetNext())
		{
			if (tmp2->GetExponent() == tmp->GetExponent()) // 동일 차수의 항이 있으면
			{
				tmp2->SetCoeff(tmp2->GetCoeff() + tmp->GetCoeff()); // 계수끼리만 더함
				flag = true; // 동일한 차수의 항이 있다는 플래그 세움
			}
			if (tmp2->GetCoeff() == 0) // 연산 결과 계수가 0이 되면
			{
				if (prev == tmp2) // 시작 노드를 없애야 한다면
					m_pHead = m_pHead->GetNext(); // m_pHead를 다음 노드로 바꿈
				else
					prev->SetNext(tmp2->GetNext()); // prev를 tmp2가 아닌 다음 노드로 가리키게 함
				delete tmp2; // 계수가 0인 노드 제거
				break;
			}
		}
		if (!flag) // 동일 차수의 항이 없다면
		{
			tem = new Term;
			tem->SetCoeff(tmp->GetCoeff());
			tem->SetExponent(tmp->GetExponent());
			this->Insert(tem); // 항의 정보를 복사해 리스트에 추가
		}
	}
}

void Polynomial::Sub(Polynomial& poly)
{
	Term* tem;
	Term* prev;
	bool flag;

	for (Term* tmp = poly.m_pHead; tmp; tmp = tmp->GetNext()) // Add 함수가 거의 동일
	{
		prev = m_pHead;
		flag = false;
		for (Term* tmp2 = m_pHead;
			tmp2 && tmp2->GetExponent() >= tmp->GetExponent();
			prev = tmp2, tmp2 = tmp2->GetNext())
		{
			if (tmp2->GetExponent() == tmp->GetExponent())
			{
				tmp2->SetCoeff(tmp2->GetCoeff() - tmp->GetCoeff()); // +를 -로 바꿈
				flag = true;
			}
			if (tmp2->GetCoeff() == 0)
			{
				if (prev == tmp2)
					m_pHead = m_pHead->GetNext();
				else
					prev->SetNext(tmp2->GetNext());
				delete tmp2;
				break;
			}
		}
		if (!flag)
		{
			tem = new Term;
			tem->SetCoeff(tmp->GetCoeff() * -1);
			tem->SetExponent(tmp->GetExponent());
			this->Insert(tem);
		}
	}
}