#include <iostream>
#include <cstdio>
#include "NestedArray.h"

using namespace std;

char input[100000];                                     //��ɾ ������ �迭

int compare_str(const char* str1, const char* str2);    //�� ���ڿ��� ���ϴ� �Լ�
NestedArray* allocation(int index);                     //�޸� �Ҵ� �� �� ���� �Լ�
void find(NestedArray* arr, int index);                 //�Է��� ��ɾ��� ÷�ڿ� ���� �ش� ���� ã�� �Լ�
void printStr(NestedArray* arr);                        //���ڿ� ��� �Լ�
void printArray(NestedArray* arr);                      //�迭 ��� �Լ�
void memory_free(NestedArray* arr);                     //�Ҵ�� �޸� ���� �Լ�

int main(void) {
	NestedArray* nestedarray;                    //NestedArray Ŭ������ ������ ���� ����
	int i, j;
	char temp[5];                                //���ڿ��� �ӽ� ������ �迭

	gets_s(input, 100000);                       //�迭 ���� ��ɾ� �Է� �ޱ�

	i = 0;
	while (input[i] == ' ') {                    //���� �����ϱ�
		i++;
	}

	nestedarray = allocation(i + 1);             //�޸� �Ҵ�
	
	while (1) {
		gets_s(input, 100000);                   //�迭 ���� ��ɾ� �Է�
		i = 0;
		j = 0;

		while (input[i] == ' ') {                //���� �����ϱ�
			i++;
		}

		while ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {   //���� �ҹ��� �Ǵ� �빮���� ���
			temp[j] = input[i];                  //temp�� �ӽ� ����
			j++;
			i++;
		}
		temp[j] = '\0';                          //temp�� �������� NULL ���� ����

		if (!compare_str(temp, "exit")) {        //exit �Է��� ���
			break;                               //�ݺ��� ����
		}
		else if (!compare_str(temp, "arr")) {    //�Է��� ���ڿ��� ù�κ��� arr�� ���
			while (input[i] == ' ') {            //���� �����ϱ�
				i++;
			}

			if (input[i] == '[') {               //÷�ڰ� ���� ���
				find(nestedarray, i + 1);        //÷�ڿ� �´� �� ã��

				cout << endl;
			}
			else if (input[i] == '\0') {         //÷�ڰ� ���� ���
				printArray(nestedarray);         //�迭�� ��� �� ���

				cout << endl;
			}
		}
	}

	memory_free(nestedarray);                    //�޸� ����

	return 0;
}

//�� ���ڿ��� ���ϴ� �Լ�
int compare_str(const char* str1, const char* str2) {
	int i = 0;

	while (1) {
		if (str1[i] != str2[i] || (str1[i] == '\0' && str2[i] == '\0')) {  //���ڿ��� �����ų� ���� ���� ���ڸ� ���� ������ �ݺ�
			if (str1[i] > str2[i]) {         //str1[i]�� �ƽ�Ű�ڵ� ���� str2[i]���� ū ��� 1 ��ȯ
				return 1;
			}
			else if (str1[i] < str2[i]) {    //str2[i]�� �ƽ�Ű�ڵ� ���� str1[i]���� ū ��� -1 ��ȯ
				return -1;
			}
			else {                           //���� ���ڿ��̸� 0 ��ȯ
				return 0;
			}

		}

		i++;
	}
}

//�޸� �Ҵ� �� �� ���� �Լ�
NestedArray* allocation(int index) {
	NestedArray* address;             //�Ҵ��� �޸𸮸� ������ ������ ����
	int num_in_bracket = 0;           //input���� �迭 �ȿ� �迭�� �ִ��� �Ǻ�
	int count = 0;                    //�� �迭�� �޸� ����
	static int current;               //���� ��ġ�� ÷��
	char temp_str[21];                //���ڿ��� �ӽ� ������ �迭
	int i = 0, j = 0;

	//���� ���� ����
	current = index;
	while (1) {
		if (input[current] == '[') {             //���� ���ȣ�� ������ ���(array�ȿ� array�� ����)
			num_in_bracket++;
		}
		else if (input[current] == ']') {        //�ݴ� ���ȣ�� ������ ���
			if (num_in_bracket == 0) {           //���� �ٱ� ���ȣ���� ��� �ݺ��� ����
				break;
			}
			else {                               //array�ȿ� �����ϴ� array�� ���ȣ���� ���
				num_in_bracket--;
			}
		}
		else if (input[current] == ',') {        //�޸��� ������ ���
			if (num_in_bracket == 0) {           //���� �迭�� �޸��� �ƴ� ���
				count++;
			}
		}

		current++;
	}     // -> count�� �迭�� ���� ��(array�� �ϳ��� ������ ���)���� 1 ���� ���� ������ �ȴ�.
	
	address = new NestedArray[count + 1];            //���� ����ŭ �޸� �Ҵ�
	address[count].setEnd();                         //������ ��ҿ� ���������� ǥ��

	//�Ҵ��� �޸𸮿� ���ڿ� �Ǵ� �迭 �����ϱ�
	current = index;
	while (1) {
		if ((input[current] >= 'a' && input[current] <= 'z') || (input[current] >= 'A' && input[current] <= 'Z')) {  //���� �빮�� �Ǵ� �ҹ����� ���
			temp_str[i] = input[current];                  //temp_str�� �ӽ� ���� 
			i++;
		}
		else if (input[current] == '[') {                  //���� ���ȣ�� ���
			address[j].setArray(allocation(current + 1));  //allocation �Լ��� ��� ȣ���Ͽ� �迭 �Ҵ� �� �� �ּҸ� ����
			j++;
			current++;
			while (input[current] == ' ') {                //���� �����ϱ�
				current++;
			}
			if (input[current] == ']') {                   //�ݴ� ���ȣ�� ��� �ݺ��� ����
				break;
			}
		}
		else if (input[current] == ',' || input[current] == ']') {   //�ݴ� ���ȣ �Ǵ� �޸��� ���
			temp_str[i] = '\0';                  //�������� NULL ���� ����
			address[j].setStr(temp_str);         //���ڿ� ����

			i = 0;
			j++;
			if (input[current] == ']') {         //�ݴ� ���ȣ�� ��� �ݺ��� ����
				break;
			}
		}

		current++;
	}

	return address;                              //�Ҵ��� �޸��� �ּ� ��ȯ
}

