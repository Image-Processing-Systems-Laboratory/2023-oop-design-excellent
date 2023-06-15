#include <iostream>
#include <cmath>
using namespace std;

// 2x2행렬의 deterninant 계산하는 함수의 prototype
int det_22(int i1, int i2, int j1, int j2, int mat[][3]);

int main()
{
	// 입력값을 받는 matrix배열, cofactor를 계산해서 저장할 cofact 배열 선언 후 초기화
	int matrix[3][3]{}, cofact[3][3]{}, i, j, det = 0;
	// 역함수를 계산하여 저장할 inverse 배열 선언 후 초기화. 결과값
	double inverse[3][3]{};
	
	// 입력값 입력받기
	cout << "Enter 3x3 Matrix" << endl;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			cin >> matrix[i][j];
	cout << endl;

	// 3x3 배열의 deterninant 계산해서 det 변수에 저장
	// 첫번째 열을 기준으로 det 계산
	for (i = 0; i < 3; i++)
		det += matrix[i][0] * det_22((i + 1) % 3, (i + 2) % 3, 1, 2, matrix) * pow(-1, i);

	// det가 0이하면 역행렬이 존재하지 않는다는 문구 출력 후 프로그램 종류
	if (det == 0)
	{
		cout << "The inverse matrix does not exist." << endl;
		return 0;
	}

	// 이중 반복문으로 cofactor 계산 후 저장
	for(i = 0; i < 3; i++) // i는 행을 의미
		for (j = 0; j < 3; j++) // j는 열을 의미
			cofact[i][j] = det_22((i + 1) % 3, (i + 2) % 3, (j + 1) % 3, (j + 2) % 3, matrix) * pow(-1, i + j);

	// 이중 반복문을 통해 cofactor를 transpose하여 기존 matrix에 저장
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			matrix[j][i] = cofact[i][j];

	// 역함수 계산 후 출력
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			inverse[i][j] = static_cast<double>(matrix[i][j]) / det; // double로 강제 형변환
			cout << right; // 출력시 오른쪽 정렬
			cout.width(5); // 출력 칸수를 5칸으로 고정시켜 가시성 증가
			cout.precision(2); // 최대 소수점 아래 2자리까지 출력
			cout << inverse[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

// 2x2 배열 계산 함수
int det_22(int i1, int i2, int j1, int j2, int mat[][3])
{
	// 행을 의미하는 i1과 i2를 비교하여 i1이 더 크면 서로 스위치
	if (i1 > i2)
	{
		int temp = i1;
		i1 = i2;
		i2 = temp;
	}
	// 열을 의미하는 j1과 j2를 비교하여 j1이 더 크면 서로 스위치
	if (j1 > j2)
	{
		int temp = j1;
		j1 = j2;
		j2 = temp;
	}
	// 앞서 처리한 행 열 인자 i1, i2, j1, j2에 따라 determinant 계산 후 반환
	return mat[i1][j1] * mat[i2][j2] - mat[i1][j2] * mat[i2][j1];
}

