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
	//temp�� FCS�� ������ ������ char ������
	temp = Transmission_Channel(FCS);

	const char* end = temp;
	while (*end) {
		++end;
	}
	size_t str_length = end - temp;

	// ���� �Ҵ��� ���ڿ� �迭�� ���ڿ� ����
	// char_array�� Receiver�� FCS ������ ������ ����.
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

	// ���� Output ��� ���
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
	// 16bit �������� 
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
	//������ �Է� ������ : e.g. 110011001111
	char Data[13];
	cout << "Data : ";
	cin >> Data;

	string data_string = Data;
	bitset<16> FCS_bitset;

	//��Ʈ ������ ����� ���ؼ� bitset �������� �ٲ۴�.
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

//�� ������ ���� ���������� ������ ����� ���� �Լ�
char* Transmission_Channel(const char* coded_frame) {
	//5% Ȯ���� (rand()�̿�) ��Ʈ�� ����
	const char* end = coded_frame;
	while (*end) {
		++end;
	}
	size_t str_length = end - coded_frame;

	// ���� �Ҵ��� ���ڿ� �迭�� ���ڿ� ����
	char* array = new char[str_length + 1];
	char* dest = array;
	while (*coded_frame) {
		*dest++ = *coded_frame++;
	}
	*dest = '\0';

	// 5%�� ������ �߻���Ű�� ���� srand(time(null))�� ����
	srand(time(NULL));
	for (int i = 0; i < 16; i++) {
		//�������� �߻���Ų ������ ���� 0.05, �� 5%���� �۰ų� ������ ��Ʈ�� flip
		if ((float)rand() / RAND_MAX <= 0.05) {
			if(array[i] == '1') array[i] = '0';
			else { array[i] = '1'; }
		}
	}

	//������ �Ű��� ������ ����
	char frame_return[16];
	for (int i = 0; i < 16; i++) {
		frame_return[i] = array[i];
	}
	// �޸� ����
	delete[] array;
	return frame_return;
}

//Send�� ���� ������ ���ϵ�, �������� �ָ�
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

	//Reconstructed data ���� ����ϰ� (T[0] ~ T[11])
	bitset<5> divisor = 27; //0b11011;
	for (int i = 0; i < 12; i++) {
		if (FCS_bitset[i]) {
			FCS_bitset ^= divisor.to_ulong() << (11 - i);
		}
	}
	//�Ǵ��� �� �ִ� bitset�� return
	return FCS_bitset;
}
