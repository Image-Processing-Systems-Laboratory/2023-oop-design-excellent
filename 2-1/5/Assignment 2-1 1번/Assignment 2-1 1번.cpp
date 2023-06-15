#include <iostream>

using namespace std;

// stack Ŭ���� ���� �� ��� ����
class stack {
	// 128ũ���� stack �迭 ����
	int arr[128] = {};
	int cnt = 0;
public:
	// push�Լ� ����
	void push(int a) {
		arr[cnt] = a;
		cnt++;
	}
	// print �Լ� ����
	void print() {
		for (int i = 0; i < cnt; i++)
			cout << arr[i];
		cout << endl;
	}
	// top �Լ� ����
	void top() {
		if(cnt==0)
			cout<< "stack is empty."<<endl;
		else
			cout << arr[cnt - 1] << endl;
	}
	// pop �Լ� ����
	void pop() {
		if (cnt == 0)
			cout << "stack is empty."<<endl;
		else {
			cout << arr[cnt - 1] << endl;
			cnt--;
		}

	}
	// empty �Լ� ����
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

	// exit�� �Է¹��� �� ���� ��.����� �ݺ��� �� �ִ� �ݺ��� ����
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
			cout << "�������� �ʴ� ��ɾ��Դϴ�.";
	}

	return 0;
}