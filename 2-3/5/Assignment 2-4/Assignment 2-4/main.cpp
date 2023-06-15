#include <iostream>
#include <windows.h>
#include <string>
#include "ooplinalg.h"

using namespace std;
using namespace ooplinag;

bool ChooseMatrix()			//select matrix
{
	string select = "";
	cout << "input 1 == select first matrix else select second matrix: ";
	getline(cin, select);

	return select == "1";
}

int main()
{
	int matrix1row, matrix1col, matrix2row, matrix2col = 0;
	cout << "1번째 매트릭스의 행과 열의 사이즈를 입력하세요" << endl;		//input matrix1 info
	cin >> matrix1row;
	cin >> matrix1col;
	cout << "2번째 매트릭스의 행과 열의 사이즈를 입력하세요" << endl;		//input matrix2 info
	cin >> matrix2row;
	cin >> matrix2col;

	cout << "1번째 행렬의 데이터를 입력하세요" << endl;
	ooplinag::Matrix matrixno1(matrix1row, matrix1col);						//make matrix 1

	cout << "2번째 행렬의 데이터를 입력하세요" << endl;
	ooplinag::Matrix matrixno2(matrix2row, matrix2col);						//make matrix 2

	string input = "";
	cout << "명령어 종류: add, sub, mul, scalarAdd, scalarSub, scalarMul, sclaraDiv" << endl;
	cout << "transpose, adjoint, inverse" << endl;

	cin.ignore(100, '\n');

	while (1)
	{
		cout << "Enter input ('exit' to quit) : ";  //exit값을 입력받을 때까지 반복한다.
		getline(cin, input);                        //cin

		if (input == "exit")
			break;

		if (input == "add" || input == "sub")
		{
			if (matrix1row == matrix2row && matrix1col == matrix2col)
			{
				ooplinag::Matrix resultMatrix;
				if (input == "add")					//execute add
				{
					resultMatrix = ooplinag::add(resultMatrix, matrixno1, matrixno2);
				}
				else								//execute sub
				{
					resultMatrix = ooplinag::sub(resultMatrix, matrixno1, matrixno2);
				}
			}
			else									//matrix의 크기가 다를 경우 
			{
				cout << "크기가 다른 행령의 덧셈과 뺄셈은 불가능 합니다." << endl;
				continue;
			}
		}
		else if (input == "mul")				
		{
			bool isPossible = isMulPossible(matrixno1, matrixno2);
			if (!isPossible)						//곱하기가 불가능 할 때
			{
				cout << "해당 행렬들은 곱하기가 불가능 합니다.";
				continue;
			}

			ooplinag::Matrix resultMatrix;
			resultMatrix = ooplinag::mul(resultMatrix, matrixno1, matrixno2);		//execute mul
		}
		else if (input == "scalarAdd" || input == "scalarSub" || input == "scalarMul" || input == "scalarDiv")
		{
			bool isFirst = ChooseMatrix();			//select matrix
			ooplinag::Matrix scalarMatrix;
			ooplinag::Matrix chooseMatrix = isFirst ? matrixno1 : matrixno2;

			float v = 0.0;
			cout << "스칼라 값을 입력하세요: ";
			cin >> v;								//input scalar
			cin.ignore();


			if (input == "scalarAdd")
			{
				scalarMatrix = ooplinag::elementAdd(scalarMatrix, chooseMatrix, v);	//execute scalar add
			}
			else if (input == "scalarSub")
			{
				scalarMatrix = ooplinag::elementSub(scalarMatrix, chooseMatrix, v);	//execute scalar sub
			}
			else if (input == "scalarMul")
			{
				scalarMatrix = ooplinag::elementMul(scalarMatrix, chooseMatrix, v);	//execute scalar mul
			}
			else
			{
				scalarMatrix = ooplinag::elementDiv(scalarMatrix, chooseMatrix, v);	//execute scalar div
			}
		}
		else if (input == "transpose" || input == "adjoint" || input == "inverse")
		{
			bool isFirst = ChooseMatrix();
			ooplinag::Matrix operationMatrix;
			ooplinag::Matrix chooseMatrix = isFirst ? matrixno1 : matrixno2;

			if (input == "transpose")
			{
				if (chooseMatrix.getRows() == 0 || chooseMatrix.getCols() == 0)	//if size = 0 exception
				{
					cout << "전치행렬을 구할 수 없습니다." << endl;
					continue;
				}
				operationMatrix = ooplinag::transpose(operationMatrix, chooseMatrix);	//execute transpose
			}
			else if (input == "adjoint")
			{
				if (chooseMatrix.getRows() == 0)								//if row size = 0 exception
				{
					cout << "여인수행렬을 구할 수 없습니다." << endl;
					continue;
				}

				operationMatrix = ooplinag::adjoint(operationMatrix, chooseMatrix);		//execute adjoint
			}
			else
			{
				if (chooseMatrix.getRows() != chooseMatrix.getCols())			//if matrix is not M * M exception
				{
					cout << "행렬이 정사각형이 아닙니다." << endl;
					continue;
				}

				if (ooplinag::determinant(chooseMatrix) == 0)					//if Det == 0 exception	
				{
					cout << "det값이 0이므로 역행렬은 존재하지 않습니다." << endl;
					continue;
				}
				operationMatrix = ooplinag::inverse(operationMatrix, chooseMatrix);		//execute inverse
			}
		}
		else
		{
			cout << "올바르지 않은 명령어입니다." << endl << "다시 입력해주세요." << endl;		//command error
			continue;
		}
	}


	system("PAUSE");
	Sleep(1000); //1 second stop
	return 0;
}