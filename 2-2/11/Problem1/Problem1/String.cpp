#include "Array.h"

//String class �� ���Ǻ�

//������
String::String(char* &input) {
	// ��ĭ�̳� , ] null Ȥ�� input�� ���� ������ 20�� �ѱ�� ������ �ݺ�
	for (int i = 0; i < 20 && (*input != ' ' && *input != ',' && *input != ']') && *input; i++) {
		//���ʷ� ����
		str[i] = *(input++);
	}
}
//������ ���(���ڿ����� �ε����� �ʿ� ����.)
void String::printData(int* index, int cnt) {
	printData();
}
//���ڿ��� �����ߴ� �ɹ� ���� ��ȯ
void String::printData() {
	cout << str;
}
