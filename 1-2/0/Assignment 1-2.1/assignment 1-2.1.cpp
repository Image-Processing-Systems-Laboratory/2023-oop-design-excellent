#include<iostream>
#include<string.h>
using namespace std;

//�Լ�����

//79 897687543217
//897687543217 89
//897687543217 897687543217

int main()
{
	char str1[20], str2[20], str3[40];	//char�� �迭 ����
	int str3_len;						//int�� �迭 ����
	cout << "Input: ";
	cin >> str1 >> str2;				//�ΰ��� ���ڿ��� �Է� ����
	
	strcpy_s(str3, str1);				//str3�� str1�� ������
	strcat_s(str3, str2);				//str3�� str2�� �̾����
	str3_len = strlen(str3);			//str3�� ���ڿ� ���̸� ������
	cout << "Output: ";
	for (int i = 0; i < str3_len; i++)	//i�� 0���� str3_len-1����
	{
		int num = 0, count = 0;			//int�� ���� ����, 0���� �ʱ�ȭ
		for (int k = 0; k < str3_len; k++)	//k�� 0���� str3_len-1����
			if (str3[i] == str3[k])		//���� �������� �ִٸ�
				num++;					//num = num + 1�� �Ѵ�.

		if (i > 0)				//i�� 0���� Ŭ��
			for (int j = i - 1; j > -1; j--)	//j�� i-1���� 0����
				if (str3[i] == str3[j])		//�̹� ����� ���� �����ϴٸ�
					count++;				//������ ���� ���� ī��Ʈ��(count = count + 1)
		if (count > 0)						//�̹� ����� ���� �ִٸ�(count>0�϶�)
			continue;
		cout << str3[i] << num;				//���ڿ� �� ������ ������ ����Ѵ�.
	}
	return 0;
}