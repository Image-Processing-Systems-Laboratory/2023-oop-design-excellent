#include "CSVLoader.h"
#include <iostream>

using namespace std;

int main(void) {
	CSVLoader csv;     //CSVLoader 클래스의 객체 생성

	cout << "행의 수: " << csv.getRows() << endl; //rows 출력
	cout << "열의 수: " << csv.getCols() << endl; //cols 출력

	cout << endl << "data:" << endl;
	csv.print();           //data 모두 출력

	cout << endl << "data[0][0]:" << endl;
	cout << csv.getData()[0][0];      //data[0][0] 출력

	return 0;
}