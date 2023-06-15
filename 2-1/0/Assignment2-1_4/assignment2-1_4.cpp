#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char read_binary[200];		//파일의 문자열을 읽어들여 저장
	
	int text = 0;		//문자를 저장할 칸
	int len;			//읽어들인 문자열의 길이 저장
	ifstream fin;		//파일 입력 사용
	fin.open("binary.txt");	//binary.txt 파일 열기
	char write_text[200];		//읽어들인 문자열을 text로 전환하여 저장
	if (!fin) {			//파일 열리지 않으면
		cout << "no" << endl;
	}
	
	while (!fin.eof())	//파일의 끝에 도달할때까지
	{
		fin.getline(read_binary, 200);	//read_binary를 200만큼 읽기
		len = strlen(read_binary);		//입력받은 문자열 길이 저장
		int before_len = 0;	//출력된 문자열 이후의 길이를 저장
		for (int j = 0; j <= len; j++)
		{
			if (read_binary[j] == '1')		//'1'을 만나게 되면
			{
				write_text[text++] = j - before_len + 'a';		//문자 저장
				before_len = j + 1;				//문자 출력 이후의 문자열 길이 저장
			}
			else if (j - before_len == 25)		//0의 개수가 25개가 되면
			{
				write_text[text++] = j - before_len + 'a';		//문자 저장
				before_len = j;					//문자 출력 이후의 문자열 길이 저장
			}
			else if (read_binary[j] == ' ')		//바이너리에 공백이 있다면
			{
				write_text[text++] = ' ';		//공백을 저장함
				before_len++;					//문자 출력 이후의 문자열 길이를 저장함
			}
		}
		write_text[text++] = '\n';				//개행 저장
	}
	ofstream fout;		//파일 출력 사용
	fout.open("alphabet.txt");		//alphabet.txt 파일 열기
	fout.write(write_text, text);	//write_text를 text만큼 쓰기
	fout.close();		//열었던 파일 닫기
	fin.close();		//열었던 파일 닫기

	return 0;
}