#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include"oopstd.h"

namespace oopstd {
	string::string() {//생성자
		s = NULL;
		len = 0;
	}

	string::string(const char* str) {//문자열 생성자
		int j = 0;
		while (str[j] != '\0')//str 길이 탐색
			j++;
		len = j;
		s = new char[len];//동적 할당

		for (int i = 0; i < len; i++)//s에 저장
			s[i] = str[i];
	}

	string::string(const string& str) {//복사 생성자
		len = str.len;//길이 설정
		s = new char[len + 1];//동적 할당

		strcpy(s, str.s);//복사
	}

	string::~string() {//소멸자
		delete s;
	}

	string& string::assign(const string& str) {//스트링에 새로운 값 저장, 기존 값으로부터의 변경
		if (str.len > len) {//변경할 값이 더 길면 새로 동적할당 해줘야 함
			delete[] s;
			s = new char[str.len];
		}
		for (int i = 0; i < str.len; i++)//새로운 값 s에 저장
			s[i] = str.s[i];
		len = str.len;//길이 저장
		return *this;//s 반환
	}

	char& string::at(size_t pos) {//특정 위치 문자 탐색
		if (pos >= len || len < 0)//예외처리
			throw std::out_of_range("string::at() out of range");
		else
			return s[pos];//해당 위치 문자 반환
	}

	const char* string::c_str() const {//string->char 변환
		char* result = new char[len + 1];//char로 동적할당
		for (int i = 0; i < len; i++)//복사
			result[i] = s[i];
		result[len] = '\0';//NULL 문자 삽입

		return result;//문자열 반환
	}

	void string::clear() {//초기화
		s = 0;
		len = 0;
	}

	void string::push_back(char c) {//문자열 뒤에 문자 추가 삽입
		len++;
		char* string = new char[len+1];//크기를 증가시켜 할당
		for (int i = 0; i < len - 1; i++)//기존 문자열 복사
			string[i] = s[i];
		string[len - 1] = c;//문자 삽입
		string[len] = '\0';//NULL 문자 삽입
		s = string;//s에 복사
	}

	int string::compare(const string& str) const {//문자열 비교
		int a = str.len;
		int min;
		if (a <= len)
			min = a;
		else
			min = len;
		for (int i = 0; i < min; i++) {
			if (s[i] > str.s[i])
				return 1;//s가 더 큼
			else if (s[i] < str.s[i])
				return -1;//str이 더 큼
		}
		if (len == str.len)
			return 0;//동일
		else if (len > str.len)
			return 1;//s가 더 긺
	}

	string& string::replace(size_t pose, size_t len, const string& str) {//특정 위치에서 문자열 교체
		string a;
		for (int i = 0; i < pose; i++)
			a.push_back(s[i]);//앞 복사
		const char* b = str.c_str();
		for (int i = 0; i < strlen(b); i++)
			a.push_back(b[i]);//중간 삽입
		for (int i = pose + len; i < this->len; i++)
			a.push_back(s[i]);//뒤 복사
		const char* z = a.c_str();
		delete s;
		s = new char[this->len - len + strlen(b) + 1];//새로운 길이로 동적할당
		this->len = strlen(z);
		for (int i = 0; i < this->len; i++)
			s[i] = z[i];//s 복사

		return *this;//s 반환
	}

	string string::substr(size_t pos, size_t len) const {//특정 위치 문자열 잘라서 반환
		string a;//string 선언
		for (int i = pos; i < len+1; i++)
			a.push_back(s[i]);//자를 문자열만 저장
		return a;
	}

	size_t string::find(const string& str) const {//특정 문자 검색
		int i, j;
		if (str.len == 0)
			return -1;//검색할 문자가 없음
		for (i = 0; i <= len - str.len; i++) {//처음부터 검색
			for (j = 0; j < str.len; j++) {
				if (s[i + j] != str.s[j])
					break;//동일하지 않으면 for문 탈출
			}
			if (j == str.len)
				return i;//break 안했을 경우 동일 문자 존재
		}
		return -1;//찾지 못할 경우
	}

	int stoi(const string& str, size_t* idx, int base) {//string->int
		int result = 0;
		bool negative = false;
		int index = 0;

		const char* string = str.c_str();//string->char
		if (string[0] == '-') {//음수인지 확인
			negative = true;
			index++;
		}

		for (size_t i = index; i < strlen(string); i++) {
			if (string[i] >= '0' && string[i] <= '9') {//숫자일 경우
				int num = string[i] - '0';//정수형 변수에 저장
				result = result * base + num;//자릿수 올려주기
			}
			else {//숫자가 아닐 경우 해당 인덱스 저장
				*idx = i;
				break;
			}
		}
		if (negative == true)
			result *= -1;//음수일 때 -1 곱해주기
		return result;
	}

	float stof(const string& str, size_t* idx) {//string->float
		float result = 0.0;
		bool negative = false;
		bool decimal_found = false;
		float decimal_place = 1.0;
		int index = 0;
		const char* string = str.c_str();//string->char

		if (string[0] == '-') {//음수인지 확인
			negative = true;
			index++;
		}

		for (size_t i = index; i < strlen(string); i++) {
			if (string[i] >= '0' && string[i] <= '9') {//숫자일 때
				float num = string[i] - '0';//저장

				if (decimal_found == false)//정수 부분일 때
					result = result * 10.0 + num;//자릿수 올려주기
				else {//소수 부분일 때
					decimal_place *= 10.0;
					result += num / decimal_place;//나눠주기
				}
			}
			else if (string[i]=='.') {//소수점일 때
				decimal_found = true;
			}
			else {//숫자 아닐 때 해당 인덱스 저장
				*idx = i;
				break;
			}
		}
		if (negative == true)
			result *= -1.0;//음수일 때 -1 곱해주기
		return result;
	}

	string to_string(int val) {//int->string
		string result = "";
		bool negative = false;

		if (val < 0) {//음수일 때
			negative = true;
			val *= -1;
		}
		int cnt = 0;
		int val_c = val;
		while (val > 0) {
			int a = val % 10;//1의 자리 수부터 저장
			result.push_back(a + '0');//string에 저장
			val = val / 10;//다음 자리 탐색 준비
			cnt++;
		}
		cnt--;//cnt=자릿수
		if (negative == true)
			result.push_back('-');//음수일 때
		if (val_c == 0)
			result = "0";
		string result_rev = "";
		//현재 result는 숫자가 반대로 저장되어 있음
		while (cnt!=-1) {
			result_rev.push_back(result.at(cnt));//역수로 저장
			cnt--;
		}

		return result_rev;
	}

	string to_string(float val) {//float->string
		string result = "";
		bool negative = false;
		float a = 10.0;

		if (val < 0) {//음수일 때
			negative = true;
			result.push_back('-');//- 기호 저장
			val *= -1;
		}
		int integer = (int)val;
		string int_str = to_string(integer);//정수부분 저장
		const char* int_str_copy = int_str.c_str();
		for(int i=0;i<strlen(int_str_copy);i++)
			result.push_back(int_str_copy[i]);//정수값 저장됨

		double decimal = val - (float)integer;//소수부분
		result.push_back('.');//소수점 저장

		float num1 = decimal * a;
		while (num1 != 0) {//while문 돌면서 각 소수자리 string에 저장
			int num2 = (int)num1;
			result.push_back(num2 + '0');
			num1 = (num1 - (float)num2) * a;
		}
		return result;
	}
}