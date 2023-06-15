#include <iostream>
#include <string.h>

using namespace std; 

int ConvertToDecimal(char* num, int base) // 10진수로 변환해주는 함수
{
	int decimal = 0;// 10진수로 변환된 값
	int power = 1; // base의 거듭제곱을 저장하는 변수

	int len = strlen(num); // num의 길이를 저장하는 변수

    for (int i = len - 1; i >= 0; i--) // num의 길이만큼 반복
    {
		int digit; // num의 각 자리수를 저장하는 변수
        if (num[i] >= '0' && num[i] <= '9') // num의 각 자리수가 0부터 9일 경우
        {
			digit = num[i] - '0'; // digit에 num의 각 자리수를 저장 ( 0 ~ 9 )
        }
        else // num이 숫자가 아닐 경우
        {
			digit = num[i] - 'A' + 10; // digit에 num의 각 자리수를 저장 ( A = 10, B = 11, C = 12, D = 13, E = 14, F = 15 )
        }
		decimal = decimal + (digit * power); // 10진수로 변환
		power = power * base; // base의 거듭제곱을 구함
    }
	return decimal; // 10진수로 변환된 값 반환
}

int main()
{

	const int MAX_LENGTH = 1000; // num의 최대 길이
	char num[MAX_LENGTH]; // num을 저장하는 배열
	int base1, base2; // base1과 base2를 저장하는 변수

	cout << "Enter the numbers: "; // 숫자들을 입력받는 문구 출력
	cin >> num >> base1 >> base2; // num, base1, base2를 입력받음

	int decimal = ConvertToDecimal(num, base1); // 10진수로 변환된 값 저장
	char result[MAX_LENGTH]; // 변환된 값 저장하는 배열
	int index = 0; // result의 인덱스를 저장하는 변수
    for (; decimal != 0; index++) // decimal이 0이 될 때까지 반복
    {
		int remainder = decimal % base2; // base2로 나눈 나머지를 저장하는 변수
        if (remainder >= 0 && remainder <= 9) // 나머지가 0부터 9일 경우
        {
			result[index] = remainder + '0'; // result에 나머지를 저장 ( 0 ~ 9 )
        }
        else // 나머지가 문자일 경우
        {
			result[index] = remainder - 10 + 'A'; // result에 나머지를 저장 ( A = 10, B = 11, C = 12, D = 13, E = 14, F = 15 )
        }
		decimal = decimal / base2; // decimal을 base2로 나눔
    }
	result[index] = '\0'; // result의 마지막에 NULL 문자를 저장

	int len = strlen(result); // result의 길이를 저장하는 변수
    for (int i = 0; i < len / 2; i++) // result의 길이 절반만큼 반복
    {
		char temp = result[i]; // result의 i번째 값을 임시로 저장하는 변수
		result[i] = result[len - i - 1]; // result의 i번째 값과 result의 len - i - 1번째 값을 교환
		result[len - i - 1] = temp; // result의 len - i - 1번째 값과 result의 i번째 값을 교환
    }

	cout << "Result: " << result << endl; // 변환된 값 출력

    return 0;

}
