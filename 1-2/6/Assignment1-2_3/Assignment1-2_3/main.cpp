#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>

#define WILD_STAR '*'
#define WILD_Q '?'

int	word_cnt(char* s) // ���ڿ��� *�� ���еǴ� �κ� ���ڿ��� �� ���� ��
{
	bool flag = false; // ���� �ܾ����� �ִ��� ����
	int cnt = 0; // �κ� ���ڿ� ����

	if (!s) // Ȥ�ó� �ؼ� ����ó��
		return (0);
	while (*s) // ���ڿ� ��ȸ
	{
		if (!flag && *s != WILD_STAR) // �ܾ ������
		{
			flag = true; // �ܾ� ���� ������ ǥ��
			cnt++; // �ܾ� ���� ����
		}
		else if (flag && *s == WILD_STAR) // �ܾ��� ���¿��� *�� ������
			flag = false; // *���� ������ ǥ��
		s++;
	}
	return (cnt); // ���� ����
}

int	word_len(char* s) // *�� ���еǴ� �κ� ���ڿ��� ���̸� ����
{
	int cnt;

	cnt = 0;
	while (*s && *s != WILD_STAR) // ���ڿ� ��ü�� �����ų� *�� ���� ������ ��ȸ
	{
		cnt++; // ���̸� ��
		s++;
	}
	return (cnt); // ���̸� ����
}

char** wildcard_split(char* s) // ��ü ���ڿ��� *�� �������� �κ� ���ڿ���� �ɰ�
{
	char** re_loc; // ������ ���ڿ� �迭
	bool flag = false; // ���� �ܾ� ���� �ִ��� ����
	int idx = 0; // �κ� ���ڿ� ����
	int len; // �κ� ���ڿ� ����

	if (!s)
		return (NULL);
	re_loc = new char* [word_cnt(s) + 1]; // �κ� ���ڿ��� ������ŭ char * �迭 �Ҵ�
	while (*s) // ���ڿ� ��ȸ
	{
		if (!flag && *s != WILD_STAR) // �ܾ ������
		{
			flag = true; // �ܾ� ���� ���� ǥ��
			len = word_len(s); // �κй��ڿ� ���� ��
			re_loc[idx] = new char[len + 1]; // ���ڿ� �Ҵ�
			strncpy(re_loc[idx], s, len + 1); // �κй��ڿ� ���̸�ŭ ����
			re_loc[idx][len] = 0; // �� ���� �ٿ���
			idx++; // �κй��ڿ� ���� ����
		}
		else if (flag && *s == WILD_STAR) // *�� ������
			flag = false; // * ������ ǥ��
		s++;
	}
	re_loc[idx] = NULL; // ���ڿ� �迭 �������� NULL�� ����
	return (re_loc); // ���ڿ� �迭 ����
}

int wild_strncmp(const char* patt, const char* s, int n) // ?�� ����� ���ڿ� ��
{
	if (!n)
		return (true);
	while (*patt && *s && --n) // ���ڿ��� �ִ� n�� ��ȸ
	{
		// ���ڿ��� ��Ī���� �ʴ� ���
		// �� �� ���� ���ڿ��� ?��� �׳� �Ѿ��
		if (*patt != WILD_Q && *patt != *s)
		{
			return (false); // false ����
		}
		patt++;
		s++;
	}
	if (*s == *patt || (*patt == WILD_Q && *s)) // ���ڿ��� ���������� ��Ī�Ǵ� ���
		return (true);
	return (false);
}

char* wild_strstr(char* str, char* patt, int n) // ?���ڸ� ����� �κй��ڿ� Ž��
{
	int i = 0;
	int patt_len = strlen(patt); // ���� ���ڿ��� ����

	if (!*patt) // ���� ���ڿ��� �� ���ڿ��� ��� str�� ���� ��ġ�� �� ���ڿ��� ����
		return (str);
	if (!*str || n < patt_len)
		return (NULL);
	while (str[i] && i < n - patt_len + 1) // �ִ� n�� ���� �ȿ��� �κй��ڿ� Ž��
	{
		if (wild_strncmp(patt, &str[i], patt_len)) // ���� ��ġ�ϴ� �κй��ڿ��� ������
			return (&str[i]); // �ش� ��ġ�� ������ ����
		i++;
	}
	return (NULL); // �κ� ���ڿ� ã�� ����
}

