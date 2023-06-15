#include"oopstd.h"

using namespace oopstd;

namespace oopstd {		//oopstd ���� ������Ͽ��� ������ �Լ� ����
	void* memset(void* ptr, int value, size_t num) {		// memset �Լ� ����
		char* temp = (char*)ptr;							//void ���������� ���� char������ ������ ���
		for (int i = 0; i < num; i++) {						//���� �ϳ��� �˻��ϸ鼭 �Է¹��� num��ŭ �ݺ�
			temp[i] = value;								//�ش� �ε����� value�� �ٲٱ�
		}
		return temp;										//temp�� �ּҰ��� ��ȯ
	}

	void* memcpy(void* destination, const void* source, size_t num) { // memcpy()�Լ� ����
		char* temp = (char*)destination;					//void ���������� ���� char������ ������ ���
		char* temp2 = (char*)source;						//void ���������� ���� char������ ������ ���
		int i;
		for (i = 0; i < num; i++) {							//�ѱ��ھ� �˻�(num��ŭ)
			temp[i] = temp2[i];								//temp2�� ���� �ε����� ���� temp1�� ���� �ε����� ���
		}
		return temp;										//temp�� �ּҰ��� ��ȯ
	}
	
	int strcmp(const char* str1, const char* str2) {		//strcmp()�Լ� ����
		for (int i = 0; str1[i]!='\0' || str2[i] != '\0'; i++) {		//�� �迭�� �ϳ��� ����������
			if (*(str1 + i) > *(str2 + i))					//���� ���Ͽ� ���� �迭�� ũ�� 1 ��ȯ
				return 1;
			if (*(str1 + i) < *(str2 + i))					//���� ���Ͽ� ���� �迭�� ũ�� -1 ��ȯ
				return -1;
		}
		return 0;											//������ ������ �ݺ��� ���� ������ ��� ���ٴ� �ǹ��̹Ƿ� 0 ��ȯ
	}
	int strncmp(const char* str1, const char* str2, size_t num) {	//strncmp()�Լ� ����
		for (int i = 0; i < num; i++) {						//num�����ŭ �ݺ��ϸ� �ε��� �˻�
			if (*(str1 + i) == *(str2 + i))					//���� �ε��� ���� ������
				continue;									//���� �ε��� �˻�
			if (*(str1 + i) > *(str2 + i))					//�� �ε����� �� �ε������� ū ���� ����
				return 1;									//1 ��ȯ
			if (*(str1 + i) < *(str2 + i))					//�� �ε����� �� �ε������� ���� ���� ����
				return -1;									//-1 ��ȯ
		}
		return 0;											//�ݺ����� ������ �ȴٸ� 0��ȯ(��� ���ٴ� ��)
	}

	char* strcpy(char* destination, const char* source) {		//strcpy()�Լ� ����
		int i;
		for (i = 0; source[i] != '\0'; i++) {					//�ҽ� �迭�� ���������� �ε��� �ϳ��ϳ� �ݺ������� ����
			destination[i] = source[i];							//���� �迭�� �ҽ� �迭 �� �ε����� ����
		}
		destination[i] = '\0';									//�ҽ��� ������ �� �������� �ΰ� �Է�
		return destination;										//���� �迭 ��ȯ
	}

	char* strncpy(char* destination, const char* source, size_t num) {	//strncpy()�Լ� ����
		int i;
		for (i = 0; i < num; i++) {								//num�� ������ ��ŭ �ݺ����� �ݺ�
			destination[i] = source[i];							//���� �迭�� �ҽ� �迭�� �ѱ��ھ� �ٿ��ֱ�
		}
		return destination;										//���� �迭 ��ȯ
	}

	size_t strlen(const char* str) {					//strlen()�Լ� ����
		int i;	
		for (i = 0; str[i] != '\0'; i++);				//i�� ī��Ʈ �ϸ鼭 �ΰ��� �ö����� ���ڿ� �˻�
		return i;										//i�� ��ȯ
	}

	int atoi(const char* str) {							//atoi()�Լ� ����
		int result = 0;									//����� ������ ���� ����
		for (int i = 0; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++) {		//�ε����� ���� ���� �ƴϸ鼭 0~9�ε���
			result = result * 10 + (str[i] - '0');					//��� ������ ���� 10�� ���� �� �ε����� ���� �����ش�.(�ƽ�Ű ���)
		}
		return result;									//��� ������ ���� ��ȯ
	}

	float atof(const char* str) {						//atof()�Լ� ����
		int integer = 0;								//������ ����� ���� ����
		float fractional = 0;							//�Ǽ��� ����� ���� ����
		float num = 0.1;								//�Ǽ��� ����� ����
		float temp = 0;									//�Ǽ��� ����� ����
		int i = 0;
		for (i = 0; str[i] != '.' && str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++) {//.�� ���� ������ �����θ� ����
			integer = integer * 10 + (str[i] - '0');			//������ ���� 10 ���ϰ� �ε����� ���� �����ش�.(�ƽ�Ű ���)
		}
		for (int i = 0; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++) {			//�Ǽ��θ� ����
			temp = str[i] * num;								//���� �˻��ϴ� �ε����� ���� �ش� �ڸ�����ŭ�� 10�� �������� �����ش�.
			num *= 0.1;											//���� ������ ���� 10�� �������� ���������ش�.
			fractional += temp;									//�ش� �ڸ����� ���� �⺻ �ִ� ���� �����ش�.
		}
		return integer + fractional;					//�����ο� �Ǽ����� ���� ��ȯ�Ѵ�.
	}
}
