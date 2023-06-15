//2022202040 ���켺

#include <iostream>

char* my_strtok(char* str);

int main()
{
	// ���ڿ� �Է¹ޱ�
	char input[100];
	std::cin >> input;
	char* ptr = my_strtok(input); // ó�� ���ڿ��� �ڸ�
	while (ptr != NULL) 
	{
		//�ڸ� ���ڿ� ��� �� �� ���� ���ڿ��� �ڸ�
		std::cout << ptr << std::endl;
		ptr = my_strtok(NULL);
	}

	return 0;
}

char* my_strtok(char* str)
{
	int i = 0; //���ڿ� ÷�� ����
	char* cur; // ���ڿ��� ó�� ÷�� �ּҰ� ����
	static char* pre; // ������ �߶��� ��ġ ���� ÷���� �ּҰ� ����

	if (str == NULL) { //�Ű������� NULL�� ���� ���
		cur = pre; // ���� �߶��� ��ġ�� ���� ÷�ں��� �˻�
	}
	else { //�Ű������� ���ڿ��� ���� ���
		cur = str; //���ڿ��� ó������ �˻� ����
	}

	if (cur[i]==NULL) //���ڿ��� ������ NULL ��ȯ
		return NULL;

	while (1)
	{
		if (cur[i] == '@' || cur[i] == '.' || cur[i]==NULL) { // '@', '.', 'NULL'�� ���� ���
			if (cur[i] == NULL) { // NULL���ڸ� ������ NULL���ڸ� ���� ÷���� �ּҰ��� pre�� ����
				pre = &cur[i];
			}
			else { // '@' �Ǵ� '.'�� ���� ���
				pre = &cur[i + 1]; // '@' �Ǵ� '.' ���� ÷�ڸ� pre�� ����
				cur[i] = NULL; // '@' �Ǵ� '.'�� NULL���ڷ� �ٲ�
			}
			break;
		}
		i++;
	}

	return cur;

}