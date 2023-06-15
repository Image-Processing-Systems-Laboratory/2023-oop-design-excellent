#include "str.h"

using namespace oopstd;

string::string() {
	s = new char;
	*s = NULL;
	len = 0;
}
string::string(const char* s) {
	len = strlen(s);
	this->s = new char[len + 1];
	strcpy(this->s, s);
}
string::string(const string& str) {
	len = str.len;
	if (len > 0){
		s = new char[len + 1];
		strcpy(s, str.s);
	}
	else {
		s = nullptr;
	}
}
string::~string() {
	if (s)
		delete[] s;
}

string& string::assign(const string& str) {
	if (s)
		delete[] s;
	len = str.len;
	s = new char[len + 1];
	strcpy(s, str.s);
	
	return *this;
}
char& string::at(size_t pos) {
	return s[pos];
}
const char* string::c_str() const {
	return s;
}
void string::clear() {
	delete[] s;
	s = new char;
	*s = NULL;
	len = 0;
}
void string::push_back(char c) {
	len++; // 문자열의 길이를 1 늘리기
	char* tmp = new char[len + 1]; // 길이를 늘린 문자열을 새로 동적할당
	strcpy(tmp, s); // s 복사
	tmp[len - 1] = c; // 문자열s 뒤에 문자 c 복사
	tmp[len] = NULL; // null문자 삽입
	delete[] s; // 원래 있던 문자열 삭제
	s = tmp;
}
int string::compare(const string* str) const {
	return strcmp(s, str->s);
}
string& string::replace(size_t pose, size_t len, const string* str) {
	/* 시작 인덱스가 범위를 벗어나면*/
	if (pose > this->len) {
		return *this;
	}
	/* 새로 만들어질 문자열의 길이*/
	if (pose + len < strlen(s))
		this->len = this->len - len + str->len;
	else
		this->len = this->len - pose + str->len;
	char* tmp = new char[this->len + 1]; // 새로 만들어질 문자열 동적할당
	
	strncpy(tmp, s, pose);
	strcpy(tmp + pose, str->s);
	if(pose + len < strlen(s)) // 원래 함수에 문자가 더 남아있는 경우
		strcat(tmp, s + pose + len);
	delete[]s; // 원래 문자열 삭제
	s = tmp;
	
	return *this;
}
string string::substr(size_t pos, size_t len) const {
	string str;
	/* pos가 문자열 s의 널문자를 가리킬 경우*/
	if (pos >= this->len)
		return str; // 비어있는 str 반환
;
	size_t Len = 0; // 새로 만들어질 문자열의 길이
	/* pos 인덱스부터 len길이만큼 문자열 s를 비교*/
	for (size_t i = pos; i < pos + len; i++) {
		if (!s[i]) // len 길이만큼 가기 전에 문자열 s가 끝난다면
			break;
		Len++;
	}
	char* tmp = new char[Len + 1]; // s에서 추출한 문자열을 복사할 공간 동적할당
	for (size_t i = 0; i < Len; i++) {
		tmp[i] = s[pos + i];
	}
	tmp[Len] = NULL;
	string str2(tmp);
	delete[]tmp;
	return str2;
}
size_t string::find(const string& str, size_t pos) const {
	size_t idx = pos;
	size_t Len = strlen(str.s);
	char* walker = s + pos; // str문자열의 pos 인덱스 주소
	while (idx<len) {
		if(!strncmp(walker, str.s, Len))
			break;
		walker++;
		idx++;
	}
	if (idx == len)
		return -1; //string::npos 대신 -1 반환
	else
		return idx;
}

