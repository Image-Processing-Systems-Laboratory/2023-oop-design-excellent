//2022202040 정우성

#include <iostream>

char* my_strtok(char* str);

int main()
{
	// 문자열 입력받기
	char input[100];
	std::cin >> input;
	char* ptr = my_strtok(input); // 처음 문자열을 자름
	while (ptr != NULL) 
	{
		//자른 문자열 출력 후 그 후의 문자열을 자름
		std::cout << ptr << std::endl;
		ptr = my_strtok(NULL);
	}

	return 0;
}

char* my_strtok(char* str)
{
	int i = 0; //문자열 첨자 접근
	char* cur; // 문자열의 처음 첨자 주소값 저장
	static char* pre; // 이전에 잘랐던 위치 다음 첨자의 주소값 저장

	if (str == NULL) { //매개변수로 NULL을 받은 경우
		cur = pre; // 전에 잘랐던 위치의 다음 첨자부터 검사
	}
	else { //매개변수로 문자열을 받은 경우
		cur = str; //문자열의 처음부터 검사 시작
	}

	if (cur[i]==NULL) //문자열이 끝나면 NULL 반환
		return NULL;

	while (1)
	{
		if (cur[i] == '@' || cur[i] == '.' || cur[i]==NULL) { // '@', '.', 'NULL'을 만난 경우
			if (cur[i] == NULL) { // NULL문자를 만나면 NULL문자를 만난 첨자의 주소값을 pre에 대입
				pre = &cur[i];
			}
			else { // '@' 또는 '.'을 만난 경우
				pre = &cur[i + 1]; // '@' 또는 '.' 다음 첨자를 pre에 대입
				cur[i] = NULL; // '@' 또는 '.'을 NULL문자로 바꿈
			}
			break;
		}
		i++;
	}

	return cur;

}