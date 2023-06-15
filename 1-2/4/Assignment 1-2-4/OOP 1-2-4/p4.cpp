#define _CRT_SECURE_NO_WARNINGS
#define IMG_HEIGHT 512
#define IMG_WIDTH 512
#include <iostream>
using namespace std;

uint8_t** memory_alloc2D(uint32_t height, uint32_t width);
int memory_free2D(uint8_t** ppMemAllocated);

int main() {
	FILE* fpInputImage = 0;
	FILE* fpOutputImage = 0;
	uint8_t** ppInputImageBuffer = 0;
	uint8_t** ppInputImageBuffer_C = 0;
	uint8_t** ppInputImageBuffer_H = 0;
	uint8_t** ppInputImageBuffer_V = 0;

	char IMG_NAME[100];
	string FILE_NAME;
	

	cout << "Input file name : ";
	cin >> IMG_NAME;

	// input file open
	fpInputImage = fopen(IMG_NAME, "rb");

	// Memory allocation
	ppInputImageBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);
	ppInputImageBuffer_H = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);
	ppInputImageBuffer_V = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);

	// input file read to memory from the file	
	for (int i = 0; i < IMG_HEIGHT; i++) {
		fread((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpInputImage);
	}
	//IMG_NAME naming
	int cnt = 0;
	while (IMG_NAME[cnt] != '\0') cnt++;
	for (int i = 0; i < 5; i++) {
		IMG_NAME[cnt - i] = '\0';
	}
	//////////////////////
	//2-1. cropped image//
	//////////////////////

	//2-1-1. 좌표 입력받기
	int x1 = 0, y1 = 0;
	int x2 = 0, y2 = 0;
	char comma;
	// 콤마를 구분자로 입력 받기
	cout << "1st coordiante : ";
	cin >> x1 >> comma >> y1;
	cout << "2nd coordiante : ";
	cin >> x2 >> comma >> y2;
	//임의 좌표의 입력을 고려한 좌표의 정렬
	if (x1 > x2) {
		int temp = x1;
		x1 = x2;
		x2 = temp;
	}
	if (y1 > y2) {
		int temp = y1;
		y1 = y2;
		y2 = temp;
	}
	int height_c = y2 - y1;
	int width_c = x2 - x1;
	//output fileopen
	char size_w[10];
	char size_h[10];
	sprintf(size_w, "%d", width_c);
	sprintf(size_h, "%d", height_c);
	FILE_NAME = FILE_NAME + IMG_NAME + "_cropped_" + size_w + "x" + size_h + ".raw";
	fpOutputImage = fopen(FILE_NAME.c_str(), "wb");
	// Memory allocation
	ppInputImageBuffer_C = memory_alloc2D(height_c, width_c);
	//change file data
	for (int i = 0; i < height_c; i++) {
		for (int j = 0; j < width_c; j++) {
			ppInputImageBuffer_C[i][j] = ppInputImageBuffer[y1 + i][x1 + j];
		}
	}
	//write the file
	for (int i = 0; i < height_c; i++) {
		fwrite((uint8_t*)ppInputImageBuffer_C[i], sizeof(uint8_t), width_c, fpOutputImage);
	}


	//////////////////////////
	//2-2. flip horizontally//
	//////////////////////////

	//output fileopen
	FILE_NAME = "";
	FILE_NAME = FILE_NAME + IMG_NAME + "_horizontallyflip.raw";
	fpOutputImage = fopen(FILE_NAME.c_str(), "wb");

	//change file data
	for (int i = 0; i < IMG_HEIGHT; i++) {
		for (int j = 0; j < IMG_WIDTH; j++) {
			int temp = ppInputImageBuffer[i][j];
			ppInputImageBuffer_H[i][j] = ppInputImageBuffer[i][IMG_WIDTH - j - 1];
			ppInputImageBuffer_H[i][IMG_WIDTH - j - 1] = temp;
		}
	}

	//write the file
	for (int i = 0; i < IMG_HEIGHT; i++) {
		fwrite((uint8_t*)ppInputImageBuffer_H[i], sizeof(uint8_t), IMG_WIDTH, fpOutputImage);
	}


	////////////////////////
	//2-3. flip vertically//
	////////////////////////

	//output fileopen
	FILE_NAME = "";
	FILE_NAME = FILE_NAME + IMG_NAME + "_verticalflip.raw";
	fpOutputImage = fopen(FILE_NAME.c_str(), "wb");

	//change file data
	for (int i = 0; i < IMG_HEIGHT; i++) {
		for (int j = 0; j < IMG_WIDTH; j++) {
			int temp = ppInputImageBuffer[j][i];
			ppInputImageBuffer_V[j][i] = ppInputImageBuffer[IMG_HEIGHT - j - 1][i];
			ppInputImageBuffer_V[IMG_HEIGHT - j - 1][i] = temp;
		}
	}

	//write the file
	for (int i = 0; i < IMG_HEIGHT; i++) {
		fwrite((uint8_t*)ppInputImageBuffer_V[i], sizeof(uint8_t), IMG_WIDTH, fpOutputImage);
	}


	cout << "Output images are stored!";

	memory_free2D(ppInputImageBuffer);
	memory_free2D(ppInputImageBuffer_C);
	memory_free2D(ppInputImageBuffer_H);
	memory_free2D(ppInputImageBuffer_V);
	fclose(fpInputImage);
	fclose(fpOutputImage);
	return 0;
}

uint8_t** memory_alloc2D(uint32_t height, uint32_t width) {

	uint8_t** ppMem2d = new uint8_t * [height];
	if (ppMem2d == 0) return 0;
	ppMem2d[0] = new uint8_t[height * width];
	if (ppMem2d[0] == 0) {
		delete[] ppMem2d;
		return 0;
	}
	for (int i = 1; i < height; i++) {
		ppMem2d[i] = ppMem2d[i - 1] + width;
	}
	return ppMem2d;
}

int memory_free2D(uint8_t** ppMemAllocated) {
	if (ppMemAllocated == 0) {
		return -1;
	}
	if (ppMemAllocated[0]) {
		delete[] ppMemAllocated[0];
	}

	delete[] ppMemAllocated;
	return 0;
}