#include <iostream>
#include <cctype>
#include <string.h>

enum e_type // 원소의 타입
{
	STR,
	ARR
};

struct Data // 배열에 들어갈 데이터
{
	int type; // 타입
	void* data; // 해당 원소를 가리키는 포인터
};

class Arr // 배열 클래스
{
public:
	Arr(int length) // 생성자에서 원소의 갯수 받음
		: len(0), arr(new Data[length]) // 공간 할당
	{}
	~Arr(void) // 소멸자에서 메모리 해제
	{
		for (int i = 0; i < len; i++)
		{
			if (arr[i].type == ARR) // 원소가 배열일 경우 해당 배열 해제
				delete (Arr*)arr[i].data;
			else
				delete[](char*)arr[i].data; // 문자열일 경우 문자열 해제
		}
		delete[] arr; // 현재 객체의 배열 해제
	}

	void push_back(Data data) // 배열 뒤에 원소 삽입
	{
		arr[len++] = data;
	}

	void print_data(int* idx) // 인덱스 리스트를 받아 해당 인덱스의 원소 출력
	{
		int i = 0;
		Arr* cur = this; // 자기 자신을 가리키는 포인터

		if (idx[0] == -1) // 인덱스가 없을 경우 전체 출력
		{
			print_arr(cur, cur->len); // 자기 자신 출력
			std::cout << std::endl; // 개행 출력
			return;
		}
		while (idx[i] != -1) // 인덱스 리스트가 끝날 때까지
		{
			if ((cur->arr[idx[i]]).type == STR) // 문자열이라면 반복문 종료
				break;
			cur = (Arr*)(cur->arr[idx[i]]).data; // cur에 nested 배열 주소 저장
			i++;
		}
		if ((cur->arr[idx[i]]).type == STR) // 해당 인덱스가 가리키는 것이 문자열
		{
			std::cout << (char*)(cur->arr[idx[i]]).data; // 문자열 출력
		}
		else // 해당 인덱스가 가리키는 것이 배열
		{
			print_arr(cur, cur->len); // 배열 출력
		}
		std::cout << std::endl;
	}
	static void print_arr(Arr* array, int length) // 인자로 배열과 배열 길이 받아 배열 출력
	{
		std::cout << '['; // 대괄호 출력
		for (int i = 0; i < length; i++) // 해당 배열을 순회
		{
			if (array->arr[i].type == STR) // 원소가 문자열일 경우
			{
				std::cout << (char*)array->arr[i].data; // 문자열 출력
			}
			else // 원소가 배열일 경우
			{
				// 해당 배열 출력
				print_arr((Arr*)array->arr[i].data, ((Arr*)array->arr[i].data)->len);
			}
			if (i != length - 1) // 마지막 원소가 아닐 경우 뒤에 쉼표 출력
				std::cout << ", ";
		}
		std::cout << ']'; // 닫는 대괄호 출력
	}
private:
	Data* arr; // data의 배열을 가리키는 포인터
	int len; // 배열의 길이
};

int arr_cnt(char* str) // 인자로 넘어온 곳의 배열의 원소의 갯수
{
	int brack = 0;
	int cnt = 0;
	int i = 0;

	while (str[i]) // 문자열 순회
	{
		if (brack == 0 && str[i] == ',') // 쉼표가 나오면 원소 갯수 + 1
			cnt++;
		else if (str[i] == '[') // 여는 대괄호는 nested 배열
			brack++;
		else if (brack && str[i] == ']') // nested 배열의 종료
			brack--;
		else if (brack == 0 && str[i] == ']') // 원래 배열의 종료 부분
			break;
		i++;
	}
	return (cnt + 1); // 원소는 쉼표 + 1개 있으므로
}

int arr_len(char* str) // 인자로 넘어온 곳부터 배열이 끝나기까지의 길이
{
	int brack = 0; // nested 깊이
	int i = 0;

	while (str[i]) // 문자열 순회
	{
		if (str[i] == '[') // 대괄호의 경우 nested 배열
			brack++;
		else if (brack && str[i] == ']') // nested 배열의 끝 부분
			brack--;
		else if (brack == 0 && str[i] == ']') // 원 배열의 끝 부분
			break;
		i++;
	}
	return (i); // 길이 반환
}

