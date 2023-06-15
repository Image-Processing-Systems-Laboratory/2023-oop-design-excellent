#include "NestedArray.h"

//생성자
NestedArray::NestedArray() {
	str[0] = '\0';
	array = 0;
	end = false;
}

//array에 값 저장
void NestedArray::setArray(NestedArray* array) {
	this->array = array;           //array에 값 저장
}

//str에 값 저장
void NestedArray::setStr(char* str) {
	int i = 0;

	while (1) {
		this->str[i] = str[i];    //값 복사

		if (str[i] == '\0') {
			break;                //문자열의 끝에 도달할 경우 반복 종료
		}

		i++;
	}
}

//배열의 마지막임을 표시
void NestedArray::setEnd(void) {
	end = true;                //end에 true 저장
}

//array 값 반환
NestedArray* NestedArray::getArray(void) {
	return array;              //array 값 반환
}

//str 값 반환
char* NestedArray::getStr(void) {
	return str;                //str 값 반환
}

//end 값 반환
bool NestedArray::getEnd(void) {
	return end;                //end 값 반환
}