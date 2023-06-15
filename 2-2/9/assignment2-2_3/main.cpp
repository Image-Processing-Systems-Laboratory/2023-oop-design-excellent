#include "CSVLoader.h"
#include <iostream>

using namespace std;

int main(void) {
	CSVLoader csv;     //CSVLoader Ŭ������ ��ü ����

	cout << "���� ��: " << csv.getRows() << endl; //rows ���
	cout << "���� ��: " << csv.getCols() << endl; //cols ���

	cout << endl << "data:" << endl;
	csv.print();           //data ��� ���

	cout << endl << "data[0][0]:" << endl;
	cout << csv.getData()[0][0];      //data[0][0] ���

	return 0;
}