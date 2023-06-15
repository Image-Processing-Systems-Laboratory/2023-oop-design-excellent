#include "School.h"

int main() {
	School school;
	char command[100];
	char name[100];
	int age;
	char class_name[100];

	while (1) {
		cin >> command;
		if (!strcmp(command, "new_student")) {
			cin >> name >> age >> class_name;
			school.new_student(name, age, class_name);
		}
		else if (!strcmp(command, "sort_by_name")) {
			school.sort_by_name();
		}
		else if (!strcmp(command, "print_all")) {
			school.print_all();
		}
		else if (!strcmp(command, "print_class")) {
			cin >> class_name;
			school.print_class(class_name);
		}
		else if (!strcmp(command, "exit")) {
			break;
		}
		else {
			cout << "Wrong command. Try again." << endl;
			while (getchar() != '\n') {} // 버퍼 비우기
		}
	}

	return 0;
}