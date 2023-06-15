#include "overloading.h"

using namespace std;

int main()
{
	Arrayoverloading array1, array2;
	
	cout << "===== Input data of array1 =====" << endl;
	array1.inputarray();
	cout << "\n===== Input data of array2 =====" << endl;
	array2.inputarray();

	cout << "Matrix 1 is\n";
	array1.printmatrix();

	cout << "Matrix 2 is\n";
	array2.printmatrix();
	// 배열을 입력 받은 뒤 기본적으로 입력된 배열을 출력
	string command;
	cout << "Please input + or - or * !\n>>> ";
	cin >> command;

	if (command == "+")
	{
		cout << "Plus result is\n";
		array1 += array2;
		array1.printmatrix();
		return 1;
	}

	if (command == "-")
	{
		cout << "Sub result is\n";
		array1 -= array2;
		array1.printmatrix();
		return 1;
	}
	// 덧셈 뺄셈은 array1 기준으로 이루어집니다.

	if (command == "*")
	{
		cout << "Mul result is\n";
		Arrayoverloading result = array1 * array2;
		result.printmatrix();
		return 1;
	}
	// 곱셈의 경우 result 객체를 새로 생성 후 해당 객체에 곱한 결과를 저장
	else
	{
		cerr << "Error: input commnad is invalid!" << endl;
		return -1;
	}

	return 0;
}