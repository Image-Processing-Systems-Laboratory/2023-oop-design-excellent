#include<iostream>
#include<random>

using namespace std;

//사용자로부터 입력을 받고 나머지를 구하여 CodeFrame을 만든 후 일정 확률로 오류를 발생, Receiver로 전달하는 Sender 함수의 선언부
void Sender();
//Sender로 부터 코드 프레임과 5비트 P를 받고, 이를 통해 나머지를 계산하는 함수의 선언부
short getR(const char*, int);
//Frame을 출력하는 함수의 선언부
void printFrame(const char*);
//coded_frame을 받고 일정 확률로 오류를 발생시키는 함수의 선언부
const char* Transmission_Channel(const char* coded_frame);
//Sender로 부터 일정 확률로 오류를 발생시킨 프레임을 받고, 오류가 났는지 확인, 출력하는 함수의 선언부
void Receiver(const char* received_frame);

//메인 함수 시작
int main() {
	//Sender 호출
	Sender();
	return 0;
}

void Sender() {
	//사용자로부터 받을 입력을 담을 변수
	unsigned long long int input;
	//정해진 P 11011
	const int divisor = 0b11011;

	//coded frame을 만들기 위한 문자열
	char code[2] = { 0, };
	cout << "Data: ";
	//입력 받기
	cin >> input;

	//입력 받은 0, 1로 이루어진 10진수 수를 12비트로 변환
	for (int i = 0, count = 12; i < 2; i++) {
		for (int j = 0; j < 8; j++) {
			//12비트를 모두 저장했으면 반복문 탈출
			if (count == 0) {
				break;
			}
			//만약 지금 확인하는 숫자가 1이면 1을 j만큼 왼쪽으로 이동시킨후 덧셈
			if (input % 10 == 1) {
				code[i] += 1 << j;
			}
			//입력받은 값을 10으로 나누어 마지막 숫자를 없앰
			input /= 10;
			//남은 비트수에 1을 뺌
			count--;
		}
	}

	//모든 비트를 좌로 4만큼 이동시켜 frame을 만듬
	code[1] = (code[1] << 4) + ((unsigned char)code[0] >> 4);
	code[0] = code[0] << 4;
	//만든 frame을 divisor로 나누어 남은 나머지를 or연산을 통해 F로 설정
	code[0] = code[0] ^ getR(code, divisor);
	
	cout << "Coded frame: ";
	//완성된 coded frame을 출력
	printFrame(code);

	//Receiver에 일정한 확률로 오류를 발생시킨 frame을 전달
	Receiver(Transmission_Channel(code));

	return;
}

//일정한 확률로 오류 생성
const char* Transmission_Channel(const char* coded_frame) {

	//랜덤값 생성을 위한 선언, 정의
	random_device rd;
	mt19937 gen(rd());
	//범위를 [0, 19]로 설정
	uniform_int_distribution<> error(0, 19);

	//총 16개의 비트에 대해 일정한 활률로 에러 생성
	for (int i = 0; i < 16; i++) {
		//임의의 숫자를 넣고 이게 0일 시 error를 발생
		if (!error(gen)) {
			//해당 비트에 xor 연산을 통해 해당 비트를 바꿈
			*(short*)coded_frame = *(short*)coded_frame ^ 1 << i;
		}
	}

	//에러가 생겼을 수 있는 frame 반환
	return coded_frame;
}

//Receiver 함수의 정의부
void Receiver(const char* received_frame) {
	//나눌 P 11011
	const int divisor = 0b11011;

	cout << "Received frame: ";
	//Sender로 부터 에러가 발생될 수 있는 frame을 받고 이를 출력
	printFrame(received_frame);

	cout << "Reconstructed data: ";
	//총 16비트의 received_frame을 short로 변환하여 계산
	short code = *(short*)received_frame;
	//만약 i번째 숫자가 1일 시 1을 출력하고 아닐시 0을 출력
	for (int i = 15; i >= 4; i--) {
		if (code & 1 << i)
			cout << 1;
		else
			cout << 0;
	}
	cout << endl;

	//나머지를 구하고 만약 0이 아닐시 에러가 발생되었음을 출력후 함수 종료
	if (getR(received_frame, divisor)) {
		cout << "Receiver has detected error" << endl;
		return;
	}
	//아닐 시 에러가 발생되지 않았음을 출력
	cout << "No detected error" << endl;
}

//나머지를 구하는 함수의 정의부
short getR(const char* frame, int P) {
	//short형으로 변환하여 연산
	short remainder = *(short*)frame;
	//총 12번 만약 높은 비트부터 1인지 확인하고 1이면 divisor와 위치를 맞춘 후 xor 연산
	for (int i = 0; i < 12; i++) {
		//최상위 비트로 부터 i번째가 1일 시
		if (remainder & (1 << 15 - i)) {
			//위치를 맞춘 후P와 xor 연산
			remainder = remainder ^ (P << 11 - i);
		}
	}
	//나머지 반환
	return remainder;
}

//Frame을 출력하는 함수의 정의부
void printFrame(const char* frame) {
	//short형으로 변환하여 연산
	short code = *(short*)frame;
	//총 16개의 비트를 확인후 출력
	for (int i = 15; i >= 0; i--) {
		//최상위 비트부터 1일시 1을 출력, 0일시 0을 출력
		if (code & 1 << i)
			cout << 1;
		else
			cout << 0;
	}
	cout << endl;
	return;
}