#include "NestedArray.h"

//������
NestedArray::NestedArray() {
	str[0] = '\0';
	array = 0;
	end = false;
}

//array�� �� ����
void NestedArray::setArray(NestedArray* array) {
	this->array = array;           //array�� �� ����
}

//str�� �� ����
void NestedArray::setStr(char* str) {
	int i = 0;

	while (1) {
		this->str[i] = str[i];    //�� ����

		if (str[i] == '\0') {
			break;                //���ڿ��� ���� ������ ��� �ݺ� ����
		}

		i++;
	}
}

//�迭�� ���������� ǥ��
void NestedArray::setEnd(void) {
	end = true;                //end�� true ����
}

//array �� ��ȯ
NestedArray* NestedArray::getArray(void) {
	return array;              //array �� ��ȯ
}

//str �� ��ȯ
char* NestedArray::getStr(void) {
	return str;                //str �� ��ȯ
}

//end �� ��ȯ
bool NestedArray::getEnd(void) {
	return end;                //end �� ��ȯ
}