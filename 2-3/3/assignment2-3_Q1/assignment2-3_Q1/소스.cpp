#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Employee//직원 클래스 선언
{
private:
    char* name;//이름
    int age;//나이
    char* country;//국적
    char* job;//직업

public:
    Employee(char* name, int age, char* country, char* job);//생성자
    ~Employee();//소멸자
    bool isNameCorrect(char* name);//이름 동일 유무 확인
    void print();//직원 정보 출력
    void change(char* name, int age, char* country, char* job);//직원 정보 변경
};

Employee::Employee(char* name, int age, char* country, char* job) {//생성자
    this->name = new char[strlen(name) + 1];//name길이만큼 동적할당
    strcpy(this->name, name);//name 복사
    this->age = age;
    this->country = new char[strlen(country) + 1];//country길이만큼 동적할당
    strcpy(this->country, country);//country 복사
    this->job = new char[strlen(job) + 1];//job길이만큼 동적할당
    strcpy(this->job, job);//job 복사
}

Employee::~Employee() {
    delete name;//동적할당 해제
    delete country;
    delete job;
}

bool Employee::isNameCorrect(char* name) {//이름 동일 유무 확인
    if (strcmp(this->name, name) == 0)//이름 동일
        return true;//참 반환
    else//이름 동일 X
        return false;//거짓 반환
}

void Employee::print() {//출력
    cout << "Name : " << this->name << endl;
    cout << "Age : " << this->age << endl;
    cout << "Country : " << this->country << endl;
    cout << "Job : " << this->job << endl;
    cout << "----------" << endl;
}

void Employee::change(char* name, int age, char* country, char* job) {//직원 정보 변경
    delete[] this->name;//기존 정보 동적할당 해제
    delete[] this->country;
    delete[] this->job;

    this->name = new char[strlen(name) + 1];//name길이만큼 동적할당
    strcpy(this->name, name);//name 복사
    this->age = age;
    this->country = new char[strlen(country) + 1];//country길이만큼 동적할당
    strcpy(this->country, country);//country 복사
    this->job = new char[strlen(job) + 1];//job길이만큼 동적할당
    strcpy(this->job, job);//job 복사
}

int main() {
    Employee* employee[10]{};// 최대 10명 저장

    char input[100]{};//input 입력
    char name_i[100]{};//이름
    char temp_name[100]{};//변경할 이름
    int age_i = 0;//나이
    char country_i[100]{};//국적
    char job_i[100]{};//직업
    int i = 0;//직원 정보 숫자

    while (1) {
        cin >> input;//input 입력

        if (strcmp(input, "insert") == 0) {//insert일 때
            if (i < 10) {//10명 이하일 때
                cin >> name_i >> age_i >> country_i >> job_i;//직원 정보 입력
                employee[i] = new Employee(name_i, age_i, country_i, job_i);//저장
                i++;//직원 정보 숫자++
            }
            else//10명 초과일 때
                break;
        }
        else if (strcmp(input, "find") == 0) {//find일 때
            cin >> name_i;//찾을 직원 이름 입력
            for (int j = 0; j < i; j++) {
                if (employee[j]->isNameCorrect(name_i) == true) {//동일 직원 이름 존재할 때
                    cout << "=====find=====" << endl;
                    employee[j]->print();//해당 직원 정보 출력
                    break;
                }
                else//동일 직원 이름 존재 X
                    continue;
            }
        }
        else if (strcmp(input, "change") == 0) {//change일 때
            cin >> name_i >> temp_name >> age_i >> country_i >> job_i;//변경할 직원 이름, 변경될 직원 정보 입력
            for (int j = 0; j < i; j++) {
                if (employee[j]->isNameCorrect(name_i) == true) {//동일 이름 직원 존재할 때
                    employee[j]->change(temp_name, age_i, country_i, job_i);//정보 변경
                    break;
                }
            }
        }
        else if (strcmp(input, "print") == 0) {//직원 정보 전체 출력
            cout << "=====print=====" << endl;
            for (int j = 0; j < i; j++)//직원 수만큼 출력
                employee[j]->print();
        }
        else if (strcmp(input, "exit") == 0)//exit일 때
            break;//while문 탈출
        else
            continue;
    }
    for (int j = 0; j < i; j++)//동적할당 해제
        delete employee[j];

    return 0;
}