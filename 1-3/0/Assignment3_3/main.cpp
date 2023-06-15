#include<iostream>
#include<cmath>
using namespace std;

// �����Ҵ��� ���� �Է°��� ���� ���� ���� ���� �Լ�
char* get_num(char* ptr, char n,int len);

//��͸� �̿���10������ ��ȯ�ϴ� �Լ�
void tenTo(int num, int to_num);

//2������ ��ȯ�ϴ� �Լ�
void twoTo(char* num, int to_num, int width);

//���� �Լ��� �̿��� 8������ 16�� ��ȯ�ϴ� �Լ�
void eightTo(char* num, int to_num, int width);
void sixTo(char* num, int to_num, int width);
int main(void)
{
	
	char* num = NULL;
	int len = 0;
	char tmp_n = 0;
	//������ ���������� ���ϴ� ���� ����
	while ((tmp_n = getchar()) != ' ')
	{
		num = get_num(num, tmp_n, ++len);
	}

	int exist_nota = 0;
	int change_nota = 0;
	cin >> exist_nota;
	cin >> change_nota;

	if (exist_nota == 10)
	{
		int num_i = 0;

		for (int i = 0; i < len; i++)
			num_i += (pow(10, len - 1 - i) * (num[i] - '0'));
		tenTo(num_i, change_nota);
	}
	else if (exist_nota == 2)
	{
		twoTo(num, change_nota, len);
	}
	else if (exist_nota == 8)
	{
		eightTo(num, change_nota, len);
	}
	else if (exist_nota == 16)
	{
		sixTo(num, change_nota, len);
	}


	delete[] num;
	return 0;
}

// �����Ҵ��� ���� �Է°��� ���� ���� ���� ����
char* get_num(char* ptr, char n, int len)
{
	//len�� null�� ������ �����̹Ƿ� ���ڿ��� ���ϰ� ����ϱ� ���� len+1�� �����Ҵ�
	char* new_num = new char[len+1];

	//���̸� �ø��� ���� ������ �� ���ϴ� ���� �߰���
	for (int i = 0; i < len - 1; i++)
		new_num[i] = ptr[i];
	new_num[len - 1] = n;
	new_num[len] = '\0';

	// ������ �Ҵ�� ���ڿ��� ������
	if(ptr!=NULL)
		delete[] ptr;

	//���� �Ҵ��� ���ڿ��� ������ ��ȯ
	return new_num;
}

void tenTo(int num, int to_num)
{
	// ����� Ż�� �������� �Ʒ��� ���� ������
	if (num / to_num != 0)
		tenTo(num / to_num, to_num);
	//16������ ǥ���ؾ� �� ��� �Ʒ��� ���� ������� ���
	if (to_num == 16 && num % to_num > 9)
	{
		int tmp = num % to_num;
		char tmp_c = 'A'+(tmp-10);
		cout << tmp_c;
	}
	else
		cout << num % to_num;
	return;
}

void twoTo(char* num,int to_num, int width)	// width == ������ ���� ���� ����
{
	
	if (to_num == 10)
	{
		int tmp = 0;
		for (int i = 0; i < width; i++)	// �ڸ����� ���� 10������ ���� ������ ����
			tmp += (pow(2, width - i - 1) * (num[i]-'0'));
		cout << tmp;
	}
	else if (to_num == 8)
	{
		int tmp = 0; // �ڸ����� ������ ����
		while ((width + tmp) % 3 != 0)
			tmp++;

		int digit = 0;
		for (int i = 0; i < width;)
		{
			//3�ڸ��� ��� �����Ұ��̱� ������ �ڸ����� ���߱� ���� �Ʒ��� ���� ���ǹ� �ۼ�
			if (tmp != 0 && i == 0)
			{
				for (int j = 2 - tmp; j > -1; j--)
					digit += (pow(2, j) * (num[i++] - '0'));
					
				cout << digit;
				digit = 0;	
				continue;
			}

			digit = 0;
			for (int j = 2; j > -1; j--)
				digit += (pow(2,j) * (num[i++] - '0'));
			cout << digit;
		}
	}
	else if (to_num == 16)
	{
		int tmp = 0; // �ڸ����� ������ ����
		while ((width + tmp) % 4 != 0)
			tmp++;

		int digit = 0;
		for (int i = 0; i < width;)
		{
			//4�ڸ��� ��� �����Ұ��̱� ������ �ڸ����� ���߱� ���� �Ʒ��� ���� ���ǹ� �ۼ�
			if (tmp != 0 && i == 0)
			{
				for (int j = 3 - tmp; j > -1; j--)
					digit += (pow(2, j) * (num[i++] - '0'));

				// ���� ���ڷ� ǥ������ ������ �Ʒ��� ���� ó����
				if (digit > 9)
				{
					char tmp = 'A' + (digit - 10);
					cout << tmp;
				}
				else
				cout << digit;
				digit = 0;
				continue;
			}

			digit = 0;
			for (int j = 3; j > -1; j--)
				digit += (pow(2, j) * (num[i++] - '0'));

			if (digit > 9)
			{
				char tmp = 'A' + (digit - 10);
				cout << tmp;
			}
			else
				cout << digit;
		}
	}

}

void eightTo(char* num, int to_num, int width)
{
	// ���� �־��� 8 ������ 2������ ��ȯ�Ͽ� ������ ������ ����
	
	int num_10 = 0;


	//8������ 10������ ��ȯ
	for (int i = 0; i < width; i++)
	{
		num_10 = num_10 + pow(2, 3 * (width - i - 1)) * (num[i]-'0');
	}

	//��쿡���� toTow�Լ��� �̿��� ���
	if (to_num == 10)
		cout << num_10;
	else if (to_num == 2)
		tenTo(num_10, 2);
	else if (to_num == 16)
		tenTo(num_10, 16);

	return;
}
//eightTo�Լ��� ����� ������� ����
void sixTo(char* num, int to_num, int width)
{
	// ���� �־��� 16 ������ 2������ ��ȯ�Ͽ� ������ ������ ����
	int num_10 = 0;


	int tmp = 0;
	//16������ 10������ ��ȯ
	for (int i = 0; i < width; i++)
	{
		if (num[i] >= 'A')
			tmp = num[i] - 'A' + 10;
		else
			tmp = num[i] - '0';
		num_10 = num_10 + pow(2, 4 * (width - i - 1)) * tmp;
	}

	//��쿡���� toTow�Լ��� �̿��� ���
	if (to_num == 10)
		cout << num_10;
	else if (to_num == 2)
		tenTo(num_10, 2);
	else if (to_num == 8)
		tenTo(num_10, 8);

	return;
}