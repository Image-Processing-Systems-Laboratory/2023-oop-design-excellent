#include<iostream>
using namespace std;

char* my_strtok(char* str)
{
	// my_strtok�� NULL�̳� @, .�� �����ϸ� �� �� ������ ��ū�� ��ȯ�Ѵ�.
	// NULL�� ������ �� ���ķ� ��ū�� ���� �����.	
	static char* cur = NULL;

	if (str != NULL)
		cur = str;

	if (cur == NULL)
		return NULL;

	char* token = cur;

	while (*cur != NULL && *cur != '@' && *cur != '.')
		cur++;

	if (*cur == NULL)
		cur = NULL;
	else
		*cur++ = NULL;

	return token;
}

int main(void)
{
	char input[256];
	cin >> input;
	cout << my_strtok(input) << endl;

	char* token = input;
	while (token != nullptr)
	{
		token = my_strtok(NULL);
		cout << token << endl;
	}
}