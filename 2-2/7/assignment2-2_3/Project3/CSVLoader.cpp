#include "CSVLoader.h"

CSVLoader::CSVLoader()                    // ������ ����
{
	data = new float* [MAX_BUFFER_SIZE];   // data�� �ִ� ���� ũ�� ���� �����Ҵ� ��
	cols = 0;                              // cols, rows �ʱ�ȭ
	rows = 0;
}
CSVLoader::CSVLoader(const char* path)    //�Ű������� �ִ� ������ ����
{
	data = 0;                            // data, cols, rows �ʱ�ȭ
	cols = 0;
	rows = 0;
	ifstream read;                     // ������ �б����� ���� ����
	read.open(path);                   // path ���ڿ��� �ش��ϴ� ������ ����
	if (!read)                       // ������ ���� ��� ���� ���
	{
		cout << "Error no file";
		return;
	}
	data = new float* [MAX_BUFFER_SIZE];   // data�� �ִ� ���� ũ����� ���� �Ҵ� ����
	read.close();                        // ������ �ݾ���
}
CSVLoader::~CSVLoader()                // �ı��� ����
{
	for (int i = 0; i < rows; i++)   // �����Ҵ� ���� ��ŭ ���� ��
	{
		delete[] data[i];
	}
	delete[] data;                 // 1�������� �����Ҵ� ���� �κ��� ������
}
float** CSVLoader::getData() const    // getData �Լ� ����
{
	return data;                         //data ���� ��ȯ�� 
}
int CSVLoader:: getRows() const      // getRows �Լ� ����
{
	return rows;                // rows ���� ��ȯ��
}
int CSVLoader:: getCols() const   // getCols �Լ� ���� 
{ 
	return cols;                // cols ���� ��ȯ��
}
void CSVLoader:: parse(const char* path)   // ������ �����м��� �Լ� ����
{
	ifstream read;                // ������ �б����� Ŭ���� ����               
	read.open(path);               // �����̸��� path ���ڿ��� ���� ����
	if (!read)                   // ������ ���� ��� ���� ���
	{
		cout << "Error no file";
		return;
	}
	string parse;             // ������ ���� string ����
	int count = 0;           // ������ ���� count, countarr[20], temp ���� �� �ʱ�ȭ 
	int countarr[20] = {};
	int temp = 0;
	getline(read, parse);             // ������ ���� �о string �� ����
	count = parse.find(",", count);      // string���� ',' �� �ִ� ��ġ�� count�� ����
	countarr[temp] = count;               // count ���� �迭�� ����
	temp++;
	cols++;                         // cols�� ���� 1�ø�
	while (parse.find(",", count + 1) != string::npos)      // string�ȿ� ',' �� ���� ������ �ݺ�
	{
		count = parse.find(",", count + 1);                // ���� �ִٸ� count�� ���� �� count�� �迭�� ����
		countarr[temp] = count;
		temp++;
		cols++;                                       // cols ���� 1 �ø�
	}
	countarr[temp] = strlen(parse.c_str());         // �迭�� ������ ���� ���ڿ��� ���̷� ��
	cols++;                                           // cols ���� 1 �ø�
	data[0] = new float[cols];                       // cols �� ��ŭ ���� �����Ҵ� ����
	data[0][0] = atof(parse.substr(0, countarr[0]).c_str());   // ���ڿ��� ���ۺ��� ',' �� ���ö����� �߶� float������ �ٲ�
	for (int i = 1; i < cols; i++)                       // cols-1 ���� �ݺ�
	{
		data[0][i] = atof(parse.substr(countarr[i-1]+1, countarr[i]- countarr[i - 1]).c_str());   // ���ڿ��� ','�� ���ö����� �߶� �� ���� float�� �ٲپ� �迭�� ����
	}
	rows++;  // row ���� 1 �ø�
	while (getline(read, parse))  // ������ ������ �ݺ�
	{
		count = 0;                      
		count = parse.find(",", count);   // string���� ',' �� �ִ� ��ġ�� count�� ����
		countarr[0] = count;              // count ���� �迭�� ����
		for (int i = 1; i < cols; i++)      
		{
			count = parse.find(",", count + 1);   // ���ڿ��� ','�� �ִٸ� count�� ���� �� count�� �迭�� ����
			countarr[i] = count;
		}
		data[rows] = new float[cols];         // cols �� ��ŭ ���� �����Ҵ� ����
		data[rows][0] = atof(parse.substr(0, countarr[0]).c_str());    // ���ڿ��� ���ۺ��� ',' �� ���ö����� �߶� float������ �ٲ�
		for (int i = 1; i < cols; i++)
		{
			data[rows][i] = atof(parse.substr(countarr[i - 1] + 1, countarr[i] - countarr[i - 1]).c_str()); // ���ڿ��� ','�� ���ö����� �߶� �� ���� float�� �ٲپ� �迭�� ����
		}
		rows++;   // row ���� 1 �ø�
	}
	read.close();   // ������ �ݾ���
}
void CSVLoader::print(void)       // ���� �м��� ������ ����ϴ� �Լ� ����
{
	for (int i = 0; i < rows; i++)      // ���� �м� �� ������ ��� �� ��ŭ �ݺ��ϸ鼭 ���
	{
		for (int j = 0; j < cols; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}