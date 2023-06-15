#include "class.h"
#include <iostream>

using namespace std;

int main(void)
{
	Professor professor;
	Student student;

	char str[32];    //입력 받은 문자열을 임시 저장할 배열
	int num;         //입력 받은 정수를 임시 저장할 변수

	//교수님 정보 입력
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

	//학생 정보 입력
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

	//교수님 정보 출력
	professor.Say();
	cout << "---------------------------------------------------------" << endl;

	//학생 정보 출력
	student.Say();

	return 0;
}