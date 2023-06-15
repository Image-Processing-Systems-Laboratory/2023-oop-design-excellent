#include<iostream>
#include <cstdlib>

using namespace std;

int main(void) {

	int num;

	int i = 0, j=0;

	char * input;
	
	input = (char*)malloc(sizeof(char)); // input 포인터 동적 할당

	int  stack[128];
		
	if (input == NULL) {
		cout << "Falied to allocate memory" << endl;
		exit(1);
	} // 에러 시 프로그램 종료

	cout << "Program is now running. Enter the commend:" << endl;

	while (1) { 

		cin >> input;

		if (strcmp(input, "exit") == 0) { //입력이 "exit"인 경우
			cout << "Program is now terminated." << endl;
			return 0;
		}
		else if (strcmp(input, "push") == 0) { //입력이 "push"인 경우
			if (i < 128) {
				cin >> num;
				stack[i] = num; //스택에 입력받은 정수를 저장
				i++;
			}
			else {
				cout << "Stack is full" << endl;
			}
		}
		else if (strcmp(input, "pop") == 0) { //입력이 "pop"인 경우
			if (i > 0) {
				cout << stack[i - 1] << endl; //스택의 가장 위에 있는 정수를 출력
				i--;
			}
			else {
				cout << "Stack is empty" << endl;
			}
		}
		else if (strcmp(input, "top") == 0) { //입력이 "top"인 경우
			if (i > 0) {
				cout << stack[i - 1] << endl; //스택의 가장 위에 있는 정수를 출력
			}
			else {
				cout << "Stack is empty" << endl;
			}
		}
		else if (strcmp(input, "print") == 0) { //입력이 "print"인 경우
			
			for (j = 0; j < i; j++) {
				cout << stack[j] << " "; //스택에 있는 정수를 출력
			}
			cout << endl;
		}
		else if (strcmp(input, "empty") == 0) { //입력이 "empty"인 경우

			if (i == 0) {
				cout << "1" << endl; //스택이 비어있는 경우
			}
			else {
				cout << "0" << endl; //스택이 비어있지 않은 경우
			}
		}
		else {
			cout << "Invalid commend. Please enter again." << endl; //입력이 "exit", "push", "pop", "top", "print", "empty"가 아닌 경우
		}
	}
	free(input);// 동적 할당 해제
	return 0;
}