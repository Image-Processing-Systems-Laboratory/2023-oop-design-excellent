#include <iostream>
#include <windows.h>
#include <string.h>
#include <string>
#include <cstring>


using namespace std;


class Employee
{
private:
	char name[10];
	int age = 0;
	char country[100];
	char job[100];

public:
	Employee(char* name, int age, char* country, char* job) : age(age)			//������.
	{
		strcpy_s(this->name, name);
		strcpy_s(this->country, country);
		strcpy_s(this->job, job);
	}

	bool isNameCorrect(char* name)								//matching �Ǿ����� �Ǵ��Ѵ�.
	{
		return strcmp(this->name, name) == 0;
	}

	void print()												//Ŭ������ private ������ ����Ѵ�.
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Country: " << country << endl;
		cout << "Job: " << job << endl;
		cout << "----------" << endl;
	}

	void change(char* name, int age, char* country, char* job)	//Ŭ������ private ���� ���� �����Ѵ�.
	{
		strcpy_s(this->name, name);
		this->age = age;
		strcpy_s(this->country, country);
		strcpy_s(this->job, job);
	}	
};

int SpaceCountInstring(string s)								//Command�� space�� �� �� ���Ҵ��� Ȯ���Ѵ�.
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)	
		if (s.find(" ", i) <= i)
			count++;
	
	return count;
}


string* GetStringToken(int count, string input)					//Token�� �������ش�.
{
	string* parameter = new string[count];

	char* str = const_cast<char*>(input.c_str());
	char* nextToken = nullptr;
	char* token = strtok_s(str, " ", &nextToken);

	for (int i = 0; i < count; i++)
	{
		parameter[i] = strtok_s(nullptr, " ", &nextToken);
	}

	return parameter;
}


int main()
{	
	Employee *employee[10];
	int employeeCount = 0;
	string input = "";

	while (true)
	{
		cout << "Enter input ('exit' to quit) : ";  //exit���� �Է¹��� ������ �ݺ��Ѵ�.
		getline(cin, input);                        //cin

		if (input == "exit")
			break;

		if (strncmp(input.c_str(), "insert", 6) == 0 || strncmp(input.c_str(), "INSERT", 6) == 0)
		{
			int spaceCount = SpaceCountInstring(input);					//parameter exception
			if(spaceCount != 4)
			{
				cout << "���� ���� �ùٸ��� �ʽ��ϴ�." << endl;
				break;
			}

			if (employeeCount == 10)									//maximum count exception
			{
				cout << "insert ������ ���� �ʰ��߽��ϴ�." << endl;
				continue;
			}

			string* tokens = GetStringToken(spaceCount, input);
			int age = stoi(tokens[1]);
			//insert data
			employee[employeeCount] = new Employee((char*)tokens[0].c_str(), age, (char*)tokens[2].c_str(), (char*)tokens[3].c_str());
			employeeCount++;
		
		}
		else if (strncmp(input.c_str(), "find", 4) == 0 || strncmp(input.c_str(), "FIND", 4) == 0)
		{
			int spaceCount = SpaceCountInstring(input);						//parameter exception
			if (spaceCount != 1)
			{
				cout << "���� ���� �ùٸ��� �ʽ��ϴ�." << endl;
				break;
			}

			bool isMatched = false;
			string* tokens = GetStringToken(spaceCount, input);
			for (int i = 0; i < employeeCount; i++)
			{
				if (employee[i]->isNameCorrect((char*)tokens[0].c_str()))	//matched data
				{
					cout << "=====find=====" << endl;
					employee[i]->print();
					isMatched = true;
					break;
				}
			}

			if (!isMatched)
			{
				cout << "Not matched: " << tokens[0] << endl;
				continue;
			}
		}
		else if (strncmp(input.c_str(), "change", 6) == 0 || strncmp(input.c_str(), "CHANGE", 6) == 0)		//command change
		{
			int spaceCount = SpaceCountInstring(input);						//parameter error
			if (spaceCount != 5)						
			{
				cout << "���� ���� �ùٸ��� �ʽ��ϴ�." << endl;
				break;
			}

			bool isMatched = false;
			string* tokens = GetStringToken(spaceCount, input);

			for (int i = 0; i < employeeCount; i++)
			{
				if (employee[i]->isNameCorrect((char*)tokens[0].c_str()))	//matched data	
				{
					int age = stoi(tokens[2]);
					employee[i]->change((char*)tokens[1].c_str(), age, (char*)tokens[3].c_str(), (char*)tokens[4].c_str());
					isMatched = true;
					break;
				}
			}

			if (!isMatched)
			{
				cout << tokens[0] << "�� ã�� �� �����ϴ�." << endl;			//exception handle
				continue;
			}
		}
		else if (strcmp(input.c_str(), "print") == 0 || strcmp(input.c_str(), "PRINT") == 0)		//command PRINT
		{
			if (employeeCount == 0)								//No data
			{
				cout << "��ϵ� ������ �����ϴ�." << endl;
				continue;
			}

			cout << "=====print=====" << endl;					//start print data
			for (int i = 0; i < employeeCount; i++)
			{
				employee[i]->print();
			}
		}
		else
		{
			cout << "�ùٸ��� ���� Command�Դϴ�." << endl;
			continue;
		}
	}

	system("PAUSE");
	Sleep(1000);					//1 second stop
	return 0;
}