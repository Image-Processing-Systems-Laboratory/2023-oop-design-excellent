#include <iostream>
using namespace std;
class Sale // 세일 클래스 
{
private: 
    double Price; // 상품 가격

public:
    Sale() // 생성자 
    {
        Price = 0; // 0으로 가격 초기화
    }

    Sale(double ThePrice) // 가격을 인자로 하는 생성자
    {
        Price = ThePrice; // 입력 받은 가격으로 복사
    }

    ~Sale() // 소멸자
    {

    }

    double GetPrice() // 가격 값 얻어오기 
    {
        return Price; // 가격 반환
    }

    virtual double Bill() // 가상 함수로 된 가격 얻어오기
    {
        return Price; // 가격 반환
    }

    double Savings(Sale& Other) // 따른 물품과의 차이로 얼마나 절약했는지
    {
        return (Price - Other.Price); // 가격차이
    }

    bool operator<(Sale& Other) // < 연산자 오버로딩
    {
        if (Bill() < Other.Bill()) // 현재 값이 더 작다면 
            return true; // 참을 반환
        else // 크다면
            return false; // 거짓을 반환
    }
};

class DiscountSale : public Sale
{
private:
    double Discount; // 할인율 변수

public:
    DiscountSale() : Sale() // 생성자 
    {
        Discount = 0; // 할인율을 0으로 초기화
    }

    DiscountSale(double ThePrice, double theDiscount) : Sale(ThePrice) // 입력받은 가격과 할인율이 인자로 들어오는 생성자
    {
        Discount = theDiscount; // 입력한 할인율로 초기화
    }

    ~DiscountSale() // 소멸자
    {
    
    }

    double GetDiscount() // 할인율 얻어오기
    { 
        return Discount; // 할인율 반환
    }

    void SetDiscount(double newDiscount) // 할인율 설정
    {
        Discount = newDiscount; // 입력한 값으로 할인율 설정
    }

    double Bill() override
    {        
        double discountPrice = Discount * GetPrice(); // 할인 금액 계산
        double finalPrice = GetPrice() - discountPrice; // 원가에서 할인된 금액 계산

        return finalPrice; // 원가에서 할인된 금액 계산 반환
    }

    double Savings(DiscountSale& Other) // 다른 물품과의 차이로 얼마나 절약했는지
    { 
        return (Bill() - Other.Bill()); // 가격 차
    }

    bool operator<(DiscountSale& Other)  // 비교 연산자 오버로딩
    { 
        if (Bill() < Other.Bill()) // 현재 값이 더 작다면 
            return true; // 참을 반환
        else // 크다면
            return false; // 거짓을 반환
    }
};

int main()
{
    double item1_price, item2_price, discount; // 아이템1,2 ,할인율 변수
    cout << "=============================================" << endl;
    cout << "Price Compare Program" << endl;
    cout << "=============================================" << endl;
    cout << "Insert item1 price: $"; // 가격 입력
    cin >> item1_price;
    cout << "Insert item2 price: $";
    cin >> item2_price;
    cout << "---------------------------------------------" << endl;
    cout << "Insert discount percent: "; // 할인율 입력
    cin >> discount;
    discount = discount / 100; // 백분율을 실제 비율로 변환
    cout << "---------------------------------------------" << endl;
    
   
    DiscountSale item1(item1_price, discount); // 아이템1의 할인율 받은 객체 생성
    DiscountSale item2(item2_price, discount); // 아이템2의 할인율 받은 객체 생성
    cout << "Result:" << endl; // 결과 출력
    
    if (item1 < item2) // 아이템1이 더 싼경우
    {
        cout << "Discount price of item1 is cheaper." << endl;
        cout << "Saving discount price is $" << item2.Savings(item1) << endl;
    }
    else if (item2 < item1) // 아이템2가 더 싼경우
    {
        cout << "Discount price of item2 is cheaper." << endl;
        cout << "Saving discount price is $" << item1.Savings(item2) << endl;
    }
    else // 같다면
        cout << "The same discount price." << endl;
    
    return 0;
}