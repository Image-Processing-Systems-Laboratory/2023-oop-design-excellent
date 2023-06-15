#include "Person.h"

//����Ʈ ������
Person::Person() {
	//��� ���� �ʱ�ȭ
	this->age = 0;
	this->name[0] = '\0';
}
//�Ҹ���
Person::~Person() {}
//���� �����Լ�
void Person::Say(){}

//����Ʈ ������
Student::Student() {
	//��� ���� �ʱ�ȭ
	this->studentNum[0] = '\0';
	this->major[0] = '\0';
	this->schoolYear = 0;
}
//�Ҹ���
Student::~Student() {}
//���̸� ��ȯ�ϴ� �Լ�
int Student::getAge() {
	return this->age;		//���� ��ȯ
}
//�̸��� ��ȯ�ϴ� �Լ�
char* Student::getName() {
	return this->name;		//�̸� ��ȯ
}
//�л� �й��� ��ȯ�ϴ� �Լ�
char* Student::getStudentNum() {
	return this->studentNum;	//�л� �й� ��ȯ
}
//������ ��ȯ�ϴ� �Լ�
char* Student::getMarjor() {
	return this->major;			//���� ��ȯ
}
//�г��� ��ȯ�ϴ� �Լ�
int Student::getSchoolYear() {
	return this->schoolYear;	//�г� ��ȯ
}
//���̸� �����ϴ� �Լ�
void Student::setAge(int age) {
	this->age = age;			//���� ����
}
//�̸��� �����ϴ� �Լ�
void Student::setName(char* name) {
	strcpy(this->name, name);	//�̸� ����
}
//�л� �й��� �����ϴ� �Լ�
void Student::setStudentNum(char* studentNum) {
	strcpy(this->studentNum, studentNum);		//�л��й� ����
}
//������ �����ϴ� �Լ�
void Student::setMajor(char* major) {
	strcpy(this->major, major);			//���� ����
}
//�г��� �����ϴ� �Լ�
void Student::setSchoolYear(int year) {
	this->schoolYear = year;			//�г� ����
}
//Say �Լ� overriding
void Student::Say() {
	std::cout << "I'm a student of KW University." << std::endl;
	std::cout << "My name is " << this->name << "." << std::endl;
	std::cout << "My StudentNum is " << this->studentNum << "." << std::endl;
	std::cout << "I'm " << this->age << " years old and I'm a sophomore." << std::endl;
	std::cout << "I'm majoring in " << this->major << "." << std::endl;
}
//����Ʈ ������
Professor::Professor() {
	//��� ���� �ʱ�ȭ
	this->professorNum[0] = '\0';
	this->major[0] = '\0';
}
//�Ҹ���
Professor::~Professor() {}
//���̸� ��ȯ�ϴ� �Լ�
int Professor::getAge() {
	return this->age;		//���� ��ȯ
}
//�̸��� ��ȯ�ϴ� �Լ�
char* Professor::getName() {
	return this->name;		//�̸� ��ȯ
}
//���� �й��� ��ȯ�ϴ� �Լ�
char* Professor::getprofessorNum() {
	return this->professorNum;	//���� �й� ��ȯ
}
//������ ��ȯ�ϴ� �Լ�
char* Professor::getMarjor() {
	return this->major;			//���� ��ȯ
}
//���̸� �����ϴ� �Լ�
void Professor::setAge(int age) {
	this->age = age;				//���� ����
}
//�̸��� �����ϴ� �Լ�
void Professor::setName(char* name) {
	strcpy(this->name, name);		//�̸� ����
}
//���� �й��� �����ϴ� �Լ�
void Professor::setprofessorNum(char* professorNum) {
	strcpy(this->professorNum, professorNum);		//�����й� ����
}
//������ �����ϴ� �Լ�
void Professor::setMajor(char* major) {
	strcpy(this->major, major);		//���� ����
}
//Say �Լ� overriding
void Professor::Say() {
	std::cout << "I'm a professor of KW University." << std::endl;
	std::cout << "My name is " << this->name << "." << std::endl;
	std::cout << "My professor is " << this->professorNum << "." << std::endl;
	std::cout << "I'm " << this->age << " years old." << std::endl;
	std::cout << "I'm majoring in " << this->major << "." << std::endl;
}