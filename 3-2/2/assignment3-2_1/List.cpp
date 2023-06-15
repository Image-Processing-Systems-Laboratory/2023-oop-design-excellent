#include "List.h"
// Node �ʱ�ȭ
Node::Node() : data{0}, next(nullptr) {
}

Node::Node(int num) : data{num}, next(nullptr) {
}

int Node::getData() {
	return data;
}

Node* Node::getNext() {
	return next;
}

void Node::setNext(Node* next) {
	this->next = next;
}

// ������ �����ε�
Node& Node::operator=(int num) {
	data = num;
	return *this;
}
Node& Node::operator=(Node& other) {
	data = other.data;
	return *this;
}
bool Node::operator<(int num) {
	return (data < num);
}
bool Node::operator<(Node& other) {
	return (data < other.data);
}
bool Node::operator>(int num) {
	return (data > num);
}
bool Node::operator>(Node& other) {
	return (data > other.data);
}
bool Node::operator==(int num) {
	return (data == num);
}
bool Node::operator==(Node& other) {
	return (data == other.data);
}
bool Node::operator!=(int num) {
	return (data != num);
}
bool Node::operator!=(Node& other) {
	return (data != other.data);
}

std::ostream& operator<<(std::ostream& os, const Node& node) {
	os << node.data;
	return os;
}


// ����Ʈ �ʱ�ȭ �� ������ ���� �Ҵ�


List::List(int num) : len(num), sotred{false} {
	root = new Node[num];
	for (size_t idx = 0; idx < num - 1; idx++) {		// next ����
		root[idx].setNext(&root[idx + 1]);
	}
	std::srand(static_cast<unsigned int>(time(NULL)));
	for (size_t idx = 0; idx < num; idx++) {
		int val = std::rand() % 201;		// 0~200
		// ������ �Ҵ��� ������ �ߺ��Ǵ��� Ȯ��
		bool isUnique = true;
		for (int i = 0; i < idx; i++) {
			if (root[i] == val) {
				isUnique = false;
				break;
			}
		}

		// �ߺ����� ���� ���̸� �Ҵ�
		if (isUnique) {
			root[idx] = val;
		}
		else {
			idx--; // �ߺ��� ���̹Ƿ� �ε����� �ǵ���
		}
	}
}

List::~List() {
	if (root != nullptr)
		delete[] root;
}

Node* List::getRoot()
{
	return root;
}


void List::print()
{
	for (size_t i = 0; i < len; i++)
		std::cout << root[i] << ' ';
	std::cout << std::endl;
}
