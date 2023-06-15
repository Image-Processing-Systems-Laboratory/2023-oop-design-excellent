#include "class.h"

namespace oopstd {

	string::string() :len(0), s{ NULL } {} //기본 생성자

	string::string(const char* s) { //초기화할 생성자
		len = strlen(s);
		this->s = new char[len + 1]; //문자열 길이만큼 동적할당 
		strcpy(this->s, s); 
	}

	string::string(const string& str) { //복사 생성자
		len = str.len;
		s = new char[len+1];
		strcpy(s, str.s); //깊은 복사
	}

	string::~string() { //소멸자
		if (s != NULL) { //할당된 것이 있으면 메모리 해제
			delete[] s;
		}
	}

	/*문자열을 새로 할당하고 현재 내용을 바꾸는 함수*/
	string& string::assign(const string& str) {
		if (s != NULL) { //이미 할당되어 있는 경우 먼저 해제
			delete[] s; 
		}
		len = str.len;
		s = new char[len+1];
		strcpy(s, str.s);
		return *this; //자신의 객체 반환
	}
	
	/*문자열에서 해당 인덱스 값의 문자를 반환하는 함수*/
	char& string::at(size_t pos) { 
		return s[pos];
	}
	
	/*string형을 char*형으로 바꾸어 주는 함수*/
	const char* string::c_str()const {
		return s;
	}

	/*문자열을 지워주는 함수*/
	void string::clear() {
		s[0] = NULL; //첫번째 값을 NULL로 설정하여 문자열 삭제
		len = 0; //길이도 0으로 설정
	}

	/*문자열 끝에 문자 추가하는 함수*/
	void string::push_back(char c) {
		char* arr = new char[len+2]; //임시 배열 생성(길이 추가)
		/*기존 문자열 복사 후 공간 삭제 시킴*/
		strcpy(arr, s);
		delete[] s;
		/*임시 배열 끝에 문자 삽입 후 마지막 칸에 NULL로 끝 알림*/
		arr[len] = c;
		arr[len + 1] = NULL;
		/*다시 기존 문자열에 복사 후 길이 증가 시킴*/
		s = arr; //strcpy로 할 경우 에러
		len += 1;
	}

	/*문자열 비교 함수*/
	int string::compare(const string* str) const {
		int com_len = (int)strlen(str->c_str());
		char* arr = new char[com_len + 1]; //임시 배열 생성
		strcpy(arr, str->c_str());
		int eq = 0; //일치 횟수 확인 변수
		for (int i = 0; s[i] != NULL || arr[i] != NULL; i++) { //어느 한쪽이라도 문자열이 끝날 때까지 검사
			if (s[i] == arr[i]) {
				eq += 1;
			}
			else if (s[i] < arr[i]) { //다른 순간 값 비교하여 반환
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
	
	/*문자열 대체 함수 (pose부터 len까지 str로 대체)*/
	string& string::replace(size_t pose, size_t len, const string* str) {
		char* arr = new char[(int)len + 1]; //임시 배열 생성
		strcpy(arr, str->c_str());
		int arr_len = (int)strlen(arr);
		for (int i = (int)pose; i < arr_len; i++) {
			s[i] = arr[i];
		}
		return *this;
	}

	/*문자열 추출 함수 (pos부터 len까지 추출)*/
	string string::substr(size_t pos, size_t len) const {
		int sub_len = (int)(len - pos);
		char* arr = new char[sub_len + 1]; //새 배열 생성
		int n = 0;
		for (int i = (int)pos; i < (int)len; i++) {
			arr[n] = s[i];
			n++;
		}
		return arr;
	}

	/*pos위치 부터 str이 나올 때까지 탐색하여 인덱스 값 찾는 함수*/
	size_t string::find(const string& str, size_t pos=0) const {
		int find_len = (int)strlen(str.s); //검색할 문자열 길이 저장
		char* arr = new char[find_len + 1]; //임시 배열 생성
		strcpy(arr, str.c_str());
		int a = 0, eq = 0; //증가 변수
		while (1) { //값을 반환하기 전까지 반복
			if (s[pos] == arr[0]) { //검색위치의 값이 문자열 첫번째 값과 같을 시
				for (int i = (int)pos; i < len; i++) { //해당 위치부터 검색 문자열 끝까지 검사
					if (s[i] == arr[a]) {
						eq+=1; //같음을 나타내는 변수 증가
						a+=1;
					}
				}
				if (eq == find_len) { //같은 횟수가 문자열 길이와 동일할 경우
					eq++;
					return eq; //해당 위치 반환
					break;
				}
				else
					pos++;
			}
			else {
				pos++;
				if (s[pos]==NULL) { //검색결과가 없을 시 npos 반환
					cout << "검색결과가 없습니다." << endl;
					return std::string::npos;
					break;
				}
			}
		}
	}

	/*문자열의 숫자를 정수타입으로 바꾸는 함수*/
	int stoi(const string& str, size_t* idx, int base = 10) {
		int i_len = (int)strlen(str.c_str());
		char* arr = new char[i_len + 1]; //임시 배열 생성
		strcpy(arr, str.c_str());

		for (int j = 0; j < i_len; j++) {
			if (arr[j] < 48 || arr[j] > 57) { //숫자 외 문자일 경우 위치 찾아서 길이로 저장
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

	/*문자열의 숫자를 실수타입으로 바꾸는 함수*/
	float stof(const string& str, size_t* idx) {
		int f_len = (int)strlen(str.c_str());
		char* arr = new char[f_len + 1]; //임시 배열 생성
		strcpy(arr, str.c_str());

		int d = 0; //소수점 위치 저장용
		for (int j = 0; j < f_len; j++) {
			if (arr[j] == '.') { //소수점 위치 저장
				d = j;
			}
			if (arr[j] < 46 || arr[j] > 57) { //.과 숫자 외 문자일 경우 위치 찾아서 길이로 저장
				f_len = j;
				break;
			}
		}
		/*소수점 이전 부분 변환*/
		float isum = 0.0;
		for (int i = 0; i < d; i++) {
			isum = isum * 10 + (arr[i] - '0');
		}
		/*소수점 이후 부분 변환*/
		float fsum = (float)0.1;
		for (int i = d + 1; i < f_len; i++) {
			isum += fsum * (arr[i] - '0');
			fsum *= (float)0.1;
		}
		*idx = f_len;
		return isum;
	}

	/*정수를 문자열로 변환하는 함수*/
	string to_string(int val) {
		char res[10]={}; //변환 값 저장
		int i = 0;
		while (val) { 
			res[i++] = (char)(val % 10 + '0'); //10으로 나눈 나머지를 문자로 변환후 저장
			val /= 10; //그 다음 자릿수로 타겟 변경
		}
		char temp[10] = {}; //res에 역순으로 저장되어 있으니 다시 순서 바꿈
		int to_len = 0; //res에 저장된 문자열 길이 셈
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

	/*실수를 문자열로 변환하는 함수*/
	string to_string(float val) {
		char res[20]={};
		sprintf(res, "%.3f", val);
		return res;
	}
}