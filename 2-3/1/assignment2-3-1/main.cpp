#include"Employee.h"
#include<iostream>

int main(){
	Employee* employee[10];
	int num = 0; // insert�� employee ��
	
	char command[10];
	char name[100];
	int age;
	char country[100];
	char job[100];

	while (1) {
		cin >> command;
		if (!strcmp(command, "insert")) {
			/* �̹� 10���� employee�� �����ϸ�*/
			if (num == 10) {
				cout << "already 10 employees exist" << endl;
				while (getchar() != '\n') {} // ���� ����
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
				/* name�̶�� �̸��� ���� employee�� �����ϸ�*/
				if (employee[i]->isNameCorret(name)) {
					employee[i]->print(); //���
					cout << "----------" << endl;
					break;
				}
			}
			/* ã������ �̸��� ���� ����� ���� ��*/
			if (i == num) {
				cout << "No one has a name like " << name << endl;
			}
		}
		else if (!strcmp(command, "change")) {
			cin >> name;

			/* �ٲٷ��� �̸��� ����� ã��*/
			int i;
			for (i = 0; i < num; i++) {
				if (employee[i]->isNameCorret(name))
					break;
			}
			
			/* �ٲٷ��� ����� �������� ������*/
			if (i == num){
				cout << "No one has a name like " << name << endl;
				while (getchar() != '\n') {} // ���� ����
				continue;
			}
			/* �����ϸ�*/
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
			while (getchar() != '\n') {} // ���� ����
		}
	}
	
	delete[]employee;
	delete[]command;
	delete[]name;
	delete[]country;
	delete[]job;
	return 0;
}

