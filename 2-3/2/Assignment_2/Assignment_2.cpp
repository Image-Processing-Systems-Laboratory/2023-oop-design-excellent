#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Student {//Student 클래스
private:
	char* name;//이름
	int age = 0;//나이
	char* class_name;//반 이름

public:
	Student(char* name, int age, char* class_name);//생성자
	~Student();//소멸자
	char* get_name() { return this->name; }//이름 반환
	int get_age() { return this->age; }//나이 반환
	char* get_class_name() { return this->class_name; }//반 이름 반환
};

class School {//School 클래스
private:
	class Student* student_list[100];//배열 선언, 최대 100명 정보 저장
	int size = 0;//저장한 학생 수

public:
	void save(char* name, int age, char* class_name) {//학생 정보 저장
		student_list[size] = new Student(name, age, class_name);//Student 객체 동적 할당
		size++;//학생 수 증가
	}
	int size_getter() { return this->size; }//학생 수 반환

	void print(int i);//출력
	int find(char* class_name, int cnt);//특정 반 학생 탐색
	void sort();//sort_by_name

	~School() {//소멸자
		for (int j = 0; j < size; j++)
			delete student_list[j];//동적 할당 해제
	}
};

Student::Student(char* name, int age, char* class_name) {//생성자
	this->name = new char[strlen(name) + 1];//name길이만큼 동적할당
	strcpy(this->name, name);//name 복사
	this->age = age;
	this->class_name = new char[strlen(class_name) + 1];//class_name길이만큼 동적할당
	strcpy(this->class_name, class_name);//class_name 복사
}

Student::~Student() {//소멸자
	delete []name;//동적할당 해제
	delete []class_name;
}

void School::print(int i) {//학생 정보 한 명 출력
	cout << "Name: " << student_list[i]->get_name() << endl;
	cout << "Age: " << student_list[i]->get_age() << endl;
	cout << "Class: " << student_list[i]->get_class_name() << endl;
	cout << "----------" << endl;
}

void School::sort() {//sort_by_name
	for (int j = 0; j < this->size; j++) {//bubble sort 사용
		for (int k = 0; k < this->size - 1; k++) {
			if (strcmp(student_list[k]->get_name(), student_list[k + 1]->get_name())>0) {//앞에 위치한 이름이 뒤보다 클 때
				Student* temp;//학생 정보 배열 순서 변경
				temp = student_list[k];
				student_list[k] = student_list[k + 1];
				student_list[k + 1] = temp;
			}
		}
	}
}

int School::find(char* class_name, int cnt) {//특정 반 학생 검색
	for (int j = 0; j < size; j++) {
		if (strcmp(student_list[j]->get_class_name(), class_name) == 0) {//동일 반일 때
			print(j);//출력
			cnt++;
		}
	}
	return cnt;//특정 반 학생 수 반환
}

int main() {
	School* school = new School;//동적 할당
	char input[100]{};
	char name_i[10]{};
	int age_i = 0;
	char class_name_i[100]{};
	int size = 0;

	while (1) {
		cin >> input;
		if (strcmp(input, "new_student") == 0) {
			cin >> name_i >> age_i >> class_name_i;
			school->save(name_i, age_i, class_name_i);//학생 정보 버장
		}
		else if (strcmp(input, "sort_by_name") == 0) {
			school->sort();//sort 함수 호출
		}
		else if (strcmp(input, "print_all") == 0) {
			size = school->size_getter();
			cout << "=====print_all=====" << endl;
			for (int j = 0; j < size; j++)//저장된 학생 수만큼 출력
				school->print(j);
		}
		else if (strcmp(input, "print_class") == 0) {
			int cnt = 0;
			cin >> class_name_i;
			cout << "=====print_class=====" << endl;
			cnt = school->find(class_name_i, 0);//find 함수 호출 후 반환된 학생 수 저장
			cout << "Number of classmates: " << cnt << endl;//학생 수 출력
		}
		else if (strcmp(input, "exit") == 0)//while문 탈출
			break;
		else
			continue;
	}

	delete school;//동적할당 해제
	return 0;
}