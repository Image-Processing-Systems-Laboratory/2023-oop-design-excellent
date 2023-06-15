#include <iostream>
#include <cctype>
#include <string.h>

enum e_type // ������ Ÿ��
{
	STR,
	ARR
};

struct Data // �迭�� �� ������
{
	int type; // Ÿ��
	void* data; // �ش� ���Ҹ� ����Ű�� ������
};

class Arr // �迭 Ŭ����
{
public:
	Arr(int length) // �����ڿ��� ������ ���� ����
		: len(0), arr(new Data[length]) // ���� �Ҵ�
	{}
	~Arr(void) // �Ҹ��ڿ��� �޸� ����
	{
		for (int i = 0; i < len; i++)
		{
			if (arr[i].type == ARR) // ���Ұ� �迭�� ��� �ش� �迭 ����
				delete (Arr*)arr[i].data;
			else
				delete[](char*)arr[i].data; // ���ڿ��� ��� ���ڿ� ����
		}
		delete[] arr; // ���� ��ü�� �迭 ����
	}

	void push_back(Data data) // �迭 �ڿ� ���� ����
	{
		arr[len++] = data;
	}

	void print_data(int* idx) // �ε��� ����Ʈ�� �޾� �ش� �ε����� ���� ���
	{
		int i = 0;
		Arr* cur = this; // �ڱ� �ڽ��� ����Ű�� ������

		if (idx[0] == -1) // �ε����� ���� ��� ��ü ���
		{
			print_arr(cur, cur->len); // �ڱ� �ڽ� ���
			std::cout << std::endl; // ���� ���
			return;
		}
		while (idx[i] != -1) // �ε��� ����Ʈ�� ���� ������
		{
			if ((cur->arr[idx[i]]).type == STR) // ���ڿ��̶�� �ݺ��� ����
				break;
			cur = (Arr*)(cur->arr[idx[i]]).data; // cur�� nested �迭 �ּ� ����
			i++;
		}
		if ((cur->arr[idx[i]]).type == STR) // �ش� �ε����� ����Ű�� ���� ���ڿ�
		{
			std::cout << (char*)(cur->arr[idx[i]]).data; // ���ڿ� ���
		}
		else // �ش� �ε����� ����Ű�� ���� �迭
		{
			print_arr(cur, cur->len); // �迭 ���
		}
		std::cout << std::endl;
	}
	static void print_arr(Arr* array, int length) // ���ڷ� �迭�� �迭 ���� �޾� �迭 ���
	{
		std::cout << '['; // ���ȣ ���
		for (int i = 0; i < length; i++) // �ش� �迭�� ��ȸ
		{
			if (array->arr[i].type == STR) // ���Ұ� ���ڿ��� ���
			{
				std::cout << (char*)array->arr[i].data; // ���ڿ� ���
			}
			else // ���Ұ� �迭�� ���
			{
				// �ش� �迭 ���
				print_arr((Arr*)array->arr[i].data, ((Arr*)array->arr[i].data)->len);
			}
			if (i != length - 1) // ������ ���Ұ� �ƴ� ��� �ڿ� ��ǥ ���
				std::cout << ", ";
		}
		std::cout << ']'; // �ݴ� ���ȣ ���
	}
private:
	Data* arr; // data�� �迭�� ����Ű�� ������
	int len; // �迭�� ����
};

int arr_cnt(char* str) // ���ڷ� �Ѿ�� ���� �迭�� ������ ����
{
	int brack = 0;
	int cnt = 0;
	int i = 0;

	while (str[i]) // ���ڿ� ��ȸ
	{
		if (brack == 0 && str[i] == ',') // ��ǥ�� ������ ���� ���� + 1
			cnt++;
		else if (str[i] == '[') // ���� ���ȣ�� nested �迭
			brack++;
		else if (brack && str[i] == ']') // nested �迭�� ����
			brack--;
		else if (brack == 0 && str[i] == ']') // ���� �迭�� ���� �κ�
			break;
		i++;
	}
	return (cnt + 1); // ���Ҵ� ��ǥ + 1�� �����Ƿ�
}

int arr_len(char* str) // ���ڷ� �Ѿ�� ������ �迭�� ����������� ����
{
	int brack = 0; // nested ����
	int i = 0;

	while (str[i]) // ���ڿ� ��ȸ
	{
		if (str[i] == '[') // ���ȣ�� ��� nested �迭
			brack++;
		else if (brack && str[i] == ']') // nested �迭�� �� �κ�
			brack--;
		else if (brack == 0 && str[i] == ']') // �� �迭�� �� �κ�
			break;
		i++;
	}
	return (i); // ���� ��ȯ
}

