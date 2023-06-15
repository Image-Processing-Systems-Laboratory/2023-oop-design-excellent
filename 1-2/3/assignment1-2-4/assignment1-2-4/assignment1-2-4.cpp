#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
#define IMG_HEIGHT 512
#define IMG_WIDTH  512      //문제에서 지정해준 크기 512 지정


uint8_t** memory_alloc2D(uint32_t height, uint32_t width) {     //2차원 배열에 동적할당 받는 예제 코드
    uint8_t** ppMem2d = new uint8_t * [height];     //이차원 배열 동적할당이므로 더블 포인터형 사용
    if (ppMem2d == 0)
        return 0;
    ppMem2d[0] = new uint8_t[height * width];       //높이 * 가로만큼의 크기만큼 할당 받는다
    if (ppMem2d[0] == 0) {
        delete[] ppMem2d;
        return 0;
    }
    for (int i = 1; i < height; i++)
        ppMem2d[i] = ppMem2d[i - 1] + width;
    return ppMem2d;
}

int memory_free2D(uint8_t** ppMemAllocated) {           //동적할당 해제 함수
    if (ppMemAllocated == 0)
        return -1;
    if (ppMemAllocated[0])
        delete[] ppMemAllocated[0];
    delete[] ppMemAllocated;        //동적할당 해제
    return 0;
}

int main() {
    FILE* fpInputImage = 0;
    FILE* fpOutputImage = 0;
    uint8_t tmp;
    uint8_t** ppInputImageBuffer = 0;
    char IMG_NAME[100];
    char IMG_NAME2[100];
    int x1, y1, x2, y2;                     //각 점들의 x, y점의 좌표를 받을 변수를 선언
    char n1[4], n2[4];

    cout << "Input file name : ";
    cin >> IMG_NAME;                        //파일 이름 입력받기
    cout << "1st coordinate : ";
    cin >> x1 >> y1;                        //첫 점의 x, y좌표를 입력받음
    cout << "2st coordinate : ";
    cin >> x2 >> y2;                        //두번째 점의 x, y좌표를 입력받음
    strcpy(IMG_NAME2, IMG_NAME);
    fpInputImage = fopen(IMG_NAME, "rb");           //입력받은 파일의 이미지를 읽기모드로 연다.
    ppInputImageBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);     //이미지 사이즈만큼 동적할당 받음
    for (int i = 0; i < IMG_HEIGHT; i++)  //높이만큼 반복문 수행
        fread((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpInputImage);    //읽기모드로 연 파일을 읽어 ppInputImageBuffer에 저장한다.



    fpOutputImage = fopen(strcat(IMG_NAME2, "_horizontalflip.raw"), "wb");      //수평으로 뒤집어진 파일을 만들기 위해 메모리를 할당 받아준다.

    for (int i = 0; i < IMG_HEIGHT; i++) {             //512번을 모두 반복한다.
        for (int j = 0; j < IMG_WIDTH/2; j++) {         //256번 반복한다.
            swap(ppInputImageBuffer[i][j], ppInputImageBuffer[i][511 - j]);
        }
    }       //수평 출력

    for (int i = 0; i < IMG_HEIGHT; i++)        //수직으로 변환된 데이터를 수직 데이터를 출력할 파일에 써준다.
        fwrite((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpOutputImage);

    fclose(fpOutputImage);      //파일을 닫는다.(수직 출력 닫기)
    strcpy(IMG_NAME2, IMG_NAME);        //IMG_NAME2에 IMG_NAME을 복사해준다.
    for (int i = 0; i < IMG_HEIGHT; i++) {     //512번 반복한다.
        for (int j = 0; j < IMG_WIDTH/2; j++) {     //256번 반복하면서 수직 변환을 수행해준다.
            swap(ppInputImageBuffer[i][j], ppInputImageBuffer[i][511 - j]);
        }
    }

    for (int i = 0; i < IMG_HEIGHT; i++) {
        for (int j = 0; j < IMG_WIDTH/2; j++) {
            swap(ppInputImageBuffer[j][i], ppInputImageBuffer[511 - j][i]);
        }
    }

    fpOutputImage = fopen(strcat(IMG_NAME2, "_verticalflip.raw"), "wb");        //수평 파일을 만들어준다.

    for (int i = 0; i < IMG_HEIGHT; i++)            //수직변환된 이미지가 저장된 배열을 반복문을 통해 출력할 파일에 넣어준다.
        fwrite((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpOutputImage);

    fclose(fpOutputImage);      //수직 변환의 결과 파일을 닫아준다.

    for (int i = 0; i < IMG_WIDTH; i++) {         //가로 길이 만큼 반복해준다.
        for (int j = 0; j < IMG_HEIGHT/2; j++) {     //높이 길이의 절반만큼 반복해준다.
            swap(ppInputImageBuffer[j][i], ppInputImageBuffer[511 - j][i]);
        }
    }
    strcpy(IMG_NAME2, IMG_NAME);

    _itoa(y2 - y1, n1, 10);
    _itoa(x2 - x1, n2, 10);

    fpOutputImage = fopen(strcat(strcat(strcat(strcat(strcat(IMG_NAME, "_cropped_"), n1), "x"), n2), ".raw"), "wb");        //크롭을 해주기 위해 파일을 만들어준다.
    for (int i = y1; i < y2; i++)
        fwrite((uint8_t*)ppInputImageBuffer[i] + x1, sizeof(uint8_t), x2 - x1, fpOutputImage);          //크롭된 이미지를 붙여넣어준다.


    memory_free2D(ppInputImageBuffer);      //모든 동적할당 메모리를 해제해준다.
    fclose(fpInputImage);
    fclose(fpOutputImage);

    cout << "Output images are stored!";
    return 0;
}