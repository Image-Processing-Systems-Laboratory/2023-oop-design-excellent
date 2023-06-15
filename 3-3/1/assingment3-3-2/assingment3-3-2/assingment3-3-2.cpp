#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Person // 사람 클래스
{
protected: // 상속받은 클래스에서 접근 가능
    int age; // 나이
    char name[32]; // 이름

public: // 외부에서 접근 가능
    Person(int age = 0, const char* name = "") : age(age) { // 생성자
        strncpy(this->name, name, sizeof(this->name)); // name을 this->name에 복사
        this->name[sizeof(this->name) - 1] = '\0'; // this->name의 마지막에 널 문자 삽입
    }
    virtual ~Person() {} // 가상 소멸자
    virtual void Say() = 0; // 순수 가상 함수
};

class Professor : public Person // 교수 클래스
{
private: // 외부에서 접근 불가
    int professorNumber; // 교수 번호
    string major; // 전공

public: // 외부에서 접근 가능
    Professor(int age = 0, const char* name = "", int professorNumber = 0, string major = "") // 생성자
        : Person(age, name), professorNumber(professorNumber), major(major) {} // 부모 클래스의 생성자 호출

    ~Professor() {} // 소멸자

    void Say() override { // 부모 클래스의 순수 가상 함수를 오버라이딩
        cout << "Professor Details: " << "\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Professor Number: " << professorNumber << "\n";
        cout << "Major: " << major << "\n";
    }
};

class Student : public Person // 학생 클래스
{
private:
    int studentNumber; // 학생 번호
    string major; // 전공
    int schoolYear; // 학년

public:
    Student(int age = 0, const char* name = "", int studentNumber = 0, string major = "", int schoolYear = 0) // 생성자
        : Person(age, name), studentNumber(studentNumber), major(major), schoolYear(schoolYear) {} // 부모 클래스의 생성자 호출

    ~Student() {}

    void Say() override { // 부모 클래스의 순수 가상 함수를 오버라이딩
        cout << "Student Details: " << "\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Student Number: " << studentNumber << "\n";
        cout << "Major: " << major << "\n";
        cout << "School Year: " << schoolYear << "\n";
    }
};

int main() {
    int age;
    char name[32];
    int professorNumber;
    string major;
    int studentNumber;
    int schoolYear;

    cout << "Enter professor's details:\n";

    cout << "Name: ";
    cin.getline(name, 32);
    cout << "Age: ";
    cin >> age;
    cout << "Professor Number: ";
    cin >> professorNumber;
    cin.ignore(); // 입력 버퍼에서 개행 문자를 무시하려면
    cout << "Major: ";
    getline(cin, major);

    Professor prof(age, name, professorNumber, major);

    cout << "\nEnter student's details:\n";

    cout << "Name: ";
    cin.getline(name, 32);
    cout << "Age: ";
    cin >> age;
    cout << "Student Number: ";
    cin >> studentNumber;
    cin.ignore(); // 입력 버퍼에서 개행 문자를 무시하려면
    cout << "Major: ";
    cout << "Major: ";
    getline(cin, major);
    cout << "School Year: ";
    cin >> schoolYear;

    Student stud(age, name, studentNumber, major, schoolYear);

    prof.Say();
    cout << "\n";
    stud.Say();

    return 0;
}
