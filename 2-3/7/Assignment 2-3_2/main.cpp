#include "class.h"

int main()
{
	string str;
	char name[10] = {};
	int age = 0;
	char class_name[30] = {};
	char s_class[30] = {};  //�й� �˻���
	int n = 0; //��ü �迭 ������ �����

	School list; //Ŭ���� ��ü ����


	while (1) { //exit �Է� ������ �ݺ�
		cin >> str;
		if (str == "new_student") { //�л� ���� �߰�
			cin >> name >> age >> class_name;
			list.new_student(name, age, class_name);
		}
		if (str == "print_all") { //��� ���� ���
			list.print_all();
			cout << endl;
		}
		if (str == "print_class") { //�ش� �й� ���� ���
			cin >> s_class; 
			cout << "=====print_class=====" << endl;
			n = list.showSize(); //��ü �迭 ������ �ҷ���
			int no = 0, yes = 0; //�̸� ����ġ, ��ġ Ƚ�� �� ����
			for (int i = 0; i < n; i++) {
				if (list.Class_correct(s_class, i) == 1) { //��ġ�� ��
					list.print_class(i);
					yes++;
				}
				else
					no++;
			}
			if (no == n) //�ش� �̸��� ���� ���
				cout << "�˻� ����� �����ϴ�." << endl;
			cout << "Number of classmates : " << yes << endl;
			cout << endl;
		}
		if (str == "sort_by_name") { //�̸� �� ����
			list.sort_by_name();
		}
		if (str == "exit") { //����
			break;
		}
	}
	return 0;
}