#include "CSVLoader.hpp"
#include <iostream>

CSVLoader::CSVLoader() // ������
	:data(NULL), rows(0), cols(0)
{}

CSVLoader::CSVLoader(const char* path) // ���� �̸��� ���ڷ� �޴� ������
	:data(NULL), rows(0), cols(0)
{
	parse(path); //������ �Ľ�
}

CSVLoader::~CSVLoader() // �Ҹ���
{
	if (!data) // data�� null�� ��� ������ ���� ����
		return;
	for (int i = 0; i < getRows(); i++) // data�� �Ҵ�� ���� ����
	{
		delete[] data[i];
	}
	delete[] data;
}

float** CSVLoader::getData() const // data getter
{
	return (data);
}

int CSVLoader::getRows() const // rows getter
{
	return (rows);
}

int CSVLoader::getCols() const // cols getter
{
	return (cols);
}

void CSVLoader::print(void) // data ���
{
	int row_val = getRows();
	int col_val = getCols();

	for (int i = 0; i < row_val; i++) // data�� ,�� �������� ������ ���
	{
		for (int j = 0; j < col_val; j++)
		{
			std::cout << data[i][j];
			if (j != col_val - 1)
				std::cout << ',';
		}
		std::cout << std::endl;
	}
}

void CSVLoader::parse(const char* path) // ������ ���� �Ľ�
{
	if (data) // ���� data�� ���� ��� ����
	{
		for (int i = 0; i < getRows(); i++)
		{
			delete[] data[i];
		}
		delete[] data;
	}
	std::ifstream ifs(path); // ���� ��
	char input[MAX_BUFFER_SIZE]; // �Է¹��� ����
	char* temp;

	if (!ifs.is_open()) // ���� open ����
	{
		std::cerr << "file open error" << std::endl;
		return;
	}
	rows = 0; // ���� ����
	cols = 1; // ���� ����
	ifs.getline(input, MAX_BUFFER_SIZE); // �� ���� ����
	for (int i = 0; input[i]; i++)
	{
		if (input[i] == ',') // ��ǥ�� ������ ���� �� �� �� �ִٴ� �ǹ�
			cols++;
	}
	while (ifs) // ������ ���� ������
	{
		rows++;
		ifs.getline(input, MAX_BUFFER_SIZE); // �� �پ� ������ �� �� ��
	}
	ifs.clear(); // eof�÷��� ����
	ifs.seekg(0); // ������ ó������ �ǵ���
	// ��� ����ŭ ���� �Ҵ�
	data = new float* [getRows()];
	for (int i = 0; i < getRows(); i++)
	{
		data[i] = new float[getCols()];
		ifs.getline(input, MAX_BUFFER_SIZE); // �� �� �б�
		temp = input;
		for (int j = 0; j < getCols(); j++)
		{
			data[i][j] = atof(temp); // entry �� �� �б�
			while (*temp && *temp != ',')// ���� entry�� temp������ �̵�
				temp++;
			if (*temp == ',') // ��ǥ�� ��� �� ĭ �� �̵�
				temp++;
		}
	}
	ifs.close(); // ���� �ݱ�
}