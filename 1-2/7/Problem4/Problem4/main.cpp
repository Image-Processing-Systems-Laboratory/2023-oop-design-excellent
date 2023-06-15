#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>

#define STRSIZE 50

using namespace std;

//���� 2���� uint8_t �� �ڷ� �迭�� �����ϰ�, �����ϴ� �Լ��� �����
uint8_t** memory_alloc2D(uint32_t height, uint32_t width);
int memory_free2D(uint8_t** ppMemallocated);
//�� ��ǥ�� ���� �߸� ���簢�� ����� �̹����� OriginalName_wdithxheight.raw �� �����ϴ� �Լ��� �����
void cropCopy(const char*, uint8_t**, int cordinate[2][2]);
//���� ������ �̹����� OriginalName_wdithxheight.raw �� �����ϴ� �Լ��� �����
void verticalflipFlippedCopy(const char* imageName, uint8_t** Buffer, int wdith, int height);
//�¿� ������ �̹����� OriginalName_wdithxheight.raw �� �����ϴ� �Լ��� �����
void horizontallyFlippedCopy(const char* imageName, uint8_t** Buffer, int wdith, int height);
//1���� uint8_t���� �迭�� �����ϴ� �Լ��� �����
void horizontallyFlipBuffer(uint8_t* Buffer, int wdith);
//������ ���ڿ��� �Ͻ������� ��ȯ�ϴ� �Լ��� ����� (��ȯ�Ǵ� char*�� �Լ� ���� ���� �����̴�. �� �Լ��� �� ȣ�� �� �� ���� �ٲ� �� �ִ�.)
char* int_to_string(unsigned int);

