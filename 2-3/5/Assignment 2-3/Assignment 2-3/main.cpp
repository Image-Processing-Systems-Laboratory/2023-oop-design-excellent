#include <iostream>
#include <windows.h>
#include <string>
#include "string.h"

using namespace std;
using namespace oopstd;


int main()
{
	oopstd::string oopstdString;
	std::string stdString;

	cout << "빈 값으로 시작" << endl;

	cout << "oopstdString c_str(): " << oopstdString.c_str() << endl;			//c_str 비교
	cout << "stdString c_str(): " << stdString.c_str() << endl;
	cout << endl;


	oopstdString.assign("HEllO");
	stdString.assign("HEllO");

	cout << "oopstdString assign(HELLO): " << oopstdString.c_str() << endl;		//assign 비교
	cout << "stdString assign(HELLO): " << stdString.c_str() << endl;
	cout << endl;


	cout << "oopstdString at(2): " << oopstdString.at(2) << endl;				//at 비교
	cout << "stdString at(2): " << stdString.at(2) << endl;
	cout << endl;

	oopstdString.clear();
	stdString.clear();

	cout << "oopstdString after clear(): " << oopstdString.c_str() << endl;		//clear 비교
	cout << "stdString after clear(): " << stdString.c_str() << endl;
	cout << endl;


	oopstdString.push_back('B');
	stdString.push_back('B');

	cout << "oopstdString after push_back(B): " << oopstdString.c_str() << endl;//push_back 비교
	cout << "stdString after push_back(B): " << stdString.c_str() << endl;
	cout << endl;


	oopstd::string str1 = "a";
	oopstd::string str2 = "A";
	oopstd::string str3 = "B";

	cout << "oopstdString = A Compare a, A, B: "								//compare 비교
		<< oopstdString.compare(&str1) << " "
		<< oopstdString.compare(&str2) << " "
		<< oopstdString.compare(&str3) << endl;

	std::string stdStr1 = "a";
	std::string stdStr2 = "A";
	std::string stdStr3 = "B";

	cout << "stdString = A Compare a, A, B: "
		<< stdString.compare(stdStr1) << " "
		<< stdString.compare(stdStr2) << " "
		<< stdString.compare(stdStr3) << endl;


	oopstdString.clear();
	stdString.clear();
	oopstdString.assign("Hello World");			
	stdString.assign("Hello World");


	cout << "oopstdString is Hello World: " << oopstdString.c_str() << endl;
	cout << "stdString is Hello World: " << stdString.c_str() << endl;
	cout << endl;

	oopstd::string oopstdReplace = "Hi";
	oopstdString.replace(0, 5, &oopstdReplace);									//replacee 비교
	std::string replace = "Hi";
	stdString.replace(0, 5, "HI");

	cout << "oopstdString repalce(0, 5, HI): " << oopstdString.c_str() << endl;
	cout << "stdString repalce(0, 5, HI): " << stdString.c_str() << endl;
	cout << endl;

	

	oopstd::string oopstdSubStr = oopstdString.substr(5, 10);
	std::string stdSubStr = stdString.substr(5, 10);

	cout << "oopstdString substr(5, 10): " << oopstdSubStr.c_str() << endl;		//substr 비교
	cout << "stdString substr(5, 10): " << stdSubStr.c_str() << endl;
	cout << endl;

	cout << "oopstdString find(Wo, 0): " << oopstdSubStr.find("Wo", 0) << endl;	//find 비교
	cout << "stdString substr(Wo, 0): " << stdSubStr.find("Wo", 0) << endl;
	cout << endl;


	oopstd::string oopstdStrToInt = "12an";
	std::string stdStrToIntr = "12an";

	int num1 = oopstd::stoi(oopstdStrToInt, 0, 10);								//stoi 비교
	int num2 = std::stoi(stdStrToIntr);

	cout << "oopstdString stoi(12an): " << num1 << endl;
	cout << "stdString stoi(12an): " << num2 << endl;
	cout << endl;

			
	oopstd::string oopstdStrToFloat = "1.2an";								
	std::string stdStrToFloat = "1.2an";

	float num3 = oopstd::stof(oopstdStrToFloat, 0);
	float num4 = std::stof(stdStrToFloat);

	cout << "oopstdString stof(1.2an): " << num3 << endl;						//stof 비교
	cout << "stdString stof(1.2an): " << num4 << endl;
	cout << endl;

	oopstd::string IntToString = oopstd::to_string(num1);						
	oopstd::string floatToString = oopstd::to_string(num3);

	cout << "IntToString (12): " << IntToString.c_str() << endl; ;				//int to string
	cout << "floatToString (1.2): " << floatToString.c_str() << endl;			//float to string
	cout << endl;


	system("PAUSE");
	Sleep(1000); //1 second stop
	return 0;
}