#include<iostream>

using namespace std;

void printDecimal(int numerator, int denominator);

int main()
{
	int Vs, R1, R2, RL;

	/* ���� ���� ���� �Է� �ޱ�*/
	cout << "Vs: "; cin >> Vs;
	cout << "R1: "; cin >> R1;
	cout << "R2: "; cin >> R2;
	cout << "R(Load): "; cin >> RL;

	int numerator, denominator;
	/* RL�� �������� ���� ��*/
	if (RL == 0) {
		numerator = Vs * R2; // Vout�� ����
		denominator = R1 + R2; // Vout�� �и�
		cout << "Vout: " << numerator << "/" << denominator;
		/* �Ҽ� �κ��� �����ϸ�*/
		if (numerator % denominator != 0) {
			cout << " = ";
			printDecimal(numerator, denominator); // �Ҽ� ���·� ���
		}
	}
	/* RL�� ������ �� */
	else {
		numerator = Vs * R2 * RL; // Vout�� ����
		denominator = R1 * (R2 + RL) + R2 * RL; // Vout�� �и�
		cout << "Vout: " << numerator << "/" << denominator;
		/* �Ҽ� �κ��� �����ϸ�*/
		if (numerator % denominator != 0) {
			cout << " = ";
			printDecimal(numerator, denominator); // �Ҽ� ���·� ���
		}
		cout << endl;

		double Vout = (double)numerator / denominator;
		/* Load power ratio = PL / Ps�� ������ ���� ���*/
		cout << fixed;
		cout.precision(2);
		cout << "Load power ratio: " << 100 * Vout * R2 / (Vs * (R2 + RL)) << "%";
	}

	return 0;
}

void printDecimal(int numerator, int denominator)
{
	cout << numerator / denominator << "."; // �����κ� ���
	numerator %= denominator;
	int remain = numerator; // �����κ� ������ �������� ���������� ���� ������ ����
	
	int decimal[100]; //�Ҽ��κ� ����
	int len = 0; // �Ҽ��κ� ����
	
	/* �������� 10���ϰ� ������ ���� �Ҽ��κ�*/
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