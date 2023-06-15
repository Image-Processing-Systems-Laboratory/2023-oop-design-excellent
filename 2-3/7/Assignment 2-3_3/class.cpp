#include "class.h"

namespace oopstd {

	string::string() :len(0), s{ NULL } {} //�⺻ ������

	string::string(const char* s) { //�ʱ�ȭ�� ������
		len = strlen(s);
		this->s = new char[len + 1]; //���ڿ� ���̸�ŭ �����Ҵ� 
		strcpy(this->s, s); 
	}

	string::string(const string& str) { //���� ������
		len = str.len;
		s = new char[len+1];
		strcpy(s, str.s); //���� ����
	}

	string::~string() { //�Ҹ���
		if (s != NULL) { //�Ҵ�� ���� ������ �޸� ����
			delete[] s;
		}
	}

	/*���ڿ��� ���� �Ҵ��ϰ� ���� ������ �ٲٴ� �Լ�*/
	string& string::assign(const string& str) {
		if (s != NULL) { //�̹� �Ҵ�Ǿ� �ִ� ��� ���� ����
			delete[] s; 
		}
		len = str.len;
		s = new char[len+1];
		strcpy(s, str.s);
		return *this; //�ڽ��� ��ü ��ȯ
	}
	
	/*���ڿ����� �ش� �ε��� ���� ���ڸ� ��ȯ�ϴ� �Լ�*/
	char& string::at(size_t pos) { 
		return s[pos];
	}
	
	/*string���� char*������ �ٲپ� �ִ� �Լ�*/
	const char* string::c_str()const {
		return s;
	}

	/*���ڿ��� �����ִ� �Լ�*/
	void string::clear() {
		s[0] = NULL; //ù��° ���� NULL�� �����Ͽ� ���ڿ� ����
		len = 0; //���̵� 0���� ����
	}

	/*���ڿ� ���� ���� �߰��ϴ� �Լ�*/
	void string::push_back(char c) {
		char* arr = new char[len+2]; //�ӽ� �迭 ����(���� �߰�)
		/*���� ���ڿ� ���� �� ���� ���� ��Ŵ*/
		strcpy(arr, s);
		delete[] s;
		/*�ӽ� �迭 ���� ���� ���� �� ������ ĭ�� NULL�� �� �˸�*/
		arr[len] = c;
		arr[len + 1] = NULL;
		/*�ٽ� ���� ���ڿ��� ���� �� ���� ���� ��Ŵ*/
		s = arr; //strcpy�� �� ��� ����
		len += 1;
	}

	/*���ڿ� �� �Լ�*/
	int string::compare(const string* str) const {
		int com_len = (int)strlen(str->c_str());
		char* arr = new char[com_len + 1]; //�ӽ� �迭 ����
		strcpy(arr, str->c_str());
		int eq = 0; //��ġ Ƚ�� Ȯ�� ����
		for (int i = 0; s[i] != NULL || arr[i] != NULL; i++) { //��� �����̶� ���ڿ��� ���� ������ �˻�
			if (s[i] == arr[i]) {
				eq += 1;
			}
			else if (s[i] < arr[i]) { //�ٸ� ���� �� ���Ͽ� ��ȯ
				return -1;
				break;
			}
			else {
				return 1;
				break;
			}
		}
		if (eq == com_len) {
			if (com_len == len - 1)
				return 0;
			else if (com_len < len - 1)
				return 1;
			else
				return -1;
		}
		else
			return 1;
	}
	
	/*���ڿ� ��ü �Լ� (pose���� len���� str�� ��ü)*/
	string& string::replace(size_t pose, size_t len, const string* str) {
		char* arr = new char[(int)len + 1]; //�ӽ� �迭 ����
		strcpy(arr, str->c_str());
		int arr_len = (int)strlen(arr);
		for (int i = (int)pose; i < arr_len; i++) {
			s[i] = arr[i];
		}
		return *this;
	}

	/*���ڿ� ���� �Լ� (pos���� len���� ����)*/
	string string::substr(size_t pos, size_t len) const {
		int sub_len = (int)(len - pos);
		char* arr = new char[sub_len + 1]; //�� �迭 ����
		int n = 0;
		for (int i = (int)pos; i < (int)len; i++) {
			arr[n] = s[i];
			n++;
		}
		return arr;
	}

