#include <cstring>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)

class Person // ��� ����
{
protected:
    int age; // ���� 
    char name[32]; // �̸�

public:
    Person() // ������ 
    {
        age = 0; // 0���� �ʱ�ȭ
        strncpy(name, "", sizeof(name) - 1); // �� ���ڿ��� �ʱ�ȭ
        name[sizeof(name) - 1] = '\0'; // �ι��ڷ� ������
    }

    ~Person() // �Ҹ���
    {

    }

    virtual void Say() = 0; // ���� ���� �Լ�
};

class Student : public Person // �л� ����
{
protected:
    char studentNum[11]; // �й�
    char major[32]; // ����
    int schoolYear; // �г�

public:
    Student() : Person() // ������
    {
        strncpy(studentNum, "", sizeof(studentNum) - 1); // �� ���ڿ��� �ʱ�ȭ
        studentNum[sizeof(studentNum) - 1] = '\0'; // �ι��ڷ� ������
        strncpy(major, "", sizeof(major) - 1); // �� ���ڿ��� �ʱ�ȭ
        major[sizeof(major) - 1] = '\0'; // �ι��ڷ� ������
        schoolYear = 0; // 0���� �ʱ�ȭ
    }

    ~Student() // �Ҹ���
    {

    }

    int getAge() // ���� ������
    {
        return age; // ���� ��ȯ
    }

    char* getName() // �̸� ������ 
    {
        return name; // �̸� ��ȯ
    }

    char* getStudentNum() // �й� ������
    {
        return studentNum; // �й� ��ȯ
    }

    char* getMajor() // ���� ������
    {
        return major; // ���� ��ȯ
    }

    int getSchoolYear() // �г� ������
    {
        return schoolYear; // �г� ��ȯ
    }

    void setAge(int age) // ���� ����
    {
        this->age = age; // �Է¹��� ���̷� �ʱ�ȭ
    }

    void setName(char* name) // �̸� ����
    {
        strncpy(this->name, name, sizeof(this->name) - 1); // �̸� ����
        this->name[sizeof(this->name) - 1] = '\0'; // �ι��ڷ� ������
    }

    void setStudentNum(char* studentNum) // �й� ����
    {
        strncpy(this->studentNum, studentNum, sizeof(this->studentNum) - 1); // �й� ����
        this->studentNum[sizeof(this->studentNum) - 1] = '\0'; // �ι��ڷ� ������
    }

    void setMajor(char* major) // ���� ���� 
    {
        strncpy(this->major, major, sizeof(this->major) - 1); // ���� ����
        this->major[sizeof(this->major) - 1] = '\0'; // �ι��ڷ� ������
    }

    void setSchoolYear(int schoolYear) // �г� ����
    {
        this->schoolYear = schoolYear; // �г� ����
    }

    void Say() override // ���� ��� �������̵� 
    {
        cout << "I'm a student of KW University." << endl;
        cout << "My name is " << name << " and my studentNum is " << studentNum << "." << endl;
        cout << "I'm  " << age << " years old and I'm a " << schoolYear << " grade student." << endl;
        cout << "I'm majoring in " << major << "."<< endl;
    }
};
class Professor :public Person // ���� ����
{
protected:
    char professorNum[11]; // ���� ��ȣ
    char major[32]; // ����
    
public:
    Professor() : Person() // ������
    {
        strncpy(professorNum, "", sizeof(professorNum) - 1); // �� ���ڿ��� �ʱ�ȭ
        professorNum[sizeof(professorNum) - 1] = '\0'; // �ι��ڷ� ������
        strncpy(major, "", sizeof(major) - 1); // �� ���ڿ��� �ʱ�ȭ
        major[sizeof(major) - 1] = '\0'; // �ι��ڷ� ������
    }

    ~Professor() // �Ҹ��� 
    {

    }

    int getAge() // ���� ������
    {
        return age; // ���� ��ȯ
    }

    char* getName() // �̸� ������
    {
        return name; // �̸� ��ȯ
    }

    char* getprofessorNum() // ���� �й� ������
    {
        return professorNum; // ���� �й� ��ȯ
    }

