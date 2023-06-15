//2022202040 정우성

#include <iostream>
#include "Node.h"

int main()
{

	char c;
	char input1[100]; 
	LinkedList* p1 = new LinkedList; //리스트 p1 생성

	// p1의 노드들의 key값 입력받기
	std::cout << "Input>> " << std::endl;
	std::cout << "Input list 1: ";
	// 개행 문자 입력받을 때까지 입력받음
	while (1)
	{
		std::cin >> input1;
		p1->add(input1);
		if ((c = getchar()) == '\n')
			break;
	}

	//p1 정렬 제대로 됐는지 확인하기 위함
	/*std::cout << "p1: ";
	p1->print();*/
	
	char input2[100];
	LinkedList* p2 = new LinkedList; //리스크 p2 생성
	std::cout << "Input list 2: ";
	//개행 문자 입력받을 때까지 입력받음
	while (1)
	{
		std::cin >> input1;
		p2->add(input1);
		if ((c = getchar()) == '\n')
			break;
	}

	//p2 정렬 제대로 됐는지 확인하기 위함
	/*std::cout << "p2: ";
	p2->print();*/
	

	LinkedList* p3 = new LinkedList; //리스트 p3 생성
	p3->compare(p1, p2, p3); // p1과 p2 비교후 p3에 정렬
	//p3 출력
	std::cout << std::endl << "Output>>" << std::endl;
	p3->print();
	
	//p1과 p2의 노드들 모두 삭제 됐는지 확인
	/*std::cout <<std::endl<< "p1: ";
	p1->nullcheck();
	std::cout << "p2: ";
	p2->nullcheck();*/
	
	//메모리 해제
	delete p1;
	delete p2;
	delete p3;

	return 0;
}