	/*pos��ġ ���� str�� ���� ������ Ž���Ͽ� �ε��� �� ã�� �Լ�*/
	size_t string::find(const string& str, size_t pos=0) const {
		int find_len = (int)strlen(str.s); //�˻��� ���ڿ� ���� ����
		char* arr = new char[find_len + 1]; //�ӽ� �迭 ����
		strcpy(arr, str.c_str());
		int a = 0, eq = 0; //���� ����
		while (1) { //���� ��ȯ�ϱ� ������ �ݺ�
			if (s[pos] == arr[0]) { //�˻���ġ�� ���� ���ڿ� ù��° ���� ���� ��
				for (int i = (int)pos; i < len; i++) { //�ش� ��ġ���� �˻� ���ڿ� ������ �˻�
					if (s[i] == arr[a]) {
						eq+=1; //������ ��Ÿ���� ���� ����
						a+=1;
					}
				}
				if (eq == find_len) { //���� Ƚ���� ���ڿ� ���̿� ������ ���
					eq++;
					return eq; //�ش� ��ġ ��ȯ
					break;
				}
				else
					pos++;
			}
			else {
				pos++;
				if (s[pos]==NULL) { //�˻������ ���� �� npos ��ȯ
					cout << "�˻������ �����ϴ�." << endl;
					return std::string::npos;
					break;
				}
			}
		}
	}

	/*���ڿ��� ���ڸ� ����Ÿ������ �ٲٴ� �Լ�*/
	int stoi(const string& str, size_t* idx, int base = 10) {
		int i_len = (int)strlen(str.c_str());
		char* arr = new char[i_len + 1]; //�ӽ� �迭 ����
		strcpy(arr, str.c_str());

		for (int j = 0; j < i_len; j++) {
			if (arr[j] < 48 || arr[j] > 57) { //���� �� ������ ��� ��ġ ã�Ƽ� ���̷� ����
				i_len = j;
				break;
			}
		}
		int sum=0;
		for (int i = 0; i < i_len; i++) {
			sum = sum * 10 + (arr[i] - '0');
		}
		*idx = i_len;
		return sum;
	}

	/*���ڿ��� ���ڸ� �Ǽ�Ÿ������ �ٲٴ� �Լ�*/
	float stof(const string& str, size_t* idx) {
		int f_len = (int)strlen(str.c_str());
		char* arr = new char[f_len + 1]; //�ӽ� �迭 ����
		strcpy(arr, str.c_str());

		int d = 0; //�Ҽ��� ��ġ �����
		for (int j = 0; j < f_len; j++) {
			if (arr[j] == '.') { //�Ҽ��� ��ġ ����
				d = j;
			}
			if (arr[j] < 46 || arr[j] > 57) { //.�� ���� �� ������ ��� ��ġ ã�Ƽ� ���̷� ����
				f_len = j;
				break;
			}
		}
		/*�Ҽ��� ���� �κ� ��ȯ*/
		float isum = 0.0;
		for (int i = 0; i < d; i++) {
			isum = isum * 10 + (arr[i] - '0');
		}
		/*�Ҽ��� ���� �κ� ��ȯ*/
		float fsum = (float)0.1;
		for (int i = d + 1; i < f_len; i++) {
			isum += fsum * (arr[i] - '0');
			fsum *= (float)0.1;
		}
		*idx = f_len;
		return isum;
	}

	/*������ ���ڿ��� ��ȯ�ϴ� �Լ�*/
	string to_string(int val) {
		char res[10]={}; //��ȯ �� ����
		int i = 0;
		while (val) { 
			res[i++] = (char)(val % 10 + '0'); //10���� ���� �������� ���ڷ� ��ȯ�� ����
			val /= 10; //�� ���� �ڸ����� Ÿ�� ����
		}
		char temp[10] = {}; //res�� �������� ����Ǿ� ������ �ٽ� ���� �ٲ�
		int to_len = 0; //res�� ����� ���ڿ� ���� ��
		for (int j = 0; j < 10; j++) {
			if (res[j] == NULL) {
				to_len = j;
				break;
			}
		}
		int n = 0;
		for (int j = to_len-1; j >= 0; j--) {
			temp[n++] = res[j];
		}
		return temp;
	}

	/*�Ǽ��� ���ڿ��� ��ȯ�ϴ� �Լ�*/
	string to_string(float val) {
		char res[20]={};
		sprintf(res, "%.3f", val);
		return res;
	}
}