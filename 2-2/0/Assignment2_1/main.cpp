#pragma warning(disable:4996)

#include<iostream>
#include<cstring>

using namespace std;

class Ele
{
public:
	Ele* next;	// ���� Ele ��带 �⸮ų ������
	Ele* under;	// �Ʒ��� ���ϴ� ��带 ����ų ������
	char str[21];
	Ele()
	{
		next = NULL;
		under = NULL;
		str[0] = '\0'; // ���������� *���
	}
	~Ele()	// �����Ҵ��� ������ ���� �Ҹ��� ����
	{
		if (under != NULL)
			under->~Ele();

		if (next != NULL)
			next->~Ele();
	}
};

class NestArry
{
public:
	Ele start;	// ������ ���

	void get_value(Ele* dest)	// �Է°��� ���� ��带 ������
	{
		while (cin.peek() != ']')	// ��ȣ�� ������ �ݺ����� ����
		{
			if (cin.peek() == '[') // ��ȣ�� ������ ��������� �Լ��� ȣ���Ѵ�
			{
				cin.get();	// '['�� ����
				dest->under = new Ele;
				get_value(dest->under); // ��ȣ�� ������ �Ʒ��� ���ϴ� ��带 �����ϰ� ��������� ȣ��
				if (cin.peek() == ']')
					break;
				dest->next = new Ele;// �Ʒ������ϴ� ��尡 �����ϴ� ��忡�� ���ڿ� ���� ���� ����
				dest = dest->next;// ���� ��� ����
			}
			else // ��ȣ�� ������ ������ ����� str�� �ް� �Է� ���Ŀ� ���� �ൿ��
			{
				get_str(dest);	// ���ڿ� �� dest�� ������
				if (cin.peek() == ']')	// ��ȣ�� ������ �ݺ��� Ż��
					break;
				dest->next = new Ele; // ��ȣ�� ������ ������ ���� ��带 ���� 
				dest = dest->next;
			}
		}cin.get();// ']' ����
		if (cin.peek() == ',') // �޸��� ������ ������ ���� ���ǹ�
		{
			cin.get();	// �޸��� ����
			while (cin.peek() == ' ') // ������ ����
			{
				cin.get();
			}
		}

		return;
	}
	
	void get_str(Ele* dest)	// �Ű������� ���� ��忡 str���� ������
	{
		int idx = 0;
		while ((cin.peek() != ']')&&(cin.peek()!=',')) // ��ȣ�� �����ų� ','�� ���еǸ� ���ڿ� ���� �б⸦ ����
		{
			(dest->str)[idx++] = cin.get();
		}

		(dest->str)[idx] = '\0'; // ������ �ι��� �߰�

		if (cin.peek() == ',') // �޸��� ������ ������ ���� ���ǹ�
		{
			cin.get();
			while (cin.peek()==' ')
			{
				cin.get();
			}
		}

		return;
	}

	int get_idx(void) // �Է°����� �ε����� ������ �������� �о���� ��ȣ�� ������
	{
		int tmp = -1;
		while (cin.peek()!=']')
		{
			cin.get();
			tmp = (cin.get()) - '0';
		}
		cin.get();// ']'����
		return tmp;
	}
	void print_nest(Ele* ptr) // �迭�ȿ� �迭�� ���Ե� ����� ��¹�
	{
		cout << '['; //��ȣ�� ���
		while (ptr != NULL)// ptr�� �������Ͷ�� �ݺ��� ����
		{
			if (ptr->under != NULL) // �ش� ����� �Ʒ��� ��尡 �����ϸ� ����� ȣ��
				print_nest(ptr->under);

			else// �Ʒ��� ��尡 ���ٸ� �ش� ����� str���� ����Ѵ�
			{
				int idx = 0;
				while (1)
				{
					cout << ptr->str[idx];
					if (ptr->str[idx] == '\0')
						break;
					idx++;
				}
			}
			if (ptr->next == NULL) // �ݺ����� ����� �����̸� ]�� ���
				cout << ']';
			else
				cout << ", "; // �ƴ϶�� , ���
			ptr = ptr->next;

		}
		return;
	}
	void print(void)
	{
		Ele* ptr = &start;
		char flag_all = 1;	// �迭�� �� ���Ҹ� ����Ű�� ���� �ƴ��� Ȯ���� �÷���, �� ���Ҷ�� 0, ��ü��� 1��
							
		while (cin.peek() != '\n')	// ��� �Է��� ������ �ݺ��� ����
		{
			int tmp = get_idx();
			for (int i = 0; i < tmp; i++) // �ε����� �ϳ� �̾Ƴ� ������ ���鿡 ������
			{
				ptr = ptr->next;
				flag_all = 0;
			}
			if (ptr->under != NULL) // �Ʒ��� ��尡 �����ϸ� �ش���� �̵��ϰ� flag ���� ������
			{
				ptr = ptr->under;
				flag_all = 1;
			}
			else
				flag_all = 0;
		}
		if (flag_all == 0) //flag �������� �����ϳ��� ������� �ƴ��� �Ǵ��� 
		{
			int idx = 0;
			while (1)
			{
				if (ptr->str[idx] == '\0'&&idx==0)
				{
					cout << "INVALID INDEX, VOID";
					break;
				}
				cout << ptr->str[idx];
				if (ptr->str[idx] == '\0')
					break;
				idx++;
			}
		}
		else
			print_nest(ptr);	// �ѿ��Ұ� �ƴ� ���� ���ҵ��� ����Ҷ� ȣ���� �Լ�

		cout << endl;

		return;
	}
	

};

char is_exit(void)	// command�� exit���� Ȯ���ϴ� �Լ�
{
	if (cin.peek() != 'e')
		return 0;

	char exit[] = "exit";
	for (int i = 0; i < 4; i++)
	{
		if (cin.get() != exit[i])
			return 0;
	}
	if (cin.peek() == '\n')
		return 1;
	
	return 0;
}
char is_arr(void)	// command�� arr���� Ȯ���ϴ� �Լ�
{
	if (cin.peek() != 'a')
		return 0;

	char arr[] = "arr";
	for (int i = 0; i < 3; i++)
	{
		if (cin.get() != arr[i])
			return 0;
	}
	return 1;
}

int main(void)
{
	cin.get();
	NestArry Na;
	Na.get_value(&(Na.start));	// �ش� ��ü�� ���� �Է¹���

	cin.ignore(5, '\n');
	while (!is_exit()) // �Է°��� exit�̸� �ݺ��� ����
	{
		if (!is_arr()) // �߸��� �Է°��̸� ���α׷��� �����Ѵ�.
		{
			cout << "INVALID INPUT, terminate program.\n";
			return 0;
		}
		Na.print(); // ����ϴ� �޼��� ȣ��
		cin.ignore(5, '\n');
	}


	return 0;
}
