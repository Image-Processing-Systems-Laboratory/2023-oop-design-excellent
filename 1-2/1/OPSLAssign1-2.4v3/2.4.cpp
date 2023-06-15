#include <iostream>
#include <fstream>
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#define IMG_HEIGHT  512
#define IMG_WIDTH  512

using namespace std;

uint8_t** memory_alloc2D(uint32_t height, uint32_t width);
int memory_free2D(uint8_t** ppMemAllocated);

uint8_t** memory_alloc2D(uint32_t height, uint32_t width)
{
	uint8_t** ppMem2d = new uint8_t * [height];

	if (ppMem2d == 0)
		return 0;
	ppMem2d[0] = new uint8_t[width * height];

	if (ppMem2d[0] == 0)
	{
		delete[] ppMem2d;
		return 0;
	}

	for (int i = 1; i < height; i++)
		ppMem2d[i] = ppMem2d[i - 1] + width;

	return ppMem2d;
}

int memory_free2D(uint8_t** ppMemAllocated)
{
	if (ppMemAllocated == 0)
		return -1;
	if (ppMemAllocated[0])
		delete[] ppMemAllocated[0];

	delete[] ppMemAllocated;
	return 0;
}

int main()
{
	FILE* fileIn = 0;

	char file_name[50];
	cin >> file_name;

	fileIn = fopen(file_name, "rb");

	if (!fileIn)
	{
		cout << "filename is not valid";
		return 1;
	}

	////////////////////////////////////////////////////////////////////// 파일 이름 입력

	uint8_t** ppInputImageBuffer = 0;
	ppInputImageBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);

	for (int i = 0; i < IMG_HEIGHT; i++)
		fread((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fileIn);

	fclose(fileIn);

	////////////////////////////////////////////////////////////////////// 이미지 입력 버퍼

	int x1, x2;
	int y1, y2;
	char comma;
	cin >> x1 >> comma >> y1;
	cin >> x2 >> comma >> y2;

	if (x1 > x2)
	{
		int tempx = x2;
		x2 = x1;
		x1 = tempx;
	}

	if (y1 > y2)
	{
		int tempy = y2;
		y2 = y1;
		y1 = tempy;
	}

	if (x1 == x2 || y1 == y2 || x1 > 512 || x2 > 512 || y1 > 512 || y2 > 512 || x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0)
	{
		cout << "The coordinate is not valid.";
		return 1;
	}

	int CROP_WIDTH = x2 - x1;
	int CROP_HEIGHT = y2 - y1;

	////////////////////////////////////////////////////////////////////// crop 좌표 입력

	char file_nameCROP[50];
	char file_nameFLIP_H[50];
	char file_nameFLIP_V[50];

	int length = strlen(file_name);
	for (int i = 0; i < 5; i++)
		file_name[length - i] = NULL;

	sprintf(file_nameCROP, "%s_cropped_%dx%d.raw", file_name, CROP_WIDTH, CROP_HEIGHT);
	sprintf(file_nameFLIP_H, "%s_horizontalflip.raw", file_name);
	sprintf(file_nameFLIP_V, "%s_verticalflip.raw", file_name);

	////////////////////////////////////////////////////////////////////// output 파일 이름 설정

	uint8_t** ppCropImageBuffer = 0;

	ppCropImageBuffer = memory_alloc2D(CROP_HEIGHT, CROP_WIDTH);

	for (int i = 0; i < CROP_HEIGHT; i++)
	{
		for (int j = 0; j < CROP_WIDTH; j++)
			ppCropImageBuffer[i][j] = ppInputImageBuffer[y1 + i][x1 + j];
	}

	FILE* fileOut = 0;
	fileOut = fopen(file_nameCROP, "wb");

	for (int i = 0; i < CROP_HEIGHT; i++)
		fwrite((uint8_t*)ppCropImageBuffer[i], sizeof(uint8_t), CROP_WIDTH, fileOut);

	memory_free2D(ppCropImageBuffer);
	fclose(fileOut);

	////////////////////////////////////////////////////////////////////// crop 파일 저장

	uint8_t** ppFLIP_HImageBuffer = 0;

	ppFLIP_HImageBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);

	for (int i = 0; i < IMG_HEIGHT; i++)
		for (int j = 0; j < IMG_WIDTH; j++)
			ppFLIP_HImageBuffer[i][j] = ppInputImageBuffer[i][IMG_WIDTH - 1 - j];

	FILE* fileOutH = 0;
	fileOutH = fopen(file_nameFLIP_H, "wb");

	for (int i = 0; i < IMG_HEIGHT; i++)
		fwrite((uint8_t*)ppFLIP_HImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fileOutH);

	memory_free2D(ppFLIP_HImageBuffer);
	fclose(fileOutH);

	////////////////////////////////////////////////////////////////////// hflip 파일 저장

	uint8_t** ppFLIP_VImageBuffer = 0;

	ppFLIP_VImageBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);

	for (int i = 0; i < IMG_HEIGHT; i++)
		for (int j = 0; j < IMG_WIDTH; j++)
			ppFLIP_VImageBuffer[i][j] = ppInputImageBuffer[IMG_HEIGHT - 1 - i][j];

	FILE* fileOutV = 0;
	fileOutV = fopen(file_nameFLIP_V, "wb");

	for (int i = 0; i < IMG_HEIGHT; i++)
		fwrite((uint8_t*)ppFLIP_VImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fileOutV);

	memory_free2D(ppFLIP_VImageBuffer);
	fclose(fileOutV);

	////////////////////////////////////////////////////////////////////// vflip 파일 저장

	cout << "File Successfully Stored!";

	memory_free2D(ppInputImageBuffer);

	return 0;
}