#include "OverridePerson.h"

using namespace std;

int isStudent(); // 학생인 경우
int isProfessor(); // 교수인 경우

int main()
{
	string whatareyou;
	cout << "Are you Student, or Are you Professor?\n>>> ";
	cin >> whatareyou;

	if (whatareyou == "Student")
	{
		isStudent();
		return 1;
	}
	if (whatareyou == "Professor")
	{
		isProfessor();
		return 1;
	}
	else
	{
		cerr << "Error: input string is invalid!" << endl;
		return -1;
	}

	return 1;
}

int isStudent()
{
	int age = 0;
	string name; // 이름
	string studentnum; // 학번
	string major; // 전공
	int schoolyear = 0; // 학년 

	cout << "Please input your age!\n>>> ";
	cin >> age;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (cin.fail() || age < 1)
	{
		cerr << "Error: you inputed non-integer something or inputed under 1!" << endl;
		return -1;
	}
	// age에 int형 값이 아니거나 0살 이전의 값이 들어온 경우를 catch

	cout << "Please input your name!\n>>> ";
	getline(cin, name);

	if (name.length() > string_maxsize)
	{
		cerr << "Error: name out of range!" << endl;
		return -1;
	}
	// name이 32자보다 긴 경우를 catch

	cout << "Please input your Student Number(학번)!\n>>> ";
	cin >> studentnum;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (studentnum.length() > num_maxsize)
	{
		cerr << "Error: Student Number out of range!" << endl;
		return -1;
	}
	// 학번이 11자보다 긴 경우를 catch

	cout << "Please input your major!\n>>> ";
	getline(cin, major);

	if (major.length() > string_maxsize)
	{
		cerr << "Error: major out of range!" << endl;
		return -1;
	}
	// major가 32자보다 긴 경우를 catch

	cout << "Please input your schoolyear(학년)!\n>>> ";
	cin >> schoolyear;
	if (cin.fail() || schoolyear < 1)
	{
		cerr << "Error: you inputed non-integer something or inputed under 1!" << endl;
		return -1;
	}
	if (schoolyear > 5)
	{
		cerr << "Error: you inputed over 4!" << endl;
		return -1;
	}
	// 학년이 int형이 아니거나, 1보다 작거나 4보다 큰 경우를 catch

	Student* Student_info = new Student();

	Student_info->setAge(age);
	Student_info->setName(name.c_str());
	Student_info->setStudentNum(studentnum.c_str());
	Student_info->setMajor(major.c_str());
	Student_info->setSchoolYear(schoolyear);

	cout << "\nI'm student of KwangWoon University." << endl;
	Student_info->Say();
	delete Student_info;
	return 1;
	// 모든 입력이 올바른 경우 객체를 동적 생성 후 입력한 값을 Set, 그 후 delete하여 프로그램 종료
}

// Professor의 경우도 일맥상통 합니다.
int isProfessor()
{
	int age = 0;
	string name;
	string professornum;
	string major;

	cout << "Please input your age!\n>>> ";
	cin >> age;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (cin.fail() || age < 1)
	{
		cerr << "Error: you inputed non-integer something or inputed under 1!" << endl;
		return -1;
	}
	// age에 int형 값이 아니거나 0살 이전의 값이 들어온 경우를 catch

	cout << "Please input your name!\n>>> ";
	getline(cin, name);

	if (name.length() > string_maxsize)
	{
		cerr << "Error: name out of range!" << endl;
		return -1;
	}

	cout << "Please input your Professor Number!\n>>> ";
	cin >> professornum;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (professornum.length() > num_maxsize)
	{
		cerr << "Error: Student Number out of range!" << endl;
		return -1;
	}

	cout << "Please input your major!\n>>> ";
	getline(cin, major);

	if (major.length() > string_maxsize)
	{
		cerr << "Error: major out of range!" << endl;
		return -1;
	}

	Professor* Professor_info = new Professor();

	Professor_info->setAge(age);
	Professor_info->setName(name.c_str());
	Professor_info->setprofessornum(professornum.c_str());
	Professor_info->setMajor(major.c_str());

	cout << "\nI'm Professor of KwangWoon University." << endl;
	Professor_info->Say();
	delete Professor_info;
	return 1;
}