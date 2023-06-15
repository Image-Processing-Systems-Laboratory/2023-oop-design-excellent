#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

char Data[13], T[17], F[5], Q[13], R[6], P[6] = "11011";        //입력값 : D, T : transmitted, F : T뒤에 붙는 4자리, P:고정된 11011 , Q : 몫, R : 나머지

void Transmission_Channel(void);
void shift(int i);
void sender(void);
void receiver(void);

int main() {
    srand((unsigned int)time(NULL));        //난수 생성용

    cout << "Input: ";
    cin >> Data;
    strcpy(T, Data);            //입력받은 데이터를 T에 넣어준다.
    strcat(T, "0000");          //T에 0을 4개 붙여 16자리를 만든다.

    //sender로 보내기 전 첫 비교를 위해 배열에 5자리를 미리 불러온다.
    for (int i = 0; i < 5; i++) {
        R[i] = T[i];
    }
    sender();
    strcpy(T, Data);           //입력받은 데이터를 T에 넣어준다.
    strcat(T, F);       // Data와 나머지로 나온 값을 붙여준다.
    cout << "Coded frame: " << T << endl;
    
    Transmission_Channel();     //5%확률으로 T의 값을 변환해준다.
    cout << "Received frame: " << T << endl;       //변환된 T를 바꿔준다.

    for (int i = 0; i < 5; i++) {       //T의 앞 5자리를 xor연산을 위해 불러옴
        R[i] = T[i];
    }
    //receiver()로 보내기 전 첫 비교를 위해 배열에 5자리를 미리 불러온다.
    receiver();

    cout << "Reconstructed data: "; //새로 만들어진 데이터를 출력하는 부분
    for (int i = 0; i < 12; i++) 
        cout << T[i];

    if (strcmp(F, "0000")) //error인 경우
        cout << endl << "Receiver has detected error" << endl;  //에러 안내
    else               //error가 아닌 경우
        cout << endl << "NO detected error" << endl;    //에러 찾기 불가 코드
}

void sender(void) {
    for (int i = 0; i < 12; i++) {      //나머지 11자리를 xor연산을 진행한다.
        if (R[0] != '0') {
            Q[i] = '1';             //몫의 첫 글자는 1이 된다.
            R[0] = '0';             //나머지의 첫 글자는 0이 된다.

            for (int j = 1; j < 5; j++) {
                // 각 문자로 저장 받은 숫자를 0 or 1로 xor연산을 진행하고 다시 문자 0 or 1로 저장
                R[j] = (R[j] - '0') ^ (P[j] - '0');
                R[j] += '0';
            }
            shift(i);   //쉬프트
        }
        else {
            Q[i] = '0';     //몫에 0을 전송한다.
            shift(i);    //쉬프트
        }
    }
    strncpy(F, R, 4); // xor연산에서 남은 나머지를 FCS에 할당
}

void receiver(void) {

    for (int i = 0; i < 12; i++) {      //나머지 11자리를 xor연산을 진행한다.
        if (R[0] != '0') {
            Q[i] = '1';             //몫의 첫 글자는 1이 된다.
            R[0] = '0';             //나머지의 첫 글자는 0이 된다.

            for (int j = 1; j < 5; j++) {
                // 각 문자로 저장 받은 숫자를 0 or 1로 xor연산을 진행하고 다시 문자 0 or 1로 저장
                R[j] = (R[j] - '0') ^ (P[j] - '0') + '0';
            }
            shift(i);   //쉬프트
        }

        else {
            Q[i] = '0';
            shift(i);   //쉬프트 연산
        }
    }
    strncpy(F, R, 4); // xor연산에서 남은 나머지를 FCS에 할당
}


void Transmission_Channel(void)     //오차를 발생시키는 함수
{
    int persentage;
    for (int i = 0; i < 16; i++) {
        persentage = rand() % 100;      //0~99 사이 랜덤한 수를 생성한다.
        if (persentage >= 5) //95퍼센트의 확률에 걸린다면
            T[i] = T[i];        //그대로 유지
        else {                  //5퍼센트의 확률에 걸린다면
            if (T[i] == '0')        //0과 1을 교환
                T[i] = '1';
            else
                T[i] = '0';
        }
    }

}

void shift(int i) {
    int num = 0;
    for (int j = 0; j < 5; j++) {
        num = num << 1; // 좌측으로 1비트 이동
        if (R[j] == '1') num |= 1; // 현재 자리가 1이면 맨 오른쪽비트에 1을 추가
    }

    num = num <<= 1; // 좌측으로 1비트 이동
    if (T[i + 5] == '1') num |= 1; // 맨 오른쪽 비트에 T[i+5] 값이 1이면 1을 추가

    // 이진수 문자열로 변환하여 R에 저장
    for (int j = 4; j >= 0; j--) {
        R[j] = (num & 1) + '0'; // 현재 자리의 비트를 문자열로 변환하여 저장
        num = num >>= 1; // 우측으로 1비트씩 이동하여 다음 자리 만들기
    }
}