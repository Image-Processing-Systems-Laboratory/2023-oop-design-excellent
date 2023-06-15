#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

#define IMG_HEIGHT 512
#define IMG_WIDTH 512

//�Լ� ����
uint8_t** memory_alloc2D(uint32_t height, uint32_t width);	//�޸��Ҵ����ִ� �Լ�
int memory_free2D(uint8_t** ppMemAllocated);				//�Ҵ��� �޸� �������ִ� �Լ�
void switch_num(int& a, int& b);							//a�� b�� ���� �ٲ��ִ� �Լ�

int main()
{
	char filename[20];			//char�� �迭 ����
	int x1, y1, x2, y2;			//int�� ���� ����
	/*  FILE  ����ü ���� ���� �� �ʱ�ȭ  */
	FILE* fpInputimage = 0;
	FILE* fpOutputimage = 0;
	uint8_t** ppInputImageBuffer = 0;

	cout << "Input file name :";
	cin >> filename;			//filename �Է¹ޱ�

	const char* IMG_NAME = filename;	//filename�� IMG_NAME�� ����

	fpInputimage = fopen(IMG_NAME, "rb");	//readbinary�� IMG_NAME�� file�� ���� fpInputimage�� ������

	ppInputImageBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);		//(IMG_HEIGHT, IMG_WIDTH)��ŭ �޸𸮸� �Ҵ���

	// i�� 0���� IMG_HEIGHT - 1���� fpInputimage�� IMG_WIDTH����ŭ �о�鿩 ppInputImageBuffer[i]�� ������
	for(int i=0;i<IMG_HEIGHT;i++) 
		fread((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpInputimage);

	int num1 = 0, num2 = 0;			//int�� ���� ���� �� �ʱ�ȭ
	char first_coordinate[20], second_coordinate[20];	//char�� �迭 ����
	cout << "1st coordinate :";
	cin >> first_coordinate;			//���ڿ��� ���� �Է¹ް�
	x1 = atoi(&first_coordinate[0]);		//�� ���ڿ��� �ִ� �� ����
	while (first_coordinate[num1] > 47 && first_coordinate[num1] < 58)	//0���� 9������ ���� �ƴ϶��
		num1++;							//num1=num1+1�� ���ش�
	y1 = atoi(first_coordinate + ++num1);	//�� ���ڿ��� �ִ� �� ����
	
	
	cout << "2nd coordinate :";
	cin >> second_coordinate;			//���ڿ��� ���� �Է¹ް�
	x2 = atoi(&second_coordinate[0]);		//�� ���ڿ��� �ִ� �� ����
	while (second_coordinate[num2] > 47 && second_coordinate[num2] < 58)	//0���� 9������ ���� �ƴ϶��
		num2++;								//num2=num2+1�� ���ش�
	y2 = atoi(second_coordinate + ++num2);	//�� ���ڿ��� �ִ� �� ����
	if (x1 > x2)				//x1�� x2���� Ŭ ���
		switch_num(x1, x2);		//�� ���� �ٲ��ش�
	if (y1 > y2)				//y1�� y2���� Ŭ ���
		switch_num(y1, y2);		//�� ���� �ٲ��ش�

			/*  croped image�� ����  */
	char Cropped[200];		//char�� �迭 ����
	sprintf(Cropped, "%s%s%d%s%d%s", filename, "_cropped_", x2 - x1, "x", y2 - y1, ".raw");	//Cropped�� �̸� ����
	fpOutputimage = fopen(Cropped, "wb");		//writebinary�� Cropped�� file�� ���� fpOutputimage�� ������
	//i�� y1���� y2 - 1���� ppInputImageBuffer[i]�� x2-x1����ŭ �о�鿩 fpOutputimage�� ������
	for(int i=y1;i<y2;i++)
		fwrite((uint8_t*)ppInputImageBuffer[i]+x1, sizeof(uint8_t), x2-x1, fpOutputimage);
	

		
			/*  horizontalflip image�� ���� (�¿� ����)  */
	char Horizontal_Image[IMG_HEIGHT][IMG_WIDTH];	//char�� �迭 ����

	char Horizontal[100];	//char�� �迭 ����
	sprintf(Horizontal, "%s%s", filename, "_horizontalflip.raw");	//Horizontal�� �̸� ����
	fpOutputimage = fopen(Horizontal, "wb");	//writebinary�� Horizontal�� file�� ���� fpOutputimage�� ������

	// i�� 0���� IMG_HEIGHT - 1����
	for (int i = 0; i < IMG_HEIGHT; i++)
		for (int j = 0; j < IMG_WIDTH; j++)	// j�� 0���� IMG_HEIGHT - 1����
			Horizontal_Image[i][j] = ppInputImageBuffer[i][511 - j];	
	fwrite(Horizontal_Image, sizeof(uint8_t), IMG_HEIGHT*IMG_WIDTH, fpOutputimage);	//Horizontal_Image�� IMG_HEIGHT*IMG_WIDTH����ŭ �о�鿩 fpOutputimage�� ������


				/*  verticalflip image�� ���� ù��° ��� (���� ����)  */
	char Vertical[100];	//char�� �迭 ����
	sprintf(Vertical, "%s%s", filename, "_verticalflip.raw");	//Vertical�� �̸� ����
	fpOutputimage = fopen(Vertical, "wb");		//writebinary�� Vertical�� file�� ���� fpOutputimage�� ������

	// i�� IMG_HEIGHT - 1���� 0���� ppInputImageBuffer[i]�� IMG_WIDTH����ŭ �о�鿩 fpOutputimage�� ������
	for (int i = IMG_HEIGHT - 1; i >= 0; i--)
		fwrite((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpOutputimage);


			/*  verticalflip image�� ���� �ι�° ��� (���� ����)  */
	//char Vertical_Image[IMG_HEIGHT][IMG_WIDTH];	//char�� �迭 ����
	//fpOutputimage = fopen("barbara_verticalflip2.raw", "wb");
	//// i�� 0���� IMG_HEIGHT - 1����
	//for (int i = 0; i < IMG_HEIGHT; i++)
	//	for (int j = 0; j < IMG_WIDTH; j++)	// j�� 0���� IMG_HEIGHT - 1����
	//		Vertical_Image[i][j] = ppInputImageBuffer[511 - i][j];
	//fwrite(Vertical_Image, sizeof(uint8_t), IMG_HEIGHT*IMG_WIDTH, fpOutputimage);


	memory_free2D(ppInputImageBuffer);	//�޸� �Ҵ� �����ϱ�
	fclose(fpInputimage);				//������ file fpInputimage �ݱ�
	fclose(fpOutputimage);				//������ file fpOutputimage �ݱ�

	return 0; 
}
/* �޷θ� �Ҵ����ִ� �Լ� */
uint8_t** memory_alloc2D(uint32_t height, uint32_t width) {
	uint8_t** ppMem2d = new uint8_t * [height];		//height��ŭ�� ���� �Ҵ��� �Ѵ�.
	if (ppMem2d == 0)		//�޸� �Ҵ��� ���ϸ�
		return 0;
	ppMem2d[0] = new uint8_t[height * width];
	if (ppMem2d[0] == 0)	//�޸� �Ҵ��� ���ϸ�
	{
		delete[] ppMem2d;	//�޸� �����Ѵ�.
		return 0;
	}

	for (int i = 1; i < height; i++)		//i�� 1���� height-1����
		ppMem2d[i] = ppMem2d[i - 1] + width;	//ppMem2d[i][0]=ppMem2d[i-1][512]
	return ppMem2d;				//ppMem2d�� ��ȯ
}
/* �޸� �������ִ� �Լ� */
int memory_free2D(uint8_t** ppMemAllocated)
{
	if (ppMemAllocated == 0)	//������ �޸𸮰� ������
		return -1;

	if (ppMemAllocated[0])		
		delete[] ppMemAllocated[0];	//�Ҵ�� �޸� ����

	delete ppMemAllocated;			//�Ҵ�� �޸� ����
	return 0;
}
/* a�� b�� �ٲ��ִ� �Լ� */
void switch_num(int& a, int& b) {
	//a�� b�� �ٲ㼭 ��������
	int temp = a;
	a = b;
	b = temp;
}