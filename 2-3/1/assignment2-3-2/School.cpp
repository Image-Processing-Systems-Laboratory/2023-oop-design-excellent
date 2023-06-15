#include "School.h"

Student::Student(char* name, int age, char* class_name) {
	/* name 깊은 복사*/
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);

	this->age = age;
	
	/* class_name 깊은 복사*/
	len = strlen(class_name);
	this->class_name = new char[len + 1];
	strcpy(this->class_name, class_name);
}
Student::~Student() {
	delete[]name;
	delete[]class_name;
}
char* Student::getName() {
	return name;
}
char* Student::getClass_name() {
	return class_name;
}

void School::new_student(char* name, int age, char* class_name) {
	if (size == 100) // 이미 100명의 student가 존재할 때
		return;
	student_list[size] = new Student(name, age, class_name);
	size++;
}
void School::sort_by_name() {
	/* Bubble Sort*/
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			/* j번째 객체가 j+1객체보다 name의 아스키코드값이 클 경우 swap*/
			if (strcmp(student_list[j]->getName(), student_list[j + 1]->getName()) > 0) {
				Student* tmp = student_list[j];
				student_list[j] = student_list[j + 1];
				student_list[j + 1] = tmp;
			}
		}
	}
}
void School::print_all() {
	cout << "=====print_all=====" << endl;
	for (int i = 0; i < size; i++) {
		student_list[i]->print();
	}
}
void School::print_class(char* class_name) {
	int num = 0; // 같은반 학생의 수
	cout << "=====print_class=====" << endl;
	for (int i = 0; i < size; i++) {
		if (!strcmp(student_list[i]->getClass_name(), class_name)){
			student_list[i]->print();
			num++;
		}
	}
	cout << "Number of classmates: " << num << endl;
}