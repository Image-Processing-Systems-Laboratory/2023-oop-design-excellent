#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Person // ��� Ŭ����
{
protected: //��� ������ protected�� ����
	int age; // ����
	char name[32]; // �̸�
public: // ��� �Լ�
	Person(); // ����Ʈ ������
	~Person(); // �Ҹ���
	virtual void Say() = 0; // ���� �Լ�
};

Person::Person() // �⺻ ������
{
	age = 0; // ���̸� 0���� �ʱ�ȭ
	strcpy(name, ""); // �̸��� �������� �ʱ�ȭ
}

Person::~Person() // �Ҹ���
{
}

class Student : public Person // �л� Ŭ������ person Ŭ������ ��ӹ޾� ����
{
protected: // ��� ������ protected�� ����
	char studentNum[11]; // �й�
	char major[32]; // ����
	int schoolYear; // �г�
public: // ��� �Լ�
	Student(); //  ������
	~Student(); // �Ҹ���
	int GetAge(); // ���̸� ��ȯ�ϴ� �Լ�
	char* GetName(); // �̸��� ��ȯ�ϴ� �Լ�
	char* GetStudentNum(); // �й��� ��ȯ�ϴ� �Լ�
	char* GetMajor(); // ������ ��ȯ�ϴ� �Լ�
	int GetSchoolYear(); // �г��� ��ȯ�ϴ� �Լ�
	void SetAge(int age); // ���̸� �����ϴ� �Լ�
	void SetName(char* name); // �̸��� �����ϴ� �Լ�
	void SetStudentNum(char* studentNum); // �й��� �����ϴ� �Լ�
	void SetMajor(char* major); // ������ �����ϴ� �Լ�
	void SetSchoolYear(int schoolYear); // �г��� �����ϴ� �Լ�
	void Say(); // ���� �Լ�
};

Student::Student() // ������
{
	strcpy(studentNum, ""); // �й��� �������� �ʱ�ȭ
	strcpy(major, ""); // ������ �������� �ʱ�ȭ
	schoolYear = 0; // �г��� 0���� �ʱ�ȭ 
}

Student::~Student() // �Ҹ���
{
}

int Student::GetAge() // ���̸� ��ȯ�ϴ� �Լ�
{
	return age; // ���̸� ��ȯ
}

char* Student::GetName() // �̸��� ��ȯ�ϴ� �Լ�
{
	return name; // �̸��� ��ȯ
}

char* Student::GetStudentNum() // �й��� ��ȯ�ϴ� �Լ�
{
	return studentNum; // �й��� ��ȯ
}

char* Student::GetMajor() // ������ ��ȯ�ϴ� �Լ�
{
	return major; // ������ ��ȯ
}

int Student::GetSchoolYear() // �г��� ��ȯ�ϴ� �Լ�
{
	return schoolYear; // �г��� ��ȯ
}

void Student::SetAge(int age) // ���̸� �����ϴ� �Լ�
{
	this->age = age; // ���̸� ����
}

void Student::SetName(char* name) // �̸��� �����ϴ� �Լ�
{
	strcpy(this->name, name); // �̸��� ����
}

void Student::SetStudentNum(char* studentNum) // �й��� �����ϴ� �Լ�
{
	strcpy(this->studentNum, studentNum); // �й��� ����
}

void Student::SetMajor(char* major) // ������ �����ϴ� �Լ�
{
	strcpy(this->major, major); // ������ ����
}

void Student::SetSchoolYear(int schoolYear) // �г��� �����ϴ� �Լ�
{
	this->schoolYear = schoolYear; // �г��� ����
}

void Student::Say() // ���� �Լ�
{
	// �л��� ������ ���
	cout << "I`m a student of KW University." << endl; 
	cout << "My student number is " << studentNum << " and my name is " << name << "." << endl;
	cout << "I`m " << age << " years old." << endl;
	cout << "My major is " << major << "." << endl;
	cout << "I`m " << schoolYear << "th grade." << endl;
}

class Professor : public Person // ���� Ŭ������ person Ŭ������ ��ӹ޾� ����
{
protected: // ��� ������ protected�� ����
	char professorNum[11]; // ���� ��ȣ
	char major[32]; // ����
public: // ��� �Լ�
	Professor(); // ������
	~Professor(); // �Ҹ���
	int GetAge(); // ���̸� ��ȯ�ϴ� �Լ�
	char* GetName(); // �̸��� ��ȯ�ϴ� �Լ�
	char* GetProfessorNum(); // ���� ��ȣ�� ��ȯ�ϴ� �Լ�
	char* GetMajor(); // ������ ��ȯ�ϴ� �Լ�
	void SetAge(int age); // ���̸� �����ϴ� �Լ�
	void SetName(char* name); // �̸��� �����ϴ� �Լ�
	void SetProfessorNum(char* professorNum); // ���� ��ȣ�� �����ϴ� �Լ�
	void SetMajor(char* major); // ������ �����ϴ� �Լ�
	void Say(); // ���� �Լ�
};

