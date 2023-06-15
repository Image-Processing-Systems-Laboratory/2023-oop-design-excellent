#include <iostream>
#include "MyString.h"		// string�� ����
#include "Employee.h"		// Employee Ŭ���� ����

using namespace std;

int main() {
	Employee employees[10];	// �ִ� 10����� ������ �� �ִ� �迭
	size_t crr = 0;		// �迭�� ������ + 1 ��Ҹ� ����ų Ŀ��
	MyString cmd;		// Ŀ�ǵ带 �Է� ���� ��ü;
	while (cmd != "exit") {
		cin >> cmd;
		if (cmd == "insert") {		// insert
			MyString name, country, job;
			int age;
			cin >> name >> age >> country>> job;
			if (crr >= 10) {		// ���� ó��
				cout << "�ִ� 10���� ����ڸ� ������ �� �ֽ��ϴ�." << endl;
			}
			else {
				employees[crr++].change(name, age, country, job);
			}
			cin.ignore(100, '\n');		// ���� ����
			cin.clear();				// ���� �ʱ�ȭ
		}
		else if (cmd == "find") {		// find
			MyString name;
			cin >> name;
			cout << "=====find=====" << endl;
			for (size_t idx = 0; idx < crr; idx++) {	
				if (employees[idx].isNameCorrect(name)) {	// ã�� �̸��� �´ٸ�
					employees[idx].print();		// ����Ѵ�
					break;
				}
			}
			cin.ignore(100, '\n');
			cin.clear();
		}
		else if (cmd == "change") {		// change
			MyString name1, name2, country, job;
			int age = 0;
			cin >> name1 >> name2 >> age >> country >> job;
			for (size_t idx = 0; idx < crr; idx++) {
				if (employees[idx].isNameCorrect(name1)) {		// ã�� �̸��� �´ٸ�
					employees[idx].change(name2, age, country, job);	// �ٲ۴�
					break;
				}
			}
			cin.ignore(100, '\n');
			cin.clear();
		}
		else if (cmd == "print") {		// print
			cout << "=====print=====" << endl;
			for (size_t idx = 0; idx < crr; idx++) {
				employees[idx].print();		// crr �� °���� ��� ��� ���
			}
			cin.ignore(100, '\n');
			cin.clear();
		}
	}
	return 0;
}