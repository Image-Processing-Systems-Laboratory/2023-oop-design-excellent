#include "Stack.h"
#include <iostream>

using namespace std;

int str_compare(const char* str1, const char* str2);      //�� ���ڿ��� ��ġ�ϴ��� �˻��ϴ� �Լ�

int main(void) {
	Stack queue;              //Stack
	Node* node;               //���� �߰��� Node
	Node* popNode;            //��� ���� �� ��ȯ�� ��
	char command[20];         //��ɾ�
	int key;                  //��忡 ������ ��
	int size;                 //Stack�� ũ��

	//Stack�� size ����
	cout << "Size of Stack: ";
	cin >> size;
	queue.SetSize(size);
	cout << "=================================" << endl;

	//command �Է�
	while (1) {
		cout << ">> ";
		cin >> command;

		if (!str_compare(command, "Push")) {             //Push �Է� : ���ο� ��� �߰�
			cin >> key;

			node = new Node;            //���ο� ��� �����Ҵ�

			//key�� ��忡 ����
			node->SetData(key);

			//Stack�� ���� ���� ��� �߰�
			if (!queue.Push(node)) {
				cout << "Stack is full." << endl;  //Stack�� ���� �� ��� ���̻� ���ο� ��带 ������ �� ���ٴ� �޽��� ���
			}
		}
		else if (!str_compare(command, "Pop")) {         //Pop �Է� : ��� ����
			popNode = queue.Pop();       //��� ����

			if (popNode != nullptr) {
				cout << popNode->GetData() << endl;  //������ ��� ���
				delete popNode;              //��� �޸� ����
			}
			else {
				cout << "Stack is Empty." << endl;    //Stack�� ����ִ� ��� ������ ��尡 ���ٴ� �޽��� ���
			}
		}
		else if (!str_compare(command, "IsEmpty")) {     //IsEmpty �Է� : Stack�� ����ִ� �������� �ƴ��� ���
			if (queue.IsEmpty()) {
				cout << "1 (Empty)" << endl;      //����ִ� ���
			}
			else {
				cout << "0 (Not Empty)" << endl;  //������� ���� ���
			}
		}
		else if (!str_compare(command, "IsFull")) {      //IsFull �Է� : Stack�� ���� �� �ִ� �������� �ƴ��� ���
			if (queue.IsFull()) {
				cout << "1 (Full)" << endl;      //���� �� ���
			}
			else {
				cout << "0 (Not Full)" << endl;  //���� ���� ���� ���
			}
		}
		else if (!str_compare(command, "PrintStack")) {  //PrintStack �Է� : Stack�� ��� ����� data ���
			queue.PrintStack();
		}
		else if (!str_compare(command, "Exit")) {        //Exit �Է� : �ݺ��� ���� -> ���α׷� ����
			break;
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