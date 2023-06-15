//2022202040 정우성
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Stack.h"

int main()
{
	int size, data; // size: 스택의 최대 사이즈 / data: 노드의 key값
	// 스택의 최대 사이즈 입력
	std::cout << "Input size: ";
	std::cin >> size;

	//스택의 객체 생성하고 사이즈 설정
	Stack stack;
	stack.SetSize(size);

	char command[100]; //명령어 입력받을 문자열 
	do
	{
		std::cin >> command;
		if (strcmp(command, "push") == 0) { // push 입력받았을 때
			if (stack.IsFull() == true) { // 스택이 꽉 차있으면 문자 출력 후 반복문 다시 시작
				std::cout << "Full stack." << std::endl;
				continue;
			}
			std::cin >> data; // 노드의 key값 입력받음
			Node* mnode = new Node; //노드 생성
			mnode->SetData(data); //노드의 key값 설정
			mnode->SetNext(nullptr); //노드의 링크값 설정
			stack.Push(mnode); // push
		}
		if (strcmp(command, "full") == 0) { //full 입력받았을 때
			if (stack.IsFull() == true) //꽉 차있으면 "True." 출력
				std::cout << "True." << std::endl;
			else // 꽉 차있지 않으면 "False." 출력
				std::cout << "False." << std::endl;
		}
		if (strcmp(command, "empty") == 0) { //empty 입력받았을 때
			if (stack.IsEmpty() == true) // 비어있으면 "True." 출력
				std::cout << "True." << std::endl;
			else // 비어있지 않으면 "False." 출력
				std::cout << "False." << std::endl;;
		}
		if (strcmp(command, "pop") == 0) { //pop 입력받았을때
			if (stack.IsEmpty() == true) { // 스택이 비어있다면 "Empty stack." 출력 후 반복문 다시 시작
				std::cout << "Empty stack." << std::endl;
				continue;
			}
			std::cout << stack.Pop()->GetData() << std::endl; //첫 노드 삭제 후 그 노드의 key값 출력
		}
		if (strcmp(command, "print") == 0) { //print 입력받았을 때
			stack.PrintStack(); // 스택에 있는 모든 노드들의 key값 출력
		}
	} while (strcmp(command, "exit") != 0); //exit 입력받으면 반복문 종료

	return 0;
}