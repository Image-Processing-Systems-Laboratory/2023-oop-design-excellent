#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Person // 사람 클래스
{
protected: //멤버 변수를 protected로 선언
	int age; // 나이
	char name[32]; // 이름
public: // 멤버 함수
	Person(); // 디폴트 생성자
	~Person(); // 소멸자
	virtual void Say() = 0; // 가상 함수
};

Person::Person() // 기본 생성자
{
	age = 0; // 나이를 0으로 초기화
	strcpy(name, ""); // 이름을 공백으로 초기화
}

Person::~Person() // 소멸자
{
}

class Student : public Person // 학생 클래스를 person 클래스를 상속받아 정의
{
protected: // 멤버 변수를 protected로 선언
	char studentNum[11]; // 학번
	char major[32]; // 전공
	int schoolYear; // 학년
public: // 멤버 함수
	Student(); //  생성자
	~Student(); // 소멸자
	int GetAge(); // 나이를 반환하는 함수
	char* GetName(); // 이름을 반환하는 함수
	char* GetStudentNum(); // 학번을 반환하는 함수
	char* GetMajor(); // 전공을 반환하는 함수
	int GetSchoolYear(); // 학년을 반환하는 함수
	void SetAge(int age); // 나이를 설정하는 함수
	void SetName(char* name); // 이름을 설정하는 함수
	void SetStudentNum(char* studentNum); // 학번을 설정하는 함수
	void SetMajor(char* major); // 전공을 설정하는 함수
	void SetSchoolYear(int schoolYear); // 학년을 설정하는 함수
	void Say(); // 가상 함수
};

Student::Student() // 생성자
{
	strcpy(studentNum, ""); // 학번을 공백으로 초기화
	strcpy(major, ""); // 전공을 공백으로 초기화
	schoolYear = 0; // 학년을 0으로 초기화 
}

Student::~Student() // 소멸자
{
}

int Student::GetAge() // 나이를 반환하는 함수
{
	return age; // 나이를 반환
}

char* Student::GetName() // 이름을 반환하는 함수
{
	return name; // 이름을 반환
}

char* Student::GetStudentNum() // 학번을 반환하는 함수
{
	return studentNum; // 학번을 반환
}

char* Student::GetMajor() // 전공을 반환하는 함수
{
	return major; // 전공을 반환
}

int Student::GetSchoolYear() // 학년을 반환하는 함수
{
	return schoolYear; // 학년을 반환
}

void Student::SetAge(int age) // 나이를 설정하는 함수
{
	this->age = age; // 나이를 설정
}

void Student::SetName(char* name) // 이름을 설정하는 함수
{
	strcpy(this->name, name); // 이름을 설정
}

void Student::SetStudentNum(char* studentNum) // 학번을 설정하는 함수
{
	strcpy(this->studentNum, studentNum); // 학번을 설정
}

void Student::SetMajor(char* major) // 전공을 설정하는 함수
{
	strcpy(this->major, major); // 전공을 설정
}

void Student::SetSchoolYear(int schoolYear) // 학년을 설정하는 함수
{
	this->schoolYear = schoolYear; // 학년을 설정
}

void Student::Say() // 가상 함수
{
	// 학생의 정보를 출력
	cout << "I`m a student of KW University." << endl; 
	cout << "My student number is " << studentNum << " and my name is " << name << "." << endl;
	cout << "I`m " << age << " years old." << endl;
	cout << "My major is " << major << "." << endl;
	cout << "I`m " << schoolYear << "th grade." << endl;
}

class Professor : public Person // 교수 클래스를 person 클래스를 상속받아 정의
{
protected: // 멤버 변수를 protected로 선언
	char professorNum[11]; // 교수 번호
	char major[32]; // 전공
public: // 멤버 함수
	Professor(); // 생성자
	~Professor(); // 소멸자
	int GetAge(); // 나이를 반환하는 함수
	char* GetName(); // 이름을 반환하는 함수
	char* GetProfessorNum(); // 교수 번호를 반환하는 함수
	char* GetMajor(); // 전공을 반환하는 함수
	void SetAge(int age); // 나이를 설정하는 함수
	void SetName(char* name); // 이름을 설정하는 함수
	void SetProfessorNum(char* professorNum); // 교수 번호를 설정하는 함수
	void SetMajor(char* major); // 전공을 설정하는 함수
	void Say(); // 가상 함수
};

