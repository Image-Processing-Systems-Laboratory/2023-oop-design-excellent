#include <iostream>
#include <string>
#include <sstream>
#include "Employee.h"

using namespace std;

#define MAX_EMPLOYEES 10        // �ִ� ���� ���� 10���� ����

int main()
{
    Employee* employees[MAX_EMPLOYEES] = { nullptr };       // �������� ������ �迭
    int employee_count = 0;     // ���� ���� ��
    string command, input;      // �Է¹��� ��ɾ�� �Է¹��� ���ڿ�

    while (true)
    {
        getline(cin, input);        // �� �� �Է¹���
        istringstream strin(input);       // �Է¹��� ���ڿ��� ������ �������� ������ ���� ��ü ����
        strin >> command;     // ������ �������� ���� ���ڿ� �� ù ��° ���ڿ��� ��ɾ�� ����

        // insert, find, change, print, exit �� �ϳ��� ��ɾ �Է¹���
        // insert ��ɾ�� ���� ������ �Է¹޾� ������ �߰�
        if (command == "insert")
        {
            // �ִ� ���� ������ ���� ��쿡�� ���� �߰�
            if (employee_count < MAX_EMPLOYEES)
            {
                char name[100], country[100], job[100];     // �̸�, ����, ������ ������ ���ڿ�
                int age;        // ���̸� ������ ������ ����
                strin >> name >> age >> country >> job;       // �̸�, ����, ����, ������ �Է¹���
                employees[employee_count++] = new Employee(name, age, country, job);        // �Է¹��� ������ ���� ��ü ����
            }
            else
            {
                cout << "Not enough memory to store an employee" << endl;
            }
        }
        // find ��ɾ�� ������ �̸��� �Է¹޾� ������ ã��
        else if (command == "find")
        {
            char name[100];	 // �̸��� ������ ���ڿ�
            strin >> name;		// �̸��� �Է¹���
            cout << endl << "=====Find=====" << endl;
            bool found = false;     // ������ ã�Ҵ��� ���θ� ������ ����
            for (int i = 0; i < employee_count; i++)
            {
                if (employees[i]->isNameCorrect(name))
                {
                    found = true;       // ������ ã���� ��� found�� true�� ����
                    employees[i]->print();      // ���� ���� ���
                    cout << "----------" << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "Not found" << endl;
            }
        }
        // change ��ɾ�� ������ �̸��� �Է¹޾� ���� ������ ����
        else if (command == "change")
        {
            char current_name[100], new_name[100], country[100], job[100];      // ���� �̸�, �� �̸�, ����, ������ ������ ���ڿ�
            int age;        // ���̸� ������ ������ ����
            strin >> current_name >> new_name >> age >> country >> job;       // ���� �̸�, �� �̸�, ����, ����, ������ �Է¹���
            bool found = false;     // ������ ã�Ҵ��� ���θ� ������ ����
            // ���� ����� ���� ����ŭ �ݺ�
            for (int i = 0; i < employee_count; i++)
            {
                if (employees[i]->isNameCorrect(current_name))
                {
                    found = true;       // ������ ã���� ��� found�� true�� ����
                    employees[i]->change(new_name, age, country, job);      // ���� ���� ����
                    break;
                }
            }
            if (!found)
            {
                cout << "Not found, unchanged" << endl;
            }
        }
        // print ��ɾ�� ���� ����� ��� ���� ������ ���
        else if (command == "print")
        {
            cout << endl << "=====Print=====" << endl;
            // ���� ����� ���� ����ŭ �ݺ�
            for (int i = 0; i < employee_count; i++)
            {
                employees[i]->print();      // ���� ���� ���
                cout << "----------" << endl;
            }
        }
        // exit ��ɾ�� ���α׷��� ����
        else if (command == "exit")
        {
            break;      // while���� ��������
        }
        // �� ���� ��ɾ �Է¹��� ���
        else
        {
            cout << "Input vaild command" << endl;
        }
    }

    for (int i = 0; i < employee_count; i++) {
        delete employees[i];        // �޸� ����
    }

    return 0;
}
