#define _CRT_SECURE_NO_WARNINGS 
#include "csv.h"



csv:: csv(const char* path) {

	fstream input_file;//파일 스트림 
	input_file.open(path);
	string line;
	

	if (input_file.fail()) {// 파일이 열리지 않을 경우 오류 메시지를 출력하고 프로그램 종료
		cout << "invalid value";
		exit(true);
	}


	std::getline(input_file, line);// 첫줄의 콤마 개수를 세어 전체 열의 값을 도출
	for (char C : line) {
		if (C == ',') {// 콤마 개수를 기준으로 열의 개수를 측정
			col++;
			
		}
	}





	while (!input_file.eof()) {
		std::getline(input_file, line);
		row++;
	}//행의 개수 측정


	input_file.close();// 파일 닫기

}

csv::~csv() {

	for (int i = 0; i < row; i++) {
		delete[] data[i];
	}

	delete[] data;// 동적 할당한 메모리 해제


}



void csv:: parse(const char* path) {
	fstream input_file;
	string line;

	
	
	
	data = new float* [row];// 멤버변수에 메모리값 할당
	
	for (int i = 0; i < row; i++) {
		data[i] = new float[col];
	}

	

	input_file.open(path);// 파일 열기


	if (input_file.fail()) {// 안열리면 오류 출력후 프로그램 종료
		cout << "invalid value";
		exit(true);
	}

	for (int i = 0; i < row; i++) {
		int index = 0;
		char buf[128] = { NULL };
		int buf_index = 0;

		getline(input_file, line);//파일로 부터 한줄 씩 읽어오기


		for (char C:line) {


			if (C == ',') {

				
				data[i][index] = atof(buf);
				strncpy(buf, "\0", 128);
				buf_index = 0;
				index++;
				continue;//쉼표를 만날경우 문자열 실수로 변환

				
			
			}

		
			buf[buf_index] = C;
			buf_index++;

		}
	
		data[i][col - 1] = atof(buf);// 맨 마지막 문자열 실수로 변환 후 멤버변수가 가르키는 메모리에 할당

	}


	input_file.close();// 파일 닫기
	





}


void csv::print() {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (data[i][j]==NULL) {
				cout << ",";
			}
			else if (j != col -1) {
				cout << data[i][j] << ",";//마지막이 아니라면 콤마 출력
			}
			else {
				cout << data[i][j];//마지막이라면 콤마를 출력하지 않음
			}

		}

		cout << endl;
	}



}