#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>

#define STRSIZE 50

using namespace std;

//각각 2차원 uint8_t 형 자료 배열을 생성하고, 해제하는 함수의 선언부
uint8_t** memory_alloc2D(uint32_t height, uint32_t width);
int memory_free2D(uint8_t** ppMemallocated);
//두 좌표에 의해 잘린 직사각형 모양의 이미지를 OriginalName_wdithxheight.raw 로 저장하는 함수의 선언부
void cropCopy(const char*, uint8_t**, int cordinate[2][2]);
//상하 반전된 이미지를 OriginalName_wdithxheight.raw 로 저장하는 함수의 선언부
void verticalflipFlippedCopy(const char* imageName, uint8_t** Buffer, int wdith, int height);
//좌우 반전된 이미지를 OriginalName_wdithxheight.raw 로 저장하는 함수의 선언부
void horizontallyFlippedCopy(const char* imageName, uint8_t** Buffer, int wdith, int height);
//1차원 uint8_t형의 배열을 반전하는 함수의 선언부
void horizontallyFlipBuffer(uint8_t* Buffer, int wdith);
//정수를 문자열로 일시적으로 변환하는 함수의 선언부 (반환되는 char*이 함수 내의 전역 변수이다. 즉 함수를 또 호출 할 시 값이 바뀔 수 있다.)
char* int_to_string(unsigned int);

