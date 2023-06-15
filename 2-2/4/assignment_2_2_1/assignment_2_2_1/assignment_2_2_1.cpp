#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

typedef struct List {				//리스트 구조체
	char* str;							//문자열
	List* list;							//하위 리스트 포인터
	List* next;							//링크드리스트를 위한 포인터
}List;

char* input;
List* new_list();						//새 리스트 추가 함수
void memory_delete(List* start);		//메모리 할당 해제 함수

int main() {
	List* list_tmp;
	List* list;
	List* output;

	list = new List;
	list->str = new char[1001];

	char command[100001];
	char* com;
	input = new char[100001];

	cin.getline(input, 100000);					//문자열 전역변수에 저장
	input = &input[1];

	list->list = new_list();					//리스트 첫 주소 반환
	list_tmp = list->list;
	strcpy(list->str, "[");						//전체 리스트 출력을 위해 전체 리스트 문자열화하여 저장
	while (list_tmp != NULL) {
		strcat(list->str, list_tmp->str);
		if (list_tmp->next) {
			strcat(list->str, ", ");
		}
		list_tmp = list_tmp->next;
	}
	strcat(list->str, "]");



	while (1) {								//명령을 입력 받아 해당 위치의 문자열을 출력
		bool flag = 0;
		output = list;
		cin >> command;							//명령 입력 받아 저장

		if (!strcmp(command, "exit")) {			//exit이면 메모리 해제 후 종료
			memory_delete(list->list);
			delete[] list->str;
			delete[] list;
			cout << "Memory Free Success." << endl;
			return 0;
		}

		com = strtok(command, "[");				//[까지 끊고
		com = strtok(NULL, "]");				//]까지 또 끊음

		while (com != NULL) {					//값이 존재하면 계속 반복
			if (com[0] == '[')						//브라켓 있을 때 브라켓 건너뛰기
				com = &com[1];
			int lim = atoi(com);					//정수형으로 변환하여 저장

			output = output->list;
			for (int i = 0; i < lim && output; i++) {			//입력한 횟수만큼 이동
				output = output->next;
				flag = 1;
			}

			com = strtok(NULL, "]");				//]로 끊기
		}

		cout << output->str << endl;			//해당 위치 출력
	}
}

List* new_list() {
	List* ptr, * head, * tail;
	List* l_ptr;
	char ch[2];
	ch[1] = '\0';
	tail = ptr = NULL;
	head = new List;
	head->str = new char[1001];
	head->next = NULL;
	head->list = NULL;
	memset(head->str, '\0', 1001);
	ptr = tail = head;
	while (*input) {
		ch[0] = *input;
		if (*input != '[' && *input != ']' && *input != ' ' && *input != ',') {	//문자일 때 마지막 구조체의 문자열에 문자 이어서 저장
			strcat(tail->str, ch);
		}
		else if (*input == ' ');		//공백일 때 무시

		else if (*input == ',') {		//쉼표일 때 새로운 구조체 할당, 문자열 할당, 초기화
			ptr = new List;
			ptr->str = new char[1001];
			memset(ptr->str, '\0', 1001);
			tail->next = ptr;
			tail = ptr;
			tail->list = NULL;
			tail->next = NULL;
		}

		else if (*input == '[') {		//새로운 리스트 생성
			input = &input[1];
			tail->list = new_list();		//새로운 리스트 주소를 마지막 구조체의 리스트 포인터에 저장
			l_ptr = tail->list;
			strcpy(tail->str, "[");				//문자열에 리스트를 문자열화하여 저장
			while (l_ptr) {
				strcat(tail->str, l_ptr->str);
				if (l_ptr->next) {
					strcat(tail->str, ", ");
				}
				l_ptr = l_ptr->next;
			}
			strcat(tail->str, "]");
		}

		else if (*input == ']') {		//리스트 시작 주소 반환
			return head;
		}
		input = &input[1];
	}
}

void memory_delete(List* start) {			//메모리 할당 해제 함수
	List* ptr,*x;
	ptr = start;
	while (ptr) {
		x = ptr;
		ptr = ptr->next;
		if (x->list) {					//하위 리스트 존재 시 함수 실행
			memory_delete(x->list);
		}
		delete[] x->str;
		delete[] x;
	}
}