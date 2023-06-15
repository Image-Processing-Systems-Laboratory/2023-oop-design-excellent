#include"CSVLoader.h"
/*
* CSVLoader �� �޼ҵ� ���Ǻ�
*/

//������
CSVLoader::CSVLoader() {
	//�ִ� ���� ������ �� ������ŭ ���� �Ҵ�
	data = (float**)calloc(sizeof(float*), MAX_BUFFER_SIZE);
	*data = (float*)calloc(sizeof(float*), MAX_BUFFER_SIZE * MAX_BUFFER_SIZE);
	//�迭 ���·� ��ȯ
	for (int i = 1; i < MAX_BUFFER_SIZE; i++) {
		data[i] = data[i - 1] + MAX_BUFFER_SIZE;
	}
}
//������ (�Ľ��� ���ÿ� ����)
CSVLoader::CSVLoader(const char* path) {
	//�ִ� ���� ������ �� ������ŭ ���� �Ҵ�
	data = (float**)calloc(sizeof(float*), MAX_BUFFER_SIZE);
	*data = (float*)calloc(sizeof(float*), MAX_BUFFER_SIZE * MAX_BUFFER_SIZE);
	//�迭 ���·� ��ȯ
	for (int i = 1; i < MAX_BUFFER_SIZE; i++) {
		data[i] = data[i - 1] + MAX_BUFFER_SIZE;
	}
	//�Ľ� �޼ҵ� ȣ��
	parse(path);
}
//�Ҹ���
CSVLoader::~CSVLoader() {
	//���� ���� ��� ����
	if (*data)
		free(*data);
	if (data)
		free(data);
}

//�������� �ּ� ��ȯ
float** CSVLoader::getData() const {
	return data;
}

//���� ũ�⸦ ��ȯ
int CSVLoader::getRows() const {
	return rows;
}

//���� ũ�⸦ ��ȯ
int CSVLoader::getCols() const {
	return cols;
}

//�Ľ��� �ϴ� �޼ҵ�
void CSVLoader::parse(const char* path) {
	//���� �޸� �Ҵ翡 ������ �־��ٸ� ����
	if (!data || !*data)
		return;
	//�⺻ ���� ũ��
	rows = 0;
	//�⺻ ���� ũ��
	cols = 0;
	//���� ��Ʈ�� ����, ���� Ȯ��
	ifstream in(path);
	if (!in)
		return;
	//������ �� ���� ���� ���ڿ� ����
	string s;
	//���� ũ�⸦ ã������ �����ϴ� ����
	bool isRowsEnd = false;
	//���� ������ Ž��
	while (!in.eof()) {
		//���� ���� ������ ����
		int r = 0;
		//�Է�
		in >> s;
		//���ڿ��� ���� Ž������ ������ ��ġ ����
		int cnt = 0;
		//float�� ��ȯ�ϱ� ���� �ӽ� ���ڿ� ����
		string tmp;
		//������ ������ �ݺ�
		while (s[cnt]) {
			// , �� �ƴϸ� �� ������ �� �Է��� cnt��° ���� �߰�
			if (s[cnt] != ',') {
				tmp.push_back(s[cnt]);
			}
			//,�� �����ٸ�
			else {
				//data�� c�� r ���� �ӽ� ������ ���ڿ��� flaot���� ��ȯ�Ͽ� ����
				data[cols][r] = stof(tmp);
				//�ӽú��� �ʱ�ȭ
				tmp = "";
				//���� ���� ����
				r++;
			}
			cnt++;
		}
		//���� ,�� �ƴ� ' '�� �����ٸ�  �ӽ� ������ ���ڿ��� flaot���� ��ȯ�Ͽ� ����
		data[cols][r] = stof(tmp);
		r++; 
		//�� ũ�Ⱑ ���������ٸ� ����
		if (!isRowsEnd) {
			//���� ũ�⸦ ���ٿ� ������ �������� ������ ����
			rows = r;
			//�������� ����
			isRowsEnd = true;
		}
		//���� ũ�⸦ �Ѱ��� ����.
		cols++;
	}
	//���� ��Ʈ�� ����
	in.close();
}
//������ ���
void CSVLoader::print() {
	//���� ũ�⸸ŭ �ݺ�
	for (int i = 0; i < cols; i++) {
		//���� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < rows; j++) {
			//ù��°�� �ƴϸ� ", "���
			if (j)
				cout << ", ";
			//�� ���
			cout << data[i][j];
		}
		//�ٳѱ�
		cout << endl;
	}
}