//s ��� �ٴҶ� ���ڿ��� patt�� ��Ī�Ǵ°�?
bool	pattern_matching(char** patt, char* s, bool front, bool last)
{
	int i = 0;
	char* ptr;

	if (front) // ���� *���� �������� ���� ���
	{
		// �� �պκ��� ��Ȯ�� ���ƾ� �Ѵ�.
		if (!wild_strncmp(patt[0], s, strlen(patt[0])))
		{
			return (false);
		}
	}
	ptr = s; // ��ȸ�� ���� ������ ����
	while (patt[i]) // ���� ���ڿ� �迭�� ��ȸ
	{
		ptr = wild_strstr(ptr, patt[i], strlen(ptr)); // ���� ���ڿ��� �������� Ž��
		if (!ptr) // ������ ���� ����ġ
			return (false);
		ptr += strlen(patt[i]); // �ִٸ� �ش� ���� ���ڿ��� �� �κ����� ������ �ű�
		i++;
	}
	if (last) // ���� *���� ������ ���� ���
	{
		// �� �޺κ��� ��Ȯ�� ���ƾ� �Ѵ�. 
		if (!wild_strncmp(patt[i - 1], &s[strlen(s) - strlen(patt[i - 1])], \
			strlen(patt[i - 1])))
			return (false);
	}
	return (true);
}

void	free_v(char** data) // (���� NULL�� ������)2���� �迭 ����
{
	int i = 0;;

	while (data[i])
		free(data[i++]);
	free(data);
}

void	file_error(void) // ���� ���� ����
{
	std::cerr << "file open error!" << std::endl;
	exit(EXIT_FAILURE);
}

// txtname�� �ִ� ���ڿ����� patt���ڿ��� ���ϰ� ��Ī���� ������ ���
void	filelist_output(char* patt, char* txtname)
{
	std::ifstream fs;
	char filename[100];
	char** pattern = wildcard_split(patt); // ������ ���� ���ڿ��� *�� �������� ���� �κ� ���ڿ� �迭

	fs.open(txtname); // �ؽ�Ʈ ���� ����
	if (!fs.is_open()) // ���Ͽ��� ����
		file_error();
	fs.getline(filename, 100); // �� ���� ����
	while (fs) // ������ ������ ���� ������(�Ǵ� �б��� ������ �� ������)
	{
		if (*pattern == NULL \
			|| pattern_matching(
				pattern, filename,
				patt[0] != WILD_STAR, patt[strlen(patt) - 1] != WILD_STAR
			)) // �Է��� *������ �̷���� �ְų� ���� ���� ���ϰ� ��ġ�ϸ� ���
			std::cout << filename << std::endl;
		fs.getline(filename, 100); // ���� ���� ����
	}
	fs.close(); // ���� ����
	free_v(pattern); // ���� �κй��ڿ��迭 ����
}

void	wildcard(char** input, char* txtname)
{
	int i = 0;

	while (input[i]) // ��� �Է��� ��ȸ�ϸ� ���ϸ�Ī ����
	{
		filelist_output(input[i], txtname);
		i++;
	}
}

int main(void)
{
	char filename[100];
	int input_num;
	char** input;
	int i = 0;


	std::cout << "Input file name :";
	std::cin >> filename; // ���� �̸� �Է�
	std::cin >> input_num; // �Է��� ����
	if (!std::cin)
		exit(EXIT_FAILURE);
	input = new char* [input_num + 1]; //�Է� ���� �Ҵ�
	while (i < input_num)
	{
		input[i] = new char[100]; // �Է� ���ڿ� �Ҵ�
		std::cin >> input[i]; // �Է¹���
		i++;
	}
	input[i] = NULL;
	wildcard(input, filename); // �Է¿� ���� ���� �� ���
	free_v(input); // �Է� ���� ����
	return (0);
}