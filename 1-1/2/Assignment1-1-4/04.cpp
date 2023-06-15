/*det(A)=0이면 예외*/
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int A[3][3]; // 입력받을 행렬
	double invA[3][3]; // 수반행렬
	int minor[2][2]; // 소행렬식
	int row = 0;// minor 행 index
	int column = 0; // minor 열 index
	int detA = 0; // 행렬식
	
	/*행렬 입력*/
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> A[i][j];
	}

	/*배열의 첫번째 행을 기준으로 행렬식 구하기*/
	detA = (A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
		- A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
		+ A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]));

	/*detA = 0 이면 역행렬이 정의되지 않음*/
	if (detA == 0)
	{
		cout << "The inverse matrix does not exist." << endl;

		return 0;
	}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			/*소행렬식 구하기*/
			row = 0;
			for (int k = 0; k < 3; k++)
			{
				column = 0;
				/*참조하고 있는 A요소와 같은 행은 건너뛰기*/
				if (k == i)
					continue;
				for (int l = 0; l < 3; l++)
				{
					/*참조하고 있는 A요소와 같은 열은 건너뛰기*/
					if (l == j)
						continue;
					minor[row][column] = A[k][l];
					column++;
				}
				row++;
			}

			/*여인수행렬 구하기*/
			if ((i + j) % 2 == 1)
				invA[i][j] = (-1) * (minor[0][0] * minor[1][1] - minor[0][1] * minor[1][0]);
			else
				invA[i][j] = (minor[0][0] * minor[1][1] - minor[0][1] * minor[1][0]);
		}
	}

	/*여인수행렬 -> 수반행렬*/
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
	
	/*역행렬 출력*/
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