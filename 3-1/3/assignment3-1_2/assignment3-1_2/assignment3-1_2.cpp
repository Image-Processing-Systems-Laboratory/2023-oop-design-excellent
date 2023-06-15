#include<iostream>
using namespace std;

int my_strlen(char* str);			//문자열의 길이를 반환하는 함수
char* my_strtok(char* str);			//문자열을 .과 @를 기준으로 나눠주는 함수

int main(void) {
	char email[200];				//이메일을 저장할 문자열
	cin >> email;					//이메일을 입력받음
	char* list;						//임시로 반환값을 저장할 문자열
	list = my_strtok(email);		//my_strtok함수를 실행해 list에 저장한다.
	while (list != NULL) {			//list가 NULL이 오지 않을동안 반복
		cout << list << endl;		//list를 출력
		list = my_strtok(email);	//list에 새로 my_strtok함수를 실행하여 값을 저장
	}

	return 0;		//main함수 반환
}

int my_strlen(char* str) {			//문자열의 길이를 반환하는 함수
	{
		if (str == nullptr) return 0;		//문자열이 비어있다면 0 반환
		int len = 0;		//길이 변수 0으로 초기화
		while (str[len++] != '\0');		//str[len]이 Null이 아닐때동안 len++
		return len - 1;		//len-1을 반환해줌
	}
}

char* my_strtok(char* str) {		//문자열을 .과 @를 기준으로 나눠주는 함수
	static int idx = 0;				//함수 실행때마다 인덱스 값을 저장해줄 변수 처음 선언때는 0으로 초기화
	if (idx > my_strlen(str)) {		//현재 인덱스가 문자열 길이보다 벗어나면
		return NULL;				//NULL 반환
	}
	char* arr = new char[my_strlen(str) + 1];		//반환할 문자열은 입력받은 문자열+1 크기만큼 동적할당받았다
	int j = 0;			//j = 0(arr의 인덱스에 접근할 변수)
	for (idx; str[idx] != '@' && str[idx] != '.' && str[idx] != '\0'; idx++) {//str[idx]가 @, ., NULL이 아닐때까지 idx를 1씩 증가시켜줌
		arr[j++] = str[idx];			//arr[j]에 str[idx]값을 넣어줌
	}
	while (str[idx] == '\0' || str[idx] == '.' || str[idx] == '@') {	//만약 str[idx]가 null, ., @라면
		idx++;			//idx를 ++시켜 .이나 @가 없을때가 다음 인덱스의 시작으로 가게 한다.
	}
	arr[j] = '\0';			//반환할 문자열 마지막 글자에 null을 넣어줌
	return arr;				//arr 반환
}