    char* getMajor() // ���� ������
    {
        return major; // ���� ��ȯ
    }

    void setAge(int age) // ���� ����
    {
        this->age = age; // �Է¹��� ���̷� �ʱ�ȭ
    }

    void setName(char* name) // �̸� ����
    {
        strncpy(this->name, name, sizeof(this->name) - 1); // �Է¹��� �̸� ����
        this->name[sizeof(this->name) - 1] = '\0'; // �ι��ڷ� ������
    }

    void setProfessorNum(char* professorNum) // ���� �й� ����
    {
        strncpy(this->professorNum, professorNum, sizeof(this->professorNum) - 1); // �Է¹��� ���� �й� ����
        this->professorNum[sizeof(this->professorNum) - 1] = '\0'; // �ι��ڷ� ������
    }

    void setMajor(char* major) // ���� ����
    {
        strncpy(this->major, major, sizeof(this->major) - 1); // �Է¹��� ���� ����
        this->major[sizeof(this->major) - 1] = '\0'; // �ι��ڷ� ������
    }

    void Say() override // ���� ��� �������̵� 
    {
        cout << "I'm a professor of KW University." << endl;
        cout << "My name is " << name << " and my professorNum is " << professorNum << "." << endl;
        cout << "I'm  " << age << " years old." << endl;
        cout << "I'm majoring in " << major << "." << endl;
    }
};
int main()
{
    Student student; // �л� ��ü
    Professor professor; // ���� ��ü

    int age; // ����
    char name[32]; // �̸�
    char studentNum[11]; // �й�
    char professorNum[11]; // ���� �й�
    char major[32]; // ����
    int schoolYear; // �г� 
    int select; // �Է�

    while (true)
    {
        cout << "student input = 1, professor input = 2 select :  "; // �л� ������ 1 ���� ������ 2 ���� �Է��� ���� ����
        cin >> select; // ���� �Է�

        if (select == 1) // 1 �̸� �л� ���� �Է�
        {
            cout << "Student age: "; // �л� ���� �Է�
            cin >> age; // ���� �Է�
            student.setAge(age); // ���� ����

            cout << "Student name: "; // �л� �̸� �Է�
            cin.ignore();  // ���� ���� ����
            cin.getline(name, sizeof(name)); // name�� ũ�⸸ŭ �Է�
            student.setName(name); // �̸� ����

            cout << "Student number: "; // �й� �Է�
            cin >> studentNum; // �й� �Է�
            student.setStudentNum(studentNum); // �й� ����

            cout << "Student major: "; // ���� �Է�
            cin.ignore();  // ���� ���� ����
            cin.getline(major, sizeof(major)); // major�� ũ�⸸ŭ �Է�
            student.setMajor(major); // ���� ����

            cout << "Student school year: "; // �г� �Է�
            cin >> schoolYear; // �г� �Է�
            student.setSchoolYear(schoolYear); // �г� ����

            student.Say(); // �л� ���� ���
            break; // �ݺ��� Ż��
        }
        else if (select == 2) // 2���̸� ���� ���� �Է�
        {
            cout << "Professor age: "; // ���� ���� �Է�
            cin >> age; // ���� ���� �Է�
            professor.setAge(age); // ���� ���� ����

            cout << "Professor name: "; // ���� �̸� ����
            cin.ignore();  // ���� ���� ����
            cin.getline(name, sizeof(name)); // name�� ũ�⸸ŭ �Է�
            professor.setName(name); // �̸� ����

            cout << "Professor number: "; // ���� �й� �Է�
            cin >> professorNum; // ���� �й� �Է�
            professor.setProfessorNum(professorNum); // ���� �й� ����

            cout << "Professor major: "; // ���� ���� �Է�
            cin.ignore();  // ���� ���� ���� 
            cin.getline(major, sizeof(major)); // major�� ũ�⸸ŭ �Է�
            professor.setMajor(major); // ���� ����

            professor.Say(); // ���� ���� ���
            break; // �ݺ��� Ż��
        }
        else // 1�̳� 2�� �ƴѰ��
            cout << "Error" << endl; // ���� ���       
    }
    return 0;
}
