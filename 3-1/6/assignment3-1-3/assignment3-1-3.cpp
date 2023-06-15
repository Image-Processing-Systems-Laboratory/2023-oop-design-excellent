//2022202040 ���켺
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Queue.h"

int main()
{
	int size, data; // size: ť�� �ִ� ������ / data: ����� key��
	// ť�� �ִ� ������ �Է�
	std::cout << "Input size: ";
	std::cin>> size;

	//ť�� ��ü �����ϰ� ������ ����
	Queue queue;
	queue.SetSize(size);

	char command[100]; //��ɾ� �Է¹��� ���ڿ� 
	do
	{
		std::cin >> command; 
		if (strcmp(command, "push")==0) { // push �Է¹޾��� ��
			if (queue.IsFull() == true) { // ť�� �� �������� ���� ��� �� �ݺ��� �ٽ� ����
				std::cout << "Full Queue." << std::endl;
				continue;
			}
			std::cin >> data; // ����� key�� �Է¹���
			Node* mnode = new Node; //��� ����
			mnode->SetData(data); //����� key�� ����
			mnode->SetNext(nullptr); //����� ��ũ�� ����
			queue.Push(mnode); // push
		}
		if (strcmp(command, "full") == 0) { //full �Է¹޾��� ��
			if (queue.IsFull() == true) //�� �������� "True." ���
				std::cout << "True." << std::endl;
			else // �� ������ ������ "False." ���
				std::cout << "False." << std::endl;
		}
		if (strcmp(command, "empty") == 0) { //empty �Է¹޾��� ��
			if (queue.IsEmpty() == true) // ��������� "True." ���
				std::cout << "True." << std::endl;
			else // ������� ������ "False." ���
				std::cout << "False."<<std::endl;;
		}
		if (strcmp(command, "pop") == 0) { //pop �Է¹޾�����
			if (queue.IsEmpty() == true) {  // ť�� ����ִٸ� "Empty queue."��� �� �ݺ��� �ٽ� ����
				std::cout << "Empty Queue." << std::endl;
				continue;
			}
			std::cout << queue.Pop()->GetData() << std::endl; //ù ��� ���� �� �� ����� key�� ���
		}
		if (strcmp(command, "print") == 0) { //print �Է¹޾��� ��
			queue.PrintQueue(); // ť�� �ִ� ��� ������ key�� �߷�
		}
	} while (strcmp(command, "exit") != 0); //exit �Է¹����� �ݺ��� ����

	return 0;
}