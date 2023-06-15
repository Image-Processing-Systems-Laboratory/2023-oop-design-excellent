//2022202040 ���켺
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Stack.h"

int main()
{
	int size, data; // size: ������ �ִ� ������ / data: ����� key��
	// ������ �ִ� ������ �Է�
	std::cout << "Input size: ";
	std::cin >> size;

	//������ ��ü �����ϰ� ������ ����
	Stack stack;
	stack.SetSize(size);

	char command[100]; //��ɾ� �Է¹��� ���ڿ� 
	do
	{
		std::cin >> command;
		if (strcmp(command, "push") == 0) { // push �Է¹޾��� ��
			if (stack.IsFull() == true) { // ������ �� �������� ���� ��� �� �ݺ��� �ٽ� ����
				std::cout << "Full stack." << std::endl;
				continue;
			}
			std::cin >> data; // ����� key�� �Է¹���
			Node* mnode = new Node; //��� ����
			mnode->SetData(data); //����� key�� ����
			mnode->SetNext(nullptr); //����� ��ũ�� ����
			stack.Push(mnode); // push
		}
		if (strcmp(command, "full") == 0) { //full �Է¹޾��� ��
			if (stack.IsFull() == true) //�� �������� "True." ���
				std::cout << "True." << std::endl;
			else // �� ������ ������ "False." ���
				std::cout << "False." << std::endl;
		}
		if (strcmp(command, "empty") == 0) { //empty �Է¹޾��� ��
			if (stack.IsEmpty() == true) // ��������� "True." ���
				std::cout << "True." << std::endl;
			else // ������� ������ "False." ���
				std::cout << "False." << std::endl;;
		}
		if (strcmp(command, "pop") == 0) { //pop �Է¹޾�����
			if (stack.IsEmpty() == true) { // ������ ����ִٸ� "Empty stack." ��� �� �ݺ��� �ٽ� ����
				std::cout << "Empty stack." << std::endl;
				continue;
			}
			std::cout << stack.Pop()->GetData() << std::endl; //ù ��� ���� �� �� ����� key�� ���
		}
		if (strcmp(command, "print") == 0) { //print �Է¹޾��� ��
			stack.PrintStack(); // ���ÿ� �ִ� ��� ������ key�� ���
		}
	} while (strcmp(command, "exit") != 0); //exit �Է¹����� �ݺ��� ����

	return 0;
}