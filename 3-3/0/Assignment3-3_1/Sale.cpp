#include "Sale.h"

//디폴트 생성자
Sale::Sale() {
	//변수 초기화
	this->Price = 0;
}
//매개변수 생성자
Sale::Sale(double ThePrice) {
	this->Price = ThePrice;		//값 저장
}
//소멸자
Sale::~Sale() {}

//Price에 저장된값을 반환하는 함수
double Sale::GetPrice() {
	return this->Price;			//Price 반환
}
//저장된 요금을 반환하는 함수
double Sale::Bill() {
	return  this->GetPrice();	//GetPrice 반환
}
//두 요금의 차를 반환함
double Sale::Savings(Sale& Other) {
	return this->Price - Other.GetPrice();	//두 값의 차 반환
}
// <operator 입력 받은 가격보다 크면 true, 작으면 false를 반환하는 함수
bool Sale::operator<(Sale& Other) {
	if (this->Price < Other.GetPrice())		//this->Price가 더 크면
		return true;					//true 반환
	//Other.GetPrice()가 더 크면
	return false;						//false 반환
}



//디폴트 생성자
DiscountSale::DiscountSale() {
	//변수 초기화
	this->Discount = 0;
}
//매개변수 생성자(Sale 함수에 저장된 Price값 저장)
DiscountSale::DiscountSale(double ThePrice, double theDiscount) :Sale(ThePrice) {
	this->Discount = theDiscount;				//값 저장
}
//소멸자
DiscountSale::~DiscountSale() {}
//할인율을 반환하는 함수
double DiscountSale::GetDiscount() {
	return this->Discount;			//Discount 반환
}
//할인율을 저장하는 함수
void DiscountSale::SetDiscount(double discount) {
	this->Discount = discount;		//discount 저장
}
//저장된 요금을 반환하는 함수
double DiscountSale::Bill() {
	return this->GetPrice() * ((100 - this->Discount) / 100);
}
//두 요금의 차를 반환함
double DiscountSale::Savings(DiscountSale& Other) {
	return this->Bill() - Other.Bill();			//두 값의 차 반환
}
// <operator 입력 받은 가격보다 크면 true, 작으면 false를 반환하는 함수
bool DiscountSale::operator<(DiscountSale& second) {
	if (this->Bill() < second.Bill())		//this->Bill()이 더 크면
		return true;					//true 반환
	//second.Bill()이 더 크면
	return false;						//false 반환
}