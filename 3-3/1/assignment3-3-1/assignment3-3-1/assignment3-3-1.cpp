#include <iostream>

using namespace std;

class Sale //기본 클래스
{
protected: 
    double Price; //가격
public:
    Sale() : Price(0.0) {} //생성자
    Sale(double ThePrice) : Price(ThePrice) {} 
    virtual ~Sale() {} //가상 소멸자

    double GetPrice() const { //가격 반환
        return Price;
    }

    virtual double Bill() const { //가격 계산
        return Price;
    }

    double Savings(const Sale& Other) const { //할인 가격 계산
        return Other.GetPrice() - Other.Bill();
    }

    bool operator < (const Sale& Other) const { //비교 연산자
        return Bill() < Other.Bill();
    }
};

class DiscountSale : public Sale //파생 클래스
{
private:
    double Discount; //할인율
public:
    DiscountSale() : Sale(), Discount(0.0) {} //생성자
    DiscountSale(double ThePrice, double TheDiscount) : Sale(ThePrice), Discount(TheDiscount) {} 

    ~DiscountSale() {} //소멸자

    double GetDiscount() const { //할인율 반환
        return Discount;
    }

    void SetDiscount(double TheDiscount) { //할인율 설정
        Discount = TheDiscount;
    }

    double Bill() const override { //할인 가격 계산
        return GetPrice() * (1.0 - Discount / 100.0);
    }
};

int main() { //메인 함수
    double price1, price2, discount;
    cout << "===================================\n";
    cout << "Price Compare Program\n";
    cout << "===================================\n";
    cout << "Insert item1 price: $";
    cin >> price1;
    cout << "Insert item2 price: $";
    cin >> price2;
    cout << "-----------------------------------------------------------\n";
    cout << "Insert discount percent: ";
    cin >> discount;
    cout << "-----------------------------------------------------------\n";

    DiscountSale item1(price1, discount);
    DiscountSale item2(price2, discount);

    if (item1 < item2) {
        cout << "Result:" << endl;
        cout << "Discounted price of item1 is cheaper.\n";
        cout << "Saving discount price is $" << item1.Savings(item1) << "\n";
    }
    else {
        cout << "Result:" << endl;
        cout << "Discounted price of item2 is cheaper.\n";
        cout << "Saving discount price is $" << item2.Savings(item2) << "\n";
    }

    return 0;
}
