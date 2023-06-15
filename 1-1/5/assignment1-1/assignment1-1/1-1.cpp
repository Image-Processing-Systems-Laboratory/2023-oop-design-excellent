#include <iostream> //iostream 선언
#include <cmath> //cmath 선언
using namespace std; //namespace std 선언
char triangle[384][768]; //삼각형 출력을 위한 배열 선언(가로 2X368칸, 세로 368칸)
void basictriangle(int y, int x); //가장 작은 삼각형을 위한 함수 선언
void getposition(int y, int x, int size); //알맞은 꼭짓점에 맞게 들어가는 재귀함수 선언
void printarr(int size); //삼각형을 위한 배열 출력 함수 선언
void resetarr(int size); //삼각형을 위한 배열 초기화 함수 선언

int main() //main함수의 시작
{
	unsigned char k; //unsigned char형 변수 선언
	cout << "Input: ";
	cin >> k; //안내문 출력 후 k 입력받기
	int K = k - 48; //연산을 위해 unsigned char형 k값에서 48을 빼 정수형 K로 저장
	int n = pow(2,K - 1); //N의 값을 pow함수를 이용하여 구하기
	resetarr(3 * n); //3n의 값을 resetarr함수에 전달하여 배열에 공백문자 넣기
	
	getposition(0, 3 * n, 3 * n); //3n 높이만큼의 제일 큰 삼각형을 기준으로 작은 단위로 쪼개는 함수 실행
	
	printarr(3 * n); //배열의 저장된 값을 출력하여 원하는 모양의 삼각형 만들기

	return 0; //0의 반환
}

void basictriangle(int y, int x) //가장 작은 단위의 삼각형을 만드는 함수
{
	triangle[y][x] = '$';

	triangle[y + 1][x + 1] = '$';
	triangle[y + 1][x - 1] = '$';

	triangle[y + 2][x - 2] = '$';
	triangle[y + 2][x - 1] = '$';
	triangle[y + 2][x] = '$';
	triangle[y + 2][x + 1] = '$';
	triangle[y + 2][x + 2] = '$';
	
	return;
} //basictriangle 함수 종료

void getposition(int y, int x, int size) //가장 큰 삼각형을 기준으로 가장 작은 단위의 삼각형까지 쪼개는 함수
{
	if (size == 3) //가장 작은 단위가 되었을 때
	{
		basictriangle(y, x); //basictriangle을 출력
		return;
	}
	getposition(y, x, size / 2); //세 부분으로 쪼갰을 때 윗 부분
	getposition(y + size / 2, x - size / 2, size / 2); //세 부분으로 쪼갰을 때 아래서 왼쪽 부분
	getposition(y + size / 2, x + size / 2, size / 2); //세 부분으로 쪼갰을 때 아래서 오른쪽 부분
} //getposition 함수 종료

void printarr(int size) //배열을 이용해 삼각형을 출력하기 위한 함수
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size*2; j++)
		{
			cout << triangle[i][j];
		}
		cout << endl;
	} //정해진 범위(세로는 size만큼, 가로는 2size만큼)에 맞게 배열을 출력한다.
	return;
} //printarr함수 종료

void resetarr(int size) //배열 전체에 공백을 넣어주는 함수
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size*2; j++)
		{
			triangle[i][j] = ' ';
		}
	} //정해진 범위(세로는 size만큼, 가로는 2size만큼)에 맞게 공백을 넣어준다. 초기화 개념
	return;
} //resetarr함수 종료

