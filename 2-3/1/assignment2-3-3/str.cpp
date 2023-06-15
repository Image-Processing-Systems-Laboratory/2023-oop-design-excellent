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
	len++; // ���ڿ��� ���̸� 1 �ø���
	char* tmp = new char[len + 1]; // ���̸� �ø� ���ڿ��� ���� �����Ҵ�
	strcpy(tmp, s); // s ����
	tmp[len - 1] = c; // ���ڿ�s �ڿ� ���� c ����
	tmp[len] = NULL; // null���� ����
	delete[] s; // ���� �ִ� ���ڿ� ����
	s = tmp;
}
int string::compare(const string* str) const {
	return strcmp(s, str->s);
}
string& string::replace(size_t pose, size_t len, const string* str) {
	/* ���� �ε����� ������ �����*/
	if (pose > this->len) {
		return *this;
	}
	/* ���� ������� ���ڿ��� ����*/
	if (pose + len < strlen(s))
		this->len = this->len - len + str->len;
	else
		this->len = this->len - pose + str->len;
	char* tmp = new char[this->len + 1]; // ���� ������� ���ڿ� �����Ҵ�
	
	strncpy(tmp, s, pose);
	strcpy(tmp + pose, str->s);
	if(pose + len < strlen(s)) // ���� �Լ��� ���ڰ� �� �����ִ� ���
		strcat(tmp, s + pose + len);
	delete[]s; // ���� ���ڿ� ����
	s = tmp;
	
	return *this;
}
string string::substr(size_t pos, size_t len) const {
	string str;
	/* pos�� ���ڿ� s�� �ι��ڸ� ����ų ���*/
	if (pos >= this->len)
		return str; // ����ִ� str ��ȯ
;
	size_t Len = 0; // ���� ������� ���ڿ��� ����
	/* pos �ε������� len���̸�ŭ ���ڿ� s�� ��*/
	for (size_t i = pos; i < pos + len; i++) {
		if (!s[i]) // len ���̸�ŭ ���� ���� ���ڿ� s�� �����ٸ�
			break;
		Len++;
	}
	char* tmp = new char[Len + 1]; // s���� ������ ���ڿ��� ������ ���� �����Ҵ�
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
	char* walker = s + pos; // str���ڿ��� pos �ε��� �ּ�
	while (idx<len) {
		if(!strncmp(walker, str.s, Len))
			break;
		walker++;
		idx++;
	}
	if (idx == len)
		return -1; //string::npos ��� -1 ��ȯ
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
	/* white space�� ��ȣ ���� ���� ù ���ڰ� ���ڰ� �ƴ� ���*/
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
	float num = 0; // �Ǽ�
	int sign = 1; // ��ȣ
	int integer = 0; // �����κ�
	int demical = 0; // �Ҽ��κ�
	int exponent = 0; // �����κ�

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
	/* white space�� ��ȣ ���� ���� ù ���ڰ� ���ڰ� �ƴ� ���*/
	if (s[i] < '0' || '9' < s[i])
		return -1;
	while ('0' <= s[i] && s[i] <= '9') {
		integer *= 10;
		integer += s[i] - '0';
		i++;
	}
	
	/* �����κ� ���� '.'�� ��ġ�Ѵٸ� ���� ���� �˻�*/
	if (s[i] == '.') {
		i++;
		/* .������ ���ڰ� ������ �Ҽ� demical�� ����*/
		while ('0' <= s[i] && s[i] <= '9') {
			demical *= 10;
			demical += s[i] - '0';
			i++;
		}
		/* .������ e��E�� ������*/
		if (s[i] == 'e' || s[i] == 'E') {
			int sign = 1; // �����κ��� ��ȣ
			i++;
			if (s[i] == '-') {
				sign = -sign;
				i++;
			}
			/* e��E ���� ���ڸ� ���� exponent�� ����*/
			while ('0' <= s[i] && s[i] <= '9') {
				exponent *= 10;
				exponent += s[i] - '0';
				i++;
			}
			exponent *= sign;
		}
	}
	/* �����κ� ���� e��E�� ���´ٸ�*/
	else if (s[i] == 'e' || s[i] == 'E') {
		int sign = 1; // �����κ��� ��ȣ
		i++;
		if (s[i] == '-') {
			sign = -sign;
			i++;
		}
		/* e��E ���� ���ڸ� ���� exponent�� ����*/
		while ('0' <= s[i] && s[i] <= '9') {
			exponent *= 10;
			exponent += s[i] - '0';
			i++;
		}
		exponent *= sign;
	}
	/* num�� �Ҽ��κ� ���� �����ֱ�*/
	while (demical > 0) {
		num += demical % 10;
		num /= 10;
		demical /= 10;
	}
	/* num�� �����κ� �����ֱ�*/
	num += integer;

	/* �����κ��� ����� �����κ� ũ�⸸ŭ 10 �����ֱ�*/
	for (; exponent > 0; exponent--)
		num *= 10;
	/* �����κ��� ������ �����κ� ũ�⸸ŭ 10 �����ֱ�*/
	for (; exponent < 0; exponent++)
		num /= 10;

	if (idx)
		*idx = i;
	return sign * num; // ��ȣ ���
}

