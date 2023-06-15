#include "class.h"

//member functions of Sale class
Sale::Sale()                                            //멤버 변수를 초기화하는 생성자
{
	Price = 0;
}

Sale::Sale(double ThePrice)                             //인자로 전달 받은 값으로 멤버 변수를 초기화하는 생성자
{
	Price = ThePrice;
}

Sale::~Sale()                                           //파괴자
{
	Price = 0;
}

double Sale::GetPrice()                                 //Price 반환
{
	return Price;
}

double Sale::Bill()                                     //할인 가격을 계산하는 가상 함수
{
	return Price;
}

double Sale::Savings(Sale& Other)                       //다른 상품의 할인 가격과 비교하여 얼마나 절약했는지 계산
{
	//두 할인 가격 차이의 절댓값을 반환하기 위한 대소 비교 후 차이 값(큰 값 - 작은 값) 반환
	if (*this < Other) {                        // overloading한 < 관계 연산자 사용
		return Other.Bill() - this->Bill();
	}
	else {
		return this->Bill() - Other.Bill();
	}
}

bool Sale::operator <(Sale& Other)                      //관계 연산자 overloading
{
	//두 객체의 할인 가격의 대소 관계 비교
	if (this->Bill() < Other.Bill()) {
		return true;                //다른 객체의 할인 가격이 더 클 경우 true 반환
	}
	else {
		return false;               //자신 객체의 할인 가격이 더 클 경우 false 반환
	}
}


//member functions of DiscountSale class
DiscountSale::DiscountSale()                                    //멤버 변수를 초기화하는 생성자
{
	DiscountPercent = 0;
}

DiscountSale::DiscountSale(double ThePrice, double TheDiscount) : Sale(ThePrice)  //인자로 전달 받은 값으로 멤버 변수를 초기화하는 생성자
{
	DiscountPercent = TheDiscount;
}
DiscountSale::~DiscountSale()                                   //파괴자
{
	DiscountPercent = 0;
}

double DiscountSale::GetDiscount()                              //DiscountPercent 반환
{
	return DiscountPercent;
}

void DiscountSale::SetDiscount(double TheDiscount)              //DiscountPercent 설정
{
	DiscountPercent = TheDiscount;
}

double DiscountSale::Bill()                                     //할인 가격을 계산하는 가상 함수
{
	//할인 가격을 계산하여 반환
	return GetPrice() * (100 - DiscountPercent) / 100;
}

double DiscountSale::Savings(DiscountSale& Other)               //다른 상품의 할인 가격과 비교하여 얼마나 절약했는지 계산
{
	//두 할인 가격 차이의 절댓값을 반환하기 위한 대소 비교 후 차이 값(큰 값 - 작은 값) 반환
	if (*this < Other) {                        // overloading한 < 관계 연산자 사용
		return Other.Bill() - this->Bill();
	}
	else {
		return this->Bill() - Other.Bill();
	}
}

bool DiscountSale::operator <(DiscountSale& second)       //관계 연산자 overloading
{
	//두 객체의 할인 가격의 대소 관계 비교
	if (this->Bill() < second.Bill()) {
		return true;                //다른 객체의 할인 가격이 더 클 경우 true 반환
	}
	else {
		return false;               //자신 객체의 할인 가격이 더 클 경우 false 반환
	}
}