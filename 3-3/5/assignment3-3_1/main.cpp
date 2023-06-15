#include "class.h"
#include <iostream>

using namespace std;

double convert_str_double(char* str);          //���ڿ��� double �ڷ������� ��ȯ

int main(void)
{
	cout << "======================================" << endl;
	cout << "Price Compare Program" << endl;
	cout << "======================================" << endl;

	//�� item�� ���� �Է�
	char str[256];    //�Ǽ��� ���ڿ��� �Է� �޾� ������ �迭

	cout << "Insert item1 price: ";
	cin >> str;
	Sale item1(convert_str_double(str));   //price_str�� �Ǽ��� ��ȯ�Ͽ� �ش� ������ �ʱ�ȭ�� Sale ��ü ����

	cout << "Insert item2 price: ";
	cin >> str;
	Sale item2(convert_str_double(str));   //price_str�� �Ǽ��� ��ȯ�Ͽ� �ش� ������ �ʱ�ȭ�� Sale ��ü ����

	//������ �Է�
	cout << "--------------------------------------" << endl;
	cout << "Insert discount percent: ";
	cin >> str;
	cout << "--------------------------------------" << endl;
	double discount = convert_str_double(str);           //���ڿ��� ������ �������� �Ǽ��� ��ȯ�Ͽ� ����

	//DiscountSale Ŭ������ ��ü ���� �Ҵ�
	Sale* item1_discount = new DiscountSale(item1.GetPrice(), discount);
	Sale* item2_discount = new DiscountSale(item2.GetPrice(), discount);

	//��� ���
	cout << "Result:" << endl;
	
	if (*item1_discount < *item2_discount) {
		cout << "Discount price of item1 is cheaper." << endl;
	}
	else {
		cout << "Discount price of item2 is cheaper." << endl;
	}

	cout.setf(ios::showpoint);
	cout << "Saving discount price is $" << item1_discount->Savings(*item2_discount) << endl;

	return 0;
}

//���ڿ��� double �ڷ������� ��ȯ
double convert_str_double(char* str)
{
	double exponent = 1;        //�ڸ���
	double num = 0;             //�Ǽ��� ��ȯ�� ��
	int start_decimal = 0;     //�Ҽ� �κ��� �����ϴ� ��ġ
	int start = 0;             //���ڰ� �����ϴ� ��ġ

	if (str[0] == '$') {
		start++;
	}

	//�Ҽ��� ���� �κ� ���ϱ�(�Ҽ��� ���� ������ �ݺ�)
	start_decimal = start;
	while (str[start_decimal] >= '0' && str[start_decimal] <= '9') {
		start_decimal++;
	}

	//���� �κ� ���
	for (int i = start_decimal - 1; i >= start; i--) {   //������ ���� �κ��� �ں��� ����
		num = num + ((str[i] - '0') * exponent);   //���ڿ��� �� �ڸ��� ����Ǿ� �ִ� ���ڿ� �ڸ����� ���� ���� num�� ���Ѵ�.
		exponent *= 10;
	}

	//�Ҽ� �κ� ���
	if (str[start_decimal] != '\0' && str[start_decimal] != '%') {
		start_decimal++;
		exponent = 0.1;
		while (str[start_decimal] != '\0' && str[start_decimal] != '%') {   //������ ���� ������ ������ �ݺ�

			num = num + ((str[start_decimal] - '0') * exponent);  //���ڿ��� �� �ڸ��� ����Ǿ� �ִ� ���ڿ� �ڸ����� ���� ���� num�� ���Ѵ�.
			exponent *= 0.1;
			start_decimal++;
		}
	}

	return num;
}