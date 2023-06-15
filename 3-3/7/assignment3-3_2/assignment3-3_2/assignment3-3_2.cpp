#include <cstring>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

class Person // 사람 정보
{
protected:
    int age; // 나이 
    char name[32]; // 이름

public:
    Person() // 생성자 
    {
        age = 0; // 0으로 초기화
        strncpy(name, "", sizeof(name) - 1); // 빈 문자열로 초기화
        name[sizeof(name) - 1] = '\0'; // 널문자로 마무리
    }

    ~Person() // 소멸자
    {

    }

    virtual void Say() = 0; // 순수 가상 함수
};

class Student : public Person // 학생 정보
{
protected:
    char studentNum[11]; // 학번
    char major[32]; // 전공
    int schoolYear; // 학년

public:
    Student() : Person() // 생성자
    {
        strncpy(studentNum, "", sizeof(studentNum) - 1); // 빈 문자열로 초기화
        studentNum[sizeof(studentNum) - 1] = '\0'; // 널문자로 마무리
        strncpy(major, "", sizeof(major) - 1); // 빈 문자열로 초기화
        major[sizeof(major) - 1] = '\0'; // 널문자로 마무리
        schoolYear = 0; // 0으로 초기화
    }

    ~Student() // 소멸자
    {

    }

    int getAge() // 나이 얻어오기
    {
        return age; // 나이 반환
    }

    char* getName() // 이름 얻어오기 
    {
        return name; // 이름 반환
    }

    char* getStudentNum() // 학번 얻어오기
    {
        return studentNum; // 학번 반환
    }

    char* getMajor() // 전공 얻어오기
    {
        return major; // 전공 반환
    }

    int getSchoolYear() // 학년 얻어오기
    {
        return schoolYear; // 학년 반환
    }

    void setAge(int age) // 나이 설정
    {
        this->age = age; // 입력받은 나이로 초기화
    }

    void setName(char* name) // 이름 설정
    {
        strncpy(this->name, name, sizeof(this->name) - 1); // 이름 복사
        this->name[sizeof(this->name) - 1] = '\0'; // 널문자로 마무리
    }

    void setStudentNum(char* studentNum) // 학번 설정
    {
        strncpy(this->studentNum, studentNum, sizeof(this->studentNum) - 1); // 학번 복사
        this->studentNum[sizeof(this->studentNum) - 1] = '\0'; // 널문자로 마무리
    }

    void setMajor(char* major) // 전공 설정 
    {
        strncpy(this->major, major, sizeof(this->major) - 1); // 전공 복사
        this->major[sizeof(this->major) - 1] = '\0'; // 널문자로 마무리
    }

    void setSchoolYear(int schoolYear) // 학년 설정
    {
        this->schoolYear = schoolYear; // 학년 복사
    }

    void Say() override // 정보 출력 오버라이드 
    {
        cout << "I'm a student of KW University." << endl;
        cout << "My name is " << name << " and my studentNum is " << studentNum << "." << endl;
        cout << "I'm  " << age << " years old and I'm a " << schoolYear << " grade student." << endl;
        cout << "I'm majoring in " << major << "."<< endl;
    }
};
class Professor :public Person // 교수 정보
{
protected:
    char professorNum[11]; // 교수 번호
    char major[32]; // 전공
    
public:
    Professor() : Person() // 생성자
    {
        strncpy(professorNum, "", sizeof(professorNum) - 1); // 빈 문자열로 초기화
        professorNum[sizeof(professorNum) - 1] = '\0'; // 널문자로 마무리
        strncpy(major, "", sizeof(major) - 1); // 빈 문자열로 초기화
        major[sizeof(major) - 1] = '\0'; // 널문자로 마무리
    }

    ~Professor() // 소멸자 
    {

    }

    int getAge() // 나이 얻어오기
    {
        return age; // 나이 반환
    }

    char* getName() // 이름 얻어오기
    {
        return name; // 이름 반환
    }

    char* getprofessorNum() // 교수 학번 얻어오기
    {
        return professorNum; // 교수 학번 반환
    }

