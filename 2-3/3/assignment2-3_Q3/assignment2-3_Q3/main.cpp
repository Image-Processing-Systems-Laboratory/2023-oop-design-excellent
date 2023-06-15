#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

namespace oopstd {

	class string {
	private:
		char* s;
		size_t len;
		
	public:
		string() {
			this->s = nullptr;
			this->len = 0;
		}
		string(const char* s) {
			// �Է¹��� ���ڿ��� ���� ����
			int cnt = 0;
			while (s[cnt]) 
				cnt++;			
			this->len = cnt;

			// ���ڿ� ���̸�ŭ �����Ҵ�
			this->s = new char[len + 1];
			
			for (int i = 0; i < this->len; i++)
				this->s[i] = s[i];

			this->s[len] = '\0'; // �������� NULL���� �߰�
		}
		string(const string& str) {
			// ���޹��� ���� ���� ����
			int cnt = 0;
			while (str.s[cnt]) // ���ڿ��� �����Ͱ� ������ cnt ����
				cnt++;
			this->len = cnt; // �ش� ����ŭ ���� ����

			this->s = new char[len + 1]; // �ش� �����͸� ������ ���ڿ� �����Ҵ�

			for (size_t i = 0; i < len; i++) { // �� ����
				this->s[i] = str.s[i];
			}
			this->s[len] = '\0'; // �������� �� ����
		}
		~string() {
			delete[] this->s;
			this->s = NULL;
		}
		
		size_t npos = -1;
		int getlen() const { return this->len; };

		string& assign(const string& str);
		char& at(size_t pos);
		const char* c_str() const;
		void clear();
		void push_back(char c);
		int compare(const string& str) const;
		string& replace(size_t pose, size_t len, const string& str);
		string substr(size_t pos, size_t len) const;
		size_t find(const string& str, size_t pos) const;
	};

	// ���ڿ� ���� ����Լ�
	string& string::assign(const string& str) {
		if (str.s != nullptr) { // ���޹��� ���� �����ϸ�
			// ���޹��� ���� ���� ����
			int cnt = 0;
			while (str.s[cnt]) // ���ڿ��� �����Ͱ� ������ cnt ����
				cnt++;
			this->len = cnt; // �ش� ����ŭ ���� ����

			this->s = new char[len + 1]; // �ش� �����͸� ������ ���ڿ� �����Ҵ�

			for (size_t i = 0; i < len; i++) { // �� ����
				this->s[i] = str.s[i];
			}
			this->s[len] = '\0'; // �������� �� ����
		}

		return *this;
	}

	// ���ڿ����� ������ ��ġ ��ȯ ����Լ�
	char& string::at(size_t pos) {
		if (pos >= len) { // ����� ���ڿ��� ���̰� �Է¹��� ��ġ���� ������
			cout << "out of range" << endl; // ���� ���
			return this->s[this->len];
		}

		return this->s[pos];
	}

	// ����� ���ڿ��� �ּ� ��ȯ ����Լ�
	const char* string::c_str() const {
		return this->s;
	}

	// ���ڿ� �ʱ�ȭ �Լ�
	void string::clear() {
		this->s[0] = '\0';
		len = 0;
	}

	// push back ����Լ�
	void string::push_back(char c) {
		char* new_s = new char[len + 2];
		if (s != nullptr) {
			for (size_t i = 0; i < len; i++)
				new_s[i] = s[i];
		}
		s = new_s;
		new_s[len++] = c;
		new_s[len] = '\0';
	}

	// compare ����Լ�
	int string::compare(const string& str) const {
		// �� ���� �� �� �� ª�� ���ڿ��� ���̸� �ӽ÷� ����
		int temp_len = (this->len < str.len) ? this->len : str.len;

		// ���� ���̱��� �� ��
		for (int i = 0; i < temp_len; i++) {
			if (this->s[i] < str.s[i]) // �ڿ��� �� ũ�� -1 ��ȯ
				return -1;			
			else if (this->s[i] > str.s[i])  // ���� �� ũ�� 1 ��ȯ
				return 1;
		}
		
		// �ռ� �ݺ����� ��� ���������� ���̸����� ��
		if (this->len == str.len) // ���̰� ������ 0 ��ȯ
			return 0;
		else if (this->len < str.len) // �ι�° ���ڰ� �� ��� -1 ��ȯ
			return -1;
		else
			return 1; // ù��° ���ڰ� �� ��� 1 ��ȯ
	}

