#include "School.h"


School::School() :size(0) {
	for (size_t i = 0; i < 100; i++) {		// student_list 초기화
		student_list[i] = nullptr;
	}
};

School::~School() {
	for (size_t idx = 0; idx < size; idx++) {
		if (student_list[idx] == nullptr)
			continue;
		delete student_list[idx];		// 동적할당 해제
	}
}

void School::append(MyString& name, int& age, MyString& class_name) {
	Student* std = new Student(name, age, class_name);		// 동적할당
	student_list[size++] = std;				// list에 배정
}

void swap_student(Student* &s1, Student* &s2) {		// 포인터 Swap 함수
	Student* temp = s2;
	s2 = s1;
	s1 = temp;
}

bool dist(MyString& name1, MyString& name2) {		// 두 문자열을 비교하는 함수
	size_t min_high = (name1.size() > name2.size()) ? name1.size() : name2.size();		// 작은 값 할당
	for (size_t idx = 0; idx < min_high; idx++) {
		char ch1 = name1[idx];
		char ch2 = name2[idx];
		if (ch1 >= 'A' && ch1 <= 'Z')
			ch1 += 32;		// 소문자가 ascii가 더크다
		if (ch2 >= 'A' && ch2 <= 'Z')
			ch2 += 32;			// 소문자가 ascii가 더크다
		if (ch1 > ch2)			// 바꿔야 할 때 true
			return true;
		else if (ch1 < ch2)		// 바꾸지 않아도 될 때 false
			return false;
	}
	return (name1.size() > name2.size()) ? true : false;		// abc, abcde 같은 케이스일 때
}

void School::sort() {
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = i+1; j < size; j++) {
			if (dist(student_list[i]->name, student_list[j]->name))
				swap_student(student_list[i], student_list[j]);
		}
	}
}


void School::print_all()
{
	for (size_t idx = 0; idx < size; idx++) {		// 학생 정보 출력
		std::cout << "Name: " << student_list[idx]->name << std::endl;
		std::cout << "Age: "<<student_list[idx]->age << std::endl;
		std::cout << "Class: "<<student_list[idx]->class_name << std::endl;
		std::cout << "----------" << std::endl;
	}
}


void School::print_class(MyString& clan)
{
	for (size_t idx = 0; idx < size; idx++) {
		if (student_list[idx]->class_name != clan)		// clan하고 같은 경우만 출력
			continue;
		std::cout << "Name: " << student_list[idx]->name << std::endl;
		std::cout << "Age: " << student_list[idx]->age << std::endl;
		std::cout << "Class: " << student_list[idx]->class_name << std::endl;
		std::cout << "----------" << std::endl;
	}
}
