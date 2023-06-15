#include "Mstring.h"
#define initial_capacity 128

void copy(char* This, const char* obj, size_t max) {	// nul 까지 복사할거면 len + 1 해야 함
	size_t i = 0;
	for (i = 0; i<max; i++ ) {
		This[i] = obj[i];
	}
}


// 기본
void Mstring::resize()
{
	capacity *= 2;
	char* temp = new char[capacity*2+1];
	temp[capacity * 2] = '\0';
	copy(temp, data, capacity);
	delete[] data;
	data = temp;
}

Mstring::Mstring() : capacity(initial_capacity), len(0) {
	data = new char[capacity+1];
	data[capacity] = '\0';
};

Mstring::Mstring(const char* str) : Mstring::Mstring() {
	const char* ptr = str;
	while (*ptr) {
		if (capacity* 0.40 <= len) {
			resize();
		}
		data[len] = *ptr++;
		len++;
	}
	data[len] = '\0';
}

Mstring::Mstring(const Mstring& other) : capacity(other.capacity), len(other.len) {
	data = new char[capacity + 1];
	data[capacity] = '\0';
	copy(data, other.data, len + 1);
}

Mstring::~Mstring() {
	if (data != nullptr) {
		delete[] data;
	}
}

// copy
Mstring& Mstring::operator=(const char* str) {
	init();
	const char* ptr = str;
	while (*ptr) {
		if (capacity * 0.40 <= len) {
			resize();
		}
		data[len] = *ptr++;
		len++;
	}
	data[len] = '\0';
	return *this;
}

Mstring& Mstring::operator=(Mstring& other) {
	*this = other.data;
	return *this;
}

// iostream
std::ostream& operator<<(std::ostream& os, const Mstring& str) {
	os << str.data;
	return os;
}

std::istream& operator>>(std::istream& is, Mstring& str) {
	char* buff = new char[10000];
	is >> buff;
	str = buff;
	delete[] buff;
	return is;
}

// []index
char& Mstring::operator[](size_t idx) {
	return data[idx];
}

char& Mstring::operator[](size_t idx) const {
	return data[idx];
}
// == & !=
bool Mstring::operator==(const Mstring& other) const {
	if (size() != other.size())
		return false;
	for (size_t i = 0; i < size(); i++) {
		if ((*this)[i] != other[i])
			return false;
	}
	return true;
}

bool Mstring::operator==(const char* other) const {
	for (size_t i = 0; i < size() + 1; i++) {		// nul까지 검사
		if ((*this)[i] != other[i])
			return false;
	}
	return true;
}

bool Mstring::operator!=(const Mstring& other) const{
	return !(*this == other);
}
bool Mstring::operator!=(const char* other) const{
	return !(*this == other);
}









/// 기타
void Mstring::init()
{
	if (data != nullptr)
		delete[] data;
	capacity = initial_capacity;
	data = new char[capacity + 1];
	data[capacity] = '\0';
	len = 0;
	return;
}


size_t Mstring::size() const
{
	return len;
}
