#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Employee//���� Ŭ���� ����
{
private:
    char* name;//�̸�
    int age;//����
    char* country;//����
    char* job;//����

public:
    Employee(char* name, int age, char* country, char* job);//������
    ~Employee();//�Ҹ���
    bool isNameCorrect(char* name);//�̸� ���� ���� Ȯ��
    void print();//���� ���� ���
    void change(char* name, int age, char* country, char* job);//���� ���� ����
};

Employee::Employee(char* name, int age, char* country, char* job) {//������
    this->name = new char[strlen(name) + 1];//name���̸�ŭ �����Ҵ�
    strcpy(this->name, name);//name ����
    this->age = age;
    this->country = new char[strlen(country) + 1];//country���̸�ŭ �����Ҵ�
    strcpy(this->country, country);//country ����
    this->job = new char[strlen(job) + 1];//job���̸�ŭ �����Ҵ�
    strcpy(this->job, job);//job ����
}

Employee::~Employee() {
    delete name;//�����Ҵ� ����
    delete country;
    delete job;
}

bool Employee::isNameCorrect(char* name) {//�̸� ���� ���� Ȯ��
    if (strcmp(this->name, name) == 0)//�̸� ����
        return true;//�� ��ȯ
    else//�̸� ���� X
        return false;//���� ��ȯ
}

void Employee::print() {//���
    cout << "Name : " << this->name << endl;
    cout << "Age : " << this->age << endl;
    cout << "Country : " << this->country << endl;
    cout << "Job : " << this->job << endl;
    cout << "----------" << endl;
}

void Employee::change(char* name, int age, char* country, char* job) {//���� ���� ����
    delete[] this->name;//���� ���� �����Ҵ� ����
    delete[] this->country;
    delete[] this->job;

    this->name = new char[strlen(name) + 1];//name���̸�ŭ �����Ҵ�
    strcpy(this->name, name);//name ����
    this->age = age;
    this->country = new char[strlen(country) + 1];//country���̸�ŭ �����Ҵ�
    strcpy(this->country, country);//country ����
    this->job = new char[strlen(job) + 1];//job���̸�ŭ �����Ҵ�
    strcpy(this->job, job);//job ����
}

int main() {
    Employee* employee[10]{};// �ִ� 10�� ����

    char input[100]{};//input �Է�
    char name_i[100]{};//�̸�
    char temp_name[100]{};//������ �̸�
    int age_i = 0;//����
    char country_i[100]{};//����
    char job_i[100]{};//����
    int i = 0;//���� ���� ����

    while (1) {
        cin >> input;//input �Է�

        if (strcmp(input, "insert") == 0) {//insert�� ��
            if (i < 10) {//10�� ������ ��
                cin >> name_i >> age_i >> country_i >> job_i;//���� ���� �Է�
                employee[i] = new Employee(name_i, age_i, country_i, job_i);//����
                i++;//���� ���� ����++
            }
            else//10�� �ʰ��� ��
                break;
        }
        else if (strcmp(input, "find") == 0) {//find�� ��
            cin >> name_i;//ã�� ���� �̸� �Է�
            for (int j = 0; j < i; j++) {
                if (employee[j]->isNameCorrect(name_i) == true) {//���� ���� �̸� ������ ��
                    cout << "=====find=====" << endl;
                    employee[j]->print();//�ش� ���� ���� ���
                    break;
                }
                else//���� ���� �̸� ���� X
                    continue;
            }
        }
        else if (strcmp(input, "change") == 0) {//change�� ��
            cin >> name_i >> temp_name >> age_i >> country_i >> job_i;//������ ���� �̸�, ����� ���� ���� �Է�
            for (int j = 0; j < i; j++) {
                if (employee[j]->isNameCorrect(name_i) == true) {//���� �̸� ���� ������ ��
                    employee[j]->change(temp_name, age_i, country_i, job_i);//���� ����
                    break;
                }
            }
        }
        else if (strcmp(input, "print") == 0) {//���� ���� ��ü ���
            cout << "=====print=====" << endl;
            for (int j = 0; j < i; j++)//���� ����ŭ ���
                employee[j]->print();
        }
        else if (strcmp(input, "exit") == 0)//exit�� ��
            break;//while�� Ż��
        else
            continue;
    }
    for (int j = 0; j < i; j++)//�����Ҵ� ����
        delete employee[j];

    return 0;
}