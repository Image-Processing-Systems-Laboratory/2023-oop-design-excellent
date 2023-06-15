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
			// 입력받은 문자열의 길이 측정
			int cnt = 0;
			while (s[cnt]) 
				cnt++;			
			this->len = cnt;

			// 문자열 길이만큼 동적할당
			this->s = new char[len + 1];
			
			for (int i = 0; i < this->len; i++)
				this->s[i] = s[i];

			this->s[len] = '\0'; // 마지막에 NULL문자 추가
		}
		string(const string& str) {
			// 전달받은 값의 길이 측정
			int cnt = 0;
			while (str.s[cnt]) // 문자열에 데이터가 있으면 cnt 증가
				cnt++;
			this->len = cnt; // 해당 값만큼 길이 저장

			this->s = new char[len + 1]; // 해당 데이터를 저장할 문자열 동적할당

			for (size_t i = 0; i < len; i++) { // 값 저장
				this->s[i] = str.s[i];
			}
			this->s[len] = '\0'; // 마지막에 널 삽입
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

	// 문자열 저장 멤버함수
	string& string::assign(const string& str) {
		if (str.s != nullptr) { // 전달받은 값이 존재하면
			// 전달받은 값의 길이 측정
			int cnt = 0;
			while (str.s[cnt]) // 문자열에 데이터가 있으면 cnt 증가
				cnt++;
			this->len = cnt; // 해당 값만큼 길이 저장

			this->s = new char[len + 1]; // 해당 데이터를 저장할 문자열 동적할당

			for (size_t i = 0; i < len; i++) { // 값 저장
				this->s[i] = str.s[i];
			}
			this->s[len] = '\0'; // 마지막에 널 삽입
		}

		return *this;
	}

	// 문자열에서 지정된 위치 반환 멤버함수
	char& string::at(size_t pos) {
		if (pos >= len) { // 저장된 문자열의 길이가 입력받은 위치보다 작으면
			cout << "out of range" << endl; // 오류 출력
			return this->s[this->len];
		}

		return this->s[pos];
	}

	// 저장된 문자열의 주소 반환 멤버함수
	const char* string::c_str() const {
		return this->s;
	}

	// 문자열 초기화 함수
	void string::clear() {
		this->s[0] = '\0';
		len = 0;
	}

	// push back 멤버함수
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

	// compare 멤버함수
	int string::compare(const string& str) const {
		// 두 전달 값 중 더 짧은 문자열의 길이를 임시로 저장
		int temp_len = (this->len < str.len) ? this->len : str.len;

		// 같은 길이까지 값 비교
		for (int i = 0; i < temp_len; i++) {
			if (this->s[i] < str.s[i]) // 뒤에가 더 크면 -1 반환
				return -1;			
			else if (this->s[i] > str.s[i])  // 앞이 더 크면 1 반환
				return 1;
		}
		
		// 앞선 반복문을 모두 빠져나오면 길이만으로 비교
		if (this->len == str.len) // 길이가 같으면 0 반환
			return 0;
		else if (this->len < str.len) // 두번째 인자가 더 길면 -1 반환
			return -1;
		else
			return 1; // 첫번째 인자가 더 길면 1 반환
	}

	// replace 멤버함수
	string& string::replace(size_t pose, size_t len, const string& str) {
		int cnt = 0; // 교체할 문자열의 길이
		while (str.s[cnt]) // 문자열에 데이터가 있으면 cnt 증가
			cnt++;
		this->len = (this->len + cnt - len + pose); // 교체될 문자열 길이 저장

		char* new_char = new char[this->len + 1]; // 교체 후 문자열만큼 동적 할당

		// 교체를 위한 반복문 세개
		int i = 0;
		for (; i < pose; i++) // 기존 문자열에서 앞쪽 부분 교체
			new_char[i] = this->s[i];
		for (int temp = 0; i < cnt + pose; i++, temp++)  // 입력받은 문자열로 교체
			new_char[i] = str.s[temp];
		for (; i < this->len; i++) // 기존 문자열에서 뒤쪽부분 교체
			new_char[i] = this->s[len - (cnt) + i];
		new_char[i] = '\0'; // 문자열의 널문자 삽입

		// 기존 포인터 삭제를 위한 임시 포인터
		char* delchar = this->s;
		this->s = new_char; // 대입
		delete delchar; // 기존 포인터 삭제

		return *this;
	}

	// substr 멤버함수
	string string::substr(size_t pose, size_t len) const {
		// 임시 문자열을 저장하기 위한 동적할당
		char* new_char = new char[len - pose + 2];
		
		// 문자열 복사 반복문
		int i = 0;
		for (; i < len - pose + 1; i++) 
			new_char[i] = this->s[pose + i];
		new_char[i + 1] = '\0'; // 마지막에 NULL 문자 삽입

		// 반환하기 위한 string 객체 선언
		string temp_str;
		temp_str.assign(new_char); // 반환하기 위한 string에 char* 저장
		temp_str.len = len - pose + 1; // 길이 저장

		return temp_str; // 반환
	}

	// find 멤버함수
	size_t string::find(const string& str, size_t pos = 0) const {
		if (pos > this->len)  // 검색 시작 위치가 문자열 길이를 초과하면
			return string::npos; // 검색 실패를 의미하는 string::npos를 반환		

		for (size_t i = pos; i <= this->len - str.len; i++) { // 검색 시작 위치부터 가능한 모든 위치에서
			size_t j = 0;
			// 검색할 문자열과 일치하는지 확인
			while (j < str.len && this->s[i + j] == str.s[j]) 
				j++;
		
			if (j == str.len) // 검색할 문자열과 일치하면
				return i; // 일치하는 위치를 반환			
		}

		return string::npos; // 검색 실패를 의미하는 string::npos를 반환
	}

	// string을 int형으로 변환
	int stoi(const string& str, size_t* idx, int base = 10) {
		int sign = 1; // 부호
		int num = 0; // 임시로 변환된 수 저장
		int i = 0; // 탐색 위치

		// 입력수의 부호 결정
		if (str.c_str()[0] == '-') // 음수면 
			sign = -1; // -1 저장
		else if (str.c_str()[0] == '+') // 양수면
			i++; // sign 그대로 납두고 i 1 증가
		
		// 각 숫자를 수로 변환
		for (; i < str.getlen(); i++) {
			// 숫자가 맞으면 해당 문자를 숫자로 변환
			if (isdigit(str.c_str()[i])) {
				int digit = str.c_str()[i] - '0';
				num = num * base + digit;
			}
			else { // 숫자가 아니면 반복문 탈출
				break;
			}
		}

		*idx = i; // 문자열이 시작되는 위치 저장

		return num;
	}

	// string을 float형으로 변환
	float stof(const string& str, size_t* idx) {
		int sign = 1; // 부호
		float num = 0; // 임시로 변환된 수 저장
		int i = 0; // 탐색 위치

		// 입력수의 부호 결정
		if (str.c_str()[0] == '-') // 음수면 
			sign = -1; // -1 저장
		else if (str.c_str()[0] == '+') // 양수면
			i++; // sign 그대로 납두고 i 1 증가

		for (; i < str.getlen(); i++) {
			// 소수점을 만나면 탈출
			if (str.c_str()[i] == '.') {
				i++;
				break;
			}
			// 숫자가 맞으면 해당 문자를 숫자로 변환하여
			if (isdigit(str.c_str()[i])) {
				int digit = str.c_str()[i] - '0';
				num = num * 10 + digit; // 10을 곱해서 더하기
			}
			else { // 숫자가 아니면 반복문 탈출
				break;
			}
		}

		float temp_num = 0; // 소수점 아래 수 임시 저장 변수
		int temp_pow = 1;
		for (; i < str.getlen(); i++) {	
			if (isdigit(str.c_str()[i])) { // 숫자가 맞으면
				int digit = str.c_str()[i] - '0';
				temp_num = temp_num + digit * pow(0.1, temp_pow++); // 0.1의 제곱을 곱해서 더하기
			}
			else
				break;
		}

		*idx = i; // 문자열이 시작되는 위치 저장

		return num + temp_num;
	}

	// int형 변수를 문자열로 변환
	string to_string(int val) {
		char* new_char = new char[12]; // 정수형의 최대 자릿수보다 조금 크게 문자열 동적할당
		sprintf(new_char, "%d", val); // 값을 문자열로 변환하여 문자열에 저장

		string temp_str; // 임시로 string객체를 생성하여
		temp_str.assign(new_char); // 앞선 문자열을 저장 후 

		return temp_str; // 반환
	}
	// float형 변수를 문자열로 변환
	string to_string(float val) {
		char* new_char = new char[50]; // 실수형의 최대 자릿수보다 조금 크게 임의로 문자열 동적할당
		sprintf(new_char, "%f", val); // 값을 문자열로 변환하여 문자열에 저장

		string temp_str; // 임시로 string객체를 생성하여
		temp_str.assign(new_char); // 앞선 문자열을 저장 후 

		return temp_str; // 반환
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