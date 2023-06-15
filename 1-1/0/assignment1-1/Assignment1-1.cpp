#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;	//std 라이브러리에 포함된 내용들을 사용

//함수 선언
void PrintSierTriangle(int k, int x_size, int y_size);	//시어핀스키 삼각형을 출력하는 함수
void PutSierTriangle(int k, int x_size, int y_size);	//시어핀 스키 삼각형을 배열에 저장하는 함수
void init_Drawing_Array(int x_size, int y_size);		//전역변수 Sier_Triangle의 동적 메모리할당을 하고 빈칸으로 초기화함 각 마지막 칸에는 널문자를 포함시키는 함수
void outit_Drawing_Array(int x_size, int y_size);		//전역변수 Sier_Triangle의 동적 메모리할당을 해제하는 함수

//전역변수 선언
unsigned char** Sier_Triangle;		//unsigned char형 이중 포인터 전역변수 선언

int main()
{
	unsigned char k;			//unsigned char형 변수 선언
	int k_int, N;				//int형 변수 선언
	cout << "입력: ";			//입력할 시어핀스키 삼각형의 호수를 정함
	cin >> k;					//입력할 시어핀스키 삼각형의 호수를 입력 받음
	/* 아스키코드에 의해 -48을 해줌 */
	k_int = k - 48;				//int형 변수k_int에 입력받은 k의 값을 int형으로 저장
	
	N = pow(2, k_int - 1);		//N에 2의 k_int-1 제곱을 넣어준다.
	int x_size = 5 * N + N - 1;		//삼각형 아랫변의 길이를 변수에 저장
	int y_size = 3 * N;					//삼각형 높이의 길이를 변수에 저장
	/*  배열 만들기  */
	init_Drawing_Array(x_size, y_size);				// 동적할당을 해주는 함수 호출

	PutSierTriangle(k_int, (x_size - 1) / 2, 0);		//시어핀스키 삼각형을 저장하는 함수에 아랫변의 중간지점과 높이를 입력
	PrintSierTriangle(k_int, x_size, y_size);			//시어핀스키 삼각형을 출력하는 함수
	/*  배열 해제하기  */
	outit_Drawing_Array(x_size, y_size);			// 동적할당을 해제 해주는 함수 호출
	
	return 0;
}
/*  시어핀 스키 삼각형을 배열에 저장하는 함수  */
void PutSierTriangle(int k, int x, int y) {
	/*  k=1일때의 삼각형을 배열에 저장  */
	if (k == 1)						//1일 경우
	{
		Sier_Triangle[y][x] = '$';		//Sier_Triangle[y][x]에 $로 초기화함
		Sier_Triangle[y + 1][x - 1] = Sier_Triangle[y + 1][x + 1] = '$';	//Sier_Triangle[y+1][x-1]과 Sier_Triangle[y+1][x+1]에 $로 초기화함
		for (int i = -2; i <= 2; i++)		//i가 -2부터 2까지
			Sier_Triangle[y + 2][x + i] = '$';	//Sier_Triangle[y+2][x-2]부터 Sier_Triangle[y+2][x+2]까지 $로 초기화함
	}
	/*  (k-1)일때의 삼각형을 각 세개의 포인트에 순서대로 저장  */
	else
	{
		PutSierTriangle(k - 1, x, y);		//x,y인 곳에서 k-1일때의 삼각형 저장
		PutSierTriangle(k - 1, x - 3 * pow(2, k - 2), y + 3 * pow(2, k - 2));	//x - 3 * pow(2, k - 2),y + 3 * pow(2, k - 2)인 곳에서 k-1일때의 삼각형 저장
		PutSierTriangle(k - 1, x + 3 * pow(2, k - 2), y + 3 * pow(2, k - 2));	//x + 3 * pow(2, k - 2),y + 3 * pow(2, k - 2)인 곳에서 k-1일때의 삼각형 저장
	}
}
/*  시어핀스키 삼각형을 출력하는 함수  */
void PrintSierTriangle(int k, int x_size, int y_size) {
	for (int i = 0; i < y_size; i++)		//i가 0부터 y_size-1까지
	{
		for (int j = 0; j < x_size; j++)	//j가 0부터 x_size-1까지
			cout << Sier_Triangle[i][j];	//Sier_Triangle[i][j]값을 출력
		cout << endl;						//개행
	}
}
/*  전역변수 Sier_Triangle의 동적 메모리할당을 하고 빈칸으로 초기화함
	각 마지막 칸에는 널문자를 포함시킴  */
void init_Drawing_Array(int x_size, int y_size) {

	/* 열 만들기 */
	Sier_Triangle = (unsigned char**)malloc(sizeof(unsigned char*) * y_size);			//(sizeof(unsigned char**) * y_size)만큼을 동적할당함
	/* 행 만들기 */
	for (int i = 0; i < y_size; i++)	//i는 0부터 y_size-1까지
		Sier_Triangle[i] = (unsigned char*)malloc(sizeof(unsigned char) * x_size + 1);	//(sizeof(unsigned char*) * x_size + 1)만큼을 동적할당함

	for (int i = 0; i < y_size; i++)	//i는 0부터 y_size-1까지
	{
		for (int j = 0; j < x_size; j++)		//j는 0부터 x_size-1까지
			Sier_Triangle[i][j] = ' ';			//배열에 공백 넣기
		Sier_Triangle[i][x_size] = '\0';		//각 열의 마지막행에 널 문자 넣기
	}
}
/*  전역변수 Sier_Triangle의 동적 메모리할당을 해제함  */
void outit_Drawing_Array(int x_size, int y_size) {

	for (int i = 0; i < y_size; i++) //i가 0부터 y_size-1까지
		free(Sier_Triangle[i]);		//0부터 y_size-1까지의 동적메모리 할당을 해제함
	free(Sier_Triangle);			//**Sier_Triangle의 동적메모리 할당을 해제함
}
