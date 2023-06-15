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
	return data;				//private의 data 값 불러오기
}
int CSVLoader::getRows() const
{
	return rows;				//private의 rows 값 불러오기
}
int CSVLoader::getCols() const
{
	return cols;				//private의 cols 값 불러오기
}
void CSVLoader::parse(const char* path)
{
	int i, j = 0, cnt = 0, key = 0, k = 0;
	//파일의 내용을 입력받을 이중 포인터 변수 메모리할당
	char** DATA = new char* [MAX_BUFFER_SIZE];
	for (i = 0; i < MAX_BUFFER_SIZE; i++)
		DATA[i] = new char[MAX_BUFFER_SIZE];
	//파일을 입력받기 위해 읽기 스트림 생성하여 파일을 열고 2차원 문자열 배열에 파일 내용 입력
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
		i++;		//행 개수
	}
	i--;	//97행+1 에서 eof 체크했기 때문에 -1
	while (DATA[k][j] != NULL)
	{
		if (DATA[k][j] != ',' && DATA[k][j] != ' ' && key == 0)		//,나 공백이 입력되지 않았다면 = 데이터
		{
			key = 1;												//데이터임을 확인하는 키
		}
		if (key == 1 && (DATA[k][j] == ',' || DATA[k][j] == ' ' || DATA[k][j + 1] == NULL))		//데이터가 ,나 공백을 만나거나 문자열의 끝 바로 이전이면
		{

			key = 0;																			//데이터가 끝남
			cnt++;																		//데이터의 개수
		}
		j++;
	}
	//파일에서 입력받아오면서 구한 행,열 값을 구한 후 CSV한 값을 넣을 data 이중 포인터 변수에 메모리 할당
	rows = i;
	cols = cnt;
	data = new float* [rows];
	for (i = 0; i < rows; i++)
	{
		data[i] = new float[cols];
	}
	key = 0;
	k = 0;
	//행과 열의 길이만큼 float 변수로 바꾸어 입력
	for (i = 0; i < rows; i++)
	{
		j = 0;
		k = 0;
		while (DATA[i][k] != NULL)
		{
			if (DATA[i][k] != ',' && DATA[i][k] != ' ' && key == 0)
			{
				key = 1;
				data[i][j] = atof(DATA[i]);						//데이터를 float으로 변형해 private data에 입력
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
