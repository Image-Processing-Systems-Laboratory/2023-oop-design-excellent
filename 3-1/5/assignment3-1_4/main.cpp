#include "Stack.h"
#include <iostream>

using namespace std;

int str_compare(const char* str1, const char* str2);      //두 문자열이 일치하는지 검사하는 함수

int main(void) {
	Stack queue;              //Stack
	Node* node;               //새로 추가할 Node
	Node* popNode;            //노드 삭제 후 반환한 값
	char command[20];         //명령어
	int key;                  //노드에 저장할 값
	int size;                 //Stack의 크기

	//Stack의 size 설정
	cout << "Size of Stack: ";
	cin >> size;
	queue.SetSize(size);
	cout << "=================================" << endl;

	//command 입력
	while (1) {
		cout << ">> ";
		cin >> command;

		if (!str_compare(command, "Push")) {             //Push 입력 : 새로운 노드 추가
			cin >> key;

			node = new Node;            //새로운 노드 동적할당

			//key를 노드에 저장
			node->SetData(key);

			//Stack에 새로 만든 노드 추가
			if (!queue.Push(node)) {
				cout << "Stack is full." << endl;  //Stack이 가득 찬 경우 더이상 새로운 노드를 저장할 수 없다는 메시지 출력
			}
		}
		else if (!str_compare(command, "Pop")) {         //Pop 입력 : 노드 삭제
			popNode = queue.Pop();       //노드 삭제

			if (popNode != nullptr) {
				cout << popNode->GetData() << endl;  //삭제한 노드 출력
				delete popNode;              //노드 메모리 해제
			}
			else {
				cout << "Stack is Empty." << endl;    //Stack가 비어있는 경우 삭제할 노드가 없다는 메시지 출력
			}
		}
		else if (!str_compare(command, "IsEmpty")) {     //IsEmpty 입력 : Stack이 비어있는 상태인지 아닌지 출력
			if (queue.IsEmpty()) {
				cout << "1 (Empty)" << endl;      //비어있는 경우
			}
			else {
				cout << "0 (Not Empty)" << endl;  //비어있지 않은 경우
			}
		}
		else if (!str_compare(command, "IsFull")) {      //IsFull 입력 : Stack이 가득 차 있는 상태인지 아닌지 출력
			if (queue.IsFull()) {
				cout << "1 (Full)" << endl;      //가득 찬 경우
			}
			else {
				cout << "0 (Not Full)" << endl;  //가득 차지 않은 경우
			}
		}
		else if (!str_compare(command, "PrintStack")) {  //PrintStack 입력 : Stack의 모든 노드의 data 출력
			queue.PrintStack();
		}
		else if (!str_compare(command, "Exit")) {        //Exit 입력 : 반복문 종료 -> 프로그램 종료
			break;
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