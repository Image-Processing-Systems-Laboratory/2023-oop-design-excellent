#include "Polynomial.h"


/// <summary>
/// Term
/// </summary>
Term::Term() : Coefficient(0), Exponent(0), Next(nullptr) {

}

Term::Term(const Term& other) : Coefficient(other.Coefficient), Exponent(other.Exponent), Next(nullptr) {		// �����͸� �����ϰ� ����

}

Term::~Term() {

}

Term& Term::operator=(const Term& other) {		// ���� ������ �����ε�
	Coefficient = other.Coefficient;
	Exponent = other.Exponent;
	Next = nullptr;
	return *this;
}


void Term::SetCoefficient(int coeff)
{
	Coefficient = coeff;
}


void Term::SetExponent(int exponent)
{
	Exponent = exponent;
}


void Term::SetNext(Term* Next)
{
	this->Next = Next;
}


int Term::GetCoeff()
{
	return Coefficient;
}


int Term::GetExponent()
{
	return Exponent;
}


Term* Term::GetNext()
{
	return Next;
}


/// <summary>
/// Polynomial
/// </summary>
Polynomial::Polynomial() {
	Head = new Term;		// 0�� �⺻������ �߰�
}

Polynomial::~Polynomial() {
	Term* ptr = Head;
	Term* temp_next = nullptr;
	while (ptr) {
		temp_next = ptr->GetNext();
		delete ptr;
		ptr = temp_next;
	}
}

void Polynomial::Insert(Term* pTerm)		// ���� �����ڸ� ����� �����Ҵ� �Ѵ�.
{
	int exp = pTerm->GetExponent();
	if (exp < 0) {		// ������ ������ ��� �߰� ����
		return;
	}
	Term* ptr = Head;
	if (ptr->GetExponent() < exp) {			// �� �տ� �߰��ؾ� �� ���
		Term* temp = new Term;
		*temp = *pTerm;		// ���� �����ڷ� Next�� ������ ���� ����
		temp->SetNext(ptr);
		Head = temp;
		return;
	}

	Term* prev = nullptr;
	while (ptr) {
		if (ptr->GetExponent() == exp) {		// ���� �� �����Ҵ� ���� ����
			ptr->SetCoefficient(ptr->GetCoeff() + pTerm->GetCoeff());
			return;
		}
		else if (ptr->GetExponent() < exp) {		// �� ���� exponent�� �߰��ϸ� ���� ��忡 �߰�
			Term* temp = new Term;
			*temp = *pTerm;		// ���� �����ڷ� Next�� ������ ���� ����
			temp->SetNext(prev->GetNext());
			prev->SetNext(temp);
			return;
		}

		prev = ptr;
		ptr = ptr->GetNext();
	}
}


void Polynomial::PrintList()		// todo: ������ 0 �� �� ��� �ٲٱ�
{
	Term* ptr = Head;			// ù°�� (�ְ�����)
	if (ptr) {
		if(ptr->GetExponent() == 0)		// ������� ���
			std::cout << ptr->GetCoeff();
		else {
			if (ptr->GetCoeff() > 0) {		// ����� ����� ��� "+" ���
				if (ptr->GetCoeff() != 1)		// 1�� �ƴҰ�� ��� ���
					std::cout << ptr->GetCoeff();
				std::cout << "x^" << ptr->GetExponent();
			}
			else if (ptr->GetCoeff() == 0) {		// 0�� ��� ��� x
			}
			else if (ptr->GetCoeff() < 0) {
				if (ptr->GetCoeff() != -1)		// -1�� �ƴҰ�� ��� ���
					std::cout << ptr->GetCoeff();
				else
					std::cout << "-";		// -1�� ��� ��� ���� �� '-' ���
				std::cout << "x^" << ptr->GetExponent();
			}
		}
		ptr = ptr->GetNext();
	}
	while (ptr) {
		if (ptr->GetExponent() == 0)		// ����� ����
			break;
		if (ptr->GetCoeff() > 0) {		// ����� ����� ��� "+" ���
			std::cout << " + ";
			if (ptr->GetCoeff() != 1)		// 1�� �ƴҰ�� ��� ���
				std::cout << ptr->GetCoeff();
			if (ptr->GetExponent() == 1)
				std::cout << "x";
			else
				std::cout << "x^" << ptr->GetExponent();
		}
		else if (ptr->GetCoeff() == 0){		// 0�� ��� ��� x
		}
		else if (ptr->GetCoeff() < 0) {
			if (ptr->GetCoeff() != -1)		// -1�� �ƴҰ�� ��� ���
				std::cout << ptr->GetCoeff();
			else
				std::cout << " - ";		// -1�� ��� ��� ���� �� '-' ���
			if (ptr->GetExponent() == 1)
				std::cout << "x";
			else
				std::cout << "x^" << ptr->GetExponent();
		}
		ptr = ptr->GetNext();
	}

	if (ptr->GetExponent() == 0) {		// �������� (�����)
		if (ptr->GetCoeff() != 0) {
			if (ptr->GetCoeff() > 0){
				std::cout << " + ";
				std::cout << ptr->GetCoeff();
			}
			else {
				std::cout << " - ";
				std::cout << -ptr->GetCoeff();
			}
			
		}
	}

	std::cout << std::endl;
}


