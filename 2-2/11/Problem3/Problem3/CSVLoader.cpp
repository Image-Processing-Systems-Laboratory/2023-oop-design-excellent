#include"CSVLoader.h"
/*
* CSVLoader 의 메소드 정의부
*/

//생성자
CSVLoader::CSVLoader() {
	//최대 버퍼 사이즈 의 제곱만큼 공간 할당
	data = (float**)calloc(sizeof(float*), MAX_BUFFER_SIZE);
	*data = (float*)calloc(sizeof(float*), MAX_BUFFER_SIZE * MAX_BUFFER_SIZE);
	//배열 형태로 변환
	for (int i = 1; i < MAX_BUFFER_SIZE; i++) {
		data[i] = data[i - 1] + MAX_BUFFER_SIZE;
	}
}
//생성자 (파싱을 동시에 수행)
CSVLoader::CSVLoader(const char* path) {
	//최대 버퍼 사이즈 의 제곱만큼 공간 할당
	data = (float**)calloc(sizeof(float*), MAX_BUFFER_SIZE);
	*data = (float*)calloc(sizeof(float*), MAX_BUFFER_SIZE * MAX_BUFFER_SIZE);
	//배열 형태로 변환
	for (int i = 1; i < MAX_BUFFER_SIZE; i++) {
		data[i] = data[i - 1] + MAX_BUFFER_SIZE;
	}
	//파싱 메소드 호출
	parse(path);
}
//소멸자
CSVLoader::~CSVLoader() {
	//만든 공간 모드 해제
	if (*data)
		free(*data);
	if (data)
		free(data);
}

//데이터의 주소 반환
float** CSVLoader::getData() const {
	return data;
}

//열의 크기를 반환
int CSVLoader::getRows() const {
	return rows;
}

//행의 크기를 반환
int CSVLoader::getCols() const {
	return cols;
}

//파싱을 하는 메소드
void CSVLoader::parse(const char* path) {
	//만약 메모리 할당에 문제가 있었다면 종료
	if (!data || !*data)
		return;
	//기본 열의 크기
	rows = 0;
	//기본 행의 크기
	cols = 0;
	//파일 스트림 생성, 오류 확인
	ifstream in(path);
	if (!in)
		return;
	//파일의 한 줄을 담을 문자열 변수
	string s;
	//열의 크기를 찾았음을 설정하는 변수
	bool isRowsEnd = false;
	//파일 끝까지 탐색
	while (!in.eof()) {
		//현재 열을 저장할 변수
		int r = 0;
		//입력
		in >> s;
		//문자열의 현재 탐색중인 문자의 위치 변수
		int cnt = 0;
		//float로 변환하기 위한 임시 문자열 변수
		string tmp;
		//끝나기 전까지 반복
		while (s[cnt]) {
			// , 이 아니면 맨 마지막 에 입력의 cnt번째 문자 추가
			if (s[cnt] != ',') {
				tmp.push_back(s[cnt]);
			}
			//,을 만났다면
			else {
				//data의 c행 r 열에 임시 저장한 문자열을 flaot으로 변환하여 저장
				data[cols][r] = stof(tmp);
				//임시변수 초기화
				tmp = "";
				//다음 열로 설정
				r++;
			}
			cnt++;
		}
		//만약 ,이 아닌 ' '을 만났다면  임시 저장한 문자열을 flaot으로 변환하여 저장
		data[cols][r] = stof(tmp);
		r++; 
		//열 크기가 안정해졌다면 설정
		if (!isRowsEnd) {
			//열의 크기를 한줄에 저장한 데이터의 갯수로 설정
			rows = r;
			//정해짐을 설정
			isRowsEnd = true;
		}
		//행의 크기를 한개씩 증가.
		cols++;
	}
	//파일 스트림 종료
	in.close();
}
//데이터 출력
void CSVLoader::print() {
	//행의 크기만큼 반복
	for (int i = 0; i < cols; i++) {
		//열의 크기만큼 반복
		for (int j = 0; j < rows; j++) {
			//첫번째가 아니면 ", "출력
			if (j)
				cout << ", ";
			//값 출력
			cout << data[i][j];
		}
		//줄넘김
		cout << endl;
	}
}