	// replace ����Լ�
	string& string::replace(size_t pose, size_t len, const string& str) {
		int cnt = 0; // ��ü�� ���ڿ��� ����
		while (str.s[cnt]) // ���ڿ��� �����Ͱ� ������ cnt ����
			cnt++;
		this->len = (this->len + cnt - len + pose); // ��ü�� ���ڿ� ���� ����

		char* new_char = new char[this->len + 1]; // ��ü �� ���ڿ���ŭ ���� �Ҵ�

		// ��ü�� ���� �ݺ��� ����
		int i = 0;
		for (; i < pose; i++) // ���� ���ڿ����� ���� �κ� ��ü
			new_char[i] = this->s[i];
		for (int temp = 0; i < cnt + pose; i++, temp++)  // �Է¹��� ���ڿ��� ��ü
			new_char[i] = str.s[temp];
		for (; i < this->len; i++) // ���� ���ڿ����� ���ʺκ� ��ü
			new_char[i] = this->s[len - (cnt) + i];
		new_char[i] = '\0'; // ���ڿ��� �ι��� ����

		// ���� ������ ������ ���� �ӽ� ������
		char* delchar = this->s;
		this->s = new_char; // ����
		delete delchar; // ���� ������ ����

		return *this;
	}

	// substr ����Լ�
	string string::substr(size_t pose, size_t len) const {
		// �ӽ� ���ڿ��� �����ϱ� ���� �����Ҵ�
		char* new_char = new char[len - pose + 2];
		
		// ���ڿ� ���� �ݺ���
		int i = 0;
		for (; i < len - pose + 1; i++) 
			new_char[i] = this->s[pose + i];
		new_char[i + 1] = '\0'; // �������� NULL ���� ����

		// ��ȯ�ϱ� ���� string ��ü ����
		string temp_str;
		temp_str.assign(new_char); // ��ȯ�ϱ� ���� string�� char* ����
		temp_str.len = len - pose + 1; // ���� ����

		return temp_str; // ��ȯ
	}

	// find ����Լ�
	size_t string::find(const string& str, size_t pos = 0) const {
		if (pos > this->len)  // �˻� ���� ��ġ�� ���ڿ� ���̸� �ʰ��ϸ�
			return string::npos; // �˻� ���и� �ǹ��ϴ� string::npos�� ��ȯ		

		for (size_t i = pos; i <= this->len - str.len; i++) { // �˻� ���� ��ġ���� ������ ��� ��ġ����
			size_t j = 0;
			// �˻��� ���ڿ��� ��ġ�ϴ��� Ȯ��
			while (j < str.len && this->s[i + j] == str.s[j]) 
				j++;
		
			if (j == str.len) // �˻��� ���ڿ��� ��ġ�ϸ�
				return i; // ��ġ�ϴ� ��ġ�� ��ȯ			
		}

		return string::npos; // �˻� ���и� �ǹ��ϴ� string::npos�� ��ȯ
	}

	// string�� int������ ��ȯ
	int stoi(const string& str, size_t* idx, int base = 10) {
		int sign = 1; // ��ȣ
		int num = 0; // �ӽ÷� ��ȯ�� �� ����
		int i = 0; // Ž�� ��ġ

		// �Է¼��� ��ȣ ����
		if (str.c_str()[0] == '-') // ������ 
			sign = -1; // -1 ����
		else if (str.c_str()[0] == '+') // �����
			i++; // sign �״�� ���ΰ� i 1 ����
		
		// �� ���ڸ� ���� ��ȯ
		for (; i < str.getlen(); i++) {
			// ���ڰ� ������ �ش� ���ڸ� ���ڷ� ��ȯ
			if (isdigit(str.c_str()[i])) {
				int digit = str.c_str()[i] - '0';
				num = num * base + digit;
			}
			else { // ���ڰ� �ƴϸ� �ݺ��� Ż��
				break;
			}
		}

		*idx = i; // ���ڿ��� ���۵Ǵ� ��ġ ����

		return num;
	}

	// string�� float������ ��ȯ
	float stof(const string& str, size_t* idx) {
		int sign = 1; // ��ȣ
		float num = 0; // �ӽ÷� ��ȯ�� �� ����
		int i = 0; // Ž�� ��ġ

		// �Է¼��� ��ȣ ����
		if (str.c_str()[0] == '-') // ������ 
			sign = -1; // -1 ����
		else if (str.c_str()[0] == '+') // �����
			i++; // sign �״�� ���ΰ� i 1 ����

		for (; i < str.getlen(); i++) {
			// �Ҽ����� ������ Ż��
			if (str.c_str()[i] == '.') {
				i++;
				break;
			}
			// ���ڰ� ������ �ش� ���ڸ� ���ڷ� ��ȯ�Ͽ�
			if (isdigit(str.c_str()[i])) {
				int digit = str.c_str()[i] - '0';
				num = num * 10 + digit; // 10�� ���ؼ� ���ϱ�
			}
			else { // ���ڰ� �ƴϸ� �ݺ��� Ż��
				break;
			}
		}

		float temp_num = 0; // �Ҽ��� �Ʒ� �� �ӽ� ���� ����
		int temp_pow = 1;
		for (; i < str.getlen(); i++) {	
			if (isdigit(str.c_str()[i])) { // ���ڰ� ������
				int digit = str.c_str()[i] - '0';
				temp_num = temp_num + digit * pow(0.1, temp_pow++); // 0.1�� ������ ���ؼ� ���ϱ�
			}
			else
				break;
		}

		*idx = i; // ���ڿ��� ���۵Ǵ� ��ġ ����

		return num + temp_num;
	}

