#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

int main(void) {
	int stack[128] = { 0 };
	int stackIndex = 0;
	bool isEmpty = true;
	while (stackIndex < 128) {
		/*command 입력*/
		char input[100] = { 0 };
		cin >> input;
		int num = 0;
		/*command가 exit이면 break;*/
		if (strcmp(input, "exit") == 0) {
			break;
		}
		/*command가 push면 num을 입력받고 stack배열에 num을 저장함*/
		else if (strcmp(input, "push") == 0) {
			cin >> num;
			stack[stackIndex++] = num;
			isEmpty = false;	//stack이 비었나 확인하는 변수
		}
		/*command가 print면 출력*/
		else if (strcmp(input, "print") == 0) {
			for (int i = 0; i < stackIndex; i++) cout << stack[i] << ' ';
			cout << endl;
		}
		/*command가 pop이면*/
		else if (strcmp(input, "pop") == 0) {
			/*stack이 비어있으면 isEmpty에 true를 넣고 continue;*/
			if (stackIndex == 0) {
				isEmpty = true;
				continue;
			}
			/*stackIndex 마이너스 1*/
			stackIndex -= 1;
			/*그 인덱스에 있는 배열을 출력함*/
			cout << stack[stackIndex];
			stack[stackIndex] = '\0';
			if (stackIndex == 0) isEmpty = true;
			cout << endl;
		}
		/*command가 top이면*/
		else if (strcmp(input, "top") == 0) {
			/*비어있는 배열이면 continue*/
			if (stackIndex == 0) continue;
			/*가장 위에 값을 출력함*/
			else cout << stack[stackIndex - 1];
			cout << endl;
		}
		/*command가 empty면*/
		else if (strcmp(input, "empty") == 0) {
			/*비어있으면 1출력*/
			if (isEmpty) cout << 1;
			/*안비어있으면 0출력*/
			else cout << 0;
			cout << endl;
		}
		/*이상한거 입력했을 때 */
		else {
			cout << "Enter the given input ! ";
			cout << endl;
		}
	}
	return 0;
}