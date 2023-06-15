#include"oopstd.h"

using namespace oopstd;

namespace oopstd {		//oopstd 내에 헤더파일에서 선언한 함수 정의
	void* memset(void* ptr, int value, size_t num) {		// memset 함수 정의
		char* temp = (char*)ptr;							//void 포인터형의 값을 char포인터 변수에 담기
		for (int i = 0; i < num; i++) {						//값을 하나씩 검사하면서 입력받은 num만큼 반복
			temp[i] = value;								//해당 인덱스를 value로 바꾸기
		}
		return temp;										//temp의 주소값을 반환
	}

	void* memcpy(void* destination, const void* source, size_t num) { // memcpy()함수 정의
		char* temp = (char*)destination;					//void 포인터형의 값을 char포인터 변수에 담기
		char* temp2 = (char*)source;						//void 포인터형의 값을 char포인터 변수에 담기
		int i;
		for (i = 0; i < num; i++) {							//한글자씩 검사(num만큼)
			temp[i] = temp2[i];								//temp2에 현재 인덱스의 값을 temp1의 현재 인덱스에 담기
		}
		return temp;										//temp의 주소값을 반환
	}
	
	int strcmp(const char* str1, const char* str2) {		//strcmp()함수 정의
		for (int i = 0; str1[i]!='\0' || str2[i] != '\0'; i++) {		//두 배열중 하나라도 끝날때까지
			if (*(str1 + i) > *(str2 + i))					//값을 비교하여 앞의 배열이 크면 1 반환
				return 1;
			if (*(str1 + i) < *(str2 + i))					//값을 비교하여 뒤의 배열이 크면 -1 반환
				return -1;
		}
		return 0;											//끝까지 했을때 반복문 밖을 나오면 모두 같다는 의미이므로 0 반환
	}
	int strncmp(const char* str1, const char* str2, size_t num) {	//strncmp()함수 정의
		for (int i = 0; i < num; i++) {						//num사이즈만큼 반복하며 인덱스 검사
			if (*(str1 + i) == *(str2 + i))					//현재 인덱스 값이 같으면
				continue;									//다음 인덱스 검사
			if (*(str1 + i) > *(str2 + i))					//앞 인덱스가 뒤 인덱스보다 큰 값이 오면
				return 1;									//1 반환
			if (*(str1 + i) < *(str2 + i))					//앞 인덱스가 뒤 인덱스보다 작은 값이 오면
				return -1;									//-1 반환
		}
		return 0;											//반복문을 나오게 된다면 0반환(모두 같다는 뜻)
	}

	char* strcpy(char* destination, const char* source) {		//strcpy()함수 선언
		int i;
		for (i = 0; source[i] != '\0'; i++) {					//소스 배열이 끝날때까지 인덱스 하나하나 반복문으로 접근
			destination[i] = source[i];							//도착 배열에 소스 배열 각 인덱스를 저장
		}
		destination[i] = '\0';									//소스가 끝나면 맨 마지막에 널값 입력
		return destination;										//도착 배열 반환
	}

	char* strncpy(char* destination, const char* source, size_t num) {	//strncpy()함수 선언
		int i;
		for (i = 0; i < num; i++) {								//num의 사이즈 만큼 반복문을 반복
			destination[i] = source[i];							//도착 배열에 소스 배열의 한글자씩 붙여넣기
		}
		return destination;										//도착 배열 반환
	}

	size_t strlen(const char* str) {					//strlen()함수 선언
		int i;	
		for (i = 0; str[i] != '\0'; i++);				//i를 카운트 하면서 널값이 올때까지 문자열 검사
		return i;										//i를 반환
	}

	int atoi(const char* str) {							//atoi()함수 선언
		int result = 0;									//결과를 저장할 변수 선언
		for (int i = 0; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++) {		//인덱스의 값이 널이 아니면서 0~9인동안
			result = result * 10 + (str[i] - '0');					//결과 변수의 값을 10을 곱한 후 인덱스의 값을 더해준다.(아스키 기반)
		}
		return result;									//결과 변수의 값을 반환
	}

	float atof(const char* str) {						//atof()함수 선언
		int integer = 0;								//정수부 저장용 변수 선언
		float fractional = 0;							//실수부 저장용 변수 선언
		float num = 0.1;								//실수부 연산용 변수
		float temp = 0;									//실수부 연산용 변수
		int i = 0;
		for (i = 0; str[i] != '.' && str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++) {//.이 오기 전까지 정수부를 연산
			integer = integer * 10 + (str[i] - '0');			//정수부 값을 10 곱하고 인덱스의 값을 더해준다.(아스키 기반)
		}
		for (int i = 0; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++) {			//실수부를 연산
			temp = str[i] * num;								//새로 검사하는 인덱스의 값에 해당 자리수만큼의 10의 음수승을 곱해준다.
			num *= 0.1;											//다음 연산을 위해 10의 음수승을 증가시켜준다.
			fractional += temp;									//해당 자리수의 값을 기본 있던 값에 더해준다.
		}
		return integer + fractional;					//정수부와 실수부의 합을 반환한다.
	}
}
