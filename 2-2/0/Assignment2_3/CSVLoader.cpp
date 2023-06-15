#include "CSVLoader.h"


CSVLoader::CSVLoader()	// 매개변수가 없는 생성자 선언
{
	data = NULL;
	rows = 0;
	cols = 0;
}
CSVLoader::CSVLoader(const char* path) //매개변수가 있는 생성자
{
	data = NULL;
	rows = 0;
	cols = 0;
	this->parse(path);
}
CSVLoader::~CSVLoader()		// 소멸자에서 동적할당 해제
{
	for (int i = 0; i < rows; i++)
		delete[] data[i];
	delete[] data;
}

float** CSVLoader::getData() const	// data주소 반환
{
	return data;
}
int CSVLoader::getRows() const	// rows반환
{
	return rows;
}
int CSVLoader::getCols() const	// cols 반환
{
	return cols;
}

void CSVLoader::CSVLoader::parse(const char* path) // CSV를 읽고 데이터를 할당함
{
	ifstream input;	// 파일스트림 선언
	input.open(path); // 파일스트림을 연다
	string tmp;		// 임시로 사용할 tmp 사용

	if (!input.is_open())	// 파일이 열리지 않았을 경우의 예외
	{
		cout << "Can't open File";
		return;
	}
	while (getline(input, tmp))	//행개수를 먼저 읽어옴
	{
		rows++;
		if (input.peek() == EOF)	// eof에 도달하기 전에 파일을 가리키는 곳을 처음으로 돌림
		{
			input.clear();
			input.seekg(0, std::ios::beg);
			break;
		}
	}

	while (input.peek() != '\n')	// , 의 개수로 열의 개수를 카운트함
	{
		if (input.get() == ',')
			cols++;
	}
	cols++;
	input.seekg(0, std::ios::beg);	// 파일을 기리키는 곳을 처음으로돌림 
	data = new float*[rows];// 위에서 읽어온 행과 열 개수를 바탕으로 동적할당
	for (int i = 0; i < rows; i++)
		data[i] = new float[cols];
	for (int i = 0; i < rows; i++)	// 위에서부터 데이터를 읽어옴
	{
		for (int j = 0; j < cols; j++)
		{
			if (j == cols - 1)	// 마지막 원소를 읽을 때에는 개행문자를 볼때까지 읽어옴
				if (i == rows - 1)
					getline(input, tmp);
				else
				getline(input, tmp, '\n');
			else
				getline(input, tmp, ',');	// 아닌 경우에는 , 단위로 읽음
			data[i][j] = stof(tmp);	// 값을 저장

		}
	}

	input.close();	// 파일스트림을 닫음

	return;
}
void CSVLoader::print(void)	// data를 출력함
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			std::cout << data[i][j]<<'\t';
		cout << endl;
	}
}
