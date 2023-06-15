#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include"oopstd.h"

namespace oopstd {
	string::string() {//������
		s = NULL;
		len = 0;
	}

	string::string(const char* str) {//���ڿ� ������
		int j = 0;
		while (str[j] != '\0')//str ���� Ž��
			j++;
		len = j;
		s = new char[len];//���� �Ҵ�

		for (int i = 0; i < len; i++)//s�� ����
			s[i] = str[i];
	}

	string::string(const string& str) {//���� ������
		len = str.len;//���� ����
		s = new char[len + 1];//���� �Ҵ�

		strcpy(s, str.s);//����
	}

	string::~string() {//�Ҹ���
		delete s;
	}

	string& string::assign(const string& str) {//��Ʈ���� ���ο� �� ����, ���� �����κ����� ����
		if (str.len > len) {//������ ���� �� ��� ���� �����Ҵ� ����� ��
			delete[] s;
			s = new char[str.len];
		}
		for (int i = 0; i < str.len; i++)//���ο� �� s�� ����
			s[i] = str.s[i];
		len = str.len;//���� ����
		return *this;//s ��ȯ
	}

	char& string::at(size_t pos) {//Ư�� ��ġ ���� Ž��
		if (pos >= len || len < 0)//����ó��
			throw std::out_of_range("string::at() out of range");
		else
			return s[pos];//�ش� ��ġ ���� ��ȯ
	}

	const char* string::c_str() const {//string->char ��ȯ
		char* result = new char[len + 1];//char�� �����Ҵ�
		for (int i = 0; i < len; i++)//����
			result[i] = s[i];
		result[len] = '\0';//NULL ���� ����

		return result;//���ڿ� ��ȯ
	}

	void string::clear() {//�ʱ�ȭ
		s = 0;
		len = 0;
	}

	void string::push_back(char c) {//���ڿ� �ڿ� ���� �߰� ����
		len++;
		char* string = new char[len+1];//ũ�⸦ �������� �Ҵ�
		for (int i = 0; i < len - 1; i++)//���� ���ڿ� ����
			string[i] = s[i];
		string[len - 1] = c;//���� ����
		string[len] = '\0';//NULL ���� ����
		s = string;//s�� ����
	}

	int string::compare(const string& str) const {//���ڿ� ��
		int a = str.len;
		int min;
		if (a <= len)
			min = a;
		else
			min = len;
		for (int i = 0; i < min; i++) {
			if (s[i] > str.s[i])
				return 1;//s�� �� ŭ
			else if (s[i] < str.s[i])
				return -1;//str�� �� ŭ
		}
		if (len == str.len)
			return 0;//����
		else if (len > str.len)
			return 1;//s�� �� ��
	}

	string& string::replace(size_t pose, size_t len, const string& str) {//Ư�� ��ġ���� ���ڿ� ��ü
		string a;
		for (int i = 0; i < pose; i++)
			a.push_back(s[i]);//�� ����
		const char* b = str.c_str();
		for (int i = 0; i < strlen(b); i++)
			a.push_back(b[i]);//�߰� ����
		for (int i = pose + len; i < this->len; i++)
			a.push_back(s[i]);//�� ����
		const char* z = a.c_str();
		delete s;
		s = new char[this->len - len + strlen(b) + 1];//���ο� ���̷� �����Ҵ�
		this->len = strlen(z);
		for (int i = 0; i < this->len; i++)
			s[i] = z[i];//s ����

		return *this;//s ��ȯ
	}

	string string::substr(size_t pos, size_t len) const {//Ư�� ��ġ ���ڿ� �߶� ��ȯ
		string a;//string ����
		for (int i = pos; i < len+1; i++)
			a.push_back(s[i]);//�ڸ� ���ڿ��� ����
		return a;
	}

