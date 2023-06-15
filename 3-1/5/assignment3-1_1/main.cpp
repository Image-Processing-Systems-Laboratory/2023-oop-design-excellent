#include "List.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	LinkedList List1, List2, List3;
	char ch;                       //문자
	int index;                     //첨자
	char* str = new char[100];

	//List1 입력받기
	std::cout << "Input>>" << endl;
	std::cout << "Input list 1: ";
	do {
		index = 0;

		while(1) {
			ch = getchar();
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			str[index] = ch;
			index++;
		}

		str[index] = '\0';
		if (!List1.add(str))   //List1에 str을 key로 갖는 노드 추가
		{
			//노드 추가 실패할 경우(동적 할당 실패할 경우)
			free_LinkedList(List1.get_pHead());

			return 0;
		}

	} while (ch != '\n');

	//List2 입력받기
	std::cout << "Input list 2: ";
	do {
		index = 0;

		while (1) {
			ch = getchar();
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			str[index] = ch;
			index++;
		}

		str[index] = '\0';
		if (!List2.add(str))   //List2에 str을 key로 갖는 노드 추가
		{
			//노드 추가 실패할 경우(동적 할당 실패할 경우)
			free_LinkedList(List1.get_pHead());
			free_LinkedList(List2.get_pHead());

			return 0;
		}

	} while (ch != '\n');
	
	List3.set_pHead(Merge_List(List1.get_pHead(), List2.get_pHead(), List3.get_pHead()));    //List1과 List2를 정렬하며 병합하여 List3 생성
	
	if (List3.get_pHead() == nullptr)
	{
		return 0;                     //List 3 생성 실패할 경우(메모리 할당 실패) 종료
	}

	//List3 출력
	std::cout << "Output>>" << endl << "Result: ";
	List3.print();

	free_LinkedList(List3.get_pHead());  //List3 메모리 해제(List1과 List2는 Merge_List 과정에서 이미 메모리가 해제되었다.)

	delete[] str;

	return 0;
}