#include "csv.h"


int main() {

	char input_file[100] = { 0 };


	cout << "Enter name of file: ";
	cin >> input_file;

	csv object(input_file);// ��ü ����
	object.parse(input_file);// ���Ϸ� ���� �Ǽ����� �о����
	object.print();// ��������� ����� �� ���



}