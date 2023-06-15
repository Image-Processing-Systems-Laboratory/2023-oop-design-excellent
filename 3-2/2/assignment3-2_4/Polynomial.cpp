#include "Polynomial.h"


/// <summary>
/// Term
/// </summary>
Term::Term() : Coefficient(0), Exponent(0), Next(nullptr) {

}

Term::Term(const Term& other) : Coefficient(other.Coefficient), Exponent(other.Exponent), Next(nullptr) {		// 포인터를 제외하고 복사

}

Term::~Term() {

}

Term& Term::operator=(const Term& other) {		// 대입 연산자 오버로딩
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
	Head = new Term;		// 0을 기본항으로 추가
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

void Polynomial::Insert(Term* pTerm)		// 대입 연산자를 사용해 동적할당 한다.
{
	int exp = pTerm->GetExponent();
	if (exp < 0) {		// 지수가 음수일 경우 추가 안함
		return;
	}
	Term* ptr = Head;
	if (ptr->GetExponent() < exp) {			// 맨 앞에 추가해야 될 경우
		Term* temp = new Term;
		*temp = *pTerm;		// 대입 연산자로 Next를 제외한 값을 복사
		temp->SetNext(ptr);
		Head = temp;
		return;
	}

	Term* prev = nullptr;
	while (ptr) {
		if (ptr->GetExponent() == exp) {		// 같을 때 동적할당 없이 갱신
			ptr->SetCoefficient(ptr->GetCoeff() + pTerm->GetCoeff());
			return;
		}
		else if (ptr->GetExponent() < exp) {		// 더 작은 exponent를 발견하면 이전 노드에 추가
			Term* temp = new Term;
			*temp = *pTerm;		// 대입 연산자로 Next를 제외한 값을 복사
			temp->SetNext(prev->GetNext());
			prev->SetNext(temp);
			return;
		}

		prev = ptr;
		ptr = ptr->GetNext();
	}
}


void Polynomial::PrintList()		// todo: 음수나 0 일 때 출력 바꾸기
{
	Term* ptr = Head;			// 첫째항 (최고차항)
	if (ptr) {
		if(ptr->GetExponent() == 0)		// 상수항인 경우
			std::cout << ptr->GetCoeff();
		else {
			if (ptr->GetCoeff() > 0) {		// 계수가 양수일 경우 "+" 출력
				if (ptr->GetCoeff() != 1)		// 1이 아닐경우 계수 출력
					std::cout << ptr->GetCoeff();
				std::cout << "x^" << ptr->GetExponent();
			}
			else if (ptr->GetCoeff() == 0) {		// 0일 경우 출력 x
			}
			else if (ptr->GetCoeff() < 0) {
				if (ptr->GetCoeff() != -1)		// -1이 아닐경우 계수 출력
					std::cout << ptr->GetCoeff();
				else
					std::cout << "-";		// -1일 경우 계수 생략 및 '-' 출력
				std::cout << "x^" << ptr->GetExponent();
			}
		}
		ptr = ptr->GetNext();
	}
	while (ptr) {
		if (ptr->GetExponent() == 0)		// 상수항 예외
			break;
		if (ptr->GetCoeff() > 0) {		// 계수가 양수일 경우 "+" 출력
			std::cout << " + ";
			if (ptr->GetCoeff() != 1)		// 1이 아닐경우 계수 출력
				std::cout << ptr->GetCoeff();
			if (ptr->GetExponent() == 1)
				std::cout << "x";
			else
				std::cout << "x^" << ptr->GetExponent();
		}
		else if (ptr->GetCoeff() == 0){		// 0일 경우 출력 x
		}
		else if (ptr->GetCoeff() < 0) {
			if (ptr->GetCoeff() != -1)		// -1이 아닐경우 계수 출력
				std::cout << ptr->GetCoeff();
			else
				std::cout << " - ";		// -1일 경우 계수 생략 및 '-' 출력
			if (ptr->GetExponent() == 1)
				std::cout << "x";
			else
				std::cout << "x^" << ptr->GetExponent();
		}
		ptr = ptr->GetNext();
	}

	if (ptr->GetExponent() == 0) {		// 마지막항 (상수항)
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
	Term* prev = nullptr;		// 이전 항 포인터
	if (ptr1->GetExponent() < ptr2->GetExponent()) {			// 더하는 다항식의 최고차수가 더 큰 경우
		Term* temp = new Term;
		*temp = *ptr2;		// 대입 연산자를 통해 값 복사
		temp->SetNext(ptr1);
		Head = temp;			// Head 재설정
		prev = Head;
		ptr2 = ptr2->GetNext();
	}

	while (ptr2) {
		int exp = ptr2->GetExponent();		// 더할 항의 exponent

		while (ptr1) {
			if (ptr1->GetExponent() == exp) {		// exponent가 같은 것을 발견한 경우
				ptr1->SetCoefficient(ptr1->GetCoeff() + ptr2->GetCoeff());		// 계수의 합으로 설정
				break;
			}
			else if (ptr1->GetExponent() < exp) {		// 더 작은 exponent를 발견하면 이전 노드 뒤에 추가
				Term* temp = new Term;
				*temp = *ptr2;		// 대입 연산자를 통해 값 복사
				temp->SetNext(prev->GetNext());
				prev->SetNext(temp);
				prev = temp;						// prev 갱신
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
	Term* prev = nullptr;		// 이전 항 포인터
	if (ptr1->GetExponent() < ptr2->GetExponent()) {			// 빼는 다항식의 최고차수가 더 큰 경우
		Term* temp = new Term;
		temp->SetCoefficient(-(ptr2->GetCoeff()));		// 부호 반전
		temp->SetExponent(ptr2->GetExponent());
		temp->SetNext(ptr1);
		Head = temp;			// Head 재설정
		prev = Head;
		ptr2 = ptr2->GetNext();
	}

	while (ptr2) {
		int exp = ptr2->GetExponent();		// 뺄 항의 exponent
		
		while (ptr1) {
			if (ptr1->GetExponent() == exp) {		// exponent가 같은 것을 발견한 경우
				ptr1->SetCoefficient(ptr1->GetCoeff() - ptr2->GetCoeff());		// 계수의 차로 설정
				break;
			}
			else if (ptr1->GetExponent() < exp) {		// 더 작은 exponent를 발견하면 이전 노드 뒤에 추가
				Term* temp = new Term;
				temp->SetCoefficient(-(ptr2->GetCoeff()));		// 부호 반전
				temp->SetExponent(exp);
				temp->SetNext(prev->GetNext());
				prev->SetNext(temp);
				prev = temp;						// prev 갱신
				break;
			}


			prev = ptr1;
			ptr1 = ptr1->GetNext();
		}
		
		
		ptr2 = ptr2->GetNext();
	}
}
