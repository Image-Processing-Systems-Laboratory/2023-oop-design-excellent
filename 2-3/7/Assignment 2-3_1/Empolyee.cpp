#include "Empolyee.h"

Empolyee::Empolyee() :age(0), name{ NULL }, country{ NULL }, job{ NULL } {} //�⺻ ������

Empolyee::Empolyee(char* name, int age, char* country, char* job) { //�����ڿ��� �ʱ�ȭ
	/*���ڿ����� �����Ҵ� �� ����*/
	this->name = new char[strlen(name) + 1]; 
	strcpy(this->name, name); 

	this->age = age;

	this->country = new char[strlen(country) + 1];
	strcpy(this->country, country);

	this->job = new char[strlen(job) + 1];
	strcpy(this->job, job);
}

bool Empolyee::isNameCorrect(char* name) { //�˻��� �̸����� ��ġ �˻�
	if (strcmp(this->name, name)==0) //��ġ�� ��
		return 1;
	else
		return 0;
}

void Empolyee::print() { //���� ���
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Country: " << country << endl;
	cout << "Job: " << job << endl;
	cout << "----------" << endl;
}

void Empolyee::change(char* name, int age, char* country, char* job) { //���� ����
	/*������ �����ϴ� ���̱� ������ ���� �Ҵ� ���� �ٷ� �����Ŵ*/
	strcpy(this->name, name);
	this->age = age;
	strcpy(this->country, country);
	strcpy(this->job, job);
}

