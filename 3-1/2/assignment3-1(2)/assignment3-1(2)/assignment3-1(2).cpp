#include<iostream>
using namespace std;

char* my_strtok(char* str)
{
	// my_strtok는 NULL이나 @, .를 감지하면 그 때 까지의 토큰을 반환한다.
	// NULL이 들어오면 그 이후로 토큰을 새로 만든다.	
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