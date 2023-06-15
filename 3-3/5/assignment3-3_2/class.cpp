#include "class.h"
#include <iostream>

//member functions of Person class
Person::Person()                                   //��� ������ �ʱ�ȭ�ϴ� ������
{
	age = 0;
	name[0] = 0;
}

Person::~Person()                                  //�ı���
{
	age = 0;
	name[0] = 0;
}


//member functions of Professor class
Professor::Professor()                                //��� ������ �ʱ�ȭ�ϴ� ������
{
	age = 0;
	name[0] = 0;
	professorNum[0] = 0;
	major[0] = 0;
}

Professor::~Professor()                               //�ı���
{
	age = 0;
	name[0] = 0;
	professorNum[0] = 0;
	major[0] = 0;
}

int Professor::getAge()                               //���� ��ȯ
{
	return age;
}

char* Professor::getName()                            //name ��ȯ
{
	return name;
}

char* Professor::getProfessorNum()                    //Professor number ��ȯ
{
	return professorNum;
}

char* Professor::getMajor()                           //�а� ��ȯ
{
	return major;
}

void Professor::setAge(int age)                       //���� ����
{
	this->age = age;
}

void Professor::setName(char* name)                   //name ����
{
	copy_str(this->name, name);
}

void Professor::setProfessorNum(char* professorNum)   //Professor number ����
{
	copy_str(this->professorNum, professorNum);
}

void Professor::setMajor(char* major)                 //�а� ����
{
	copy_str(this->major, major);
}

void Professor::Say()                                 //��� ���� ���� ��� ����ϴ� ���� ���� �Լ�
{
	std::cout << "I'm a professor of " << major << " at KW University." << std::endl;  //�а� ���
	std::cout << "My name is " << name << "." << std::endl;                      //���� ���
	std::cout << "I'm " << age << "years old." << std::endl;                     //���̿� ���


	std::cout << "My professor number is " << professorNum << "." << std::endl;   //Professor number ���
}


//member functions of Student class
Student::Student()                                  //��� ������ �ʱ�ȭ�ϴ� ������
{
	age = 0;
	name[0] = 0;
	studentNum[0] = 0;
	major[0] = 0;
	schoolYear = 0;
}

Student::~Student()                                 //�ı���
{
	age = 0;
	name[0] = 0;
	studentNum[0] = 0;
	major[0] = 0;
	schoolYear = 0;
}

int Student::getAge()                               //���� ��ȯ
{
	return age;
}

char* Student::getName()                            //�̸� ��ȯ
{
	return name;
}

char* Student::getStudentNum()                      //�й� ��ȯ
{
	return studentNum;
}

char* Student::getMajor()                           //���� ��ȯ
{
	return major;
}

int Student::getSchoolYear()                        //���� ���� ��ȯ
{
	return schoolYear;
}

void Student::setAge(int age)                       //���� ����
{
	this->age = age;
}

void Student::setName(char* name)                   //�̸� ����
{
	copy_str(this->name, name);
}

void Student::setStudentNum(char* studentNum)       //�й� ����
{
	copy_str(this->studentNum, studentNum);
}

void Student::setMajor(char* major)                 //���� ����
{
	copy_str(this->major, major);
}

void Student::setSchoolYear(int year)               //���� ���� ����
{
	schoolYear = year;
}

void Student::Say()                                 //��� ���� ���� ��� ����ϴ� ���� ���� �Լ�
{
	std::cout << "I'm a student of KW University." << std::endl;
	std::cout << "My name is " << name << "." << std::endl;                      //�̸� ���
	std::cout << "I'm " << age << "years old and I'm a ";                        //���̿� �г� ���
	switch (age)
	{
	case 20:
		std::cout << "freshman." << std::endl;
		break;

	case 21:
		std::cout << "sophomore." << std::endl;
		break;

	case 22:
		std::cout << "junior." << std::endl;
		break;

	default:
		std::cout << "senior." << std::endl;
		break;
	}

	std::cout << "My student number is " << studentNum << "." << std::endl;       //�й� ���
	std::cout << "I'm majoring in " << major << "." << std::endl;                 //���� ���
	std::cout << "I entered the school in " << schoolYear << "." << std::endl;    //���� ���� ���
}


//���ڿ� ���� �Լ�(destination�� source�� �����Ͽ� ����)
char* copy_str(char* destination, const char* source) {
	int i = 0;

	while (1) {
		destination[i] = source[i];  //�� ����

		if (source[i] == '\0') {
			break;  //���ڿ��� ���� ������ ��� �ݺ� ����
		}

		i++;
	}

	return destination;
}