#include "Sale.h"

//����Ʈ ������
Sale::Sale() {
	//���� �ʱ�ȭ
	this->Price = 0;
}
//�Ű����� ������
Sale::Sale(double ThePrice) {
	this->Price = ThePrice;		//�� ����
}
//�Ҹ���
Sale::~Sale() {}

//Price�� ����Ȱ��� ��ȯ�ϴ� �Լ�
double Sale::GetPrice() {
	return this->Price;			//Price ��ȯ
}
//����� ����� ��ȯ�ϴ� �Լ�
double Sale::Bill() {
	return  this->GetPrice();	//GetPrice ��ȯ
}
//�� ����� ���� ��ȯ��
double Sale::Savings(Sale& Other) {
	return this->Price - Other.GetPrice();	//�� ���� �� ��ȯ
}
// <operator �Է� ���� ���ݺ��� ũ�� true, ������ false�� ��ȯ�ϴ� �Լ�
bool Sale::operator<(Sale& Other) {
	if (this->Price < Other.GetPrice())		//this->Price�� �� ũ��
		return true;					//true ��ȯ
	//Other.GetPrice()�� �� ũ��
	return false;						//false ��ȯ
}



//����Ʈ ������
DiscountSale::DiscountSale() {
	//���� �ʱ�ȭ
	this->Discount = 0;
}
//�Ű����� ������(Sale �Լ��� ����� Price�� ����)
DiscountSale::DiscountSale(double ThePrice, double theDiscount) :Sale(ThePrice) {
	this->Discount = theDiscount;				//�� ����
}
//�Ҹ���
DiscountSale::~DiscountSale() {}
//�������� ��ȯ�ϴ� �Լ�
double DiscountSale::GetDiscount() {
	return this->Discount;			//Discount ��ȯ
}
//�������� �����ϴ� �Լ�
void DiscountSale::SetDiscount(double discount) {
	this->Discount = discount;		//discount ����
}
//����� ����� ��ȯ�ϴ� �Լ�
double DiscountSale::Bill() {
	return this->GetPrice() * ((100 - this->Discount) / 100);
}
//�� ����� ���� ��ȯ��
double DiscountSale::Savings(DiscountSale& Other) {
	return this->Bill() - Other.Bill();			//�� ���� �� ��ȯ
}
// <operator �Է� ���� ���ݺ��� ũ�� true, ������ false�� ��ȯ�ϴ� �Լ�
bool DiscountSale::operator<(DiscountSale& second) {
	if (this->Bill() < second.Bill())		//this->Bill()�� �� ũ��
		return true;					//true ��ȯ
	//second.Bill()�� �� ũ��
	return false;						//false ��ȯ
}