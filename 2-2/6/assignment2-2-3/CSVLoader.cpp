#include "CSVLoader.h"

// 생성자
CSVLoader::CSVLoader()
{
	cols = 0;
	rows = 0;
	data = 0;
}

// 생성자 + 파싱
CSVLoader::CSVLoader(const char* path)
{
	cols = 0;
	rows = 0;
	data = 0;
	CSVLoader::parse(path);
}

// 소멸자 | 할당 해제
CSVLoader::~CSVLoader()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] data[i];
	}
	delete[] data;
}

// 데이터 주소 반환
float** CSVLoader::getData() const
{
	return data;
}

// 행 반환
int CSVLoader::getRows() const
{
	return rows;
}

// 열 반환
int CSVLoader::getCols() const
{
	return cols;
}

// 파싱
void CSVLoader::parse(const char* path)
{
	// CSV 파일 스트림
	std::ifstream fin(path);
	int i = 0, j = 0;
	char file[MAX_BUFFER_SIZE];

	// 파일 확인
	if (!fin.is_open())
	{
		return;
	}

	// 행과 열 크기 측정
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

	// 배열 할당
	data = new float*[rows];
	for (i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
	}

	// 파일 읽기
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
	
	// 파일 닫기
	fin.close();
	return;
}

// 출력
void CSVLoader::print(void)
{
	// 스트림
	std::ofstream txt("CSV2TXT.txt");
	// 파일 확인
	if (!txt.is_open())
	{
		return;
	}
	// 파일 쓰기
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			txt << data[i][j] << "\t";
		}
		txt << std::endl;
	}
	// 파일 닫기
	txt.close();
	return;
}
