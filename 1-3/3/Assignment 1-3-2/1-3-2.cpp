#include <iostream>
using namespace std;

int start, a, b, d2;
int GCD(int x, int y);
bool CircCheck(int nume, int deno);
int CircLength();

int main() {
	
	double Vs, R1, R2, RL, Vout;
	// ���� �� ���� �� �Է�
	cout << "Vs : ";
	cin >> Vs;
	cout << "R1 : ";
	cin >> R1;
	cout << "R2 : ";
	cin >> R2;
	cout << "R(Load) : ";
	cin >> RL;
    int nume, deno;

	// R load�� ���� ��쿡�� R load�� ���� ȸ�θ� �������� ���
	if (RL == 0) {
		Vout = Vs / (R1 + R2) * R2;
        cout << "Vout: " << Vs * R2 << "/" << (R1 + R2) << " = ";
        nume = Vs * R2;
        deno = (R1 + R2);
	}
    // R load�� 0�� �ƴ� ��쿡�� R load�� �ִ� ȸ�θ� �������� ���
	else {
		Vout = Vs * (R2 * RL) / (R2 + RL) / (R1 + (R2 * RL) / (R2 + RL));
        cout << "Vout: " << Vs * R2 * RL << '/' << (R1 * (R2 + RL) + R2 * RL) << " = ";
        nume = Vs * (R2 * RL);
        deno = (R2 + RL) * (R1 + (R2 * RL) / (R2 + RL));
	}

    // �ִ������� ����ϰ� ��� ������ ���м� �����

    int div = GCD(nume, deno);
    nume /= div;
    deno /= div;

    if (CircCheck(nume, deno)) {    // ��ȯ ������ �ƴ� ��� Vout ���� �״�� ���
        cout << Vout << "\n";
    }
    else {    // ��ȯ�Ҽ��� ���
        int length = CircLength();    // ��ȯ �κ� ���̸� ���
        cout << nume / deno << ".";          // ó�� ���۰� ��ȯ ������ ����ϰ� ���
        for (int i = 0; i < start; i++) {
            nume = (nume % deno) * 10;
            cout << (char)(nume / deno + '0');
        }
        cout << "(";    // ��ȣ ����
        // �ݺ��Ǵ� ���ڸ� ����Ͽ� ���
        for (int i = 0; i < length; i++) {
            nume = (nume % deno) * 10;
            cout << (char)(nume / deno + '0');
        }
        cout << ")\n";    // ��ȣ �ݱ�
    }

    if (RL != 0) { // R load�� 0�� �ƴ� ��� load power ratio ���
        double IL = (R2 / (R2 + RL)) * Vs * (R2 + RL) / (R1 * (R2 + RL) + R2 * RL);
        cout << fixed; // �Ҽ��� ����
        cout.precision(2); // ��°�ڸ�����
        cout << "Load power ratio: " << IL * IL * RL / (Vs * Vs * (R2 + RL) / (R1 * (R2 + RL) + R2 * RL)) * 100 << "%";
    }
	return 0;
}

bool CircCheck(int nume, int deno) {    // ��ȯ���� ���ȯ���� Ȯ��
    if (nume % deno == 0)
        return true;
    int n1 = nume;
    int d1 = deno;
    a = 0, b = 0;
    while (d1 % 2 == 0) { // ���м��� �и��� ���μ��� 2�� 5�� ��� : ���ѼҼ�
        d1 /= 2;
        a++;
    }
    while (d1 % 5 == 0) {
        d1 /= 5;
        b++;
    }
    d2 = d1;
    if (d2 == 1)
        return true; // �������� ��� ���ȯ
    else
        return false; // �������� ��ȯ
}

int GCD(int x, int y) { // �ִ������� ���ϴ� ����Լ�
    if (y == 0) return x;
    return GCD(y, x % y);
}

int CircLength() {    // ��ȯ ���� ���
    int n = 1;
    int target = 9;
    // ��ȯ ���� ��ġ ���
    if (a > b) {
        start = a;
    }
    else {
        start = b;
    }
    // �� ���� �ݺ��Ǵ��� ��� �� ��ȯ
    while ((target %= d2) != 0) {
        n++;
        target = target * 10 + 9;
    }
    return n;
}