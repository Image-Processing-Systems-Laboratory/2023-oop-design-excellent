#include "class.h"

//member functions of Sale class
Sale::Sale()                                            //��� ������ �ʱ�ȭ�ϴ� ������
{
	Price = 0;
}

Sale::Sale(double ThePrice)                             //���ڷ� ���� ���� ������ ��� ������ �ʱ�ȭ�ϴ� ������
{
	Price = ThePrice;
}

Sale::~Sale()                                           //�ı���
{
	Price = 0;
}

double Sale::GetPrice()                                 //Price ��ȯ
{
	return Price;
}

double Sale::Bill()                                     //���� ������ ����ϴ� ���� �Լ�
{
	return Price;
}

double Sale::Savings(Sale& Other)                       //�ٸ� ��ǰ�� ���� ���ݰ� ���Ͽ� �󸶳� �����ߴ��� ���
{
	//�� ���� ���� ������ ������ ��ȯ�ϱ� ���� ��� �� �� ���� ��(ū �� - ���� ��) ��ȯ
	if (*this < Other) {                        // overloading�� < ���� ������ ���
		return Other.Bill() - this->Bill();
	}
	else {
		return this->Bill() - Other.Bill();
	}
}

bool Sale::operator <(Sale& Other)                      //���� ������ overloading
{
	//�� ��ü�� ���� ������ ��� ���� ��
	if (this->Bill() < Other.Bill()) {
		return true;                //�ٸ� ��ü�� ���� ������ �� Ŭ ��� true ��ȯ
	}
	else {
		return false;               //�ڽ� ��ü�� ���� ������ �� Ŭ ��� false ��ȯ
	}
}


//member functions of DiscountSale class
DiscountSale::DiscountSale()                                    //��� ������ �ʱ�ȭ�ϴ� ������
{
	DiscountPercent = 0;
}

DiscountSale::DiscountSale(double ThePrice, double TheDiscount) : Sale(ThePrice)  //���ڷ� ���� ���� ������ ��� ������ �ʱ�ȭ�ϴ� ������
{
	DiscountPercent = TheDiscount;
}
DiscountSale::~DiscountSale()                                   //�ı���
{
	DiscountPercent = 0;
}

double DiscountSale::GetDiscount()                              //DiscountPercent ��ȯ
{
	return DiscountPercent;
}

void DiscountSale::SetDiscount(double TheDiscount)              //DiscountPercent ����
{
	DiscountPercent = TheDiscount;
}

double DiscountSale::Bill()                                     //���� ������ ����ϴ� ���� �Լ�
{
	//���� ������ ����Ͽ� ��ȯ
	return GetPrice() * (100 - DiscountPercent) / 100;
}

double DiscountSale::Savings(DiscountSale& Other)               //�ٸ� ��ǰ�� ���� ���ݰ� ���Ͽ� �󸶳� �����ߴ��� ���
{
	//�� ���� ���� ������ ������ ��ȯ�ϱ� ���� ��� �� �� ���� ��(ū �� - ���� ��) ��ȯ
	if (*this < Other) {                        // overloading�� < ���� ������ ���
		return Other.Bill() - this->Bill();
	}
	else {
		return this->Bill() - Other.Bill();
	}
}

bool DiscountSale::operator <(DiscountSale& second)       //���� ������ overloading
{
	//�� ��ü�� ���� ������ ��� ���� ��
	if (this->Bill() < second.Bill()) {
		return true;                //�ٸ� ��ü�� ���� ������ �� Ŭ ��� true ��ȯ
	}
	else {
		return false;               //�ڽ� ��ü�� ���� ������ �� Ŭ ��� false ��ȯ
	}
}