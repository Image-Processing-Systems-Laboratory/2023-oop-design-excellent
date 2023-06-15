#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int str_compare(const char* str1, const char* str2);    //�� ���ڿ��� ��ġ�ϴ��� �˻��ϴ� �Լ�

int main(void)
{
	StudentScoreList List;

	char command[32];               //��ɾ �ӽ� ������ �迭
	double Math, English, Science;  //Math, English, Science ���� ����
	double average;                 //���

	while (1) {
		cout << ">>";
		cin >> command;    //��� �Է�

		if (!str_compare(command, "Insert")) {             //���ο� ��� �߰�
			cin >> Math >> English >> Science;          //���� �Է�
			average = (Math + English + Science) / 3;   //��� ���
			cout << "average: " << average << endl;     //��� ���

			Score* pNew = new Score;                    //���ο� ��� ���� �Ҵ�
			pNew->SetAvg(average);                      //��� �� ����
			List.Insert(pNew);                          //Student Score List�� �߰�
		}
		else if (!str_compare(command, "PrintList")) {     //Student Score List ���
			cin >> command;                             //�������� �Ǵ� �������� ��� �Է�

			if (!str_compare(command, "Ascending")) {  //���������� ��� true�� ���ڷ� �����Ͽ� PrintList �Լ� ȣ��
				List.PrintList(true);
			}
			else if (!str_compare(command, "Descending")) {  //���������� ��� false�� ���ڷ� �����Ͽ� PrintList �Լ� ȣ��
				List.PrintList(false);
			}
			else {
				cout << "Invalid command." << endl;    //�߸��� ����� �Է��Ͽ��� �� ���� �޽��� ���
			}
		}
		else if (!str_compare(command, "Exit")) {          //�ݺ��� Ż�� -> ���α׷� ����
			break;
		}
		else {                                             //�߸��� ����� �Է��Ͽ��� �� ���� �޽��� ���
			cout << "Invalid command." << endl;
		}
	}

	return 0;
}

//�� ���ڿ��� ��ġ�ϴ��� �˻��ϴ� �Լ�
int str_compare(const char* str1, const char* str2) {
	int i = 0;

	while (1) {
		if (str1[i] != str2[i] || (str1[i] == '\0' && str2[i] == '\0')) {  //���ڿ��� �����ų� ���� ���� ���ڸ� ���� ������ �ݺ�
			if (str1[i] > str2[i]) {        //str1[i]�� �ƽ�Ű�ڵ� ���� str2[i]���� ū ��� 1 ��ȯ
				return 1;
			}
			else if (str1[i] < str2[i]) {    //str2[i]�� �ƽ�Ű�ڵ� ���� str1[i]���� ū ��� -1 ��ȯ
				return -1;
			}
			else {                          //���� ���ڿ��̸� 0 ��ȯ
				return 0;
			}

		}

		i++;
	}
}