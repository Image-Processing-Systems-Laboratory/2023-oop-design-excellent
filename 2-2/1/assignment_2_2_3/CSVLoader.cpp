#include "CSVLoader.h"

using namespace std;

CSVLoader::CSVLoader()
{
	data = 0;
	cols = 0;
	rows = 0;
	// 입력받은 path가 없으므로 그냥 변수 초기화
}

CSVLoader::CSVLoader(const char* path)
{
	parse(path); // parse 함수로 data 변수 초기화
}

CSVLoader::~CSVLoader()
{
	delete[]data[0];
	delete[]data; // data 변수에 할당받은 메모리 삭제
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

	fin.open(path); // CSV 파일을 읽을 스트림 생성
	for (i = 0; !fin.eof(); i++)
	{
		getline(fin, arr[i]); // 한 라인씩 읽는다
		if (arr[i] == "") // 마지막의 널 문자를 읽는다면 이는 파싱의 대상이 아님
			i--;
	}
	rows = i; // row 초기화
	cols = return_cols(arr[0]); // column 초기화
	data = new float* [rows];
	data[0] = new float[rows * cols]; // 메모리 해제 편의를 위해 왼쪽처럼 할당
	for (int i = 1; i < rows; i++)
		data[i] = data[i - 1] + cols; // 2차원 배열 할당
	for (int j = 0; j < rows; j++)
	{
		i = 0;
		for (int k = 0; k < cols; k++)
		{
			data[j][k] = atof(arr[j].c_str() + i); // 데이터 뒤에 콤마는 atof가 읽지 않음
			while (arr[j][i] != ',' && i < arr[j].length())
				i++; // 콤마가 나오거나 다 읽을 때까지 한 라인을 읽음
			if (i < arr[j].length())
				i++; // 마지막까지 읽은 것이 아니면 다음 칸 읽기(콤마가 아닌 다음 데이터의 시작)
		}
	}
	fin.close(); // 파일 스트림 닫기
}

void CSVLoader::print(void) // 2차원 배열 출력 함수
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

	for (int i = 0; i < str.length(); i++) // 한 라인을 순회
	{
		if (str[i] == ',')
			cnt++; // 콤마의 개수를 셈
	}
	return (cnt + 1); // 콤마의 개수 + 1 == 한 라인의 데이터의 개수 == column
}