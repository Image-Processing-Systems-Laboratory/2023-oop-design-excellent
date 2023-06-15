#include <iostream>
#include <string.h>

using namespace std; 

int ConvertToDecimal(char* num, int base) // 10������ ��ȯ���ִ� �Լ�
{
	int decimal = 0;// 10������ ��ȯ�� ��
	int power = 1; // base�� �ŵ������� �����ϴ� ����

	int len = strlen(num); // num�� ���̸� �����ϴ� ����

    for (int i = len - 1; i >= 0; i--) // num�� ���̸�ŭ �ݺ�
    {
		int digit; // num�� �� �ڸ����� �����ϴ� ����
        if (num[i] >= '0' && num[i] <= '9') // num�� �� �ڸ����� 0���� 9�� ���
        {
			digit = num[i] - '0'; // digit�� num�� �� �ڸ����� ���� ( 0 ~ 9 )
        }
        else // num�� ���ڰ� �ƴ� ���
        {
			digit = num[i] - 'A' + 10; // digit�� num�� �� �ڸ����� ���� ( A = 10, B = 11, C = 12, D = 13, E = 14, F = 15 )
        }
		decimal = decimal + (digit * power); // 10������ ��ȯ
		power = power * base; // base�� �ŵ������� ����
    }
	return decimal; // 10������ ��ȯ�� �� ��ȯ
}

int main()
{

	const int MAX_LENGTH = 1000; // num�� �ִ� ����
	char num[MAX_LENGTH]; // num�� �����ϴ� �迭
	int base1, base2; // base1�� base2�� �����ϴ� ����

	cout << "Enter the numbers: "; // ���ڵ��� �Է¹޴� ���� ���
	cin >> num >> base1 >> base2; // num, base1, base2�� �Է¹���

	int decimal = ConvertToDecimal(num, base1); // 10������ ��ȯ�� �� ����
	char result[MAX_LENGTH]; // ��ȯ�� �� �����ϴ� �迭
	int index = 0; // result�� �ε����� �����ϴ� ����
    for (; decimal != 0; index++) // decimal�� 0�� �� ������ �ݺ�
    {
		int remainder = decimal % base2; // base2�� ���� �������� �����ϴ� ����
        if (remainder >= 0 && remainder <= 9) // �������� 0���� 9�� ���
        {
			result[index] = remainder + '0'; // result�� �������� ���� ( 0 ~ 9 )
        }
        else // �������� ������ ���
        {
			result[index] = remainder - 10 + 'A'; // result�� �������� ���� ( A = 10, B = 11, C = 12, D = 13, E = 14, F = 15 )
        }
		decimal = decimal / base2; // decimal�� base2�� ����
    }
	result[index] = '\0'; // result�� �������� NULL ���ڸ� ����

	int len = strlen(result); // result�� ���̸� �����ϴ� ����
    for (int i = 0; i < len / 2; i++) // result�� ���� ���ݸ�ŭ �ݺ�
    {
		char temp = result[i]; // result�� i��° ���� �ӽ÷� �����ϴ� ����
		result[i] = result[len - i - 1]; // result�� i��° ���� result�� len - i - 1��° ���� ��ȯ
		result[len - i - 1] = temp; // result�� len - i - 1��° ���� result�� i��° ���� ��ȯ
    }

	cout << "Result: " << result << endl; // ��ȯ�� �� ���

    return 0;

}
