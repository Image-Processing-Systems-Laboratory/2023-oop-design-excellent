#include <iostream>
#include <string>
using namespace std;

class Sale // ���� Ŭ���� ����
{
private: // ���� Ŭ������ private ��� ���� ����
	double Price; // ����
public: // ���� Ŭ������ public ��� ���� ����
	Sale(); // �⺻ ������ 
	Sale(double ThePrice); // ������
	~Sale(); // �Ҹ���
	double GetPrice(); // ������ ��ȯ�ϴ� �Լ�
	virtual double Bill(); // ������ ��ȯ�ϴ� �Լ�
	double Savings(Sale& Other); // ������ ������ ��ȯ�ϴ� �Լ�
	bool operator < (Sale& Other); // ���� ������ ���ϴ� �Լ�
};

Sale::Sale() // �⺻ ������ ����
{
	Price = 0; // ������ 0���� �ʱ�ȭ
}

Sale::Sale(double ThePrice) // ������ ����
{
	Price = ThePrice; // ������ ThePrice�� �ʱ�ȭ
}

Sale::~Sale() // �Ҹ��� ����
{
}

double Sale::GetPrice() // ������ ��ȯ�ϴ� �Լ� ����
{
	return Price; // ���� ��ȯ
}

double Sale::Bill() // ������ ��ȯ�ϴ� �Լ� ����
{
	return Price; // ���� ��ȯ
}

double Sale::Savings(Sale& Other) // ������ ������ ��ȯ�ϴ� �Լ� ����
{
	return (Bill() - Other.Bill()); // ���� ���ݿ��� Other�� ���� ������ �� ���� ��ȯ
}

bool Sale::operator < (Sale& Other) // ���� ������ ���ϴ� �Լ� ����
{
	return (Bill() < Other.Bill()); // ���� ������ Other�� ���� ���ݺ��� ������ true ��ȯ
}

class DiscountSale : public Sale // ���� ������ �������ִ� Ŭ������ ���� Ŭ������ ��ӹ޾� ����
{
private: // ���� ������ �������ִ� Ŭ������ private ��� ���� ����
	double discount; // ���� �ۼ�Ʈ
public: // ���� ������ �������ִ� Ŭ������ public ��� ���� ����
	DiscountSale(); // �⺻ ������
	DiscountSale(double ThePrice, double theDiscount); // ������
	~DiscountSale(); // �Ҹ���
	double GetDiscount(); // ���� �ۼ�Ʈ�� ��ȯ�ϴ� �Լ�
	void setDiscount(double theDiscount); // ���� �ۼ�Ʈ�� �����ϴ� �Լ�
	double Bill(); // ������ ��ȯ�ϴ� �Լ�
	double Savings(DiscountSale& Other); // ������ ������ ��ȯ�ϴ� �Լ�
	bool operator < (Sale& Other); // ���� ������ ���ϴ� �Լ�
};

DiscountSale::DiscountSale() // �⺻ ������ ����
{
	discount = 0; // ���� �ۼ�Ʈ�� 0���� �ʱ�ȭ
}

DiscountSale::DiscountSale(double ThePrice, double theDiscount) : Sale(ThePrice) // ������ ����
{
	discount = theDiscount; // ���� �ۼ�Ʈ�� theDiscount�� �ʱ�ȭ
}

DiscountSale::~DiscountSale() // �Ҹ��� ����
{
}

double DiscountSale::GetDiscount() // ���� �ۼ�Ʈ�� ��ȯ�ϴ� �Լ� ����
{
	return discount; // ���� �ۼ�Ʈ ��ȯ
}

void DiscountSale::setDiscount(double theDiscount) // ���� �ۼ�Ʈ�� �����ϴ� �Լ� ����
{
	discount = theDiscount; // ���� �ۼ�Ʈ�� theDiscount�� ����
}

double DiscountSale::Bill() // ������ ��ȯ�ϴ� �Լ� ����
{
	return (GetPrice() - (GetPrice() * discount / 100)); // ���� ���ݿ��� ���� �ۼ�Ʈ��ŭ ������ ���� ��ȯ
}

double DiscountSale::Savings(DiscountSale& Other) // ������ ������ ��ȯ�ϴ� �Լ� ����
{
	return (Bill() - Other.Bill()); // ���� ���ݿ��� Other�� ���� ������ �� ���� ��ȯ
}

bool DiscountSale::operator < (Sale& Other) // ���� ������ ���ϴ� �Լ� ����
{
	return (Bill() < Other.Bill()); // ���� ������ Other�� ���� ���ݺ��� ������ true ��ȯ
}

int main()
{
	// ������ ���ô�� ���
	cout << "===============================" << endl;
	cout << "Price Compare Program" << endl;
	cout << "===============================" << endl;
	cout << "Insert item1 Price: "; // item1�� ������ �Է¹޴´�.
	string firstitem; // item1�� ������ ������ ���� ����
	cin >> firstitem; // item1�� ������ �Է¹޴´�.
	if (firstitem.find("$") != string::npos) // ���� item1�� ���ݿ� $�� ������
	{
		firstitem = firstitem.substr(1, firstitem.length()); // $�� ������ ���ڸ� �����Ѵ�.
	}
	double item1Price = stod(firstitem); // item1�� ������ double������ ��ȯ�Ѵ�.

	cout << "Insert item2 Price: "; // item2�� ������ �Է¹޴´�.
	string seconditem; // item2�� ������ ������ ���� ����
	cin >> seconditem; // item2�� ������ �Է¹޴´�.
	if (seconditem.find("$") != string::npos) // ���� item2�� ���ݿ� $�� ������
	{
		seconditem = seconditem.substr(1, seconditem.length()); // $�� ������ ���ڸ� �����Ѵ�.
	}
	double item2Price = stod(seconditem); // item2�� ������ double������ ��ȯ�Ѵ�.
	cout << endl;

	cout << "--------------------------------" << endl;
	cout << "Insert discount percent: "; // ���� �ۼ�Ʈ�� �Է¹޴´�.
	double discountPercent; // ���� �ۼ�Ʈ�� ������ ���� ����
	cin >> discountPercent; // ���� �ۼ�Ʈ�� �Է¹޴´�.
	cout << "--------------------------------" << endl;
	cout << "Result:" << endl;

	DiscountSale item1(item1Price, discountPercent); // item1�� ���ݰ� ���� �ۼ�Ʈ�� DiscountSale ��ü ����
	DiscountSale item2(item2Price, discountPercent); // item2�� ���ݰ� ���� �ۼ�Ʈ�� DiscountSale ��ü ����

	if (item1 < item2) // ���۷����͸� �̿��Ͽ� item1�� ���� ������ item2�� ���� ���ݺ��� ������
	{
		cout << "Discount price of item1 is cheaper." << endl; // item1�� ���� ������ �� �δٰ� ���
	}
	else if (item2 < item1) // ���۷����͸� �̿��Ͽ� item2�� ���� ������ item1�� ���� ���ݺ��� ������
	{
		cout << "Discount price of item2 is cheaper." << endl; // item2�� ���� ������ �� �δٰ� ���
	}
	else // �� ���� ���
	{
		cout << "Both items have the same price." << endl; // �� �������� ���� ������ ���ٰ� ���
	}

	cout << fixed; // �Ҽ����� ������Ų��.
	cout.precision(1); // �Ҽ��� �Ʒ� �� �ڸ����� ����Ѵ�.
	cout << "Saving discount price is $" << abs(item1.Savings(item2)) << endl; // �� �������� ���� ���� ���̸� ����Ѵ�.

	return 0; // ���α׷� ����
}