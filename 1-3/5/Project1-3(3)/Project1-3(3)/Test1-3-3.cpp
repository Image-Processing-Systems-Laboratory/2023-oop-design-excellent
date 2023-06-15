#include <iostream>
#include <cmath>

using namespace std;

void convertBOH(int ber, int base)  //10������ 2����, 8����, 16������ ��ȯ���ִ� �Լ�
{
	char hexa[17] = "0123456789ABCDEF";  //2����, 8����, 16������ ��ȯ��ų�� �������� ���� ����Ͽ� �����ϱ� ���� 16���� ����
	char out[20] = { 0 };          //����� ������ �迭

	int i;

	for (i = 0; ber != 0; i++)   //10������ 2����, 8����, 16������ ��ȯ��Ű�� ������ ���ؼ� �� ��ȯ�� ������ ������ �������� �迭�� ������
	{
		out[i] = hexa[ber % base];  //�������� ������� �����
		ber /= base;
	}

	for (int a = i - 1; a >= 0; a--)  //�������� ������� ����Ǿ������Ƿ� �̸� �������� ����Ͽ� ǥ����
	{
		cout << out[a];       
	}
}

int main()
{
	char arr[15];  //arr�� �Է��� ��

	int  b, c;   //a�� �Է��� ��, b�� �Է��� ���� Ÿ��, c�� ��ȯ�� ���� �����̴�.

	cin >> arr >> b >> c;

	int i = 0;
	int num = 0;

	switch (b)        //������ �Է¹��� ���� ������ ���� 10������ ��ȯ����
	{
	case 2:
		while (arr[i] != '\0')   //�迭�� ũ�⸦ �����
		{
			i++;
		}

		for (int a = 0; a < i; a++)  //10������ 2������ ��ȯ�ϴ� ����
		{
			num += ((int)arr[a] - '0') * pow(b, (i - a - 1));

		}
		break;

	case 8:
		while (arr[i] != '\0')
		{
			i++;
		}

		for (int a = 0; a < i; a++)
		{
			num += ((int)arr[a] - '0') * pow(b, (i - a - 1));

		}
		break;

	case 10:
		while (arr[i] != '\0')
		{
			i++;
		}

		for (int a = 0; a < i; a++)
		{
			
			num += ((int)arr[a] - '0') * pow(b, (i - a - 1));
		}
		break;

	case 16:
		while (arr[i] != '\0')
		{
			i++;
		}

		for (int a = 0; a < i; a++)
		{
			if(arr[a] >= 'A' && arr[a] <= 'F')    //16������ ���� ������ ��� A���� F�� �ƽ�Ű �ڵ尪���� 55�� ���� 10������ ��ȯ
				num += ((int)arr[a] - '7') * pow(b, (i - a - 1));

			else
				num += ((int)arr[a] - '0') * pow(b, (i - a - 1));

		}
		break;

	default:
		cout << "error";
		break;
	}

	switch (c)    //�Է¹��� ���� ���ϴ� ������ ��ȯ���ִ� switch��
	{
	case 2:
		convertBOH(num, c);
		break;

	case 8:
		convertBOH(num, c);
		break;

	case 10:
		cout << num;     //10������ 10������ ��ȯ�ҋ��� �׳� num���� �����
		break;

	case 16:
		convertBOH(num, c);
		break;

	default:
		cout << "error";
		break;
	}

	return 0;
}