#include "CSVLoader.h"
CSVLoader::CSVLoader()
{
	cols = 0;
	rows = 0;
	data = NULL;
}
CSVLoader::CSVLoader(const char* path)
{
	data = NULL;
	cols = 0;
	rows = 0;
	parse("CSVLoader_Data.txt");
}
CSVLoader::~CSVLoader()
{
	for (int i = 0; i < rows; i++)
		delete[] data[i];
	delete[] data;
}
float** CSVLoader::getData() const
{
	return data;				//private�� data �� �ҷ�����
}
int CSVLoader::getRows() const
{
	return rows;				//private�� rows �� �ҷ�����
}
int CSVLoader::getCols() const
{
	return cols;				//private�� cols �� �ҷ�����
}
void CSVLoader::parse(const char* path)
{
	int i, j = 0, cnt = 0, key = 0, k = 0;
	//������ ������ �Է¹��� ���� ������ ���� �޸��Ҵ�
	char** DATA = new char* [MAX_BUFFER_SIZE];
	for (i = 0; i < MAX_BUFFER_SIZE; i++)
		DATA[i] = new char[MAX_BUFFER_SIZE];
	//������ �Է¹ޱ� ���� �б� ��Ʈ�� �����Ͽ� ������ ���� 2���� ���ڿ� �迭�� ���� ���� �Է�
	ifstream fin;
	fin.open("CSVLoader_Data.txt");
	if (!fin)
	{
		cout << "Error" << std::endl;
	}
	i = 0;
	while (!fin.eof())
	{
		fin.getline(DATA[i], MAX_BUFFER_SIZE);
		i++;		//�� ����
	}
	i--;	//97��+1 ���� eof üũ�߱� ������ -1
	while (DATA[k][j] != NULL)
	{
		if (DATA[k][j] != ',' && DATA[k][j] != ' ' && key == 0)		//,�� ������ �Էµ��� �ʾҴٸ� = ������
		{
			key = 1;												//���������� Ȯ���ϴ� Ű
		}
		if (key == 1 && (DATA[k][j] == ',' || DATA[k][j] == ' ' || DATA[k][j + 1] == NULL))		//�����Ͱ� ,�� ������ �����ų� ���ڿ��� �� �ٷ� �����̸�
		{

			key = 0;																			//�����Ͱ� ����
			cnt++;																		//�������� ����
		}
		j++;
	}
	//���Ͽ��� �Է¹޾ƿ��鼭 ���� ��,�� ���� ���� �� CSV�� ���� ���� data ���� ������ ������ �޸� �Ҵ�
	rows = i;
	cols = cnt;
	data = new float* [rows];
	for (i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
	}
	key = 0;
	k = 0;
	//��� ���� ���̸�ŭ float ������ �ٲپ� �Է�
	for (i = 0; i < rows; i++)
	{
		j = 0;
		k = 0;
		while (DATA[i][k] != NULL)
		{
			if (DATA[i][k] != ',' && DATA[i][k] != ' ' && key == 0)
			{
				key = 1;
				data[i][j] = atof(DATA[i]);						//�����͸� float���� ������ private data�� �Է�
				j++;
			}
			if (key == 1 && (DATA[i][k] == ',' || DATA[i][k] == ' ' || DATA[i][k + 1] == NULL))
			{
				key = 0;
			}
			DATA[i][k] = ' ';
			k++;
		}
	}
	fin.close();
	for (i = 0; i < MAX_BUFFER_SIZE; i++)
		delete[] DATA[i];
	delete[] DATA;
}
void CSVLoader::print(void)
{
	for (int i = 0; i < rows; i++)
	{
		cout << i+1 << ": ";
		for (int j = 0; j < cols; j++)
		{
			cout << data[i][j] << "  ";
		}
		cout << endl;
	}
}
