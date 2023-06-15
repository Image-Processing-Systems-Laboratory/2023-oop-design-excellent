#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // ������ϼ���
#include <fstream>
using namespace std; // ǥ�� ���̺귯�� ���
/* cin���� �Լ����� �տ� ���ǵ� Ŭ������ ������
C++ ǥ�� ���̺귯�� �Լ��� �޾Ƶ��̰ڴٴ� ��*/


unsigned char** memory_alloc2D(size_t height, size_t width) // �����Ҵ��ϴ� �Լ� unsigned char**������ ��ȯ
{//memory_alloc2D �Լ��� ������ ����(512)�� �ʺ�(512)�� ��ȣ ���� ���� �������� 2D �迭�� �Ҵ��ϴ� �� ���ȴ�. �� �Լ��� �Ҵ�� �޸𸮷� �����͸� ��ȯ�Ѵ�.
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

int memory_free2D(unsigned char** memory) // �����Ҵ��� �����ϴ� �Լ� int������ ��ȯ
{//memory_alloc2D�� ���� �Ҵ�� �޸𸮸� �����ϴ� �� ���ȴ�.
	if (memory == 0)
		return -1;
	if (memory[0])
		delete[] memory[0];

	delete[] memory;
	return 0;
}

int main() // main�Լ� ����
{
	char IMAGE_NAME[100]; // ���� �̸��� �Է¹��� ����
	const int IMAGE_HEIGHT = 512, IMAGE_WIDTH = 512; // ���� �̹����� ���̴� 512, �ʺ�� 512, �̸� const int������ �ʱ�ȭ

	FILE* fp = 0;
	unsigned char** input_image = 0; // ���� ������ ���� input_image ���Ͽ� ����Ǿ��ִ� �̹������� �����ϱ� ���� ���
	unsigned char** output_image = 0; // ���� ������ ���� output_image �̸� �̿��ؼ� ������ ���� ���� ���� ���

	cout << "Input file name : ";
	cin >> IMAGE_NAME;
	fopen_s(&fp, IMAGE_NAME, "rb"); // IMAGE_NAME�� ��ġ�ϴ� ���� ���� (�б���)
	if (fp == 0) // IMAGE_NAME�� ��ġ�ϴ� ������ ���� ��
	{
		cout << "���� ���⿡ �����߽��ϴ�.(" << IMAGE_NAME << ")" << endl;
		return -1;
	}

	char input1[10];
	char input2[10];
	cout << "1st coordinate : ";
	cin >> input1 >> input2; // 1st coordinate �Է�
	for (int i = 0; i < 5; i++) { // ������ ������ ���ڸ��� NULL������ �޾� ���ڿ��� ����
		if (input1[i] == ',') {
			input1[i] = NULL;
		}
	}
	char input3[10];
	char input4[10];
	cout << "2st coordinate : "; // 2nd coordinate �Է�
	cin >> input3 >> input4;
	for (int i = 0; i < 5; i++)  {// ������ ������ ���ڸ��� NULL������ �޾� ���ڿ��� ����
		if (input3[i] == ',') {
			input3[i] = NULL;
		}
	}

	int a = atoi(input1); // ���ڿ��� ������ ��ȯ 
	int b = atoi(input2);
	int c = atoi(input3);
	int d = atoi(input4);
	if (a > 512 || a < 0) { // �Է��� 512���� ũ�ų� 0���� �۰� ���� ��� ����ó��.
		cout << "�ٽ� �Է��� �ּ���.";
		return 0;
	}
	if (b > 512 || b < 0) {
		cout << "�ٽ� �Է��� �ּ���.";
		return 0;
	}
	if (c > 512 || c < 0) {
		cout << "�ٽ� �Է��� �ּ���.";
		return 0;
	}
	if (d > 512 || d < 0) {
		cout << "�ٽ� �Է��� �ּ���.";
		return 0;
	}
	// ���� 2nd coordinate ���� 1st coordinate �� �� ũ�ٸ�, ���� �����Ͽ� �ڿ� �� ���� ���� �ٿ��ش�. 
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
	if (c - a < 0 || d - b<0) { // �ι�° ��ǥ�� ù��° ��ǥ���� ���� �� ����ó��
		cout << "cropped �� �� �����ϴ�.";
		return 0;
	}
	// �̶� output���ִ� �������� a�� ���� width, c�� �� width�� �ǹ��ϸ�
	// b�� ���� height, d�� �� height�� �ǹ��Ѵ�
	char width[10];
	char height[10];
	_itoa(c - a, width, 10); // ������ ���ڿ���  ��ȯ�ؼ� width�� ����
	_itoa(d - b, height, 10); // ������ ���ڿ��� ��ȯ�ؼ� height�� ����

	char RESULT_NAME1[100]; // cropped image ���� �� ���� �̸�
	strcpy(RESULT_NAME1, IMAGE_NAME);
	strcat(RESULT_NAME1, "_cropped_(");
	strcat(RESULT_NAME1, width);
	strcat(RESULT_NAME1, ")x(");
	strcat(RESULT_NAME1, height);
	strcat(RESULT_NAME1, ").raw");
	char RESULT_NAME2[100]; // horizontalflip image ���� �� ���� �̸�
	strcpy(RESULT_NAME2, IMAGE_NAME); 
	strcat(RESULT_NAME2, "_horizontalflip.raw");
	char RESULT_NAME3[100]; // verticalflip image ���� �� ���� �̸�
	strcpy(RESULT_NAME3, IMAGE_NAME);
	strcat(RESULT_NAME3, "_verticalflip.raw");

	input_image = memory_alloc2D(IMAGE_HEIGHT, IMAGE_WIDTH); // sizeof(char) * 512 * 512 ��ŭ�� �޸� �Ҵ�
	if (input_image == 0) // �޸� �Ҵ翡 �������� ��
	{
		cout << "�޸� �Ҵ翡 �����߽��ϴ�." << endl;
		return -1;
	}

	fread((unsigned char*)input_image[0], sizeof(unsigned char), IMAGE_WIDTH * IMAGE_HEIGHT, fp); // 512*512*sizeof(unsigned char) ��ŭ�� ������ input_image�� ����
	fclose(fp); // ���� �ݱ�

	output_image = memory_alloc2D(IMAGE_HEIGHT, IMAGE_WIDTH); // sizeof(char) * 512 * 512 ��ŭ�� �޸� �Ҵ�
	if (output_image == 0) // �޸� �Ҵ翡 �������� ��
	{
		cout << "�޸� �Ҵ翡 �����߽��ϴ�." << endl;
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

	fopen_s(&fp, RESULT_NAME1, "wb"); // RESULT_NAME1�� ��ġ�ϴ� ���� ����(������)
	if (fp == 0)
	{
		cout << "Failed to open filename(" << RESULT_NAME1 << ")" << endl;
		return -1;
	}

	fwrite((unsigned char*)output_image[0], sizeof(unsigned char), (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT), fp); 
	// �������Ͽ� sizeof(unsigned char) * (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT) ��ŭ�� ũ�⸦ ������� �ۼ� �̶� (unsigned char*)output_image[0]�� �̿���
	fclose(fp); // ���� �ݱ�


	//Horizontally
	for (int i = 0; i < IMAGE_HEIGHT; i++)
	{
		for (int j = 0; j < IMAGE_WIDTH; j++)
		{
			output_image[i][j] = input_image[i][IMAGE_WIDTH-1-j];
		}
	}


	fopen_s(&fp, RESULT_NAME2, "wb"); // RESULT_NAME2�� ��ġ�ϴ� ���� ����(������)
	if (fp == 0)
	{
		cout << "Failed to open filename(" << RESULT_NAME2 << ")" << endl;
		return -1;
	}

	fwrite((unsigned char*)output_image[0], sizeof(unsigned char), (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT), fp);
	// �������Ͽ� sizeof(unsigned char) * (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT) ��ŭ�� ũ�⸦ ������� �ۼ� �̶� (unsigned char*)output_image[0]�� �̿���
	fclose(fp); // ���� �ݱ�

	//Vertically flipped
	for (int i = 0; i < IMAGE_HEIGHT; i++)
	{
		for (int j = 0; j < IMAGE_WIDTH; j++)
		{
			output_image[i][j] = input_image[IMAGE_HEIGHT-i-1][j];
		}
	}

	fopen_s(&fp, RESULT_NAME3, "wb"); // RESULT_NAME3�� ��ġ�ϴ� ���� ����(������)
	if (fp == 0)
	{
		cout << "Failed to open filename(" << RESULT_NAME3 << ")" << endl;
		return -1;
	}

	fwrite((unsigned char*)output_image[0], sizeof(unsigned char), (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT), fp);
	// �������Ͽ� sizeof(unsigned char) * (size_t)(IMAGE_WIDTH * IMAGE_HEIGHT) ��ŭ�� ũ�⸦ ������� �ۼ� �̶� (unsigned char*)output_image[0]�� �̿���
	fclose(fp); // ���� �ݱ�
	


	memory_free2D(output_image); // output_image �޸� ����
	memory_free2D(input_image); // input_image �޸� ����

	cout << "Output images are stored!"; // ��� ������ �������� �ۼ� �ƴٸ� ���

	return 0; // 0�� ��ȯ
}
