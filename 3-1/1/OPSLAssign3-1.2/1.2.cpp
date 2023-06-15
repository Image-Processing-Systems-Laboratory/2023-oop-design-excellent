#include <iostream>
#include <cstring>

int delimiter(const char* str)
{
	for (int i = 0; str[i] != '\0'; i++)		// 문자열의 시작부터 끝까지 검사한다.
	{
		if (str[i] == '@' || str[i] == '.')		// @ 또는 . 이 있으면 그 index인 i를 반환한다.
		{
			return i;
		}
	}
	return strlen(str);	// 없다면, 즉 
}

char* my_strtok(char* str)
{
	static char* start = nullptr;	// 정적 변수 start
	static char* next = nullptr;	// 정적 변수 next

	if (str != nullptr)	// str에 값이 있다면 str부터 시작 (초기 상태)
		start = str;

	else if (next != nullptr)	// next에 값이 있다면 next부터 시작 (다음 상태)
		start = next;

	else
		return nullptr;	// 이외의 경우(다음 상태에서 next가 문자열의 끝)

/////////////////////////////////////////////////////////////////////////////////////////

	int block = delimiter(start);	// 시작 문자열에서 delimiter (@, .)이 시작되는 위치

	char* end = start + block;		// example@gmail.com
									// s------b end는 example에서 
	if (*end == '\0')		// 문자열의 끝이라면 다음 상태는 nullptr(중지)
		next = nullptr;
	else
	{
		*end = '\0';		// s------\0 -> start는 \0까지 "example"이 된다.
		next = end + 1;		// 다음 상태는 \0 다음의 g 부터 시작
	}

	return start;
}

int main()
{
	char str[256];
	std::cout << "Email address: ";	// 입력
	std::cin >> str;

	char* token = my_strtok(str);

	while (token != nullptr)	// 문자열의 끝에 도달할 때 중지
	{
		std::cout << token << std::endl;	// delimiter 이전의 문자열을 출력
		token = my_strtok(nullptr);			// 이미 next에 문자열이 저장되어 있기에 다음 상태로 넘어가기 위해 nullptr 전달
	}

	return 0;
}