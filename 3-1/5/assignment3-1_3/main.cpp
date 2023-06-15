#include "Queue.h"
#include <iostream>

using namespace std;

int str_compare(const char* str1, const char* str2);        //�� ���ڿ��� ��ġ�ϴ��� �˻��ϴ� �Լ�

int main(void) {
	Queue queue;              //Queue
	Node* node;               //���� �߰��� Node
	Node* popNode;            //��� ���� �� ��ȯ�� ��
	char command[20];         //��ɾ�
	int key;                  //��忡 ������ ��
	int size;                 //queue�� ũ��

	//queue�� size ����
	cout << "Size of Queue: ";
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

			//��忡 key �߰�
			node->SetData(key);

			//Queue�� ���� ���� ��� �߰�
			if (!queue.Push(node)) {
				cout << "Queue is full." << endl;  //queue�� ���� �� ��� ���̻� ���ο� ��带 ������ �� ���ٴ� �޽��� ���
			}
		}
		else if (!str_compare(command, "Pop")) {         //Pop �Է� : ��� ����
			popNode = queue.Pop();       //��� ����

			if (popNode != nullptr) {
				cout << popNode->GetData() << endl;  //������ ��� ���
				delete popNode;              //��� �޸� ����
			}
			else {
				cout << "Queue is Empty." << endl;    //queue�� ����ִ� ��� ������ ��尡 ���ٴ� �޽��� ���
			}
		}
		else if (!str_compare(command, "IsEmpty")) {     //IsEMpty �Է� : Queue�� ����ִ� �������� �ƴ��� ���
			if (queue.IsEmpty()) {
				cout << "1 (Empty)" << endl;      //����ִ� ���
			}
			else {
				cout << "0 (Not Empty)" << endl;  //������� ���� ���
			}
		}
		else if (!str_compare(command, "IsFull")) {      //IsFull �Է� : Queue�� ���� �� �ִ� �������� �ƴ��� ���
			if (queue.IsFull()) {
				cout << "1 (Full)" << endl;      //���� �� ���
			}
			else {
				cout << "0 (Not Full)" << endl;  //���� ���� ���� ���
			}
		}
		else if (!str_compare(command, "PrintQueue")) {  //PrintQueue �Է� : Queue�� ��� ����� data ���
			queue.PrintQueue();
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