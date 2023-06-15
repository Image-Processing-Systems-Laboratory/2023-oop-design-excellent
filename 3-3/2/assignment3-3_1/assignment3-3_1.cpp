#include <iostream>
#include <string>
using namespace std;

class Sale // 세일 클래스 정의
{
private: // 세일 클래스의 private 멤버 변수 선언
	double Price; // 가격
public: // 세일 클래스의 public 멤버 변수 선언
	Sale(); // 기본 생성자 
	Sale(double ThePrice); // 생성자
	~Sale(); // 소멸자
	double GetPrice(); // 가격을 반환하는 함수
	virtual double Bill(); // 가격을 반환하는 함수
	double Savings(Sale& Other); // 저축한 가격을 반환하는 함수
	bool operator < (Sale& Other); // 세일 가격을 비교하는 함수
};

Sale::Sale() // 기본 생성자 정의
{
	Price = 0; // 가격을 0으로 초기화
}

Sale::Sale(double ThePrice) // 생성자 정의
{
	Price = ThePrice; // 가격을 ThePrice로 초기화
}

Sale::~Sale() // 소멸자 정의
{
}

double Sale::GetPrice() // 가격을 반환하는 함수 정의
{
	return Price; // 가격 반환
}

double Sale::Bill() // 가격을 반환하는 함수 정의
{
	return Price; // 가격 반환
}

double Sale::Savings(Sale& Other) // 저축한 가격을 반환하는 함수 정의
{
	return (Bill() - Other.Bill()); // 세일 가격에서 Other의 세일 가격을 뺀 값을 반환
}

bool Sale::operator < (Sale& Other) // 세일 가격을 비교하는 함수 정의
{
	return (Bill() < Other.Bill()); // 세일 가격이 Other의 세일 가격보다 작으면 true 반환
}

class DiscountSale : public Sale // 세일 가격을 할인해주는 클래스를 세일 클래스를 상속받아 정의
{
private: // 세일 가격을 할인해주는 클래스의 private 멤버 변수 선언
	double discount; // 할인 퍼센트
public: // 세일 가격을 할인해주는 클래스의 public 멤버 변수 선언
	DiscountSale(); // 기본 생성자
	DiscountSale(double ThePrice, double theDiscount); // 생성자
	~DiscountSale(); // 소멸자
	double GetDiscount(); // 할인 퍼센트를 반환하는 함수
	void setDiscount(double theDiscount); // 할인 퍼센트를 설정하는 함수
	double Bill(); // 가격을 반환하는 함수
	double Savings(DiscountSale& Other); // 저축한 가격을 반환하는 함수
	bool operator < (Sale& Other); // 세일 가격을 비교하는 함수
};

DiscountSale::DiscountSale() // 기본 생성자 정의
{
	discount = 0; // 할인 퍼센트를 0으로 초기화
}

DiscountSale::DiscountSale(double ThePrice, double theDiscount) : Sale(ThePrice) // 생성자 정의
{
	discount = theDiscount; // 할인 퍼센트를 theDiscount로 초기화
}

DiscountSale::~DiscountSale() // 소멸자 정의
{
}

double DiscountSale::GetDiscount() // 할인 퍼센트를 반환하는 함수 정의
{
	return discount; // 할인 퍼센트 반환
}

void DiscountSale::setDiscount(double theDiscount) // 할인 퍼센트를 설정하는 함수 정의
{
	discount = theDiscount; // 할인 퍼센트를 theDiscount로 설정
}

double DiscountSale::Bill() // 가격을 반환하는 함수 정의
{
	return (GetPrice() - (GetPrice() * discount / 100)); // 세일 가격에서 할인 퍼센트만큼 할인한 값을 반환
}

double DiscountSale::Savings(DiscountSale& Other) // 저축한 가격을 반환하는 함수 정의
{
	return (Bill() - Other.Bill()); // 세일 가격에서 Other의 세일 가격을 뺀 값을 반환
}

bool DiscountSale::operator < (Sale& Other) // 세일 가격을 비교하는 함수 정의
{
	return (Bill() < Other.Bill()); // 세일 가격이 Other의 세일 가격보다 작으면 true 반환
}

int main()
{
	// 문제의 예시대로 출력
	cout << "===============================" << endl;
	cout << "Price Compare Program" << endl;
	cout << "===============================" << endl;
	cout << "Insert item1 Price: "; // item1의 가격을 입력받는다.
	string firstitem; // item1의 가격을 저장할 변수 선언
	cin >> firstitem; // item1의 가격을 입력받는다.
	if (firstitem.find("$") != string::npos) // 만약 item1의 가격에 $가 있으면
	{
		firstitem = firstitem.substr(1, firstitem.length()); // $를 제외한 숫자만 저장한다.
	}
	double item1Price = stod(firstitem); // item1의 가격을 double형으로 변환한다.

	cout << "Insert item2 Price: "; // item2의 가격을 입력받는다.
	string seconditem; // item2의 가격을 저장할 변수 선언
	cin >> seconditem; // item2의 가격을 입력받는다.
	if (seconditem.find("$") != string::npos) // 만약 item2의 가격에 $가 있으면
	{
		seconditem = seconditem.substr(1, seconditem.length()); // $를 제외한 숫자만 저장한다.
	}
	double item2Price = stod(seconditem); // item2의 가격을 double형으로 변환한다.
	cout << endl;

	cout << "--------------------------------" << endl;
	cout << "Insert discount percent: "; // 할인 퍼센트를 입력받는다.
	double discountPercent; // 할인 퍼센트를 저장할 변수 선언
	cin >> discountPercent; // 할인 퍼센트를 입력받는다.
	cout << "--------------------------------" << endl;
	cout << "Result:" << endl;

	DiscountSale item1(item1Price, discountPercent); // item1의 가격과 할인 퍼센트로 DiscountSale 객체 생성
	DiscountSale item2(item2Price, discountPercent); // item2의 가격과 할인 퍼센트로 DiscountSale 객체 생성

	if (item1 < item2) // 오퍼레이터를 이용하여 item1의 세일 가격이 item2의 세일 가격보다 작으면
	{
		cout << "Discount price of item1 is cheaper." << endl; // item1의 세일 가격이 더 싸다고 출력
	}
	else if (item2 < item1) // 오퍼레이터를 이용하여 item2의 세일 가격이 item1의 세일 가격보다 작으면
	{
		cout << "Discount price of item2 is cheaper." << endl; // item2의 세일 가격이 더 싸다고 출력
	}
	else // 그 외의 경우
	{
		cout << "Both items have the same price." << endl; // 두 아이템의 세일 가격이 같다고 출력
	}

	cout << fixed; // 소수점을 고정시킨다.
	cout.precision(1); // 소수점 아래 한 자리까지 출력한다.
	cout << "Saving discount price is $" << abs(item1.Savings(item2)) << endl; // 두 아이템의 세일 가격 차이를 출력한다.

	return 0; // 프로그램 종료
}