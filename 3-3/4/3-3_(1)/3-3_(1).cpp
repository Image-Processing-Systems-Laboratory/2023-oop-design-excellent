#include <iostream>
#include <string>

using namespace std;

class Sale {
private:
    double Price;

public:
    Sale();
    Sale(double thePrice);
    ~Sale();

    double GetPrice();
    virtual double Bill();
    double Savings(Sale& Other);
    bool operator<(Sale& Other);
};

// Sale class 생성자, 0으로 Price 멤버 변수 초기화
Sale::Sale() : Price(0) {}
// Sale class 생성자, 인수로 Price 멤버 변수 초기화
Sale::Sale(double thePrice) : Price(thePrice) {}
// Sale class 소멸자
Sale::~Sale() {}

// GetPrice() 함수 Price를 return 
double Sale::GetPrice() {
    return Price;
}

// Bill() 함수 Price를 return
// 파생 클래스에서 이 함수를 재정의하여 다른 구현을 제공할 수 있습니다.
double Sale::Bill() {
    return Price;
}

// Savings() 함수 객체의 금액에서 bill 만큼 빼서 Savings계산
double Sale::Savings(Sale& Other) {
    return this->Bill() - Other.Bill();
}

// 금액을 비교하여 true or false 값 반환
bool Sale::operator<(Sale& Other) {
    return this->Bill() < Other.Bill();
}

// Sale class를 상속 받은 DiscountSale class
class DiscountSale : public Sale {
private:
    double Discount;

public:
    DiscountSale();
    DiscountSale(double thePrice, double theDiscount);
    ~DiscountSale();

    double GetDiscount();
    void SetDiscount(double newDiscount);
    double Bill() override;
    double Savings(DiscountSale& Other);
    bool operator<(DiscountSale& Other);
};

// DiscountSale의 생성자, 변수 초기화 및 소멸자
DiscountSale::DiscountSale() : Sale(), Discount(0) {}
DiscountSale::DiscountSale(double thePrice, double theDiscount) : Sale(thePrice), Discount(theDiscount) {}
DiscountSale::~DiscountSale() {}

// GetDiscount() 함수 Discount 값 반환
double DiscountSale::GetDiscount() {
    return Discount;
}

// SetDiscount 함수 Discount를 newDiscount의 값으로 저장
void DiscountSale::SetDiscount(double newDiscount) {
    Discount = newDiscount;
}

// Bill() 재정의 함수 할인 적용 후 금액 반환
double DiscountSale::Bill() {
    return (1.0 - Discount / 100.0) * GetPrice();
}

// Savings() 함수 객체의 금액에서 bill 만큼 빼서 Savings계산
double DiscountSale::Savings(DiscountSale& Other) {
    return this->Bill() - Other.Bill();
}

// 금액을 비교하여 true or false 값 반환
bool DiscountSale::operator<(DiscountSale& Other) {
    return this->Bill() < Other.Bill();
}
int main() {
    // 프로그램 실행
    cout << "==============================" << endl;
    cout << "Price Compare Program" << endl;
    cout << "==============================" << endl;
    double price1, price2, discount;
    string discountPercent;
    // item1 가격 입력 받기
    cout << "Insert item1 price: $";
    cin >> price1;
    // item2 가격 입력 받기
    cout << "Insert item2 price: $";
    cin >> price2;
    // discount percent 입력 받기
    cout << endl << "------------------------------" << endl;
    cout << "Insert discount percent: ";
    cin >> discountPercent;
    cout << "------------------------------" << endl;
    // 만약 마지막 문자가 %라면 %를 제거해준뒤 double 형으로 변환
    discount = discountPercent[discountPercent.size() - 1] != '%' ? stod(discountPercent) : stod(discountPercent.substr(0, discountPercent.size() - 1));

    Sale item1(price1);
    Sale item2(price2);

    cout << "Result:" << endl;
    // item1이 item2보다 작으면 
    if (item1 < item2) {
        // discountedItem 객체 생성
        DiscountSale discountedItem(item1.GetPrice(), discount);
        Sale* pDItem = &discountedItem;
        cout << "Discount price of item1 is cheaper." << endl;
        // item1의 Savings() 함수를 사용하여 값 출력
        cout << "Saving discount price is $" << item1.Savings(*pDItem) << endl;
    }
    else {
        // item1이 item2보다 크면 
        DiscountSale discountedItem(item2.GetPrice(), discount);
        Sale* pDItem = &discountedItem;
        cout << "Discount price of item2 is cheaper." << endl;
        // item2의 Savings() 함수를 사용하여 값 출력
        cout << "Saving discount price is $" << item2.Savings(*pDItem) << endl;
    }

    return 0;
}