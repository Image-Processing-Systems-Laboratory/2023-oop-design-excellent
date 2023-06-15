#include "CSVLoader.h"

// ������
CSVLoader::CSVLoader()
{
	cols = 0;
	rows = 0;
	data = 0;
}

// ������ + �Ľ�
CSVLoader::CSVLoader(const char* path)
{
	cols = 0;
	rows = 0;
	data = 0;
	CSVLoader::parse(path);
}

// �Ҹ��� | �Ҵ� ����
CSVLoader::~CSVLoader()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] data[i];
	}
	delete[] data;
}

// ������ �ּ� ��ȯ
float** CSVLoader::getData() const
{
	return data;
}

// �� ��ȯ
int CSVLoader::getRows() const
{
	return rows;
}

// �� ��ȯ
int CSVLoader::getCols() const
{
	return cols;
}

// �Ľ�
void CSVLoader::parse(const char* path)
{
	// CSV ���� ��Ʈ��
	std::ifstream fin(path);
	int i = 0, j = 0;
	char file[MAX_BUFFER_SIZE];

	// ���� Ȯ��
	if (!fin.is_open())
	{
		return;
	}

	// ��� �� ũ�� ����
	fin.getline(file, MAX_BUFFER_SIZE);
	if (!fin.eof())
	{
		while (file[i] != NULL)
		{
			if (file[i] == ',')
			{
				cols++;
			}
			i++;
		}
		rows++;
		cols++;
	}
	while (!fin.eof())
	{
		fin.getline(file, MAX_BUFFER_SIZE);
		if (file[0])	rows++;
	}

	// �迭 �Ҵ�
	data = new float*[rows];
	for (i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
	}

	// ���� �б�
	fin.clear();
	fin.seekg(0);
	i = 0;
	while (!fin.eof() && i < rows)
	{
		if (j == cols - 1)
		{
			fin.getline(file, MAX_BUFFER_SIZE);
		}
		else
		{
			fin.getline(file, MAX_BUFFER_SIZE, ',');
		}
		data[i][j++] = (float)atof(file);
		if (j >= cols)
		{
			j = 0;
			i++;
		}
	}
	
	// ���� �ݱ�
	fin.close();
	return;
}

// ���
void CSVLoader::print(void)
{
	// ��Ʈ��
	std::ofstream txt("CSV2TXT.txt");
	// ���� Ȯ��
	if (!txt.is_open())
	{
		return;
	}
	// ���� ����
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			txt << data[i][j] << "\t";
		}
		txt << std::endl;
	}
	// ���� �ݱ�
	txt.close();
	return;
}
