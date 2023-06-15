#include <iostream>
#include <string.h>

using namespace std;

// 학생 class 선언부
class Student {
private:
	char* name;
	int age;
	char* class_name;
	
public:
	Student() {
		this->name = NULL;
		this->age = 0;
		this->class_name = NULL;
	}
	// 소멸자
	~Student() {
		if (name != nullptr) 
			delete[] name;
		
		if (class_name != nullptr) 
			delete[] class_name;
	}

	// 각 데이터 저장 및 출력 멤버 함수들
	void setName(char name[]) { this->name = name; }
	char* getName() { return this->name; }
	void setAge(int age) { this->age = age; }
	int getAge() { return this->age; }
	void setClass(char class_name[]) { this->class_name = class_name; }
	char* getClass() { return this->class_name; }
};

// School class 선언부
class School {
private:
	class Student* student_list[100];
	int size;

public:
	School() {
		for (int i = 0; i < 100; i++) {
			student_list[i] = new Student();
		}
		size = 0;
	}
	~School() {
		for (int i = 0; i < size; i++) {
			if (student_list[i] != nullptr) {
				delete student_list[i];
				student_list[i] = nullptr;
			}
		}
	}

	void setStudent(char name[], int age, char class_name[]);
	void sort_Name();
	bool compare_names(Student* s1, Student* s2);
	void print_all();
	void print_class(char class_name[]);
};

// School 객체에 student 객체 추가하는 멤버함수
void School::setStudent(char name[], int age, char class_name[]) {
	
	Student* newstudent = new Student();

	newstudent->setName(name);
	newstudent->setAge(age);
	newstudent->setClass(class_name);

	this->student_list[this->size++] = newstudent;
}

// 이름으로 오름차순 정렬
void School::sort_Name() {

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (compare_names(student_list[j], student_list[j + 1])) {
				// 뒤가 더 크면 앞 뒤 교환
				Student* temp = student_list[j];
				student_list[j] = student_list[j + 1];
				student_list[j + 1] = temp;
			}
		}
	}
}

bool School::compare_names(Student* s1, Student* s2)
{
	// 두 이름 비교하여 참 거짓 반환
	// 앞이 뒤보다 작으면 거짓 반환
	// 뒤가 앞보다 크거나 같으면 참 반환
	return strcmp(s1->getName(), s2->getName()) > 0;
}

// 전체 출력 멤버함수
void School::print_all() {
	for (int i = 0; i < this->size; i++) {
		cout << "Name: " << this->student_list[i]->getName() << endl;
		cout << "Age: " << this->student_list[i]->getAge() << endl;
		cout << "Class: " << this->student_list[i]->getClass() << endl;
		cout << "----------" << endl;
	}
}

// class 출력 멤버함수
void School::print_class(char class_name[]) {
	for (int i = 0; i < this->size; i++) {
		// 입력받은 class명이 같으면 출력
		if (strcmp(class_name, this->student_list[i]->getClass()) == 0) {
			cout << "Name: " << this->student_list[i]->getName() << endl;
			cout << "Age: " << this->student_list[i]->getAge() << endl;
			cout << "Class: " << this->student_list[i]->getClass() << endl;
			cout << "----------" << endl;
		}
	}
}


int main() {

	School* school = new School;
	char command[20];

	while (1) {
		cin >> command; // command 입력부

		// command에 따라 다른 기능 실행
		if (strcmp(command, "new_student") == 0) {
			char* name = new char[100];
			char* class_name = new char[100];
			int age = 0;

			cin >> name >> age >> class_name;
			school->setStudent(name, age, class_name);
		}
		else if (strcmp(command, "sort_by_name") == 0) {
			school->sort_Name();
		}
		else if (strcmp(command, "print_all") == 0) {
			cout << "=====print_all=====" << endl;
			school->print_all();
		}
		else if (strcmp(command, "print_class") == 0) {
			char class_name[100];
			cin >> class_name;

			cout << "=====print_class=====" << endl;
			school->print_class(class_name);

		}
		else if (strcmp(command, "exit") == 0) {
			break;
		}
		else // 매치되는 않는 command면 예외처리
			cout << "Enter vaild command." << endl;
	}

	delete school; // 할당 해제


	return 0;
}