#include "oopstd.h"
#include <iostream>
using namespace oopstd;

int main() {

	// Test constructors
	string s1;
	string s2("Hello, world!");
	string s3(s2);

	// Test assign
	s1.assign(s3);
	std::cout << "s1: " << s1.c_str() << std::endl;

	// Test at
	std::cout << "s2[0]: " << s2.at(0) << std::endl;

	// Test c_str
	std::cout << "s3: " << s3.c_str() << std::endl;

	// Test clear
	s1.clear();
	std::cout << "s1 (cleared): " << s1.c_str() << std::endl;

	// Test push_back
	s1.push_back('A');
	s1.push_back('B');
	s1.push_back('C');
	std::cout << "s1 (pushed back): " << s1.c_str() << std::endl;

	// Test compare
	std::cout << "s1.compare(s3): " << s1.compare(s3) << std::endl;

	// Test replace
	s2.replace(0, 5, "Hi");
	std::cout << "s2 (replaced): " << s2.c_str() << std::endl;

	// Test substr
	string s4 = s3.substr(7, 5);
	std::cout << "s3.substr(7, 5): " << s4.c_str() << std::endl;

	// Test find
	size_t pos = s3.find("world");
	std::cout << "s3.find(\"world\"): " << pos << std::endl;

	// Test stoi
	string num_str("42");
	int num = oopstd::stoi(num_str);
	std::cout << "stoi(\"42\"): " << num << std::endl;

	// Test stof
	string float_str("3.14159");
	float pi = oopstd::stof(float_str);
	std::cout << "stof(\"3.14159\"): " << pi << std::endl;

	// Test to_string (int and float)
	string num_string = oopstd::to_string(42);
	string pi_string = oopstd::to_string(3.14159f);
	std::cout << "to_string(42): " << num_string.c_str() << std::endl;
	std::cout << "to_string(3.14159): " << pi_string.c_str() << std::endl;

	return 0;
}
