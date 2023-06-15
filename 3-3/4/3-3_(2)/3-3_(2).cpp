#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

class Person {
protected:
    int age;
    char name[32];

public:
    Person();
    ~Person();
    virtual void Say() = 0;
};

// Person class 생성자, 변수 초기화
Person::Person() : age(0) { strcpy(name, ""); }
// Person class 소멸자
Person::~Person() {}

// Student class는 Person class를 상속 받음
class Student : public Person {
protected:
    char studentNum[11];
    char major[32];
    int schoolYear;

public:
    Student();
    ~Student();
    int getAge();
    char* getName();
    char* getStudentNum();
    char* getMajor();
    int getSchoolYear();
    void setAge(int age);
    void setName(const char* name);
    void setStudentNum(const char* studentNum);
    void setMajor(const char* major);
    void setSchoolYear(int year);
    void Say() override;
};

// Student class 생성자, 변수 초기화
Student::Student() : Person(), schoolYear(0) {
    strcpy(studentNum, "");
    strcpy(major, "");
}
// Student class 소멸자
Student::~Student() {}

// getAge() 함수 age를 return
int Student::getAge() { return age; }
// getName() 함수 name을 return 
char* Student::getName() { return name; }
// getStudentNum() 함수 studentNum을 return
char* Student::getStudentNum() { return studentNum; }
// getMajor() 함수 major을 return
char* Student::getMajor() { return major; }
// getSchoolYear() 함수 schoolYear을 return 
int Student::getSchoolYear() { return schoolYear; }
// setAge() 함수 객체 age에 age 값을 저장
void Student::setAge(int age) { this->age = age; }
// setName() 함수 strncpy를 통해 객체 name에 name을 저장
void Student::setName(const char* name) {
    strncpy(this->name, name, sizeof(this->name));
    this->name[sizeof(this->name) - 1] = '\0';
}
//setStudentNum() 함수 strncpy를 통해 객체 studentNum에 studentNum 값을 저장
void Student::setStudentNum(const char* studentNum) {
    strncpy(this->studentNum, studentNum, sizeof(this->studentNum));
    this->studentNum[sizeof(this->studentNum) - 1] = '\0';
}
// setMajor() 함수 strncpy 함수를 통해 객체 major에 major를 저장
void Student::setMajor(const char* major) {
    strncpy(this->major, major, sizeof(this->major));
    this->major[sizeof(this->major) - 1] = '\0';
}
// setSchoolYear() 함수 객체 schoolYear에 year 값을 저장
void Student::setSchoolYear(int year) { this->schoolYear = year; }

// Say() 함수
void Student::Say() {
    int schoolYear = getSchoolYear();
    cout << "I'm a student of KW University." << endl;
    // getName() 을 통해 이름 가져오기
    cout << "My name is " << getName() << endl;
    // getAge()를 통해 age 가져오고
    if (schoolYear == 1)
        // 1학년이면 freshman 출력
        cout << "I'm " << getAge() << " years old and I'm a freshman" << endl;
    else if (schoolYear == 2) {
        // 2학년이면 sophomore 출력
        cout << "I'm " << getAge() << " years old and I'm a sophomore" << endl;
    }
    else if (schoolYear == 3) {
        // 3학년이면 junior 출력
        cout << "I'm " << getAge() << " years old and I'm a junior" << endl;
    }
    else if (schoolYear == 4) {
        // 4학년이면 senior 출력
        cout << "I'm " << getAge() << " years old and I'm a senior" << endl;
    }
    else {
        cout << "I'm " << getAge()
            << " years old and I'm a graduate student" << endl;
    }
    // getMajor() 함수를 통해 major 받아오기
    cout << "I'm majoring in " << getMajor() << endl;
}

// Professor class는 Person class를 상속 받음
class Professor : public Person {
protected:
    char professorNum[11];
    char major[32];

public:
    Professor();
    virtual ~Professor();

    int getAge();
    char* getName();
    char* getProfessorNum();
    char* getMajor();

    void setProfessorNum(const char* professorNum);
    void setMajor(const char* major);
    void setAge(int age);
    void setName(const char* name);

    virtual void Say();
};
// Professor class 생성자, 변수 초기화
Professor::Professor() : Person() {
    strcpy(professorNum, "");
    strcpy(major, "");
}
// Professor class 소멸자
Professor::~Professor() {}

// getAge() 함수 age를 return
int Professor::getAge() { return age; }
// getName() 함수 name을 return 
char* Professor::getName() { return name; }
// getProfessorNum() 함수 professorNum을 return
char* Professor::getProfessorNum() { return professorNum; }
// getMajor() 함수 major을 return
char* Professor::getMajor() { return major; }
//setStudentNum() 함수 strncpy를 통해 객체 professorNum에 professorNum 값을 저장
void Professor::setProfessorNum(const char* professorNum) {
    strncpy(this->professorNum, professorNum, sizeof(this->professorNum));
    this->professorNum[sizeof(this->professorNum) - 1] = '\0';
}
// setMajor() 함수 strncpy 함수를 통해 객체 major에 major를 저장
void Professor::setMajor(const char* major) {
    strncpy(this->major, major, sizeof(this->major));
    this->major[sizeof(this->major) - 1] = '\0';
}
// setAge() 함수 객체 age에 age 값을 저장
void Professor::setAge(int age) { this->age = age; }
// setName() 함수 strncpy를 통해 객체 name에 name을 저장
void Professor::setName(const char* name) {
    strncpy(this->name, name, sizeof(this->name));
    this->name[sizeof(this->name) - 1] = '\0';
}
// Say() 함수
void Professor::Say() {
    cout << "I'm a professor at KW University." << endl;
    cout << "My name is " << getName() << "." << endl;
    cout << "I'm " << getAge() << " years old." << endl;
    cout << "I'm a professor in " << getMajor() << "." << endl;
}

int main() {
    Student student;
    student.setName("Hong Gill Dong");
    student.setAge(21);
    student.setStudentNum("123456789");
    student.setMajor("Computer Engineering");
    student.setSchoolYear(2);

    Professor professor;
    professor.setName("Choi Choi Choi");
    professor.setAge(52);
    professor.setProfessorNum("8987123");
    professor.setMajor("Computer Engineering");

    // Person의 Say()를 불러오기 위해 선언
    Person* pPerson{};
    string job;
    cin >> job;
    if (job == "student") {
        pPerson = &student;
    }
    else if (job == "professor") {
        pPerson = &professor;
    }

    pPerson->Say();

    return 0;
}
