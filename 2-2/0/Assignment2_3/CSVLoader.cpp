#include "CSVLoader.h"


CSVLoader::CSVLoader()	// �Ű������� ���� ������ ����
{
	data = NULL;
	rows = 0;
	cols = 0;
}
CSVLoader::CSVLoader(const char* path) //�Ű������� �ִ� ������
{
	data = NULL;
	rows = 0;
	cols = 0;
	this->parse(path);
}
CSVLoader::~CSVLoader()		// �Ҹ��ڿ��� �����Ҵ� ����
{
	for (int i = 0; i < rows; i++)
		delete[] data[i];
	delete[] data;
}

float** CSVLoader::getData() const	// data�ּ� ��ȯ
{
	return data;
}
int CSVLoader::getRows() const	// rows��ȯ
{
	return rows;
}
int CSVLoader::getCols() const	// cols ��ȯ
{
	return cols;
}

void CSVLoader::CSVLoader::parse(const char* path) // CSV�� �а� �����͸� �Ҵ���
{
	ifstream input;	// ���Ͻ�Ʈ�� ����
	input.open(path); // ���Ͻ�Ʈ���� ����
	string tmp;		// �ӽ÷� ����� tmp ���

	if (!input.is_open())	// ������ ������ �ʾ��� ����� ����
	{
		cout << "Can't open File";
		return;
	}
	while (getline(input, tmp))	//�ళ���� ���� �о��
	{
		rows++;
		if (input.peek() == EOF)	// eof�� �����ϱ� ���� ������ ����Ű�� ���� ó������ ����
		{
			input.clear();
			input.seekg(0, std::ios::beg);
			break;
		}
	}

	while (input.peek() != '\n')	// , �� ������ ���� ������ ī��Ʈ��
	{
		if (input.get() == ',')
			cols++;
	}
	cols++;
	input.seekg(0, std::ios::beg);	// ������ �⸮Ű�� ���� ó�����ε��� 
	data = new float*[rows];// ������ �о�� ��� �� ������ �������� �����Ҵ�
	for (int i = 0; i < rows; i++)
		data[i] = new float[cols];
	for (int i = 0; i < rows; i++)	// ���������� �����͸� �о��
	{
		for (int j = 0; j < cols; j++)
		{
			if (j == cols - 1)	// ������ ���Ҹ� ���� ������ ���๮�ڸ� �������� �о��
				if (i == rows - 1)
					getline(input, tmp);
				else
				getline(input, tmp, '\n');
			else
				getline(input, tmp, ',');	// �ƴ� ��쿡�� , ������ ����
			data[i][j] = stof(tmp);	// ���� ����

		}
	}

	input.close();	// ���Ͻ�Ʈ���� ����

	return;
}
void CSVLoader::print(void)	// data�� �����
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			std::cout << data[i][j]<<'\t';
		cout << endl;
	}
}
