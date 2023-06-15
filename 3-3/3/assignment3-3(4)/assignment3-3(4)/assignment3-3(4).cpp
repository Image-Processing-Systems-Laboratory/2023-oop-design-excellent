#include"StudentScoreList.h"

int main(void)
{
	StudentScoreList list;
	
	while (true)
	{
		char command[32];
		cout << "Command: ";
		cin >> command;

		if (!strncmp(command, "insert", 6))
		{
			double math, eng, sci;
			cin >> math;
			cin >> eng;
			cin >> sci;
			list.Insert(new Node((math + eng + sci) / 3));
		}
		else if (!strncmp(command, "printascend", 11))
		{
			list.printlist(true);
		}
		else if (!strncmp(command, "printdescend", 12))
		{
			list.printlist(false);
		}
		else if (!strncmp(command, "exit", 4))
		{
			cout << "Exit the program..." << endl;
			exit(0);
		}
	}
}