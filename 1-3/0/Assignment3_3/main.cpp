#include<iostream>
#include<cmath>
using namespace std;

// 동적할당을 통해 입력값을 범위 제한 없이 받을 함수
char* get_num(char* ptr, char n,int len);

//재귀를 이용한10진수를 변환하는 함수
void tenTo(int num, int to_num);

//2진수를 변환하는 함수
void twoTo(char* num, int to_num, int width);

//위의 함수를 이용한 8진수와 16를 변환하는 함수
void eightTo(char* num, int to_num, int width);
void sixTo(char* num, int to_num, int width);
int main(void)
{
	
	char* num = NULL;
	int len = 0;
	char tmp_n = 0;
	//공백을 만날때까지 원하는 값을 받음
	while ((tmp_n = getchar()) != ' ')
	{
		num = get_num(num, tmp_n, ++len);
	}

	int exist_nota = 0;
	int change_nota = 0;
	cin >> exist_nota;
	cin >> change_nota;

	if (exist_nota == 10)
	{
		int num_i = 0;

		for (int i = 0; i < len; i++)
			num_i += (pow(10, len - 1 - i) * (num[i] - '0'));
		tenTo(num_i, change_nota);
	}
	else if (exist_nota == 2)
	{
		twoTo(num, change_nota, len);
	}
	else if (exist_nota == 8)
	{
		eightTo(num, change_nota, len);
	}
	else if (exist_nota == 16)
	{
		sixTo(num, change_nota, len);
	}


	delete[] num;
	return 0;
}

// 동적할당을 통해 입력값을 범위 제한 없이 받음
char* get_num(char* ptr, char n, int len)
{
	//len이 null을 제외한 길이이므로 문자열을 편하게 사용하기 위해 len+1로 동적할당
	char* new_num = new char[len+1];

	//길이를 늘리고 값을 복사한 뒤 원하는 값을 추가함
	for (int i = 0; i < len - 1; i++)
		new_num[i] = ptr[i];
	new_num[len - 1] = n;
	new_num[len] = '\0';

	// 기존에 할당된 문자열을 해제함
	if(ptr!=NULL)
		delete[] ptr;

	//새로 할당한 문자열의 포인터 반환
	return new_num;
}

void tenTo(int num, int to_num)
{
	// 재귀의 탈출 조건으로 아래와 같이 구현함
	if (num / to_num != 0)
		tenTo(num / to_num, to_num);
	//16진수로 표현해야 할 경우 아래와 같은 방식으로 출력
	if (to_num == 16 && num % to_num > 9)
	{
		int tmp = num % to_num;
		char tmp_c = 'A'+(tmp-10);
		cout << tmp_c;
	}
	else
		cout << num % to_num;
	return;
}

void twoTo(char* num,int to_num, int width)	// width == 널제외 실제 문자 길이
{
	
	if (to_num == 10)
	{
		int tmp = 0;
		for (int i = 0; i < width; i++)	// 자리수에 따라서 10진수는 실제 값으로 구함
			tmp += (pow(2, width - i - 1) * (num[i]-'0'));
		cout << tmp;
	}
	else if (to_num == 8)
	{
		int tmp = 0; // 자릿수를 관리할 변수
		while ((width + tmp) % 3 != 0)
			tmp++;

		int digit = 0;
		for (int i = 0; i < width;)
		{
			//3자리씩 끊어서 생각할것이기 때문에 자릿수를 맞추기 위해 아래와 같은 조건문 작성
			if (tmp != 0 && i == 0)
			{
				for (int j = 2 - tmp; j > -1; j--)
					digit += (pow(2, j) * (num[i++] - '0'));
					
				cout << digit;
				digit = 0;	
				continue;
			}

			digit = 0;
			for (int j = 2; j > -1; j--)
				digit += (pow(2,j) * (num[i++] - '0'));
			cout << digit;
		}
	}
	else if (to_num == 16)
	{
		int tmp = 0; // 자릿수를 관리할 변수
		while ((width + tmp) % 4 != 0)
			tmp++;

		int digit = 0;
		for (int i = 0; i < width;)
		{
			//4자리씩 끊어서 생각할것이기 때문에 자릿수를 맞추기 위해 아래와 같은 조건문 작성
			if (tmp != 0 && i == 0)
			{
				for (int j = 3 - tmp; j > -1; j--)
					digit += (pow(2, j) * (num[i++] - '0'));

				// 값이 숫자로 표현되지 않을떄 아래와 같이 처리함
				if (digit > 9)
				{
					char tmp = 'A' + (digit - 10);
					cout << tmp;
				}
				else
				cout << digit;
				digit = 0;
				continue;
			}

			digit = 0;
			for (int j = 3; j > -1; j--)
				digit += (pow(2, j) * (num[i++] - '0'));

			if (digit > 9)
			{
				char tmp = 'A' + (digit - 10);
				cout << tmp;
			}
			else
				cout << digit;
		}
	}

}

void eightTo(char* num, int to_num, int width)
{
	// 먼저 주어진 8 진수를 2진수로 변환하여 저장할 변수를 선언
	
	int num_10 = 0;


	//8진수를 10진수로 변환
	for (int i = 0; i < width; i++)
	{
		num_10 = num_10 + pow(2, 3 * (width - i - 1)) * (num[i]-'0');
	}

	//경우에따라 toTow함수를 이용해 출력
	if (to_num == 10)
		cout << num_10;
	else if (to_num == 2)
		tenTo(num_10, 2);
	else if (to_num == 16)
		tenTo(num_10, 16);

	return;
}
//eightTo함수와 비슷한 방식으로 구현
void sixTo(char* num, int to_num, int width)
{
	// 먼저 주어진 16 진수를 2진수로 변환하여 저장할 변수를 선언
	int num_10 = 0;


	int tmp = 0;
	//16진수를 10진수로 변환
	for (int i = 0; i < width; i++)
	{
		if (num[i] >= 'A')
			tmp = num[i] - 'A' + 10;
		else
			tmp = num[i] - '0';
		num_10 = num_10 + pow(2, 4 * (width - i - 1)) * tmp;
	}

	//경우에따라 toTow함수를 이용해 출력
	if (to_num == 10)
		cout << num_10;
	else if (to_num == 2)
		tenTo(num_10, 2);
	else if (to_num == 8)
		tenTo(num_10, 8);

	return;
}