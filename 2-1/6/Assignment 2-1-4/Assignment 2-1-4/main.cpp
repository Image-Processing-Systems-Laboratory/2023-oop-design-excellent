#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

/*클래스 선언*/
class Decode {
public:
	/*멤버 함수 원형 선언*/
	void read_file(ifstream& readFile);
};

/*Decode클래스 안의 함수*/
void Decode::read_file(ifstream& readFile) {
	char c;
	/*알파벳을 저장하기 위한 배열*/
	char str[100];
	int i = 0;
	int cnt = 0;
	/*파일 끝까지 읽음*/
	while (!readFile.eof()) {
		/*한 문자씩 읽음*/
		readFile.get(c);
		/*만약 c가 0이면 cnt++*/
		if (c == '0') { 
			cnt++; 
			/*해독했는데 z일경우는 '1'이 없는 특이 케이스 이므로 따로 저장*/
			if (cnt == 25) {
				str[i++] = 'z';
				cnt = 0;
			}
		}
		/*c가 1이면 str배열에 0의 갯수 + 적절한 아스키코드를 수행해 원하는 알파벳 얻음*/
		if (c == '1') {
			str[i++] = cnt + 97;
			/*한번 1을 만나면 0으로 초기화*/
			cnt = 0;
		}
		/*한번 반복문을 돌면 초기화*/
		c = 0;
	}
	/*문자열의 끝을 알리기 위한 널문자*/
	str[i] = '\0';
	ofstream writeFile;
	/*"alpha.txt" 파일 생성 하고 엶*/
	writeFile.open("alpha.txt");
	/*파일이 안 열리면 no!! 출력*/
	if (!writeFile) cout << "no!!" << endl;
	/*파일에 문자열 씀 readFile.eof()함수를 사용하니 추가로 한바퀴를 더 돌아서
	a가 저장되므로 구한 문자열의 길이보다 한 문자 적은 문자열을 파일에 씀*/
	writeFile.write(str, strlen(str));
	/*파일 닫음*/
	writeFile.close();
}

int main(void) {
	ifstream readFile;
	/*decode 객체 생성*/
	Decode decode;
	/*"binary.txt 파일 오픈"*/
	readFile.open("binary.txt");
	/*파일 안열리면 no!! 출력*/
	if (!readFile) cout << "no!!" << endl;
	/*decode 객체의 멤버함수로 보냄*/
	decode.read_file(readFile);
	/*파일 닫음*/
	readFile.close();
	return 0;
}