#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Student { // Student 클래스
private:
    char* name; // 이름
    int age; // 나이
    char* class_name; // 반

public:
    Student() {
        name = nullptr;
        age = 0;
        class_name = nullptr;       
    }
         
    Student(const char* name, int age, const char* class_name) { // 생성자
        this->name = new char[strlen(name) + 1]; // 동적할당
        strcpy(this->name, name); // 복사

        this->age = age;

        this->class_name = new char[strlen(class_name) + 1];
        strcpy(this->class_name, class_name);
    }
    ~Student() {
        delete[] name; // 동적할당 해제
        delete[] class_name;    
    }
    void print() const { // 출력
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Class: " << class_name << endl;
        cout << "----------" << endl;
    }
    const char* getName() const { 
        return name;
    }
    const char* getClassName() const {
        return class_name;
    }
};

class School { // School 클래스
private:
    Student* student_list[100]; // Student 객체를 담는 배열
    int size; // 배열의 크기

public:
    School(){
    size = 0;
    }
    ~School() { // 소멸자
        for (int i = 0; i < size; ++i) {
            delete student_list[i];
        }
    }
    void addStudent(const char* name, int age, const char* class_name) { // 학생 추가
        student_list[size++] = new Student(name, age, class_name); 
    }
    void sortByNames() { // 이름순으로 정렬
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (strcmp(student_list[i]->getName(), student_list[j]->getName()) > 0) { // strcmp를 이용하여 이름순으로 정렬
                    swap(student_list[i], student_list[j]); 
                }
            }
        }
    }
    void printAll() { // 모든 학생 출력
        cout << "=====print_all=====" << endl;
        for (int i = 0; i < size; ++i) {
            student_list[i]->print(); // Student 클래스의 print 함수 호출
        }
    }
    void printClass(const char* class_name) { // 반 이름이 일치하는 학생 출력
        cout << "=====print_class=====" << endl;
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (strcmp(student_list[i]->getClassName(), class_name) == 0) { // strcmp를 이용하여 반 이름이 일치하는 학생 출력
                student_list[i]->print();
                ++count;
            }
        }
        cout << "Number of classmates: " << count << endl;
    }
};
int main() {
    School school; // School 객체 생성
    string command;
    while (cin >> command) { // command 입력
        if (command == "new_student") { // command가 new_student일 경우
            char name[50], class_name[50];
            int age;
            cin >> name >> age >> class_name;
            school.addStudent(name, age, class_name); // 학생 추가
        }
        else if (command == "sort_by_name") { // command가 sort_by_name일 경우
            school.sortByNames(); // 이름순으로 정렬
        }
        else if (command == "print_all") { // command가 print_all일 경우
            school.printAll(); // 모든 학생 출력
        }
        else if (command == "print_class") { // command가 print_class일 경우
            char class_name[50];
            cin >> class_name;
            school.printClass(class_name); // 반 이름이 일치하는 학생 출력
        }
        else if (command == "exit") { // command가 exit일 경우
            break;
        }
    }
    return 0;
}