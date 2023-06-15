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

// Person class ������, ���� �ʱ�ȭ
Person::Person() : age(0) { strcpy(name, ""); }
// Person class �Ҹ���
Person::~Person() {}

// Student class�� Person class�� ��� ����
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

// Student class ������, ���� �ʱ�ȭ
Student::Student() : Person(), schoolYear(0) {
    strcpy(studentNum, "");
    strcpy(major, "");
}
// Student class �Ҹ���
Student::~Student() {}

// getAge() �Լ� age�� return
int Student::getAge() { return age; }
// getName() �Լ� name�� return 
char* Student::getName() { return name; }
// getStudentNum() �Լ� studentNum�� return
char* Student::getStudentNum() { return studentNum; }
// getMajor() �Լ� major�� return
char* Student::getMajor() { return major; }
// getSchoolYear() �Լ� schoolYear�� return 
int Student::getSchoolYear() { return schoolYear; }
// setAge() �Լ� ��ü age�� age ���� ����
void Student::setAge(int age) { this->age = age; }
// setName() �Լ� strncpy�� ���� ��ü name�� name�� ����
void Student::setName(const char* name) {
    strncpy(this->name, name, sizeof(this->name));
    this->name[sizeof(this->name) - 1] = '\0';
}
//setStudentNum() �Լ� strncpy�� ���� ��ü studentNum�� studentNum ���� ����
void Student::setStudentNum(const char* studentNum) {
    strncpy(this->studentNum, studentNum, sizeof(this->studentNum));
    this->studentNum[sizeof(this->studentNum) - 1] = '\0';
}
// setMajor() �Լ� strncpy �Լ��� ���� ��ü major�� major�� ����
void Student::setMajor(const char* major) {
    strncpy(this->major, major, sizeof(this->major));
    this->major[sizeof(this->major) - 1] = '\0';
}
// setSchoolYear() �Լ� ��ü schoolYear�� year ���� ����
void Student::setSchoolYear(int year) { this->schoolYear = year; }

// Say() �Լ�
void Student::Say() {
    int schoolYear = getSchoolYear();
    cout << "I'm a student of KW University." << endl;
    // getName() �� ���� �̸� ��������
    cout << "My name is " << getName() << endl;
    // getAge()�� ���� age ��������
    if (schoolYear == 1)
        // 1�г��̸� freshman ���
        cout << "I'm " << getAge() << " years old and I'm a freshman" << endl;
    else if (schoolYear == 2) {
        // 2�г��̸� sophomore ���
        cout << "I'm " << getAge() << " years old and I'm a sophomore" << endl;
    }
    else if (schoolYear == 3) {
        // 3�г��̸� junior ���
        cout << "I'm " << getAge() << " years old and I'm a junior" << endl;
    }
    else if (schoolYear == 4) {
        // 4�г��̸� senior ���
        cout << "I'm " << getAge() << " years old and I'm a senior" << endl;
    }
    else {
        cout << "I'm " << getAge()
            << " years old and I'm a graduate student" << endl;
    }
    // getMajor() �Լ��� ���� major �޾ƿ���
    cout << "I'm majoring in " << getMajor() << endl;
}

// Professor class�� Person class�� ��� ����
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
// Professor class ������, ���� �ʱ�ȭ
Professor::Professor() : Person() {
    strcpy(professorNum, "");
    strcpy(major, "");
}
// Professor class �Ҹ���
Professor::~Professor() {}

// getAge() �Լ� age�� return
int Professor::getAge() { return age; }
// getName() �Լ� name�� return 
char* Professor::getName() { return name; }
// getProfessorNum() �Լ� professorNum�� return
char* Professor::getProfessorNum() { return professorNum; }
// getMajor() �Լ� major�� return
char* Professor::getMajor() { return major; }
//setStudentNum() �Լ� strncpy�� ���� ��ü professorNum�� professorNum ���� ����
void Professor::setProfessorNum(const char* professorNum) {
    strncpy(this->professorNum, professorNum, sizeof(this->professorNum));
    this->professorNum[sizeof(this->professorNum) - 1] = '\0';
}
// setMajor() �Լ� strncpy �Լ��� ���� ��ü major�� major�� ����
void Professor::setMajor(const char* major) {
    strncpy(this->major, major, sizeof(this->major));
    this->major[sizeof(this->major) - 1] = '\0';
}
// setAge() �Լ� ��ü age�� age ���� ����
void Professor::setAge(int age) { this->age = age; }
// setName() �Լ� strncpy�� ���� ��ü name�� name�� ����
void Professor::setName(const char* name) {
    strncpy(this->name, name, sizeof(this->name));
    this->name[sizeof(this->name) - 1] = '\0';
}
// Say() �Լ�
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

    // Person�� Say()�� �ҷ����� ���� ����
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
