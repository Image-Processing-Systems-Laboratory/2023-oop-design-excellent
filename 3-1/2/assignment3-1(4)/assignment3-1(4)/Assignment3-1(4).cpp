#include"mystack.h"

int main(void)
{
	mystack s;
	char input[128];

	// 테스트용

	cout << "Insert \"help\"to verify all commands. " << endl;
	while (true)
	{
		cout << "Insert command: ";
		cin >> input;

		if (!strncmp(input, "help", 4))
		{
			cout << "========================help========================" << endl;
			cout << "setSize <n> : set the size of the stack to n." << endl;
			cout << "isEmpty : check that the stack is empty." << endl;
			cout << "isFull : check that the stack is full." << endl;
			cout << "push <data> : inserts the data into the stack." << endl;
			cout << "pop : print out and remove the data that came in last." << endl;
			cout << "printqueue : prints all data of the stack." << endl;
			cout << "exit : exit the program." << endl;
			cout << "====================================================" << endl;
		}

		else if (!strncmp(input, "setSize", 7))
		{
			int n;
			cin >> n;
			s.setSize(n);
		}

		else if (!strncmp(input, "isEmpty", 7))
		{
			if (s.isEmpty())
				cout << "true" << endl;
			else
				cout << "false" << endl;
		}

		else if (!strncmp(input, "isFull", 6))
		{
			if (s.isFull())
				cout << "true" << endl;
			else
				cout << "false" << endl;
		}

		else if (!strncmp(input, "push", 4))
		{
			int data;
			cin >> data;
			Node* a = new Node;
			a->setData(data);
			s.push(a);
		}

		else if (!strncmp(input, "pop", 3))
		{
			s.pop();
		}

		else if (!strncmp(input, "printstack", 10))
		{
			s.printstack();
		}
		else if (!strncmp(input, "exit", 4))
		{
			exit(0);
		}
	}

	return 0;
}