#define _CRT_SECURE_NO_WARNINGS
#include "Empolyee.h"

int main()
{
	string str; //��ɾ�

	char name[10]={};
	int age=0;
	char country[100]={};
	char job[100]={};

	char s_name[10] = {}; //�˻��� �̸�
	char c_name[10] = {}; //������ �̸�

	Empolyee emp[10]; //Ŭ���� ��ü �迭 ����


	int num = 0;
	while (1) { //exit �Է� ������ �ݺ�
		cin >> str;
		if (str=="insert") { //���� �߰� ����
			cin >> name >> age >> country >> job;
			emp[num++]=Empolyee(name, age, country, job);
			
		}
		if (str=="print") { //�� ���
			cout << "=====print=====" << endl;
			for (int i = 0; i < num; i++) {
				emp[i].print();
			}
			cout << endl;
		}
		if (str == "find") { //�˻�
			cin >> s_name;
			int no = 0; //�̸� ����ġ ����
			for (int i = 0; i < num; i++) {
				if (emp[i].isNameCorrect(s_name) == 1) { //�̸� ��ġ �˻�
					cout << "=====find=====" << endl;
					emp[i].print(); //�ش� ���� ���
				}
				else
					no++;
			}
			if (no == num) { //�˻��� �̸��� ���� ���
				cout << "�˻� ����� �����ϴ�." << endl;
			}
			cout << endl;
		}
		if (str == "change") { //���� ����
			cin >> c_name >> name >> age >> country >> job;
			for (int i = 0; i < num; i++) {
				if (emp[i].isNameCorrect(c_name) == 1) { //�̸� ��ġ �˻�
					emp[i].change(name, age, country, job); //���� ���� ����
				}
			}
		}
		if (str=="exit") { //����
			break;
		}
	}
	return 0;
}