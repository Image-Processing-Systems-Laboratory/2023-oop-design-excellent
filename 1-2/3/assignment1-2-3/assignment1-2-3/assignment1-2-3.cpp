#include<iostream>
#include<fstream>

using namespace std;

int checkstring(char* str1, char* str2);		//와일드 카드 체크 함수

int main(void) {
	char arr[50];						//파일 이름 배열
	int wild;							//와일드 카드 수
	cout << "Input file name : ";		//안내문 출력
	cin >> arr;							//파일 이름 입력받기
	char data[100];						//파일의 한줄한줄을 입력받을 배열
	ifstream fin;						//fin 객체에 파일을 읽기모드로 열기 위해 객체 선언
	fin.open(arr);						//파일스트림 연결

	if (!fin)							//연결된 파일이 없다면
	{
		cerr << "Error!" << endl;		//에러 출력
		return -1;						//프로그램 종료
	}
	int line = 0;						//파일 속 내용이 몇줄인지 저장하는 변수
	while (!fin.eof()) {				//파일이 끝날때까지 위를 반복한다.
		fin.getline(data, 100);			//파일 속 내용 불러오기
		line++;							//라인수 세기
	}
	int* wild_flag = new int[line];		//플래그 변수 라인수만큼 동적할당

	for (int i = 0; i < line; i++) {
		wild_flag[i] = 0;				//플래그 0으로 초기화
	}
	fin.close();						//파일 닫고 다시 열기
	fin.open(arr);

	cin >> wild;						//와일드 카드 수 입력받기
	char** wild_list = new char*[wild];	//와일드 카드 수만큼 문자열 동적할당
	for (int i = 0; i < wild; i++) {	//문자열 각각 길이 지정하기 위한 반복문
		wild_list[i] = new char[100];	//문자열 각각 길이를 100으로 지정
		cin >> wild_list[i];			//와일드 카드를 입력 받는다.
	}
	
	cout << "\n\n";						//구분을 위한 개행

	for (int i = 0; i < wild; i++) {		//와일드 카드만큼 반복
		int num = 0;
		while (!fin.eof()) {				//파일이 끝날때까지 위를 반복한다.
			fin.getline(data, 100);			//햔줄 입력 받아 data 문자열에 저장
			if (wild_flag[num] == 0) {			//이전에 출력한 문자인지 비교
				if (checkstring(data, wild_list[i])) {	// 실행
					cout << data << endl;			//data에 저장된 문자열을 출력 후 개행
					wild_flag[num] = 1;			//출력 후 플래그를 1로 변경
				}
			}
			num++;		//한줄 한줄 비교를 위해 num의 값을 증가
		}		
		fin.close();						//파일 닫기
		fin.open(arr);						//다시 파일 열기
	}
	

	fin.close();							//파일 닫기
	return 0;								//main함수 종료
}

int checkstring(char* str1, char* str2) {			//와일드카드 체크 함수 정의
	for (int i = 0; i < 100; i++) {				//최대 100글자이므로 100글자 동안 반복하며 비교하기
		if (str2[i] == '?') continue;		//str2의 i번 인덱스가 ?라면 다음 반복문으로 넘기기
		if (str2[i] == '*') {				//str2의 i번 인덱스가 *이라면 그 후는 상관 없으므로 조건문 실행
			return 1;		//1을 반환하고 함수 종료
		}
		if (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {	//str1과 str2의 같은 인덱스의 문자가 null이 아닌채로 같은 입력값을 가진다면?
			continue;			//다음 반복문으로 넘어가기
		}
		if (str1[i] == '\0' && str2[i] == '\0') {		//str1, str2의 같은 인덱스가 null이라면? 즉, 문자열의 마지막이라면?
			return 1;		//1을 반환하고 함수 종료
		}
		
		if (str1[i] != str2[i]) {		//str1과 str2의 같은 인덱스의 값이 다르다면?
			return 0;		//0을 반환하고 함수 종료
		}
	}
}