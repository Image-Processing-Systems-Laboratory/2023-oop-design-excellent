#define _CRT_SECURE_NO_WARNINGS
#include "CSVLoader.h"

using namespace std;

CSVLoader::CSVLoader() {	//인자 X 생성자
	cout << "CSVLoader is working without path" << endl;	//경로가 없다고 알려줌
	cols = 0;
	rows = 0;
	data = NULL;
}
CSVLoader::CSVLoader(const char* path) {	//인자 O 생성자
	cout << "CSVLoader is working ( path : " << path << " )" << endl;	//해당 경로로 데이터 분석한다고 출력
	cols = 0;
	rows = 0;
	data = NULL;
	parse(path);	//데이터 분석
}
CSVLoader::~CSVLoader() {	//소멸자
	cout << "CSVLoader is not working" << endl;		//작동 중지 출력
	delete[] data[0];	//메모리 할당 해제
	delete[] data;		
}

float** CSVLoader::getData() const {	//클래스 내부 data 값 반환
	return data;
}
int CSVLoader::getRows() const {		//클래스 내부 rows 값 반환
	return rows;
}
int CSVLoader::getCols() const {		//클래스 내부 cols 값 반환
	return cols;
}

void CSVLoader::parse(const char* path) {	//path의 파일에서 데이터 분석 후 저장
	ifstream input;
	input.open(path);		//파일 열기

	char* tmp = new char[MAX_BUFFER_SIZE];		//버퍼 사이즈 만큼 메모리 할당
	char tmpc = '1';
	char* p;
	int row = 0;
	int col = 1;
	while (input.get(tmpc)) {	//한 글자씩 입력 받아 반복
		if (tmpc == ',')				// , 이면 열 1 증가
			col++;
		else if (tmpc == '\n') {		// 개행이면 행 1 증가, 클래스 내부 변수에 col저장 후 col초기화
			row++;
			cols = col;
			col = 1;
		}
	}

	rows = row;	//내부 변수 행 저장

	//data에 [rows*cols]만큼 동적 할당
	data = new float* [rows];
	data[0] = new float[rows * cols];
	for (int i = 1; i < rows; i++) {
		data[i] = data[i - 1] + cols;
	}
	

	row = 0;
	col = 0;
	input.clear();
	input.seekg(0);
	while (!input.eof()) {		//한 줄씩 입력 받아 , 로 문자열 구분하고 atof로 float형으로 변환하여 data에 저장
		input >> tmp;
		p = strtok(tmp, ",");
		while (p) {
			data[row][col++] = atof(p);
			p = strtok(NULL, ",");
		}
		row++;
		col = 0;
	}
	input.close();
	delete[] tmp;
}
void CSVLoader::print() {					//한 줄에 한 행씩 출력
	for (int i = 0; i < rows; i++) {
		cout << i + 1 << " :\t";
		for (int j = 0; j < cols; j++) {
			cout << data[i][j] << '\t';
		}
		cout << endl;
	}
}