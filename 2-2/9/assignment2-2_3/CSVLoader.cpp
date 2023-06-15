#include "CSVLoader.h"
#include <iostream>
#include <cstdio>

CSVLoader::CSVLoader()
{
	//cols와 rows 측정을 위한 파일 열기
	std::fstream file;
	file.open("CSVLoader_Data.txt");
	if (!file) {             //파일 열기 실패할 경우 에러 메시지 출력 후 종료
		std::cerr << "ERROR";
		exit(100);
	}

	char ch;

	//cols 측정
	cols = 0;
	while (1) {
		ch = file.get();      //파일의 문자 읽어서 저장

		if (ch == '\n' || file.eof()) {
			break;                //개행 문자를 만나거나 파일의 끝에 도달했을 경우 반복 종료
		}

		if (ch == ',') {
			cols++;            //','를 만날 때마다 cols를 1 증가
		}
	}
	cols++;            //열의 수는 파일의 문자열 한 줄의 ','의 개수보다 하나 더 많으므로 1 증가
	file.seekg(0);      //파일의 가장 앞으로 이동
	
	//rows 측정
	rows = 0;
	while (1) {
		ch = file.get();     //파일의 문자 읽어서 저장

		if (file.eof()) {
			break;         //파일의 끝에 도달했을 경우 반복 종료
		}

		if (ch == '\n') {
			rows++;          //개행 문자를 만날 때마다 rows를 1 증가 (파일 내의 개행 문자의 수와 행의 수는 같다.)
		}
	}

	file.close();             //파일 닫기
	
	//동적할당
	data = new float* [rows];          //float* 자료형으로 행의 수만큼 할당 후 data에 주소 값 저장
	if (data == NULL) {           //할당 실패할 경우 에러 메시지 출력 후 종료
		std::cerr << "ERROR";          
		exit(100);
	}
	data[0] = new float[rows * cols];  //float 자료형으로 (행 * 열) 만큼 할당 후 data[0]에 주소 값 저장
	if (data[0] == NULL) {            //할당 실패할 경우 에러 메시지 출력 후 종료
		std::cerr << "ERROR";
		delete[] data;
		exit(100);
	}
	for (int i = 1; i < rows; i++)
	{
		data[i] = data[i - 1] + cols;     //행마다 열의 수 간격으로 주소 값 대입
	}

	//CSV 내용을 분석하여 data에 저장하기 위한 파일 열기
	std::fstream CSV;
	CSV.open("CSVLoader_Data.txt");
	if (!CSV) {                  //파일 열기 실패할 경우 에러 메시지 출력 후 종료
		std::cerr << "ERROR";
		exit(100);
	}

	char str[MAX_BUFFER_SIZE];  //파일의 한 줄을 저장할 char형 배열

	//data에 저장
	int k = rows;     //k에 rows 값 임시 저장
	for (rows = 0; rows < k; rows++) {         //행의 수만큼 반복
		CSV.getline(str, MAX_BUFFER_SIZE);     //파일 한 줄씩 읽어오기

		parse(str);                  //parse 함수에 str을 전달하여 호출
	}
	

	
	CSV.close();        //파일 닫기
}

CSVLoader::CSVLoader(const char* path) {

	cols = 0;
	rows = 1;

	//cols 측정
	int comma = 0;
	while (path[comma] != '\0') {  //문자열의 끝까지 반복
		if (path[comma] == ',') {
			cols++;         //','를 만났을 경우 cols를 1 증가
		}
		comma++;
	}
	cols++;             //열의 수는 문자열의 ','의 개수보다 하나 더 많으므로 1 증가

	//동적 할당
	data = new float* [rows];  //float* 자료형으로 행의 수만큼 할당 후 data에 주소 값 저장
	if (data == NULL) {        //할당 실패할 경우 에러 메시지 출력 후 종료
		std::cerr << "ERROR";
		exit(100);
	}
	data[0] = new float[rows * cols];   //float 자료형으로 (행 * 열) 만큼 할당 후 data[0]에 주소 값 저장
	if (data[0] == NULL) {   //할당 실패할 경우 에러 메시지 출력 후 종료
		std::cerr << "ERROR";
		delete[] data;
		exit(100);
	}

	rows = 0;
	parse(path);      //CSV 분석
	rows++;
}

CSVLoader::~CSVLoader()
{
	if (data == 0)  //data에 할당된 메모리가 없을 경우 종료
	{
		exit(100);
	}

	if (data[0])
	{
		delete[] data[0];  //data[0]가 NULL이 아닌 경우 메모리 해제
	}

	delete[] data;  //data의 메모리 해제
}

