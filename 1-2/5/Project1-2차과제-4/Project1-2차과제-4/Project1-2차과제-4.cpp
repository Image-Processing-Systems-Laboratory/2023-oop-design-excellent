#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // 헤더파일선언
#include <fstream>
using namespace std; // 표준 라이브러리 사용
/* cin같은 함수들의 앞에 정의된 클래스가 없으면
C++ 표준 라이브러리 함수로 받아들이겠다는 뜻*/


unsigned char** memory_alloc2D(size_t height, size_t width) // 동적할당하는 함수 unsigned char**형으로 반환
{//memory_alloc2D 함수는 지정된 높이(512)와 너비(512)로 부호 없는 문자 포인터의 2D 배열을 할당하는 데 사용된다. 이 함수는 할당된 메모리로 포인터를 반환한다.
	unsigned char** memory = new unsigned char * [height];
	if (memory == 0)
		return 0;

	memory[0] = new unsigned char[height * width];
	if (memory[0] == 0)
	{
		delete[] memory;
		return 0;
	}

	for (size_t i = 1; i < height; i++)
		memory[i] = memory[i - 1] + width;

	return memory;
}

int memory_free2D(unsigned char** memory) // 동적할당을 해제하는 함수 int형으로 반환
{//memory_alloc2D에 의해 할당된 메모리를 해제하는 데 사용된다.
	if (memory == 0)
		return -1;
	if (memory[0])
		delete[] memory[0];

	delete[] memory;
	return 0;
}

