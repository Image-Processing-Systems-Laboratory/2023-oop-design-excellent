#include "Empolyee.h"

Empolyee::Empolyee() :age(0), name{ NULL }, country{ NULL }, job{ NULL } {} //기본 생성자

Empolyee::Empolyee(char* name, int age, char* country, char* job) { //생성자에서 초기화
	/*문자열들은 동적할당 후 복사*/
	this->name = new char[strlen(name) + 1]; 
	strcpy(this->name, name); 

	this->age = age;

	this->country = new char[strlen(country) + 1];
	strcpy(this->country, country);

	this->job = new char[strlen(job) + 1];
	strcpy(this->job, job);
}

bool Empolyee::isNameCorrect(char* name) { //검색할 이름과의 일치 검사
	if (strcmp(this->name, name)==0) //일치할 시
		return 1;
	else
		return 0;
}

void Empolyee::print() { //정보 출력
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Country: " << country << endl;
	cout << "Job: " << job << endl;
	cout << "----------" << endl;
}

void Empolyee::change(char* name, int age, char* country, char* job) { //정보 수정
	/*정보만 수정하는 것이기 때문에 따로 할당 없이 바로 복사시킴*/
	strcpy(this->name, name);
	this->age = age;
	strcpy(this->country, country);
	strcpy(this->job, job);
}

