#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;

// Default constructor
Employee::Employee()
{
    name = nullptr;     // name�� nullptr�� �ʱ�ȭ
    age = 0;		// age�� 0���� �ʱ�ȭ
    country = nullptr;		// country�� nullptr�� �ʱ�ȭ
    job = nullptr;		// job�� nullptr�� �ʱ�ȭ
}

// Copy constructor
Employee::Employee(const Employee& other)
{
    name = new char[strlen(other.name) + 1];        // name�� ���� + 1��ŭ �����Ҵ�
    strcpy_s(name, strlen(other.name) + 1, other.name);     // other.name�� name�� ����
    age = other.age;        // age�� other.age�� ����
    country = new char[strlen(other.country) + 1];	  // country�� ���� + 1��ŭ �����Ҵ�
    strcpy_s(country, strlen(other.country) + 1, other.country);	 // other.country�� country�� ����
    job = new char[strlen(other.job) + 1];	  // job�� ���� + 1��ŭ �����Ҵ�
    strcpy_s(job, strlen(other.job) + 1, other.job);	 // other.job�� job�� ����
}

// �Ű����� constructor
Employee::Employee(char* name, int age, char* country, char* job)
{
    this->name = new char[strlen(name) + 1];        // name�� ���� + 1��ŭ �����Ҵ�
    strcpy_s(this->name, strlen(name) + 1, name);       // name�� this->name�� ����
    this->age = age;        // age�� this->age�� ����
    this->country = new char[strlen(country) + 1];      // country�� ���� + 1��ŭ �����Ҵ�
    strcpy_s(this->country, strlen(country) + 1, country);      // country�� this->country�� ����
    this->job = new char[strlen(job) + 1];		// job�� ���� + 1��ŭ �����Ҵ�
    strcpy_s(this->job, strlen(job) + 1, job);      // job�� this->job�� ����
}

// Destructor
Employee::~Employee()
{
    delete[] name;      // �����Ҵ� ����
    delete[] country;   // �����Ҵ� ����
    delete[] job;	   // �����Ҵ� ����
}

// �̸��� �´��� Ȯ���� �Լ�
bool Employee::isNameCorrect(char* name)
{
    return strcmp(this->name, name) == 0;       // this->name�� name�� ������ true, �ٸ��� false ��ȯ
}

// ���� ������ ����� �Լ�
void Employee::print()
{
    cout << "�̸� : " << name << endl;
    cout << "���� : " << age << endl;
    cout << "���� : " << country << endl;
    cout << "���� : " << job << endl;
}

// ���� ������ �ٲ� �Լ�
void Employee::change(char* name, int age, char* country, char* job)
{
    delete[] this->name;
    delete[] this->country;
    delete[] this->job;
    this->name = new char[strlen(name) + 1];        // name�� ���� + 1��ŭ �����Ҵ�
    strcpy_s(this->name, strlen(name) + 1, name);	   // name�� this->name�� ����
    this->age = age;		// age�� this->age�� ����
    this->country = new char[strlen(country) + 1];		// country�� ���� + 1��ŭ �����Ҵ�
    strcpy_s(this->country, strlen(country) + 1, country);		// country�� this->country�� ����
    this->job = new char[strlen(job) + 1];		// job�� ���� + 1��ŭ �����Ҵ�
    strcpy_s(this->job, strlen(job) + 1, job);		// job�� this->job�� ����
}