int str_len(char* str) // 하나의 문자열 원소의 길이
{
	int i = 0;

	while (str[i]) // 문자열 순회
	{
		if (!isalnum(str[i])) // 영문이나 숫자가 아닌 것이 나오면 종료
			break;
		i++;
	}
	return (i); // 길이 리턴
}

char* strndup(const char* s, size_t len) // 부분 문자열 복사본 리턴
{
	char* ret_str = new char[len + 1]; // 복사본 공간 할당

	int i = 0;
	while (i < len) // len 만큼 복사
	{
		ret_str[i] = s[i];
		i++;
	}
	ret_str[i] = 0; // 마지막에 널문자 삽입
	return (ret_str); // 복사본 반환
}

Arr* make_arr(char* str) //파싱 및 배열 제작
{
	int i = 0;
	int len = arr_cnt(str); // 현재 str을 파싱하면 나오는 배열의 원소 갯수(nested는 하나로 간주)

	Arr* ret_arr = new Arr(len); // 배열 객체 할당
	Data temp;
	while (str[i]) // 문자열 순회
	{
		if (isalnum(str[i])) // 만약 알파벳 또는 숫자를 만날 경우
		{
			temp.type = STR; // 타입을 문자열로 표시
			temp.data = (void*)strndup(&str[i], str_len(&str[i])); // 해당 문자열 복사본 저장
			ret_arr->push_back(temp); // 배열에 삽입
			i += str_len(&str[i]) - 1; // 인덱스를 문자열 끝으로 옮김
		}
		else if (str[i] == '[') // 만약 대괄호가 나올 경우 nested 배열로 판단
		{
			temp.type = ARR; // 타입을 배열로 표시
			temp.data = (void*)make_arr(&str[i + 1]); // make arr 함수를 해당 문자열 위치를 넘겨 호출
			ret_arr->push_back(temp); // 나온 배열을 원 배열에 삽입
			i += arr_len(&str[i + 1]) + 1; // 해당 nested배열의 끝까지 인덱스를 옮김
		}
		else if (str[i] == ']') // 닫는 대괄호가 나올 경우 배열의 끝
			break;
		i++;
	}
	return (ret_arr); // 만들어진 배열 리턴
}

int* input_idx_parse(char* input) // 인덱스 파싱 함수
{
	int idx_num = 0;
	int i;
	int cnt = 1;
	int* ret_arr;

	// 유효하지 않은 입력 또는 exit의 경우 NULL리턴
	if (strcmp(input, "exit") == 0 || strlen(input) < 3)
		return (NULL);
	i = 0;
	while (input[i]) // 대괄호의 갯수를 세서 인덱스 갯수 측정
	{
		if (input[i] == '[')
			cnt++;
		i++;
	}
	ret_arr = new int[cnt]; // 배열 할당
	if (cnt == 1) // 인덱스가 없는 경우(전체 배열 출력)
	{
		ret_arr[0] = -1; // -1을 담아 리턴
		return (ret_arr);
	}
	i = 4;
	while (input[i]) // "arr["는 넘기고 이후부터 출력
	{
		ret_arr[idx_num++] = atoi(&input[i]); // 숫자로 변환해서 배열에 저장
		while (input[i] && isdigit(input[i])) // 해당 숫자 건너 뜀
			i++;
		while (input[i] && !isdigit(input[i])) // 다음번 숫자까지 이동
			i++;
	}
	ret_arr[idx_num] = -1; // 마지막 칸에 -1을 넣어 마지막임을 표시
	return (ret_arr); // 인덱스 배열 반환
}

int main(void)
{
	char input[100001];
	Arr* arr;
	int i = 0;
	int* idx_list;

	std::cin.getline(input, 100001); // 입력 받기
	while (input[i] != '[') // 공백 건너뛰기
		i++;
	arr = make_arr(&input[i + 1]); // 첫 입력(배열) 파싱 및 저장

	std::cin.getline(input, 100001); // 입력 받기
	idx_list = input_idx_parse(input); // 인덱스 값 파싱
	while (idx_list) // exit 들어올 때까지 (인덱스 파싱 함수에서 NULL 리턴시까지)
	{
		arr->print_data(idx_list); // 해당 인덱스에 해당하는 값 출력
		delete[] idx_list; // 인덱스 배열 해제
		std::cin.getline(input, 100001); // 입력 받기
		idx_list = input_idx_parse(input); // 인덱스 파싱
	}
	delete arr; // 배열 해제
}