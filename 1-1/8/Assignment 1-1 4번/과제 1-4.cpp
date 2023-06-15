#include <iostream> // 헤더파일 선언
using namespace std; // 표준 라이브러리 사용

int main() //메인함수 선언
{

	double A[3][3]; // 3x3 행렬 A를 double 형으로 선언
	double a, b, c; // det(A)를 구할 때 쓰기위한 변수 a,b,c 선언
	double det_A;  // det(A) 선언
	double C[3][3]; // 행렬 A의 cofactor matrix C 선언
	double transpose_C[3][3]; // 행렬 C의 transpose matrix 선언
	double inverse_A[3][3]; // A의 역행렬 선언
	int input; // 문제 조건에 따라 사용자로부터 입력받을 정수형 변수 input 선언
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> input; // 사용자로부터 정수형 변수 input을 입력받고
			A[i][j] = input; // 이 값들을 행렬 A에 저장
		}
	}
	a = A[0][0] * ((A[1][1] * A[2][2]) - (A[1][2] * A[2][1]));
	b = A[0][1] * ((A[1][0] * A[2][2]) - (A[1][2] * A[2][0]));
	c = A[0][2] * ((A[1][0] * A[2][1]) - (A[1][1] * A[2][0]));
	det_A = a - b + c;  // a,b,c의 값들을 계산해 det(A)값 구하기

	// A의 cofactor matrix C 구하는 과정
	C[0][0] = A[1][1] * A[2][2] - A[2][1] * A[1][2];
	C[0][1] = -(A[1][0] * A[2][2] - A[2][0] * A[1][2]);
	C[0][2] = A[1][0] * A[2][1] - A[1][1] * A[2][0];
	C[1][0] = -(A[0][1] * A[2][2] - A[0][2] * A[2][1]);
	C[1][1] = A[0][0] * A[2][2] - A[2][0] * A[0][2];
	C[1][2] = -(A[0][0] * A[2][1] - A[0][1] * A[2][0]);
	C[2][0] = A[0][1] * A[1][2] - A[0][2] * A[1][1];
	C[2][1] = -(A[0][0] * A[1][2] - A[0][2] * A[1][0]);
	C[2][2] = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	
	// 위의 과정에서 행렬 C의 원소가 0인데, 앞에 -가 붙었을 경우 -0이 되지 않도록 -0이면 0으로 바꿔줌
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (C[i][j] == -0)
				C[i][j] = 0;
		}
	}
	
	// 행렬 C의 각 원소의 행과 열을 바꿔줘서 transpose matrix를 구하고, 여기에 1/det(A)를 곱한 값이 A의 역행렬이므로
	// 역행렬 inverse_A에 맞는 값들을 넣어줌
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			transpose_C[i][j] = C[j][i];
			inverse_A[i][j] = transpose_C[i][j] * (1 / det_A);
		}
	}
	
	cout << endl; // 결과 화면에서 입력값과 출력값을 구분하기 위해 개행해줌
	
	// det(A)가 0이면 역행렬이 존재하지 않으므로
	if (det_A == 0)
		cout << "The inverse matrix does not exist."; // 존재하지 않는다는 메세지 출력

	// 그 외의 경우
	else 
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << inverse_A[i][j] << " ";
			}
			cout << endl;
		} // 역행렬을 출력
	
	return 0; // 프로그램 종료
}	