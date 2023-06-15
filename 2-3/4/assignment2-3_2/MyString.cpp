#include "MyString.h"

MyString::MyString() : text(nullptr), length(0) {

}

MyString::MyString(const char* str) : MyString::MyString() {
	// length ���ϱ�
	const char* ptr = str;
	while (*ptr++) {
		length++;
	}
	// ���� �Ҵ� �� ����
	ptr = str;
	text = new char[length+1];		// NUL �Ҵ�
	for (size_t i = 0; i < length; i++) {
		text[i] = str[i];
	}
	text[length] = '\0';
}

MyString::~MyString() {
	if (text == nullptr) {
		return;
	}
	//std::cout << text << " ����" << std::endl;
	delete[] text;
}
// index
char& MyString::operator[](size_t idx) {
	if (idx >= length) {
		return text[idx % length];		// ���� ó��
	}
	return text[idx];
}
// ==
bool MyString::operator==(const MyString& other) const {
	if (this->length != other.length)		// length �˻�
		return false;
	for (size_t idx = 0; idx < length; idx++) {		// ���� �˻�
		if (this->text[idx] != other.text[idx])
			return false;
	}
	return true;
}


bool MyString::operator==(const char* str) const {
	const char* ptr = str;
	for (size_t idx = 0; idx < length; idx++) {
		if (this->text[idx] != str[idx] || !str[idx])
			return false;
	}
	if (str[length] != '\0')	// ���� ���ڰ� �� ��ٸ� false
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
	// length ���ϱ�
	const char* ptr = str;
	length = 0;
	while (*ptr++) {
		length++;
	}
	// ���� �Ҵ� �� ����
	ptr = str;
	text = new char[length + 1];    // NUL �Ҵ�
	for (size_t i = 0; i < length; i++) {
		text[i] = str[i];
	}
	text[length] = '\0';
	return *this;
}

MyString& MyString::operator=(const MyString& other) {
	if (text != nullptr) {
		delete[] text;
	}
	length = other.length;
	text = new char[length + 1];    // NUL �Ҵ�
	for (size_t i = 0; i < length; i++) {
		text[i] = other.text[i];
	}
	text[length] = '\0';
	return *this;
}

// ��� ������ �����ε�
std::ostream& operator<<(std::ostream& os, const MyString& obj) {
	if (obj.text == nullptr) {		// nul�� ���� ���
		return os;
	}
	os << obj.text;
	return os;
}

// �Է� ������ �����ε�
std::istream& operator>>(std::istream& is, MyString& obj) {
	size_t max = 10000;
	char* temp = new char[max];
	std::cin >> temp;
	//is.getline(temp, max)	���� �Է� �ڵ�
	obj = temp;
	delete[] temp;
	return is;
}

// ��ȯ
const char* MyString::c_str() const {	// �ٷ� �����ϸ� string�� �������� �� ���� ���� �� ����
	return this->text;
}




size_t MyString::size()
{
	return length;
}
