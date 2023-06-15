#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

int main(void) {
	int stack[128] = { 0 };
	int stackIndex = 0;
	bool isEmpty = true;
	while (stackIndex < 128) {
		/*command �Է�*/
		char input[100] = { 0 };
		cin >> input;
		int num = 0;
		/*command�� exit�̸� break;*/
		if (strcmp(input, "exit") == 0) {
			break;
		}
		/*command�� push�� num�� �Է¹ް� stack�迭�� num�� ������*/
		else if (strcmp(input, "push") == 0) {
			cin >> num;
			stack[stackIndex++] = num;
			isEmpty = false;	//stack�� ����� Ȯ���ϴ� ����
		}
		/*command�� print�� ���*/
		else if (strcmp(input, "print") == 0) {
			for (int i = 0; i < stackIndex; i++) cout << stack[i] << ' ';
			cout << endl;
		}
		/*command�� pop�̸�*/
		else if (strcmp(input, "pop") == 0) {
			/*stack�� ��������� isEmpty�� true�� �ְ� continue;*/
			if (stackIndex == 0) {
				isEmpty = true;
				continue;
			}
			/*stackIndex ���̳ʽ� 1*/
			stackIndex -= 1;
			/*�� �ε����� �ִ� �迭�� �����*/
			cout << stack[stackIndex];
			stack[stackIndex] = '\0';
			if (stackIndex == 0) isEmpty = true;
			cout << endl;
		}
		/*command�� top�̸�*/
		else if (strcmp(input, "top") == 0) {
			/*����ִ� �迭�̸� continue*/
			if (stackIndex == 0) continue;
			/*���� ���� ���� �����*/
			else cout << stack[stackIndex - 1];
			cout << endl;
		}
		/*command�� empty��*/
		else if (strcmp(input, "empty") == 0) {
			/*��������� 1���*/
			if (isEmpty) cout << 1;
			/*�Ⱥ�������� 0���*/
			else cout << 0;
			cout << endl;
		}
		/*�̻��Ѱ� �Է����� �� */
		else {
			cout << "Enter the given input ! ";
			cout << endl;
		}
	}
	return 0;
}