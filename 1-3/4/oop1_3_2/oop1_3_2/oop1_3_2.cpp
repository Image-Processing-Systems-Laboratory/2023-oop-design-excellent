#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

// 순환소수인지 판별
/*
1. gcd 함수를 이용하여 최대공약수를 구합니다.
2. 분모를 최대공약수로 나눠
3. 나눠진 분모를 소인수 분해한다.
4. 요소가 1이될 때가 2또는 5가 아닌 경우 바로 얘는 순환소수다.
*/

using namespace std;

// 각각 Vs, R1, R2, RL, 분모, 분자, 2의 지수와 5의 지수를 카운트할 변수
float Vs, R1, R2, RL;
int denominator, numerator, cnt1 = 0, cnt2 = 0, INT;
double FLOAT;
char str[400] = { 0 };

int gcd(int a, int b); // 최대공약수 구하는 함수
int fun(int a); // 순환소수인지 판별 (분모를 인자로 가지며 분모를 소인수 분해 했을 경우 2, 5가 아니면 순환소수가 나온다.)

void fun1(double Vout); // 순환소수를 구하고 출력까지 하는 함수


int main() {

	//입력값 받기
	cout << "Input" << endl;
	cout << "Vs: ";
	cin >> Vs;
	cout << "R1: ";
	cin >> R1;
	cout << "R2: ";
	cin >> R2;
	cout << "R(Load): ";
	cin >> RL;

	double Vout;
	double I;


	if (RL != 0) { // RLoad가 있는 경우

		//double value = (R2 * RL) / (R2 + RL);
		//Vout = (Vs * value) / (R1 + value);

		Vout = Vs * R2 * RL / (R1 * (R2 + RL) + R2 * RL); // 왠만하면 정수들의 연산을 한다. 
		I = Vout * (R2 + RL) / (R2 * RL); // Vout = (R2||RL) * I이다 .

		//순환소수인지 판별하기
		int GCD = gcd(Vs * R2 * RL, (R1 * (R2 + RL) + R2 * RL)); // 최대 공약수 구하기

		// 분모와 분자를 최대공약수로 나누어 기약분수로 만든다 
		denominator = (R1 * (R2 + RL) + R2 * RL) / GCD;
		numerator = Vs * R2 * RL / GCD;

		if (fun(denominator)) { // 유한소수인경우

			// 소수 두번째 자리에서 반올림
			Vout *= 100;
			Vout = floor(Vout + 0.5);
			Vout /= 100;

			// 분수를 표현하기 위해 정수들의 연산을 이용하여 표현
			cout << endl << endl << "Ouput" << endl << "Vout: " << Vs * R2 * RL << '/' << (R1 * (R2 + RL) + R2 * RL) << " = " << Vout << endl;

		}

		else { // 순환소수인 경우 (무한소수는 분수로 나타낼 수 없다. 근본적으로 Vout은 분수로 표현할 수 있으니 끝)

			// 분수를 표현하기 위해 정수들의 연산을 이용하여 표현
			cout << endl << endl << "Ouput" << endl << "Vout: " << Vs * R2 * RL << '/' << (R1 * (R2 + RL) + R2 * RL) << " = ";

			fun1(Vout); // 순환소수 연산과 출력

		}

		// 전력 구하기
		double Ps = Vs * I; // total 전력 구하기
		double VL = I * (R2 * RL / (R2 + RL)); // VL = I* (R2||RL)
		double IRL = R2 * I / (R2 + RL); // 병렬 전류 IRL 구하는 공식
		double PL = VL * IRL; // Load의 전력 구하기

		double P_ratio = PL / Ps; // 전력 비율 구하기


		P_ratio *= 100; // %형식

		printf("Load power ratio: %.2f%%\n\n", P_ratio);


	}

	else {	// RLoad가 없는 경우

		I = Vs / (R1 + R2);
		Vout = I * R2; // Vout을 구하는 식

		//순환소수인지 판별하기
		int GCD = gcd(Vs * R2, R1 + R2); // 최대 공약수 구하기

		// 분모와 분자를 최대공약수로 나누어 기약분수로 만든다
		denominator = (R1 + R2) / GCD;
		numerator = (Vs * R2) / GCD;

		if (fun(denominator)) { // 유한소수인경우

			//소수 두번째 자리에서 반올림
			Vout *= 100;
			Vout = floor(Vout + 0.5);
			Vout /= 100;

			// 분수를 표현하기 위해 정수들의 연산을 이용하여 표현
			cout << endl << endl << "Ouput" << endl << "Vout: " << Vs * R2 << '/' << R1 + R2 << " = " << Vout << endl << endl;

		}

		else { // 순환소수인 경우 (무한소수는 분수로 나타낼 수 없다. 근본적으로 Vout은 분수로 표현할 수 있으니 끝)

			cout << endl << endl << "Ouput" << endl << "Vout: " << Vs * R2 << '/' << R1 + R2 << " = ";

			fun1(Vout); // 순환소수 연산과 출력

		}


	}


}

