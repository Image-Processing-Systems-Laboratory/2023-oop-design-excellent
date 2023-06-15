#include "node.h"

Node::Node()
{
    data = 0;
    next = 0; // ��� ���� �ʱ�ȭ
}

void Node::setNext(Node* ptr)
{
    next = ptr;
}

void Node::setData(int data)
{
    this->data = data; // ��� ������ �� �Ҵ�
}

Node* Node::getNext()
{
    return next;
}

int Node::getData()
{
    return data; // ��� ���� ��ȯ
}

int check_dup(Node* head, int num)
{
	Node* tmp;

	for (tmp = head; tmp; tmp = tmp->getNext()) // head������ ����Ʈ�� ��ȸ
	{
		if (tmp->getData() == num) // num data�� ������ ������
			return 1; // 1 ��ȯ
	}
	return 0;
}

Node* make_rand_list()
{
	Node* head;
	Node* last;
	Node* tmp;
	int num;

	srand((unsigned int)time(NULL)); // ���� �õ带 time()���� �ʱ�ȭ
	head = new Node; // head node ����
	num = (int)rand() % 201; // num�� 0���� 200�� ������ ��
	head->setData(num); // head ��忡 data �߰�
	last = head;
	for (int i = 0; i < 15; i++)
	{
		num = (int)rand() % 201;
		if (check_dup(head, num)) // ���� ����Ʈ�� �ִ� ���� ������
		{
			i--; // ���� �߰� X
			continue; // �ݺ����� ���� �κ����� �̵�
		}
		tmp = new Node;
		tmp->setData(num); // ��� ����
		last->setNext(tmp); // last�� �� �κп� ��� ����
		last = tmp; // last ����
	}
	return head;
}

void push(Node* prev, Node* now)
{
	now->setNext(prev->getNext()); // now�� ������ prev�� ����
	prev->setNext(now); // prev�� ������ now
}

Node* pop(Node* prev)
{
	Node* ret;

	ret = prev->getNext(); // prev����� ���� ��尡 pop�� ���
	prev->setNext(ret->getNext()); // prev�� �ٴ��� ��尡 prev�� ���� ���(���� ����)
	ret->setNext(0); // ret�� ������ 0���� ����� ret ���� ����Ʈ�� ���� ���� ����
	return ret;
}

void insertion_sort(Node** head)
{
	Node* now_prev, *now, *prev;
	int num;

	if (!(*head)) // ����Ʈ�� ���������
		return; // ����
	now_prev = *head; // ���� ���� �ÿ� ���ϴ� ���
	while (now_prev->getNext())
	{
		num = now_prev->getNext()->getData(); // ��带 ���� pop�ϴ� ��� ���� ����
		if (num > (*head)->getData()) // �� ���� ��尡 ���� �տ� �;� �Ѵٸ�
		{
			now = pop(now_prev); // now_prev�� ���� ��带 ���� ��ġ���� pop
			now->setNext(*head); // now�� �� �տ� ����
			*head = now; // head ����
			continue; // �������� �̵�
		}
		for (prev = *head; prev != now_prev; prev = prev->getNext())
		{
			if (num > prev->getNext()->getData()) // ����� ������ ��ġ�� ã����
			{
				now = pop(now_prev); // ��带 pop
				push(prev, now); // prev ������ now�� push
				break; // �� �̻� Ž�� x
			}
		}
		if (prev == now_prev) // ���������� ���ߴٸ�(����� ��ġ�� �����ߴٸ�)
			now_prev = now_prev->getNext(); // now_prev�� �� ĭ �ű�
	}
}

void print_list(Node* head)
{
	for (Node* tmp = head; tmp; tmp = tmp->getNext())
		std::cout << tmp->getData() << " "; // head���� data�� �ϳ��� ���
	std::cout << std::endl;
}

Node* getNode(int idx, Node* head)
{
	for (int i = 0; head && i < idx; head = head->getNext(), i++);
	return head; // head�������� idx��° �ִ� ��带 ��ȯ
}

Node* recur_binary(int f, int r, Node* p, int n)
{
	int mid, mid_data;
	Node* f_node = 0;
	Node* r_node = 0;
	Node* m_node = 0;

	if (f >= 0 && f < 16)
		f_node = getNode(f, p);
	if (r >= 0 && r < 16)
		r_node = getNode(r, p); // f�� r�� ������ ���� �����ٸ�, �� ��ġ�� ��带 �Ҵ�
	if (f > r) // Ž���� �����Ѵٸ�(�� �ε����� ����)
	{
		std::cout << "Search failed..." << std::endl; // ������ ���
		if (f_node && r_node) // f_node, r_node �Ѵ� �����ϸ�
		{
			if (abs(f_node->getData() - n) < abs(r_node->getData() - n))
				return f_node; // �� �� n���� ������ ���밪�� ���� ���� ������ ��带 ��ȯ
			else
				return r_node;
		}
		else if (f_node)
			return f_node;
		else if (r_node)
			return r_node; // �� �� �ϳ��� �����Ѵٸ� �� ��带 ��ȯ
		else
			return 0; // �� �� �������� �ʴ´ٸ� �� ��ȯ
	}
	mid = (f + r) / 2; // front�� rear�� �߰� ���� mid
	if (mid >= 0 && mid < 16)
		m_node = getNode(mid, p); // �ش� �ε����� ���
	mid_data = m_node->getData();
	if (mid_data == n) // �˻� ����
		return m_node;
	else if (mid_data < n) // �߰� ������ �����Ͱ� ũ�ٸ�
		return (recur_binary(f, mid - 1, p, n)); // rear �ε����� ����
	else
		return (recur_binary(mid + 1, r, p, n)); // front �ε����� ����

}

Node* Binary_Search(Node* p, int n)
{
	return recur_binary(0, 15, p, n); // �� 16���� �����͸� ���� ����Ʈ�̹Ƿ� 0���� 15���� Ž��
}

void memory_free(Node* head)
{
	Node* tmp;

	while (head) // head ������
	{
		tmp = head;
		head = head->getNext();
		delete tmp; // �ϳ��� �޸� ����
	}
}