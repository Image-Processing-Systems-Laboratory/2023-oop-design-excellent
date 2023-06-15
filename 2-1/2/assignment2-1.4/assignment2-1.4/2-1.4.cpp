#include <iostream> //iostream 선언
#include <fstream> //fstream 선언

using namespace std; //namespace std 선언

class decorde //decorde class 선언
{
private:
	char get[1000] = { 0 }; //읽을 파일의 텍스트를 받기 위한 문자형 배열
	char put[1000] = { 0 }; //파일에 쓸 텍스트를 위한 문자형 배열
	const char charac = 'a'; //a가 기준이기 때문에 charac 변수에 a를 저장해서 사용
	ifstream readfile;
	ofstream writefile; //입력 파일 스트림, 출력 파일 스트림 선언
	int countzero = 0; //0이 몇개인지 세기 위한 변수 선언
	int j = 0; //반복문에서 put 배열의 인덱스를 가리키기 위한 변수 선언

public:
	void fileopen(const char* readtext, const char* writetext) //fileopen 함수
	{
		readfile.open(readtext); //읽을 텍스트 파일 열기
		if (!readfile) //만약 존재하지 않으면
			cout << "No file detected"; //안내문 출력
		writefile.open(writetext); //쓰기를 위한 텍스트 파일 열기
	} //fileopen 함수 종료

	void read(void) //read 함수
	{
		while (!readfile.eof()) //읽을 텍스트파일이 끝날 때까지
			readfile.getline(get, 1000); //get 배열에 저장하기
		for (int i = 0; get[i] != '\0'; i++) //다 저장한 후 get배열의 요소들을 조건에 맞게 변환해서 put배열에 넣어주기 위한 반복문 시작
		{
			if ((get[i] == '1')) //만약 1을 만나면
			{
				put[j] = static_cast<char>(charac + countzero); //1 앞에 있던 0의 개수만큼을 charac(기준인 a)에 더한 후 char형으로 형변환 후 put배열에 저장
				countzero = 0; //countzero는 초기화
				j++; //put의 인덱스를 가리키는 j 증가
			}
			else //1을 만나지 않은 경우, 즉 0을 만나는 경우 
			{
				if (countzero == 24) //z처리를 위해서 만든 조건문, countzero가 24까지 증가하면 z라는 뜻!
				{
					put[j] = static_cast<char>(charac + countzero + 1); //charac에 25를 더한 후 char형으로 형변환 하여 put배열에 저장 (z 처리)
					countzero = 0; //countzero는 초기화
					j++; //put의 인덱스를 가리키는 j 증가
				}
				else //그 외의 경우, 즉 일반적으로 0을 만나는 상황
				{
					countzero++; //countzero를 증가시킨다.
				}
			}
		}
	} //read함수 종료

	void write(void) //write함수
	{
		if (writefile.is_open()) //정상적으로 파일이 열리면
		{
			writefile << put; //put배열에 입력된 문자들을 writefile에 써준다.
		}
		else //정상적으로 열리지 않으면
		{
			cout << "No File to write"; //안내문 출력
		}
	} //write함수 종료

	void fileclose(void) //fileclose함수
	{
		readfile.close();
		writefile.close(); //정상적으로 파일을 닫는다.
	} //fileclose함수 종료

};

int main()
{
	char input1[] = "binary.txt"; //0000000100001000000000001000000000001000000000000001 이 들어가있는 텍스트 파일
	char output1[] = "hello.txt"; //hello가 저장될 텍스트 파일

	char input2[] = "allnumber.txt";
	//0000000000000000000000000010101101001000100001000001000000100000001000000001000000000100000000001000000000000000000000000000000 이 들어가있는 텍스트 파일
	char output2[] = "alphabet.txt"; //zbbbabcdefghijkz 가 저장될 텍스트 파일

	decorde object1; //decorde 클래스에 대한 object1 객체 생성
	object1.fileopen(input1, output1); //object1 객체에 대한 fileopen 함수 실행
	object1.read(); //read 함수 실행
	object1.write(); //write 함수 실행
	object1.fileclose(); //fileclose 함수 실행

	decorde object2; //decorde 클래스에 대한 object2 객체 생성
	object2.fileopen(input2, output2); //object2 객체에 대한 fileopen 함수 실행
	object2.read(); //read 함수 실행
	object2.write(); //write 함수 실행
	object2.fileclose(); //fileclose 함수 실행

	return 0; //0의 반환
} //main함수 종료