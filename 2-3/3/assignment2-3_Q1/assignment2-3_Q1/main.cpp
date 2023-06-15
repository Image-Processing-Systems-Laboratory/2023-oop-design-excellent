#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Employee class ����
class Employee {
private:
	char* name;
	int age;
	char* country;
	char* job;

public:
	// �Ű������� �ִ� ������ ���� �� ����
	Employee(char* name, int age, char* country, char* job) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
		this->country = new char[strlen(country) + 1];
		strcpy(this->country, country);
		this->job = new char[strlen(job) + 1];
		strcpy(this->job, job);
	}
	~Employee() { // �Ҹ��� ���� �� ����
		if (this->name != nullptr) {
			delete name;
			name = NULL;
		}
		if (this->country != nullptr) {
			delete[] country;
			country = NULL;
		}
		if (this->job != nullptr) {
			delete[] job;
			job = NULL;
		}

	}

	// ����Լ� �����
	bool isNameCorrect(char* name);
	void print();
	void change(char* name, int age, char* country, char* job);
};


// �̸��� ������ Ȯ���ϴ� ����Լ�
bool Employee::isNameCorrect(char* name) {
	if (strcmp(name, this->name) == 0)
		return 1; // �̸��� ������ �ǹ�
	else
		return 0; // �̸��� �ٸ��� �ǹ�
}

// ��� ����Լ�
void Employee::print() {
	cout << "Name: " << this->name << endl;
	cout << "Age: " << this->age << endl;
	cout << "Country: " << this->country << endl;
	cout << "Job: " << this->job << endl;
	cout << "----------" << endl;
}

// ������ ���� ����Լ�
void Employee::change(char* name, int age, char* country, char* job) {
	delete[] this->name;//���� ���� �����Ҵ� ����
	delete[] this->country;
	delete[] this->job;

	this->name = new char[strlen(name) + 1];// name���̸�ŭ �����Ҵ�
	strcpy(this->name, name);
	this->age = age;
	this->country = new char[strlen(country) + 1];// country���̸�ŭ �����Ҵ�
	strcpy(this->country, country);
	this->job = new char[strlen(job) + 1];// job���̸�ŭ �����Ҵ�
	strcpy(this->job, job);
}

int main() {
	Employee* employee[10]{}; // ������ ���� 10�� ����
	char command[10], temp_name[100], name[100], country[100], job[100];
	int index = 0, age;

	while (1) {
		cin >> command;

		// command�� ���� �ٸ� ��� ����
		if (strcmp(command, "insert") == 0) {
			if (index > 10) {
				cout << "stored information is already 10" << endl;
				continue;
			}

			cin >> name >> age >> country >> job;
			// employee ��ü �����Ҵ� �� �Ű����� ���� ����
			employee[index++] = new Employee(name, age, country, job);
			
		}
		// ���尪 ��� ���
		else if (strcmp(command, "print") == 0) {
			cout << "=====print=====" << endl;
			for (int i = 0; i < index; i++)
				employee[i]->print();
			cout << endl;
		}
		// �̸����� ã�Ƽ� ���
		else if (strcmp(command, "find") == 0) {
			cin >> temp_name;
			for (int i = 0; i < index; i++) {
				if (employee[i]->isNameCorrect(temp_name)) {
					cout << "=====find=====" << endl;
					employee[i]->print();
					cout << endl;
					break;
				}
			}
		}
		// �̸����� ã�Ƽ� ���� ���� ����
		else if (strcmp(command, "change") == 0) {
			cin >> temp_name;
			for (int i = 0; i < index; i++) {
				if (employee[i]->isNameCorrect(temp_name)) { // �ٲ� �̸��� �����Ͱ� ������
					char name[100], country[100], job[100];
					int age;

					cin >> name >> age >> country >> job;
					employee[i]->change(name, age, country, job);
					break;
				}
			}
		}
		// �ݺ��� ȣ��
		else if (strcmp(command, "exit") == 0) {
			break;
		}
		else {
			cout << "Enter valid command." << endl;
		}
	}
	
	// �Ҹ��� ȣ��
	for (int i = 0; i < index; i++)
		delete employee[i];

	return 0;
}