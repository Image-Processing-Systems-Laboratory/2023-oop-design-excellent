#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

#define IMG_HEIGHT 512
#define IMG_WIDTH 512

//함수 선언
uint8_t** memory_alloc2D(uint32_t height, uint32_t width);	//메모리할당해주는 함수
int memory_free2D(uint8_t** ppMemAllocated);				//할당한 메모리 해제해주는 함수
void switch_num(int& a, int& b);							//a와 b의 값을 바꿔주는 함수

int main()
{
	char filename[20];			//char형 배열 선언
	int x1, y1, x2, y2;			//int형 변수 선언
	/*  FILE  구조체 변수 선언 및 초기화  */
	FILE* fpInputimage = 0;
	FILE* fpOutputimage = 0;
	uint8_t** ppInputImageBuffer = 0;

	cout << "Input file name :";
	cin >> filename;			//filename 입력받기

	const char* IMG_NAME = filename;	//filename을 IMG_NAME에 저장

	fpInputimage = fopen(IMG_NAME, "rb");	//readbinary로 IMG_NAME을 file로 열고 fpInputimage에 저장함

	ppInputImageBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);		//(IMG_HEIGHT, IMG_WIDTH)만큼 메모리를 할당함

	// i가 0부터 IMG_HEIGHT - 1까지 fpInputimage를 IMG_WIDTH번만큼 읽어들여 ppInputImageBuffer[i]에 저장함
	for(int i=0;i<IMG_HEIGHT;i++) 
		fread((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpInputimage);

	int num1 = 0, num2 = 0;			//int형 변수 선언 및 초기화
	char first_coordinate[20], second_coordinate[20];	//char형 배열 선언
	cout << "1st coordinate :";
	cin >> first_coordinate;			//문자열로 값을 입력받고
	x1 = atoi(&first_coordinate[0]);		//앞 문자열에 있는 수 저장
	while (first_coordinate[num1] > 47 && first_coordinate[num1] < 58)	//0부터 9사이의 수가 아니라면
		num1++;							//num1=num1+1을 해준다
	y1 = atoi(first_coordinate + ++num1);	//뒤 문자열에 있는 수 저장
	
	
	cout << "2nd coordinate :";
	cin >> second_coordinate;			//문자열로 값을 입력받고
	x2 = atoi(&second_coordinate[0]);		//앞 문자열에 있는 수 저장
	while (second_coordinate[num2] > 47 && second_coordinate[num2] < 58)	//0부터 9사이의 수가 아니라면
		num2++;								//num2=num2+1을 해준다
	y2 = atoi(second_coordinate + ++num2);	//뒤 문자열에 있는 수 저장
	if (x1 > x2)				//x1이 x2보다 클 경우
		switch_num(x1, x2);		//두 값을 바꿔준다
	if (y1 > y2)				//y1이 y2보다 클 경우
		switch_num(y1, y2);		//두 값을 바꿔준다

			/*  croped image로 저장  */
	char Cropped[200];		//char형 배열 선언
	sprintf(Cropped, "%s%s%d%s%d%s", filename, "_cropped_", x2 - x1, "x", y2 - y1, ".raw");	//Cropped에 이름 저장
	fpOutputimage = fopen(Cropped, "wb");		//writebinary로 Cropped를 file로 열고 fpOutputimage에 저장함
	//i가 y1부터 y2 - 1까지 ppInputImageBuffer[i]를 x2-x1번만큼 읽어들여 fpOutputimage에 저장함
	for(int i=y1;i<y2;i++)
		fwrite((uint8_t*)ppInputImageBuffer[i]+x1, sizeof(uint8_t), x2-x1, fpOutputimage);
	

		
			/*  horizontalflip image로 저장 (좌우 반전)  */
	char Horizontal_Image[IMG_HEIGHT][IMG_WIDTH];	//char형 배열 선언

	char Horizontal[100];	//char형 배열 선언
	sprintf(Horizontal, "%s%s", filename, "_horizontalflip.raw");	//Horizontal에 이름 저장
	fpOutputimage = fopen(Horizontal, "wb");	//writebinary로 Horizontal을 file로 열고 fpOutputimage에 저장함

	// i가 0부터 IMG_HEIGHT - 1까지
	for (int i = 0; i < IMG_HEIGHT; i++)
		for (int j = 0; j < IMG_WIDTH; j++)	// j가 0부터 IMG_HEIGHT - 1까지
			Horizontal_Image[i][j] = ppInputImageBuffer[i][511 - j];	
	fwrite(Horizontal_Image, sizeof(uint8_t), IMG_HEIGHT*IMG_WIDTH, fpOutputimage);	//Horizontal_Image를 IMG_HEIGHT*IMG_WIDTH번만큼 읽어들여 fpOutputimage에 저장함


				/*  verticalflip image로 저장 첫번째 방법 (상하 반전)  */
	char Vertical[100];	//char형 배열 선언
	sprintf(Vertical, "%s%s", filename, "_verticalflip.raw");	//Vertical에 이름 저장
	fpOutputimage = fopen(Vertical, "wb");		//writebinary로 Vertical을 file로 열고 fpOutputimage에 저장함

	// i가 IMG_HEIGHT - 1부터 0까지 ppInputImageBuffer[i]를 IMG_WIDTH번만큼 읽어들여 fpOutputimage에 저장함
	for (int i = IMG_HEIGHT - 1; i >= 0; i--)
		fwrite((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpOutputimage);


			/*  verticalflip image로 저장 두번째 방법 (상하 반전)  */
	//char Vertical_Image[IMG_HEIGHT][IMG_WIDTH];	//char형 배열 선언
	//fpOutputimage = fopen("barbara_verticalflip2.raw", "wb");
	//// i가 0부터 IMG_HEIGHT - 1까지
	//for (int i = 0; i < IMG_HEIGHT; i++)
	//	for (int j = 0; j < IMG_WIDTH; j++)	// j가 0부터 IMG_HEIGHT - 1까지
	//		Vertical_Image[i][j] = ppInputImageBuffer[511 - i][j];
	//fwrite(Vertical_Image, sizeof(uint8_t), IMG_HEIGHT*IMG_WIDTH, fpOutputimage);


	memory_free2D(ppInputImageBuffer);	//메모리 할당 해제하기
	fclose(fpInputimage);				//열었던 file fpInputimage 닫기
	fclose(fpOutputimage);				//열었던 file fpOutputimage 닫기

	return 0; 
}
/* 메로리 할당해주는 함수 */
uint8_t** memory_alloc2D(uint32_t height, uint32_t width) {
	uint8_t** ppMem2d = new uint8_t * [height];		//height만큼의 동적 할당을 한다.
	if (ppMem2d == 0)		//메모리 할당을 못하면
		return 0;
	ppMem2d[0] = new uint8_t[height * width];
	if (ppMem2d[0] == 0)	//메모리 할당을 못하면
	{
		delete[] ppMem2d;	//메모리 해제한다.
		return 0;
	}

	for (int i = 1; i < height; i++)		//i가 1부터 height-1까지
		ppMem2d[i] = ppMem2d[i - 1] + width;	//ppMem2d[i][0]=ppMem2d[i-1][512]
	return ppMem2d;				//ppMem2d를 반환
}
/* 메모리 해제해주는 함수 */
int memory_free2D(uint8_t** ppMemAllocated)
{
	if (ppMemAllocated == 0)	//해제할 메모리가 없으면
		return -1;

	if (ppMemAllocated[0])		
		delete[] ppMemAllocated[0];	//할당된 메모리 해제

	delete ppMemAllocated;			//할당된 메모리 해제
	return 0;
}
/* a와 b를 바꿔주는 함수 */
void switch_num(int& a, int& b) {
	//a와 b를 바꿔서 저장해줌
	int temp = a;
	a = b;
	b = temp;
}