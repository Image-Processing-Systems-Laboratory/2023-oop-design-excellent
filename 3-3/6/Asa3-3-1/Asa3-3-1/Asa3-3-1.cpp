#include "sale.h"

using namespace std;

int main()
{
	double price1 = 0;
	double price2 = 0;
	cout << "===== price compare program =====" << endl;
	cout << "Please input item 1 price!\n>>> $";
	cin >> price1;
	if (cin.fail() || price1 < 0)
	{
		cerr << "Error: you inputed non-double something or inputed negative number." << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Please input item 2 price!\n>>> $";
	cin >> price2;
	if (cin.fail() || price2 < 0)
	{
		cerr << "Error: you inputed non-double something or inputed negative number." << endl;
		exit(EXIT_FAILURE);
	}

	// 두 개 item의 price를 받되,
	// price에 double형이 아니거나, 혹은 음수가 입력된 경우를 catch
	string Sale_percentage;
	cout << "\n===== insert discount percentage =====" << endl;
	cout << "Please input discount percent with %!";
	while (1)
	{
		cout << "\n>>> ";
		cin >> Sale_percentage;
		if (Sale_percentage.back() != '%')
		{
			cerr << "Error: last char is not %, please re-input!";
			cin.clear();
			continue;
		}
		else break;
	}
	Sale_percentage.pop_back();
	double Percentage = strtof(Sale_percentage.c_str(), nullptr);

	if (cin.fail() || Percentage < 0)
	{
		cerr << "Error: you inputed non-double something or inputed negative number." << endl;
		exit(EXIT_FAILURE);
	}
	if (Percentage > 100)
	{
		cerr << "Error: you inputed over 100!" << endl;
		exit(EXIT_FAILURE);
	}
	// 할인률을 받되 입력 형식은 (0~100)%
	// 수가 0보다 작거나, 혹은 100보다 크거나를 catch
	// 또한, 입력 형식 중 가장 끝 문자가 %가 아닌 경우에도 catch

	DiscountSale Dis_Priceno1(price1, Percentage);
	DiscountSale Dis_Priceno2(price2, Percentage);
	// 객체 생성, 생성 클래스는 Sale이 아닌 DiscountSale로 생성
	cout << "\n===== Final Price of apply discount " << Percentage << "% =====\n" << "item #1 >>> $" << Dis_Priceno1.Bill() << "\nitem #2 >>> $" << Dis_Priceno2.Bill() << endl;
	
	cout << "\nResult:" << endl;
	if (Percentage == 100)
	{
		cout << "Price of item 1 and 2 is same because discount percentage is 100!" << endl;
		return 1;
	}
	// 할인율이 100%여서 두 item의 가격이 동일한 경우
	
	if (Dis_Priceno1 < Dis_Priceno2)
	{
		cout << "Discount price of item #1 is cheaper!\nSaving discount price is>>> $" << Dis_Priceno1.Savings(Dis_Priceno2) << endl;
		return 1;
	}
	else
	{
		cout << "Discount price of item #2 is cheaper!\nSaving discount price is>>> $" << Dis_Priceno2.Savings(Dis_Priceno1) << endl;
		return 1;
	}
	
	return 0;
}
