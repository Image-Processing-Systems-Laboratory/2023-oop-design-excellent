#include <iostream>

using namespace std;

// stack 클래스 선언 및 기능 구현
class stack {
	// 128크기의 stack 배열 선언
	int arr[128] = {};
	int cnt = 0;
public:
	// push함수 구현
	void push(int a) {
		arr[cnt] = a;
		cnt++;
	}
	// print 함수 구현
	void print() {
		for (int i = 0; i < cnt; i++)
			cout << arr[i];
		cout << endl;
	}
	// top 함수 구현
	void top() {
		if(cnt==0)
			cout<< "stack is empty."<<endl;
		else
			cout << arr[cnt - 1] << endl;
	}
	// pop 함수 구현
	void pop() {
		if (cnt == 0)
			cout << "stack is empty."<<endl;
		else {
			cout << arr[cnt - 1] << endl;
			cnt--;
		}

	}
	// empty 함수 구현
	void empty() {
		if (cnt == 0) {
			cout << "1" << endl;
		}
		else
			cout << "0" << endl;
	}
};



int main() {
	stack a;

	// exit을 입력받을 때 까지 입.출력을 반복할 수 있는 반복문 선언
	while (1) {
		char input[50];
		int push_int;
		cin >> input;
		if (strcmp(input, "top") == 0)
			a.top();

		else if (strcmp(input, "pop") == 0)
			a.pop();

		else if (strcmp(input, "empty") == 0)
			a.empty();

		else if (strcmp(input, "push") == 0) {
			cin >> push_int;
			a.push(push_int);
		}
		else if (strcmp(input, "print") == 0)
			a.print();

		else if (strcmp(input, "exit") == 0)
			break;
		else
			cout << "존재하지 않는 명령어입니다.";
	}

	return 0;
}