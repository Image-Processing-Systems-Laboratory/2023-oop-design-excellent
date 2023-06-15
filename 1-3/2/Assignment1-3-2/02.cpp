#include<iostream>

using namespace std;

void printDecimal(int numerator, int denominator);

int main()
{
	int Vs, R1, R2, RL;

	/* 전압 저항 값들 입력 받기*/
	cout << "Vs: "; cin >> Vs;
	cout << "R1: "; cin >> R1;
	cout << "R2: "; cin >> R2;
	cout << "R(Load): "; cin >> RL;

	int numerator, denominator;
	/* RL이 존재하지 않을 때*/
	if (RL == 0) {
		numerator = Vs * R2; // Vout의 분자
		denominator = R1 + R2; // Vout의 분모
		cout << "Vout: " << numerator << "/" << denominator;
		/* 소수 부분이 존재하면*/
		if (numerator % denominator != 0) {
			cout << " = ";
			printDecimal(numerator, denominator); // 소수 형태로 출력
		}
	}
	/* RL이 존재할 때 */
	else {
		numerator = Vs * R2 * RL; // Vout의 분자
		denominator = R1 * (R2 + RL) + R2 * RL; // Vout의 분모
		cout << "Vout: " << numerator << "/" << denominator;
		/* 소수 부분이 존재하면*/
		if (numerator % denominator != 0) {
			cout << " = ";
			printDecimal(numerator, denominator); // 소수 형태로 출력
		}
		cout << endl;

		double Vout = (double)numerator / denominator;
		/* Load power ratio = PL / Ps를 정리한 것을 출력*/
		cout << fixed;
		cout.precision(2);
		cout << "Load power ratio: " << 100 * Vout * R2 / (Vs * (R2 + RL)) << "%";
	}

	return 0;
}

void printDecimal(int numerator, int denominator)
{
	cout << numerator / denominator << "."; // 정수부분 출력
	numerator %= denominator;
	int remain = numerator; // 정수부분 나눗셈 과정에서 마지막으로 나온 나머지 저장
	
	int decimal[100]; //소수부분 저장
	int len = 0; // 소수부분 길이
	
	/* 나머지에 10곱하고 나눠준 몫이 소수부분*/
	numerator *= 10;
	decimal[0] = numerator / denominator;
	len++;
	numerator %= denominator;
	
	for (int i = 1; numerator != remain; i++) {
		numerator *= 10;
		decimal[i] = numerator / denominator;
		numerator %= denominator;
		len++;
	}

	cout << "(";
	for (int i = 0; i < len; i++) {
		cout << decimal[i];
	}
	cout << ")";
}