#include <iostream>
#include <cmath>
using namespace std;


namespace oopstd {
	// strcmp �Լ� ����
	int strcmp(const char* str1, const char* str2) {
		int i = 0;
		while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0') 
			i++;
		
		if (str1[i] == '\0' && str2[i] == '\0') 
			return 0;
		
		else if (str1[i] < str2[i]) 
			return -1;
		
		else 
			return 1;
		
	}
	// strncmp �Լ� ����
	int strncmp(const char* str1, const char* str2, size_t num) {
		for (int i = 0; i < num; i++) {
			if (str1[i]  != str2[i] ) {
				if (str1[i] > str2[i] )
					return 1;
				else if (str1[i] < str2[i] )
					return -1;
			}
			if (str1[i] == '\0' && str2[i] == '\0')
				return 0;
		}
		return 0;
	};
	// strcpy �Լ� ����
	char* strcpy(char* destination, const char* source) {
		int i = 0;
		for (i = 0; source[i] != '\0'; i++) {
			destination[i] = source[i];
		}
		destination[i] = '\0';
		return destination;
	};
	// strncpy �Լ� ����
	char* strncpy(char* destination, const char* source, size_t num) {
		size_t i = 0;
		for (i = 0; i < num; i++) {
			destination[i] = source[i];
		}
		destination[i] = '\0';
		return destination;
	};
	// strlen �Լ� ����
	size_t strlen(const char* str) {
		size_t size = 0;
		while (str[size] != '\0') {
			size++;
		}
		return size;
	};
	// memset �Լ� ����
	void* memset(void* ptr, int value, size_t num) {
		char* input = (char*)ptr;
		for (size_t i = 0; i < num; i++) {
			input[i] = value;
		}
		return ptr;
	};
	// memcpy �Լ� ����
	void* memcpy(void* destination, const void* source, size_t num) {
		char* des_str = (char*)destination;
		char* input_str = (char*)source;
		for (size_t i = 0; i < num; i++) {
			des_str[i] = input_str[i];
		}
		return destination;
	};
	 // atoi �Լ� ����
	int atoi(const char* str) {
		int result = 0;
		int plus_minus = 1;
		int i = 0;
		// ���� ó��
		if (str[i] == ' ') {
			i++;
		}
		// ��ȣ ó��
		if (str[i] == '-') {
			plus_minus = -1;
			i++;
		}
		else if (str[i] == '+') {
			i++;
		}
		// ���� ���
		while (str[i] != '\0') {
			result = result* 10 + (str[i] - '0');
			i++;
		};
		return result * plus_minus;
	};
	// atof �Լ� ����
	float atof(const char* str) {
		int i = 0, plus_minus = 1,flag=0;
		float integer = 0.0, fract = 0.0;
		// ���� ó��
		if (str[i] == ' ') {
			i++;
		}
		// ��ȣ ó��
		if (str[i] == '-') {
			plus_minus = -1;
			i++;
		}
		else if (str[i] == '+') {
			i++;
		}
		// �����κ� ��� �� . ó��
		while (str[i] != '\0') {
			integer =integer*10 + (str[i] - '0');
			i++;
			if (str[i] == '.')
				break;
		}
		
		// �Ҽ��κ� ����
		if (str[i] == '.') {
			flag = i;
			i++;
			
		};
		while (str[i] != '\0') {
			fract = fract + (str[i]-'0') / pow(10, (i - flag));
			i++;
		}

		
		return (fract + integer) * plus_minus;
	}
	
}
int main() {
	// �� �Լ� ���� �� ���
	char str1[] = "sample string";
	char str2[] = "sample";
	char atoi_res[] = "-187910";
	char atof_res[] = "121.012";
	char str3[40];
	char str4[40];
	char str5[40]="";
	int result1 = oopstd::strcmp(str1, str2);
	int result2 = oopstd::strncmp(str1, str2, 5);
	oopstd::strcpy(str3, str1);
	oopstd::strncpy(str4, str1, 4);
	size_t size = oopstd::strlen(str2);
	oopstd::memset(str2, '0', 4);
	oopstd::memcpy(str5, str2, 2);
	int atoi_result = oopstd::atoi(atoi_res);
	float atof_result = oopstd::atof(atof_res);
	// �����Լ� ��
	char str1_func[] = "sample string";
	char str2_func[] = "sample";
	char atoi_func[] = "-187910";
	char atof_func[] = "121.012";
	char str3_func[40];
	char str4_func[40];
	char str5_func[40] = "";
	int result1_func = strcmp(str1_func, str2_func);
	int result2_func = strncmp(str1_func, str2_func, 5);
	strcpy_s(str3_func, str1_func);
	strncpy_s(str4_func, str1_func, 4);
	size_t size_func = strlen(str2_func);
	memset(str2_func, '0', 4);
	memcpy(str5_func, str2_func, 2);
	int atoi_result_func = atoi(atoi_func);
	float atof_result_func = oopstd::atof(atof_func);
	// ������ �Լ� ���
	cout << endl << "---------------������ �Լ� ��� -------------------" << endl;
	cout << "strcmp: "<<result1 << endl << "strncmp: "<<result2 << endl << 
		"strcpy: "<<str3 << endl << "strlen: "<<size << endl << "strncpy: "<<str4 << endl << "memset: "<<str2 << endl << "memcpy: "<<str5;
	cout << endl << "atoi: "<<atoi_result << endl << "atof: "<<atof_result;
	cout << endl << "---------------���� �Լ� ��� -------------------"<<endl;
	// ���� �Լ� ���
	cout << "strcmp: " << result1_func << endl << "strncmp: " << result2_func << endl <<
	"strcpy: " << str3_func << endl << "strlen: " << size_func << endl << "strncpy: " << str4_func << endl << "memset: " << str2_func << endl << "memcpy: " << str5_func;
	cout << endl << "atoi: " << atoi_result_func << endl << "atof: " << atof_result_func;

	return 0;
}