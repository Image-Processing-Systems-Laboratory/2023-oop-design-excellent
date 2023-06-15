#include <iostream>
#include <string.h>

using namespace std;

// �л� class �����
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
	// �Ҹ���
	~Student() {
		if (name != nullptr) 
			delete[] name;
		
		if (class_name != nullptr) 
			delete[] class_name;
	}

	// �� ������ ���� �� ��� ��� �Լ���
	void setName(char name[]) { this->name = name; }
	char* getName() { return this->name; }
	void setAge(int age) { this->age = age; }
	int getAge() { return this->age; }
	void setClass(char class_name[]) { this->class_name = class_name; }
	char* getClass() { return this->class_name; }
};

// School class �����
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

// School ��ü�� student ��ü �߰��ϴ� ����Լ�
void School::setStudent(char name[], int age, char class_name[]) {
	
	Student* newstudent = new Student();

	newstudent->setName(name);
	newstudent->setAge(age);
	newstudent->setClass(class_name);

	this->student_list[this->size++] = newstudent;
}

// �̸����� �������� ����
void School::sort_Name() {

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (compare_names(student_list[j], student_list[j + 1])) {
				// �ڰ� �� ũ�� �� �� ��ȯ
				Student* temp = student_list[j];
				student_list[j] = student_list[j + 1];
				student_list[j + 1] = temp;
			}
		}
	}
}

bool School::compare_names(Student* s1, Student* s2)
{
	// �� �̸� ���Ͽ� �� ���� ��ȯ
	// ���� �ں��� ������ ���� ��ȯ
	// �ڰ� �պ��� ũ�ų� ������ �� ��ȯ
	return strcmp(s1->getName(), s2->getName()) > 0;
}

// ��ü ��� ����Լ�
void School::print_all() {
	for (int i = 0; i < this->size; i++) {
		cout << "Name: " << this->student_list[i]->getName() << endl;
		cout << "Age: " << this->student_list[i]->getAge() << endl;
		cout << "Class: " << this->student_list[i]->getClass() << endl;
		cout << "----------" << endl;
	}
}

// class ��� ����Լ�
void School::print_class(char class_name[]) {
	for (int i = 0; i < this->size; i++) {
		// �Է¹��� class���� ������ ���
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
		cin >> command; // command �Էº�

		// command�� ���� �ٸ� ��� ����
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
		else // ��ġ�Ǵ� �ʴ� command�� ����ó��
			cout << "Enter vaild command." << endl;
	}

	delete school; // �Ҵ� ����


	return 0;
}