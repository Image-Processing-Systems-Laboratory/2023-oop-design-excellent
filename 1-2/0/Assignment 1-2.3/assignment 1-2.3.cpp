#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;


//함수선언
char** memory_alloc2D(int n);			//메모리 할당해주는 함수
int memory_free2D(char** ppMemAllocated, int n);	//메모리 해제해주는 함수
int Check_Strncmp(char* data, char* Input);			//'*'와 '?'의 규칙에 맞게 문자열이 같다면 0반환 다르다면 1반환 해주는 함수


void main()
{
	char File_Name[100], data[100];	//char형 배열 선언
	int n;							//int형 변수 선언
	char** Input_char;				//char형 이중포인터 선언
	ifstream fin;					//파일 읽는 객체명 fin 선언

	cout << "Input file name :";
	cin >> File_Name;		//filename 값을 입력받는다.
	cin >> n;				//입력할 문자열의 수
	Input_char = memory_alloc2D(n);
	for (int i = 0; i < n; i++)		//총 n번 반복함
	{
		cin >> Input_char[i];			//문자열을 입력 받는다
	}
	

	cout << endl << "Output :" << endl;
	for (int i = 0; i < n; i++)		//총 n번 반복함
	{
		fin.open(File_Name);		//File_Name의 파일을 연다.
		if (!fin) {					//file이 열리지 않았을 경우
			cout << "no" << endl;
		}
		while (!fin.eof())			//파일의 끝에 도달하기 전까지 반복
		{
			fin.getline(data, 100);		//한줄을 읽어들여 data 배열에저장한다.

			if (Check_Strncmp(data, Input_char[i]) == 0)			//입력받은 '*', '?'의 규칙에 맞는 문자열이 있으면 0 출력
				cout << data << endl;								//data에 저장된 문자열 출력
		}
		fin.close();		//파일을 닫는다.
	}
	memory_free2D(Input_char, n);		//할당된 메모리를 닫는다.
}
/*  '?', '*' 의 패턴에 맞는 문자열이 있으면 0을 반환하고 없다면 1을 반환함  */
int Check_Strncmp(char*data, char*Input) {
	int len_Input = strlen(Input);	//Input의 길이 저장
	int len_data = strlen(data);	//data의 길이 저장
	char Input_back[100], data_back[100];		//'?'나'*' 뒤 문자를 저장할때 사용하는 배열 선언
	char data_cpy[100], Input_cpy[100];			//배열을 복사할때사용
	strcpy(data_cpy, data);						//data에 저장된 문자열을 data_cpy에 저장
	strcpy(Input_cpy, Input);					//Input에 저장된 문자열을 Input_cpy에 저장
	int after = 0;								//int형 배열 선언
	for (int i = 0; i < len_Input; i++)			//i가 0부터 len_Input-1까지
	{
		
		if (Input[i] == '*')			//input[i]에 '*'가 있을때
		{
			if (strncmp(data, Input, i) == 0)	//data와 Input이 i-1까지 같은 문자일때
			{

				/*  *뒤의 문자열 저장  */
				for (int k = 0; k < len_data - i; k++)	//k가 0부터 len_data-i-1까지
				{
					Input_back[k] = Input[k + i + 1];	//Input의 뒷 문자열을 Input_back에 저장
					data_back[k] = data[k + i + 1];		//data의 뒷 문자열을 data_back에 저장
				}
				for (int j = i + 1; j < len_data; j++)	//j가 i+1부터 len_data-1까지
					if (Input[j] == '?')	//'?'가 있으면
					{
						if (Check_Strncmp(data_back, Input_back) == 0)	//뒤 문자열을 체크한다
							return 0;									//같다면 0 반환
						else
							return 1;									//다르면 1반환
					}
				return 0;	//0반환
			}
			return 1;		//1반환

		}
		else if (Input[i] == '?')	//?가 있다면
		{
			data_cpy[i] = ' ';		//공백으로 저장
			Input_cpy[i] = ' ';		//공백으로 저장
			after = i;				//?가 있는 위치 저장
		}
	}
	if (strcmp(data_cpy, Input_cpy) == 0)		//두 문자열이 같다면
		return 0;		//0반환

	for (int k = 0; k <= len_data - after; k++)	//k가 0부터  len_data-after-1까지
	{
		Input_back[k] = Input[k + 1];			//Input의 뒷 문자열을 Input_back에 저장
		data_back[k] = data[k + 1];				//data의 뒷 문자열을 data_back에 저장
	}
	for (int j = after + 1; j < len_data; j++)	//j가 after+1부터 len_data-1까지 
		if (Input[j] == '*')					//Input[j]가 '*'이라면
		{
			if (Check_Strncmp(data_back, Input_back) == 0)	//뒤 문자열을 체크한다
				return 0;				//0반환
			else
				return 1;				//1반환
		}
}
	
/*  메모리 할당을 해주는 함수 */
char** memory_alloc2D(int n) {
	char** ppMem2d = new char* [n];
	if (ppMem2d == 0)			//메모리 할당에 실패하면
		return 0;
	for (int i = 0; i < n; i++)	//i가 0부터 n-1까지
		ppMem2d[i] = new char[200];	//200사이즈 만큼 할당

	for (int i = 0; i < n; i++)	//i가 0부터 n-1까지
		if (ppMem2d[i] == 0)	//메모리 할당을 못하면
		{
			delete[]ppMem2d;	//메모리 해제한다.
			return 0;
		}
	return ppMem2d;			//ppMem2d 반환
}
/*  메모리 할당된 메모리를 해제 해주는 함수  */
int memory_free2D(char** ppMemAllocated,int n) {
	if (ppMemAllocated == 0)		//해제할 메모리가 없으면
		return -1;					
	for (int i = 0; i < n; i++)		//i가 0부터 n-1까지
		if (ppMemAllocated[i])		
			delete[] ppMemAllocated[i];	//할당된 메모리해제
	delete[] ppMemAllocated;	//할당된 메모리해제
	return 0;
}

