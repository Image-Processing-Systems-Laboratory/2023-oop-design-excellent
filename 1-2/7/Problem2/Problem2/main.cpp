#include<iostream>
#include<random>

using namespace std;

//����ڷκ��� �Է��� �ް� �������� ���Ͽ� CodeFrame�� ���� �� ���� Ȯ���� ������ �߻�, Receiver�� �����ϴ� Sender �Լ��� �����
void Sender();
//Sender�� ���� �ڵ� �����Ӱ� 5��Ʈ P�� �ް�, �̸� ���� �������� ����ϴ� �Լ��� �����
short getR(const char*, int);
//Frame�� ����ϴ� �Լ��� �����
void printFrame(const char*);
//coded_frame�� �ް� ���� Ȯ���� ������ �߻���Ű�� �Լ��� �����
const char* Transmission_Channel(const char* coded_frame);
//Sender�� ���� ���� Ȯ���� ������ �߻���Ų �������� �ް�, ������ ������ Ȯ��, ����ϴ� �Լ��� �����
void Receiver(const char* received_frame);

//���� �Լ� ����
int main() {
	//Sender ȣ��
	Sender();
	return 0;
}

void Sender() {
	//����ڷκ��� ���� �Է��� ���� ����
	unsigned long long int input;
	//������ P 11011
	const int divisor = 0b11011;

	//coded frame�� ����� ���� ���ڿ�
	char code[2] = { 0, };
	cout << "Data: ";
	//�Է� �ޱ�
	cin >> input;

	//�Է� ���� 0, 1�� �̷���� 10���� ���� 12��Ʈ�� ��ȯ
	for (int i = 0, count = 12; i < 2; i++) {
		for (int j = 0; j < 8; j++) {
			//12��Ʈ�� ��� ���������� �ݺ��� Ż��
			if (count == 0) {
				break;
			}
			//���� ���� Ȯ���ϴ� ���ڰ� 1�̸� 1�� j��ŭ �������� �̵���Ų�� ����
			if (input % 10 == 1) {
				code[i] += 1 << j;
			}
			//�Է¹��� ���� 10���� ������ ������ ���ڸ� ����
			input /= 10;
			//���� ��Ʈ���� 1�� ��
			count--;
		}
	}

	//��� ��Ʈ�� �·� 4��ŭ �̵����� frame�� ����
	code[1] = (code[1] << 4) + ((unsigned char)code[0] >> 4);
	code[0] = code[0] << 4;
	//���� frame�� divisor�� ������ ���� �������� or������ ���� F�� ����
	code[0] = code[0] ^ getR(code, divisor);
	
	cout << "Coded frame: ";
	//�ϼ��� coded frame�� ���
	printFrame(code);

	//Receiver�� ������ Ȯ���� ������ �߻���Ų frame�� ����
	Receiver(Transmission_Channel(code));

	return;
}

//������ Ȯ���� ���� ����
const char* Transmission_Channel(const char* coded_frame) {

	//������ ������ ���� ����, ����
	random_device rd;
	mt19937 gen(rd());
	//������ [0, 19]�� ����
	uniform_int_distribution<> error(0, 19);

	//�� 16���� ��Ʈ�� ���� ������ Ȱ���� ���� ����
	for (int i = 0; i < 16; i++) {
		//������ ���ڸ� �ְ� �̰� 0�� �� error�� �߻�
		if (!error(gen)) {
			//�ش� ��Ʈ�� xor ������ ���� �ش� ��Ʈ�� �ٲ�
			*(short*)coded_frame = *(short*)coded_frame ^ 1 << i;
		}
	}

	//������ ������ �� �ִ� frame ��ȯ
	return coded_frame;
}

//Receiver �Լ��� ���Ǻ�
void Receiver(const char* received_frame) {
	//���� P 11011
	const int divisor = 0b11011;

	cout << "Received frame: ";
	//Sender�� ���� ������ �߻��� �� �ִ� frame�� �ް� �̸� ���
	printFrame(received_frame);

	cout << "Reconstructed data: ";
	//�� 16��Ʈ�� received_frame�� short�� ��ȯ�Ͽ� ���
	short code = *(short*)received_frame;
	//���� i��° ���ڰ� 1�� �� 1�� ����ϰ� �ƴҽ� 0�� ���
	for (int i = 15; i >= 4; i--) {
		if (code & 1 << i)
			cout << 1;
		else
			cout << 0;
	}
	cout << endl;

	//�������� ���ϰ� ���� 0�� �ƴҽ� ������ �߻��Ǿ����� ����� �Լ� ����
	if (getR(received_frame, divisor)) {
		cout << "Receiver has detected error" << endl;
		return;
	}
	//�ƴ� �� ������ �߻����� �ʾ����� ���
	cout << "No detected error" << endl;
}

//�������� ���ϴ� �Լ��� ���Ǻ�
short getR(const char* frame, int P) {
	//short������ ��ȯ�Ͽ� ����
	short remainder = *(short*)frame;
	//�� 12�� ���� ���� ��Ʈ���� 1���� Ȯ���ϰ� 1�̸� divisor�� ��ġ�� ���� �� xor ����
	for (int i = 0; i < 12; i++) {
		//�ֻ��� ��Ʈ�� ���� i��°�� 1�� ��
		if (remainder & (1 << 15 - i)) {
			//��ġ�� ���� ��P�� xor ����
			remainder = remainder ^ (P << 11 - i);
		}
	}
	//������ ��ȯ
	return remainder;
}

//Frame�� ����ϴ� �Լ��� ���Ǻ�
void printFrame(const char* frame) {
	//short������ ��ȯ�Ͽ� ����
	short code = *(short*)frame;
	//�� 16���� ��Ʈ�� Ȯ���� ���
	for (int i = 15; i >= 0; i--) {
		//�ֻ��� ��Ʈ���� 1�Ͻ� 1�� ���, 0�Ͻ� 0�� ���
		if (code & 1 << i)
			cout << 1;
		else
			cout << 0;
	}
	cout << endl;
	return;
}