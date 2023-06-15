#include <iostream>
#include <string>
#include <sstream>
#include "Employee.h"

using namespace std;

#define MAX_EMPLOYEES 10        // 최대 직원 수를 10으로 정의

int main()
{
    Employee* employees[MAX_EMPLOYEES] = { nullptr };       // 직원들을 저장할 배열
    int employee_count = 0;     // 현재 직원 수
    string command, input;      // 입력받을 명령어와 입력받은 문자열

    while (true)
    {
        getline(cin, input);        // 한 줄 입력받음
        istringstream strin(input);       // 입력받은 문자열을 공백을 기준으로 나누기 위한 객체 생성
        strin >> command;     // 공백을 기준으로 나눈 문자열 중 첫 번째 문자열을 명령어로 저장

        // insert, find, change, print, exit 중 하나의 명령어를 입력받음
        // insert 명령어는 직원 정보를 입력받아 직원을 추가
        if (command == "insert")
        {
            // 최대 직원 수보다 적을 경우에만 직원 추가
            if (employee_count < MAX_EMPLOYEES)
            {
                char name[100], country[100], job[100];     // 이름, 국적, 직업을 저장할 문자열
                int age;        // 나이를 저장할 정수형 변수
                strin >> name >> age >> country >> job;       // 이름, 나이, 국적, 직업을 입력받음
                employees[employee_count++] = new Employee(name, age, country, job);        // 입력받은 정보로 직원 객체 생성
            }
            else
            {
                cout << "Not enough memory to store an employee" << endl;
            }
        }
        // find 명령어는 직원의 이름을 입력받아 직원을 찾음
        else if (command == "find")
        {
            char name[100];	 // 이름을 저장할 문자열
            strin >> name;		// 이름을 입력받음
            cout << endl << "=====Find=====" << endl;
            bool found = false;     // 직원을 찾았는지 여부를 저장할 변수
            for (int i = 0; i < employee_count; i++)
            {
                if (employees[i]->isNameCorrect(name))
                {
                    found = true;       // 직원을 찾았을 경우 found를 true로 변경
                    employees[i]->print();      // 직원 정보 출력
                    cout << "----------" << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "Not found" << endl;
            }
        }
        // change 명령어는 직원의 이름을 입력받아 직원 정보를 수정
        else if (command == "change")
        {
            char current_name[100], new_name[100], country[100], job[100];      // 현재 이름, 새 이름, 국적, 직업을 저장할 문자열
            int age;        // 나이를 저장할 정수형 변수
            strin >> current_name >> new_name >> age >> country >> job;       // 현재 이름, 새 이름, 나이, 국적, 직업을 입력받음
            bool found = false;     // 직원을 찾았는지 여부를 저장할 변수
            // 현재 저장된 직원 수만큼 반복
            for (int i = 0; i < employee_count; i++)
            {
                if (employees[i]->isNameCorrect(current_name))
                {
                    found = true;       // 직원을 찾았을 경우 found를 true로 변경
                    employees[i]->change(new_name, age, country, job);      // 직원 정보 수정
                    break;
                }
            }
            if (!found)
            {
                cout << "Not found, unchanged" << endl;
            }
        }
        // print 명령어는 현재 저장된 모든 직원 정보를 출력
        else if (command == "print")
        {
            cout << endl << "=====Print=====" << endl;
            // 현재 저장된 직원 수만큼 반복
            for (int i = 0; i < employee_count; i++)
            {
                employees[i]->print();      // 직원 정보 출력
                cout << "----------" << endl;
            }
        }
        // exit 명령어는 프로그램을 종료
        else if (command == "exit")
        {
            break;      // while문을 빠져나감
        }
        // 그 외의 명령어를 입력받을 경우
        else
        {
            cout << "Input vaild command" << endl;
        }
    }

    for (int i = 0; i < employee_count; i++) {
        delete employees[i];        // 메모리 해제
    }

    return 0;
}