string oopstd::to_string(int val) {
	int len = 0; // val ����
	int sign = 1;
	char* num;
	
	/* val�� 0�̸�*/
	if (val == 0) {
		num = new char[2];
		num[0] = '0';
		num[1] = NULL;
	}
	/* val�� 0�� �ƴϸ�*/
	else {
		/* val�� ������*/
		if (val < 0) {
			val = -val;
			sign = -sign;
			len++;
		}
		/* val �ڸ��� ���*/
		for (int v = val; v; v /= 10)
			len++;
		/* ���� �ڸ��� ũ�⸸ŭ�� �迭 �Ҵ�(null ����)*/
		num = new char[len + 1];
		num[len] = NULL;
		for (int i = len - 1; i >= 0; i--) {
			num[i] = val % 10 + '0';
			val /= 10;
		}
		/* val�� ������� num[0]�� '0'�� ������� ���̰� �̸� '-'�� �ٲ��ش�.*/
		if (sign == -1)
			num[0] = '-';
	}
	string tmp(num);
	delete[]num;
	return tmp;
}
string oopstd::to_string(float val) {
	int integer; // �����κ�
	float demical;// �Ҽ��κ�
	int sign = 1; // ��ȣ
	char* num;
	int ilen = 0; // �����κ� ����
	int dlen = 0; // �Ҽ��κ� ����
	
	/* val�� 0�̸�*/
	if (val == 0) {
		num = new char[9];
		num[0] = '0';
		num[1] = '.';
		for (int i = 2; i < 8; i++)
			num[i] = '0';
		num[8] = NULL;
	}
	/* val�� 0�� �ƴϸ�*/
	else {
		/* val�� ������*/
		if (val < 0) {
			val = -val;
			sign = -sign;
		}
		integer = val;
		demical = val - integer;
		/* val �����κ� �ڸ��� ���*/
		for (int v = integer; v; v /= 10)
			ilen++;
\
		/* �迭 �����Ҵ� �� ������ �� ����*/
		if (sign == 1) { // ����� ��
			/* len�� �Ǽ� ��ü ����*/
			int len = ilen + 6 + 1; // �Ҽ��� ���� ���� 1 ���, to_string�� �Ҽ��� �Ʒ� 6�ڸ������� �����
			num = new char[len + 1]; // �Ǽ� ���̸�ŭ �����Ҵ�
			num[len] = NULL; // null���� ����
			/* �����κ� ����*/
			for (int i = ilen - 1; i >= 0; i--) {
				num[i] = integer % 10 + '0';
				integer /= 10;
			}
			num[ilen] = '.'; // �Ҽ��� ����
			/* �Ǽ� �κ� ����*/
			for (int i = ilen + 1; i < len; i++) {
				demical *= 10;
				integer = demical;
				demical -= integer;
				num[i] = integer + '0';
			}
		}
		else { // ������ ��
			/* len�� �Ǽ� ��ü ����*/
			int len = ilen + 6 + 1 + 1; // �Ҽ��� ���� ���� 1, ��ȣ ���� 1 ���, to_string�� �Ҽ��� �Ʒ� 6�ڸ������� �����
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