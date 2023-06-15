#define _CRT_SECURE_NO_WARNINGS
#include "CSVLoader.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

CSVLoader::CSVLoader()
{
	cout << "Hi coding!" << endl;
	this->data = NULL;
	this->rows = 0;
	this->cols = 0;
}

CSVLoader::CSVLoader(const char* path) //������ with �Ű����� + �ʱ�ȭ
{
	cout << "Hi coding!" << endl; 
	this->data = NULL;
	this->rows = 0;
	this->cols = 0;
	parse(path);
}

CSVLoader::~CSVLoader() //�Ҹ���
{
	cout << "\nSeeYa!" << endl;
}

float** CSVLoader::getData() const //float�� ������ ��ȯ�� ����� �迭�� ����
{
	return data;
}

int CSVLoader::getRows() const //���� ���� ����
{
	return rows;
}

int CSVLoader::getCols() const //���� ���� ���� -> �Ƹ� getData�� ���ɵ�?
{
	return cols;
}

void CSVLoader::parse(const char* path) //�Ľ��ϴ� ��
{
	ifstream file(path);
	string line, result;

	while (getline(file, line)) //rows, cols ����
	{
		for (char comma : line)
		{
			if (comma == ',')
			{
				cols++;
			}
		}
		rows++;
		cols++;
		result += line + '\n';
	}

	cols /= rows; //���� cols���� �迭 ��� �����̹Ƿ� �� ũ��� ���� �ָ� ���� ���̰� ���´�.

	int row = CSVLoader::getRows();
	int col = CSVLoader::getCols();
	
	
	cout << "col: " << col << " row: " << row << endl;

	data = new float* [row];

	for (int i = 0; i < row; i++)
	{
		data[i] = new float[col];
	} //2���� �迭 �����Ҵ�

	for (int i = 0; i < row ; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] = { 0 };
		}
	} //�ʱ�ȭ

	int k = 0;
	int i = 0;
	int j = 0;
	string value;

	int current = 0;
	int before = 0;

	while (result[i] != NULL) //, �� ���๮�ڸ� �������� �Ľ��Ѵ�.
	{
		if (result[i] == ',') // , ����
		{
			current = i;
			value = result.substr(before , current - before); //�κ� ����
			data[j][k % (col)] = stof(value); //�Ǽ������� ��ȯ
			before = i + 1;
			k++;
			i++;
		}
		else if (result[i] == '\n') //���๮��
		{
			current = i;
			value = result.substr(before, current - before); //�κ� ����
			data[j][k % (col)] = stof(value); //�Ǽ������� ��ȯ
			j++;
			before = i + 1;
			i++;
			k = 0;
		}
		else
		{
			i++;
		}
	}

	print();
}

void CSVLoader::print(void) //�׳� �� ��� ����ϴ� �Լ�
{
	int row = getRows(); //rows���� �ҷ��´�
	int col = getCols(); //cols���� �ҷ��´�

	for (int i = 0 ; i < row ; i++)
	{
		for (int j = 0; j < col ; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}