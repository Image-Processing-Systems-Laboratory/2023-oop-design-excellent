#include "List.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	LinkedList List1, List2, List3;
	char ch;                       //����
	int index;                     //÷��
	char* str = new char[100];

	//List1 �Է¹ޱ�
	std::cout << "Input>>" << endl;
	std::cout << "Input list 1: ";
	do {
		index = 0;

		while(1) {
			ch = getchar();
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			str[index] = ch;
			index++;
		}

		str[index] = '\0';
		if (!List1.add(str))   //List1�� str�� key�� ���� ��� �߰�
		{
			//��� �߰� ������ ���(���� �Ҵ� ������ ���)
			free_LinkedList(List1.get_pHead());

			return 0;
		}

	} while (ch != '\n');

	//List2 �Է¹ޱ�
	std::cout << "Input list 2: ";
	do {
		index = 0;

		while (1) {
			ch = getchar();
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			str[index] = ch;
			index++;
		}

		str[index] = '\0';
		if (!List2.add(str))   //List2�� str�� key�� ���� ��� �߰�
		{
			//��� �߰� ������ ���(���� �Ҵ� ������ ���)
			free_LinkedList(List1.get_pHead());
			free_LinkedList(List2.get_pHead());

			return 0;
		}

	} while (ch != '\n');
	
	List3.set_pHead(Merge_List(List1.get_pHead(), List2.get_pHead(), List3.get_pHead()));    //List1�� List2�� �����ϸ� �����Ͽ� List3 ����
	
	if (List3.get_pHead() == nullptr)
	{
		return 0;                     //List 3 ���� ������ ���(�޸� �Ҵ� ����) ����
	}

	//List3 ���
	std::cout << "Output>>" << endl << "Result: ";
	List3.print();

	free_LinkedList(List3.get_pHead());  //List3 �޸� ����(List1�� List2�� Merge_List �������� �̹� �޸𸮰� �����Ǿ���.)

	delete[] str;

	return 0;
}