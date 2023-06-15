#include"CSVLoader.h"
using namespace std;

int main()
{
	char filename[20] = {};    // 사용자에게 parse 할 파일의 이름을 입력 받음
	cin >> filename;
	CSVLoader load;               // 클래스 선언
	load.parse(filename);         // 사용자가 원하는 파일을 구문분석함
	load.print();                 // 구문분석 한 파일을 출력함
	cout << load.getRows() << ' ' << load.getCols() << endl;  // 구문 분석한 파일의 행과 열 출력
}