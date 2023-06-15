#include<iostream>

int main()
{
	int matrix[3][3];
	int Cofactor[3][3];
	int detA;		//��Ľ�
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			std::cin >> matrix[i][j];
	Cofactor[0][0] = matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2];			//C ���ϱ�
	Cofactor[0][1] = -(matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);
	Cofactor[0][2] = matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1];
	Cofactor[1][0] = -(matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]);
	Cofactor[1][1] = matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2];
	Cofactor[1][2] = -(matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]);
	Cofactor[2][0] = matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2];
	Cofactor[2][1] = -(matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]);
	Cofactor[2][2] = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	detA = (matrix[0][0] * Cofactor[0][0]) + (matrix[0][1] * Cofactor[0][1]) + (matrix[0][2] * Cofactor[0][2]);
	if (detA == 0)		//��� A�� ���� ����� ���翩�� �Ǻ� => detA�� 0�� �� ������� ���� ���� ���� 
	{
		std::cout << "The inverse matrix does not exist";
		return 0;
	}
	for (i = 0; i < 3; i++)
		for (j = 0; j <= i; j++)		//C�� ��ġ�ؼ� C_t���ϱ�
		{
			int temp;
			temp = Cofactor[i][j];
			Cofactor[i][j] = Cofactor[j][i];
			Cofactor[j][i] = temp;
		}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			std::cout.width(11);	//�Ҽ����� ����� ���� ����� ������ �� ���
			std::cout << (double)Cofactor[i][j] / (double)detA;		//double������ ����ȯ �� ������

		}
		std::cout << "\n";
	}
}