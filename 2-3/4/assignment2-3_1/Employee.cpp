#include "Employee.h"

Employee::Employee() : age(0) {};

Employee::Employee(MyString& name, int age, MyString& country, MyString& job): Employee::Employee() {
	this->name = name;
	this->age = age;
	this->country = country;
	this->job = job;
}

bool Employee::isNameCorrect(MyString& name) {
	if (this->name == name)
		return true;
	return false;
}
void Employee::print() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Country: " << country << std::endl;
	std::cout << "Job: " << job << std::endl;
	std::cout << "----------" << std::endl;	
}
void Employee::change(MyString& name, int age, MyString& country, MyString& job){
	this->name = name;
	this->age = age;
	this->country = country;
	this->job = job;
	return;
}

Employee& Employee::operator=(Employee& other) {
	this->name = other.name;
	this->age = other.age;
	this->country = other.country;
	this->job = other.job;
	return *this;
}