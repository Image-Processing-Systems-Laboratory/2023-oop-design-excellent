#include <iostream> // 헤더파일 선언
#include <cmath> // 헤더파일 선언 => pow함수만을 사용하기 위해 사용
#include <cstdlib> // 헤더파일 선언 => rand함수만을 사용하기 위해 사용
#include <ctime> // 헤더파일 선언
using namespace std; // 표준 라이브러리 사용

/* cin같은 함수들의 앞에 정의된 클래스가 없으면
C++ 표준 라이브러리 함수로 받아들이겠다는 뜻*/


void Receiver(const char* received_frame, long long P) {// 반환형이 없고 const char*형과 long long 형을 매개변수로 받는 Receiver 함수 
    cout << "Received frame: "; // Received frame: 출력
    for (int i = 0; i < 16; i++) { // for문을 이용하여 Received frame의 요소를 출력하는 과정
        cout << received_frame[i];
    }
    cout << endl; // 줄바꿈

    long long num1 = 0; // int형 변수 num1 선언 이는 2진수를 10진수로 표현하기 위해 사용
    int arr[16] = { 0, }; // int형 1차원배열 arr선언 received_frame를 요소대로 나누어 정수형으로 저장하기 위해 선언
    for (int i = 0; i < 16; i++) { // 이것이 포인터 received_frame를 1차원배열 arr에 정수형으로 저장하는 과정이다
        if (received_frame[i] == '1') {
            arr[i] = 1;
        }
        else {
            arr[i] = 0;
        }
    }

    for (int i = 0; i < 16; i++) { // 배열 arr에 저장되어있는 요소들을 10진수로 변환하는 과정 
        num1 += (arr[i] * pow(2, 15 - i));
    }
    int R = 0; // int 형 변수 R 나머지 저장하기 위해 선언
    int i = 0; // int형 변수 i는 다음 XOR연산할 때 시프트를 몇번 해줄지 결정함
    int j = 0; // int형 변수 j는 지금까지 총 시프트한 개수를 세어주기 위해 사용
    char frame[16];// char형 1차원배열 frame 선언 이는 Reconstructed data를 출력하기 위해 사용 
    R = ((num1 >> 11) ^ P); // num1를 오른쪽으로 11번 시프트하여 P와 XOR 연산결과를 R에 저장

    while (1) { // 반복문 선언
        int imag1 = 0; // int형 변수 imag1는 바로 아래의 조건문에서 R의 값을 변경하지 않기 위해 사용
        imag1 = R;
        i = 0; // i 0으로 초기화
        if (R != 0) {
            while (1) { // 반복문 선언 => R에서 맨앞의 1이 뒤에서 몇번째 자리에 있는지 세어줌
                imag1 /= 2;
                i++;
                if (imag1 == 0) {
                    break; // 반복문 탈출
                }
            }
            i = 5 - i; // 이제 변수 i는 시프트 몇번 해줄지 결정함
        }
        else { // 만약 아직 XOR 연산해야할 과정이 남아있는데 R이 0이라면 시프트 5번 
            i = 5;
        }

        if (i > 11 - j) { // 시프트해야되는 횟수가 남아있는 요소의 수 보다 많을 때 예외처리 
            R = R << (11 - j); // R을 11-j만큼 시프트하고
            for (int k = 1; k <= 11 - j; k++) { // 남아있는 요소를 10진수로 변환해 덧셈
                R += (arr[4 + j + k] * pow(2, i - k));
            }
            for (int m = 0; m < 15; m++) { // num1을 쪼개어 1차원 배열 frame에 요소를 문자형으로 넣어주는 과정
                int num;
                num = num1 % 2;
                num1 /= 2;
                if (num1 == 1) {
                    frame[0] = '1';
                }
                if (num == 1) {
                    frame[15 - m] = '1';
                }
                else {
                    frame[15 - m] = '0';
                }
            }
            cout << "Reconstructed data: ";
            for (int n = 0; n < 12; n++) {
                cout << frame[n];
            }
            cout << endl;
            // Reconstructed data 출력
            if (R == 0) {
                cout << "No detected error";
            }
            else {
                cout << "Receiver has detected error";
            }
            // error 발생 유무 출력
            break; // 반복문 탈출!
        }

        R = (R << i); // R을 i만큼 왼쪽으로 시프트
        for (int k = 1; k <= i; k++) {
            R += (arr[4 + j + k] * pow(2, i - k)); // 시프트한 횟수만큼 다음의 요소를 채워줌
        }
        j += i; // 총 시프트한 횟수 연산 과정
        R = R ^ P; // XOR연산
        if (4 + j >= 15) { // 만약 더 연산할 요소가 남아있지 않은경우 XOR연산을 마무리한다
            for (int i = 0; i < 15; i++) {// num1을 쪼개어 1차원 배열 frame에 요소를 문자형으로 넣어주는 과정
                int num;
                num = num1 % 2;
                num1 /= 2;
                if (num1 == 1) {
                    frame[0] = '1';
                }
                if (num == 1) {
                    frame[15 - i] = '1';
                }
                else {
                    frame[15 - i] = '0';
                }
            }
            cout << "Reconstructed data: ";
            for (int n = 0; n < 12; n++) {
                cout << frame[n];
            }
            cout << endl;
            // Reconstructed data 출력
            if (R == 0) {
                cout << "No detected error";
            }
            else {
                cout << "Receiver has detected error";
            }
            // error 발생 유무 출력
            break;// 반복문 탈출!
        }
    }
}
void Transmission_Channel(const char* coded_frame, long long P) {// 반환형이 없고 const char*형과 long long 형을 매개변수로 받는 Transmission_Channel 함수
    cout << "Coded frame: ";
    char frame[16];
    for (int i = 0; i < 16; i++) {  // for문을 이용하여, Coded_frame 출력 과정
        cout << coded_frame[i];
        frame[i] = coded_frame[i];
    }
    cout << endl;

    srand((unsigned)time(NULL)); // seed값을 현재의 시간으로 넣어줌

    for (int i = 0; i < 16; i++) { // rand 함수를 이용하여 0~99중 무작위 수를 a에 저장하고 a가 0~4면 숫자를 1이면 0으로, 0이면 1로 바꿔줌. 따라서 각 요소의 값이 변경될 확률은 5%이다.
        int a = rand() % 99;
        if (a >= 0 && a <= 4) {
            if (frame[i] == '1') {
                frame[i] = '0';
            }
            else {
                frame[i] = '1';
            }
        }
    }
    Receiver(frame, P); // Receiver함수 호출 frame과 P를 넘겨줌
}
void Sender(long long D, long long P) {// 반환형이 없고 long long형과 long long 형을 매개변수로 받는 Sender 함수
    int arr[16] = { 0, }; // int형 1차원배열 arr선언 이는 받은 Data를 요소대로 나누어 저장하기 위해 선언
    long long num1 = 0; // int형 변수 num1 선언 이는 2진수를 10진수로 표현하기 위해 사용
    char frame[16]; // char형 1차원배열 frame 선언 이는 Transmission_Channel함수에서 매개변수로 받을 것을 넘겨줄 때 char형으로 넘겨주기 위해 사용 

    for (int i = 0; i < 12; i++) { // D를 각 요소대로 배열에 저장하기 위한 반복문 
        long long  num = D; // long long형 변수 num 선언
        num = D / pow(10, 11 - i);

        if (num >= 10) { // num이 10보다 크면 요소에 1과 0이 아닌 다른 숫자가 저장된다 따라서 10으로 나눴을 때 나머지를 넣어준다.
            num %= 10;
            arr[i] = num;
        }
        else {
            arr[i] = num;
        }
    }
    for (int i = 0; i < 12; i++) { // 배열 arr에 저장되어있는 요소들을 10진수로 변환하는 과정 
        num1 += (arr[i] * pow(2, 11 - i));
    }
    // num1 = D를 10진수로 표현한 것
    long long T = num1 << 4; //12bit frame에서 16bit frame(T)으로 바꿔줌, long long형 변수 T
    long long R = 0; // long long 형 변수 R 이는 나머지 값을 저장하기 위한 변수
    int i = 0; // int형 변수 i는 다음 XOR연산할 때 시프트를 몇번 해줄지 결정함
    int j = 0; // int형 변수 j는 지금까지 총 시프트한 개수를 세어주기 위해 사용

    R = (T >> 11) ^ P; // T를 오른쪽으로 11번 시프트하여 P와 XOR 연산결과를 R에 저장

    while (1) { // 반복문 선언
        int imag1 = 0; // int형 변수 imag1는 바로 아래의 조건문에서 R의 값을 변경하지 않기 위해 사용
        imag1 = R;
        i = 0; // i 0으로 초기화
        if (R != 0) {
            while (1) { // 반복문 선언 => R에서 맨앞의 1이 뒤에서 몇번째 자리에 있는지 세어줌
                imag1 /= 2;
                i++;
                if (imag1 == 0) {
                    break; // 반복문 탈출
                }
            }
            i = 5 - i; // 이제 변수 i는 시프트 몇번 해줄지 결정함
        }
        else { // 만약 아직 XOR 연산해야할 과정이 남아있는데 R이 0이라면 시프트 5번 
            i = 5;
        }
        long long FCS = 0;
        if (i > 11 - j) { // 시프트해야되는 횟수가 남아있는 요소의 수 보다 많을 때 예외처리 
            R = R << (11 - j); // R을 11-j만큼 시프트하고
            for (int k = 1; k <= 11 - j; k++) { // 남아있는 요소를 10진수로 변환해 덧셈
                R += (arr[4 + j + k] * pow(2, i - k));
            }
            FCS = R;
            num1 = ((num1 << 4) + FCS); // num1을 왼쪽으로 4번 시프트하고 R을 더해주는 과정 이때 이는 Coded frame의 2진수를 10진수로 변환한 결과이다.
            for (int m = 0; m < 15; m++) { // num1을 쪼개어 1차원 배열 frame에 요소를 문자형으로 넣어주는 과정
                int num;
                num = num1 % 2;
                num1 /= 2;
                if (num1 == 1) {
                    frame[0] = '1';
                }
                if (num == 1) {
                    frame[15-m] = '1';
                }
                else {
                    frame[15-m] = '0';
                }
            }
            Transmission_Channel(frame,P); // Transmission_Channel 함수 호출하고 frame과 P를 넘겨준다
            break; // 반복문 탈출!
        }

        R = (R << i); // R을 i만큼 왼쪽으로 시프트
        for (int k = 1; k <= i; k++) {
            R += (arr[4 + j + k] * pow(2, i - k)); // 시프트한 횟수만큼 다음의 요소를 채워줌
        }
        j += i; // 총 시프트한 횟수 연산 과정
        R = R ^ P; // XOR연산
        if (4 + j >= 15) { // 만약 더 연산할 요소가 남아있지 않은경우 XOR연산을 마무리한다
            FCS = R;
            num1 = ((num1 << 4) + FCS);// num1을 왼쪽으로 4번 시프트하고 R을 더해주는 과정 이때 이는 Coded frame의 2진수를 10진수로 변환한 결과이다
            for (int i = 0; i < 15; i++) {// num1을 쪼개어 1차원 배열 frame에 요소를 문자형으로 넣어주는 과정
                int num;
                num = num1 % 2;
                num1 /= 2;
                if (num1 == 1) {
                    frame[0] = '1';
                }
                if (num==1) {
                    frame[15-i] = '1';
                }
                else {
                    frame[15-i] = '0';
                }
            }
            Transmission_Channel(frame,P);// Transmission_Channel 함수 호출하고 frame과 P를 넘겨준다
            break;// 반복문 탈출!
        }
    }

}


int main() { // main 함수 선언
    long long input1; // long long 형 input 1 선언 이는 Data를 받기 위해 선언
    long long input2 = 0b11011; // input 2 선언 이는 P를 의미한다.

    cout << "Data: ";
    cin >> input1; // Data 입력
    Sender(input1, input2);  // Sender 함수 호출, input1과 input2를 넘김.

    return 0; // 0의 반환
}