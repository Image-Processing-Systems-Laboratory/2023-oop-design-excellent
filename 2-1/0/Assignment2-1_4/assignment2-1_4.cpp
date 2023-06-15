#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char read_binary[200];		//������ ���ڿ��� �о�鿩 ����
	
	int text = 0;		//���ڸ� ������ ĭ
	int len;			//�о���� ���ڿ��� ���� ����
	ifstream fin;		//���� �Է� ���
	fin.open("binary.txt");	//binary.txt ���� ����
	char write_text[200];		//�о���� ���ڿ��� text�� ��ȯ�Ͽ� ����
	if (!fin) {			//���� ������ ������
		cout << "no" << endl;
	}
	
	while (!fin.eof())	//������ ���� �����Ҷ�����
	{
		fin.getline(read_binary, 200);	//read_binary�� 200��ŭ �б�
		len = strlen(read_binary);		//�Է¹��� ���ڿ� ���� ����
		int before_len = 0;	//��µ� ���ڿ� ������ ���̸� ����
		for (int j = 0; j <= len; j++)
		{
			if (read_binary[j] == '1')		//'1'�� ������ �Ǹ�
			{
				write_text[text++] = j - before_len + 'a';		//���� ����
				before_len = j + 1;				//���� ��� ������ ���ڿ� ���� ����
			}
			else if (j - before_len == 25)		//0�� ������ 25���� �Ǹ�
			{
				write_text[text++] = j - before_len + 'a';		//���� ����
				before_len = j;					//���� ��� ������ ���ڿ� ���� ����
			}
			else if (read_binary[j] == ' ')		//���̳ʸ��� ������ �ִٸ�
			{
				write_text[text++] = ' ';		//������ ������
				before_len++;					//���� ��� ������ ���ڿ� ���̸� ������
			}
		}
		write_text[text++] = '\n';				//���� ����
	}
	ofstream fout;		//���� ��� ���
	fout.open("alphabet.txt");		//alphabet.txt ���� ����
	fout.write(write_text, text);	//write_text�� text��ŭ ����
	fout.close();		//������ ���� �ݱ�
	fin.close();		//������ ���� �ݱ�

	return 0;
}