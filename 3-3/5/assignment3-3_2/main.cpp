#include "class.h"
#include <iostream>

using namespace std;

int main(void)
{
	Professor professor;
	Student student;

	char str[32];    //�Է� ���� ���ڿ��� �ӽ� ������ �迭
	int num;         //�Է� ���� ������ �ӽ� ������ ����

	//������ ���� �Է�
	cout << "[Professor]" << endl;

	cout << "Age: ";
	cin >> num;
	professor.setAge(num);
	getchar();

	cout << "Name: ";
	cin.getline(str, 32);
	professor.setName(str);

	cout << "Professor number: ";
	cin.getline(str, 11);
	professor.setProfessorNum(str);

	cout << "Major: ";
	cin.getline(str, 32);
	professor.setMajor(str);

	cout << "---------------------------------------------------------" << endl;

	//�л� ���� �Է�
	cout << "[Student]" << endl;

	cout << "Age: ";
	cin >> num;
	student.setAge(num);
	getchar();

	cout << "Name: ";
	cin.getline(str, 32);
	student.setName(str);

	cout << "Student number: ";
	cin.getline(str, 11);
	student.setStudentNum(str);

	cout << "Major: ";
	cin.getline(str, 32);
	student.setMajor(str);

	cout << "School year: ";
	cin >> num;
	student.setSchoolYear(num);

	cout << "=========================================================" << endl;

	//������ ���� ���
	professor.Say();
	cout << "---------------------------------------------------------" << endl;

	//�л� ���� ���
	student.Say();

	return 0;
}