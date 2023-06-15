#include "class.h"

Student::Student() :name{ NULL }, age(0), class_name{ NULL } {}

Student::Student(char* name, int age, char* class_name) { //생성자에서 초기화
	/*문자열들은 동적할당 후 복사*/
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->age = age;

	this->class_name = new char[strlen(class_name) + 1];
	strcpy(this->class_name, class_name);
}

char* Student::get_name() { //해당 객체의 이름 값 반환
	return name;
}
int Student::get_age() { //해당 객체의 나이 값 반환
	return age;
}
char* Student::get_class_name() { //해당 객체의 분반 값 반환
	return class_name;
}


School::School() :size(0), student_list{ NULL } {}

void School::new_student(char*name, int age, char*class_name) { //학생 정보 추가
	student_list[size] = new Student(name, age, class_name); //클래스 객체 배열로 동적할당 저장
	size++;
}

void School::print_all() { //학생 정보 전체 출력
	cout << "=====print_all=====" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Name: " << student_list[i]->get_name() << endl;
		cout << "Age: " << student_list[i]->get_age() << endl;
		cout << "Class: " << student_list[i]->get_class_name() << endl;
		cout << "----------" << endl;
	}
}

void School::print_class(int idx) { //해당 분반 전체 출력
	cout << "Name: " << student_list[idx]->get_name() << endl;
	cout << "Age: " << student_list[idx]->get_age() << endl;
	cout << "Class: " << student_list[idx]->get_class_name() << endl;
	cout << "----------" << endl;
}

void School::sort_by_name() { ////객체 배열들 이름 순 정렬 (선택 정렬 이용)
	int i_; //이전 배열 값 가리킬 변수
	for (int i = 0; i < size; i++) {
		i_ = i;
		for (int j = i + 1; j < size; j++) {
			/*이전 배열 값이 다음 배열 값보다 클 경우 다음 배열 값을 가리킴*/
			string name1 = student_list[i_]->get_name();
			string name2 = student_list[j]->get_name();
			if (name1 > name2) {
				i_ = j;
			}
		}
		/*선택한 배열 값이 작은 값이 아닐 경우 서로 자리 교환*/
		if (i_ != i) {
			Student* temp = student_list[i];
			student_list[i] = student_list[i_];
			student_list[i_] = temp;
		}
	}
}

int School::showSize() { //객체 배열의 size 전달용 (main에서 쓰임)
	return size;
}

bool School::Class_correct(char* class_name, int idx) { //분반 이름 검색
	if (strcmp(student_list[idx]->get_class_name(), class_name) == 0) //일치할 시
		return 1;
	else
		return 0;
}