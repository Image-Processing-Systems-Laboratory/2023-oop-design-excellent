#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char data[100];
	char text_name[100];
	int compare_num = 0;
	char wildcard[10][100];
	//�̸��� üũ���� �Ҹ���
	bool isIncluded = false;
	ifstream fin;

	fin.open("filename_list.txt");

	//������ ������ ���� ���
	if (!fin) {
		cout << "Error : no such file in directory." << endl;
	}

	//�ʿ��� ���� �Է¿䱸
	cout << "Input file name : ";
	cin >> text_name;
	cin >> compare_num;

	for (int i = 0; i < compare_num; i++) {
		cin >> wildcard[i];
	}

	//Check Wildcard Pattern

	while (!fin.eof()) {
		fin.getline(data, 100, '\n');
		
		
		for (int i = 0; i < compare_num; i++) {
			for (int j = 0; data[j] != '\0'; j++) {
				// ���� ���ڸ� ���
				if (data[j] == wildcard[i][j]) {
					isIncluded = true;
				}
				// *�̸� ������ ���ڿ� ���� Ŀ��
				else if (wildcard[i][j] == '*') {
					isIncluded = true;
					break;
				}
				// ? �� ���
				else if (wildcard[i][j] == '?') {
					isIncluded = true;
				}
				else {
					isIncluded = false;
					break;
				}
			}
			// true�� ������ ������ ���δ� ���ԵǴ� ����̹Ƿ� ���
			if (isIncluded == true) {
				cout << data << endl;
				isIncluded == false;
			}
		}
	}
	fin.close();
	return 0;
}