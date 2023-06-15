#include "string.h"

namespace oopstd {

	string::string() : str_size(0), data(nullptr) {};
	string::string(const char* str) : string::string() {
		while (str[str_size]) {
			str_size++;
		}

		data = new char[str_size + 1];		// nul���� �ƽ��ƽ��ϰ� �����Ҵ�

		for (size_t i = 0; i < str_size; i++) {		// ������ ����
			data[i] = str[i];
		}
		data[str_size] = '\0';		// ������ nul
	};

	string::string(const string& str) : string::string() {
		size_t length = str.size();
		data = new char[length + 1];
		for (size_t i = 0; i < length; i++) {    // ������ ����
			data[i] = str.data[i];
		}
		data[length] = '\0';    // ������ nul
	}


	string::~string() {
		if (data == nullptr)		// ���� ��� ���� ����
			return;
		delete[] data;			// ���� �Ҵ� ����
	}

	const char* string::c_str() const {
		return data;
	}

	char& string::operator[](size_t index) {
		if (index < str_size) {
			return data[index];
		}
	}

	char& string::operator[](size_t index) const {
		if (index < str_size) {
			return data[index];
		}
	}


	string& string::operator+(const string& other) const {
		string* temp = new string;
		size_t length = this->str_size + other.str_size;
		temp->str_size = length;
		temp->data = new char[length + 1];


		size_t temp_idx = 0;
		for (size_t i = 0; i < this->str_size; i++) {
			temp->data[temp_idx++] = this->data[i];
		}
		for (size_t i = 0; i < other.str_size; i++) {
			temp->data[temp_idx++] = other.data[i];
		}
		temp->data[length] = '\0';
		return *temp;
	}

	string& string::operator=(const char* str) {
		if (data != nullptr) {
			delete[] data;
		}
		// length ���ϱ�
		const char* ptr = str;
		str_size = 0;
		while (*ptr++) {
			str_size++;
		}
		// ���� �Ҵ� �� ����
		ptr = str;
		data = new char[str_size + 1];    // NUL �Ҵ�
		for (size_t i = 0; i < str_size; i++) {
			data[i] = str[i];
		}
		data[str_size] = '\0';
		return *this;
	}
	string& string::operator=(const string& other) {
		if (data != nullptr) {
			delete[] data;
		}
		str_size = other.str_size;
		data = new char[str_size + 1];    // NUL �Ҵ�
		for (size_t i = 0; i < str_size; i++) {
			data[i] = other.data[i];
		}
		data[str_size] = '\0';
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const string& str) {
		if (str.data == nullptr) {		// nul�� ���� ���
			return os;
		}
		os << str.data;
		return os;
	}
	std::istream& operator>>(std::istream& is, string& str) {
		size_t max = 10000;
		char* temp = new char[max];
		std::cin >> temp;
		//is.getline(temp, max)	���� �Է� �ڵ�
		str = temp;
		delete[] temp;
		return is;
	}

	char* string::begin()
	{
		return data;
	}

	char* string::end()
	{
		return data+str_size;
	}


	size_t string::size() const {		// ���ڿ� ũ�� ����
		return str_size;
	}




	string& string::assign(const string& str)
	{
		if (data != nullptr) {		// �ϴ� ���� ��
			delete[] data;
		}
		// ���� �Ҵ� �� ����
		size_t length = str.size();
		data = new char[length + 1];    
		for (size_t i = 0; i < length; i++) {
			data[i] = str[i];
		}
		data[length] = '\0';	// NUL �Ҵ�
		str_size = length;
		return *this;
	}


	char& string::at(size_t pos)
	{
		return (*this)[pos];
	}


	void string::clear()
	{
		if (data != nullptr) {
			delete[] data;		// �� ����
		}
		data = nullptr;		// �ʱ�ȭ
		str_size = 0;
	}


	void string::push_back(char c)
	{
		char temp[2] = { c,'\0' };		// ���ڿ��� ��ȯ
		*this = *this + temp;		// ���Ѵ�
	}


