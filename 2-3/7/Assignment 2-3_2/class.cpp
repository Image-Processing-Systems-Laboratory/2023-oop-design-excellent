#include "class.h"

Student::Student() :name{ NULL }, age(0), class_name{ NULL } {}

Student::Student(char* name, int age, char* class_name) { //�����ڿ��� �ʱ�ȭ
	/*���ڿ����� �����Ҵ� �� ����*/
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->age = age;

	this->class_name = new char[strlen(class_name) + 1];
	strcpy(this->class_name, class_name);
}

char* Student::get_name() { //�ش� ��ü�� �̸� �� ��ȯ
	return name;
}
int Student::get_age() { //�ش� ��ü�� ���� �� ��ȯ
	return age;
}
char* Student::get_class_name() { //�ش� ��ü�� �й� �� ��ȯ
	return class_name;
}


School::School() :size(0), student_list{ NULL } {}

void School::new_student(char*name, int age, char*class_name) { //�л� ���� �߰�
	student_list[size] = new Student(name, age, class_name); //Ŭ���� ��ü �迭�� �����Ҵ� ����
	size++;
}

void School::print_all() { //�л� ���� ��ü ���
	cout << "=====print_all=====" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Name: " << student_list[i]->get_name() << endl;
		cout << "Age: " << student_list[i]->get_age() << endl;
		cout << "Class: " << student_list[i]->get_class_name() << endl;
		cout << "----------" << endl;
	}
}

void School::print_class(int idx) { //�ش� �й� ��ü ���
	cout << "Name: " << student_list[idx]->get_name() << endl;
	cout << "Age: " << student_list[idx]->get_age() << endl;
	cout << "Class: " << student_list[idx]->get_class_name() << endl;
	cout << "----------" << endl;
}

void School::sort_by_name() { ////��ü �迭�� �̸� �� ���� (���� ���� �̿�)
	int i_; //���� �迭 �� ����ų ����
	for (int i = 0; i < size; i++) {
		i_ = i;
		for (int j = i + 1; j < size; j++) {
			/*���� �迭 ���� ���� �迭 ������ Ŭ ��� ���� �迭 ���� ����Ŵ*/
			string name1 = student_list[i_]->get_name();
			string name2 = student_list[j]->get_name();
			if (name1 > name2) {
				i_ = j;
			}
		}
		/*������ �迭 ���� ���� ���� �ƴ� ��� ���� �ڸ� ��ȯ*/
		if (i_ != i) {
			Student* temp = student_list[i];
			student_list[i] = student_list[i_];
			student_list[i_] = temp;
		}
	}
}

int School::showSize() { //��ü �迭�� size ���޿� (main���� ����)
	return size;
}

bool School::Class_correct(char* class_name, int idx) { //�й� �̸� �˻�
	if (strcmp(student_list[idx]->get_class_name(), class_name) == 0) //��ġ�� ��
		return 1;
	else
		return 0;
}