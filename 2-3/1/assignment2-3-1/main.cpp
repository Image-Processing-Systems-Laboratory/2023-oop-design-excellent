#include"Employee.h"
#include<iostream>

int main(){
	Employee* employee[10];
	int num = 0; // insert된 employee 수
	
	char command[10];
	char name[100];
	int age;
	char country[100];
	char job[100];

	while (1) {
		cin >> command;
		if (!strcmp(command, "insert")) {
			/* 이미 10명의 employee가 존재하면*/
			if (num == 10) {
				cout << "already 10 employees exist" << endl;
				while (getchar() != '\n') {} // 버퍼 비우기
				continue;
			}
			cin >> name >> age >> country >> job;
			employee[num] = new Employee(name, age, country, job);
			num++;
		}
		else if (!strcmp(command, "find")) {
			cout << "=====find=====" << endl;
			cin >> name;
			int i;
			for (i = 0; i < num; i++) {
				/* name이라는 이름을 가진 employee가 존재하면*/
				if (employee[i]->isNameCorret(name)) {
					employee[i]->print(); //출력
					cout << "----------" << endl;
					break;
				}
			}
			/* 찾으려는 이름을 가진 사람이 없을 때*/
			if (i == num) {
				cout << "No one has a name like " << name << endl;
			}
		}
		else if (!strcmp(command, "change")) {
			cin >> name;

			/* 바꾸려는 이름의 대상을 찾기*/
			int i;
			for (i = 0; i < num; i++) {
				if (employee[i]->isNameCorret(name))
					break;
			}
			
			/* 바꾸려는 대상이 존재하지 않으면*/
			if (i == num){
				cout << "No one has a name like " << name << endl;
				while (getchar() != '\n') {} // 버퍼 비우기
				continue;
			}
			/* 존재하면*/
			else{
				cin >> name >> age >> country >> job;
				employee[i]->change(name, age, country, job);
			}
		}
		else if (!strcmp(command, "print")) {
			cout << "=====print=====" << endl;
			if (num == 0)
				cout << "No employees exist" << endl;
			for (int i = 0; i < num; i++){
				employee[i]->print();
				cout << "----------" << endl;
			}
		}
		else if (!strcmp(command, "exit")) {
			break;
		}
		else{
			cout << "Wrong command. Try again." << endl;
			while (getchar() != '\n') {} // 버퍼 비우기
		}
	}
	
	delete[]employee;
	delete[]command;
	delete[]name;
	delete[]country;
	delete[]job;
	return 0;
}

