#include "MyString.h"

MyString::MyString() : text(nullptr), size(0) {

}

MyString::MyString(const char* str) : MyString::MyString() {
	// size 정하기
	const char* ptr = str;
	while (*ptr++) {
		size++;
	}
	// 동적 할당 및 복사
	ptr = str;
	text = new char[size+1];		// NUL 할당
	for (size_t i = 0; i < size; i++) {
		text[i] = str[i];
	}
	text[size] = '\0';
}

MyString::~MyString() {
	if (text == nullptr) {
		return;
	}
	//std::cout << text << " 삭제" << std::endl;
	delete[] text;
}
// index
char& MyString::operator[](size_t idx) {
	if (idx >= size) {
		return text[idx % size];		// 예외 처리
	}
	return text[idx];
}
// ==
bool MyString::operator==(const MyString& other) const {
	if (this->size != other.size)		// size 검사
		return false;
	for (size_t idx = 0; idx < size; idx++) {		// 문자 검사
		if (this->text[idx] != other.text[idx])
			return false;
	}
	return true;
}


bool MyString::operator==(const char* str) const {
	const char* ptr = str;
	for (size_t idx = 0; idx < size; idx++) {
		if (this->text[idx] != str[idx] || !str[idx])
			return false;
	}
	if (str[size] != '\0')	// 비교할 문자가 더 길다면 false
		return false;
	return true;
}
// !=
bool MyString::operator!=(const MyString& other) const {
	return !(* this == other);
}
bool MyString::operator!=(const char* str) const {
	return !(*this == str);
}


// =
MyString& MyString::operator=(const char* str) {
	if (text != nullptr) {
		delete[] text;
	}
	// size 정하기
	const char* ptr = str;
	size = 0;
	while (*ptr++) {
		size++;
	}
	// 동적 할당 및 복사
	ptr = str;
	text = new char[size + 1];    // NUL 할당
	for (size_t i = 0; i < size; i++) {
		text[i] = str[i];
	}
	text[size] = '\0';
	return *this;
}

MyString& MyString::operator=(const MyString& other) {
	if (text != nullptr) {
		delete[] text;
	}
	size = other.size;
	text = new char[size + 1];    // NUL 할당
	for (size_t i = 0; i < size; i++) {
		text[i] = other.text[i];
	}
	text[size] = '\0';
	return *this;
}

// 출력 연산자 오버로딩
std::ostream& operator<<(std::ostream& os, const MyString& obj) {
	if (obj.text == nullptr) {		// nul만 있을 경우
		return os;
	}
	os << obj.text;
	return os;
}

// 입력 연산자 오버로딩
std::istream& operator>>(std::istream& is, MyString& obj) {
	size_t max = 10000;
	char* temp = new char[max];
	std::cin >> temp;
	//is.getline(temp, max)	라인 입력 코드
	obj = temp;
	delete[] temp;
	return is;
}

// 변환
const char* MyString::c_str() const {	// 바로 참조하면 string이 삭제됬을 때 문제 생길 수 있음
	return this->text;
}


