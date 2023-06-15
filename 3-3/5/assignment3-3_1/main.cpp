#include "class.h"
#include <iostream>

using namespace std;

double convert_str_double(char* str);          //문자열을 double 자료형으로 변환

int main(void)
{
	cout << "======================================" << endl;
	cout << "Price Compare Program" << endl;
	cout << "======================================" << endl;

	//두 item의 가격 입력
	char str[256];    //실수를 문자열로 입력 받아 저장할 배열

	cout << "Insert item1 price: ";
	cin >> str;
	Sale item1(convert_str_double(str));   //price_str을 실수로 변환하여 해당 값으로 초기화한 Sale 객체 생성

	cout << "Insert item2 price: ";
	cin >> str;
	Sale item2(convert_str_double(str));   //price_str을 실수로 변환하여 해당 값으로 초기화한 Sale 객체 생성

	//할인율 입력
	cout << "--------------------------------------" << endl;
	cout << "Insert discount percent: ";
	cin >> str;
	cout << "--------------------------------------" << endl;
	double discount = convert_str_double(str);           //문자열로 저장한 할인율을 실수로 변환하여 저장

	//DiscountSale 클래스의 객체 동적 할당
	Sale* item1_discount = new DiscountSale(item1.GetPrice(), discount);
	Sale* item2_discount = new DiscountSale(item2.GetPrice(), discount);

	//결과 출력
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

//문자열을 double 자료형으로 변환
double convert_str_double(char* str)
{
	double exponent = 1;        //자릿수
	double num = 0;             //실수로 변환한 값
	int start_decimal = 0;     //소수 부분이 시작하는 위치
	int start = 0;             //숫자가 시작하는 위치

	if (str[0] == '$') {
		start++;
	}

	//소수의 시작 부분 구하기(소수점 만날 때까지 반복)
	start_decimal = start;
	while (str[start_decimal] >= '0' && str[start_decimal] <= '9') {
		start_decimal++;
	}

	//정수 부분 계산
	for (int i = start_decimal - 1; i >= start; i--) {   //숫자의 정수 부분의 뒤부터 시작
		num = num + ((str[i] - '0') * exponent);   //문자열의 각 자리에 저장되어 있는 숫자와 자릿수를 곱한 값을 num에 더한다.
		exponent *= 10;
	}

	//소수 부분 계산
	if (str[start_decimal] != '\0' && str[start_decimal] != '%') {
		start_decimal++;
		exponent = 0.1;
		while (str[start_decimal] != '\0' && str[start_decimal] != '%') {   //숫자의 끝에 도달할 때까지 반복

			num = num + ((str[start_decimal] - '0') * exponent);  //문자열의 각 자리에 저장되어 있는 숫자와 자릿수를 곱한 값을 num에 더한다.
			exponent *= 0.1;
			start_decimal++;
		}
	}

	return num;
}