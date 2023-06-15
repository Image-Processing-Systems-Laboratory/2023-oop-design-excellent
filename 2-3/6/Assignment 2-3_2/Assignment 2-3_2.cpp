#include "School.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    School school;      // School ��ü ����
    string input;       // ����� �Է��� ������ string ����

    while (true)
    {
        getline(cin, input);        // ����� �Է��� input�� ����
        stringstream strin(input);      // input�� stringstream���� ��ȯ
        string command;     // ��ɾ ������ string ����
        strin >> command;    // strin���� command�� �о��

        // command�� ���� �ٸ� �Լ� ȣ��
        // new_student�� ��� �̸�, ����, ���� �Է¹޾� �л��� �߰�
        if (command == "new_student")
        {
            char name[100], class_name[100];
            int age;
            strin >> name >> age >> class_name;
            school.new_student(name, age, class_name);
        }
        // sort_by_name�� ��� �л����� �̸������� ����
        else if (command == "sort_by_name")
        {
            school.sort_by_name();
        }
        // print_all�� ��� �л����� ������ ��� ���
        else if (command == "print_all")
        {
            school.print_all();
        }
        // print_class�� ��� ���� �Է¹޾� �ش� ���� �л����� ������ ���
        else if (command == "print_class")
        {
            char class_name[100];
            strin >> class_name;
            school.print_class(class_name);
        }
        // exit�� ��� ���α׷� ����
        else if (command == "exit")
        {
            break;
        }
        // �� ���� ��� ��ȿ�� ��ɾ �Է��ϵ��� ���
        else
        {
            cout << "Input vaild command" << endl;
        }
    }

    return 0;
}
