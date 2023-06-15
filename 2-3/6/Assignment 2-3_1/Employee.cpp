#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;

// Default constructor
Employee::Employee()
{
    name = nullptr;     // name을 nullptr로 초기화
    age = 0;		// age를 0으로 초기화
    country = nullptr;		// country를 nullptr로 초기화
    job = nullptr;		// job을 nullptr로 초기화
}

// Copy constructor
Employee::Employee(const Employee& other)
{
    name = new char[strlen(other.name) + 1];        // name의 길이 + 1만큼 동적할당
    strcpy_s(name, strlen(other.name) + 1, other.name);     // other.name을 name에 복사
    age = other.age;        // age를 other.age로 변경
    country = new char[strlen(other.country) + 1];	  // country의 길이 + 1만큼 동적할당
    strcpy_s(country, strlen(other.country) + 1, other.country);	 // other.country를 country에 복사
    job = new char[strlen(other.job) + 1];	  // job의 길이 + 1만큼 동적할당
    strcpy_s(job, strlen(other.job) + 1, other.job);	 // other.job을 job에 복사
}

// 매개변수 constructor
Employee::Employee(char* name, int age, char* country, char* job)
{
    this->name = new char[strlen(name) + 1];        // name의 길이 + 1만큼 동적할당
    strcpy_s(this->name, strlen(name) + 1, name);       // name을 this->name에 복사
    this->age = age;        // age를 this->age로 변경
    this->country = new char[strlen(country) + 1];      // country의 길이 + 1만큼 동적할당
    strcpy_s(this->country, strlen(country) + 1, country);      // country를 this->country에 복사
    this->job = new char[strlen(job) + 1];		// job의 길이 + 1만큼 동적할당
    strcpy_s(this->job, strlen(job) + 1, job);      // job을 this->job에 복사
}

// Destructor
Employee::~Employee()
{
    delete[] name;      // 동적할당 해제
    delete[] country;   // 동적할당 해제
    delete[] job;	   // 동적할당 해제
}

// 이름이 맞는지 확인할 함수
bool Employee::isNameCorrect(char* name)
{
    return strcmp(this->name, name) == 0;       // this->name과 name이 같으면 true, 다르면 false 반환
}

// 직원 정보를 출력할 함수
void Employee::print()
{
    cout << "이름 : " << name << endl;
    cout << "나이 : " << age << endl;
    cout << "국적 : " << country << endl;
    cout << "직업 : " << job << endl;
}

// 직원 정보를 바꿀 함수
void Employee::change(char* name, int age, char* country, char* job)
{
    delete[] this->name;
    delete[] this->country;
    delete[] this->job;
    this->name = new char[strlen(name) + 1];        // name의 길이 + 1만큼 동적할당
    strcpy_s(this->name, strlen(name) + 1, name);	   // name을 this->name에 복사
    this->age = age;		// age를 this->age로 변경
    this->country = new char[strlen(country) + 1];		// country의 길이 + 1만큼 동적할당
    strcpy_s(this->country, strlen(country) + 1, country);		// country를 this->country에 복사
    this->job = new char[strlen(job) + 1];		// job의 길이 + 1만큼 동적할당
    strcpy_s(this->job, strlen(job) + 1, job);		// job을 this->job에 복사
}