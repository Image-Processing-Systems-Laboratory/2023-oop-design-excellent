#include<iostream>

int main()
{
	int matrix[3][3];
	int Cofactor[3][3];
	int detA;		//행렬식
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			std::cin >> matrix[i][j];
	Cofactor[0][0] = matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2];			//C 구하기
	Cofactor[0][1] = -(matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);
	Cofactor[0][2] = matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1];
	Cofactor[1][0] = -(matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]);
	Cofactor[1][1] = matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2];
	Cofactor[1][2] = -(matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]);
	Cofactor[2][0] = matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2];
	Cofactor[2][1] = -(matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]);
	Cofactor[2][2] = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	detA = (matrix[0][0] * Cofactor[0][0]) + (matrix[0][1] * Cofactor[0][1]) + (matrix[0][2] * Cofactor[0][2]);
	if (detA == 0)		//행렬 A에 대한 역행렬 존재여부 판별 => detA가 0일 시 역행렬이 존재 하지 않음 
	{
		std::cout << "The inverse matrix does not exist";
		return 0;
	}
	for (i = 0; i < 3; i++)
		for (j = 0; j <= i; j++)		//C를 전치해서 C_t구하기
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
			std::cout.width(11);	//소수점이 길어질 것을 대비해 간격을 띄어서 출력
			std::cout << (double)Cofactor[i][j] / (double)detA;		//double형으로 형변환 후 나누기

		}
		std::cout << "\n";
	}
}