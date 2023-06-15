#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define IMG_HEIGHT 512
#define IMG_WIDTH 512

FILE* fpInputImage = 0; // 입력용 파일포인터
FILE* fpOutputImage = 0; // 출력용 파일포인터
uint8_t** ppInputImageBuffer = 0; // 입력용 동적 메모리 할당 
uint8_t result[IMG_HEIGHT][IMG_WIDTH]; // 출력용 이차원 배열
// 다른 함수에서도 사용하기 위해 전역 변수로 선언

uint8_t** memory_alloc2D(uint32_t height, uint32_t width) {

	uint8_t** ppMem2d = new uint8_t* [height];
	// unsigned char* 형 변수 512개 할당
	if (ppMem2d == 0) {
		// 메모리가 할당되지 않았을 때 예외처리
		return 0;
	}

	for (int i = 0; i < height; i++) {
		ppMem2d[i] = new uint8_t[width];
		// 배열 형태 메모리 할당
	}
	if (ppMem2d[0] == 0) {
		// 배열 형태 메모리가 할당되지 않았을 때 예외처리
		delete[] ppMem2d;
		return 0;
	}

	return ppMem2d;
	// 할당된 메모리 반환
}

int memory_free2D(uint8_t** ppMemAllocated) {

	if (ppMemAllocated == 0) {
		// 메모리 크기가 0일 때 예외처리
		return -1;
	}

	for (int i = 0; i < IMG_HEIGHT; i++) {
		delete[] ppMemAllocated[i];
	}
	// 배열 형태 메모리 해제

	delete[] ppMemAllocated;
	// 메모리 해제
	return 0;
	// 정상적인 종료시
}

void crop(uint8_t** image) {
	// 이미지 크롭
	int coord_x1, coord_y1;
	int coord_x2, coord_y2;
	int temp;
	// 입력받을 x,y 좌표

	for (int i = 0; i < IMG_HEIGHT; i++) {
		for (int j = 0; j < IMG_WIDTH; j++) {
			result[i][j] = image[i][j];
		}
	}
	// 이미지를 그대로 복사

	std::cout << "1st coordinat: ";
	std::cin >> coord_x1, std::cin >> coord_y1;
	// 좌표1을 입력받음

	std::cout << "2nd coordinat: ";
	std::cin >> coord_x2, std::cin >> coord_y2;
	// 좌표2을 입력받음

	if (coord_x2 < coord_x1) { // 좌표가 어떤 꼭짓점이라도 작동할 수 있게 좌표를 바꿔줌
		temp = coord_x1;
		coord_x1 = coord_x2;
		coord_x2 = temp;
	}

	if (coord_y2 < coord_y1) { // 좌표가 어떤 꼭짓점이라도 작동할 수 있게 좌표를 바꿔줌
		temp = coord_y1;
		coord_y1 = coord_y2;
		coord_y2 = temp;
	}

	for (int i = 0; i < IMG_HEIGHT; i++) {
		for (int j = 0; j < IMG_WIDTH; j++) {
			if (!((coord_y1-1 <= i) && (i <= coord_y2-1) && (coord_x1-1 <= j) && (j <= coord_x2-1))) {
				// 크롭할 이미지 좌표 안이 아니면
				result[i][j] = 255;
				// 흰색으로 칠함
			}
		}
	}

	fpOutputImage = fopen("result_crop_512x512_yuv400_8bit.raw", "wb");
	for (int i = 0; i < IMG_HEIGHT; i++) {
		fwrite((uint8_t*)result[i], sizeof(uint8_t), IMG_WIDTH, fpOutputImage);
	}
	fclose(fpOutputImage);
	// 이미지를 저장

	return;
	// 함수 종료
}

void horizon_filp(uint8_t** image) {
	// 이미지 상하반전

	for (int i = 0; i < IMG_HEIGHT; i++) {
		for (int j = 0; j < IMG_WIDTH; j++) {
			result[i][j] = image[IMG_HEIGHT - i - 1][j]; // 같은 열에서 행을 위아래로 바꿔줌
		}
	}

	fpOutputImage = fopen("result_horizon_filp_512x512_yuv400_8bit.raw", "wb");
	for (int i = 0; i < IMG_HEIGHT; i++) {
		fwrite((uint8_t*)result[i], sizeof(uint8_t), IMG_WIDTH, fpOutputImage);
	}
	fclose(fpOutputImage);
	// 이미지를 저장

	return;
	// 함수 종료
}

void vertical_filp(uint8_t** image) {
	// 이미지 좌우반전

	for (int i = 0; i < IMG_HEIGHT; i++) {
		for (int j = 0; j < IMG_WIDTH; j++) {
			result[i][j] = image[i][IMG_WIDTH - j - 1]; // 같은 행에서 열을 좌우로 바꿔줌
		}
	}

	fpOutputImage = fopen("result_vertical_filp_512x512_yuv400_8bit.raw", "wb");
	for (int i = 0; i < IMG_HEIGHT; i++) {
		fwrite((uint8_t*)result[i], sizeof(uint8_t), IMG_WIDTH, fpOutputImage);
	}
	fclose(fpOutputImage);
	// 이미지를 저장
	
	return;
	// 함수 종료
}

int main()
{
	char* name;
	const char* IMG_NAME;

	name = new char[100]; // 최대 100자의 문자를 받기 위해 메모리 할당

	std::cout << "Input file name: ";
	std::cin >> name;
	// 파일 이름을 입력받음

	IMG_NAME = name;

	fpInputImage = fopen(IMG_NAME, "rb");
	// 파일 연결

	if (fpInputImage == NULL) {
		std::cout << "Opening file failure";
		return -1;
	}
	// 파일이 없을 때 예외처리

	ppInputImageBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);
	// 메모리 할당

	for (int i = 0; i < IMG_HEIGHT; i++) {
		fread((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpInputImage);
	}
	// 파일을 읽어서 메모리에 저장

	crop(ppInputImageBuffer);
	// 이미지를 크롭

	horizon_filp(ppInputImageBuffer);
	// 이미지를 상하반전

	vertical_filp(ppInputImageBuffer);
	// 이미지를 좌우반전

	std::cout << "Output images are stored!";

	memory_free2D(ppInputImageBuffer);
	// 메모리 해제
	fclose(fpInputImage);
	// 파일 연결 해제
	delete[] name;
	// 메모리 해제
	
	return 0;
	// 정상적인 종료시
}