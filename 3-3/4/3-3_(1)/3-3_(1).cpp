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

// Sale class ������, 0���� Price ��� ���� �ʱ�ȭ
Sale::Sale() : Price(0) {}
// Sale class ������, �μ��� Price ��� ���� �ʱ�ȭ
Sale::Sale(double thePrice) : Price(thePrice) {}
// Sale class �Ҹ���
Sale::~Sale() {}

// GetPrice() �Լ� Price�� return 
double Sale::GetPrice() {
    return Price;
}

// Bill() �Լ� Price�� return
// �Ļ� Ŭ�������� �� �Լ��� �������Ͽ� �ٸ� ������ ������ �� �ֽ��ϴ�.
double Sale::Bill() {
    return Price;
}

// Savings() �Լ� ��ü�� �ݾ׿��� bill ��ŭ ���� Savings���
double Sale::Savings(Sale& Other) {
    return this->Bill() - Other.Bill();
}

// �ݾ��� ���Ͽ� true or false �� ��ȯ
bool Sale::operator<(Sale& Other) {
    return this->Bill() < Other.Bill();
}

// Sale class�� ��� ���� DiscountSale class
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

// DiscountSale�� ������, ���� �ʱ�ȭ �� �Ҹ���
DiscountSale::DiscountSale() : Sale(), Discount(0) {}
DiscountSale::DiscountSale(double thePrice, double theDiscount) : Sale(thePrice), Discount(theDiscount) {}
DiscountSale::~DiscountSale() {}

// GetDiscount() �Լ� Discount �� ��ȯ
double DiscountSale::GetDiscount() {
    return Discount;
}

// SetDiscount �Լ� Discount�� newDiscount�� ������ ����
void DiscountSale::SetDiscount(double newDiscount) {
    Discount = newDiscount;
}

// Bill() ������ �Լ� ���� ���� �� �ݾ� ��ȯ
double DiscountSale::Bill() {
    return (1.0 - Discount / 100.0) * GetPrice();
}

// Savings() �Լ� ��ü�� �ݾ׿��� bill ��ŭ ���� Savings���
double DiscountSale::Savings(DiscountSale& Other) {
    return this->Bill() - Other.Bill();
}

// �ݾ��� ���Ͽ� true or false �� ��ȯ
bool DiscountSale::operator<(DiscountSale& Other) {
    return this->Bill() < Other.Bill();
}
int main() {
    // ���α׷� ����
    cout << "==============================" << endl;
    cout << "Price Compare Program" << endl;
    cout << "==============================" << endl;
    double price1, price2, discount;
    string discountPercent;
    // item1 ���� �Է� �ޱ�
    cout << "Insert item1 price: $";
    cin >> price1;
    // item2 ���� �Է� �ޱ�
    cout << "Insert item2 price: $";
    cin >> price2;
    // discount percent �Է� �ޱ�
    cout << endl << "------------------------------" << endl;
    cout << "Insert discount percent: ";
    cin >> discountPercent;
    cout << "------------------------------" << endl;
    // ���� ������ ���ڰ� %��� %�� �������ص� double ������ ��ȯ
    discount = discountPercent[discountPercent.size() - 1] != '%' ? stod(discountPercent) : stod(discountPercent.substr(0, discountPercent.size() - 1));

    Sale item1(price1);
    Sale item2(price2);

    cout << "Result:" << endl;
    // item1�� item2���� ������ 
    if (item1 < item2) {
        // discountedItem ��ü ����
        DiscountSale discountedItem(item1.GetPrice(), discount);
        Sale* pDItem = &discountedItem;
        cout << "Discount price of item1 is cheaper." << endl;
        // item1�� Savings() �Լ��� ����Ͽ� �� ���
        cout << "Saving discount price is $" << item1.Savings(*pDItem) << endl;
    }
    else {
        // item1�� item2���� ũ�� 
        DiscountSale discountedItem(item2.GetPrice(), discount);
        Sale* pDItem = &discountedItem;
        cout << "Discount price of item2 is cheaper." << endl;
        // item2�� Savings() �Լ��� ����Ͽ� �� ���
        cout << "Saving discount price is $" << item2.Savings(*pDItem) << endl;
    }

    return 0;
}