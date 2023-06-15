#include <iostream>
#include <string.h>
using namespace std;

int change_to_ten(char* input, int jinsu); //jinsu(2����,8����,16����) -> 10������ ��ȯ
void ten_to_change(int ten, char* output, int jinsu); //10���� -> jinsu(2����,8����,16����)�� ��ȯ

int main(void)
{
	char num[40], character[40];
	int change[2], integer, i;
	
	//����, ����, ��ȯ ������ �Է� �޴´�
	cout << "Input: ";
	cin >> num;
	
	for (i = 0; i < 2; i++)
	{
		cin >> change[i];
	}

	if (change[1] == 10) //(2����,8����,16����) -> 10������ ��ȯ�ϴ� ���
	{
		//10������ ��ȯ
		integer = change_to_ten(num, change[0]);
		cout << "Output: " << integer;
	}
	else
	{
		//10������ ��ȯ
		integer = change_to_ten(num, change[0]);
		//���ϴ� ������ ��ȯ
		ten_to_change(integer, character, change[1]);
		//��ȯ�� �� ���
		cout << "Output: " << character;
	}

	return 0;
}
//�ٸ� ������ 10������ ��ȯ�ϱ�
int change_to_ten(char* input, int jinsu)
{
	int num = 0, multiply = 1, i;
	int len = (int)strlen(input);

	//input ������ �迭�� ���������� 10������ ��ȯ
	for (i = len - 1; i >= 0; i--)
	{
		if (input[i] >= '0' && input[i] <= '9') //2����, 8����, 16�������� 0~9�� �ش��ϴ� ���� 10������ ��ȯ
		{
			num += (input[i] - '0') * multiply;
		}
		else //16�������� A~F�� �ش��ϴ� ���� 10������ ��ȯ
		{
			num += (input[i] - '7') * multiply;
		}
		multiply *= jinsu;
	}

	return num;
}

//10������ �ٸ� ������ ��ȯ�ϱ�
void ten_to_change(int ten, char* output, int jinsu)
{
	int temp, len, i = 0;

	//10���� ��ȯ �������� ten�� jinsu�� ������ �� ��, �������� 0�� �ƴ� ���� �ݺ�
	while (ten != 0)
	{
		//ten�� jinsu�� �������� �� �߻��ϴ� ������ ���� �迭�� ����ش�
		if ((ten % jinsu) >= 0 && (ten % jinsu) <= 9) //2����, 8����, 16�������� 0~9�� �ش��ϴ� ��
		{
			output[i] = '0' + (ten % jinsu);
		}
		else //16�������� A~F�� �ش��ϴ� ��
		{
			output[i] = '7' + (ten % jinsu);
		}
		//ten�� jinsu�� �������� �� �߻��ϴ� ���� �ٽ� ten�� �����Ѵ�
		ten /= jinsu;

		//��� �迭 �ε����� �������� �ѱ��
		i++;
	}
	//�ι��� �ֱ�
	output[i] = 0;

	//�迭 ���� ���������� �����ϱ�
	len = (int)strlen(output);
	for (i = 0; i < len / 2; i++)
	{
		temp = output[i];
		output[i] = output[len - 1 - i];
		output[len - 1 - i] = temp;
	}
}