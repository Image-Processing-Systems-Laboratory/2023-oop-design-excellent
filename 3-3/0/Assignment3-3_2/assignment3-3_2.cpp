#include<iostream>
#include "Person.h"
using namespace std;


int main()
{
	//�Է¹ޱ�
	cout << "Student" << endl;
	int age_s;
	char name_s[20];
	char studentNum[11];
	char major_s[32];
	int schoolYear;
	cin >> age_s >> name_s >> studentNum >> major_s >> schoolYear;

	//�Է¹ޱ�
	cout << "Professor" << endl;
	int age_p = 21;
	char name_p[20];
	char ProfessorNum[11];
	char major_p[32];
	cin >> age_p >> name_p >> ProfessorNum >> major_p;

	Professor prof1;
	Student stu1;
	
	//�л� ���� ���� �� ���
	stu1.setAge(age_s);
	stu1.setName(name_s);
	stu1.setStudentNum(studentNum);
	stu1.setMajor(major_s);
	stu1.setSchoolYear(schoolYear);
	stu1.Say();
	cout << endl << endl;
	//���� ���� ���� �� ���
	prof1.setAge(age_p);
	prof1.setName(name_p);
	prof1.setprofessorNum(ProfessorNum);
	prof1.setMajor(major_p);
	prof1.Say();

	return 0;
}