int main() {
	//���� �̹��� ������ ��ü �̸��� ������ ���ڿ� ����
	char fileName[STRSIZE];
	//���� �̹��� ������ �̸�����, �� �̸� �ڿ� ��ġ�� �̹����� ũ��� ���� Ȯ���ڴ� ������ �̸��� ������ ���ڿ� ����
	char imageName[STRSIZE];

	//crop�� ���� ����� �� ��ǥ�� ������ �迭
	int coordinate[2][2] = { 0, };
	//���� �̸� �Է�
	cout << "Input file name : ";
	cin >> fileName;

	//�̹����� ũ�⸦ ������ ���� 512 x 512�� �⺻������ ����
	int IMG_HEIGHT = 512;
	int IMG_WDITH = 512;
	
	//��ǥ�� ������ "x, y"���� �Է¿� ���� , �� �����ϰ� �ΰ��� ������ �����ϱ� ���� �ݺ���
	for (int i = 0; i < 2; i++) {
		//x�� �ش��ϴ� ���ڿ� �Է��� ������ ���ڿ� ����
		char input[STRSIZE/2];
		cout << i + 1 << "st coordinate: ";
		//�Է�
		cin >> input >> coordinate[i][1];

		//x�� �ش��ϴ� ���ڿ� �Է��� ������ ������ �ּҸ� �ӽ� ����
		char* tmp = input;
		//,�� ��ġ�� ���� �� ����
		int x = 0;
		//���� ��ġ�� ���� �� ����
		int cnt = 1;
		//���ڿ��� ���ڰ� null�� �ɶ����� �ϳ��� Ȯ���� ���� , �� ��ġ�� x �� ����
		while ((*++tmp)) {
			if (*tmp == ',') {
				x = cnt;
			}
			cnt++;
		}
		cnt = 1;
		//x��° ���������� ���ڿ��� ���Ͽ� ���ڸ� ���ڷ� ��ȯ�ϱ� ���� ascii�ڵ� 0�� �ش��ϴ� ���� 48�� ���ְ� �ڸ����� ���� ���ڷ� ��ȯ
		for (int j = x - 1; j >=0; j--) {
			if (!((input[j] - 48) / 10)) {
				coordinate[i][0] += (input[j] - 48) * cnt;
				cnt *= 10;
			}
		}
			
	}

	//�̹����� ������ ���������� ��Ÿ���� ����
	bool isEnd = false;

	//������ ��ü �̸����� ���� �̹����� ũ�� ����(�̹��� ������ N x M ���� �̹����� ũ��� �����Ѵ�.)
	for (int i = 0; i < STRSIZE; i++) {
		//���� ������ �����ų� ���� �̸��� �������� ���������� �ݺ��� Ż��
		if (!fileName[i] || isEnd)
			break;
		//_�� �߰�������
		if (fileName[i] == '_') {
			//_���� ���ں��͸� �������� ����
			char* tmp = &fileName[i + 1];
			//'x'�� ��ġ�� (N x M)���� ������ ��ġ�� �����ϱ� ���� ���� x, f ����
			int x, f;
			//��ġ�� ���� �� ����
			int cnt = 1;
			//_�� �߰������� �̸� �߰������� ����
			bool isFound = false;
			
			//���� _�� �����ų� ���ڰ� �ƴ� ���ڸ� ������ ��
			while (*(++tmp) != '_' || !((*(++tmp) - 48) / 10)) {
				//x�� ���� �� x �� ��ġ�� ����
				if (*tmp == 'x') {
					x = cnt;
				}
				//(N x M)���� �ƴҽ� isFound�� �������� �����ϰ� �ݺ��� Ż��
				else if ((*tmp - 48) / 10 > 0) {
					isFound = false;
					break;
				}
				//ã������ �����ϰ� cnt�� ���� ��ġ�� ����
				isFound = true;
				cnt++;
				//(N x M)���� ������ ��ġ�� cnt�� ����
				f = cnt;
			}

			//i ��, �� _ ���� ������ �̸��� inmageName�� ����
			int j = 0;
			for (; j < i; j++) {
				imageName[j] = fileName[j];
			}
			imageName[j] = 0;

			//(N x M)���� ã���� �� ���� ���ΰ��� �����ϴ� ���ǹ�
			if (isFound) {
				//���� ���θ� 0���� �ٽ� ����
				IMG_HEIGHT = 0;
				IMG_WDITH = 0;
				cnt = 1;
				//���ڿ��� ���ڷ� ��ȯ �� �ڸ����� ���� ���� ���ΰ��� ����
				for (int j = i + x; j > i ; j--) {
					IMG_WDITH += (fileName[j] - 48) * cnt;
					cnt *= 10;
				}
				cnt = 1;
				//���ڿ��� ���ڷ� ��ȯ �� �ڸ����� ���� ���� ���ΰ��� ����
				for (int j = i + f; j > i + x + 1; j--) {
					IMG_HEIGHT += (fileName[j] - 48) * cnt;
					cnt *= 10;
				}
				//�ݺ��� Ż��
				break;
			}
		}
	}

	//���� ��Ʈ�� ����
	FILE* fpInputImage = 0;
	//���� ��Ʈ�� ����
	fpInputImage = fopen(fileName, "rb");
	//���� ��Ʈ�� ���� ���� �� ����
	if (!fpInputImage) {
		return 1;
	}

	//���ΰ�, ���ΰ� ũ���� 2���� uint8_t�� �迭 ����
	uint8_t** ppInputImageBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WDITH);

	//�迭 ���� ���н� ����
	if (!ppInputImageBuffer)
		return 1;

	//���Ϸκ��� �̹����� ��� �ʼ����� ppInputImageBuffer�� ����
	for (int i = 0; i < IMG_HEIGHT; i++) {
		fread((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WDITH, fpInputImage);
	}

	//coordinate�� �������� �̹��� �ڸ��� �� ����
	cropCopy(imageName, ppInputImageBuffer, coordinate);
	//�̹��� ���� ���� �� ����
	verticalflipFlippedCopy(imageName, ppInputImageBuffer, IMG_WDITH, IMG_HEIGHT);
	//�̹��� �¿� ���� �� ����
	horizontallyFlippedCopy(imageName, ppInputImageBuffer, IMG_WDITH, IMG_HEIGHT);

	//�迭�� �Ҵ�� �޸� ����, ������ �߻��� �� �ִ� ���� ����
	if (memory_free2D(ppInputImageBuffer))
		return 1;

	//�̹����� �����ߴٴ� ���� ���
	cout << "Output images are stored!" << endl;

	//����
	return 0;
}
//�� ��ǥ�� ���� �߸� ���簢�� ����� �̹����� OriginalName_wdithxheight.raw �� �����ϴ� �Լ��� ���Ǻ�
void cropCopy(const char* imageName, uint8_t** Buffer, int cordinate[2][2]) {
	//�߸� �̹����� ���ΰ� ���
	int wdith = cordinate[1][0] - cordinate[0][0];
	//����� �̸� �迭 ����
	char name[50];
	//����� �̸� ����
	strcpy(name, imageName);
	strcat(name, "_");
	strcat(name, "copped");
	strcat(name, "_");
	strcat(name, int_to_string(wdith));
	strcat(name, "x");
	//cordinate[1][1] - cordinate[0][1] : ���ΰ�
	strcat(name, int_to_string(cordinate[1][1] - cordinate[0][1]));
	strcat(name, ".raw");
	//����� �̸����� 2�� ���� ���� ���� ��Ʈ�� ����
	FILE* fpOutputImage = fopen(name, "wb");
	//���� �߻��� �Լ� ����
	if (!fpOutputImage)
		return;
	//1�� ��ǥ�� �������� 2�� ��ǥ�� y�� ���� 1�� ��ǥ�� x ���� ���� 1�� ��ǥ�� x ���� wdith�� ���� ��ǥ���� ���� ���
	for (int i = cordinate[0][1]; i < cordinate[1][1]; i++) {
		fwrite((uint8_t*)(Buffer[i] + cordinate[0][0]), sizeof(uint8_t), wdith, fpOutputImage);
	}
	//���� ��Ʈ�� �ݱ�
	fclose(fpOutputImage);
}
//���� ������ �̹����� OriginalName_wdithxheight.raw �� �����ϴ� �Լ��� ���Ǻ�
void verticalflipFlippedCopy(const char* imageName, uint8_t** Buffer, int wdith, int height) {
	//����� �̸� �迭 ����
	char name[50];
	//����� �̸� ����
	strcpy(name, imageName);
	strcat(name, "_");
	strcat(name, int_to_string(wdith));
	strcat(name, "x");
	strcat(name, int_to_string(height));
	strcat(name, "_");
	strcat(name, "verticalflip.raw");
	//����� �̸����� 2�� ���� ���� ���� ��Ʈ�� ����
	FILE* fpOutputImage = fopen(name, "wb");
	//���� �߻��� �Լ� ����
	if (!fpOutputImage)
		return;
	//�̹����� �� ������ �� �ϴܱ��� ���ʷ� ���� ���
	for (int i = height - 1; i >= 0; i--) {
		fwrite((uint8_t*)(Buffer[i]), sizeof(uint8_t), wdith, fpOutputImage);
	}
	//���� ��Ʈ�� �ݱ�
	fclose(fpOutputImage);
}
//�¿� ������ �̹����� OriginalName_wdithxheight.raw �� �����ϴ� �Լ��� ���Ǻ�
void horizontallyFlippedCopy(const char* imageName, uint8_t** Buffer, int wdith, int height) {
	//����� �̸� �迭 ����
	char name[50];
	//����� �̸� ����
	strcpy(name, imageName);
	strcat(name, "_");
	strcat(name, int_to_string(wdith));
	strcat(name, "x");
	strcat(name, int_to_string(height));
	strcat(name, "_");
	strcat(name, "horizontalflip.raw");
	//����� �̸����� 2�� ���� ���� ���� ��Ʈ�� ����
	FILE* fpOutputImage = fopen(name, "wb");
	//���� �߻��� �Լ� ����
	if (!fpOutputImage)
		return;
	//�̹����� �� �ϴܺ��� �� ������ �� ���� uint8_t �迭�� �����ϰ� ���� ���
	for (int i = 0; i < height; i++) {
		//���� uint8_t �迭�� ����
		horizontallyFlipBuffer(Buffer[i], wdith);
		fwrite((uint8_t*)(Buffer[i]), sizeof(uint8_t), wdith, fpOutputImage);
	}
	//���� ��Ʈ�� �ݱ�
	fclose(fpOutputImage);
}
//1���� uint8_t���� �迭�� �����ϴ� �Լ��� ���Ǻ�
void horizontallyFlipBuffer(uint8_t* Buffer, int wdith) {
	//�� ���� �ٲٱ� ���� �ӽ� ����
	uint8_t tmp = 0;
	//�� wdith / 2 ��ŭ �ݺ��Ͽ� �迭 ����
	for (int i = 0; i < wdith / 2 - 1; i++) {
		//�ӽ� ����
		tmp = Buffer[i];
		//����븦 �������� �� ���� ����
		Buffer[i] = Buffer[wdith - i - 1];
		Buffer[wdith - i - 1] = tmp;
	}
}
//������ ���ڿ��� �Ͻ������� ��ȯ�ϴ� �Լ��� ���Ǻ� (��ȯ�Ǵ� char*�� �Լ� ���� ���� �����̴�. �� �Լ��� �� ȣ�� �� �� ���� �ٲ� �� �ִ�.)
char* int_to_string(unsigned int x) {
	//����� ����� ������ ���� ����
	static char result[10] = { 0, };
	//�ڸ����� ������ ����
	int digit = 1;
	//�ڸ����� ���ϱ� ���� �Է��� ������ �ӽú��� ����, �Ҵ�
	int tmp = x;
	//x�� �ڸ��� ���ϱ�
	while (tmp = tmp / 10) {
		digit *= 10;
	}
	//�ڸ����� ������ �� �ڸ��� ���� ���ϰ� �̸� ���ڷ� ��ȯ
	for (int i = 0; i < 10; i++) {
		//�ڸ����� �� ��������� �ݺ��� Ż��
		if (!digit)
			break;
		//���� �� �ڸ��� ���ڸ� ���ڷ� ��ȯ�ϰ� �̸� ���ʷ� ����
		result[i] = x / digit + 48;
		//���ڿ��� �������� null�� ����
		result[i + 1] = 0;
		//���� ���ڸ��� ���ڸ� ����
		x = x % digit;
		//�ڸ����� �ϳ� ����
		digit /= 10;

	}
	//��� ��ȯ
	return result;
}
//���� 2���� uint8_t �� �ڷ� �迭�� �����ϴ� �Լ��� ���Ǻ�
uint8_t** memory_alloc2D(uint32_t height, uint32_t width) {
	//uint8_t�� 1���� �迭�� height��ŭ ���� ũ���� ������ �Ҵ� 
	uint8_t** ppMem2d = new uint8_t * [height];
	//�Ҵ� ���� ���θ� �Ǻ�
	if (!ppMem2d)
		return 0;
	//ũ�Ⱑ width uint8_t�� 1���� �迭�� height�� ��ŭ ���� ũ���� ������ �Ҵ�.
	ppMem2d[0] = new uint8_t[height * width];
	//�Ҵ� ���� ���θ� �Ǻ�
	if (!ppMem2d[0]) {
		delete[] ppMem2d;
		return 0;
	}
	//(hight x wdith)���� 2���� �迭�� ����
	for (int i = 1; i < height; i++) {
		ppMem2d[i] = ppMem2d[i - 1] + width;
	}
	//�Ҵ��� ������ �ּҸ� ��ȯ
	return ppMem2d;
}
//���� 2���� uint8_t �� �ڷ� �迭�� �����ϴ� �Լ��� �����
int memory_free2D(uint8_t** ppMemallocated) {
	//�Ҵ��� �ȵǾ������� -1 ��ȯ
	if (!ppMemallocated)
		return -1;
	//�Ҵ�� ���� ����
	if (ppMemallocated[0])
		delete[] ppMemallocated[0];
	delete[] ppMemallocated;
	// 0 ��ȯ
	return 0;
}