Professor::Professor() // 생성자
{
	strcpy(professorNum, ""); // 교수 번호를 공백으로 초기화
	strcpy(major, ""); // 전공을 공백으로 초기화
}

Professor::~Professor() // 소멸자
{
}

int Professor::GetAge() // 나이를 반환하는 함수
{
	return age; // 나이를 반환
}

char* Professor::GetName() // 이름을 반환하는 함수
{
	return name; // 이름을 반환
}

char* Professor::GetProfessorNum() // 교수 번호를 반환하는 함수
{
	return professorNum; // 교수 번호를 반환
}

char* Professor::GetMajor() // 전공을 반환하는 함수
{
	return major; // 전공을 반환
}

void Professor::SetAge(int age) // 나이를 설정하는 함수
{
	this->age = age; // 나이를 설정
}

void Professor::SetName(char* name) // 이름을 설정하는 함수
{
	strcpy(this->name, name); // 이름을 설정
}

void Professor::SetProfessorNum(char* professorNum) // 교수 번호를 설정하는 함수
{
	strcpy(this->professorNum, professorNum); // 교수 번호를 설정
}

void Professor::SetMajor(char* major) // 전공을 설정하는 함수
{
	strcpy(this->major, major); // 전공을 설정
}

void Professor::Say() // 가상 함수
{
	// 교수의 정보를 출력
	cout << "I`m a professor of KW University." << endl;
	cout << "My professor number is " << professorNum << " and my name is " << name << "." << endl;
	cout << "I`m " << age << " years old." << endl;
	cout << "My major is " << major << "." << endl;
}

int main()
{
	char studentNum[11]; // 학생 번호
	char name1[32]; // 학생 이름
	int age1; // 학생 나이
	char major1[32]; // 학생 전공
	int schoolYear; // 학생 학년
	char professorNum[11]; // 교수 번호
	char name2[32]; // 교수 이름
	int age2; // 교수 나이
	char major2[32]; // 교수 전공
	
	cout << "학생 정보 입력" << endl; // 학생 정보 입력 안내문 출력
	cout << "학번: "; // 학번 입력 안내문 출력 
	cin.getline(studentNum, 11); // 학번 입력
	cout << "이름: "; // 이름 입력 안내문 출력
	cin.getline(name1, 32); // 이름 입력
	cout << "나이: "; // 나이 입력 안내문 출력
	cin >> age1; // 나이 입력
	cout << "전공: "; // 전공 입력 안내문 출력
	cin.ignore(); // 버퍼 비우기
	cin.getline(major1, 32); // 전공 입력
	cout << "학년: "; // 학년 입력 안내문 출력
	cin >> schoolYear; // 학년 입력
	cout << endl; // 줄 바꿈
	
	
	
	cout << "교수 정보 입력" << endl; // 교수 정보 입력 안내문 출력
	cout << "교번: "; // 교번 입력 안내문 출력
	cin.ignore(); // 버퍼 비우기
	cin.getline(professorNum, 11); // 교번 입력
	cout << "이름: "; // 이름 입력 안내문 출력
	cin.getline(name2, 32); // 이름 입력
	cout << "나이: "; // 나이 입력 안내문 출력
	cin >> age2; // 나이 입력
	cout << "전공: "; // 전공 입력 안내문 출력
	cin.ignore(); // 버퍼 비우기
	cin.getline(major2, 32); // 전공 입력
	cout << endl;
	
	Student student; // Student 클래스 객체 생성
	student.SetStudentNum(studentNum); // 학생 번호 설정
	student.SetName(name1); // 이름 설정
	student.SetAge(age1); // 나이 설정
	student.SetMajor(major1); // 전공 설정
	student.SetSchoolYear(schoolYear); // 학년 설정
	student.Say(); // 학생 정보 출력
	cout << endl;
	
	Professor professor; // Professor 클래스 객체 생성
	professor.SetProfessorNum(professorNum); // 교수 번호 설정
	professor.SetName(name2); // 이름 설정
	professor.SetAge(age2); // 나이 설정
	professor.SetMajor(major2); // 전공 설정
	professor.Say(); // 교수 정보 출력
	
	return 0; // 프로그램 종료
}

