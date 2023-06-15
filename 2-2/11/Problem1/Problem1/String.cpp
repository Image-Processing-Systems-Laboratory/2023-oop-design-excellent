#include "Array.h"

//String class 의 정의부

//생성자
String::String(char* &input) {
	// 빈칸이나 , ] null 혹은 input의 문자 개수가 20을 넘기기 전까지 반복
	for (int i = 0; i < 20 && (*input != ' ' && *input != ',' && *input != ']') && *input; i++) {
		//차례로 저장
		str[i] = *(input++);
	}
}
//데이터 출력(문자열에는 인덱스가 필요 없다.)
void String::printData(int* index, int cnt) {
	printData();
}
//문자열을 저장했던 맴버 변수 반환
void String::printData() {
	cout << str;
}
