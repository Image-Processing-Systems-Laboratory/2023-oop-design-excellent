#include<iostream>

using namespace std;	//std 라이브러리에 포함된 내용들을 사용

//함수 선언
void PutIn_Matrix(double (*Matrix_arr)[3]);				//3*3 배열의 각 입력값을 받는 함수
double MakeInverseMatirx(double(*Matrix_arr)[3], double(*InverseMatrix_arr)[3]);	//Matrix_arr의 역행렬이 있다면 InverseMatrix_arr에 저장하고 1을 반환하는 함수 없다면 0반환
double det(double(*Matrix_arr)[3]);				//Matrix_arr의 행렬식을 반환하는 함수
void PrintArr(double(*inverseMatrix_arr)[3]);	//3*3 배열의 값을 출력하는 함수

int main()
{
	double Matrix_arr[3][3];			//double형 2차원 배열 3*3 선언
	double inverseMatrix_arr[3][3];		//double형 2차원 배열 3*3 선언
	cout << "3*3 Matrix의 수를 입력해라" << endl;
	PutIn_Matrix(Matrix_arr);				//3*3 배열의 각 입력값을 받음
	/*  Matrix_arr의 역행렬을 inverseMatirx_arr에 저장  */
	if (MakeInverseMatirx(Matrix_arr, inverseMatrix_arr) == 1)		//역행렬이 있다면 MakeInverseMatirx함수는 1을 반환
	{
		cout << "3*3 Matrix의 역행렬은 " << endl;
		PrintArr(inverseMatrix_arr);						//InverseMatirx_arr 배열의 값을 출력
	}
	return 0;
}
/*  3*3배열의 입력값을 받는 함수   */
void PutIn_Matrix(double(*Matrix_arr)[3]) {
	/* Matrix_arr[0][0]부터 Matrix_arr[2][2]까지 값을 입력 받음 */
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> Matrix_arr[i][j];		//Matrix_arr[i][j]에 값을 입력 받는다
}
/*  Matrix_arr의 역행렬이 있다면 InverseMatrix_arr에 저장하고 1을 반환하는 함수 없다면 0반환   */
double MakeInverseMatirx(double(*Matrix_arr)[3], double(*InverseMatrix_arr)[3]) {
	/*  각 doube형 변수를 선언 및 각각의 Matrix_arr의 값으로 초기화함  */
	double a = Matrix_arr[0][0], b = Matrix_arr[0][1], c = Matrix_arr[0][2];
	double d = Matrix_arr[1][0], e = Matrix_arr[1][1], f = Matrix_arr[1][2];
	double g = Matrix_arr[2][0], h = Matrix_arr[2][1], i = Matrix_arr[2][2];

	if (det(Matrix_arr) == 0)	//행렬식의 값이 0 이면
	{
		cout << "The inverse matrix does not exist" << endl;
		return 0;
	}
	/*  각 역행렬의 값을 InverseMatrix_arr의 배열에 저장함  */
	InverseMatrix_arr[0][0] = (e * i - f * h) / det(Matrix_arr);
	InverseMatrix_arr[0][1] = (c * h - b * i) / det(Matrix_arr);
	InverseMatrix_arr[0][2] = (b * f - c * e) / det(Matrix_arr);
	InverseMatrix_arr[1][0] = (f * g - d * i) / det(Matrix_arr);
	InverseMatrix_arr[1][1] = (a * i - c * g) / det(Matrix_arr);
	InverseMatrix_arr[1][2] = (c * d - a * f) / det(Matrix_arr);
	InverseMatrix_arr[2][0] = (d * h - e * g) / det(Matrix_arr);
	InverseMatrix_arr[2][1] = (b * g - a * h) / det(Matrix_arr);
	InverseMatrix_arr[2][2] = (a * e - b * d) / det(Matrix_arr);
	return 1;
}
/*  Matrix_arr의 행렬식을 반환하는 함수  */
double det(double(*Matrix_arr)[3]) {
	/*  행렬식을 반환함  */
	return (Matrix_arr[0][0] * Matrix_arr[1][1] * Matrix_arr[2][2]
		+ Matrix_arr[0][1] * Matrix_arr[1][2] * Matrix_arr[2][0]
		+ Matrix_arr[0][2] * Matrix_arr[1][0] * Matrix_arr[2][1]
		- Matrix_arr[0][2] * Matrix_arr[1][1] * Matrix_arr[2][0]
		- Matrix_arr[1][2] * Matrix_arr[2][1] * Matrix_arr[0][0]
		- Matrix_arr[2][2] * Matrix_arr[0][1] * Matrix_arr[1][0]);
}
/*  3*3 배열의 값을 출력하는 함수  */
void PrintArr(double(*inverseMatrix_arr)[3]) {
	/* inverseMatrix_arr[0][0]부터 inverseMatrix_arr[2][2]까지 값을 출력함 */
	for (int i = 0; i < 3; i++)						//i가 0부터 2까지
	{
		for (int j = 0; j < 3; j++)					//j가 0부터 2까지
			cout << inverseMatrix_arr[i][j]<<' ';	//inverseMatrix_arr[i][j]값을 출력함
		cout << endl;								//개행
	}
}