#define _CRT_SECURE_NO_WARNINGS 
#include "csv.h"



csv:: csv(const char* path) {

	fstream input_file;//���� ��Ʈ�� 
	input_file.open(path);
	string line;
	

	if (input_file.fail()) {// ������ ������ ���� ��� ���� �޽����� ����ϰ� ���α׷� ����
		cout << "invalid value";
		exit(true);
	}


	std::getline(input_file, line);// ù���� �޸� ������ ���� ��ü ���� ���� ����
	for (char C : line) {
		if (C == ',') {// �޸� ������ �������� ���� ������ ����
			col++;
			
		}
	}





	while (!input_file.eof()) {
		std::getline(input_file, line);
		row++;
	}//���� ���� ����


	input_file.close();// ���� �ݱ�

}

csv::~csv() {

	for (int i = 0; i < row; i++) {
		delete[] data[i];
	}

	delete[] data;// ���� �Ҵ��� �޸� ����


}



void csv:: parse(const char* path) {
	fstream input_file;
	string line;

	
	
	
	data = new float* [row];// ��������� �޸𸮰� �Ҵ�
	
	for (int i = 0; i < row; i++) {
		data[i] = new float[col];
	}

	

	input_file.open(path);// ���� ����


	if (input_file.fail()) {// �ȿ����� ���� ����� ���α׷� ����
		cout << "invalid value";
		exit(true);
	}

	for (int i = 0; i < row; i++) {
		int index = 0;
		char buf[128] = { NULL };
		int buf_index = 0;

		getline(input_file, line);//���Ϸ� ���� ���� �� �о����


		for (char C:line) {


			if (C == ',') {

				
				data[i][index] = atof(buf);
				strncpy(buf, "\0", 128);
				buf_index = 0;
				index++;
				continue;//��ǥ�� ������� ���ڿ� �Ǽ��� ��ȯ

				
			
			}

		
			buf[buf_index] = C;
			buf_index++;

		}
	
		data[i][col - 1] = atof(buf);// �� ������ ���ڿ� �Ǽ��� ��ȯ �� ��������� ����Ű�� �޸𸮿� �Ҵ�

	}


	input_file.close();// ���� �ݱ�
	





}


void csv::print() {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (data[i][j]==NULL) {
				cout << ",";
			}
			else if (j != col -1) {
				cout << data[i][j] << ",";//�������� �ƴ϶�� �޸� ���
			}
			else {
				cout << data[i][j];//�������̶�� �޸��� ������� ����
			}

		}

		cout << endl;
	}



}