int main() {
	//원본 이미지 파일의 전체 이름을 저장할 문자열 변수
	char fileName[STRSIZE];
	//원본 이미지 파일의 이름만을, 즉 이름 뒤에 위치한 이미지의 크기와 파일 확장자는 제외한 이름을 저장할 문자열 변수
	char imageName[STRSIZE];

	//crop을 위해 사용할 두 좌표를 저장할 배열
	int coordinate[2][2] = { 0, };
	//파일 이름 입력
	cout << "Input file name : ";
	cin >> fileName;

	//이미지의 크기를 저장할 변수 512 x 512을 기본값으로 설정
	int IMG_HEIGHT = 512;
	int IMG_WDITH = 512;
	
	//좌표를 받을때 "x, y"식의 입력에 대해 , 을 무시하고 두개의 정수로 저장하기 위한 반복문
	for (int i = 0; i < 2; i++) {
		//x에 해당하는 문자열 입력을 저장할 문자열 변수
		char input[STRSIZE/2];
		cout << i + 1 << "st coordinate: ";
		//입력
		cin >> input >> coordinate[i][1];

		//x에 해당하는 문자열 입력을 저장한 변수의 주소를 임시 저장
		char* tmp = input;
		//,의 위치를 저장 할 변수
		int x = 0;
		//현재 위치를 저장 할 변수
		int cnt = 1;
		//문자열의 문자가 null이 될때까지 하나씩 확인해 가며 , 의 위치를 x 에 저장
		while ((*++tmp)) {
			if (*tmp == ',') {
				x = cnt;
			}
			cnt++;
		}
		cnt = 1;
		//x번째 이전까지의 문자열에 대하여 문자를 숫자로 변환하기 위해 ascii코드 0에 해당하는 정수 48을 빼주고 자릿수를 곱해 숫자로 변환
		for (int j = x - 1; j >=0; j--) {
			if (!((input[j] - 48) / 10)) {
				coordinate[i][0] += (input[j] - 48) * cnt;
				cnt *= 10;
			}
		}
			
	}

	//이미지의 추출이 끝났는지를 나타내는 변수
	bool isEnd = false;

	//파일의 전체 이름으로 부터 이미지의 크기 추출(이미지 파일의 N x M 꼴을 이미지의 크기로 가정한다.)
	for (int i = 0; i < STRSIZE; i++) {
		//만약 추출이 끝났거나 파일 이름의 마지막에 도닥했을때 반복문 탈출
		if (!fileName[i] || isEnd)
			break;
		//_를 발견했을때
		if (fileName[i] == '_') {
			//_다음 글자부터를 기준으로 설정
			char* tmp = &fileName[i + 1];
			//'x'의 위치와 (N x M)꼴의 마지막 위치를 저장하기 위해 각각 x, f 선언
			int x, f;
			//위치를 저장 할 변수
			int cnt = 1;
			//_를 발견했을때 이를 발견했음을 설정
			bool isFound = false;
			
			//다음 _을 만나거나 숫자가 아닌 문자를 만났을 시
			while (*(++tmp) != '_' || !((*(++tmp) - 48) / 10)) {
				//x를 만날 시 x 의 위치를 저장
				if (*tmp == 'x') {
					x = cnt;
				}
				//(N x M)꼴이 아닐시 isFound를 거짓으로 설정하고 반복문 탈출
				else if ((*tmp - 48) / 10 > 0) {
					isFound = false;
					break;
				}
				//찾았음을 설정하고 cnt를 다음 위치로 설정
				isFound = true;
				cnt++;
				//(N x M)꼴의 마지막 위치를 cnt로 설정
				f = cnt;
			}

			//i 전, 즉 _ 이전 까지의 이름을 inmageName에 저장
			int j = 0;
			for (; j < i; j++) {
				imageName[j] = fileName[j];
			}
			imageName[j] = 0;

			//(N x M)꼴을 찾았을 시 가로 세로값을 저장하는 조건문
			if (isFound) {
				//가로 세로를 0으로 다시 설정
				IMG_HEIGHT = 0;
				IMG_WDITH = 0;
				cnt = 1;
				//문자열을 숫자로 변환 후 자릿수를 곱한 값을 가로값에 더함
				for (int j = i + x; j > i ; j--) {
					IMG_WDITH += (fileName[j] - 48) * cnt;
					cnt *= 10;
				}
				cnt = 1;
				//문자열을 숫자로 변환 후 자릿수를 곱한 값을 세로값에 더함
				for (int j = i + f; j > i + x + 1; j--) {
					IMG_HEIGHT += (fileName[j] - 48) * cnt;
					cnt *= 10;
				}
				//반복문 탈출
				break;
			}
		}
	}

	//파일 스트림 선언
	FILE* fpInputImage = 0;
	//파일 스트림 생성
	fpInputImage = fopen(fileName, "rb");
	//파일 스트림 생성 실패 시 종료
	if (!fpInputImage) {
		return 1;
	}

	//세로값, 가로값 크기의 2차원 uint8_t형 배열 생성
	uint8_t** ppInputImageBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WDITH);

	//배열 생성 실패시 종료
	if (!ppInputImageBuffer)
		return 1;

	//파일로부터 이미지의 모든 필셀값을 ppInputImageBuffer에 저장
	for (int i = 0; i < IMG_HEIGHT; i++) {
		fread((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WDITH, fpInputImage);
	}

	//coordinate를 기준으로 이미지 자르기 후 저장
	cropCopy(imageName, ppInputImageBuffer, coordinate);
	//이미지 상하 반전 후 저장
	verticalflipFlippedCopy(imageName, ppInputImageBuffer, IMG_WDITH, IMG_HEIGHT);
	//이미지 좌우 반전 후 저장
	horizontallyFlippedCopy(imageName, ppInputImageBuffer, IMG_WDITH, IMG_HEIGHT);

	//배열에 할당된 메모리 해제, 해제시 발생할 수 있는 오류 검출
	if (memory_free2D(ppInputImageBuffer))
		return 1;

	//이미지를 저장했다는 것을 출력
	cout << "Output images are stored!" << endl;

	//종료
	return 0;
}
//두 좌표에 의해 잘린 직사각형 모양의 이미지를 OriginalName_wdithxheight.raw 로 저장하는 함수의 정의부
void cropCopy(const char* imageName, uint8_t** Buffer, int cordinate[2][2]) {
	//잘린 이미지의 가로값 계산
	int wdith = cordinate[1][0] - cordinate[0][0];
	//저장될 이름 배열 선언
	char name[50];
	//저장될 이름 생성
	strcpy(name, imageName);
	strcat(name, "_");
	strcat(name, "copped");
	strcat(name, "_");
	strcat(name, int_to_string(wdith));
	strcat(name, "x");
	//cordinate[1][1] - cordinate[0][1] : 세로값
	strcat(name, int_to_string(cordinate[1][1] - cordinate[0][1]));
	strcat(name, ".raw");
	//저장될 이름으로 2진 쓰기 모드로 파일 스트림 생성
	FILE* fpOutputImage = fopen(name, "wb");
	//오류 발생시 함수 종료
	if (!fpOutputImage)
		return;
	//1번 좌표를 기준으로 2번 좌표의 y값 까지 1번 좌표의 x 값을 부터 1번 좌표의 x 값에 wdith를 더한 좌표까지 파일 출력
	for (int i = cordinate[0][1]; i < cordinate[1][1]; i++) {
		fwrite((uint8_t*)(Buffer[i] + cordinate[0][0]), sizeof(uint8_t), wdith, fpOutputImage);
	}
	//파일 스트림 닫기
	fclose(fpOutputImage);
}
//상하 반전된 이미지를 OriginalName_wdithxheight.raw 로 저장하는 함수의 정의부
void verticalflipFlippedCopy(const char* imageName, uint8_t** Buffer, int wdith, int height) {
	//저장될 이름 배열 선언
	char name[50];
	//저장될 이름 생성
	strcpy(name, imageName);
	strcat(name, "_");
	strcat(name, int_to_string(wdith));
	strcat(name, "x");
	strcat(name, int_to_string(height));
	strcat(name, "_");
	strcat(name, "verticalflip.raw");
	//저장될 이름으로 2진 쓰기 모드로 파일 스트림 생성
	FILE* fpOutputImage = fopen(name, "wb");
	//오류 발생시 함수 종료
	if (!fpOutputImage)
		return;
	//이미지의 맨 위부터 맨 하단까지 차례로 파일 출력
	for (int i = height - 1; i >= 0; i--) {
		fwrite((uint8_t*)(Buffer[i]), sizeof(uint8_t), wdith, fpOutputImage);
	}
	//파일 스트림 닫기
	fclose(fpOutputImage);
}
//좌우 반전된 이미지를 OriginalName_wdithxheight.raw 로 저장하는 함수의 정의부
void horizontallyFlippedCopy(const char* imageName, uint8_t** Buffer, int wdith, int height) {
	//저장될 이름 배열 선언
	char name[50];
	//저장될 이름 생성
	strcpy(name, imageName);
	strcat(name, "_");
	strcat(name, int_to_string(wdith));
	strcat(name, "x");
	strcat(name, int_to_string(height));
	strcat(name, "_");
	strcat(name, "horizontalflip.raw");
	//저장될 이름으로 2진 쓰기 모드로 파일 스트림 생성
	FILE* fpOutputImage = fopen(name, "wb");
	//오류 발생시 함수 종료
	if (!fpOutputImage)
		return;
	//이미지의 맨 하단부터 맨 위까지 각 행의 uint8_t 배열을 반전하고 파일 출력
	for (int i = 0; i < height; i++) {
		//행의 uint8_t 배열을 반전
		horizontallyFlipBuffer(Buffer[i], wdith);
		fwrite((uint8_t*)(Buffer[i]), sizeof(uint8_t), wdith, fpOutputImage);
	}
	//파일 스트림 닫기
	fclose(fpOutputImage);
}
//1차원 uint8_t형의 배열을 반전하는 함수의 정의부
void horizontallyFlipBuffer(uint8_t* Buffer, int wdith) {
	//두 값을 바꾸기 위한 임시 변수
	uint8_t tmp = 0;
	//총 wdith / 2 만큼 반복하여 배열 반전
	for (int i = 0; i < wdith / 2 - 1; i++) {
		//임시 정장
		tmp = Buffer[i];
		//가운대를 기준으로 양 쪽을 반전
		Buffer[i] = Buffer[wdith - i - 1];
		Buffer[wdith - i - 1] = tmp;
	}
}
//정수를 문자열로 일시적으로 변환하는 함수의 정의부 (반환되는 char*이 함수 내의 전역 변수이다. 즉 함수를 또 호출 할 시 값이 바뀔 수 있다.)
char* int_to_string(unsigned int x) {
	//출력할 결과를 저장할 전역 변수
	static char result[10] = { 0, };
	//자릿수를 저장할 변수
	int digit = 1;
	//자릿수를 구하기 위해 입력을 저장할 임시변수 선언, 할당
	int tmp = x;
	//x의 자릿수 구하기
	while (tmp = tmp / 10) {
		digit *= 10;
	}
	//자릿수로 나누어 각 자리의 수를 구하고 이를 문자로 변환
	for (int i = 0; i < 10; i++) {
		//자릿수를 다 사용했을때 반복문 탈출
		if (!digit)
			break;
		//구한 각 자리의 숫자를 문자로 변환하고 이를 차례로 저장
		result[i] = x / digit + 48;
		//문자열의 마지막을 null로 설정
		result[i + 1] = 0;
		//가장 윗자리의 숫자를 제거
		x = x % digit;
		//자릿수를 하나 낮춤
		digit /= 10;

	}
	//결과 반환
	return result;
}
//각각 2차원 uint8_t 형 자료 배열을 생성하는 함수의 정의부
uint8_t** memory_alloc2D(uint32_t height, uint32_t width) {
	//uint8_t형 1차원 배열을 height만큼 담을 크기의 공간을 할당 
	uint8_t** ppMem2d = new uint8_t * [height];
	//할당 실패 여부를 판별
	if (!ppMem2d)
		return 0;
	//크기가 width uint8_t형 1차원 배열을 height개 만큼 담을 크기의 공간을 할당.
	ppMem2d[0] = new uint8_t[height * width];
	//할당 실패 여부를 판별
	if (!ppMem2d[0]) {
		delete[] ppMem2d;
		return 0;
	}
	//(hight x wdith)꼴의 2차원 배열로 설정
	for (int i = 1; i < height; i++) {
		ppMem2d[i] = ppMem2d[i - 1] + width;
	}
	//할당한 공간의 주소를 반환
	return ppMem2d;
}
//각각 2차원 uint8_t 형 자료 배열을 해제하는 함수의 선언부
int memory_free2D(uint8_t** ppMemallocated) {
	//할당이 안되어있으면 -1 반환
	if (!ppMemallocated)
		return -1;
	//할당된 공간 해제
	if (ppMemallocated[0])
		delete[] ppMemallocated[0];
	delete[] ppMemallocated;
	// 0 반환
	return 0;
}