int main() // main함수 선언
{
	char IMAGE_NAME[100]; // 파일 이름을 입력받을 변수
	const int IMAGE_HEIGHT = 512, IMAGE_WIDTH = 512; // 원본 이미지의 높이는 512, 너비는 512, 이를 const int형으로 초기화

	FILE* fp = 0;
	unsigned char** input_image = 0; // 더블 포인터 변수 input_image 파일에 저장되어있는 이미지값을 저장하기 위해 사용
	unsigned char** output_image = 0; // 더블 포인터 변수 output_image 이를 이용해서 파일을 새로 쓰기 위해 사용

	cout << "Input file name : ";
	cin >> IMAGE_NAME;
	fopen_s(&fp, IMAGE_NAME, "rb"); // IMAGE_NAME과 일치하는 파일 열기 (읽기모드)
	if (fp == 0) // IMAGE_NAME과 일치하는 파일이 없을 때
	{
		cout << "파일 열기에 실패했습니다.(" << IMAGE_NAME << ")" << endl;
		return -1;
	}

	char input1[10];
	char input2[10];
	cout << "1st coordinate : ";
	cin >> input1 >> input2; // 1st coordinate 입력
	for (int i = 0; i < 5; i++) { // 반점이 나오면 그자리를 NULL값으로 받아 문자열로 만듬
		if (input1[i] == ',') {
			input1[i] = NULL;
		}
	}
	char input3[10];
	char input4[10];
	cout << "2st coordinate : "; // 2nd coordinate 입력
	cin >> input3 >> input4;
	for (int i = 0; i < 5; i++)  {// 반점이 나오면 그자리를 NULL값으로 받아 문자열로 만듬
		if (input3[i] == ',') {
			input3[i] = NULL;
		}
	}

	int a = atoi(input1); // 문자열을 정수로 변환 
	int b = atoi(input2);
	int c = atoi(input3);
	int d = atoi(input4);
	if (a > 512 || a < 0) { // 입력을 512보다 크거나 0보다 작게 했을 경우 예외처리.
		cout << "다시 입력해 주세요.";
		return 0;
	}
	if (b > 512 || b < 0) {
		cout << "다시 입력해 주세요.";
		return 0;
	}
	if (c > 512 || c < 0) {
		cout << "다시 입력해 주세요.";
		return 0;
	}
	if (d > 512 || d < 0) {
		cout << "다시 입력해 주세요.";
		return 0;
	}
	// 만약 2nd coordinate 보다 1st coordinate 가 더 크다면, 수를 변경하여 뒤에 할 연산 수를 줄여준다. 
	if (a > c) {
		int temp = c;
		c = a;
		a = temp;
	}
	if (b > d) {
		int temp = d;
		d = b;
		b = temp;
	}
	if (c - a < 0 || d - b<0) { // 두번째 좌표가 첫번째 좌표보다 작을 때 예외처리
		cout << "cropped 할 수 없습니다.";
		return 0;
	}
	// 이때 output해주는 과정에서 a는 시작 width, c는 끝 width를 의미하며
	// b는 시작 height, d는 끝 height를 의미한다
	char width[10];
	char height[10];
	_itoa(c - a, width, 10); // 정수를 문자열로  변환해서 width에 저장
	_itoa(d - b, height, 10); // 정수를 문자열로 변환해서 height에 저장

	char RESULT_NAME1[100]; // cropped image 쓰기 할 파일 이름
	strcpy(RESULT_NAME1, IMAGE_NAME);
	strcat(RESULT_NAME1, "_cropped_(");
	strcat(RESULT_NAME1, width);
	strcat(RESULT_NAME1, ")x(");
	strcat(RESULT_NAME1, height);
	strcat(RESULT_NAME1, ").raw");
	char RESULT_NAME2[100]; // horizontalflip image 쓰기 할 파일 이름
	strcpy(RESULT_NAME2, IMAGE_NAME); 
	strcat(RESULT_NAME2, "_horizontalflip.raw");
	char RESULT_NAME3[100]; // verticalflip image 쓰기 할 파일 이름
	strcpy(RESULT_NAME3, IMAGE_NAME);
	strcat(RESULT_NAME3, "_verticalflip.raw");

	input_image = memory_alloc2D(IMAGE_HEIGHT, IMAGE_WIDTH); // sizeof(char) * 512 * 512 만큼의 메모리 할당
	if (input_image == 0) // 메모리 할당에 실패했을 때
	{
		cout << "메모리 할당에 실패했습니다." << endl;
		return -1;
	}

	fread((unsigned char*)input_image[0], sizeof(unsigned char), IMAGE_WIDTH * IMAGE_HEIGHT, fp); // 512*512*sizeof(unsigned char) 만큼의 파일을 input_image에 저장
	fclose(fp); // 파일 닫기

	output_image = memory_alloc2D(IMAGE_HEIGHT, IMAGE_WIDTH); // sizeof(char) * 512 * 512 만큼의 메모리 할당
	if (output_image == 0) // 메모리 할당에 실패했을 때
	{
		cout << "메모리 할당에 실패했습니다." << endl;
		return -1;
	}

	// Cropped
	for (int i = b; i < d; i++)
	{
		for (int j = a; j < c; j++)
		{
			output_image[i][j] = input_image[i][j];
		}
	}

	fopen_s(&fp, RESULT_NAME1, "wb"); // RESULT_NAME1과 일치하는 파일 열기(쓰기모드)
	if (fp == 0)
	{
		cout << "Failed to open filename(" << RESULT_NAME1 << ")" << endl;
		return -1;
	}

	fwrite((unsigned char*)output_image[0], sizeof(unsigned char), (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT), fp); 
	// 열린파일에 sizeof(unsigned char) * (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT) 만큼의 크기를 쓰기모드로 작성 이때 (unsigned char*)output_image[0]를 이용함
	fclose(fp); // 파일 닫기


	//Horizontally
	for (int i = 0; i < IMAGE_HEIGHT; i++)
	{
		for (int j = 0; j < IMAGE_WIDTH; j++)
		{
			output_image[i][j] = input_image[i][IMAGE_WIDTH-1-j];
		}
	}


	fopen_s(&fp, RESULT_NAME2, "wb"); // RESULT_NAME2와 일치하는 파일 열기(쓰기모드)
	if (fp == 0)
	{
		cout << "Failed to open filename(" << RESULT_NAME2 << ")" << endl;
		return -1;
	}

	fwrite((unsigned char*)output_image[0], sizeof(unsigned char), (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT), fp);
	// 열린파일에 sizeof(unsigned char) * (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT) 만큼의 크기를 쓰기모드로 작성 이때 (unsigned char*)output_image[0]를 이용함
	fclose(fp); // 파일 닫기

	//Vertically flipped
	for (int i = 0; i < IMAGE_HEIGHT; i++)
	{
		for (int j = 0; j < IMAGE_WIDTH; j++)
		{
			output_image[i][j] = input_image[IMAGE_HEIGHT-i-1][j];
		}
	}

	fopen_s(&fp, RESULT_NAME3, "wb"); // RESULT_NAME3와 일치하는 파일 열기(쓰기모드)
	if (fp == 0)
	{
		cout << "Failed to open filename(" << RESULT_NAME3 << ")" << endl;
		return -1;
	}

	fwrite((unsigned char*)output_image[0], sizeof(unsigned char), (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT), fp);
	// 열린파일에 sizeof(unsigned char) * (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT) 만큼의 크기를 쓰기모드로 작성 이때 (unsigned char*)output_image[0]를 이용함
	fclose(fp); // 파일 닫기
	


	memory_free2D(output_image); // output_image 메모리 해제
	memory_free2D(input_image); // input_image 메모리 해제

	cout << "Output images are stored!"; // 모든 파일이 오류없이 작성 됐다면 출력

	return 0; // 0의 반환
}