	size_t string::find(const string& str) const {//Ư�� ���� �˻�
		int i, j;
		if (str.len == 0)
			return -1;//�˻��� ���ڰ� ����
		for (i = 0; i <= len - str.len; i++) {//ó������ �˻�
			for (j = 0; j < str.len; j++) {
				if (s[i + j] != str.s[j])
					break;//�������� ������ for�� Ż��
			}
			if (j == str.len)
				return i;//break ������ ��� ���� ���� ����
		}
		return -1;//ã�� ���� ���
	}

	int stoi(const string& str, size_t* idx, int base) {//string->int
		int result = 0;
		bool negative = false;
		int index = 0;

		const char* string = str.c_str();//string->char
		if (string[0] == '-') {//�������� Ȯ��
			negative = true;
			index++;
		}

		for (size_t i = index; i < strlen(string); i++) {
			if (string[i] >= '0' && string[i] <= '9') {//������ ���
				int num = string[i] - '0';//������ ������ ����
				result = result * base + num;//�ڸ��� �÷��ֱ�
			}
			else {//���ڰ� �ƴ� ��� �ش� �ε��� ����
				*idx = i;
				break;
			}
		}
		if (negative == true)
			result *= -1;//������ �� -1 �����ֱ�
		return result;
	}

	float stof(const string& str, size_t* idx) {//string->float
		float result = 0.0;
		bool negative = false;
		bool decimal_found = false;
		float decimal_place = 1.0;
		int index = 0;
		const char* string = str.c_str();//string->char

		if (string[0] == '-') {//�������� Ȯ��
			negative = true;
			index++;
		}

		for (size_t i = index; i < strlen(string); i++) {
			if (string[i] >= '0' && string[i] <= '9') {//������ ��
				float num = string[i] - '0';//����

				if (decimal_found == false)//���� �κ��� ��
					result = result * 10.0 + num;//�ڸ��� �÷��ֱ�
				else {//�Ҽ� �κ��� ��
					decimal_place *= 10.0;
					result += num / decimal_place;//�����ֱ�
				}
			}
			else if (string[i]=='.') {//�Ҽ����� ��
				decimal_found = true;
			}
			else {//���� �ƴ� �� �ش� �ε��� ����
				*idx = i;
				break;
			}
		}
		if (negative == true)
			result *= -1.0;//������ �� -1 �����ֱ�
		return result;
	}

	string to_string(int val) {//int->string
		string result = "";
		bool negative = false;

		if (val < 0) {//������ ��
			negative = true;
			val *= -1;
		}
		int cnt = 0;
		int val_c = val;
		while (val > 0) {
			int a = val % 10;//1�� �ڸ� ������ ����
			result.push_back(a + '0');//string�� ����
			val = val / 10;//���� �ڸ� Ž�� �غ�
			cnt++;
		}
		cnt--;//cnt=�ڸ���
		if (negative == true)
			result.push_back('-');//������ ��
		if (val_c == 0)
			result = "0";
		string result_rev = "";
		//���� result�� ���ڰ� �ݴ�� ����Ǿ� ����
		while (cnt!=-1) {
			result_rev.push_back(result.at(cnt));//������ ����
			cnt--;
		}

		return result_rev;
	}

	string to_string(float val) {//float->string
		string result = "";
		bool negative = false;
		float a = 10.0;

		if (val < 0) {//������ ��
			negative = true;
			result.push_back('-');//- ��ȣ ����
			val *= -1;
		}
		int integer = (int)val;
		string int_str = to_string(integer);//�����κ� ����
		const char* int_str_copy = int_str.c_str();
		for(int i=0;i<strlen(int_str_copy);i++)
			result.push_back(int_str_copy[i]);//������ �����

		double decimal = val - (float)integer;//�Ҽ��κ�
		result.push_back('.');//�Ҽ��� ����

		float num1 = decimal * a;
		while (num1 != 0) {//while�� ���鼭 �� �Ҽ��ڸ� string�� ����
			int num2 = (int)num1;
			result.push_back(num2 + '0');
			num1 = (num1 - (float)num2) * a;
		}
		return result;
	}
}