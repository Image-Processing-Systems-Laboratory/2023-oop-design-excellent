#include"Sale.h"

int main(void) 
{
	// 테스트용 코드
	double a, b, dc;

	cout << "Insert item1 price: $";
	cin >> a;
	cout << "Insert item2 price: $";
	cin >> b;
	cout << "Insert discount percent(%): ";
	cin >> dc;

	DiscountSale item1(a, dc);
	DiscountSale item2(b, dc);

	if (a == b) // 가격이 같은 경우
	{
		cout << "Discount price of both items is the same." << endl;
	}
	else if (item1 < item2) // item1이 더 싼 경우
	{
		cout << "Discount price of item1 is cheaper." << endl;
		cout << "Saving discount price is $" << item1.savings(item2) << endl;
	}
	else // item2가 더 싼 경우
	{
		cout << "Discount price of item2 is cheaper." << endl;
		cout << "Saving discount price is $" << item2.savings(item1) << endl;
	}

	return 0;
}