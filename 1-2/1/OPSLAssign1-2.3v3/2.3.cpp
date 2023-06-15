#include <iostream>
#include <fstream>

#pragma warning(disable:4996)

using namespace std;


int searchCODE(int searchnum, char** searcharr);
void searchLINE(int searchnum, int searchcode, char** searcharr, char* file_name);


int searchCODE(int searchnum, char** searcharr)	// �˻� �ڵ带 ��ȯ�ϴ� �Լ�.
{
	int Asterisk = 1;
	int Question = 1;

	int length = strlen(searcharr[searchnum]);	// searchnum��° �˻����� ����

	for (int i = 0; i < length; i++)
	{
		if (searcharr[searchnum][i] == '*')
		{
			if (i == 0)
				Asterisk = -1;		// * �� ���� �տ� ���� �� = �ڵ� 4
			else
				Asterisk = Asterisk * 2;		// * ���� = �ڵ� 0
		}
		if (searcharr[searchnum][i] == '?')		// ? ���� = �ڵ� 1
			Question++;
	}

	if (Asterisk > 1 && Question == 1)
		return 0;
	if (Asterisk == 1 && Question > 1)	// ? �� ����				OK
		return 1;
	if (Asterisk > 1 && Question > 1)	// *, ? ��� ����		
		return 3;	
	if (Asterisk < 0 && Question == 1)	// �� �� * ����, ? ������
		return 4;
	if (Asterisk < 0 && Question > 1)	// �� �� * ����, ? ����	
		return 5;
	if (Asterisk == 1 && Question == 1)	// �⺻ �˻� = �ڵ� 2		OK
		return 2;
}