//�Է��� ��ɾ��� ÷�ڿ� ���� �ش� ���� ã�� �Լ�
void find(NestedArray* arr, int index) {
	int number = 0;                 //�Է��� ÷�ڸ� ������ ��ȯ�Ͽ� ����
	int start;                      //������ ���� ��ġ
	int exponent = 1;               //�ڸ���
	bool end = true;                //�Է��� ÷�ڰ� ��� �������� ǥ��

	while (input[index] == ' ') {      //���� �����ϱ�
		index++;
	}

	start = index;  //������ ���� ��ġ ����

	//������ ������ ��ġ�� �̵�
	while (input[index] >= '0' && input[index] <= '9') {
		index++;
	}

	//���� ���
	for (int j = index - 1; j >= start; j--) {
		number = number + (input[j] - '0') * exponent;  //�ش� �ڸ����� ���Ͽ� ���ϱ�
		exponent *= 10;
	}

	//���� �Ǵ� �ݴ� ���ȣ �����ϱ�
	while (input[index] == ' ' || input[index] == ']') {
		index++;
	}

	//���� ���ȣ�� ���� ��� (���� ÷�ڰ� ����)
	if (input[index] == '[') {
		find((arr + number)->getArray(), index + 1);  //÷�ڿ� �ش��ϴ� �ּҿ� ����� �� �迭�� �ּҸ� ���ڷ� �����Ͽ� find �Լ� ��� ȣ��
		end = false;                                  //���� �ƴ��� ǥ��
	}

	if (end) {                                           //�Է��� ÷�ڰ� ������ ���
		if ((arr + number)->getStr()[0] != '\0') {       //÷�ڿ� �ش��ϴ� �ּҿ� ����� ���ڿ��� ù��° ���� NULL ���ڰ� �ƴ� ���(���ڿ��� ����Ǿ� �ִ� ��ü)
			printStr(arr + number);                      //÷�ڿ� �ش��ϴ� �ּҿ� ����� ���ڿ� ���
		}
		else {                                           //�� �迭�� �ּ� ���� ����Ǿ� �ְų� �� �迭
			printArray((arr + number)->getArray());      //�迭 ���
		}
	}
}

//���ڿ� ��� �Լ�
void printStr(NestedArray* arr) {
	cout << arr->getStr();             //arr �ּ��� ��ü�� ���ڿ� ���
}

//�迭 ��� �Լ�
void printArray(NestedArray* arr) {
	int i = 0;
	
	cout << '[';

	while (1) {
		if ((arr + i)->getArray() != NULL) {                //arr + i �ּ��� ��ü�� ���� �迭�� �ּҰ� ����Ǿ� ���� ��
			printArray((arr + i)->getArray());              //���� �迭�� �ּҸ� ���ڷ� �����Ͽ� printArray �Լ� ��� ȣ�� -> �� �迭 ���
		}
		else if ((arr + i)->getStr()[0] != '\0') {          //arr + i �ּ��� ��ü�� ���ڿ��� ����Ǿ� ���� ��
			printStr(arr + i);                              //�ش� ���ڿ� ���
		}
		else {                                              //�� �迭�� ��� �ݺ��� ����
			break;
		}
		
		if ((arr + i)->getEnd() == true) {                  //arr + i �ּ��� ��ü�� ������ ����� ��� �ݺ��� ����
			break;
		}
		else {                                              //arr + i �ּ��� ��ü�� ������ ��Ұ� �ƴ� ���
			cout << ", ";
		}

		i++;
	}

	cout << ']';
}

//�Ҵ�� �޸� ���� �Լ�
void memory_free(NestedArray* arr) {
	int i = 0;

	while (1) {
		if ((arr + i)->getArray() != NULL){              //arr + i �ּ��� ��ü�� ���� �迭�� �ּҰ� ����Ǿ� ���� ��
			memory_free((arr + i)->getArray());          //���� �迭�� �ּҸ� ���ڷ� �����Ͽ� memory_free �Լ� ��� ȣ�� -> �� �迭�� �޸� ����
		}

		if ((arr + i)->getEnd() == true) {               //arr + i �ּ��� ��ü�� ������ ����� ��� �ݺ��� ����
			break;
		}

		i++;
	}

	delete[] arr;                                         //arr �޸� ����
}