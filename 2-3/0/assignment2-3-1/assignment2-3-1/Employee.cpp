#include <iostream>
#include "Employee.h"

class Employee {

private:
	char* name;
	int age;
	char* country;
	char* job;

public:
	Employee();
	Employee(char* name, int age, char* country, char* job) {
		this->name = name;
		this->age = age;
		this->country = country;
		this->job = job;
	}
	Employee(Employee& A);

	bool isNameCorrect(char* name) {
		if (this->name == name) {
			return true;
		}
		else {
			return false;
		}
	}
	void print() {
		std::cout << "Name: " << name << std::endl;
		std::cout << "Age: " << age << std::endl;
		std::cout << "Country: " << country << std::endl;
		std::cout << "Job: " << job << std::endl;
	}
	void change(char* name, int age, char* country, char* job) {
		this->name = name;
		this->age = age;
		this->country = country;
		this->job = job;
	}
};