//data 값 반환하는 함수
float** CSVLoader::getData() const {
	return data;         //data 값 반환
}

//rows 값 반환하는 함수
int CSVLoader::getRows() const {
	return rows;             //rows 값 반환
}

//cols 값 반환하는 함수
int CSVLoader::getCols() const {
	return cols;            //cols 값 반환
}

//CSV 형식 분석
void CSVLoader::parse(const char* path) {
	float exponent;        //자릿수
	float num;             //실수로 변환한 값
	int exponent_num;      //지수표기법
	bool minus;            //음수인지 판단
	bool minus_exponent;   //지수 표기법에서 음수인지 판단

	int start = 0;             //숫자가 시작하는 위치

	int start_decimal;     //소수 부분이 시작하는 위치
	int len;

	//열의 수만큼 반복
	for (int index = 0; index < cols; index++) {
		exponent = 1;
		num = 0;
		exponent_num = 0;
		minus = false;
		minus_exponent = false;

		//부호가 있는지 판별하기
		if (path[start] == '+' || path[start] == '-') {
			if (path[start] == '-') { //'-'가 있을 경우 음수로 설정
				minus = true;
			}
			start++;     
		}  // -> 반복문 수행 후 start는 숫자가 시작하는 위치 의미

		//소수의 시작 부분 구하기(소수점 만날 때까지 반복)
		start_decimal = start;
		while (path[start_decimal] >= '0' && path[start_decimal] <= '9') {
			start_decimal++;
		}       // -> 반복문 수행 후 start_decimal은 숫자 외의 다른 값 '.', ',', '\0'의 위치 의미

		//정수 부분 계산
		for (int i = start_decimal - 1; i >= start; i--) {   //숫자의 정수 부분의 뒤부터 시작
			num = num + ((path[i] - '0') * exponent);   //각 자리에 저장되어 있는 숫자와 자릿수를 곱한 값을 num에 더한다.
			exponent *= 10;
		}

		//소수일 경우
		if (path[start_decimal] == '.') {  
			start_decimal++;   //소수의 시작 부분 의미
			exponent = 0.1;


			//소수 부분 계산
			while (path[start_decimal] != ',' && path[start_decimal] != '\0') {   //숫자의 끝에 도달할 때까지 반복
				if (path[start_decimal] == 'e' || path[start_decimal] == 'E') {  //지수 표기법인 경우
					start_decimal++;

					//부호가 있는지 판별하기
					if (path[start_decimal] == '+' || path[start_decimal] == '-') {
						if (path[start_decimal] == '-') {
							minus_exponent = true;
						}
						start_decimal++;
					}

					//숫자의 길이 구하기
					len = start_decimal;
					while (path[len] >= '0' && path[len] <= '9') {
						len++;
					}

					//e 또는 E 뒤의 숫자 구하기
					exponent = 1;
					for (int i = len - 1; i >= start_decimal; i--) {  //숫자의 뒤부터 시작
						exponent_num = exponent_num + ((path[i] - '0') * exponent); //문자열의 각 자리에 저장되어 있는 숫자와 자릿수를 곱한 값을 exponent_num에 더한다.
						exponent *= 10;
					}

					//num에 곱하기
					if (minus_exponent) {
						for (int i = 0; i < exponent_num; i++) {
							num *= 0.1;
						}
					}
					else {
						for (int i = 0; i < exponent_num; i++) {
							num *= 10;
						}
					}

					start_decimal = len;  //start_decimal은 숫자의 다음 부분에 저장되어 있는 문자(',', '\0')의 위치 의미
					break;
				}
				
				num = num + ((path[start_decimal] - '0') * exponent);  //문자열의 각 자리에 저장되어 있는 숫자와 자릿수를 곱한 값을 num에 더한다.
				exponent *= 0.1;
				start_decimal++;
			}
		}

		
		if (minus) {
			num *= -1;    //가장 앞에 '-'부호가 존재할 경우 -1 곱하여 음수로 변환
		}

		data[rows][index] = num;     //data[rows][index]에 num 값 저장

		start = start_decimal + 1;   //start를 다음 숫자의 시작 위치로 변경
	}
}

//data 출력 함수
void CSVLoader::print(void) {
	for (int i = 0; i < rows; i++) {          //행의 수만큼 반복
		for (int j = 0; j < cols; j++) {      //열의 수만큼 반복
			std::cout << data[i][j] << "    ";    //공백으로 구분하여 data 값 순서대로 출력
		}
		std::cout << std::endl;         //줄 바꾸기
	}
}