	// int�� ������ ���ڿ��� ��ȯ
	string to_string(int val) {
		char* new_char = new char[12]; // �������� �ִ� �ڸ������� ���� ũ�� ���ڿ� �����Ҵ�
		sprintf(new_char, "%d", val); // ���� ���ڿ��� ��ȯ�Ͽ� ���ڿ��� ����

		string temp_str; // �ӽ÷� string��ü�� �����Ͽ�
		temp_str.assign(new_char); // �ռ� ���ڿ��� ���� �� 

		return temp_str; // ��ȯ
	}
	// float�� ������ ���ڿ��� ��ȯ
	string to_string(float val) {
		char* new_char = new char[50]; // �Ǽ����� �ִ� �ڸ������� ���� ũ�� ���Ƿ� ���ڿ� �����Ҵ�
		sprintf(new_char, "%f", val); // ���� ���ڿ��� ��ȯ�Ͽ� ���ڿ��� ����

		string temp_str; // �ӽ÷� string��ü�� �����Ͽ�
		temp_str.assign(new_char); // �ռ� ���ڿ��� ���� �� 

		return temp_str; // ��ȯ
	}
}


int main() {
	
	// string & c_str method test
	string a1;
	a1.assign("HI");
	cout << a1 << endl;
	// custom method test
	oopstd::string a2;
	a2.assign("HI");
	cout << a2.c_str() << endl << endl;

	// at method test
	string example1 = "Hello World";
	cout << example1.at(2) << endl;
	// custom method test
	oopstd::string example2 = "Hello World";
	cout << example2.at(2) << endl << endl;

	// push_back method test
	example1.push_back('b');
	cout << example1 << endl;
	// custom method test
	example2.push_back('b');
	cout << example2.c_str() << endl;

	// clear method test
	example1.clear();
	cout << example1 << endl;
	// custom method test
	example2.clear();
	cout << example2.c_str() << endl << endl;

	// compare method test
	string com1 = "abc", com2 = "abc", com3 = "aab";
	cout << "com1 is " << com1 << ", com2 is " << com2 << ", com3 is " << com3 << endl;
	cout << "com1 is same with com2: " << com1.compare(com2) << endl;
	cout << "com1 is different with com3: " << com1.compare(com3) << endl;
	// custom method test
	oopstd::string temp_com1 = "abc", temp_com2 = "abc", temp_com3 = "aab";
	cout << "com1 is same with com2: " << temp_com1.compare(temp_com2) << endl;
	cout << "com1 is different with com3: " << temp_com1.compare(temp_com3) << endl << endl;

	string example3 = "Hello World";
	oopstd::string example4 = "Hello World";
	// replace method test
	string d1 = example3.replace(0, 5, "Hi");
	cout << d1 << endl;
	// custom method test
	oopstd::string d2 = example4.replace(0, 5, "Hi");
	cout << d2.c_str() << endl << endl;

	string example5 = "Hello World";
	oopstd::string example6 = "Hello World";
	// substr method test
	string c1 = example5.substr(5, 10);
	cout << c1 << endl;
	// custom method test
	oopstd::string c2 = example6.substr(5, 10);
	cout << c2.c_str() << endl << endl;

	// find method test
	cout << example5.find("World") << endl;
	// custom method test
	cout << example6.find("World") << endl << endl;

	// stoi method test
	string number1 = "10bus";
	size_t sz1;
	int num1 = stoi(number1, &sz1);
	cout << num1 << "  " << sz1 << endl;
	// custom method test
	oopstd::string number2 = "10bus";
	size_t sz2;
	int num2 = stoi(number2, &sz2);
	cout << num2 << "  " << sz2 << endl << endl;

	// stof method test
	string float_number1 = "1.5abc";
	float float_num1 = stof(float_number1, &sz1);
	cout << float_num1 << "  " << sz1 << endl;
	// custom method test
	oopstd::string float_number2 = "1.5abc";
	float float_num2 = stof(float_number2, &sz2);
	cout << float_num2 << "  " << sz2 << endl << endl;

	// to_string method test
	int test1 = 42;
	float test2 = 23.56;
	string str1 = to_string(test1);
	string str2 = to_string(test2);
	cout << str1 << "  " << str2 << endl;
	// custom method test
	oopstd::string str3 = oopstd::to_string(test1);
	oopstd::string str4 = oopstd::to_string(test2);
	cout << str3.c_str() << "  " << str4.c_str() << endl << endl;
	
	return 0;
}