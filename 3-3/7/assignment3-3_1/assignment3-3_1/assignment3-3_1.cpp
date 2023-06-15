#include <iostream>
using namespace std;
class Sale // ���� Ŭ���� 
{
private: 
    double Price; // ��ǰ ����

public:
    Sale() // ������ 
    {
        Price = 0; // 0���� ���� �ʱ�ȭ
    }

    Sale(double ThePrice) // ������ ���ڷ� �ϴ� ������
    {
        Price = ThePrice; // �Է� ���� �������� ����
    }

    ~Sale() // �Ҹ���
    {

    }

    double GetPrice() // ���� �� ������ 
    {
        return Price; // ���� ��ȯ
    }

    virtual double Bill() // ���� �Լ��� �� ���� ������
    {
        return Price; // ���� ��ȯ
    }

    double Savings(Sale& Other) // ���� ��ǰ���� ���̷� �󸶳� �����ߴ���
    {
        return (Price - Other.Price); // ��������
    }

    bool operator<(Sale& Other) // < ������ �����ε�
    {
        if (Bill() < Other.Bill()) // ���� ���� �� �۴ٸ� 
            return true; // ���� ��ȯ
        else // ũ�ٸ�
            return false; // ������ ��ȯ
    }
};

class DiscountSale : public Sale
{
private:
    double Discount; // ������ ����

public:
    DiscountSale() : Sale() // ������ 
    {
        Discount = 0; // �������� 0���� �ʱ�ȭ
    }

    DiscountSale(double ThePrice, double theDiscount) : Sale(ThePrice) // �Է¹��� ���ݰ� �������� ���ڷ� ������ ������
    {
        Discount = theDiscount; // �Է��� �������� �ʱ�ȭ
    }

    ~DiscountSale() // �Ҹ���
    {
    
    }

    double GetDiscount() // ������ ������
    { 
        return Discount; // ������ ��ȯ
    }

    void SetDiscount(double newDiscount) // ������ ����
    {
        Discount = newDiscount; // �Է��� ������ ������ ����
    }

    double Bill() override
    {        
        double discountPrice = Discount * GetPrice(); // ���� �ݾ� ���
        double finalPrice = GetPrice() - discountPrice; // �������� ���ε� �ݾ� ���

        return finalPrice; // �������� ���ε� �ݾ� ��� ��ȯ
    }

    double Savings(DiscountSale& Other) // �ٸ� ��ǰ���� ���̷� �󸶳� �����ߴ���
    { 
        return (Bill() - Other.Bill()); // ���� ��
    }

    bool operator<(DiscountSale& Other)  // �� ������ �����ε�
    { 
        if (Bill() < Other.Bill()) // ���� ���� �� �۴ٸ� 
            return true; // ���� ��ȯ
        else // ũ�ٸ�
            return false; // ������ ��ȯ
    }
};

int main()
{
    double item1_price, item2_price, discount; // ������1,2 ,������ ����
    cout << "=============================================" << endl;
    cout << "Price Compare Program" << endl;
    cout << "=============================================" << endl;
    cout << "Insert item1 price: $"; // ���� �Է�
    cin >> item1_price;
    cout << "Insert item2 price: $";
    cin >> item2_price;
    cout << "---------------------------------------------" << endl;
    cout << "Insert discount percent: "; // ������ �Է�
    cin >> discount;
    discount = discount / 100; // ������� ���� ������ ��ȯ
    cout << "---------------------------------------------" << endl;
    
   
    DiscountSale item1(item1_price, discount); // ������1�� ������ ���� ��ü ����
    DiscountSale item2(item2_price, discount); // ������2�� ������ ���� ��ü ����
    cout << "Result:" << endl; // ��� ���
    
    if (item1 < item2) // ������1�� �� �Ѱ��
    {
        cout << "Discount price of item1 is cheaper." << endl;
        cout << "Saving discount price is $" << item2.Savings(item1) << endl;
    }
    else if (item2 < item1) // ������2�� �� �Ѱ��
    {
        cout << "Discount price of item2 is cheaper." << endl;
        cout << "Saving discount price is $" << item1.Savings(item2) << endl;
    }
    else // ���ٸ�
        cout << "The same discount price." << endl;
    
    return 0;
}