int gcd(int a, int b) // 최대 공약수 구하기
{
	if (b == 0)
		return a;
	else
		gcd(b, a % b);

}

int fun(int a) // 소인수 분해시 2or5가 아닌 다른 수로 나눠 떨어지는지 검사 , 순환마디의 길이는 분모에 의해 결정한다. 
{
	while (1) {

		if (a % 2 == 0) { //2로 나눠지는 경우
			a /= 2;
			cnt1++; //2의 지수를 카운트
		}

		else if (a % 5 == 0) {// 5로 나눠지는 경우
			a /= 5;
			cnt2++; //5의 지수 카운트
		}

		else { // 무한루프 탈출. 더 이상 2나 5로 떨어지지 않을 때
			if (a != 1) // 순환소수임
				return 0;

			else
				return 1; // 유한소수임
		}

	}
}

void fun1(double Vout) {

	// 2^(a) * 5^(b) * a0로 소인수 분해되면 소수 max+1 자리부터 순환마디가 시작된다.
	//이때 max는 2의 지수와 5의 지수중 가장 큰 값이다.
	int max = cnt1;

	if (max < cnt2) //2와 5의 지수중 가장 큰 것이 순환소수의 시작 포인트를 결정한다. 
		max = cnt2;

	INT = (int)Vout; // 정수 부분 따로 저장


	_itoa(numerator, str, 10); // 분자를 문자열에 저장

	int len = strlen(str); // 분자가 어디까지 이어지는가

	for (int i = len; i < 400; i++)
		str[i] = '0'; // 공백란을 '0'으로 채워놓기

	int Q[400] = { 0 }, R = 0; // 몫을 저장할 배열과 나머지

	for (int i = 0; i < 400; i++) { // 긴 나눗셈 방식(손으로 나눗셈 풀때와 비슷한 방식)
		R = R * 10 + (str[i] - '0'); //문자형태의 숫자를 연산하기 위해 '0'을 빼서 연산한다
		Q[i] = R / denominator; // 몫 부분 정수와 소수의 구분이 없음 그래서 정수부분의 자릿수를 구해야 함
		R %= denominator; // 나머지 부분 계속 나눗셈을 해야하므로 다시 저장받아야 함
	}

	for (int i = 0; i < 400; i++)
		str[i] = Q[i] + '0'; // 몫에 있는 숫자를 문자형태로 문자열에 저장


	if (denominator > numerator) { // 분모가 분자보다 큰 경우 필연적으로 몫 부분에 0부터 채워진다
		char ptr1[20] = { 0 };
		_itoa(denominator, ptr1, 10);

		int len1 = strlen(ptr1);

		for (int i = 0; i < 399; i++)
			str[i] = str[i + len1 - 1];

	}

	else { // 몫이 0이 아닌 경우
		int k;
		for (k = 0; k < 20; k++) {
			if (str[k] == '0')
				continue;
			else
				break;
		}

		for (int i = 0; i < 399; i++)
			str[i] = str[i + k]; // 몫이 0이 아닌데 0부터 시작하는 경우 0의 개수를 파악해 앞을 당겨준다

		char ptr[20] = { 0 };
		_itoa(INT, ptr, 10); // 몫의 정수 부분이 어디까지 이어지나 알아야 함.
		len = strlen(ptr); // 정수 부분이 어디까지 이어지는가
		//len--; //  배열은 0부터 시작하므로 정수의 끝 주소는 len -1 이다. 

		for (int i = 0; i < 400 - len; i++) {
			str[i] = str[i + len]; // 간격이 정수의 길이만큼 떨어져 있음
		}

	}
	// 이제 긴 자릿수의 소수점들을 구했으니 순환마디를 구해야 한다. 

	int flag = 1, i; // flag 는 순환 마디의 길이로 추정한다

	for (i = max + 1; i < flag + 1 + max; i++) { // max 부터 시작이니 탐색은 그 다음(max +1)부터로 한다. 
		int cnt = 0; // flag의 길이 2배동안 길이가 맞는지 확인한다
		for (int j = 0; j < flag + 1; j++) { // 순환 마디의 길이로 추정되는 값의 두 배 동안 모든 소수가 맞을 때 flag를 순환마디의 길이로 확정한다. 
			if (str[i + j] == str[i + j + flag])
				cnt++; // 순환 갯수를 추정했을 때 순환 되는 수의 간격은 같으므로 얼마나 같은지 알기 위해 cnt를 확인한다.
			if (cnt == flag + 1) //flag 랑 cnt가 같다면 길이 추정이 맞았다는 뜻
				break;
		}
		if (cnt == flag + 1)
			break;
		else
			flag++;
	}

	// 정수 부분 출력
	cout << INT << '.';

	for (i = 0; i < max; i++)
		cout << str[i]; // 순환되지 않는 소수 출력

	cout << '(';

	for (i = max; i < max + flag; i++) { //순환마디 부분 출력
		cout << str[i];
	}

	cout << ')' << endl;

}