int str_len(char* str) // �ϳ��� ���ڿ� ������ ����
{
	int i = 0;

	while (str[i]) // ���ڿ� ��ȸ
	{
		if (!isalnum(str[i])) // �����̳� ���ڰ� �ƴ� ���� ������ ����
			break;
		i++;
	}
	return (i); // ���� ����
}

char* strndup(const char* s, size_t len) // �κ� ���ڿ� ���纻 ����
{
	char* ret_str = new char[len + 1]; // ���纻 ���� �Ҵ�

	int i = 0;
	while (i < len) // len ��ŭ ����
	{
		ret_str[i] = s[i];
		i++;
	}
	ret_str[i] = 0; // �������� �ι��� ����
	return (ret_str); // ���纻 ��ȯ
}

Arr* make_arr(char* str) //�Ľ� �� �迭 ����
{
	int i = 0;
	int len = arr_cnt(str); // ���� str�� �Ľ��ϸ� ������ �迭�� ���� ����(nested�� �ϳ��� ����)

	Arr* ret_arr = new Arr(len); // �迭 ��ü �Ҵ�
	Data temp;
	while (str[i]) // ���ڿ� ��ȸ
	{
		if (isalnum(str[i])) // ���� ���ĺ� �Ǵ� ���ڸ� ���� ���
		{
			temp.type = STR; // Ÿ���� ���ڿ��� ǥ��
			temp.data = (void*)strndup(&str[i], str_len(&str[i])); // �ش� ���ڿ� ���纻 ����
			ret_arr->push_back(temp); // �迭�� ����
			i += str_len(&str[i]) - 1; // �ε����� ���ڿ� ������ �ű�
		}
		else if (str[i] == '[') // ���� ���ȣ�� ���� ��� nested �迭�� �Ǵ�
		{
			temp.type = ARR; // Ÿ���� �迭�� ǥ��
			temp.data = (void*)make_arr(&str[i + 1]); // make arr �Լ��� �ش� ���ڿ� ��ġ�� �Ѱ� ȣ��
			ret_arr->push_back(temp); // ���� �迭�� �� �迭�� ����
			i += arr_len(&str[i + 1]) + 1; // �ش� nested�迭�� ������ �ε����� �ű�
		}
		else if (str[i] == ']') // �ݴ� ���ȣ�� ���� ��� �迭�� ��
			break;
		i++;
	}
	return (ret_arr); // ������� �迭 ����
}

int* input_idx_parse(char* input) // �ε��� �Ľ� �Լ�
{
	int idx_num = 0;
	int i;
	int cnt = 1;
	int* ret_arr;

	// ��ȿ���� ���� �Է� �Ǵ� exit�� ��� NULL����
	if (strcmp(input, "exit") == 0 || strlen(input) < 3)
		return (NULL);
	i = 0;
	while (input[i]) // ���ȣ�� ������ ���� �ε��� ���� ����
	{
		if (input[i] == '[')
			cnt++;
		i++;
	}
	ret_arr = new int[cnt]; // �迭 �Ҵ�
	if (cnt == 1) // �ε����� ���� ���(��ü �迭 ���)
	{
		ret_arr[0] = -1; // -1�� ��� ����
		return (ret_arr);
	}
	i = 4;
	while (input[i]) // "arr["�� �ѱ�� ���ĺ��� ���
	{
		ret_arr[idx_num++] = atoi(&input[i]); // ���ڷ� ��ȯ�ؼ� �迭�� ����
		while (input[i] && isdigit(input[i])) // �ش� ���� �ǳ� ��
			i++;
		while (input[i] && !isdigit(input[i])) // ������ ���ڱ��� �̵�
			i++;
	}
	ret_arr[idx_num] = -1; // ������ ĭ�� -1�� �־� ���������� ǥ��
	return (ret_arr); // �ε��� �迭 ��ȯ
}

int main(void)
{
	char input[100001];
	Arr* arr;
	int i = 0;
	int* idx_list;

	std::cin.getline(input, 100001); // �Է� �ޱ�
	while (input[i] != '[') // ���� �ǳʶٱ�
		i++;
	arr = make_arr(&input[i + 1]); // ù �Է�(�迭) �Ľ� �� ����

	std::cin.getline(input, 100001); // �Է� �ޱ�
	idx_list = input_idx_parse(input); // �ε��� �� �Ľ�
	while (idx_list) // exit ���� ������ (�ε��� �Ľ� �Լ����� NULL ���Ͻñ���)
	{
		arr->print_data(idx_list); // �ش� �ε����� �ش��ϴ� �� ���
		delete[] idx_list; // �ε��� �迭 ����
		std::cin.getline(input, 100001); // �Է� �ޱ�
		idx_list = input_idx_parse(input); // �ε��� �Ľ�
	}
	delete arr; // �迭 ����
}