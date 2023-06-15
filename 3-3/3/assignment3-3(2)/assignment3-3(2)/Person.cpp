#include"Person.h"

Person::Person()
{
	// Person 생성자
	m_age = 0;
	for (int i = 0; i < 32; i++)
		m_name[i] = NULL;
}

Person::~Person() {}

void Person::setage(int age)
{
	m_age = age;
}

void Person::setname(char* name)
{
	for (int i = 0; i < 32; i++)
		m_name[i] = name[i];
}

Professor::Professor()
{
	// Professor 생성자
	// Person의 멤버는 Professor가 생성되기 전에 생성된다. (초기화 필요X)
	for (int i = 0; i < 11; i++)
		m_professornum[i] = NULL;
	for (int i = 0; i < 32; i++)
		m_major[i] = NULL;
}

Professor::~Professor() {}

void Professor::Say()
{
	cout << "==========Professor-Profile==========" << endl;
	cout << "Name: " << m_name << endl;
	cout << "Age: " << m_age << endl;
	cout << "Student Number: " << m_professornum << endl;
	cout << "Major: " << m_major << endl;
}

void Professor::setpnum(char* pnum)
{
	for (int i = 0; i < 11; i++)
		m_professornum[i] = pnum[i];
}

void Professor::setmajor(char* major)
{
	for (int i = 0; i < 32; i++)
		m_major[i] = major[i];
}

Student::Student()
{
	for (int i = 0; i < 11; i++)
		m_studentnum[i] = NULL;
	for (int i = 0; i < 32; i++)
		m_major[i] = NULL;
	m_schoolyear = 0;
}

Student::~Student() {}

void Student::Say()
{
	cout << "==========Student-Profile==========" << endl;
	cout << "Name: " << m_name << endl;
	cout << "Age: " << m_age << endl;
	cout << "Student Number: " << m_studentnum << endl;
	cout << "Major: " << m_major << endl;
	cout << "School Year: " << m_schoolyear << endl;
}

void Student::setsnum(char* snum)
{
	for (int i = 0; i < 11; i++)
		m_studentnum[i] = snum[i];
}

void Student::setmajor(char* major)
{
	for (int i = 0; i < 32; i++)
		m_major[i] = major[i];
}

void Student::setyear(int year)
{
	m_schoolyear = year;
}