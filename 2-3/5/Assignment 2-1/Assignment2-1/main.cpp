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
	Employee(char* name, int age, char* country, char* job) : age(age)			//생성자.
	{
		strcpy_s(this->name, name);
		strcpy_s(this->country, country);
		strcpy_s(this->job, job);
	}

	bool isNameCorrect(char* name)								//matching 되었는지 판단한다.
	{
		return strcmp(this->name, name) == 0;
	}

	void print()												//클래스의 private 변수를 출력한다.
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Country: " << country << endl;
		cout << "Job: " << job << endl;
		cout << "----------" << endl;
	}

	void change(char* name, int age, char* country, char* job)	//클래스의 private 변수 값을 변경한다.
	{
		strcpy_s(this->name, name);
		this->age = age;
		strcpy_s(this->country, country);
		strcpy_s(this->job, job);
	}	
};

int SpaceCountInstring(string s)								//Command에 space가 몇 개 남았는지 확인한다.
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)	
		if (s.find(" ", i) <= i)
			count++;
	
	return count;
}


string* GetStringToken(int count, string input)					//Token을 설정해준다.
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
		cout << "Enter input ('exit' to quit) : ";  //exit값을 입력받을 때까지 반복한다.
		getline(cin, input);                        //cin

		if (input == "exit")
			break;

		if (strncmp(input.c_str(), "insert", 6) == 0 || strncmp(input.c_str(), "INSERT", 6) == 0)
		{
			int spaceCount = SpaceCountInstring(input);					//parameter exception
			if(spaceCount != 4)
			{
				cout << "인자 값이 올바르지 않습니다." << endl;
				break;
			}

			if (employeeCount == 10)									//maximum count exception
			{
				cout << "insert 가능한 수를 초과했습니다." << endl;
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
				cout << "인자 값이 올바르지 않습니다." << endl;
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
				cout << "인자 값이 올바르지 않습니다." << endl;
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
				cout << tokens[0] << "을 찾을 수 없습니다." << endl;			//exception handle
				continue;
			}
		}
		else if (strcmp(input.c_str(), "print") == 0 || strcmp(input.c_str(), "PRINT") == 0)		//command PRINT
		{
			if (employeeCount == 0)								//No data
			{
				cout << "등록된 정보가 없습니다." << endl;
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
			cout << "올바르지 않은 Command입니다." << endl;
			continue;
		}
	}

	system("PAUSE");
	Sleep(1000);					//1 second stop
	return 0;
}