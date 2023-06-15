#include "poly.h"

Term::Term()
{
	m_Coefficient = 0;
	m_Exponent = 0;
	m_pNext = 0; // ��� ���� �ʱ�ȭ
}

Term::~Term()
{
	m_Coefficient = 0;
	m_Exponent = 0;
	m_pNext = 0; // �����Ҵ�� �޸𸮰� �����Ƿ� ��ǻ� �ʿ� X
}

void Term::SetCoeff(int coeff)
{
	m_Coefficient = coeff; // ��� ������ �� �Ҵ�
}

void Term::SetExponent(int exponent)
{
	m_Exponent = exponent;
}

int Term::GetCoeff()
{
	return m_Coefficient; // ��� ���� ��ȯ
}

int Term::GetExponent()
{
	return m_Exponent;
}

void Term::SetNext(Term* pNext)
{
	m_pNext = pNext; // �� �Ҵ�
}

Term* Term::GetNext()
{
	return m_pNext; // ��ȯ
}

Polynomial::Polynomial()
{
	m_pHead = 0; // ��� ���� �ʱ�ȭ
}

Polynomial::~Polynomial()
{
	Term* tmp;

	while (m_pHead)
	{
		tmp = m_pHead;
		m_pHead = m_pHead->GetNext();
		delete tmp; // m_pHead���� ������ ������ �޸� ����
	}
}

void Polynomial::Insert(Term* pTerm)
{
	Term* prev;

	if (!m_pHead) // ����Ʈ�� ���������
	{
		m_pHead = pTerm; // pTerm�� head
		return;
	}
	if (m_pHead->GetExponent() < pTerm->GetExponent()) // pTerm�� head���� ������ ������
	{
		pTerm->SetNext(m_pHead); // pTerm�� ������ head
		m_pHead = pTerm; // pTerm�� �� head
		return;
	}
	for (prev = m_pHead; prev->GetNext(); prev = prev->GetNext())
	{
		if (prev->GetNext()->GetExponent() < pTerm->GetExponent()) // pTerm�� ��ġ�� ã����
		{
			pTerm->SetNext(prev->GetNext()); // pTerm�� ������ prev�� ���� ���
			prev->SetNext(pTerm); // prev�� ���� ��尡 pTerm
			return;
		}
	}
	prev->SetNext(pTerm); // prev�� ������ ������ ���� prev�� ���� ��尡 pTerm
}

void Polynomial::PrintList()
{
	for (Term* tmp = m_pHead; tmp; tmp = tmp->GetNext())
	{
		if (tmp != m_pHead && tmp->GetCoeff() > 0)
			std::cout << "+"; // ���� ���� �ƴѵ� ����� ����� + ���
		if (tmp->GetCoeff() != 1 || tmp->GetExponent() == 0)
		{ // ����� 1�� �ƴϰų� ������ 0�� �ƴ� �� ���
			if (tmp->GetCoeff() == -1 && tmp->GetExponent() != 0) // ������� �ƴѵ� ����� -1
				std::cout << '-'; // -�� ���
			else
				std::cout << tmp->GetCoeff(); // ��� ���
		}
		if (tmp->GetExponent() != 0) // ������ 0�� �ƴϸ�
			std::cout << "x^" << tmp->GetExponent(); // x^(����)���
	}
	std::cout << std::endl;
}

void Polynomial::Add(Polynomial& poly)
{
	Term* tem;
	Term* prev;
	bool flag;

	for (Term* tmp = poly.m_pHead; tmp; tmp = tmp->GetNext()) // �� �ϳ��� �߰�
	{
		prev = m_pHead;
		flag = false; // ������ ������ ���� �ִ����� �Ǻ��ϴ� �÷���
		for (Term* tmp2 = m_pHead;
			tmp2 && tmp2->GetExponent() >= tmp->GetExponent();
			prev = tmp2, tmp2 = tmp2->GetNext())
		{
			if (tmp2->GetExponent() == tmp->GetExponent()) // ���� ������ ���� ������
			{
				tmp2->SetCoeff(tmp2->GetCoeff() + tmp->GetCoeff()); // ��������� ����
				flag = true; // ������ ������ ���� �ִٴ� �÷��� ����
			}
			if (tmp2->GetCoeff() == 0) // ���� ��� ����� 0�� �Ǹ�
			{
				if (prev == tmp2) // ���� ��带 ���־� �Ѵٸ�
					m_pHead = m_pHead->GetNext(); // m_pHead�� ���� ���� �ٲ�
				else
					prev->SetNext(tmp2->GetNext()); // prev�� tmp2�� �ƴ� ���� ���� ����Ű�� ��
				delete tmp2; // ����� 0�� ��� ����
				break;
			}
		}
		if (!flag) // ���� ������ ���� ���ٸ�
		{
			tem = new Term;
			tem->SetCoeff(tmp->GetCoeff());
			tem->SetExponent(tmp->GetExponent());
			this->Insert(tem); // ���� ������ ������ ����Ʈ�� �߰�
		}
	}
}

void Polynomial::Sub(Polynomial& poly)
{
	Term* tem;
	Term* prev;
	bool flag;

	for (Term* tmp = poly.m_pHead; tmp; tmp = tmp->GetNext()) // Add �Լ��� ���� ����
	{
		prev = m_pHead;
		flag = false;
		for (Term* tmp2 = m_pHead;
			tmp2 && tmp2->GetExponent() >= tmp->GetExponent();
			prev = tmp2, tmp2 = tmp2->GetNext())
		{
			if (tmp2->GetExponent() == tmp->GetExponent())
			{
				tmp2->SetCoeff(tmp2->GetCoeff() - tmp->GetCoeff()); // +�� -�� �ٲ�
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