void Polynomial::Add(Polynomial& poly)
{
	Term* ptr1 = Head;
	Term* ptr2 = poly.Head;
	Term* prev = nullptr;		// ���� �� ������
	if (ptr1->GetExponent() < ptr2->GetExponent()) {			// ���ϴ� ���׽��� �ְ������� �� ū ���
		Term* temp = new Term;
		*temp = *ptr2;		// ���� �����ڸ� ���� �� ����
		temp->SetNext(ptr1);
		Head = temp;			// Head �缳��
		prev = Head;
		ptr2 = ptr2->GetNext();
	}

	while (ptr2) {
		int exp = ptr2->GetExponent();		// ���� ���� exponent

		while (ptr1) {
			if (ptr1->GetExponent() == exp) {		// exponent�� ���� ���� �߰��� ���
				ptr1->SetCoefficient(ptr1->GetCoeff() + ptr2->GetCoeff());		// ����� ������ ����
				break;
			}
			else if (ptr1->GetExponent() < exp) {		// �� ���� exponent�� �߰��ϸ� ���� ��� �ڿ� �߰�
				Term* temp = new Term;
				*temp = *ptr2;		// ���� �����ڸ� ���� �� ����
				temp->SetNext(prev->GetNext());
				prev->SetNext(temp);
				prev = temp;						// prev ����
				break;
			}


			prev = ptr1;
			ptr1 = ptr1->GetNext();
		}


		ptr2 = ptr2->GetNext();
	}
}


void Polynomial::Sub(Polynomial& poly)
{
	Term* ptr1 = Head;
	Term* ptr2 = poly.Head;
	Term* prev = nullptr;		// ���� �� ������
	if (ptr1->GetExponent() < ptr2->GetExponent()) {			// ���� ���׽��� �ְ������� �� ū ���
		Term* temp = new Term;
		temp->SetCoefficient(-(ptr2->GetCoeff()));		// ��ȣ ����
		temp->SetExponent(ptr2->GetExponent());
		temp->SetNext(ptr1);
		Head = temp;			// Head �缳��
		prev = Head;
		ptr2 = ptr2->GetNext();
	}

	while (ptr2) {
		int exp = ptr2->GetExponent();		// �� ���� exponent
		
		while (ptr1) {
			if (ptr1->GetExponent() == exp) {		// exponent�� ���� ���� �߰��� ���
				ptr1->SetCoefficient(ptr1->GetCoeff() - ptr2->GetCoeff());		// ����� ���� ����
				break;
			}
			else if (ptr1->GetExponent() < exp) {		// �� ���� exponent�� �߰��ϸ� ���� ��� �ڿ� �߰�
				Term* temp = new Term;
				temp->SetCoefficient(-(ptr2->GetCoeff()));		// ��ȣ ����
				temp->SetExponent(exp);
				temp->SetNext(prev->GetNext());
				prev->SetNext(temp);
				prev = temp;						// prev ����
				break;
			}


			prev = ptr1;
			ptr1 = ptr1->GetNext();
		}
		
		
		ptr2 = ptr2->GetNext();
	}
}
