#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Employee { // Employee 클래스
private:
    char* name; // 이름
    int age; // 나이
    char* country; // 국적
    char* job; // 직업
public: 
    Employee(char* name, int age, char* country, char* job) { // 생성자
        this->name = new char[strlen(name) + 1]; // 이름 동적할당
        strcpy(this->name, name); // 이름 복사
        this->age = age; // 나이 복사
        this->country = new char[strlen(country) + 1]; // 국적 동적할당
        strcpy(this->country, country); // 국적 복사
        this->job = new char[strlen(job) + 1]; // 직업 동적할당
        strcpy(this->job, job); // 직업 복사
    }

    ~Employee() {
        delete[] name; // 동적할당 해제
        delete[] country; 
        delete[] job; 
    }

    bool isNameCorrect(const char* name) { // 이름이 일치하는지 확인
        return strcmp(this->name, name) == 0;
    }

    void print() { // 정보 출력
        cout << "Name: " << name << endl; 
        cout << "Age: " << age << endl;
        cout << "Country: " << country << endl;
        cout << "Job: " << job << endl;
        cout << "----------" << endl;
    }

    void change(char* name, int age, char* country, char* job) { // 정보 변경
        delete[] this->name; // 기존 동적할당 해제
        this->name = new char[strlen(name) + 1]; // 새로 동적할당
        strcpy(this->name, name); // 복사
        this->age = age;
        delete[] this->country;
        this->country = new char[strlen(country) + 1];
        strcpy(this->country, country);
        delete[] this->job;
        this->job = new char[strlen(job) + 1];
        strcpy(this->job, job);
    }
};

int main() {
    Employee* employees[10]; // Employee 객체 배열
    int employee_count = 0; // 현재 Employee 객체의 개수
    char command[10];  // 명령어
    char name[50], country[50], job[50]; 
    int age;

    while (true) { // 명령어 입력
        cin >> command; 

        if (strcmp(command, "insert") == 0) { // insert 명령어
            cin >> name >> age >> country >> job;
            if (employee_count < 10) { // 10명 이하일 때만 추가
                employees[employee_count++] = new Employee(name, age, country, job);
            }
            else {
                cout << "Cannot insert more than 10 employees." << endl;
            }
        }
        else if (strcmp(command, "find") == 0) { // find 명령어
            cin >> name;
            bool found = false; // 찾았는지 여부
            for (int i = 0; i < employee_count; i++) { // 이름이 일치하는지 확인
                if (employees[i]->isNameCorrect(name)) {
                    cout << "=====find=====" << endl;
                    employees[i]->print();
                    found = true;
                    break;
                }
            }
            if (!found) { // 찾지 못했을 때
                cout << "Employee not found." << endl;
            }
        }
        else if (strcmp(command, "change") == 0) { // change 명령어
            char new_name[50];
            cin >> name >> new_name >> age >> country >> job; 
            bool found = false; // 찾았는지 여부
            for (int i = 0; i < employee_count; i++) { // 이름이 일치하는지 확인
                if (employees[i]->isNameCorrect(name)) {
                    employees[i]->change(new_name, age, country, job);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Employee not found." << endl;
            }
        }
        else if (strcmp(command, "print") == 0) { // print 명령어
            cout << "=====print=====" << endl;
            for (int i = 0; i < employee_count; i++) {
                employees[i]->print();
            }
        }
        else if (strcmp(command, "exit") == 0) { // exit 명령어
            break;
        }
        else {
            cout << "Invalid command." << endl;
        }
    }

    for (int i = 0; i < employee_count; i++) { // 동적할당 해제
        delete employees[i];
    }

    return 0;
}

