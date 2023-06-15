#include <iostream>
#include <string.h>
using namespace std;

int change_to_ten(char* input, int jinsu); //jinsu(2진수,8진수,16진수) -> 10진수로 변환
void ten_to_change(int ten, char* output, int jinsu); //10진수 -> jinsu(2진수,8진수,16진수)로 변환

int main(void)
{
	char num[40], character[40];
	int change[2], integer, i;
	
	//숫자, 진수, 변환 진수를 입력 받는다
	cout << "Input: ";
	cin >> num;
	
	for (i = 0; i < 2; i++)
	{
		cin >> change[i];
	}

	if (change[1] == 10) //(2진수,8진수,16진수) -> 10진수로 변환하는 경우
	{
		//10진수로 변환
		integer = change_to_ten(num, change[0]);
		cout << "Output: " << integer;
	}
	else
	{
		//10진수로 변환
		integer = change_to_ten(num, change[0]);
		//원하는 진수로 변환
		ten_to_change(integer, character, change[1]);
		//변환한 값 출력
		cout << "Output: " << character;
	}

	return 0;
}
//다른 진수를 10진수로 변환하기
int change_to_ten(char* input, int jinsu)
{
	int num = 0, multiply = 1, i;
	int len = (int)strlen(input);

	//input 문자형 배열의 끝에서부터 10진수로 변환
	for (i = len - 1; i >= 0; i--)
	{
		if (input[i] >= '0' && input[i] <= '9') //2진수, 8진수, 16진수에서 0~9에 해당하는 값을 10진수로 변환
		{
			num += (input[i] - '0') * multiply;
		}
		else //16진수에서 A~F에 해당하는 값을 10진수로 변환
		{
			num += (input[i] - '7') * multiply;
		}
		multiply *= jinsu;
	}

	return num;
}

//10진수를 다른 진수로 변환하기
void ten_to_change(int ten, char* output, int jinsu)
{
	int temp, len, i = 0;

	//10진법 변환 과정에서 ten과 jinsu를 나누어 줄 때, 나머지가 0이 아닌 동안 반복
	while (ten != 0)
	{
		//ten과 jinsu를 나누었을 때 발생하는 나머지 값을 배열에 담아준다
		if ((ten % jinsu) >= 0 && (ten % jinsu) <= 9) //2진수, 8진수, 16진수에서 0~9에 해당하는 값
		{
			output[i] = '0' + (ten % jinsu);
		}
		else //16진수에서 A~F에 해당하는 값
		{
			output[i] = '7' + (ten % jinsu);
		}
		//ten과 jinsu를 나누었을 때 발생하는 몫을 다시 ten에 대입한다
		ten /= jinsu;

		//출력 배열 인덱스를 다음으로 넘기기
		i++;
	}
	//널문자 넣기
	output[i] = 0;

	//배열 순서 순차적으로 정렬하기
	len = (int)strlen(output);
	for (i = 0; i < len / 2; i++)
	{
		temp = output[i];
		output[i] = output[len - 1 - i];
		output[len - 1 - i] = temp;
	}
}