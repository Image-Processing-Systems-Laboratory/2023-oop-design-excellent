#include "MyString.h"
#include <iostream>
#include "School.h"

using namespace std;

int main() {
	School KW;
	MyString cmd;
	while (cmd != "exit") {
		cin >> cmd;
		if (cmd == "new_student") {
			MyString name, class_name;
			int age;
			cin >> name >> age >> class_name;
			KW.append(name, age, class_name);
		}
		else if (cmd == "sort_by_name") {
			KW.sort();
		}
		else if (cmd == "print_all") {
			cout << "=====print_all=====" << endl;
			KW.print_all();
		}
		else if (cmd == "print_class") {
			MyString class_name;
			cin >> class_name;
			cout << "=====print_class=====" << endl;
			KW.print_class(class_name);
		}
	}
	return 0;
}
