#include <iostream>
#include "MyString.h"		// string을 구현
#include "Employee.h"		// Employee 클래스 구현

using namespace std;

int main() {
	Employee employees[10];	// 최대 10명까지 저장할 수 있는 배열
	size_t crr = 0;		// 배열의 마지막 + 1 요소를 가리킬 커서
	MyString cmd;		// 커맨드를 입력 받을 객체;
	while (cmd != "exit") {
		cin >> cmd;
		if (cmd == "insert") {		// insert
			MyString name, country, job;
			int age;
			cin >> name >> age >> country>> job;
			if (crr >= 10) {		// 예외 처리
				cout << "최대 10명의 고용자만 저장할 수 있습니다." << endl;
			}
			else {
				employees[crr++].change(name, age, country, job);
			}
			cin.ignore(100, '\n');		// 버퍼 비우기
			cin.clear();				// 버퍼 초기화
		}
		else if (cmd == "find") {		// find
			MyString name;
			cin >> name;
			cout << "=====find=====" << endl;
			for (size_t idx = 0; idx < crr; idx++) {	
				if (employees[idx].isNameCorrect(name)) {	// 찾는 이름이 맞다면
					employees[idx].print();		// 출력한다
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
				if (employees[idx].isNameCorrect(name1)) {		// 찾는 이름이 맞다면
					employees[idx].change(name2, age, country, job);	// 바꾼다
					break;
				}
			}
			cin.ignore(100, '\n');
			cin.clear();
		}
		else if (cmd == "print") {		// print
			cout << "=====print=====" << endl;
			for (size_t idx = 0; idx < crr; idx++) {
				employees[idx].print();		// crr 번 째까지 모든 요소 출력
			}
			cin.ignore(100, '\n');
			cin.clear();
		}
	}
	return 0;
}