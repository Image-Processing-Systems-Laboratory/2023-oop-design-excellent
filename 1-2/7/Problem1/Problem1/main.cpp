#include<iostream>

using namespace std;
//수의 자릿수를 찾는 함수의 선언부
long long int getDigit(long long int);
//수가 이미 출력 되었는지를 확인하는 함수의 선언부
bool isUsed(int);

//메인 함수 시작
int main() {
	//두 입력과 두 입력의 자릿수를 저장할 변수 4개를 선언;
	long long int first, second, firstDigit, secondDigit;
	//입력
	cin >> first >> second;

	//두 수의 자릿수(10^n)를 찾고 맞는 변수에 각각 저장
	firstDigit = getDigit(first);
	secondDigit = getDigit(second);

	//결과 출력
	while (true)
	{
		//계산할 수중 맨 앞 숫자를 담을 변수
		int head;
		//만일 첫 입력이 0이 아닐 시
		if (first != 0) {
			//첫번째 변수를 그 변수의 자릿수로 나누어 가장 앞에 있는 수를 저장
			head = first / firstDigit;
		}
		//만일 첫 입력이 0일 시
		else {
			//두번째 입력이 0일시
			if (secondDigit == 0) {
				//반복문 탈출
				break;
			}
			//두번째 입력이 0이 아닐 시 두번째 변수와 그 변수의 자릿수로 나누어 가장 앞에 있는 수를 저장
			head = second / secondDigit; 
		}
		
		//이미 출력하였을때
		if (isUsed(head)) {
			//만일 첫번째 변수가 0이 아닐 시
			if (first != 0) {
				//첫번째 변수를 그 자릿수로 나눈 나머지값으로 변경
				first = first % firstDigit;
				//자릿수에 10을 나눠줌
				firstDigit = firstDigit / 10;
			}
			//첫번째 변수가 0일 시 위와 마찬가지로 두번째 변수의 자릿수를 하나 낮추고 자릿수 또한 하나 낮춤
			else {
				second = second % secondDigit;
				secondDigit = secondDigit / 10;
			}
			//while문 반복
			continue;
		}
		//두 변수가 0이 아니고 이미 출력이 안되었을 때 수만 우선 출력
		cout << head;

		//임시 변수
		int tmp = 0;
		//첫번째 변수에서 수 head가 얼마나 있는지 확인
		for (long long int i = first, Digit = firstDigit; i > 0; i = i % Digit, Digit = Digit / 10) {
			//head와 i의 맨 앞자리 수가 같을 시
			if (head == i / Digit)
				//변수에 1 덧셈
				tmp++;
		}
		//두번째 변수에서 수 head가 얼마나 있는지 확인
		for (long long int i = second, Digit = secondDigit; i > 0; i = i % Digit, Digit = Digit / 10) {
			//head와 i의 맨 앞자리 수가 같을 시
			if (head == i / Digit)
				//변수에 1 덧셈
				tmp++;
		}

		//첫번째 수가 0이 아닐 시 first를 자릿수로 나눈 나머지를 저장, 자릴수를 하나 낮춤
		if (first != 0) {
			first = first % firstDigit;
			firstDigit = firstDigit / 10;
		}
		//첫번째 수가 0이고, 두번째 수가 0이 아닐 시 first를 자릿수로 나눈 나머지를 저장, 자릴수를 하나 낮춤
		else {
			second = second % secondDigit;
			secondDigit = secondDigit / 10;
		}
		//센 개수를 출력
		cout << tmp;
	}
	//종료
	return 0;
}

//수의 자릿수를 찾는 함수의 정의부
long long int getDigit(long long int x) {
	//미리 1을 저장
	long long int result = 1;
	//10으로 나누어 0이 아닐 시 자릿수를 하나씩 올림, 0이면 반복문 종료
	while ((x = x / 10) != 0) {
		result *= 10;
	}
	//결과 반환
	return result;
}

//수가 이미 출력 되었는지를 확인하는 함수의 정의부
bool isUsed(int x) {
	//전역 변수 정수형 배열을 선언
	static int used[9] = { 0, };
	//만약 전역 변수 used에 값이 있으면 true를 반환
	if (used[x - 1])
		return true;
	//없으면used에 값을 설정하고 false를 반환
	else {
		used[x - 1] = 1;
		return false;
	}
}
