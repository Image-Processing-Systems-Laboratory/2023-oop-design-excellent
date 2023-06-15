#define _CRT_SECURE_NO_WARNINGS
#include "CSVLoader.h"

using namespace std;

CSVLoader::CSVLoader() {	//���� X ������
	cout << "CSVLoader is working without path" << endl;	//��ΰ� ���ٰ� �˷���
	cols = 0;
	rows = 0;
	data = NULL;
}
CSVLoader::CSVLoader(const char* path) {	//���� O ������
	cout << "CSVLoader is working ( path : " << path << " )" << endl;	//�ش� ��η� ������ �м��Ѵٰ� ���
	cols = 0;
	rows = 0;
	data = NULL;
	parse(path);	//������ �м�
}
CSVLoader::~CSVLoader() {	//�Ҹ���
	cout << "CSVLoader is not working" << endl;		//�۵� ���� ���
	delete[] data[0];	//�޸� �Ҵ� ����
	delete[] data;		
}

float** CSVLoader::getData() const {	//Ŭ���� ���� data �� ��ȯ
	return data;
}
int CSVLoader::getRows() const {		//Ŭ���� ���� rows �� ��ȯ
	return rows;
}
int CSVLoader::getCols() const {		//Ŭ���� ���� cols �� ��ȯ
	return cols;
}

void CSVLoader::parse(const char* path) {	//path�� ���Ͽ��� ������ �м� �� ����
	ifstream input;
	input.open(path);		//���� ����

	char* tmp = new char[MAX_BUFFER_SIZE];		//���� ������ ��ŭ �޸� �Ҵ�
	char tmpc = '1';
	char* p;
	int row = 0;
	int col = 1;
	while (input.get(tmpc)) {	//�� ���ھ� �Է� �޾� �ݺ�
		if (tmpc == ',')				// , �̸� �� 1 ����
			col++;
		else if (tmpc == '\n') {		// �����̸� �� 1 ����, Ŭ���� ���� ������ col���� �� col�ʱ�ȭ
			row++;
			cols = col;
			col = 1;
		}
	}

	rows = row;	//���� ���� �� ����

	//data�� [rows*cols]��ŭ ���� �Ҵ�
	data = new float* [rows];
	data[0] = new float[rows * cols];
	for (int i = 1; i < rows; i++) {
		data[i] = data[i - 1] + cols;
	}
	

	row = 0;
	col = 0;
	input.clear();
	input.seekg(0);
	while (!input.eof()) {		//�� �پ� �Է� �޾� , �� ���ڿ� �����ϰ� atof�� float������ ��ȯ�Ͽ� data�� ����
		input >> tmp;
		p = strtok(tmp, ",");
		while (p) {
			data[row][col++] = atof(p);
			p = strtok(NULL, ",");
		}
		row++;
		col = 0;
	}
	input.close();
	delete[] tmp;
}
void CSVLoader::print() {					//�� �ٿ� �� �྿ ���
	for (int i = 0; i < rows; i++) {
		cout << i + 1 << " :\t";
		for (int j = 0; j < cols; j++) {
			cout << data[i][j] << '\t';
		}
		cout << endl;
	}
}