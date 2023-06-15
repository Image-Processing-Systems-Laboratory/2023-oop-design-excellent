#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int str_compare(const char* str1, const char* str2);    //두 문자열이 일치하는지 검사하는 함수

int main(void)
{
	StudentScoreList List;

	char command[32];               //명령어를 임시 저장할 배열
	double Math, English, Science;  //Math, English, Science 과목 점수
	double average;                 //평균

	while (1) {
		cout << ">>";
		cin >> command;    //명령 입력

		if (!str_compare(command, "Insert")) {             //새로운 노드 추가
			cin >> Math >> English >> Science;          //점수 입력
			average = (Math + English + Science) / 3;   //평균 계산
			cout << "average: " << average << endl;     //평균 출력

			Score* pNew = new Score;                    //새로운 노드 동적 할당
			pNew->SetAvg(average);                      //평균 값 설정
			List.Insert(pNew);                          //Student Score List에 추가
		}
		else if (!str_compare(command, "PrintList")) {     //Student Score List 출력
			cin >> command;                             //오름차순 또는 내림차순 명령 입력

			if (!str_compare(command, "Ascending")) {  //오름차순일 경우 true를 인자로 전달하여 PrintList 함수 호출
				List.PrintList(true);
			}
			else if (!str_compare(command, "Descending")) {  //내림차순일 경우 false를 인자로 전달하여 PrintList 함수 호출
				List.PrintList(false);
			}
			else {
				cout << "Invalid command." << endl;    //잘못된 명령을 입력하였을 때 오류 메시지 출력
			}
		}
		else if (!str_compare(command, "Exit")) {          //반복문 탈출 -> 프로그램 종료
			break;
		}
		else {                                             //잘못된 명령을 입력하였을 때 오류 메시지 출력
			cout << "Invalid command." << endl;
		}
	}

	return 0;
}

//두 문자열이 일치하는지 검사하는 함수
int str_compare(const char* str1, const char* str2) {
	int i = 0;

	while (1) {
		if (str1[i] != str2[i] || (str1[i] == '\0' && str2[i] == '\0')) {  //문자열이 끝나거나 같지 않은 문자를 만날 때까지 반복
			if (str1[i] > str2[i]) {        //str1[i]의 아스키코드 값이 str2[i]보다 큰 경우 1 반환
				return 1;
			}
			else if (str1[i] < str2[i]) {    //str2[i]의 아스키코드 값이 str1[i]보다 큰 경우 -1 반환
				return -1;
			}
			else {                          //같은 문자열이면 0 반환
				return 0;
			}

		}

		i++;
	}
}