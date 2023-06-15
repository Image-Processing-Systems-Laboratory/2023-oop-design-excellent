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

CSVLoader::CSVLoader(const char* path) //생성자 with 매개변수 + 초기화
{
	cout << "Hi coding!" << endl; 
	this->data = NULL;
	this->rows = 0;
	this->cols = 0;
	parse(path);
}

CSVLoader::~CSVLoader() //소멸자
{
	cout << "\nSeeYa!" << endl;
}

float** CSVLoader::getData() const //float형 변수로 변환한 결과를 배열로 저장
{
	return data;
}

int CSVLoader::getRows() const //가로 길이 측정
{
	return rows;
}

int CSVLoader::getCols() const //세로 길이 측정 -> 아마 getData에 사용될듯?
{
	return cols;
}

void CSVLoader::parse(const char* path) //파싱하는 것
{
	ifstream file(path);
	string line, result;

	while (getline(file, line)) //rows, cols 측정
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

	cols /= rows; //기존 cols값은 배열 요소 개수이므로 행 크기로 나눠 주면 열의 길이가 나온다.

	int row = CSVLoader::getRows();
	int col = CSVLoader::getCols();
	
	
	cout << "col: " << col << " row: " << row << endl;

	data = new float* [row];

	for (int i = 0; i < row; i++)
	{
		data[i] = new float[col];
	} //2차원 배열 동적할당

	for (int i = 0; i < row ; i++)
	{
		for (int j = 0; j < col; j++)
		{
			data[i][j] = { 0 };
		}
	} //초기화

	int k = 0;
	int i = 0;
	int j = 0;
	string value;

	int current = 0;
	int before = 0;

	while (result[i] != NULL) //, 와 개행문자를 기준으로 파싱한다.
	{
		if (result[i] == ',') // , 문자
		{
			current = i;
			value = result.substr(before , current - before); //부분 추출
			data[j][k % (col)] = stof(value); //실수형으로 전환
			before = i + 1;
			k++;
			i++;
		}
		else if (result[i] == '\n') //개행문자
		{
			current = i;
			value = result.substr(before, current - before); //부분 추출
			data[j][k % (col)] = stof(value); //실수형으로 전환
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

void CSVLoader::print(void) //그냥 뭐 결과 출력하는 함수
{
	int row = getRows(); //rows값을 불러온다
	int col = getCols(); //cols값을 불러온다

	for (int i = 0 ; i < row ; i++)
	{
		for (int j = 0; j < col ; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}