	int string::compare(const string* str) const
	{
		size_t min_high = (str_size < str->str_size) ? str_size : str->str_size;		// �ּҰ�
		for (size_t i = 0; i < min_high; i++) {
			if ((*this)[i] > (*str)[i])
				return 1;
			else if ((*this)[i] < (*str)[i])
				return -1;
		}
		if (str_size > str->str_size)
			return 1;
		else if (str_size < str->str_size)
			return -1;
		return 0;
	}


	string& string::replace(size_t pose, size_t len, const string* str)
	{
		char temp[10000];
		size_t crr = 0;
		len += pose;
		for (size_t i = 0; i < pose; i++) {
			temp[crr++] = data[i];
		}
		for (size_t i = 0; i < (* str).size(); i++) {
			temp[crr++] = (*str)[i];
		}
		for (size_t i = len; i < str_size; i++) {
			temp[crr++] = data[i];
		}
		temp[crr] = '\0';
		*this = temp;
		return *this;
	}


	string string::substr(size_t pose, size_t len)
	{
		string ss;
		char temp[10000];
		size_t crr = 0;
		for (size_t i = pose; i < len + 1; i++) {
			temp[crr++] = data[i];
		}
		temp[crr] = '\0';

		ss = temp;
		return ss;
	}


	size_t string::find(const string& substr, size_t pose) const {
		int strLength = str_size;
		int substrLength = substr.size();

		for (int i = 0; i < strLength - substrLength + 1; i++) {
			bool found = true;
			for (int j = 0; j < substrLength; j++) {
				if (data[i + j] != substr[j]) {
					found = false;
					break;
				}
			}
			if (found) {
				return i;
			}
		}

		return -1;
	}

	int stoi(const string& str, size_t* idx, int base)  {
		int sol = 0;
		int sign = 1;	// ��ȣ
		size_t start = 0;
		if (str[0] == '-') {
			start++;
			sign = -1;
		}
		for (size_t i = start; i < str.size(); i++) {
			if (str[i] < '0' || str[i] > '9') {
				*idx = i;
				return sol;
			}
			sol *= 10;
			sol += str[i] - '0';
		}
		return (sol * sign);
	}

	float stof(const string& str, size_t* idx)
	{
		float sol = 0.0f;
		float sign = 1.0f;
		size_t start = 0;
		if (str[0] == '-') {
			start++;
			sign = -1.0f;
		}
		bool decimal = false;
		float frac = 10.0f;
		for (size_t i = start; i < str.size(); i++) {
			if (str[i] == '.') {
				decimal = true;
			}
			else if (str[i] < '0' || str[i] > '9') {
				*idx = i;
				break;
			}
			else {
				if (decimal) {
					sol += (str[i] - '0') / frac;
					frac *= 10.0f;
				}
				else {
					sol *= 10.0f;
					sol += str[i] - '0';
				}
			}
		}
		return sol * sign;
	}


	string to_string(int val)
	{
		char res[1000];
		size_t crr = 0;
		if (val < 0) {
			res[crr++] += '-';
			val = -val;
		}
		if (val == 0) {
			return "0";
		}
		while (val > 0) {
			char digit = '0' + (val % 10);
			res[crr++] = digit;
			val /= 10;
		}
		res[crr] = '\0';
		string* temp = new string;
		*temp = res;
		return *temp;

	}

	string to_string(float val)
	{
		string result;
		int int_part = static_cast<int>(val); // ������ ����
		float frac_part = val - int_part; // �Ҽ��� ����
		result = to_string(int_part); // �����θ� ���ڿ��� ��ȯ

		if (frac_part == 0) // �Ҽ��ΰ� ���� ��
			return result;

		char temp[2] = { '.', '\0' };
		result = result + temp; // �Ҽ��� �߰�

		while (frac_part != 0) { // �Ҽ��θ� ���ڿ��� ��ȯ
			frac_part *= 10;
			int int_val = static_cast<int>(frac_part);
			result =  result + to_string(int_val);
			frac_part -= int_val;
		}

		return result;
	}
}