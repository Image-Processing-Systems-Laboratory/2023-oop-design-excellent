#include<iostream>
using namespace std;

int main(void) {

	char cmd[10];				//명령어를 입력받기 위한 배열
	int cmd_n = 0;				// push를 사용하였을 때 같이 입력된 숫자 변수

	int stack[129] = { 0 };		//스택을 저장할 배열을 선언해준다.
	int top = 0;

	while (1) {					//특정 조건에 다르기 전까지 무한 루프
		cin >> cmd;				//명령어 입력 받기
		if (!strcmp(cmd, "exit"))		//명령어가 exit이면
			break;				//무한반복 나가기

		if (!strcmp(cmd, "push")) {		//명령어가 push이면
			cin >> cmd_n;				//정수 하나 입력 받기
			if (top == 128) {			//현재 128개의 값이 이미 들어있으면
				cout << "범위를 초과함." << endl;		//범위 초과 안내
			}
			else {						//아니라면
				stack[top++] = cmd_n;		//스택에 담고, top을 1 추가해준다.
			}
		}

		if (!strcmp(cmd, "pop")) {		//명령어가 pop이라면
			if (top > 0) {				// top이 0보다 큰 경우에만 한다(데이터가 있는 경우)
				cout << stack[top - 1] << endl;		//맨 마지막 값을 출력한다.
				stack[top--] = 0;		// 인덱스의 마지막 칸을 한칸 당기고, 마지막 칸을 0으로 채워놓는다.
			}
		}

		if (!strcmp(cmd, "top")) {		//명령어가 top라면
			if (top <= 0) {				//데이터가 없을 때 예외처리
				cout << "출력할 데이터가 없음" << endl;;
			}
			else {						//맨 마지막 데이터를 출력
				cout << stack[top - 1] << endl;
			}
		}

		if (!strcmp(cmd, "print")) {		//명령어가 print라면
			if (top <= 0) {					//데이터 없을 때 예외처리
				cout << "출력할 데이터가 없음." << endl;
			}
			else {							//데이터 있을 때
				for (int i = 0; i < top; i++)
					cout << stack[i] << " ";		//모두 출력
				cout << endl;
			}
		}

		if (!strcmp(cmd, "empty")) {		//명령어가 empty라면
			if (top <= 0) {					//top이 가르키는 인덱스를 보고 결정하는데, 0이라면 데이터가 없는 것이므로 1 출력
				cout << 1 << endl;
			}
			else {							//1이라면 데이터가 있으므로 0 출력
				cout << 0 << endl;
			}
		}
	}
	


	return 0;
}