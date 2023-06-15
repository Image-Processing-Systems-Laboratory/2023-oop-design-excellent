#include"Matrix.h"

int main(void)
{
	// 테스트용 코드
	Matrix mat1;
	mat1.setelem(0, 0, 1);
	mat1.setelem(0, 1, 2);
	mat1.setelem(0, 2, 3);
	mat1.setelem(1, 0, 0);
	mat1.setelem(1, 1, 1);
	mat1.setelem(1, 2, 4);
	mat1.setelem(2, 0, 5);
	mat1.setelem(2, 1, 6);
	mat1.setelem(2, 2, 0);
	mat1.print();
	cout << endl;

	Matrix mat2;
	mat2.setelem(0, 0, 3);
	mat2.setelem(0, 1, 4);
	mat2.setelem(0, 2, 5);
	mat2.setelem(1, 0, 1);
	mat2.setelem(1, 1, 0);
	mat2.setelem(1, 2, 2);
	mat2.setelem(2, 0, 3);
	mat2.setelem(2, 1, 4);
	mat2.setelem(2, 2, 4);
	mat2.print();
	cout << endl;

	cout << "Addition" << endl;
	(mat1 += mat2).print();
	cout << endl;

	cout << "Subtraction" << endl;
	(mat1 -= mat2).print();
	cout << endl;

	cout << "Multiplication" << endl;
	(mat1 * mat2).print();

	return 0;
}