#include "string.h"
#include <iostream>

using namespace oopstd;

int main() {
	string a;
	a.assign("HI");
	std::cout << a << std::endl;		// result: "HI"

	string example = "Hello World";
	std::cout << example.at(2) << std::endl;		// result: "l"

	const char* b;
	b = example.c_str();
	std::cout << b << std::endl;		// result: "Hello World"

	example.clear();
	std::cout << example << std::endl;		// result: None

	example.push_back('b');
	std::cout << example << std::endl;		// result: "b"

	std::cout << example.compare(&a) << std::endl;		//result: 1

	example = "Hello World";
	string d = example.replace(0, 5, &a);
	std::cout << d << std::endl;		// result: "b"

	example = "Hello World";
	string c = example.substr(5, 10);
	std::cout << c << std::endl;		// result: " World"


	string number2 = "10bus";
	size_t sz;
	int num = stoi(number2, &sz);
	std::cout << num << std::endl;
	std::cout << sz << std::endl;

	string float_number = "1.5abc";
	float float_num = stof(float_number, &sz);
	std::cout << float_num << std::endl;
	std::cout << sz << std::endl;


}