#include <iostream>
using namespace std;

int start, a, b, d2;
int GCD(int x, int y);
bool CircCheck(int nume, int deno);
int CircLength();

int main() {
	
	double Vs, R1, R2, RL, Vout;
	// 전류 및 저항 값 입력
	cout << "Vs : ";
	cin >> Vs;
	cout << "R1 : ";
	cin >> R1;
	cout << "R2 : ";
	cin >> R2;
	cout << "R(Load) : ";
	cin >> RL;
    int nume, deno;

	// R load가 없는 경우에는 R load가 없는 회로를 기준으로 계산
	if (RL == 0) {
		Vout = Vs / (R1 + R2) * R2;
        cout << "Vout: " << Vs * R2 << "/" << (R1 + R2) << " = ";
        nume = Vs * R2;
        deno = (R1 + R2);
	}
    // R load가 0이 아닐 경우에는 R load가 있는 회로를 기준으로 계산
	else {
		Vout = Vs * (R2 * RL) / (R2 + RL) / (R1 + (R2 * RL) / (R2 + RL));
        cout << "Vout: " << Vs * R2 * RL << '/' << (R1 * (R2 + RL) + R2 * RL) << " = ";
        nume = Vs * (R2 * RL);
        deno = (R2 + RL) * (R1 + (R2 * RL) / (R2 + RL));
	}

    // 최대공약수를 계산하고 계속 나누어 기약분수 만들기

    int div = GCD(nume, deno);
    nume /= div;
    deno /= div;

    if (CircCheck(nume, deno)) {    // 순환 구조가 아닐 경우 Vout 값을 그대로 출력
        cout << Vout << "\n";
    }
    else {    // 순환소수인 경우
        int length = CircLength();    // 순환 부분 길이를 계산
        cout << nume / deno << ".";          // 처음 시작과 순환 전까지 계산하고 출력
        for (int i = 0; i < start; i++) {
            nume = (nume % deno) * 10;
            cout << (char)(nume / deno + '0');
        }
        cout << "(";    // 괄호 열기
        // 반복되는 숫자를 계산하여 출력
        for (int i = 0; i < length; i++) {
            nume = (nume % deno) * 10;
            cout << (char)(nume / deno + '0');
        }
        cout << ")\n";    // 괄호 닫기
    }

    if (RL != 0) { // R load가 0이 아닌 경우 load power ratio 출력
        double IL = (R2 / (R2 + RL)) * Vs * (R2 + RL) / (R1 * (R2 + RL) + R2 * RL);
        cout << fixed; // 소수점 고정
        cout.precision(2); // 둘째자리까지
        cout << "Load power ratio: " << IL * IL * RL / (Vs * Vs * (R2 + RL) / (R1 * (R2 + RL) + R2 * RL)) * 100 << "%";
    }
	return 0;
}

bool CircCheck(int nume, int deno) {    // 순환인지 비순환인지 확인
    if (nume % deno == 0)
        return true;
    int n1 = nume;
    int d1 = deno;
    a = 0, b = 0;
    while (d1 % 2 == 0) { // 기약분수의 분모의 소인수가 2나 5인 경우 : 유한소수
        d1 /= 2;
        a++;
    }
    while (d1 % 5 == 0) {
        d1 /= 5;
        b++;
    }
    d2 = d1;
    if (d2 == 1)
        return true; // 나누어진 경우 비순환
    else
        return false; // 나머지는 순환
}

int GCD(int x, int y) { // 최대공약수를 구하는 재귀함수
    if (y == 0) return x;
    return GCD(y, x % y);
}

int CircLength() {    // 순환 길이 계산
    int n = 1;
    int target = 9;
    // 순환 시작 위치 계산
    if (a > b) {
        start = a;
    }
    else {
        start = b;
    }
    // 몇 개씩 반복되는지 계산 후 반환
    while ((target %= d2) != 0) {
        n++;
        target = target * 10 + 9;
    }
    return n;
}