#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Employee class 선언
class Employee {
private:
	char* name;
	int age;
	char* country;
	char* job;

public:
	// 매개변수가 있는 생성자 선언 및 정의
	Employee(char* name, int age, char* country, char* job) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
		this->country = new char[strlen(country) + 1];
		strcpy(this->country, country);
		this->job = new char[strlen(job) + 1];
		strcpy(this->job, job);
	}
	~Employee() { // 소멸자 선언 및 정의
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

	// 멤버함수 선언부
	bool isNameCorrect(char* name);
	void print();
	void change(char* name, int age, char* country, char* job);
};


// 이름이 같은지 확인하는 멤버함수
bool Employee::isNameCorrect(char* name) {
	if (strcmp(name, this->name) == 0)
		return 1; // 이름이 같음을 의미
	else
		return 0; // 이름이 다름을 의미
}

// 출력 멤버함수
void Employee::print() {
	cout << "Name: " << this->name << endl;
	cout << "Age: " << this->age << endl;
	cout << "Country: " << this->country << endl;
	cout << "Job: " << this->job << endl;
	cout << "----------" << endl;
}

// 데이터 변경 멤버함수
void Employee::change(char* name, int age, char* country, char* job) {
	delete[] this->name;//기존 정보 동적할당 해제
	delete[] this->country;
	delete[] this->job;

	this->name = new char[strlen(name) + 1];// name길이만큼 동적할당
	strcpy(this->name, name);
	this->age = age;
	this->country = new char[strlen(country) + 1];// country길이만큼 동적할당
	strcpy(this->country, country);
	this->job = new char[strlen(job) + 1];// job길이만큼 동적할당
	strcpy(this->job, job);
}

int main() {
	Employee* employee[10]{}; // 포인터 변수 10개 선언
	char command[10], temp_name[100], name[100], country[100], job[100];
	int index = 0, age;

	while (1) {
		cin >> command;

		// command에 따라 다른 기능 수행
		if (strcmp(command, "insert") == 0) {
			if (index > 10) {
				cout << "stored information is already 10" << endl;
				continue;
			}

			cin >> name >> age >> country >> job;
			// employee 객체 동적할당 및 매개변수 전달 생성
			employee[index++] = new Employee(name, age, country, job);
			
		}
		// 저장값 출력 기능
		else if (strcmp(command, "print") == 0) {
			cout << "=====print=====" << endl;
			for (int i = 0; i < index; i++)
				employee[i]->print();
			cout << endl;
		}
		// 이름으로 찾아서 출력
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
		// 이름으로 찾아서 같은 것을 변경
		else if (strcmp(command, "change") == 0) {
			cin >> temp_name;
			for (int i = 0; i < index; i++) {
				if (employee[i]->isNameCorrect(temp_name)) { // 바꿀 이름의 데이터가 있으면
					char name[100], country[100], job[100];
					int age;

					cin >> name >> age >> country >> job;
					employee[i]->change(name, age, country, job);
					break;
				}
			}
		}
		// 반복문 호출
		else if (strcmp(command, "exit") == 0) {
			break;
		}
		else {
			cout << "Enter valid command." << endl;
		}
	}
	
	// 소멸자 호출
	for (int i = 0; i < index; i++)
		delete employee[i];

	return 0;
}