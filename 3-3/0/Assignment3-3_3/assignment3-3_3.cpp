#include<iostream>
#include "Matrix.h"
using namespace std;

int main()
{
	Matrix mat1;
	Matrix mat2;
	Matrix mat3;
	Matrix mat4;
	double A[3][3];

	//mat1 입력받기
	cout << "mat1= ";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> A[i][j];
	//mat1에 저장된 행렬 저장
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			mat1.setElement(A[i][j], i, j);

	//mat2 입력받기
	cout << "mat2= ";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> A[i][j];
	//mat2에 저장된 행렬 저장
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			mat2.setElement(A[i][j], i, j);
	
	//mat1 출력
	cout << "mat1" << endl;
	mat1.printMatrix();
	//mat2 출력
	cout << "mat2" << endl;
	mat2.printMatrix();

	//mat1*mat2 출력
	cout << "mat1 * mat2" << endl;
	mat3 = mat1 * mat2;
	mat3.printMatrix();
	//mat1+=mat2 출력
	cout << "mat1+=mat2" << endl;
	mat1.operator+=(mat2);
	mat1.printMatrix();
	//mat1+=3 출력
	cout << "mat1+=3" << endl;
	mat1.operator+=(3);
	mat1.printMatrix();

	//mat1-=3 출력
	cout << "mat1-=3" << endl;
	mat1.operator-=(3);
	mat1.printMatrix();
	//mat1-=mat2 출력
	cout << "mat1-=mat2" << endl;
	mat1.operator-=(mat2);
	mat1.printMatrix();
	//mat2*3 출력
	cout << "mat2*3" << endl;
	mat4 = mat2 * 3;
	mat4.printMatrix();

	return 0;
}