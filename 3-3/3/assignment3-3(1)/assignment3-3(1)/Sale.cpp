#include"Sale.h"

Sale::Sale()
{
	m_Price = 0;
}

Sale::Sale(double price)
{
	m_Price = price;
}

Sale::~Sale() {}

double Sale::getprice()
{
	return m_Price;
}

double Sale::bill()
{
	return 0;
}

double Sale::savings(Sale& Other)
{
	// 두 물품의 가격 차이 반환
	return abs(m_Price - Other.getprice());
}

bool Sale::operator<(Sale& Other)
{
	// 비교 연산자
	return (m_Price < Other.getprice()) ? true : false;
}

DiscountSale::DiscountSale()
{
	m_DiscountPercent = 0;
}

DiscountSale::DiscountSale(double price, double dc) : Sale(price)
{
	m_DiscountPercent = dc;
}

DiscountSale::~DiscountSale() {}

double DiscountSale::getdiscount()
{
	return m_DiscountPercent;
}

void DiscountSale::setdiscount(double dc)
{
	m_DiscountPercent = dc;
}

double DiscountSale::bill()
{
	// 할인률이 적용된 값 반환
	return getprice() -(getprice() * m_DiscountPercent) / 100;
}

double DiscountSale::savings(DiscountSale& Other)
{
	// 두 물품의 할인된 가격 차이 반환
	return abs(bill() - Other.bill());
}

bool DiscountSale::operator<(DiscountSale& Other)
{
	// 비교 연산자
	return (getprice() < Other.getprice()) ? true : false;
}