    char* getMajor() // 전공 얻어오기
    {
        return major; // 전공 반환
    }

    void setAge(int age) // 나이 설정
    {
        this->age = age; // 입력받은 나이로 초기화
    }

    void setName(char* name) // 이름 설정
    {
        strncpy(this->name, name, sizeof(this->name) - 1); // 입력받은 이름 복사
        this->name[sizeof(this->name) - 1] = '\0'; // 널문자로 마무리
    }

    void setProfessorNum(char* professorNum) // 교수 학번 설정
    {
        strncpy(this->professorNum, professorNum, sizeof(this->professorNum) - 1); // 입력받은 교수 학번 복사
        this->professorNum[sizeof(this->professorNum) - 1] = '\0'; // 널문자로 마무리
    }

    void setMajor(char* major) // 전공 설정
    {
        strncpy(this->major, major, sizeof(this->major) - 1); // 입력받은 전공 복사
        this->major[sizeof(this->major) - 1] = '\0'; // 널문자로 마무리
    }

    void Say() override // 정보 출력 오버라이드 
    {
        cout << "I'm a professor of KW University." << endl;
        cout << "My name is " << name << " and my professorNum is " << professorNum << "." << endl;
        cout << "I'm  " << age << " years old." << endl;
        cout << "I'm majoring in " << major << "." << endl;
    }
};
int main()
{
    Student student; // 학생 객체
    Professor professor; // 교수 객체

    int age; // 나이
    char name[32]; // 이름
    char studentNum[11]; // 학번
    char professorNum[11]; // 교수 학번
    char major[32]; // 전공
    int schoolYear; // 학년 
    int select; // 입력

    while (true)
    {
        cout << "student input = 1, professor input = 2 select :  "; // 학생 정보는 1 교수 정보는 2 숫자 입력을 통해 선택
        cin >> select; // 숫자 입력

        if (select == 1) // 1 이면 학생 정보 입력
        {
            cout << "Student age: "; // 학생 나이 입력
            cin >> age; // 나이 입력
            student.setAge(age); // 나이 설정

            cout << "Student name: "; // 학생 이름 입력
            cin.ignore();  // 이전 개행 무시
            cin.getline(name, sizeof(name)); // name의 크기만큼 입력
            student.setName(name); // 이름 설정

            cout << "Student number: "; // 학번 입력
            cin >> studentNum; // 학번 입력
            student.setStudentNum(studentNum); // 학번 설정

            cout << "Student major: "; // 전공 입력
            cin.ignore();  // 이전 개행 무시
            cin.getline(major, sizeof(major)); // major의 크기만큼 입력
            student.setMajor(major); // 전공 설정

            cout << "Student school year: "; // 학년 입력
            cin >> schoolYear; // 학년 입력
            student.setSchoolYear(schoolYear); // 학년 설정

            student.Say(); // 학생 정보 출력
            break; // 반복문 탈출
        }
        else if (select == 2) // 2번이면 교수 정보 입력
        {
            cout << "Professor age: "; // 교수 나이 입력
            cin >> age; // 교수 나이 입력
            professor.setAge(age); // 교수 나이 설정

            cout << "Professor name: "; // 교수 이름 설정
            cin.ignore();  // 이전 개행 무시
            cin.getline(name, sizeof(name)); // name의 크기만큼 입력
            professor.setName(name); // 이름 설정

            cout << "Professor number: "; // 교수 학번 입력
            cin >> professorNum; // 교수 학번 입력
            professor.setProfessorNum(professorNum); // 교수 학번 설정

            cout << "Professor major: "; // 교수 전공 입력
            cin.ignore();  // 이전 개행 무시 
            cin.getline(major, sizeof(major)); // major의 크기만큼 입력
            professor.setMajor(major); // 전공 설정

            professor.Say(); // 교수 정보 출력
            break; // 반복문 탈출
        }
        else // 1이나 2가 아닌경우
            cout << "Error" << endl; // 에러 출력       
    }
    return 0;
}
