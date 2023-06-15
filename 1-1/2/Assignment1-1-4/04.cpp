/*det(A)=0�̸� ����*/
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int A[3][3]; // �Է¹��� ���
	double invA[3][3]; // �������
	int minor[2][2]; // ����Ľ�
	int row = 0;// minor �� index
	int column = 0; // minor �� index
	int detA = 0; // ��Ľ�
	
	/*��� �Է�*/
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> A[i][j];
	}

	/*�迭�� ù��° ���� �������� ��Ľ� ���ϱ�*/
	detA = (A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
		- A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
		+ A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]));

	/*detA = 0 �̸� ������� ���ǵ��� ����*/
	if (detA == 0)
	{
		cout << "The inverse matrix does not exist." << endl;

		return 0;
	}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			/*����Ľ� ���ϱ�*/
			row = 0;
			for (int k = 0; k < 3; k++)
			{
				column = 0;
				/*�����ϰ� �ִ� A��ҿ� ���� ���� �ǳʶٱ�*/
				if (k == i)
					continue;
				for (int l = 0; l < 3; l++)
				{
					/*�����ϰ� �ִ� A��ҿ� ���� ���� �ǳʶٱ�*/
					if (l == j)
						continue;
					minor[row][column] = A[k][l];
					column++;
				}
				row++;
			}

			/*���μ���� ���ϱ�*/
			if ((i + j) % 2 == 1)
				invA[i][j] = (-1) * (minor[0][0] * minor[1][1] - minor[0][1] * minor[1][0]);
			else
				invA[i][j] = (minor[0][0] * minor[1][1] - minor[0][1] * minor[1][0]);
		}
	}

	/*���μ���� -> �������*/
	for (int i = 1; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int tmp = invA[i][j];
			invA[i][j] = invA[j][i];
			invA[j][i] = tmp;
		}
	}
	
	/* inverse matrix = (1 / detA)adjA */
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			invA[i][j] /= detA;
		}
	}
	
	/*����� ���*/
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout.width(6);
			cout << left << invA[i][j];
		}
		cout << endl;
	}


	return 0;
}