#include "Employee.h"

Employee::Employee() {
	name = nullptr;
	age = 0;
	country = nullptr;
	job = nullptr;
}
Employee::Employee(char* name, int age, char* country, char* job) {
	/*name 복사*/
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);

	/* age 복사*/
	this->age = age;

	/* country 복사*/
	len = strlen(country);
	this->country = new char[len + 1];
	strcpy(this->country, country);

	/* job 복사*/
	len = strlen(job);
	this->job = new char[len + 1];
	strcpy(this->job, job);
}
Employee::Employee(Employee& A) {
	/*name 복사*/
	int len = strlen(A.name);
	this->name = new char[len + 1];
	strcpy(this->name, A.name);

	/* age 복사*/
	this->age = A.age;

	/* country 복사*/
	len = strlen(A.country);
	this->country = new char[len + 1];
	strcpy(this->country, A.country);

	/* job 복사*/
	len = strlen(A.job);
	this->job = new char[len + 1];
	strcpy(this->job, A.job);
}
Employee::~Employee() {
	if(name)
		delete[]name;
	if(country)
		delete[]country;
	if(job)
		delete[]job;
}
bool Employee::isNameCorret(char* name) {
	if (!strcmp(this->name, name))
		return true;
	else
		return false;
}
void  Employee::print() {
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Country: " << country << endl;
	cout << "Job: " << job << endl;
}
void  Employee::change(char* name, int age, char* country, char* job) {
	/* name 변경*/
	delete[](this->name); // 먼저 존재하던 메모리 해제
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
	
	/* age 변경*/
	this->age = age;

	/* country 변경*/
	delete[](this->country); // 먼저 존재하던 메모리 해제
	len = strlen(country);
	this->country = new char[len + 1];
	strcpy(this->country, country);
	
	/* job 변경*/
	delete[](this->job); // 먼저 존재하던 메모리 해제
	len = strlen(job);
	this->job = new char[len + 1];
	strcpy(this->job, job);
}