Professor::Professor() // ������
{
	strcpy(professorNum, ""); // ���� ��ȣ�� �������� �ʱ�ȭ
	strcpy(major, ""); // ������ �������� �ʱ�ȭ
}

Professor::~Professor() // �Ҹ���
{
}

int Professor::GetAge() // ���̸� ��ȯ�ϴ� �Լ�
{
	return age; // ���̸� ��ȯ
}

char* Professor::GetName() // �̸��� ��ȯ�ϴ� �Լ�
{
	return name; // �̸��� ��ȯ
}

char* Professor::GetProfessorNum() // ���� ��ȣ�� ��ȯ�ϴ� �Լ�
{
	return professorNum; // ���� ��ȣ�� ��ȯ
}

char* Professor::GetMajor() // ������ ��ȯ�ϴ� �Լ�
{
	return major; // ������ ��ȯ
}

void Professor::SetAge(int age) // ���̸� �����ϴ� �Լ�
{
	this->age = age; // ���̸� ����
}

void Professor::SetName(char* name) // �̸��� �����ϴ� �Լ�
{
	strcpy(this->name, name); // �̸��� ����
}

void Professor::SetProfessorNum(char* professorNum) // ���� ��ȣ�� �����ϴ� �Լ�
{
	strcpy(this->professorNum, professorNum); // ���� ��ȣ�� ����
}

void Professor::SetMajor(char* major) // ������ �����ϴ� �Լ�
{
	strcpy(this->major, major); // ������ ����
}

void Professor::Say() // ���� �Լ�
{
	// ������ ������ ���
	cout << "I`m a professor of KW University." << endl;
	cout << "My professor number is " << professorNum << " and my name is " << name << "." << endl;
	cout << "I`m " << age << " years old." << endl;
	cout << "My major is " << major << "." << endl;
}

int main()
{
	char studentNum[11]; // �л� ��ȣ
	char name1[32]; // �л� �̸�
	int age1; // �л� ����
	char major1[32]; // �л� ����
	int schoolYear; // �л� �г�
	char professorNum[11]; // ���� ��ȣ
	char name2[32]; // ���� �̸�
	int age2; // ���� ����
	char major2[32]; // ���� ����
	
	cout << "�л� ���� �Է�" << endl; // �л� ���� �Է� �ȳ��� ���
	cout << "�й�: "; // �й� �Է� �ȳ��� ��� 
	cin.getline(studentNum, 11); // �й� �Է�
	cout << "�̸�: "; // �̸� �Է� �ȳ��� ���
	cin.getline(name1, 32); // �̸� �Է�
	cout << "����: "; // ���� �Է� �ȳ��� ���
	cin >> age1; // ���� �Է�
	cout << "����: "; // ���� �Է� �ȳ��� ���
	cin.ignore(); // ���� ����
	cin.getline(major1, 32); // ���� �Է�
	cout << "�г�: "; // �г� �Է� �ȳ��� ���
	cin >> schoolYear; // �г� �Է�
	cout << endl; // �� �ٲ�
	
	
	
	cout << "���� ���� �Է�" << endl; // ���� ���� �Է� �ȳ��� ���
	cout << "����: "; // ���� �Է� �ȳ��� ���
	cin.ignore(); // ���� ����
	cin.getline(professorNum, 11); // ���� �Է�
	cout << "�̸�: "; // �̸� �Է� �ȳ��� ���
	cin.getline(name2, 32); // �̸� �Է�
	cout << "����: "; // ���� �Է� �ȳ��� ���
	cin >> age2; // ���� �Է�
	cout << "����: "; // ���� �Է� �ȳ��� ���
	cin.ignore(); // ���� ����
	cin.getline(major2, 32); // ���� �Է�
	cout << endl;
	
	Student student; // Student Ŭ���� ��ü ����
	student.SetStudentNum(studentNum); // �л� ��ȣ ����
	student.SetName(name1); // �̸� ����
	student.SetAge(age1); // ���� ����
	student.SetMajor(major1); // ���� ����
	student.SetSchoolYear(schoolYear); // �г� ����
	student.Say(); // �л� ���� ���
	cout << endl;
	
	Professor professor; // Professor Ŭ���� ��ü ����
	professor.SetProfessorNum(professorNum); // ���� ��ȣ ����
	professor.SetName(name2); // �̸� ����
	professor.SetAge(age2); // ���� ����
	professor.SetMajor(major2); // ���� ����
	professor.Say(); // ���� ���� ���
	
	return 0; // ���α׷� ����
}

