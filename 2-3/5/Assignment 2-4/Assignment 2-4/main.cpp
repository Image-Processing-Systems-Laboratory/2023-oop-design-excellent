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
	cout << "1��° ��Ʈ������ ��� ���� ����� �Է��ϼ���" << endl;		//input matrix1 info
	cin >> matrix1row;
	cin >> matrix1col;
	cout << "2��° ��Ʈ������ ��� ���� ����� �Է��ϼ���" << endl;		//input matrix2 info
	cin >> matrix2row;
	cin >> matrix2col;

	cout << "1��° ����� �����͸� �Է��ϼ���" << endl;
	ooplinag::Matrix matrixno1(matrix1row, matrix1col);						//make matrix 1

	cout << "2��° ����� �����͸� �Է��ϼ���" << endl;
	ooplinag::Matrix matrixno2(matrix2row, matrix2col);						//make matrix 2

	string input = "";
	cout << "��ɾ� ����: add, sub, mul, scalarAdd, scalarSub, scalarMul, sclaraDiv" << endl;
	cout << "transpose, adjoint, inverse" << endl;

	cin.ignore(100, '\n');

	while (1)
	{
		cout << "Enter input ('exit' to quit) : ";  //exit���� �Է¹��� ������ �ݺ��Ѵ�.
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
			else									//matrix�� ũ�Ⱑ �ٸ� ��� 
			{
				cout << "ũ�Ⱑ �ٸ� ����� ������ ������ �Ұ��� �մϴ�." << endl;
				continue;
			}
		}
		else if (input == "mul")				
		{
			bool isPossible = isMulPossible(matrixno1, matrixno2);
			if (!isPossible)						//���ϱⰡ �Ұ��� �� ��
			{
				cout << "�ش� ��ĵ��� ���ϱⰡ �Ұ��� �մϴ�.";
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
			cout << "��Į�� ���� �Է��ϼ���: ";
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
					cout << "��ġ����� ���� �� �����ϴ�." << endl;
					continue;
				}
				operationMatrix = ooplinag::transpose(operationMatrix, chooseMatrix);	//execute transpose
			}
			else if (input == "adjoint")
			{
				if (chooseMatrix.getRows() == 0)								//if row size = 0 exception
				{
					cout << "���μ������ ���� �� �����ϴ�." << endl;
					continue;
				}

				operationMatrix = ooplinag::adjoint(operationMatrix, chooseMatrix);		//execute adjoint
			}
			else
			{
				if (chooseMatrix.getRows() != chooseMatrix.getCols())			//if matrix is not M * M exception
				{
					cout << "����� ���簢���� �ƴմϴ�." << endl;
					continue;
				}

				if (ooplinag::determinant(chooseMatrix) == 0)					//if Det == 0 exception	
				{
					cout << "det���� 0�̹Ƿ� ������� �������� �ʽ��ϴ�." << endl;
					continue;
				}
				operationMatrix = ooplinag::inverse(operationMatrix, chooseMatrix);		//execute inverse
			}
		}
		else
		{
			cout << "�ùٸ��� ���� ��ɾ��Դϴ�." << endl << "�ٽ� �Է����ּ���." << endl;		//command error
			continue;
		}
	}


	system("PAUSE");
	Sleep(1000); //1 second stop
	return 0;
}