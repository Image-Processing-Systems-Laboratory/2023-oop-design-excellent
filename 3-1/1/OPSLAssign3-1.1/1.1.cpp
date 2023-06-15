#include <iostream>
#include <string>

class Node {

public:

	std::string data;
	Node* next;

	Node();
	Node(std::string data);

	void insert(std::string data);
	void sortList();
	void printList();
};

//////////////////////////////////////////////////////////////////////////////////////////

void inputList(Node& node);
int strcasecmp(const std::string& s1, const std::string& s2);
void Merge_List(Node* p1, Node* p2, Node* p3);

//////////////////////////////////////////////////////////////////////////////////////////

Node::Node()
{
	this->data = "";		// 비어있는 string으로 초기화
	this->next = nullptr;	// 가리키는 다음 노드는 nullptr
}

Node::Node(std::string data)
{
	this->data = data;		// string을 data로 초기화
	this->next = nullptr;	// 가리키는 다음 노드는 아직 nullptr
}

//////////////////////////////////////////////////////////////////////////////////////////

void Node::insert(std::string data)
{
	if (this->data == "")	// 비어있는 string이라면 data로 초기화
	{
		this->data = data;
	}

	else
	{
		Node* temp = this;

		while (temp->next != nullptr)
		{
			temp = temp->next;			// 현재 노드부터 다음 노드가 nullptr일때까지(끝까지) 진행 
		}

		temp->next = new Node(data);	// 끝 노드에서 data를 가진 새로운 노드 추가
	}
}

void Node::sortList()
{
	Node* current = this;	// 정렬할 현재 노드 리스트
	Node* compare;			// 정렬할 값을 저장할 노드 리스트

	std::string temp;	// string temp

	while (current != nullptr) 
	{
		compare = current->next;	// 비교할 노드는 현재 노드의 다음 노드를 가리킨다

		while (compare != nullptr) 
		{
			if (strcasecmp(current->data, compare->data) > 0) // 현재 데이터가 다음 비교 데이터보다 크다면(뒷 순서 알파벳)
			{
				temp = current->data;
				current->data = compare->data;
				compare->data = temp;
			}
			compare = compare->next;// 비교할 노드의 다음 노드를 불러온다
		}
		current = current->next;	// 현재 노드의 다음 노드를 불러온다	(자세한 다이어그램은 보고서에)
	}
}

void Node::printList()
{
	Node* temp = this;

	while (temp != nullptr)		// 현재 노드부터 다음 노드가 nullptr일때까지(끝까지) 진행 
	{
		std::cout << temp->data << " ";	// data를 출력
		temp = temp->next;
	}

	std::cout << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////

void inputList(Node& node)
{
	std::string word;
	char c;

	while (std::cin.get(c))	// 입력을 loop
	{
		if (c == ' ' || c == '\n')
		{
			if (!word.empty())		// ' ' 공백 문자가 들어온 경우, 단어가 비어있지 않다면
			{
				node.insert(word);	// 노드에 단어를 삽입
				word.clear();		// 다음 loop, 다음 단어 입력을 위해 clear
			}

			if (c == '\n')			// enter가 들어온 경우 while문을 빠져나와 종료
				break;
		}
		else
			word.push_back(c);	// 이외의 경우 string(단어)에 글자 하나를 추가
	}
}

int strcasecmp(const std::string& s1, const std::string& s2)
{
	for (int i = 0; i < s1.length() && i < s2.length(); i++)
	{
		char c1 = s1[i];
		char c2 = s2[i];

		if (c1 >= 'A' && c1 <= 'Z')	// 대문자를 소문자로 변환
			c1 += 32;

		if (c2 >= 'A' && c2 <= 'Z')	// 대문자를 소문자로 변환
			c2 += 32;

		if (c1 < c2)		// 문자의 ASCII 값이 c2가 더 크다면 -1 반환
			return -1;

		else if (c1 > c2)	// 문자의 ASCII 값이 c1이 더 크다면 1 반환
			return 1;
	}

	if (s1.length() < s2.length())
		return -1;	// 두 string이 같으나 s2가 더 길다면 -1 반환

	else if (s1.length() > s2.length())
		return 1;	// 두 string이 같으나 s1이 더 길다면 1 반환

	else
		return 0;	// 모두 만족하는 경우 두 string은 같은 string.
}

void Merge_List(Node* p1, Node* p2, Node* p3)
{
	while (p1 != nullptr && p2 != nullptr) 
	{
		if (strcasecmp(p1->data, p2->data) <= 0)	// p1의 데이터가 p2보다 작거나 같다면 (앞 순서 알파벳), p1의 노드를 p3에 삽입
		{
			p3->insert(p1->data);
			p1 = p1->next;			// 다음 p1 노드
		}
		else 
		{
			p3->insert(p2->data);					// p2의 데이터가 p1보다 작다면 (앞 순서 알파벳), p2의 노드를 p3에 삽입
			p2 = p2->next;			// 다음 p2 노드
		}
	}

	while (p1 != nullptr)		// p1의 남은 노드를 p3에 삽입
	{
		p3->insert(p1->data);
		p1 = p1->next;			// 다음 p1 노드
	}

	while (p2 != nullptr)		// p2의 남은 노드를 p3에 삽입
	{
		p3->insert(p2->data);
		p2 = p2->next;			// 다음 p2 노드
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	Node p1, p2, p3;

	std::cout << "Input>>" << std::endl;
	std::cout << "Input list 1: ";			// 첫번째 문장
	inputList(p1);

	std::cout << "Input list 2: ";			// 두번째 문장
	inputList(p2);

	p1.sortList();	// 문장의 sort
	p2.sortList();	// 문장의 sort

	Merge_List(&p1, &p2, &p3);	// 정렬된 두 문장의 merge

	std::cout << std::endl << "Output>>" << std::endl << "Result: ";
	p3.printList();	// merge된 문장의 출력

	return 0;
}