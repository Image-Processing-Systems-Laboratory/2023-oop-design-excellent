#include<iostream>
#include<fstream>

using namespace std;

int main(void) {
	ifstream fin("binary.txt");		//binary.txt 파일 읽기 모드로 열기
	
	char arr[1000];
	char result[100] = " ";		//결과 출력할 문자열 공백으로 초기화
	fin.getline(arr, 1000);		//binary.txt 파일에 있는 문자열 불러오기

	fin.close();		//binary.txt 파일 닫기


	int start = 0, end = 0, i = 0, dis = 0;		//0의 개수를 구하여 차를 구할 시작, 끝 변수를 생성 후 0으로 초기화. 길이 변수 0으로 초기화
	int j = 0;
	while (arr[i] != '\0') {		//문자열이 끝날때까지 한문자씩 분석
		if (end - start == 25) {		//25글자를 검사했는데도 1이 나오지 않으면
			dis = end - start;			//현재 인덱스값 - 0의 시작 인덱스 값인 25를 넣는다.
			start = end + 1;			//시작 인덱스 값을 다음 검사를 위해 조정
			end = start;				//끝 인덱스 값을 다음 검사를 위해 조정
			result[j++] = (char)('a' + dis);		//아스키코드 a에 (0의 개수)길이를 더하여 해당하는 문자로 바꾼후, 결과 저장하는 배열에 넣어준다.
		}
		if (arr[i] == '0') {		//검사한 문자가 0이면 끝 변수를 1 증가시켜준다.
			end++;
		}
		if (arr[i] == '1') {		//검사한 문자가 1이면 
			dis = end - start;		//0의 시작과 끝을 계산한다.
			start = end+1;			//검사 시작 칸을 바꿔준다.
			end = start;			//끝 칸도 시작과 같이 바꿔 조정해준다.
			result[j++] = (char)('a' + dis);		//아스키코드 a에 (0의 개수)길이를 더하여 해당하는 문자로 바꾼후, 결과 저장하는 배열에 넣어준다.
		}
		i++;		//i를 증가시켜준다.(다음 문자 검사하는 용도)
	}
	ofstream fout("Alphabet.txt");			//출력할 파일을 연다.
	fout.write(result, strlen(result));		//출력할 파일에 최종 결과 배열의 값을 적어준다.

	fout.close();					//출력할 파일을 닫는다.
	return 0;
}