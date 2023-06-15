#include"myqueue.h"

int main(void)
{
	myqueue q;
	char input[128];

	// 테스트용

	cout << "Insert \"help\"to verify all commands. " << endl;
	while (true)
	{
		cout << "Insert command: ";
		cin >> input;

		if (!strncmp(input, "help", 4))
		{
			// help
			cout << "========================help========================" << endl;
			cout << "setSize <n> : set the size of the queue to n." << endl;
			cout << "isEmpty : check that the queue is empty." << endl;
			cout << "isFull : check that the queue is full." << endl;
			cout << "push <data> : inserts data into the queue." << endl;
			cout << "pop : print out and remove the data that came in first." << endl;
			cout << "printqueue : prints all data of the queue." << endl;
			cout << "exit : exit the program." << endl;
			cout << "====================================================" << endl;
		}

		else if (!strncmp(input, "setSize", 7))
		{
			int n;
			cin >> n;
			q.setSize(n);
		}

		else if (!strncmp(input, "isEmpty", 7))
		{
			if (q.isEmpty())
				cout << "true" << endl;
			else
				cout << "false" << endl;
		}

		else if (!strncmp(input, "isFull", 6))
		{
			if (q.isFull())
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
			q.push(a);
		}

		else if (!strncmp(input, "pop", 3))
		{
			q.pop();
		}

		else if (!strncmp(input, "printqueue", 10))
		{
			q.printqueue();
		}

		else if (!strncmp(input, "exit", 4))
		{
			exit(0);
		}
	}

	return 0;
}