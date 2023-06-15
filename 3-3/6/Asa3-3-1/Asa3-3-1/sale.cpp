#include "sale.h"

using namespace std;

// Sale의 기본 생성자 정의
Sale::Sale() : Price(0) { };
Sale::Sale(double price) : Price(price) { };
Sale::~Sale() { };

double Sale::GetPrice() { return Price; };

double Sale::Bill() { return Price; };

double Sale::Savings(Sale& other) { return Price < other.Price ? other.Price - Price : Price - other.Price; };

bool Sale::operator< (Sale& other) { return this->Price < other.Price ? true : false; }

// 자식 클래스 DiscountSale의 기본 생성자 정의
DiscountSale::DiscountSale() : discount(0) { };
DiscountSale::DiscountSale(double price, double discount) : Sale(price), discount(discount) { };
DiscountSale::~DiscountSale() { };
// DiscountSale(double price, double discount)을 조금 주목할 필요가 있다.
// Sale을 상속받았으므로, main에 선언한 객체에 대하여 discount 값과 price 값을 둘 다 가질 수 있다.
// 다만, Sale 클래스에 따로 SetPrice()가 없으므로, discount된 값을 price에 갱신할 수는 없다.

double DiscountSale::GetDiscount() { return discount; };

void DiscountSale::SetDiscount(double Percentage) { discount = Percentage; };

double DiscountSale::Bill()
{
	double Price_discounted = this->GetPrice() -(this->GetPrice() * (discount / 100.0));
	return Price_discounted;
}
// this->GetPrice()는 객체가 Sale()을 가지고 있기 때문에 가능한 연산

double DiscountSale::Savings(DiscountSale& other)
{
	double price1 = this->Bill();
	double price2 = other.Bill();

	return price2 - price1;
}
// Bill을 통하여 할인률이 적용된 가격을 구한 뒤
// 차이값을 return
// 이때 부호를 신경써야 하는데, main 함수에서 < 을 통하여 누가 큰 지 구별하므로 따로 부호를 신경쓰지 않는다.

bool DiscountSale::operator < (DiscountSale& second)
{
	double price1 = this->Bill();
	double price2 = second.Bill();
	return price1 < price2;
}
// 우선 Bill을 통하여 할인률이 적용된 가격을 구한 뒤
// < 연산에 맞게 true 혹은 false를 return