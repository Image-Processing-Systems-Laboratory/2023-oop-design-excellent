#include <iostream>
#include <cstring>

using namespace std;

struct s_node // array�� �� element�� ��� ����ü
{
	char arr[21]; // �� element ���ڿ��� ����
	struct s_node* next; // �� element
	struct s_node* down; // array �ȿ� array�� ����Ű�� ������
};

s_node* make_one_node(const char* str, int &cnt) // ��� �ϳ��� ����� �Լ�
{
	int i = 0;
	s_node* new_node = new s_node;

	if (!new_node)
		return (0);
	if (str[0]) // �� ���ڿ��� �ƴϸ� ��忡 ����
	{
		while (str[cnt] && str[cnt] != ' '
			&& (str[cnt] < 9 || str[cnt] > 13) && str[cnt] != ','
			&& str[cnt] != '[' && str[cnt] != ']') // ����, �޸�, ���ȣ�� �ƴ� ������ ����
		{
			new_node->arr[i] = str[cnt];
			i++;
			cnt++;
		}
	}
	new_node->arr[i] = 0;
	new_node->down = 0;
	new_node->next = 0; // ������ �ʱ�ȭ
	return (new_node);
}

s_node* make_array(const char *str, int& cnt) // linked list�� ������ nested array�� ����� �Լ�
{
	s_node* head; // �� line�� ���� �� ���
	s_node* prev;
	s_node* now;

	head = 0;
	prev = 0;
	while (str[cnt]) // ���ڿ��� �� ĭ�� �о��
	{
		while (str[cnt] && ((str[cnt] == ' ')
			|| (str[cnt] >= 9 && str[cnt] <= 13) || (str[cnt] == ',')))
			cnt++; // �޸�, ������ �ƴ� �κ��� ����ħ
		if (str[cnt] == '[') // element�� array �̸�
		{
			cnt++;
			now = make_one_node("", cnt); // element�� array�� ����Ű�� ��� ����
			// �ش� ����� arr�� �� ���ڿ��� ������ �ִ�.
			if (head)
				prev->next = now;
			else
				head = now;
			prev = now;
			prev->down = make_array(str, cnt); // ����Լ�(array ���� �� ����)
		}
		else if (str[cnt] == ']') // ��ü array Ȥ�� element�� array�� ������
		{
			cnt++;
			return (head);
		}
		else // element�� string
		{
			now = make_one_node(str, cnt);
			if (head)
				prev->next = now;
			else
				head = now;
			prev = now; // ��� ���� �� ����
		}
	}
	return (head);
}

void print_array(s_node* head)
{
	cout << "["; // array�� ����
	while (head)
	{
		if (head->down) // down�� �ִٸ� == nested array�� �ִٸ�
		{
			print_array(head->down); // �ش� array�� �� ��� ���
			if (head->next)
				cout << ", ";
		}
		else
		{
			if (!(head->arr)[0] && !head->down) // �� ���ڿ��ε� down�� ����->�� �迭!
				cout << "[]";
			else
				cout << head->arr; // element ���
			if (head->next)
				cout << ", ";
		}
		head = head->next;
	}
	cout << "]";
}

void execute_order(s_node* head)
{
	s_node* tmp = 0;
	char* input = 0;

	input = new char[100001]; // ��ɵ��� ���� ���ڿ�
	while (1)
	{
		cout << "order(break: exit): ";
		cin >> input;
		if (!strcmp(input, "exit"))
			break;
		else if (strlen(input) % 3 && strlen(input) < 3) // �Է��� ������ ���� ������ �ٽ� �Է�
			continue;
		tmp = head;
		for (int i = 3; input[i]; i += 3) // ��ɹ����� index�� ���� ��(��: arr["3"]["1"][...)
		{
			if (tmp->down)
			{
				tmp = tmp->down;
				for (int j = 0; j < input[i + 1] - '0' && tmp->next; j++)
					tmp = tmp->next;
			} // ������ index ���� ���� array�� ��� ��ġ�� �̵�
		}
		if (tmp->down) // ����ؾ� �Ǵ� element�� array���
			print_array(tmp->down);
		else
		{
			if (!(tmp->arr)[0] && !tmp->down) // ����ؾ� �ϴ� element�� ����ִٸ� -> �� �迭
				cout << "[]";
			else
				cout << tmp->arr;
		}
		cout << endl;
	}
	delete[]input;
}

void free_array(s_node* head) // nested array�� free�ϴ� �Լ�
{
	s_node* tmp;

	while (head)
	{
		if (head->down) // element�� array���
			free_array(head->down); // �ش� array���� free
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

int main()
{
	s_node* head = 0;
    char* input;
	int cnt = 0;

    cout << "nested array: ";
    input = new char[100001];
    cin.getline(input, 100001); // array �Է��� ������ ���� �� �����Ƿ� getline �Լ� ���
	head = make_array(input, cnt); // array ����
	if (!head)
	{
		delete[]input;
		input = 0;
		return (0);
	}
	delete[]input;
	input = 0;
	execute_order(head); // ��ɾ� �Է� �ް� ����
	free_array(head); // �޸� ����
    return 0;
}