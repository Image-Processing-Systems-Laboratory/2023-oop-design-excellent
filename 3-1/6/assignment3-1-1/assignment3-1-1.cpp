//2022202040 ���켺

#include <iostream>
#include "Node.h"

int main()
{

	char c;
	char input1[100]; 
	LinkedList* p1 = new LinkedList; //����Ʈ p1 ����

	// p1�� ������ key�� �Է¹ޱ�
	std::cout << "Input>> " << std::endl;
	std::cout << "Input list 1: ";
	// ���� ���� �Է¹��� ������ �Է¹���
	while (1)
	{
		std::cin >> input1;
		p1->add(input1);
		if ((c = getchar()) == '\n')
			break;
	}

	//p1 ���� ����� �ƴ��� Ȯ���ϱ� ����
	/*std::cout << "p1: ";
	p1->print();*/
	
	char input2[100];
	LinkedList* p2 = new LinkedList; //����ũ p2 ����
	std::cout << "Input list 2: ";
	//���� ���� �Է¹��� ������ �Է¹���
	while (1)
	{
		std::cin >> input1;
		p2->add(input1);
		if ((c = getchar()) == '\n')
			break;
	}

	//p2 ���� ����� �ƴ��� Ȯ���ϱ� ����
	/*std::cout << "p2: ";
	p2->print();*/
	

	LinkedList* p3 = new LinkedList; //����Ʈ p3 ����
	p3->compare(p1, p2, p3); // p1�� p2 ���� p3�� ����
	//p3 ���
	std::cout << std::endl << "Output>>" << std::endl;
	p3->print();
	
	//p1�� p2�� ���� ��� ���� �ƴ��� Ȯ��
	/*std::cout <<std::endl<< "p1: ";
	p1->nullcheck();
	std::cout << "p2: ";
	p2->nullcheck();*/
	
	//�޸� ����
	delete p1;
	delete p2;
	delete p3;

	return 0;
}

