#include<iostream>

using namespace std;
//���� �ڸ����� ã�� �Լ��� �����
long long int getDigit(long long int);
//���� �̹� ��� �Ǿ������� Ȯ���ϴ� �Լ��� �����
bool isUsed(int);

//���� �Լ� ����
int main() {
	//�� �Է°� �� �Է��� �ڸ����� ������ ���� 4���� ����;
	long long int first, second, firstDigit, secondDigit;
	//�Է�
	cin >> first >> second;

	//�� ���� �ڸ���(10^n)�� ã�� �´� ������ ���� ����
	firstDigit = getDigit(first);
	secondDigit = getDigit(second);

	//��� ���
	while (true)
	{
		//����� ���� �� �� ���ڸ� ���� ����
		int head;
		//���� ù �Է��� 0�� �ƴ� ��
		if (first != 0) {
			//ù��° ������ �� ������ �ڸ����� ������ ���� �տ� �ִ� ���� ����
			head = first / firstDigit;
		}
		//���� ù �Է��� 0�� ��
		else {
			//�ι�° �Է��� 0�Ͻ�
			if (secondDigit == 0) {
				//�ݺ��� Ż��
				break;
			}
			//�ι�° �Է��� 0�� �ƴ� �� �ι�° ������ �� ������ �ڸ����� ������ ���� �տ� �ִ� ���� ����
			head = second / secondDigit; 
		}
		
		//�̹� ����Ͽ�����
		if (isUsed(head)) {
			//���� ù��° ������ 0�� �ƴ� ��
			if (first != 0) {
				//ù��° ������ �� �ڸ����� ���� ������������ ����
				first = first % firstDigit;
				//�ڸ����� 10�� ������
				firstDigit = firstDigit / 10;
			}
			//ù��° ������ 0�� �� ���� ���������� �ι�° ������ �ڸ����� �ϳ� ���߰� �ڸ��� ���� �ϳ� ����
			else {
				second = second % secondDigit;
				secondDigit = secondDigit / 10;
			}
			//while�� �ݺ�
			continue;
		}
		//�� ������ 0�� �ƴϰ� �̹� ����� �ȵǾ��� �� ���� �켱 ���
		cout << head;

		//�ӽ� ����
		int tmp = 0;
		//ù��° �������� �� head�� �󸶳� �ִ��� Ȯ��
		for (long long int i = first, Digit = firstDigit; i > 0; i = i % Digit, Digit = Digit / 10) {
			//head�� i�� �� ���ڸ� ���� ���� ��
			if (head == i / Digit)
				//������ 1 ����
				tmp++;
		}
		//�ι�° �������� �� head�� �󸶳� �ִ��� Ȯ��
		for (long long int i = second, Digit = secondDigit; i > 0; i = i % Digit, Digit = Digit / 10) {
			//head�� i�� �� ���ڸ� ���� ���� ��
			if (head == i / Digit)
				//������ 1 ����
				tmp++;
		}

		//ù��° ���� 0�� �ƴ� �� first�� �ڸ����� ���� �������� ����, �ڸ����� �ϳ� ����
		if (first != 0) {
			first = first % firstDigit;
			firstDigit = firstDigit / 10;
		}
		//ù��° ���� 0�̰�, �ι�° ���� 0�� �ƴ� �� first�� �ڸ����� ���� �������� ����, �ڸ����� �ϳ� ����
		else {
			second = second % secondDigit;
			secondDigit = secondDigit / 10;
		}
		//�� ������ ���
		cout << tmp;
	}
	//����
	return 0;
}

//���� �ڸ����� ã�� �Լ��� ���Ǻ�
long long int getDigit(long long int x) {
	//�̸� 1�� ����
	long long int result = 1;
	//10���� ������ 0�� �ƴ� �� �ڸ����� �ϳ��� �ø�, 0�̸� �ݺ��� ����
	while ((x = x / 10) != 0) {
		result *= 10;
	}
	//��� ��ȯ
	return result;
}

//���� �̹� ��� �Ǿ������� Ȯ���ϴ� �Լ��� ���Ǻ�
bool isUsed(int x) {
	//���� ���� ������ �迭�� ����
	static int used[9] = { 0, };
	//���� ���� ���� used�� ���� ������ true�� ��ȯ
	if (used[x - 1])
		return true;
	//������used�� ���� �����ϰ� false�� ��ȯ
	else {
		used[x - 1] = 1;
		return false;
	}
}
