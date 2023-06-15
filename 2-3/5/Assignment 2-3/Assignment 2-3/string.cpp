#define _CRT_SECURE_NO_WARNINGS6

#include "string.h"
#include <iostream>
#include <sstream>

using namespace oopstd;

string::string(): s(nullptr), len(0)					//just initiallize
{

}

string::string(const char* s): s(nullptr), len(0)		//set s and len 
{
	if (s != nullptr) {
		len = strlen(s);
		this->s = new char[len + 1];

		size_t i = 0;
		while (s[i] != '\0' && i < len)
		{
			this->s[i] = s[i];
			i++;
		}
		this->s[i] = '\0';
	}
}

string::string(const string& str): s(nullptr), len(0)	//set with &str
{
	len = str.len;
	s = new char[len + 1];

	size_t i = 0;
	while (str.s[i] != '\0' && i < len)
	{
		s[i] = str.s[i];
		i++;
	}
	s[i] = '\0';
}

string::~string()										//free
{
	delete[] s;
}

string&  string::assign(const string& str)				//reset string data
{
	if (this != &str) {
		delete[] s;
		len = str.len;
		s = new char[len + 1];

		size_t i = 0;
		while (str.s[i] != '\0' && i < len)
		{
			s[i] = str.s[i];
			i++;
		}
		s[i] = '\0';
	}
	return *this;
}

char& string::at(size_t pos)							//print char by pos ex) pos = 2 print 3rd char
{
	if (pos >= len) {
		throw std::out_of_range("position out of range");
	}
	return s[pos];
}

const char* string::c_str() const						//return const char* just s
{
	if (s == nullptr)
		return "";

	return s;
}

void string::clear()									//reset string
{
	if (s != nullptr) {
		delete[] s;
		s = nullptr;
	}
	len = 0;
}

void string::push_back(char c)							//insert char tail of char
{
	if (s == nullptr) {
		s = new char[2];
		s[0] = c;
		s[1] = '\0';
		len = 1;
	}
	else {

		char* temp = new char[len + 2];
		for (int i = 0; i < len; i++)
		{
			temp[i] = s[i];
		}
		temp[len] = c;
		temp[len + 1] = '\0';
		s = nullptr;
		s = temp;
		len++;
	}
}

int string::compare(const string* str) const		//compare same = 0. else if  str1 > str2 1 else -1
{
	if (str == nullptr) {
		return 1;
	}

	if (this == str) {
		return 0;
	}
	
	const char* p1 = s;
	const char* p2 = str->s;
	while (*p1 && (*p1 == *p2)) {
		++p1;
		++p2;
	}

	return (*p1 - *p2) > 0 ? 1 : (*p1 - *p2) == 0 ? 0 : -1;
}

string& string::replace(size_t pose, size_t len, const string* str) //replace string with set positon
{
	if (pose > len) {
		throw std::out_of_range("position out of range");
	}

	size_t newLen = this->len - len + str->len;
	char* newS = new char[newLen + 1];

	// Copy characters before the replaced segment  (before pose)
	std::memcpy(newS, s, pose);
	size_t endOfPrefix = pose;

	// Copy the replacement string					(str size: len - pose + 1)
	std::memcpy(newS + endOfPrefix, str->s, str->len);
	size_t endOfReplacement = endOfPrefix + str->len;

	// Copy characters after the replaced segment	(afeter len)
	std::memcpy(newS + endOfReplacement, s + pose + len, this->len - pose - len);
	newS[newLen] = '\0';					//set \0

	delete[] s;
	s = newS;
	this->len = newLen;

	return *this;
}

string string::substr(size_t pos, size_t len) const				//copy string with position
{
	if (s == nullptr) {
		return "\0";
	}
	else 
	{
		int index = 0;
		char* temp = new char[len - pos + 2];
		for (size_t i = pos; i < len + 1; i++)
		{
			temp[index] = s[i];
			index++;
		}
		temp[index] = '\0';

		return temp;
	}
}

size_t string::find(const string& str, size_t pos) const	//find string data start point is pos
{
	char* ptr = std::strstr(s + pos, str.s);
	if (ptr == nullptr) {
		return -1;
	}
	return ptr - s;
}


int oopstd::stoi(const string& str, size_t idx, int base)	//string to int
{
	char* endptr;
	long val = std::strtol(str.c_str() + idx, &endptr, base);
	if (endptr == str.c_str() + idx) {
		throw std::invalid_argument("invalid argument");
	}
	if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min()) {
		throw std::out_of_range("out of range");
	}
	return static_cast<int>(val);
}

float oopstd::stof(const string& str, size_t* idx)		//string to float
{
	char* endptr;
	float val = std::strtof(str.c_str(), &endptr);
	if (endptr == str.c_str()) {
		throw std::invalid_argument("invalid argument");
	}
	if (idx != nullptr) {
		*idx = endptr - str.c_str();
	}
	return val;
}

string oopstd::to_string(int val)					//int to string with sstream
{
	std::ostringstream ss;
	ss << val;
	std::string str = ss.str();
	return string(str.c_str());
}

string oopstd::to_string(float val)					//float to string with sstream
{
	std::ostringstream ss;
	ss << val;
	std::string str = ss.str();
	return string(str.c_str());
}