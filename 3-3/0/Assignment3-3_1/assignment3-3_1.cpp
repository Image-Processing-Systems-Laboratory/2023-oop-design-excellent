#include<iostream>
#include "Sale.h"

using namespace std;

int main()
{
	//변수 선언
	Sale count1;
	double price1, price2;
	char discount[10];
	cout << "=======================================" << endl;
	cout << "Price Compare Program" << endl;
	cout << "=======================================" << endl;

	//가격 입력받기
	cout << "Insert item1 price: $";
	cin >> price1;
	cout << "Insert item2 price: $";
	cin >> price2;

	//할인율 입력받기
	cout << "----------------------------------------" << endl;
	cout << "Insert discount percent: ";
	cin >> discount;
	cout << "----------------------------------------" << endl;


	//입력받은 값 저장
	DiscountSale dis1(price1, atof(discount));
	DiscountSale dis2(price2, atof(discount));
	//결과 출력
	cout << "Result: " << endl;
	//dis2에 저장된 값이 더 클 경우
	if (dis1 < dis2) {
		cout << "Discount price of item1 is cheaper." << endl;
		cout << "Saving discout price is $";
		cout << dis2.Savings(dis1);				//두 가격의 차 출력
	}
	//dis1에 저장된 값이 더 클 경우
	else {
		cout << "Discount price of item2 is cheaper." << endl;
		cout << "Saving discout price is $";
		cout << dis1.Savings(dis2);				//두 가격의 차 출력
	}

	return 0;
}