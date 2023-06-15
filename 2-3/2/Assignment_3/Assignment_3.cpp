#include <iostream>
#include "oopstd.h"
using namespace std;

int main()
{
	oopstd::string a;//assign
	a.assign("Hi");
	cout << a.c_str() << endl;
	cout << endl;

	oopstd::string example("Hello World");//at
	cout << example.at(2) << endl;
	cout << endl;

	const char* b;//c_str
	b = example.c_str();
	cout << b << endl;
	cout << endl;

	oopstd::string example2("Hello World");//clear
	example2.clear();
	cout << example2.c_str() << endl;
	cout << endl;

	oopstd::string example3("Hello World");//push_back
	example3.push_back('b');
	cout << example3.c_str() << endl;
	cout << endl;

	oopstd::string ex1("HELLO");//compare
	cout << ex1.compare("Hello") << endl;
	cout << ex1.compare("HELLO") << endl;
	cout << ex1.compare("HA") << endl;
	cout << endl;

	oopstd::string example4("Hello World");//replace
	cout << example4.replace(0, 5, "Hi").c_str() << endl;
	cout << endl;

	oopstd::string example5="Hello World";//substr
	oopstd::string e = example5.substr(5, 10);
	cout << e.c_str() << endl;
	cout << endl;

	oopstd::string example6 = "Hello World";//find
	cout << example6.find("World") << endl;
	cout << endl;

	oopstd::string number = "10bus";//stoi
	size_t sz;
	int num = oopstd::stoi(number, &sz,10);
	cout << num << endl;
	cout << sz << endl;
	cout << endl;

	oopstd::string float_number = "1.5abc";//stof
	size_t sz_1;
	float float_num = oopstd::stof(float_number, &sz_1);
	cout << float_num << endl;
	cout << sz_1 << endl;
	cout << endl;

	oopstd::string y = oopstd::to_string(123);//to_string(int)
	cout << y.c_str() << endl;
	cout << endl;

	oopstd::string z = oopstd::to_string((float) - 24.3);//to_string(float)
	cout << z.c_str() << endl;
	cout << endl;
}