int oopstd::stoi(const string& str, size_t* idx, int base) {
	int num = 0;
	int sign = 1;
	const char* s = str.c_str();

	size_t i = 0;
	while ((9 <= s[i] && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-') {
		i++;
		sign = -sign;
	}
	/* white space와 부호 제외 가장 첫 문자가 숫자가 아닌 경우*/
	if (s[i] < '0' || '9' < s[i])
		return -1;
	while ('0' <= s[i] && s[i] <= '9') {
		num *= 10;
		num += s[i] - '0';
		i++;
	}
	if (idx)
		*idx = i;
	return sign*num;
}

float oopstd::stof(const string& str, size_t* idx) {
	float num = 0; // 실수
	int sign = 1; // 부호
	int integer = 0; // 정수부분
	int demical = 0; // 소수부분
	int exponent = 0; // 지수부분

	const char* s = str.c_str();

	size_t i = 0;
	while ((9 <= s[i] && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-') {
		i++;
		sign = -sign;
	}
	/* white space와 부호 제외 가장 첫 문자가 숫자가 아닌 경우*/
	if (s[i] < '0' || '9' < s[i])
		return -1;
	while ('0' <= s[i] && s[i] <= '9') {
		integer *= 10;
		integer += s[i] - '0';
		i++;
	}
	
	/* 정수부분 다음 '.'이 위치한다면 다음 문자 검사*/
	if (s[i] == '.') {
		i++;
		/* .다음에 숫자가 나오면 소수 demical에 저장*/
		while ('0' <= s[i] && s[i] <= '9') {
			demical *= 10;
			demical += s[i] - '0';
			i++;
		}
		/* .다음에 e나E가 나오면*/
		if (s[i] == 'e' || s[i] == 'E') {
			int sign = 1; // 지수부분의 부호
			i++;
			if (s[i] == '-') {
				sign = -sign;
				i++;
			}
			/* e나E 다음 숫자를 지수 exponent에 저장*/
			while ('0' <= s[i] && s[i] <= '9') {
				exponent *= 10;
				exponent += s[i] - '0';
				i++;
			}
			exponent *= sign;
		}
	}
	/* 정수부분 다음 e나E가 나온다면*/
	else if (s[i] == 'e' || s[i] == 'E') {
		int sign = 1; // 지수부분의 부호
		i++;
		if (s[i] == '-') {
			sign = -sign;
			i++;
		}
		/* e나E 다음 숫자를 지수 exponent에 저장*/
		while ('0' <= s[i] && s[i] <= '9') {
			exponent *= 10;
			exponent += s[i] - '0';
			i++;
		}
		exponent *= sign;
	}
	/* num에 소수부분 먼저 더해주기*/
	while (demical > 0) {
		num += demical % 10;
		num /= 10;
		demical /= 10;
	}
	/* num에 정수부분 더해주기*/
	num += integer;

	/* 지수부분이 양수면 지수부분 크기만큼 10 곱해주기*/
	for (; exponent > 0; exponent--)
		num *= 10;
	/* 지수부분이 음수면 지수부분 크기만큼 10 나눠주기*/
	for (; exponent < 0; exponent++)
		num /= 10;

	if (idx)
		*idx = i;
	return sign * num; // 부호 고려
}

string oopstd::to_string(int val) {
	int len = 0; // val 길이
	int sign = 1;
	char* num;
	
	/* val이 0이면*/
	if (val == 0) {
		num = new char[2];
		num[0] = '0';
		num[1] = NULL;
	}
	/* val이 0이 아니면*/
	else {
		/* val이 음수면*/
		if (val < 0) {
			val = -val;
			sign = -sign;
			len++;
		}
		/* val 자릿수 계산*/
		for (int v = val; v; v /= 10)
			len++;
		/* 정수 자릿수 크기만큼의 배열 할당(null 포함)*/
		num = new char[len + 1];
		num[len] = NULL;
		for (int i = len - 1; i >= 0; i--) {
			num[i] = val % 10 + '0';
			val /= 10;
		}
		/* val이 음수라면 num[0]에 '0'이 저장됐을 것이고 이를 '-'로 바꿔준다.*/
		if (sign == -1)
			num[0] = '-';
	}
	string tmp(num);
	delete[]num;
	return tmp;
}
string oopstd::to_string(float val) {
	int integer; // 정수부분
	float demical;// 소수부분
	int sign = 1; // 부호
	char* num;
	int ilen = 0; // 정수부분 길이
	int dlen = 0; // 소수부분 길이
	
	/* val이 0이면*/
	if (val == 0) {
		num = new char[9];
		num[0] = '0';
		num[1] = '.';
		for (int i = 2; i < 8; i++)
			num[i] = '0';
		num[8] = NULL;
	}
	/* val이 0이 아니면*/
	else {
		/* val이 음수면*/
		if (val < 0) {
			val = -val;
			sign = -sign;
		}
		integer = val;
		demical = val - integer;
		/* val 정수부분 자리수 계산*/
		for (int v = integer; v; v /= 10)
			ilen++;
\
		/* 배열 동적할당 후 적절한 수 저장*/
		if (sign == 1) { // 양수일 떄
			/* len은 실수 전체 길이*/
			int len = ilen + 6 + 1; // 소수점 문자 길이 1 고려, to_string은 소수점 아래 6자리까지만 출력함
			num = new char[len + 1]; // 실수 길이만큼 동적할당
			num[len] = NULL; // null문자 저장
			/* 정수부분 저장*/
			for (int i = ilen - 1; i >= 0; i--) {
				num[i] = integer % 10 + '0';
				integer /= 10;
			}
			num[ilen] = '.'; // 소수점 저장
			/* 실수 부분 저장*/
			for (int i = ilen + 1; i < len; i++) {
				demical *= 10;
				integer = demical;
				demical -= integer;
				num[i] = integer + '0';
			}
		}
		else { // 음수일 떄
			/* len은 실수 전체 길이*/
			int len = ilen + 6 + 1 + 1; // 소수점 문자 길이 1, 부호 길이 1 고려, to_string은 소수점 아래 6자리까지만 출력함
			num = new char[len + 1];
			num[0] = '-';
			num[len] = NULL;
			for (int i = ilen; i > 0; i--) {
				num[i] = integer % 10 + '0';
				integer /= 10;
			}
			num[ilen + 1] = '.';
			for (int i = ilen + 2; i < len; i++) {
				demical *= 10;
				integer = demical;
				demical -= integer;
				num[i] = integer + '0';
			}
		}
	}
	
	string tmp(num);
	delete[]num;
	return tmp;
}