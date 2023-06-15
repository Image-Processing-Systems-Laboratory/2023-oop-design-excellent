#include <iostream>
#include <bitset>
using namespace std;

void Sender(char Data[]);
char* Transmission_Channel(const char* coded_frame);
bitset<16> Receiver(const char* received_frame);
bitset<16> calFCS(bitset<12> data, bitset<5> divisor);

int main() {
	bool isErrored = false;
	char FCS[16];
	char* temp;
	bitset<16> FCS_last;
	Sender(FCS);
	//temp는 FCS의 정보를 가지는 char 포인터
	temp = Transmission_Channel(FCS);

	const char* end = temp;
	while (*end) {
		++end;
	}
	size_t str_length = end - temp;

	// 동적 할당한 문자열 배열에 문자열 복사
	// char_array는 Receiver의 FCS 정보를 가지고 있음.
	char* array = new char[str_length + 1];
	char* dest = array;
	while (*temp) {
		*dest++ = *temp++;
	}
	*dest = '\0';

	FCS_last = Receiver(array);
	for (int i = 0; i < 4; i++) {
		if (FCS_last[i] == 1) {
			isErrored = true;
			break;
		}
	}

	// 최종 Output 모두 출력
	cout << "Received frame : ";
	for (int i = 0; i < 16; i++) {
		cout << FCS_last[15 - i];
	}
	cout << endl;

	cout << "Reconstructed data : ";
	for (int i = 0; i < 12; i++) {
		cout << FCS_last[11 - i];
	}
	cout << endl;

	if (isErrored == true) {
		cout << "Receiver has detected error." << endl;
	}
	else {
		cout << "No detected Error." << endl;
	}

	delete[] array;
	return 0;
}

//Get 12-digit binary data
//Calculates frame check sequence (FCS) from a 12 - bit block and appends FCS to the block.

bitset<16> calFCS(bitset<12> data, bitset<5> divisor) {
	// 16bit 사이즈의 
	bitset<16> block(data.to_string() + string("0000"));

	// Perform long division on the block and divisor to calculate the remainder
	for (int i = 0; i < 12; i++) {
		if (block[i]) {
			block ^= divisor.to_ulong() << (11 - i);
		}
	}

	// The remainder is the FCS
	return block;
}

void Sender(char FCS[]) {
	//최초의 입력 데이터 : e.g. 110011001111
	char Data[13];
	cout << "Data : ";
	cin >> Data;

	string data_string = Data;
	bitset<16> FCS_bitset;

	//비트 연산자 사용을 위해서 bitset 형식으로 바꾼다.
	bitset<12> data(data_string);
	bitset<5> divisor = 27; //0b11011;

	FCS_bitset = calFCS(data, divisor);
	for (int i = 0; i < 16; i++) {
		if(FCS_bitset[i] == 1){
			FCS[15 - i] = '1';
		}
		else {
			FCS[15 - i] = '0';
		}
	}
	cout << "Coded frame : ";
	for (int i = 0; i < 16; i++) cout << FCS[i];
	cout << endl;
}

//본 문제를 위해 인위적으로 에러를 만들기 위한 함수
char* Transmission_Channel(const char* coded_frame) {
	//5% 확률로 (rand()이용) 비트를 반전
	const char* end = coded_frame;
	while (*end) {
		++end;
	}
	size_t str_length = end - coded_frame;

	// 동적 할당한 문자열 배열에 문자열 복사
	char* array = new char[str_length + 1];
	char* dest = array;
	while (*coded_frame) {
		*dest++ = *coded_frame++;
	}
	*dest = '\0';

	// 5%의 에러를 발생시키는 것을 srand(time(null))로 구현
	srand(time(NULL));
	for (int i = 0; i < 16; i++) {
		//랜덤으로 발생시킨 임의의 수가 0.05, 즉 5%보다 작거나 같으면 비트를 flip
		if ((float)rand() / RAND_MAX <= 0.05) {
			if(array[i] == '1') array[i] = '0';
			else { array[i] = '1'; }
		}
	}

	//전달을 매개할 변수를 선언
	char frame_return[16];
	for (int i = 0; i < 16; i++) {
		frame_return[i] = array[i];
	}
	// 메모리 해제
	delete[] array;
	return frame_return;
}

//Send와 같은 동작을 취하되, 나머지에 주목
bitset<16> Receiver(const char* received_frame) {
	bitset<16> FCS_bitset;
	for (int i = 0; i < 16; i++) {
		if (received_frame[i] == 1) {
			FCS_bitset[15 - i] = '1';
		}
		else {
			FCS_bitset[15 - i] = '0';
		}
	}

	//Reconstructed data 먼저 출력하고 (T[0] ~ T[11])
	bitset<5> divisor = 27; //0b11011;
	for (int i = 0; i < 12; i++) {
		if (FCS_bitset[i]) {
			FCS_bitset ^= divisor.to_ulong() << (11 - i);
		}
	}
	//판단할 수 있는 bitset을 return
	return FCS_bitset;
}
