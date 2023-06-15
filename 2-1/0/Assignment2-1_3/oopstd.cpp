#include<cmath>


namespace oopstd {

	void* memset(void* ptr, int value, size_t num) {
		//unsigned char형 포인터 선언 후 ptr이 가리키는 메모리 주소 취급
		unsigned char* char_ptr = (unsigned char*)ptr;
		//i가 0부터 num-1까지
		for (int i = 0; i < num; i++)
			char_ptr[i] = (char)value;	//char_ptr[i]에 value값을 저장함

		return ptr;		//ptr 반환
	}
	void* memcpy(void* destination, const void* source, size_t num) {
		//char형 포인터 선언 후 ptr이 가리키는 메모리 주소 취급
		char* char_dest = (char*)destination;

		//const char형 포인터 선언 후 ptr이 가리키는 메모리 주소 취급
		const char* char_source = (const char*)source;
		//i가 0부터 num-1까지
		for (int i = 0; i < num; i++)
			char_dest[i] = char_source[i];	//char_source[i]에 저장된 값을 char_dest[i]에 저장함
		return destination;		//destination 반환
	}

	int strcmp(const char* str1, const char* str2) {
		//i가 0부터 str1[i] 또는 str2[i]가 null문자를 만나기 전까지 반복
		for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
			if (str1[i] != str2[i])			//str1[i]와 str2[i]가 다르면
				return str1[i] > str2[i] ? 1 : -1;	//str1[i]가 더 크면 1 반환 str2[i]가 더 크면 2 반환

		return 0;		//같으면 0 반환
	}
	int strncmp(const char* str1, const char* str2, size_t num) {
		//i가 0부터 num-1까지
		for (int i = 0; i < num; i++)
			if (str1[i] != str2[i])			//str1[i]와 str2[i]가 다르면
				return str1[i] > str2[i] ? 1 : -1;	//str1[i]가 더 크면 1 반환 str2[i]가 더 크면 2 반환
		return 0;	//같으면 0 반환
	}

	char* strcpy(char* destination, const char* source) {
		int i;		//int형 변수 선언
		//i가 0부터 source[i]가 null문자를 만나기전 까지
		for (i = 0; source[i] != '\0'; i++)
		{
			destination[i] = source[i];	//source[i]를 destination[i]에 저장
		}
		destination[i] = '\0';	//null문자 저장

		return destination;		//destination 반환
	}
	char* strncpy(char* destination, const char* source, size_t num) {
		//i가 0부터 num-1까지
		for (int i = 0; i < num; i++)
		{
			if (source[i] != '\0')	//source[i] != '\0'이면
			{
				destination[i] = source[i];	//source[i]를 destination[i]에 저장
				continue;					//다음 반복문 시행
			}
			else					//source[i] == '\0'이면
			{
				destination[i] = '\0';	//null문자 저장
				break;					//반복문 탈출
			}
		}
		
		return destination;			//destination 반환
	}

	size_t strlen(const char* str) {
		size_t len = 0;		//길이를 저장할 변수 선언 및 0으로 초기화
		for (int i = 0; str[i] != '\0'; i++)	//i가 0부터 str[i]가 null문자를 만나기전 까지
			len++;		//len의 값을 1증가시킴
	
		return len;		//len 반환
	}

	int atoi(const char* str) {
		int int_num = 0;
		int pos = 1;		//음수이면 0 양수이면 1을 저장
		//정수 저장
		for (int i = 0; str[i] != '\0'; i++)	//i가 0부터 str[i]가 null문자를 만나기전 까지
		{
			//첫번째 문자가 음수이면
			if (str[0] == '-')
			{
				pos = 0;		//pos를 0으로 초기화
				continue;		//다음 반복문 시행
			}
			//str[i]의 문자가 '0'~'9'이면
			if (str[i] >= '0' && str[i] <= '9')
				int_num = int_num * 10 + (str[i] - '0');
			else		//str[i]가 문자이면
				break;	//반복문 탈출
		}
		//음수이면
		if (pos == 0)
			int_num *= -1;		//저장된 값에 -1을 곱함

		return int_num;			//int_num 반환
	}
	float atof(const char* str) {
		float float_num = 0;	//str에 저장된 실수를 저장
		int pos = 1;		//음수이면 0 양수이면 1을 저장
		int decimal_point = 0;	//소수점 수 저장
		for (int i = 0; str[i] != '\0'; i++)	//i가 0부터 str[i]가 null문자를 만나기전 까지
		{
			//첫번째 문자가 음수이면
			if (str[0] == '-')
			{
				pos = 0;		//pos를 0으로 초기화
				continue;		//다음 반복문 시행
			}
			//실수 부분 저장
			//str[i]의 문자가 '0'~'9'이면
			if (str[i] >= '0' && str[i] <= '9')
				float_num = float_num * 10 + (str[i] - 48);
			
			//소수점이 나오면
			else if (str[i] == '.')
			{
				//소수점 부분 저장
				//j=i+1부터 str[j]가 null 문자를 만나기 전까지
				for (int j = i + 1; str[j] != '\0'; j++)
				{
					//str[i]의 문자가 '0'~'9'이면 str[i]를 소수점 부분으로 저장
					if (str[j] >= '0' && str[j] <= '9')
						float_num = float_num + (str[j] - '0') * pow(10, -(++decimal_point));
					else	//str[i]가 문자이면
						break;	//반복문 탈출
				}
				break;	//반복문 탈출
			}
			else		//str[i]가 문자이면
				break;	//반복문 탈출
		}
		//음수이면
		if (pos == 0)
			float_num *= -1;	//저장된 값에 -1을 곱함

		return  float_num;		//float_num 반환
	}

}