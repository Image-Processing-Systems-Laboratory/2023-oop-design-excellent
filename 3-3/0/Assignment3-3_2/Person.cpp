#include "Person.h"

//디폴트 생성자
Person::Person() {
	//멤버 변수 초기화
	this->age = 0;
	this->name[0] = '\0';
}
//소멸자
Person::~Person() {}
//순수 가상함수
void Person::Say(){}

//디폴트 생성자
Student::Student() {
	//멤버 변수 초기화
	this->studentNum[0] = '\0';
	this->major[0] = '\0';
	this->schoolYear = 0;
}
//소멸자
Student::~Student() {}
//나이를 반환하는 함수
int Student::getAge() {
	return this->age;		//나이 반환
}
//이름을 반환하는 함수
char* Student::getName() {
	return this->name;		//이름 반환
}
//학생 학번을 반환하는 함수
char* Student::getStudentNum() {
	return this->studentNum;	//학생 학번 반환
}
//전공을 반환하는 함수
char* Student::getMarjor() {
	return this->major;			//전공 반환
}
//학년을 반환하는 함수
int Student::getSchoolYear() {
	return this->schoolYear;	//학년 반환
}
//나이를 저장하는 함수
void Student::setAge(int age) {
	this->age = age;			//나이 저장
}
//이름을 저장하는 함수
void Student::setName(char* name) {
	strcpy(this->name, name);	//이름 저장
}
//학생 학번을 저장하는 함수
void Student::setStudentNum(char* studentNum) {
	strcpy(this->studentNum, studentNum);		//학생학번 저장
}
//전공을 저장하는 함수
void Student::setMajor(char* major) {
	strcpy(this->major, major);			//전공 저장
}
//학년을 저장하는 함수
void Student::setSchoolYear(int year) {
	this->schoolYear = year;			//학년 저장
}
//Say 함수 overriding
void Student::Say() {
	std::cout << "I'm a student of KW University." << std::endl;
	std::cout << "My name is " << this->name << "." << std::endl;
	std::cout << "My StudentNum is " << this->studentNum << "." << std::endl;
	std::cout << "I'm " << this->age << " years old and I'm a sophomore." << std::endl;
	std::cout << "I'm majoring in " << this->major << "." << std::endl;
}
//디폴트 생성자
Professor::Professor() {
	//멤버 변수 초기화
	this->professorNum[0] = '\0';
	this->major[0] = '\0';
}
//소멸자
Professor::~Professor() {}
//나이를 반환하는 함수
int Professor::getAge() {
	return this->age;		//나이 반환
}
//이름을 반환하는 함수
char* Professor::getName() {
	return this->name;		//이름 반환
}
//교수 학번을 반환하는 함수
char* Professor::getprofessorNum() {
	return this->professorNum;	//교수 학번 반환
}
//전공을 반환하는 함수
char* Professor::getMarjor() {
	return this->major;			//전공 반환
}
//나이를 저장하는 함수
void Professor::setAge(int age) {
	this->age = age;				//나이 저장
}
//이름을 저장하는 함수
void Professor::setName(char* name) {
	strcpy(this->name, name);		//이름 저장
}
//교수 학번을 저장하는 함수
void Professor::setprofessorNum(char* professorNum) {
	strcpy(this->professorNum, professorNum);		//교수학번 저장
}
//전공을 저장하는 함수
void Professor::setMajor(char* major) {
	strcpy(this->major, major);		//전공 저장
}
//Say 함수 overriding
void Professor::Say() {
	std::cout << "I'm a professor of KW University." << std::endl;
	std::cout << "My name is " << this->name << "." << std::endl;
	std::cout << "My professor is " << this->professorNum << "." << std::endl;
	std::cout << "I'm " << this->age << " years old." << std::endl;
	std::cout << "I'm majoring in " << this->major << "." << std::endl;
}