#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

char* upper(char* str);

int main() {

	char str[1000] = { 0 }; // 첫번째 입력값은 문자로 
	int b, c; // 두번째와 세번째 입력값

	int number = 0; // 모든 형태의 수를 십진수로 저장하고 다시 십진수에서 변환

	cout << "Input: ";
	cin >> str >> b >> c;
	int len = strlen(str);

	if (b != 16) { //2, 8, 10 진수인 경우
		for (int i = 0; i < len; i++) {
			number += (str[i] - '0') * pow(b, len - i - 1);
		}
	}

	else if (b == 16) {
		for (int i = 0; i < len; i++) {
			if (str[i] <= '9') // 9 이하일 경우
				number += (str[i] - '0') * pow(b, len - i - 1);
			else if('A'<= str[i] && str[i] <= 'F')// 10이상인 경우 즉 A,B,C ,... 등일 경우
				number += (str[i] - 'A' + 10) * pow(b, len - i - 1);
			else
				number += (str[i] - 'a' + 10) * pow(b, len - i - 1);
		}
	}

	else // 두 번째로 입력받는 수가 2, 8, 10, 16 이 아닌 경우 종료
		return 0;

	char p[1000] = { 0 };

	cout << "Output: ";

	{

		int remain = 0, dev = c, i=0;

		if (c == 2 || c == 8) {

			while (1) {

				p[i++] = number % c + '0';
				number /= c;

				if (number == 0)
					break;

			}

			int len = strlen(p);

			for (i = len - 1; i >= 0; i--) // 거꾸로 저장되어있으니 역순으로 출력
				cout << p[i];

		}

		else if (c == 10) {
			cout << number;
		}

		else if (c == 16) {
			while (1) {

				if (number % c <= 9) { // 16 진수에서 9이하로 표시 된는 것
					p[i++] = number % c + '0';
					number /= c;
				}

				else { // A, B, C... 으로 표시 된는 것들
					p[i++] = (number % c) - 10 + 'A' ; // A부터는 number%c의 값이 10이상이다
					number /= c;
				}

				if (number == 0) 
					break;

			}

			int len = strlen(p);

			for (i = len - 1; i >= 0; i--) // 거꾸로 저장되어있으니 역순으로 출력
				cout << p[i];
		}
	}

	//_itoa(number, p, c); // 10진수 형태의 저장 받은 수를 문자형태로 저장

	//upper(p); // itoa를 16진수로 표현한 경우 소문자가 나와서 소문자를 대문자로 고쳐주는 함수

	//cout << "Output: " << p << endl;

}

// 처음엔 itoa 써서 구현했는데 친구들이 말려서 결국 다른 결로 구현함. 아까워서 주석처리
//char* upper(char* str)
//{
//	int len = strlen(str);
//
//	for (int i = 0; i < len; i++) {
//
//		if (!(str[i] >= 'a' && str[i] <= 'z')) // 16진수식 표현이 아닌 경우
//			continue;
//
//		else	// 16진수식 표현이 필요한 경우
//			str[i] -= 'a' - 'A'; // 소문자와 대문자 사이의 간격은 아스키 코드로 a-A의 간격과 같다. (숫자로는 32)
//
//	}
//
//	return str;
//
//}


