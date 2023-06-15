#include <iostream>
#include <string>

class Node {

public:

	std::string data;
	Node* next;

	Node();
	Node(std::string data);

	void insert(std::string data);
	void sortList();
	void printList();
};

//////////////////////////////////////////////////////////////////////////////////////////

void inputList(Node& node);
int strcasecmp(const std::string& s1, const std::string& s2);
void Merge_List(Node* p1, Node* p2, Node* p3);

//////////////////////////////////////////////////////////////////////////////////////////

Node::Node()
{
	this->data = "";		// ����ִ� string���� �ʱ�ȭ
	this->next = nullptr;	// ����Ű�� ���� ���� nullptr
}

Node::Node(std::string data)
{
	this->data = data;		// string�� data�� �ʱ�ȭ
	this->next = nullptr;	// ����Ű�� ���� ���� ���� nullptr
}

//////////////////////////////////////////////////////////////////////////////////////////

void Node::insert(std::string data)
{
	if (this->data == "")	// ����ִ� string�̶�� data�� �ʱ�ȭ
	{
		this->data = data;
	}

	else
	{
		Node* temp = this;

		while (temp->next != nullptr)
		{
			temp = temp->next;			// ���� ������ ���� ��尡 nullptr�϶�����(������) ���� 
		}

		temp->next = new Node(data);	// �� ��忡�� data�� ���� ���ο� ��� �߰�
	}
}

void Node::sortList()
{
	Node* current = this;	// ������ ���� ��� ����Ʈ
	Node* compare;			// ������ ���� ������ ��� ����Ʈ

	std::string temp;	// string temp

	while (current != nullptr) 
	{
		compare = current->next;	// ���� ���� ���� ����� ���� ��带 ����Ų��

		while (compare != nullptr) 
		{
			if (strcasecmp(current->data, compare->data) > 0) // ���� �����Ͱ� ���� �� �����ͺ��� ũ�ٸ�(�� ���� ���ĺ�)
			{
				temp = current->data;
				current->data = compare->data;
				compare->data = temp;
			}
			compare = compare->next;// ���� ����� ���� ��带 �ҷ��´�
		}
		current = current->next;	// ���� ����� ���� ��带 �ҷ��´�	(�ڼ��� ���̾�׷��� ������)
	}
}

void Node::printList()
{
	Node* temp = this;

	while (temp != nullptr)		// ���� ������ ���� ��尡 nullptr�϶�����(������) ���� 
	{
		std::cout << temp->data << " ";	// data�� ���
		temp = temp->next;
	}

	std::cout << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////

void inputList(Node& node)
{
	std::string word;
	char c;

	while (std::cin.get(c))	// �Է��� loop
	{
		if (c == ' ' || c == '\n')
		{
			if (!word.empty())		// ' ' ���� ���ڰ� ���� ���, �ܾ ������� �ʴٸ�
			{
				node.insert(word);	// ��忡 �ܾ ����
				word.clear();		// ���� loop, ���� �ܾ� �Է��� ���� clear
			}

			if (c == '\n')			// enter�� ���� ��� while���� �������� ����
				break;
		}
		else
			word.push_back(c);	// �̿��� ��� string(�ܾ�)�� ���� �ϳ��� �߰�
	}
}

int strcasecmp(const std::string& s1, const std::string& s2)
{
	for (int i = 0; i < s1.length() && i < s2.length(); i++)
	{
		char c1 = s1[i];
		char c2 = s2[i];

		if (c1 >= 'A' && c1 <= 'Z')	// �빮�ڸ� �ҹ��ڷ� ��ȯ
			c1 += 32;

		if (c2 >= 'A' && c2 <= 'Z')	// �빮�ڸ� �ҹ��ڷ� ��ȯ
			c2 += 32;

		if (c1 < c2)		// ������ ASCII ���� c2�� �� ũ�ٸ� -1 ��ȯ
			return -1;

		else if (c1 > c2)	// ������ ASCII ���� c1�� �� ũ�ٸ� 1 ��ȯ
			return 1;
	}

	if (s1.length() < s2.length())
		return -1;	// �� string�� ������ s2�� �� ��ٸ� -1 ��ȯ

	else if (s1.length() > s2.length())
		return 1;	// �� string�� ������ s1�� �� ��ٸ� 1 ��ȯ

	else
		return 0;	// ��� �����ϴ� ��� �� string�� ���� string.
}

void Merge_List(Node* p1, Node* p2, Node* p3)
{
	while (p1 != nullptr && p2 != nullptr) 
	{
		if (strcasecmp(p1->data, p2->data) <= 0)	// p1�� �����Ͱ� p2���� �۰ų� ���ٸ� (�� ���� ���ĺ�), p1�� ��带 p3�� ����
		{
			p3->insert(p1->data);
			p1 = p1->next;			// ���� p1 ���
		}
		else 
		{
			p3->insert(p2->data);					// p2�� �����Ͱ� p1���� �۴ٸ� (�� ���� ���ĺ�), p2�� ��带 p3�� ����
			p2 = p2->next;			// ���� p2 ���
		}
	}

	while (p1 != nullptr)		// p1�� ���� ��带 p3�� ����
	{
		p3->insert(p1->data);
		p1 = p1->next;			// ���� p1 ���
	}

	while (p2 != nullptr)		// p2�� ���� ��带 p3�� ����
	{
		p3->insert(p2->data);
		p2 = p2->next;			// ���� p2 ���
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	Node p1, p2, p3;

	std::cout << "Input>>" << std::endl;
	std::cout << "Input list 1: ";			// ù��° ����
	inputList(p1);

	std::cout << "Input list 2: ";			// �ι�° ����
	inputList(p2);

	p1.sortList();	// ������ sort
	p2.sortList();	// ������ sort

	Merge_List(&p1, &p2, &p3);	// ���ĵ� �� ������ merge

	std::cout << std::endl << "Output>>" << std::endl << "Result: ";
	p3.printList();	// merge�� ������ ���

	return 0;
}