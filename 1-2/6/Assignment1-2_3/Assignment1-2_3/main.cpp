#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>

#define WILD_STAR '*'
#define WILD_Q '?'

int	word_cnt(char* s) // 문자열에 *로 구분되는 부분 문자열이 몇 갠지 셈
{
	bool flag = false; // 현재 단어위에 있는지 여부
	int cnt = 0; // 부분 문자열 갯수

	if (!s) // 혹시나 해서 예외처리
		return (0);
	while (*s) // 문자열 순회
	{
		if (!flag && *s != WILD_STAR) // 단어를 만나면
		{
			flag = true; // 단어 위에 있음을 표시
			cnt++; // 단어 갯수 증가
		}
		else if (flag && *s == WILD_STAR) // 단어인 상태에서 *을 만나면
			flag = false; // *위에 있음을 표시
		s++;
	}
	return (cnt); // 갯수 리턴
}

int	word_len(char* s) // *로 구분되는 부분 문자열의 길이를 측정
{
	int cnt;

	cnt = 0;
	while (*s && *s != WILD_STAR) // 문자열 전체가 끝나거나 *이 나올 때까지 순회
	{
		cnt++; // 길이를 잼
		s++;
	}
	return (cnt); // 길이를 리턴
}

char** wildcard_split(char* s) // 전체 문자열을 *을 기준으로 부분 문자열들로 쪼갬
{
	char** re_loc; // 리턴할 문자열 배열
	bool flag = false; // 현재 단어 위에 있는지 여부
	int idx = 0; // 부분 문자열 갯수
	int len; // 부분 문자열 길이

	if (!s)
		return (NULL);
	re_loc = new char* [word_cnt(s) + 1]; // 부분 문자열의 갯수만큼 char * 배열 할당
	while (*s) // 문자열 순회
	{
		if (!flag && *s != WILD_STAR) // 단어를 만나면
		{
			flag = true; // 단어 위에 있음 표시
			len = word_len(s); // 부분문자열 길이 잼
			re_loc[idx] = new char[len + 1]; // 문자열 할당
			strncpy(re_loc[idx], s, len + 1); // 부분문자열 길이만큼 복사
			re_loc[idx][len] = 0; // 널 문자 붙여줌
			idx++; // 부분문자열 갯수 증가
		}
		else if (flag && *s == WILD_STAR) // *를 만나면
			flag = false; // * 위임을 표시
		s++;
	}
	re_loc[idx] = NULL; // 문자열 배열 마지막에 NULL을 붙임
	return (re_loc); // 문자열 배열 리턴
}

int wild_strncmp(const char* patt, const char* s, int n) // ?를 고려한 문자열 비교
{
	if (!n)
		return (true);
	while (*patt && *s && --n) // 문자열을 최대 n번 순회
	{
		// 문자열이 매칭되지 않는 경우
		// 이 때 패턴 문자열이 ?라면 그냥 넘어간다
		if (*patt != WILD_Q && *patt != *s)
		{
			return (false); // false 리턴
		}
		patt++;
		s++;
	}
	if (*s == *patt || (*patt == WILD_Q && *s)) // 문자열이 마지막까지 매칭되는 경우
		return (true);
	return (false);
}

char* wild_strstr(char* str, char* patt, int n) // ?문자를 고려한 부분문자열 탐색
{
	int i = 0;
	int patt_len = strlen(patt); // 패턴 문자열의 길이

	if (!*patt) // 패턴 문자열이 빈 문자열일 경우 str의 시작 위치의 빈 문자열로 간주
		return (str);
	if (!*str || n < patt_len)
		return (NULL);
	while (str[i] && i < n - patt_len + 1) // 최대 n의 길이 안에서 부분문자열 탐색
	{
		if (wild_strncmp(patt, &str[i], patt_len)) // 만약 일치하는 부분문자열이 있으면
			return (&str[i]); // 해당 위치의 포인터 리턴
		i++;
	}
	return (NULL); // 부분 문자열 찾지 못함
}

//s 라는 바닐라 문자열이 patt에 매칭되는가?
bool	pattern_matching(char** patt, char* s, bool front, bool last)
{
	int i = 0;
	char* ptr;

	if (front) // 만약 *으로 시작하지 않을 경우
	{
		// 맨 앞부분이 정확히 같아야 한다.
		if (!wild_strncmp(patt[0], s, strlen(patt[0])))
		{
			return (false);
		}
	}
	ptr = s; // 순회를 위해 포인터 대입
	while (patt[i]) // 패턴 문자열 배열을 순회
	{
		ptr = wild_strstr(ptr, patt[i], strlen(ptr)); // 패턴 문자열이 나오는지 탐색
		if (!ptr) // 없으면 패턴 불일치
			return (false);
		ptr += strlen(patt[i]); // 있다면 해당 패턴 문자열의 끝 부분으로 포인터 옮김
		i++;
	}
	if (last) // 만약 *으로 끝나지 않을 경우
	{
		// 맨 뒷부분이 정확히 같아야 한다. 
		if (!wild_strncmp(patt[i - 1], &s[strlen(s) - strlen(patt[i - 1])], \
			strlen(patt[i - 1])))
			return (false);
	}
	return (true);
}

void	free_v(char** data) // (끝이 NULL로 끝나는)2차원 배열 해제
{
	int i = 0;;

	while (data[i])
		free(data[i++]);
	free(data);
}

void	file_error(void) // 파일 오픈 에러
{
	std::cerr << "file open error!" << std::endl;
	exit(EXIT_FAILURE);
}

// txtname에 있는 문자열들을 patt문자열의 패턴과 매칭시켜 맞으면 출력
void	filelist_output(char* patt, char* txtname)
{
	std::ifstream fs;
	char filename[100];
	char** pattern = wildcard_split(patt); // 패턴은 패턴 문자열을 *을 기준으로 나눈 부분 문자열 배열

	fs.open(txtname); // 텍스트 파일 열기
	if (!fs.is_open()) // 파일열기 에러
		file_error();
	fs.getline(filename, 100); // 한 줄을 읽음
	while (fs) // 파일의 끝까지 읽을 때까지(또는 읽기의 오류가 날 때까지)
	{
		if (*pattern == NULL \
			|| pattern_matching(
				pattern, filename,
				patt[0] != WILD_STAR, patt[strlen(patt) - 1] != WILD_STAR
			)) // 입력이 *만으로 이루어져 있거나 읽은 줄이 패턴과 일치하면 출력
			std::cout << filename << std::endl;
		fs.getline(filename, 100); // 다음 줄을 읽음
	}
	fs.close(); // 파일 닫음
	free_v(pattern); // 패턴 부분문자열배열 해제
}

void	wildcard(char** input, char* txtname)
{
	int i = 0;

	while (input[i]) // 모든 입력을 순회하며 패턴매칭 실행
	{
		filelist_output(input[i], txtname);
		i++;
	}
}

int main(void)
{
	char filename[100];
	int input_num;
	char** input;
	int i = 0;


	std::cout << "Input file name :";
	std::cin >> filename; // 파일 이름 입력
	std::cin >> input_num; // 입력의 갯수
	if (!std::cin)
		exit(EXIT_FAILURE);
	input = new char* [input_num + 1]; //입력 버퍼 할당
	while (i < input_num)
	{
		input[i] = new char[100]; // 입력 문자열 할당
		std::cin >> input[i]; // 입력받음
		i++;
	}
	input[i] = NULL;
	wildcard(input, filename); // 입력에 대한 실행 및 출력
	free_v(input); // 입력 버퍼 해제
	return (0);
}