#define _CRT_SECURE_NO_WARNINGS
#include "oopstd.h"
#include <string.h>


int main(void) {
	std::cout << "---------memset-----------"<<std::endl;
	char str[] = "almost every programmer should know memset!";
	std::cout << "memset" << std::endl;
	memset(str, '-', 6);
	std::cout << str << std::endl;
	std::cout << "oopstd::memset" << std::endl;
	oopstd::memset(str, '*', 6);
	std::cout << str << std::endl;

	std::cout << "---------memcpy-----------" << std::endl;
	char hel[] = "Hello World";
	char abc[50]={0};
	std::cout << "memcpy" << std::endl;
	memcpy(abc, hel, sizeof(char)*6);
	std::cout << abc<<std::endl;
	std::cout << "oopstd::memcpy" << std::endl;
	oopstd::memcpy(abc, hel, 8);
	std::cout << abc << std::endl;

	std::cout << "---------strcmp-----------" << std::endl;
	char b[] = "hello";
	char a[] = "hello";
	std::cout << "strcmp" << std::endl;
	if (strcmp(a, b) == 0) std::cout << "Correct Answer !" << std::endl;
	std::cout << "oopstd::strcmp" << std::endl;
	if (oopstd::strcmp(a, b) == 0) std::cout << "Correct Answer !" << std::endl;

	std::cout << "---------strncmp----------" << std::endl;
	std::cout << "strncmp" << std::endl;
	if(strncmp(a,b,3)==0) std::cout << "Correct Answer !" << std::endl;
	std::cout << "oopstd::strncmp" << std::endl;
	if (oopstd::strncmp(a, b, 3) == 0) std::cout << "Correct Answer !" << std::endl;

	std::cout << "---------strcpy-----------" << std::endl;
	char c[50] = { 0 };
	std::cout << "strcpy" << std::endl;
	strcpy(c, a);
	std::cout << c << std::endl;
	std::cout << "oopstd::strcpy" << std::endl;
	oopstd::strcpy(c, a);
	std::cout << c << std::endl;

	std::cout << "---------strncpy----------" << std::endl;
	char d[50] = { 0 };
	std::cout << "strncpy" << std::endl;
	strncpy(d, b, 3);
	std::cout << d << std::endl;
	std::cout << "oopstd::strncpy" << std::endl;
	oopstd::strncpy(d, b, 3);
	std::cout << d << std::endl;

	std::cout << "---------strlen-----------" << std::endl;
	std::cout << "strlen" << std::endl;
	std::cout << strlen(str) << std::endl;
	std::cout << "oopstd::strlen" << std::endl;
	std::cout << oopstd::strlen(str) << std::endl;

	std::cout << "-----------atoi-----------" << std::endl;
	char arr[] = {"+1"};
	int oop[10] = {0};
	std::cout << "atoi" << std::endl;
	std::cout<<atoi(arr)<<std::endl;
	std::cout << "oopstd::atoi" << std::endl;
	std::wcout << oopstd::atoi(arr)<<std::endl;

	std::cout << "-----------atof-----------" << std::endl;
	char qwe[] = { "-1.1" };
	std::cout << "atof" << std::endl;
	std::cout << atof(qwe)<<std::endl;
	std::cout << "oopstd::atof" << std::endl;
	std::cout << oopstd::atof(qwe) << std::endl;
	return 0;
}