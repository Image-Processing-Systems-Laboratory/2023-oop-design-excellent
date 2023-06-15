#include"mylinkedlist.h"

Node* Merge_List(Node* p1, Node* p2, Node** p3)
{
	mylinkedlist* result = new mylinkedlist;

	// �� ����Ʈ ��� ��Ұ� �ִ� ���
	// �����͸� ���� ���� ���� �߰��ϰ� �� ����Ʈ�� �������� �ѱ��.
	while (p1 != nullptr && p2 != nullptr)
	{
		if (strcasecmp(p1->getData(), p2->getData()) > 0)
		{
			result->push_back(p2->getData());
			p2 = p2->getNext();
		}
		else
		{
			result->push_back(p1->getData());
			p1 = p1->getNext();
		}
	}

	// �񱳰� ���� �� ���� ��Ҹ� �����ش�.
	while (p1 != nullptr)
	{
		result->push_back(p1->getData());
		p1 = p1->getNext();
	}

	while (p2 != nullptr)
	{
		result->push_back(p2->getData());
		p2 = p2->getNext();
	}

	// ��� ���
	cout << "Result: ";
	result->printlist();

	// p3�� ������ ���� ȣ��� �޾����Ƿ� �����͸� �������ش�.
	*p3 = result->getHead();
	return result->getHead();
}

int main(void)
{
	mylinkedlist m1;
	mylinkedlist m2;
	char input[2048];
	char* token;

	// ����Ʈ1 �Է�
	cout << "Input list 1: ";
	cin.getline(input, 2048);

	// ����Ʈ1�� �ڷ� �Է�
	token = strtok(input, " ");
	while (token != NULL)
	{
		m1.push_back(token);
		token = strtok(NULL, " ");
	}
	
	// ����Ʈ2 �Է�
	cout << "Input list 2: ";
	cin.getline(input, 2048);

	// ����Ʈ2�� �ڷ� �Է�
	token = strtok(input, " ");
	while (token != NULL)
	{
		m2.push_back(token);
		token = strtok(NULL, " ");
	}

	// ����Ʈ1, ����Ʈ2 ���� �� ��� ���
	m1.sortlist();
	m2.sortlist();
	Node* p3 = nullptr;
	Merge_List(m1.getHead(), m2.getHead(), &p3);
	
	return 0;
}