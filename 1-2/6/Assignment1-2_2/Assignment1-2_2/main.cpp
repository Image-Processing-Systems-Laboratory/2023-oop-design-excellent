#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <string.h>

#define P 0b11011 // 나눌 수
#define INPUT_SIZE 12 // 입력받을 비트 수

bool	check_valid_input(const char* input) // 올바른 이진수 입력인지 판단
{
	int i = 0;

	while (input[i])
	{
		if (input[i] != '0' && input[i] != '1') // 0과 1이외의 글자가 있을 경우
			return (false);
		i++;
	}
	if (i != 12) // 12bit입력이 아닌 경우
		return (false);
	return (true);
}

void	invalid_input(void) // 유효하지 않은 입력 에러 처리
{
	std::cerr << "Invalid input!" << std::endl;
	exit(EXIT_FAILURE);
}

int	NumOfDigits(unsigned int data) // 이진수 자릿수 계산
{
	int	digit = 0;

	while (data) // data가 0이 되기 전까지
	{
		digit++; // 자릿수 증가
		data = data >> 1; // 한 자리씩 오른쪽으로 쉬프트
	}
	return (digit); // 자릿수 리턴
}

int	modulo_2(unsigned int data) // xor을 사용한 나머지 연산
{
	// 나머지가 나누는 수의 자릿수보다 적은 자릿수를 가질 때까지
	while (NumOfDigits(data) >= NumOfDigits(P))
	{
		data ^= (P << (NumOfDigits(data) - NumOfDigits(P))); // 맨 앞 자릿수를 맞춘 후 xor 시행
	}
	return (data); // 나머지 리턴
}

char* binary_to_string(unsigned int data, int len) // 2진수를 문자열로 변환
{
	char* ret_str;
	int i;

	ret_str = new char[len + 1]; // 문자열 공간 할당
	ret_str[len] = 0; // 널 문자 삽입
	i = len - 1;
	while (i >= 0) // 2진수를 맨 뒷 자리부터 한 자리씩 계산하여 삽입
	{
		ret_str[i--] = (data % 2) + '0'; // 맨 뒷자리에 '0'을 더해 문자로 만듦
		data = data >> 1; // 오른쪽으로 한 칸 쉬프트(맨 뒷자리 자름)
	}
	return (ret_str); // 결과 반환
}

unsigned int string_to_binary(const char* data) // 문자열을 정수형으로 변환
{
	int i;
	unsigned int ret_n;

	i = 0;
	ret_n = 0;
	while (data[i]) // 문자열 순회
	{
		ret_n = (ret_n << 1); // 지금까지의 수를 왼쪽으로 한 칸 쉬프트
		ret_n += (data[i] - '0'); // 현재 가리키고 있는 문자에 '0'을 빼서 수로 만들고 더함
		i++;
	}
	return (ret_n); // 결과 리턴
}

char* Sender(const char* data) // sender 부분
{
	unsigned int d;
	unsigned int f;

	d = string_to_binary(data); // 문자열을 정수로 변환한다
	d = d << (NumOfDigits(P) - 1); // 모듈로 연산한 값을 저장할 공간을 만든다
	f = modulo_2(d); // d를 P로 나머지 연산한 값을 f에 저장한다. 
	d += f; // 나머지 값을 붙인다
	return (binary_to_string(d, 16)); // 다시 문자열로 변환하여 리턴
}

char* Transmission_Channel(const char* coded_frame) // 문자열의 에러를 시뮬레이트
{
	char* ret_str;
	int len;
	int i;

	srand((unsigned int)time(NULL)); // 랜덤 시드 설정
	std::cout << "Coded frame:" << coded_frame << std::endl; // 받은 문자열 출력
	len = strlen(coded_frame) + 1;
	ret_str = new char[len]; // 새 리턴해줄 문자열 공간 할당
	strcpy(ret_str, coded_frame); // 문자열 복사
	i = 0;
	while (ret_str[i]) // 문자열 순회
	{
		if (rand() % 100 < 5) // 5%의 확률
		{
			ret_str[i] = ret_str[i] == '0' ? '1' : '0'; // 0이면 1로, 1이면 0으로 변경
		}
		i++;
	}
	return (ret_str); // 결과 반환
}

void Receiver(const char* received_frame) // 받은 데이터의 에러 감지
{
	unsigned int data;
	int err;
	char* temp;

	std::cout << "Received frame:" << received_frame << std::endl; // 받은 데이터 출력
	data = string_to_binary(received_frame); // 정수로 변환
	err = modulo_2(data); // 나머지 연산을 통해 에러 검출
	temp = binary_to_string(data >> (NumOfDigits(P) - 1), 12); // 뒤의 네 자리를 자르면 원래 데이터
	std::cout << "Reconstructed data:" << temp << std::endl; // 원래 데이터 출력
	if (err) // 에러가 있는 경우
		std::cout << "Receiver has detected error" << std::endl;
	else // 에러가 없는 경우
		std::cout << "No detected error" << std::endl;
}

int main(void)
{
	char input[20];
	char *coded_frame;
	char *received_frame;

	std::cout << "Data: ";
	std::cin >> input; // 데이터 입력
	if (!std::cin || !check_valid_input(input)) // 입력이 유효하지 않거나 에러 난 경우
		invalid_input();
	coded_frame = Sender(input); // 입력을 sender에 넣음
	received_frame = Transmission_Channel(coded_frame); // sender의 출력을 transmission_channel에 넣음
	Receiver(received_frame);// transmission의 출력을 receiver에 넣음
	delete[] coded_frame; // 할당된 문자열들 해제
	delete[] received_frame;
	return (0);
}