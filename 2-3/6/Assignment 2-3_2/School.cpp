#include "School.h"
#include <iostream>
#include <cstring>

using namespace std;

// destructor
School::~School()
{
    // student_list에 저장된 모든 학생들의 name, class_name을 delete
    for (int i = 0; i < size; i++)
    {
        delete[] student_list[i]->name;
        delete[] student_list[i]->class_name;
        delete student_list[i];
    }
}

// 학생을 추가하는 함수
void School::new_student(const char* name, int age, const char* class_name)
{
    // 학생 수가 100명을 넘으면 "School is full." 출력 후 함수 종료
    if (size >= 101)
    {
        cout << "Full" << endl;
        return;
    }

    Student* new_student = new Student;     // 새로운 학생 생성
    new_student->name = new char[strlen(name) + 1];     // name을 저장할 char 배열 동적 할당
    strcpy_s(new_student->name, strlen(name) + 1, name);        // name을 new_student->name에 복사
    new_student->age = age;     // age 저장
    new_student->class_name = new char[strlen(class_name) + 1];     // class_name을 저장할 char 배열 동적 할당
    strcpy_s(new_student->class_name, strlen(class_name) + 1, class_name);      // class_name을 new_student->class_name에 복사

    student_list[size++] = new_student;     // student_list에 새로운 학생 추가
}

// 학생들을 이름순으로 정렬하는 함수
void School::sort_by_name()
{
    // bubble sort
    for (int i = 0; i < size; i++)
    {
        // student_list[0]부터 student_list[size - 1]까지 반복
        for (int j = 0; j < size - 1; j++)
        {
            // student_list[j]의 이름이 student_list[j + 1]의 이름보다 크면 두 학생의 정보를 swap
            if (strcmp(student_list[j]->name, student_list[j + 1]->name) > 0)
            {
                swap(student_list[j], student_list[j + 1]);
            }
        }
    }
}

// 학생들의 정보를 모두 출력하는 함수
void School::print_all() const
{
    cout << "=====print_all=====" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Name: " << student_list[i]->name << endl;
        cout << "Age: " << student_list[i]->age << endl;
        cout << "Class: " << student_list[i]->class_name << endl;
        cout << "----------" << endl;
    }
}

// 특정 반의 학생들의 정보를 출력하는 함수
void School::print_class(const char* class_name) const
{
    int classmates = 0;     // 특정 반의 학생 수

    cout << "=====print_class=====" << endl;
    for (int i = 0; i < size; i++)
    {
        // student_list[i]의 class_name이 class_name과 같으면 학생의 정보 출력
        if (strcmp(student_list[i]->class_name, class_name) == 0)
        {
            cout << "Name: " << student_list[i]->name << endl;
            cout << "Age: " << student_list[i]->age << endl;
            cout << "Class: " << student_list[i]->class_name << endl;
            cout << "----------" << endl;
            classmates++;       // 특정 반의 학생 수 증가
        }
    }
    cout << "Number of classmates : " << classmates << endl;
}
