#include "sale.h"

using namespace std;

// Sale�� �⺻ ������ ����
Sale::Sale() : Price(0) { };
Sale::Sale(double price) : Price(price) { };
Sale::~Sale() { };

double Sale::GetPrice() { return Price; };

double Sale::Bill() { return Price; };

double Sale::Savings(Sale& other) { return Price < other.Price ? other.Price - Price : Price - other.Price; };

bool Sale::operator< (Sale& other) { return this->Price < other.Price ? true : false; }

// �ڽ� Ŭ���� DiscountSale�� �⺻ ������ ����
DiscountSale::DiscountSale() : discount(0) { };
DiscountSale::DiscountSale(double price, double discount) : Sale(price), discount(discount) { };
DiscountSale::~DiscountSale() { };
// DiscountSale(double price, double discount)�� ���� �ָ��� �ʿ䰡 �ִ�.
// Sale�� ��ӹ޾����Ƿ�, main�� ������ ��ü�� ���Ͽ� discount ���� price ���� �� �� ���� �� �ִ�.
// �ٸ�, Sale Ŭ������ ���� SetPrice()�� �����Ƿ�, discount�� ���� price�� ������ ���� ����.

double DiscountSale::GetDiscount() { return discount; };

void DiscountSale::SetDiscount(double Percentage) { discount = Percentage; };

double DiscountSale::Bill()
{
	double Price_discounted = this->GetPrice() -(this->GetPrice() * (discount / 100.0));
	return Price_discounted;
}
// this->GetPrice()�� ��ü�� Sale()�� ������ �ֱ� ������ ������ ����

double DiscountSale::Savings(DiscountSale& other)
{
	double price1 = this->Bill();
	double price2 = other.Bill();

	return price2 - price1;
}
// Bill�� ���Ͽ� ���η��� ����� ������ ���� ��
// ���̰��� return
// �̶� ��ȣ�� �Ű��� �ϴµ�, main �Լ����� < �� ���Ͽ� ���� ū �� �����ϹǷ� ���� ��ȣ�� �Ű澲�� �ʴ´�.

bool DiscountSale::operator < (DiscountSale& second)
{
	double price1 = this->Bill();
	double price2 = second.Bill();
	return price1 < price2;
}
// �켱 Bill�� ���Ͽ� ���η��� ����� ������ ���� ��
// < ���꿡 �°� true Ȥ�� false�� return