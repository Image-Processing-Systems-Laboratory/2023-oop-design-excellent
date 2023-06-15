#include "School.h"


School::School() :size(0) {
	for (size_t i = 0; i < 100; i++) {		// student_list �ʱ�ȭ
		student_list[i] = nullptr;
	}
};

School::~School() {
	for (size_t idx = 0; idx < size; idx++) {
		if (student_list[idx] == nullptr)
			continue;
		delete student_list[idx];		// �����Ҵ� ����
	}
}

void School::append(MyString& name, int& age, MyString& class_name) {
	Student* std = new Student(name, age, class_name);		// �����Ҵ�
	student_list[size++] = std;				// list�� ����
}

void swap_student(Student* &s1, Student* &s2) {		// ������ Swap �Լ�
	Student* temp = s2;
	s2 = s1;
	s1 = temp;
}

bool dist(MyString& name1, MyString& name2) {		// �� ���ڿ��� ���ϴ� �Լ�
	size_t min_high = (name1.size() > name2.size()) ? name1.size() : name2.size();		// ���� �� �Ҵ�
	for (size_t idx = 0; idx < min_high; idx++) {
		char ch1 = name1[idx];
		char ch2 = name2[idx];
		if (ch1 >= 'A' && ch1 <= 'Z')
			ch1 += 32;		// �ҹ��ڰ� ascii�� ��ũ��
		if (ch2 >= 'A' && ch2 <= 'Z')
			ch2 += 32;			// �ҹ��ڰ� ascii�� ��ũ��
		if (ch1 > ch2)			// �ٲ�� �� �� true
			return true;
		else if (ch1 < ch2)		// �ٲ��� �ʾƵ� �� �� false
			return false;
	}
	return (name1.size() > name2.size()) ? true : false;		// abc, abcde ���� ���̽��� ��
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
	for (size_t idx = 0; idx < size; idx++) {		// �л� ���� ���
		std::cout << "Name: " << student_list[idx]->name << std::endl;
		std::cout << "Age: "<<student_list[idx]->age << std::endl;
		std::cout << "Class: "<<student_list[idx]->class_name << std::endl;
		std::cout << "----------" << std::endl;
	}
}


void School::print_class(MyString& clan)
{
	for (size_t idx = 0; idx < size; idx++) {
		if (student_list[idx]->class_name != clan)		// clan�ϰ� ���� ��츸 ���
			continue;
		std::cout << "Name: " << student_list[idx]->name << std::endl;
		std::cout << "Age: " << student_list[idx]->age << std::endl;
		std::cout << "Class: " << student_list[idx]->class_name << std::endl;
		std::cout << "----------" << std::endl;
	}
}
