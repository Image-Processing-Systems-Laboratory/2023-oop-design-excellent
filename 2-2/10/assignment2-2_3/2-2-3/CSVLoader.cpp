#include "CSVLoader.hpp"
#include <iostream>

CSVLoader::CSVLoader() // 생성자
	:data(NULL), rows(0), cols(0)
{}

CSVLoader::CSVLoader(const char* path) // 파일 이름을 인자로 받는 생성자
	:data(NULL), rows(0), cols(0)
{
	parse(path); //파일을 파싱
}

CSVLoader::~CSVLoader() // 소멸자
{
	if (!data) // data가 null일 경우 해제할 것이 없음
		return;
	for (int i = 0; i < getRows(); i++) // data에 할당된 공간 해제
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

void CSVLoader::print(void) // data 출력
{
	int row_val = getRows();
	int col_val = getCols();

	for (int i = 0; i < row_val; i++) // data를 ,와 개행으로 구분해 출력
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

void CSVLoader::parse(const char* path) // 파일을 열어 파싱
{
	if (data) // 기존 data가 있을 경우 해제
	{
		for (int i = 0; i < getRows(); i++)
		{
			delete[] data[i];
		}
		delete[] data;
	}
	std::ifstream ifs(path); // 파일 엶
	char input[MAX_BUFFER_SIZE]; // 입력받을 버퍼
	char* temp;

	if (!ifs.is_open()) // 파일 open 에러
	{
		std::cerr << "file open error" << std::endl;
		return;
	}
	rows = 0; // 행의 갯수
	cols = 1; // 열의 갯수
	ifs.getline(input, MAX_BUFFER_SIZE); // 한 줄을 읽음
	for (int i = 0; input[i]; i++)
	{
		if (input[i] == ',') // 쉼표가 나오면 열이 한 개 더 있다는 의미
			cols++;
	}
	while (ifs) // 파일이 끝날 때까지
	{
		rows++;
		ifs.getline(input, MAX_BUFFER_SIZE); // 한 줄씩 읽으며 줄 수 셈
	}
	ifs.clear(); // eof플래그 해제
	ifs.seekg(0); // 파일의 처음으로 되돌림
	// 행과 열만큼 공간 할당
	data = new float* [getRows()];
	for (int i = 0; i < getRows(); i++)
	{
		data[i] = new float[getCols()];
		ifs.getline(input, MAX_BUFFER_SIZE); // 한 줄 읽기
		temp = input;
		for (int j = 0; j < getCols(); j++)
		{
			data[i][j] = atof(temp); // entry 한 개 읽기
			while (*temp && *temp != ',')// 다음 entry로 temp포인터 이동
				temp++;
			if (*temp == ',') // 쉼표일 경우 한 칸 더 이동
				temp++;
		}
	}
	ifs.close(); // 파일 닫기
}