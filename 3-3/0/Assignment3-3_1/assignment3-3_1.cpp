#include<iostream>
#include "Sale.h"

using namespace std;

int main()
{
	//���� ����
	Sale count1;
	double price1, price2;
	char discount[10];
	cout << "=======================================" << endl;
	cout << "Price Compare Program" << endl;
	cout << "=======================================" << endl;

	//���� �Է¹ޱ�
	cout << "Insert item1 price: $";
	cin >> price1;
	cout << "Insert item2 price: $";
	cin >> price2;

	//������ �Է¹ޱ�
	cout << "----------------------------------------" << endl;
	cout << "Insert discount percent: ";
	cin >> discount;
	cout << "----------------------------------------" << endl;


	//�Է¹��� �� ����
	DiscountSale dis1(price1, atof(discount));
	DiscountSale dis2(price2, atof(discount));
	//��� ���
	cout << "Result: " << endl;
	//dis2�� ����� ���� �� Ŭ ���
	if (dis1 < dis2) {
		cout << "Discount price of item1 is cheaper." << endl;
		cout << "Saving discout price is $";
		cout << dis2.Savings(dis1);				//�� ������ �� ���
	}
	//dis1�� ����� ���� �� Ŭ ���
	else {
		cout << "Discount price of item2 is cheaper." << endl;
		cout << "Saving discout price is $";
		cout << dis1.Savings(dis2);				//�� ������ �� ���
	}

	return 0;
}