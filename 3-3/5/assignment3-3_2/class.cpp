#include "class.h"
#include <iostream>

//member functions of Person class
Person::Person()                                   //멤버 변수를 초기화하는 생성자
{
	age = 0;
	name[0] = 0;
}

Person::~Person()                                  //파괴자
{
	age = 0;
	name[0] = 0;
}


//member functions of Professor class
Professor::Professor()                                //멤버 변수를 초기화하는 생성자
{
	age = 0;
	name[0] = 0;
	professorNum[0] = 0;
	major[0] = 0;
}

Professor::~Professor()                               //파괴자
{
	age = 0;
	name[0] = 0;
	professorNum[0] = 0;
	major[0] = 0;
}

int Professor::getAge()                               //나이 반환
{
	return age;
}

char* Professor::getName()                            //name 반환
{
	return name;
}

char* Professor::getProfessorNum()                    //Professor number 반환
{
	return professorNum;
}

char* Professor::getMajor()                           //학과 반환
{
	return major;
}

void Professor::setAge(int age)                       //나이 설정
{
	this->age = age;
}

void Professor::setName(char* name)                   //name 설정
{
	copy_str(this->name, name);
}

void Professor::setProfessorNum(char* professorNum)   //Professor number 설정
{
	copy_str(this->professorNum, professorNum);
}

void Professor::setMajor(char* major)                 //학과 설정
{
	copy_str(this->major, major);
}

void Professor::Say()                                 //멤버 변수 값을 모두 출력하는 순수 가상 함수
{
	std::cout << "I'm a professor of " << major << " at KW University." << std::endl;  //학과 출력
	std::cout << "My name is " << name << "." << std::endl;                      //성함 출력
	std::cout << "I'm " << age << "years old." << std::endl;                     //나이와 출력


	std::cout << "My professor number is " << professorNum << "." << std::endl;   //Professor number 출력
}


//member functions of Student class
Student::Student()                                  //멤버 변수를 초기화하는 생성자
{
	age = 0;
	name[0] = 0;
	studentNum[0] = 0;
	major[0] = 0;
	schoolYear = 0;
}

Student::~Student()                                 //파괴자
{
	age = 0;
	name[0] = 0;
	studentNum[0] = 0;
	major[0] = 0;
	schoolYear = 0;
}

int Student::getAge()                               //나이 반환
{
	return age;
}

char* Student::getName()                            //이름 반환
{
	return name;
}

char* Student::getStudentNum()                      //학번 반환
{
	return studentNum;
}

char* Student::getMajor()                           //전공 반환
{
	return major;
}

int Student::getSchoolYear()                        //입학 연도 반환
{
	return schoolYear;
}

void Student::setAge(int age)                       //나이 설정
{
	this->age = age;
}

void Student::setName(char* name)                   //이름 설정
{
	copy_str(this->name, name);
}

void Student::setStudentNum(char* studentNum)       //학번 설정
{
	copy_str(this->studentNum, studentNum);
}

void Student::setMajor(char* major)                 //전공 설정
{
	copy_str(this->major, major);
}

void Student::setSchoolYear(int year)               //입학 연도 설정
{
	schoolYear = year;
}

void Student::Say()                                 //멤버 변수 값을 모두 출력하는 순수 가상 함수
{
	std::cout << "I'm a student of KW University." << std::endl;
	std::cout << "My name is " << name << "." << std::endl;                      //이름 출력
	std::cout << "I'm " << age << "years old and I'm a ";                        //나이와 학년 출력
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

	std::cout << "My student number is " << studentNum << "." << std::endl;       //학번 출력
	std::cout << "I'm majoring in " << major << "." << std::endl;                 //전공 출력
	std::cout << "I entered the school in " << schoolYear << "." << std::endl;    //입학 연도 출력
}


//문자열 복사 함수(destination에 source를 복사하여 저장)
char* copy_str(char* destination, const char* source) {
	int i = 0;

	while (1) {
		destination[i] = source[i];  //값 복사

		if (source[i] == '\0') {
			break;  //문자열의 끝에 도달할 경우 반복 종료
		}

		i++;
	}

	return destination;
}