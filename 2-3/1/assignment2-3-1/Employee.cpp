#include "Employee.h"

Employee::Employee() {
	name = nullptr;
	age = 0;
	country = nullptr;
	job = nullptr;
}
Employee::Employee(char* name, int age, char* country, char* job) {
	/*name ����*/
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);

	/* age ����*/
	this->age = age;

	/* country ����*/
	len = strlen(country);
	this->country = new char[len + 1];
	strcpy(this->country, country);

	/* job ����*/
	len = strlen(job);
	this->job = new char[len + 1];
	strcpy(this->job, job);
}
Employee::Employee(Employee& A) {
	/*name ����*/
	int len = strlen(A.name);
	this->name = new char[len + 1];
	strcpy(this->name, A.name);

	/* age ����*/
	this->age = A.age;

	/* country ����*/
	len = strlen(A.country);
	this->country = new char[len + 1];
	strcpy(this->country, A.country);

	/* job ����*/
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
	/* name ����*/
	delete[](this->name); // ���� �����ϴ� �޸� ����
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
	
	/* age ����*/
	this->age = age;

	/* country ����*/
	delete[](this->country); // ���� �����ϴ� �޸� ����
	len = strlen(country);
	this->country = new char[len + 1];
	strcpy(this->country, country);
	
	/* job ����*/
	delete[](this->job); // ���� �����ϴ� �޸� ����
	len = strlen(job);
	this->job = new char[len + 1];
	strcpy(this->job, job);
}