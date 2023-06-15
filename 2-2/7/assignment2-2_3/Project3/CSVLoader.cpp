#include "CSVLoader.h"

CSVLoader::CSVLoader()                    // 생성자 정의
{
	data = new float* [MAX_BUFFER_SIZE];   // data를 최대 버퍼 크기 까지 동적할당 함
	cols = 0;                              // cols, rows 초기화
	rows = 0;
}
CSVLoader::CSVLoader(const char* path)    //매개변수가 있는 생성자 정의
{
	data = 0;                            // data, cols, rows 초기화
	cols = 0;
	rows = 0;
	ifstream read;                     // 파일을 읽기위한 변수 선언
	read.open(path);                   // path 문자열에 해당하는 파일을 열음
	if (!read)                       // 파일이 없을 경우 에러 출력
	{
		cout << "Error no file";
		return;
	}
	data = new float* [MAX_BUFFER_SIZE];   // data를 최대 버퍼 크기까지 동적 할당 받음
	read.close();                        // 파일을 닫아줌
}
CSVLoader::~CSVLoader()                // 파괴자 정의
{
	for (int i = 0; i < rows; i++)   // 동적할당 받은 만큼 해제 함
	{
		delete[] data[i];
	}
	delete[] data;                 // 1차원으로 동적할당 받은 부분을 해제함
}
float** CSVLoader::getData() const    // getData 함수 정의
{
	return data;                         //data 값을 반환함 
}
int CSVLoader:: getRows() const      // getRows 함수 정의
{
	return rows;                // rows 값을 반환함
}
int CSVLoader:: getCols() const   // getCols 함수 정의 
{ 
	return cols;                // cols 값을 반환함
}
void CSVLoader:: parse(const char* path)   // 파일을 구문분석할 함수 정의
{
	ifstream read;                // 파일을 읽기위한 클래스 선언               
	read.open(path);               // 파일이름이 path 문자열인 파일 열기
	if (!read)                   // 파일이 없는 경우 에러 출력
	{
		cout << "Error no file";
		return;
	}
	string parse;             // 연산을 위한 string 선언
	int count = 0;           // 연산을 위한 count, countarr[20], temp 선언 및 초기화 
	int countarr[20] = {};
	int temp = 0;
	getline(read, parse);             // 파일을 한줄 읽어서 string 에 저장
	count = parse.find(",", count);      // string에서 ',' 가 있는 위치를 count에 저장
	countarr[temp] = count;               // count 값을 배열에 저장
	temp++;
	cols++;                         // cols의 값을 1올림
	while (parse.find(",", count + 1) != string::npos)      // string안에 ',' 가 없을 때까지 반복
	{
		count = parse.find(",", count + 1);                // 만약 있다면 count에 저장 후 count를 배열에 저장
		countarr[temp] = count;
		temp++;
		cols++;                                       // cols 값을 1 올림
	}
	countarr[temp] = strlen(parse.c_str());         // 배열의 마지막 끝을 문자열의 길이로 함
	cols++;                                           // cols 값을 1 올림
	data[0] = new float[cols];                       // cols 값 만큼 새로 동적할당 받음
	data[0][0] = atof(parse.substr(0, countarr[0]).c_str());   // 문자열의 시작부터 ',' 가 나올때까지 잘라 float형으로 바꿈
	for (int i = 1; i < cols; i++)                       // cols-1 까지 반복
	{
		data[0][i] = atof(parse.substr(countarr[i-1]+1, countarr[i]- countarr[i - 1]).c_str());   // 문자열을 ','가 나올때마다 잘라서 그 값을 float로 바꾸어 배열에 삽입
	}
	rows++;  // row 값을 1 올림
	while (getline(read, parse))  // 파일의 끝까지 반복
	{
		count = 0;                      
		count = parse.find(",", count);   // string에서 ',' 가 있는 위치를 count에 저장
		countarr[0] = count;              // count 값을 배열에 저장
		for (int i = 1; i < cols; i++)      
		{
			count = parse.find(",", count + 1);   // 문자열에 ','가 있다면 count에 저장 후 count를 배열에 저장
			countarr[i] = count;
		}
		data[rows] = new float[cols];         // cols 값 만큼 새로 동적할당 받음
		data[rows][0] = atof(parse.substr(0, countarr[0]).c_str());    // 문자열의 시작부터 ',' 가 나올때까지 잘라 float형으로 바꿈
		for (int i = 1; i < cols; i++)
		{
			data[rows][i] = atof(parse.substr(countarr[i - 1] + 1, countarr[i] - countarr[i - 1]).c_str()); // 문자열을 ','가 나올때마다 잘라서 그 값을 float로 바꾸어 배열에 삽입
		}
		rows++;   // row 값을 1 올림
	}
	read.close();   // 파일을 닫아줌
}
void CSVLoader::print(void)       // 구문 분석한 파일을 출력하는 함수 정의
{
	for (int i = 0; i < rows; i++)      // 구문 분석 한 파일을 행과 열 만큼 반복하면서 출력
	{
		for (int j = 0; j < cols; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}