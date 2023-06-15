#include"mylinkedlist.h"

Node* Merge_List(Node* p1, Node* p2, Node** p3)
{
	mylinkedlist* result = new mylinkedlist;

	// 두 리스트 모두 요소가 있는 경우
	// 데이터를 비교해 빠른 쪽을 추가하고 그 리스트는 다음으로 넘긴다.
	while (p1 != nullptr && p2 != nullptr)
	{
		if (strcasecmp(p1->getData(), p2->getData()) > 0)
		{
			result->push_back(p2->getData());
			p2 = p2->getNext();
		}
		else
		{
			result->push_back(p1->getData());
			p1 = p1->getNext();
		}
	}

	// 비교가 끝난 후 남은 요소를 합쳐준다.
	while (p1 != nullptr)
	{
		result->push_back(p1->getData());
		p1 = p1->getNext();
	}

	while (p2 != nullptr)
	{
		result->push_back(p2->getData());
		p2 = p2->getNext();
	}

	// 결과 출력
	cout << "Result: ";
	result->printlist();

	// p3를 참조에 의한 호출로 받았으므로 포인터를 설정해준다.
	*p3 = result->getHead();
	return result->getHead();
}

int main(void)
{
	mylinkedlist m1;
	mylinkedlist m2;
	char input[2048];
	char* token;

	// 리스트1 입력
	cout << "Input list 1: ";
	cin.getline(input, 2048);

	// 리스트1에 자료 입력
	token = strtok(input, " ");
	while (token != NULL)
	{
		m1.push_back(token);
		token = strtok(NULL, " ");
	}
	
	// 리스트2 입력
	cout << "Input list 2: ";
	cin.getline(input, 2048);

	// 리스트2에 자료 입력
	token = strtok(input, " ");
	while (token != NULL)
	{
		m2.push_back(token);
		token = strtok(NULL, " ");
	}

	// 리스트1, 리스트2 정렬 후 결과 출력
	m1.sortlist();
	m2.sortlist();
	Node* p3 = nullptr;
	Merge_List(m1.getHead(), m2.getHead(), &p3);
	
	return 0;
}