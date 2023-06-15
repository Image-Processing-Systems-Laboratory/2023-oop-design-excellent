#include <iostream> //iostream 선언
using namespace std; //namespace std 선언
void inputmatrix(void); //original Matrix 입력받는 함수 선언
void outputinverse(void); //inverse Matrix 계산 및 출력하는 함수 선언
double finddev(void); //original matrix의 행렬값을 구하는 함수 선언

double detmat = 0; //행렬값을 받는 변수 선언
int original[3][3];//original matrix를 위한 배열 선언
double inverse[3][3];//inverse matrix를 위한 배열 선언

int main(void) //main함수 시작
{
	inputmatrix(); //함수를 통한 original matrix 입력받기
	detmat = finddev(); //입력받은 matrix의 행렬값을 finddev함수로 계산 후 반환값을 detmat에 저장
	if (detmat == 0) //행렬값이 0이면
		cout << "The inverse matrix does not exist." << endl; //역행렬이 존재하지 않는다는 안내문 출력
	else {
		outputinverse(); //그 외의 경우 역행렬을 계산 후 출력
	}
	return 0; //0의 반환
} //main함수 종료

void inputmatrix(void) //Original Matrix를 입력받는 함수 시작
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cout << i + 1 << "행 " << j + 1 << "열 수 입력: ";
			cin >> original[i][j];
		}
	} //중첩 for문을 이용하여 차례대로 행렬의 숫자들을 입력받기
	cout << endl << "Original Matrix: " << endl;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cout << original[i][j] << " ";
		}cout << endl;
	} //입력 확인 및 역행렬과 비교를 위해 Original Matrix를 중첩 for문을 이용하여 출력

	return;
} //inputmatrix 함수 종료

void outputinverse(void) //inverse matrix를 계산하고 출력하는 함수 시작
{
	inverse[0][0] = static_cast<double>(original[1][1] * original[2][2] - original[1][2] * original[2][1]);
	inverse[1][0] = static_cast<double>(-(original[1][0] * original[2][2] - original[1][2] * original[2][0]));
	inverse[2][0] = static_cast<double>(original[1][0] * original[2][1] - original[1][1] * original[2][0]);
	inverse[0][1] = static_cast<double>(-(original[0][1] * original[2][2] - original[0][2] * original[2][1]));
	inverse[1][1] = static_cast<double>(original[0][0] * original[2][2] - original[0][2] * original[2][0]);
	inverse[2][1] = static_cast<double>(-(original[0][0] * original[2][1] - original[0][1] * original[2][0]));
	inverse[0][2] = static_cast<double>(original[0][1] * original[1][2] - original[0][2] * original[1][1]);
	inverse[1][2] = static_cast<double>(-(original[0][0] * original[1][2] - original[0][2] * original[1][0]));
	inverse[2][2] = static_cast<double>(original[0][0] * original[1][1] - original[0][1] * original[1][0]);
	//cofactor matrix를 구하고 transpose 한 상태, 그 과정에서 double로 형변환

	cout << "Inverse Matrix: " << endl;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cout << inverse[i][j] / detmat << " ";
		}
		cout << endl;
	}
	//계산을 통해 구한 transpose된 cofactor matrix를 행렬값으로 나누어 중첩 for문을 이용하여 출력
	return;
} //outputinverse 함수 종료

double finddev(void) //행렬값을 구하는 함수
{
	double dev = static_cast<double>((original[0][0] * ((original[1][1] * original[2][2]) - (original[1][2] * original[2][1]))) - (original[0][1] * ((original[1][0] * original[2][2]) - (original[1][2] * original[2][0]))) + (original[0][2] * ((original[1][0] * original[2][1]) - (original[1][1] * original[2][0]))));
	//original matrix의 값들을 이용하여 행렬값을 구하고, double로 형변환

	return dev; //행렬값을 반환
} //finddev함수 종료
