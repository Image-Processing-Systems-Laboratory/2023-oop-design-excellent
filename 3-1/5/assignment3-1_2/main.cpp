#include <iostream>

using namespace std;

char* my_strtok(char* str);               //���ڿ� str�� '@'�� '.'���� �����ϴ� �Լ�

int main(void) {
	char str[100];                        //tokenize�� ���ڿ�
	char* token;                          //my_strtok �Լ��� ��ȯ ���� ������ ����

	cin >> str;

	while (1) {
		token = my_strtok(str);           //my_strtok �Լ� ȣ�� �� ��ȯ ��(token�� �ּ�) ����

		if (token == NULL) {              //NULL���ڸ� ��ȯ���� ��� ���ڿ��� ������ �м��� ���̹Ƿ� �ݺ� ����
			break;
		}
		else {
			cout << token << endl;        //token ���
		}
	}

	return 0;
}

//���ڿ� str�� '@'�� '.'���� �����ϴ� �Լ�
char* my_strtok(char* str) {
	static char* ptr = str;               //static pointer
	char* address = ptr;                  //token�� �ּ�
	str = ptr;

	//���ڿ� �м�
	while (*address) {
		if (*str == '@' || *str == '.') { //'@' �Ǵ� '.' �Ǵ� NULL ���ڸ� ������ ���
			*str = '\0';				  //�ش� ��ġ�� NULL ���� ����
			str++;
			ptr = str;					  //ptr�� str ����
			return address;				  //token�� �ּ� ��ȯ (�Ű����� str�� token�� ������ ������ ���ڿ��� �ּҸ� ����Ű�� �ȴ�.)
		}

		if (*str == '\0') {               //���ڿ��� ���� �������� ���
			ptr = str;					  //ptr�� str ����
			return address;				  //token�� �ּ� ��ȯ (�Ű����� str�� token�� ������ ������ ���ڿ��� �ּҸ� ����Ű�� �ȴ�.)
		}
		
		str++;							  //���� ���ڷ� �̵�
	}

	return NULL;                          //���ڿ��� ��� �м����� ��� NULL ��ȯ
}