void searchLINE(int searchnum, int searchcode, char** searcharr, char* file_name)
{
	ifstream file;
	file.open(file_name);
	char data[20];
	////////////////////////////////////////////////////////////// ���� ���°� �� ���� ���ڿ��� ���� data ����
	switch (searchcode)
	{
	case 0:	// wildcard * search

		while (!file.eof())
		{
			file.getline(data, 20);							// ���� 20��ŭ�� �����͸� eof���� �� �ٿ��� �޴´�.
			int asterisk = 0;
			for (int i = 0; i < strlen(searcharr[searchnum]); i++)
			{
				if (searcharr[searchnum][i] == '*')
					asterisk++;	// asterisk�� �� ����
			}
			int length = strlen(searcharr[searchnum]) - asterisk;// searcharr(�˻���)�� ���� *�� ��� ������ ����.
			int check = 0;

			for (int i = 0; i < length; i++)
			{
				if (data[i] == searcharr[searchnum][i])	// ���� ó������ �˻��� - 1�� ���̱��� �ܾ �ϳ��� Ȯ��
					check++;

			}
			if (check == length)			// �´ٸ� check�� Ȯ���� ���̿� ���� ���̴�.
				cout << data << endl;
		}
		file.close();
		break;

		//////////////////////////////////////////////////////////////
	case 1:	// wildcard ? search

		while (!file.eof())
		{
			file.getline(data, 20);

			int length = strlen(searcharr[searchnum]);
			int check = 0;

			if (length == strlen(data))			// *�ʹ� �޸� �������� ���̰� �ٸ��� �����Ѵ�.
			{
				for (int i = 0; i < length; i++)
				{
					if (searcharr[searchnum][i] == '?' || searcharr[searchnum][i] == data[i])
						check++;
				}								// ?�� ���ϵ�ī��� ���� �ʾƵ� ���� ������ �Ѵ�.
			}
			if (check == length)
				cout << data << endl;		// ���ڰ� �ϳ��� �ٸ��� check = length�� �� �� ����.
		}
		file.close();
		break;

		//////////////////////////////////////////////////////////////
	case 2:	// default line search
		while (!file.eof())
		{
			file.getline(data, 20);

			int length = strlen(searcharr[searchnum]);
			int check = 0;

			if (length == strlen(data))		// *�ʹ� �޸� �������� ���̰� �ٸ��� �����Ѵ�.
			{
				for (int i = 0; i < length; i++)
				{
					if (data[i] == searcharr[searchnum][i])
						check++;
				}
			}
			if (check == length)
				cout << data << endl;		// ���ڰ� �ϳ��� �ٸ��� check = length�� �� �� ����.
		}
		file.close();
		break;

	case 3:	// *, ? ��� ����
		while (!file.eof())
		{
			file.getline(data, 20);

			int asterisk = 0;
			for (int i = 0; i < strlen(searcharr[searchnum]); i++)
			{
				if (searcharr[searchnum][i] == '*')
					asterisk++;	// asterisk�� �� ����
			}
			int length = strlen(searcharr[searchnum]) - asterisk;// searcharr(�˻���)�� ���� *�� ��� ������ ����.
			//////////////////////////////////////////////////////////////////////////////
			int check = 0;

			for (int i = 0; i < length; i++)
			{
				if (searcharr[searchnum][i] == '?' || searcharr[searchnum][i] == data[i] || searcharr[searchnum][i] == '*')
				{
					if(data[i] != NULL)
					check++;
				}
			}

			if (check == length)
				cout << data << endl;		// ���ڰ� �ϳ��� �ٸ��� check = length�� �� �� ����.
		}
		file.close();
		break;

	case 4:	// �Ǿ� *, ? ������
	{
		int length = strlen(searcharr[searchnum]);
		int asterisk = 0;
		int i = 0;
		while (searcharr[searchnum][0] == '*')
		{
			for (int j = 0; j < length; j++)
			{
				searcharr[searchnum][j] = searcharr[searchnum][j + 1];
			}
			searcharr[searchnum][length - i] = NULL;
			i++;
		}
		length = strlen(searcharr[searchnum]);

		/////////////////	�Ǿ��� *�� ������ŭ �迭�� ���� ������ �δ�. �׸��� ���� ���� ���ŭ���� �ٽ� �����Ѵ�.

		while (!file.eof())
		{
			file.getline(data, 20);

			int check = 0;

			if (length == 0)	// �˻�� ���� *�� �̷����������
			{
				cout << data << endl;
				continue;
			}

			for (int k = 0; k < strlen(data) - length + 2; k++)	// �������� ���� - �˻����� ������ �� + 1��ŭ ����
			{											// k�� �˻��� �����Ͷ�� �ϸ� �˻�� ���ϱ����� �����͸� �Űܰ���.
				for (int i = 0; i < length; i++)	// �˻����� ���̸�ŭ ����: �� �����͸� ��
				{
					if (data[k + i] == searcharr[searchnum][i] || searcharr[searchnum][i] == '*')	// �������� ��ġ���� �˻�� ���Ѵ�.
					{
						if (data[i] != NULL)	// �˻��� �������� ���̸� �ʰ��ؼ� �˻����� �ʵ�����
							check++;
					}
				}
				if (check == length)		// �˻����� ��ġ ������ �˻���� ������ �ùٸ� ���.
				{
					cout << data << endl;
				}
					check = 0;	// ���� �˻��� ���� �ʱ�ȭ
			}
		}
		file.close();
		break;
	}

	case 5:	// �Ǿ� *, ? ���� > �Ǿ��� *�϶��� ������ ?�� check�� ���ԵǴ� ���� �ٸ���.
	{
		int length = strlen(searcharr[searchnum]);
		int asterisk = 0;
		while (searcharr[searchnum][asterisk] == '*')
		{
			asterisk++;
		}
		for (int i = 0; i < asterisk; i++)
		{
			for (int j = 0; j < length; j++)
			{
				searcharr[searchnum][j] = searcharr[searchnum][j + 1];
			}
			searcharr[searchnum][length - i] = NULL;
		}
		length = length - asterisk;
		/////////////////

		while (!file.eof())
		{
			file.getline(data, 20);

			int check = 0;

			for (int k = 0; k < strlen(data) - length + 2; k++)
			{
				for (int i = 0; i < length; i++)
				{
					if (data[k + i] == searcharr[searchnum][i] || searcharr[searchnum][i] == '?' || searcharr[searchnum][i] == '*') // ?�� check�� ����
					{
						if (data[i] != NULL)
							check++;
					}
				}
				if (check == length)
				{
					cout << data << endl;
				}
					check = 0;
			}
		}
		file.close();
		break;
	}

	}
	return;
}











int main()
{
	char file_name[20];

	cout << "Input file name : ";
	cin >> file_name;

	ifstream file;
	file.open(file_name);

	if (!file)	// ������ ������ �ʾ����� ���� ���
	{
		cout << "No File" << endl;
		return 1;
	}
	file.close();

	////////////////////////////////////////////////////////////// ������ �̸� �Է� �ޱ�

	int N;
	cin >> N;

	char searchline[20];
	char** searcharr;
	searcharr = new char* [N];		// searcharr�� �����Ҵ� N���� ��� �˻��� ���� + 1�� ���̸� ������ �ִ�.


	for (int i = 0; i < N; i++)
	{
		cin >> searchline;
		searcharr[i] = new char[strlen(searchline) + 1];	// searharr[i]�� �˻�� ����ȴ�.
		strcpy(searcharr[i], searchline);
	}

	////////////////////////////////////////////////////////////// searcharr�� ���� �Ҵ�

	cout << endl;

	for (int i = 0; i < N; i++)
		searchLINE(i, searchCODE(i, searcharr), searcharr, file_name);	// searchCODE�� �˻��� ��ȣ�� �˻���, searchLINE���� �ڵ�� ���ϸ�, �˻�� �����Ѵ�.
	
	////////////////////////////////////////////////////////////// searchLINE�� ����

	for (int i = 0; i < N; i++)
		delete[] searcharr[i];		//�޸� ����

	return 0;
	//////////////////////////////////////////////////////////////  ��ȯ
}