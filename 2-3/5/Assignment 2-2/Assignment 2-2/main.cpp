#include <iostream>
#include <string.h>
#include <windows.h>
#include <string>
#include <cstring>

using namespace std;

class Student
{
private:
	char* name;
	int age;
	char* class_name;

public:
	Student(char* name, int age, char* class_name) :age(age)	//������ �⺻ ����
	{
		this->name = name;
		this->class_name = class_name;
	}

	char* GetName()												//get Name
	{
		return 	name;
	}

	int GetAge()												//get Age
	{
		return age;
	}

	char* GetClass()											//get Class
	{
		return class_name;
	}
};

class School
{
public:
	School()
	{
		for (int i = 0; i < 100; i++)							//student_list reset
		{
			student_list[i] = nullptr;
		}
	}

	~School()
	{
		// Student ��ü ����
		for (int i = 0; i < size; i++)							//delete dynamic allocation
		{
			delete student_list[i];
			student_list[i] = nullptr;
		}
	}
	
	void InsertStudent(char* name, int age, char* class_name)
	{
		student_list[size++] = new Student(name, age, class_name);	//insert data and size++
	}

	int GetStudentCount()											//return student count
	{
		return size;
	}

	void PrintAll()
	{
		if (size == 0)												//size exception
		{
			cout << "�л��� ��ϵ��� �ʾҽ��ϴ�." << endl;
			return;
		}

		cout << "=====print_all=====" << endl;

		for (int i = 0; i < size; i++)								//print all data
		{
			cout << "Name: " << student_list[i]->GetName() << endl;
			cout << "Age: " << student_list[i]->GetAge() << endl;
			cout << "Class: " << student_list[i]->GetClass() << endl;
			cout << "----------" << endl;
		}
	}

	void PrintMatchClass(char* class_name)
	{
		if (size == 0)												//size exception
		{
			cout << "�л��� ��ϵ��� �ʾҽ��ϴ�." << endl;
			return;
		}

		bool isMatched = false;
		for (int i = 0; i < size; i++)
		{
			if (strcmp(class_name, student_list[i]->GetClass()) == 0)
			{
				isMatched = true;
				break;
			}
		}

		if (!isMatched)												//is not matche exception
		{
			cout << class_name << "�ݿ� ��ϵ� �л��� �����ϴ�." << endl;
			return;
		}

		cout << "=====print_class=====" << endl;
		for (int i = 0; i < size; i++)								//print only matched data
		{
			if (strcmp(class_name, student_list[i]->GetClass()) == 0)
			{
				cout << "Name: " << student_list[i]->GetName() << endl;
				cout << "Age: " << student_list[i]->GetAge() << endl;
				cout << "Class: " << student_list[i]->GetClass() << endl;
				cout << "----------" << endl;
			}
		}
	}

	void SortByName()												//sort by name with buuble sort
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (_stricmp(student_list[j]->GetName(), student_list[j + 1]->GetName()) > 0)	//sort case insensitively
				{
					Student* temp = student_list[j];
					student_list[j] = student_list[j + 1];
					student_list[j + 1] = temp;
				}
			}
		}
	}

private:
	class Student* student_list[100];
	int size = 0;
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
	School A;
	string input = "";

	while (true)
	{
		cout << "Enter input ('exit' to quit) : ";  //exit���� �Է¹��� ������ �ݺ��Ѵ�.
		getline(cin, input);                        //cin

		if (input == "exit")
			break;

		if (strncmp(input.c_str(), "new_student", 11) == 0)					//insert new student command
		{
			int spaceCount = SpaceCountInstring(input);						//parameter exception
			if (spaceCount != 3)
			{
				cout << "���� ���� �ùٸ��� �ʽ��ϴ�." << endl;
				break;
			}

			if (A.GetStudentCount() > 99)									//maximum count exception
			{
				cout << "������ �� �ִ� �л� ���� �ʰ��Ͽ����ϴ�." << endl;
				continue;
			}

			string* tokens = GetStringToken(spaceCount, input);
			int age = stoi(tokens[1]);
			//insert data
			A.InsertStudent((char*)tokens[0].c_str(), age, (char*)tokens[2].c_str());	//insert student
		}
		else if (strcmp(input.c_str(), "sort_by_name") == 0)				//sort command
		{
			A.SortByName();													//execute sort
		}
		else if (strcmp(input.c_str(), "print_all") == 0)					//print all command
		{
			A.PrintAll();													//execute print all
		}
		else if (strncmp(input.c_str(), "print_class", 11) == 0)			//print matched class command
		{
			int spaceCount = SpaceCountInstring(input);						//parameter exception
			if (spaceCount != 1)
			{
				cout << "���� ���� �ùٸ��� �ʽ��ϴ�." << endl;
				break;
			}

			string* tokens = GetStringToken(spaceCount, input);
			A.PrintMatchClass((char*)tokens[0].c_str());					//execute command
		}
		else
		{
			cout << "�ùٸ��� ���� Command�Դϴ�." << endl;					//command error exception
			continue;
		}
	}

	system("PAUSE");
	Sleep(1000); //1 second stop
	return 0;
}