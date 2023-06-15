#include "CSVLoader.h"

using namespace std;

CSVLoader::CSVLoader()
{
	data = 0;
	cols = 0;
	rows = 0;
	// �Է¹��� path�� �����Ƿ� �׳� ���� �ʱ�ȭ
}

CSVLoader::CSVLoader(const char* path)
{
	parse(path); // parse �Լ��� data ���� �ʱ�ȭ
}

CSVLoader::~CSVLoader()
{
	delete[]data[0];
	delete[]data; // data ������ �Ҵ���� �޸� ����
}

float** CSVLoader::getData() const
{
	return (data);
}

int CSVLoader::getRows() const
{
	return (rows);
}

int CSVLoader::getCols() const
{
	return (cols);
}

void CSVLoader::parse(const char* path)
{
	ifstream fin;
	string arr[100];
	int i;

	fin.open(path); // CSV ������ ���� ��Ʈ�� ����
	for (i = 0; !fin.eof(); i++)
	{
		getline(fin, arr[i]); // �� ���ξ� �д´�
		if (arr[i] == "") // �������� �� ���ڸ� �д´ٸ� �̴� �Ľ��� ����� �ƴ�
			i--;
	}
	rows = i; // row �ʱ�ȭ
	cols = return_cols(arr[0]); // column �ʱ�ȭ
	data = new float* [rows];
	data[0] = new float[rows * cols]; // �޸� ���� ���Ǹ� ���� ����ó�� �Ҵ�
	for (int i = 1; i < rows; i++)
		data[i] = data[i - 1] + cols; // 2���� �迭 �Ҵ�
	for (int j = 0; j < rows; j++)
	{
		i = 0;
		for (int k = 0; k < cols; k++)
		{
			data[j][k] = atof(arr[j].c_str() + i); // ������ �ڿ� �޸��� atof�� ���� ����
			while (arr[j][i] != ',' && i < arr[j].length())
				i++; // �޸��� �����ų� �� ���� ������ �� ������ ����
			if (i < arr[j].length())
				i++; // ���������� ���� ���� �ƴϸ� ���� ĭ �б�(�޸��� �ƴ� ���� �������� ����)
		}
	}
	fin.close(); // ���� ��Ʈ�� �ݱ�
}

void CSVLoader::print(void) // 2���� �迭 ��� �Լ�
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << data[i][j] << " ";
		cout << endl;
	}
}


int CSVLoader::return_cols(string str)
{
	int cnt = 0;

	for (int i = 0; i < str.length(); i++) // �� ������ ��ȸ
	{
		if (str[i] == ',')
			cnt++; // �޸��� ������ ��
	}
	return (cnt + 1); // �޸��� ���� + 1 == �� ������ �������� ���� == column
}