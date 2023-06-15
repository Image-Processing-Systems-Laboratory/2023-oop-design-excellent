#include <iostream>
#include <cstring>

int delimiter(const char* str)
{
	for (int i = 0; str[i] != '\0'; i++)		// ���ڿ��� ���ۺ��� ������ �˻��Ѵ�.
	{
		if (str[i] == '@' || str[i] == '.')		// @ �Ǵ� . �� ������ �� index�� i�� ��ȯ�Ѵ�.
		{
			return i;
		}
	}
	return strlen(str);	// ���ٸ�, �� 
}

char* my_strtok(char* str)
{
	static char* start = nullptr;	// ���� ���� start
	static char* next = nullptr;	// ���� ���� next

	if (str != nullptr)	// str�� ���� �ִٸ� str���� ���� (�ʱ� ����)
		start = str;

	else if (next != nullptr)	// next�� ���� �ִٸ� next���� ���� (���� ����)
		start = next;

	else
		return nullptr;	// �̿��� ���(���� ���¿��� next�� ���ڿ��� ��)

/////////////////////////////////////////////////////////////////////////////////////////

	int block = delimiter(start);	// ���� ���ڿ����� delimiter (@, .)�� ���۵Ǵ� ��ġ

	char* end = start + block;		// example@gmail.com
									// s------b end�� example���� 
	if (*end == '\0')		// ���ڿ��� ���̶�� ���� ���´� nullptr(����)
		next = nullptr;
	else
	{
		*end = '\0';		// s------\0 -> start�� \0���� "example"�� �ȴ�.
		next = end + 1;		// ���� ���´� \0 ������ g ���� ����
	}

	return start;
}

int main()
{
	char str[256];
	std::cout << "Email address: ";	// �Է�
	std::cin >> str;

	char* token = my_strtok(str);

	while (token != nullptr)	// ���ڿ��� ���� ������ �� ����
	{
		std::cout << token << std::endl;	// delimiter ������ ���ڿ��� ���
		token = my_strtok(nullptr);			// �̹� next�� ���ڿ��� ����Ǿ� �ֱ⿡ ���� ���·� �Ѿ�� ���� nullptr ����
	}

	return 0;
}