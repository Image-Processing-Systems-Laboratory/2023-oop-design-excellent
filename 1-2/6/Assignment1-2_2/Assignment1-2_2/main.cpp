#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <string.h>

#define P 0b11011 // ���� ��
#define INPUT_SIZE 12 // �Է¹��� ��Ʈ ��

bool	check_valid_input(const char* input) // �ùٸ� ������ �Է����� �Ǵ�
{
	int i = 0;

	while (input[i])
	{
		if (input[i] != '0' && input[i] != '1') // 0�� 1�̿��� ���ڰ� ���� ���
			return (false);
		i++;
	}
	if (i != 12) // 12bit�Է��� �ƴ� ���
		return (false);
	return (true);
}

void	invalid_input(void) // ��ȿ���� ���� �Է� ���� ó��
{
	std::cerr << "Invalid input!" << std::endl;
	exit(EXIT_FAILURE);
}

int	NumOfDigits(unsigned int data) // ������ �ڸ��� ���
{
	int	digit = 0;

	while (data) // data�� 0�� �Ǳ� ������
	{
		digit++; // �ڸ��� ����
		data = data >> 1; // �� �ڸ��� ���������� ����Ʈ
	}
	return (digit); // �ڸ��� ����
}

int	modulo_2(unsigned int data) // xor�� ����� ������ ����
{
	// �������� ������ ���� �ڸ������� ���� �ڸ����� ���� ������
	while (NumOfDigits(data) >= NumOfDigits(P))
	{
		data ^= (P << (NumOfDigits(data) - NumOfDigits(P))); // �� �� �ڸ����� ���� �� xor ����
	}
	return (data); // ������ ����
}

char* binary_to_string(unsigned int data, int len) // 2������ ���ڿ��� ��ȯ
{
	char* ret_str;
	int i;

	ret_str = new char[len + 1]; // ���ڿ� ���� �Ҵ�
	ret_str[len] = 0; // �� ���� ����
	i = len - 1;
	while (i >= 0) // 2������ �� �� �ڸ����� �� �ڸ��� ����Ͽ� ����
	{
		ret_str[i--] = (data % 2) + '0'; // �� ���ڸ��� '0'�� ���� ���ڷ� ����
		data = data >> 1; // ���������� �� ĭ ����Ʈ(�� ���ڸ� �ڸ�)
	}
	return (ret_str); // ��� ��ȯ
}

unsigned int string_to_binary(const char* data) // ���ڿ��� ���������� ��ȯ
{
	int i;
	unsigned int ret_n;

	i = 0;
	ret_n = 0;
	while (data[i]) // ���ڿ� ��ȸ
	{
		ret_n = (ret_n << 1); // ���ݱ����� ���� �������� �� ĭ ����Ʈ
		ret_n += (data[i] - '0'); // ���� ����Ű�� �ִ� ���ڿ� '0'�� ���� ���� ����� ����
		i++;
	}
	return (ret_n); // ��� ����
}

char* Sender(const char* data) // sender �κ�
{
	unsigned int d;
	unsigned int f;

	d = string_to_binary(data); // ���ڿ��� ������ ��ȯ�Ѵ�
	d = d << (NumOfDigits(P) - 1); // ���� ������ ���� ������ ������ �����
	f = modulo_2(d); // d�� P�� ������ ������ ���� f�� �����Ѵ�. 
	d += f; // ������ ���� ���δ�
	return (binary_to_string(d, 16)); // �ٽ� ���ڿ��� ��ȯ�Ͽ� ����
}

char* Transmission_Channel(const char* coded_frame) // ���ڿ��� ������ �ùķ���Ʈ
{
	char* ret_str;
	int len;
	int i;

	srand((unsigned int)time(NULL)); // ���� �õ� ����
	std::cout << "Coded frame:" << coded_frame << std::endl; // ���� ���ڿ� ���
	len = strlen(coded_frame) + 1;
	ret_str = new char[len]; // �� �������� ���ڿ� ���� �Ҵ�
	strcpy(ret_str, coded_frame); // ���ڿ� ����
	i = 0;
	while (ret_str[i]) // ���ڿ� ��ȸ
	{
		if (rand() % 100 < 5) // 5%�� Ȯ��
		{
			ret_str[i] = ret_str[i] == '0' ? '1' : '0'; // 0�̸� 1��, 1�̸� 0���� ����
		}
		i++;
	}
	return (ret_str); // ��� ��ȯ
}

void Receiver(const char* received_frame) // ���� �������� ���� ����
{
	unsigned int data;
	int err;
	char* temp;

	std::cout << "Received frame:" << received_frame << std::endl; // ���� ������ ���
	data = string_to_binary(received_frame); // ������ ��ȯ
	err = modulo_2(data); // ������ ������ ���� ���� ����
	temp = binary_to_string(data >> (NumOfDigits(P) - 1), 12); // ���� �� �ڸ��� �ڸ��� ���� ������
	std::cout << "Reconstructed data:" << temp << std::endl; // ���� ������ ���
	if (err) // ������ �ִ� ���
		std::cout << "Receiver has detected error" << std::endl;
	else // ������ ���� ���
		std::cout << "No detected error" << std::endl;
}

int main(void)
{
	char input[20];
	char *coded_frame;
	char *received_frame;

	std::cout << "Data: ";
	std::cin >> input; // ������ �Է�
	if (!std::cin || !check_valid_input(input)) // �Է��� ��ȿ���� �ʰų� ���� �� ���
		invalid_input();
	coded_frame = Sender(input); // �Է��� sender�� ����
	received_frame = Transmission_Channel(coded_frame); // sender�� ����� transmission_channel�� ����
	Receiver(received_frame);// transmission�� ����� receiver�� ����
	delete[] coded_frame; // �Ҵ�� ���ڿ��� ����
	delete[] received_frame;
	return (0);
}