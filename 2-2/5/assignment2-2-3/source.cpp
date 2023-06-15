#include "csv.h"


int main() {

	char input_file[100] = { 0 };


	cout << "Enter name of file: ";
	cin >> input_file;

	csv object(input_file);// 객체 생성
	object.parse(input_file);// 파일로 부터 실수값을 읽어들어옴
	object.print();// 멤버변수에 저장된 값 출력



}