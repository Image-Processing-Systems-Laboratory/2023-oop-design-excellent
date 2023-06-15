#include "OverridePerson.h"

using namespace std;

Person::Person() : age(0), name{} { };
Person::~Person() { };

Student::Student() : studentNum{}, major{}, schoolYear(0) { };
Student::~Student() { };

const int Student::getAge() const { return Person::age; };

const char* Student::getName() const { return Person::name; };

const char* Student::getStudentNum() const { return studentNum; };

const char* Student::getMajor() const { return major; };

const int Student::getschoolYear() const { return schoolYear; };

void Student::setAge(const int age) { this->age = age; };

void Student::setName(const char* name) { strncpy(this->name, name, string_maxsize); }; // strncpy임을 주의!!

void Student::setStudentNum(const char* studentNum) { strncpy(this->studentNum, studentNum, num_maxsize); };

void Student::setMajor(const char* major) { strncpy(this->major, major, string_maxsize); };

void Student::setSchoolYear(const int year) { this->schoolYear = year; };

void Student::Say()
{
	cout << "My name is " << this->getName() << "." << endl;
	cout << "My Student Number is " << this->getStudentNum() << "." <<  endl;
	cout << "I'm " << this->getAge() << " years old and I'm a ";

	if (this->getschoolYear() == 1) cout << "freshman." << endl;
	else if (this->getschoolYear() == 2) cout << "sophomore." << endl;
	else if (this->getschoolYear() == 3) cout << "Junior." << endl;
	else if (this->getschoolYear() == 4) cout << "Senior." << endl;

	//schoolYear에서 반환받은 값에 맞춰 알맞은 string 출력
	cout << "I'm majoring in " << this->getMajor() << "." << endl;
}

Professor::Professor() : professornum{}, major{} { };

Professor::~Professor() { };

const int Professor::getAge() const { return Person::age; };

const char* Professor::getName() const { return Person::name; };

const char* Professor::getprofessornum() const { return professornum; };

const char* Professor::getMajor() const { return major; };

void Professor::setAge(const int age) { this->age = age; };

void Professor::setName(const char* name) { strncpy(this->name, name, string_maxsize); };

void Professor::setprofessornum(const char* professornum) { strncpy(this->professornum, professornum, num_maxsize); };

void Professor::setMajor(const char* major) { strncpy(this->major, major, string_maxsize); };

void Professor::Say()
{
	cout << "My name is " << this->getName() << "." << endl;
	cout << "I'm " << this->getAge() << " years." << endl;
	cout << "My Professor Number is " << this->getprofessornum() << "." << endl;
	cout << "And I'm majoring in " << this->getMajor() << "." << endl;
}
