#include<iostream>

using namespace std;


int main()
{
	int Output[128];	//���� ������ �迭
	int top = 0;		//���� �� ����
	char Input[128];	//�Է¹��� ���ڿ� ����
	while (1)
	{
		cout << "Input: ";
		//�Է¹ޱ�
		cin.getline(Input, sizeof(Input));

		//�Է¹��� ���� ����
		if (strncmp(Input, "push", 4) == 0)
		{
			Output[++top - 1] = atoi(Input + 5);	//++top �� ���� ���� 
		}

		//���� ���� ���� ����ϰ� ����
		else if (strcmp(Input, "pop") == 0 && top > 0)
		{
			cout << Output[top - 1] << endl;		//���� ���� ���� ���
			Output[top-- - 1] = 0;					//���� ���� ���� ������
		}

		//���� ���� ���� ���
		else if (strcmp(Input, "top") == 0 && top > 0)
			cout << Output[top - 1] << endl;		//���� ���� �� ���

		//����� ���� ���
		else if (strcmp(Input, "print") == 0)
		{
			for (int i = 0; i <= top - 1; i++)		//top-1���� ����Ǿ� �ִ� ��� �� ���
				cout << Output[i] << " ";
			cout << endl;
		}

		//��� �ִٸ� 1��� ������� �ʴٸ� 0���
		else if (strcmp(Input, "empty") == 0)
		{
			if (top > 0)	//stack�� ������� ������
				cout << 0 << endl;
			else			//stack�� ���������
				cout << 1 << endl;
		}
		
		//���α׷� ����
		else if (strcmp(Input, "exit") == 0)
			return 0;

	}

	return 0;
}


