#include "School.h"
#include <iostream>
#include <cstring>

using namespace std;

// destructor
School::~School()
{
    // student_list�� ����� ��� �л����� name, class_name�� delete
    for (int i = 0; i < size; i++)
    {
        delete[] student_list[i]->name;
        delete[] student_list[i]->class_name;
        delete student_list[i];
    }
}

// �л��� �߰��ϴ� �Լ�
void School::new_student(const char* name, int age, const char* class_name)
{
    // �л� ���� 100���� ������ "School is full." ��� �� �Լ� ����
    if (size >= 101)
    {
        cout << "Full" << endl;
        return;
    }

    Student* new_student = new Student;     // ���ο� �л� ����
    new_student->name = new char[strlen(name) + 1];     // name�� ������ char �迭 ���� �Ҵ�
    strcpy_s(new_student->name, strlen(name) + 1, name);        // name�� new_student->name�� ����
    new_student->age = age;     // age ����
    new_student->class_name = new char[strlen(class_name) + 1];     // class_name�� ������ char �迭 ���� �Ҵ�
    strcpy_s(new_student->class_name, strlen(class_name) + 1, class_name);      // class_name�� new_student->class_name�� ����

    student_list[size++] = new_student;     // student_list�� ���ο� �л� �߰�
}

// �л����� �̸������� �����ϴ� �Լ�
void School::sort_by_name()
{
    // bubble sort
    for (int i = 0; i < size; i++)
    {
        // student_list[0]���� student_list[size - 1]���� �ݺ�
        for (int j = 0; j < size - 1; j++)
        {
            // student_list[j]�� �̸��� student_list[j + 1]�� �̸����� ũ�� �� �л��� ������ swap
            if (strcmp(student_list[j]->name, student_list[j + 1]->name) > 0)
            {
                swap(student_list[j], student_list[j + 1]);
            }
        }
    }
}

// �л����� ������ ��� ����ϴ� �Լ�
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

// Ư�� ���� �л����� ������ ����ϴ� �Լ�
void School::print_class(const char* class_name) const
{
    int classmates = 0;     // Ư�� ���� �л� ��

    cout << "=====print_class=====" << endl;
    for (int i = 0; i < size; i++)
    {
        // student_list[i]�� class_name�� class_name�� ������ �л��� ���� ���
        if (strcmp(student_list[i]->class_name, class_name) == 0)
        {
            cout << "Name: " << student_list[i]->name << endl;
            cout << "Age: " << student_list[i]->age << endl;
            cout << "Class: " << student_list[i]->class_name << endl;
            cout << "----------" << endl;
            classmates++;       // Ư�� ���� �л� �� ����
        }
    }
    cout << "Number of classmates : " << classmates << endl;
}
